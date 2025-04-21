#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void partition(int *vet, int n, int k);
void assign_partitions( int *vet, int n, int k, int *partitions, int *best_partitions);
void assign_partitions_r( int *vet, int n, int k, int *partitions, int *best_partitions, float *best_var, int pos);
int check_suitable_partition_sizes(int *partitions, int n, int k);
float variance(int *vet,int *partitions,int n,int k);
void copy_partitions(int *part,int *best, int n);

int main() {
	int vet[] = {1,2,3,4,5};
	partition(vet, 5, 4);
	return 0;
}

// let's design a solution:
// a. given vet I will assign to each value a partition index p ( 1 <= p <= k )
// b. I will try all possible assignments
// c. when every n number has a partition index, I will check if the partitions have a size that satisfy the constraints (easily checked with (n/k) <= partition size <= (n/k)+1 )
// d. if the partitioning is ok, I will consider the next constraint, that is finding the partition set with minimum variance
//
// So, what I need?
// from a. : a supporting array of size n to store the partition indexes
// from d. : a supporting array of size k to store the Si value for each partition (Si is the sum of all elements in partition p_i)
// from d. : I need to keep track of the "best" partition so far, so I will track a copy of the supporting array from point a.
//
// let's provide a scaffold, before jumping into the actual code
// void partition(int *vet, int n, int k) {
//   int *partitions = calloc( |int| * n )
//   int *best_partitions = calloc( |int| * n )
//   int *sums = calloc( |int| * k )
//   assign_partitions( vet, n, k, partitions, best_partitions)
// }
//
// void assign_partitions( int *vet, int n, int k, int *partitions, int *best_partitions) {
//   // just a wrapper to the recursive call
//   float best_var = -1; // an impossible value, no mark that there is no best_var at the moment
//   assign_partitions_r(vet, n, k, partitions, best_partitions, &best_var, 0)
// }
//
// void assign_partitions_r( int *vet, int n, int k, int *partitions, int *best_partitions, float *best_var, int pos) {
//   // base case check
//   if( pos == n ) {
//     if( check_suitable_partition_sizes(partitions,n,k) == 1 ) {
//       // ok, let's evaluate variance
//       float var = variance(vet,partitions,k)
//       if( *best_var == -1 || var < *best_var ) {
//         copy_partitions(partitions, best_partitions)
//         *best_var = var
//       }
//     }
//     return
//   }
//   for( int index = 1; index <= k; index++ ) {
//     partitions[pos] = index
//     assign_partitions_r( vet, n, k, partitions, best_partitions, best_var, pos+1)
//   }
// }
//
// now we still have to implement check_suitable_partition_sizes(.), variance(.), and copy_partitions(.)
// copy_partitions(.) is the most intuitive, let's implement that as the last function
//
// let's implement check_suitable_partition_sizes(.). Do not waste time in find the optimal, most efficient solution, just implement something that works
// in this case:
// 1. we have k partitions, with index from 1 to k
// 2. for each index, let's count how many times it appears in partitions
// 3. check if the count is within the limits (n\k) <= count <= (n\k)+1
// By the way, this checks ensures that we have k partitions
// int check_suitable_partition_sizes(int *partitions, int n, int k) {
//   int min = n\k      // no need to round, this is an integer division
//   int max = n\k + 1
//   for( int index = 1; index <= k; index++ ) {
//     int count = 0;
//     for( int j=0; j<n; j++ ) {
//       if( partitions[j] == index ) count++;
//     }
//     if( count < min || count > max )
//       return 0; // failure
//   }
//   return 1; // success
// }
//
// Ok, now the real code

void partition(int *vet, int n, int k) {
  int *partitions = (int *)calloc(n, sizeof(int));
  int *best_partitions = (int *)calloc( n, sizeof(int));
  assign_partitions( vet, n, k, partitions, best_partitions);
	// show the result
	for(int p=1;p<=k;p++) {
		printf(" partition %d: ",p);
		for(int i=0;i<n;i++) {
			if( best_partitions[i] == p )
				printf(" %d",vet[i]);
		}
		printf("\n");
	}
}

void assign_partitions( int *vet, int n, int k, int *partitions, int *best_partitions) {
  // just a wrapper to the recursive call
  float best_var = -1; // an impossible value, no mark that there is no best_var at the moment
  assign_partitions_r(vet, n, k, partitions, best_partitions, &best_var, 0);
}

void assign_partitions_r( int *vet, int n, int k, int *partitions, int *best_partitions, float *best_var, int pos) {
	// base case check
	if( pos == n ) {
		if( check_suitable_partition_sizes(partitions,n,k) == 1 ) {
			// ok, let's evaluate variance
			float var = variance(vet,partitions,n,k);
			if( *best_var == -1 || var < *best_var ) {
				copy_partitions(partitions, best_partitions,n);
				*best_var = var;
			}
		}
		return;
	}
	for( int index = 1; index <= k; index++ ) {
		partitions[pos] = index;
		assign_partitions_r( vet, n, k, partitions, best_partitions, best_var, pos+1);
	}
}

int check_suitable_partition_sizes(int *partitions, int n, int k) {
	// useful comment to the evaluator: this function ensure that we have k partitions and that they have the correct size
	int min = n/k;      // no need to round, this is an integer division
	int max = n/k + 1;
	for( int index = 1; index <= k; index++ ) {
		int count = 0;
		for( int j=0; j<n; j++ ) {
			if( partitions[j] == index ) count++;
		}
		if( count < min || count > max )
			return 0; // failure
	}
	return 1; // success
}

float variance(int *vet,int *partitions,int n,int k) {
	int p,i;
	// let's compute k sums (starting with index 1)
	int *sums = calloc(k+1,sizeof(int));
	// let's collect the sum for each partition index
	for(p = 1; p<=k; p++ ) {
		for( i=0; i<n; i++) {
			if(partitions[i] == p)
				sums[p] += vet[i];
		}
	}
	// let's compute the average
	float average=0;
	for(p = 1; p<=k; p++ ) {
		average += sums[p];
	}
	average = average / k; // float / int is promoted to float / float
	// now the variance
	float variance=0;
	for(p = 1; p<=k; p++ ) {
		float delta = sums[p] - average;
		delta *= delta;
		variance += delta;
	}
	variance = variance / (k-1);
	return variance;
}

void copy_partitions(int *part,int *best, int n) {
	for(int i=0;i<n;i++)
		best[i] = part[i];
}
