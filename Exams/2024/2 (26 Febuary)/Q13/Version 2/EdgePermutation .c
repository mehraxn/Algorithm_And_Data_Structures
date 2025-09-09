#include <stdio.h>
#include <stdlib.h>

typedef struct EDGES edge ;
struct EDGES {
    int source , destination,weight;
};


void find_maximum(edge array[],int edge_counter, int *colour , int nv,
    int *solution ,int * mark ,int n , int k , int pos, int * final_numbers , int *final_maximum);

int check (edge array[],int edge_counter, int *colour , int nv , int *solution , int k, int * final_numbers , int *final_maximum) { // Fixed: added * to final_maximum
    for(int i = 0 ; i < k ; i++) {
        if (colour[array[solution[i]].source] == colour[array[solution[i]].destination] ) { // Fixed: added solution[i] indexing
            return 0;
        }
    }
    for(int i = 0 ; i < k-1 ; i++) {
        if (array[solution[i]].destination != array[solution[i+1]].source) { // Fixed: added solution[] indexing
            return 0;
        }
    }

    // Fixed: moved weight calculation outside the loop
    int temp=0;
    for (int j = 0 ; j < k ; j++) {
        temp = temp + array[solution[j]].weight ; // Fixed: added solution[j] indexing
    }

    if (temp>*final_maximum ) { // Fixed: dereferenced final_maximum
        // Fixed: copy solution to final_numbers properly
        for(int i = 0; i < k; i++) {
            final_numbers[i] = solution[i];
        }
        *final_maximum = temp;
        return 1;
    }
    else
        return 0;
}

void longest_weight_path (int **g, int *colour, char **vertex_id, int n) { // Fixed: function name typo
    edge array[n*n];
    int edge_counter=0;
    for (int i=0 ;i<n ; i++) {
        for (int j=0 ; j<n ; j++) {
            if (g[i][j] >0) {
                array[edge_counter].source =i;
                array[edge_counter].destination =j;
                array[edge_counter].weight =g[i][j];
                edge_counter++;
            }
        }
    }

    // Added: missing implementation to call find_maximum
    int solution[edge_counter];
    int mark[edge_counter];
    int final_numbers[edge_counter];
    int final_maximum = 0;

    // Initialize arrays
    for(int i = 0; i < edge_counter; i++) {
        mark[i] = 0;
        final_numbers[i] = -1;
    }

    // Try different path lengths
    for(int k = 1; k <= edge_counter; k++) {
        find_maximum(array, edge_counter, colour, n, solution, mark, edge_counter, k, 0, final_numbers, &final_maximum);
    }

    // Display result with vertex identifiers as required
    printf("Path with maximum weight: ");
    if (final_maximum > 0) {
        for(int i = 0; final_numbers[i] != -1 && i < edge_counter; i++) {
            int edge_idx = final_numbers[i];
            printf("%s ", vertex_id[array[edge_idx].source]);
        }
        // Print the final destination vertex
        if (final_numbers[0] != -1) {
            int last_edge = final_numbers[0];
            for(int i = 1; final_numbers[i] != -1 && i < edge_counter; i++) {
                last_edge = final_numbers[i];
            }
            printf("%s ", vertex_id[array[last_edge].destination]);
        }
        printf("- Weight: %d\n", final_maximum);
    } else {
        printf("No valid path found\n");
    }

}


void find_maximum(edge array[],int edge_counter, int *colour , int nv,
    int *solution ,int * mark ,int n , int k , int pos, int * final_numbers , int *final_maximum) {
    if (pos >= k) {
        check (array,edge_counter, colour , nv , solution , k,final_numbers , final_maximum);
        return;
    }
    for (int i = 0; i < edge_counter; i++) {
        if (mark[i] == 0) {
            // Check path continuity: if not first edge, ensure it connects to previous edge
            if (pos > 0 && array[solution[pos-1]].destination != array[i].source) {
                continue; // Skip this edge as it doesn't continue the path
            }

            mark[i] = 1;
            solution[pos] = i;
            find_maximum(array,edge_counter,colour,nv,solution,mark,edge_counter,k,pos+1,final_numbers,final_maximum);
            mark[i] = 0;
        }
    }
    return;
}