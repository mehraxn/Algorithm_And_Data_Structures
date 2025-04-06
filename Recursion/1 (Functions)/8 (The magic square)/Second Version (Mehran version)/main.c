#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int check(int **, int );
int ** change_array_to_matrix (int * ,int );
void check_all_the_number (int *, int * ,int * , int , int  ,int *, int *);

int main() {
    int array[9]={1,2,3,4,5,6,7,8,9};
    int mark[9]={0};
    int sol[9];
    int found = 0;

    int * final_array=(int *)malloc(9 *sizeof(int));
    if (final_array == NULL) {
        printf("error of memory allocation. \n");
        return 0;
    }

    for (int i = 0; i < 9; i++) {
        final_array[i] = 0;
    }

    check_all_the_number(array,sol,mark,9,0,final_array, &found);

    if (found) {
        int ** matrix=(int **)malloc(3 * sizeof(int*));
        if (matrix == NULL){
            printf("error of memory allocation. \n");
            free(final_array);
            return 0;
        }

        for (int i=0 ; i<3 ; i++){
            matrix[i]=(int *)malloc(3 * sizeof(int));
            if (matrix[i] == NULL){
                printf("error of memory allocation. \n");
                for (int j=0; j<i; j++) {
                    free(matrix[j]);
                }
                free(matrix);
                free(final_array);
                return 0;
            }
        }

        printf("\nMagic Square Solution:\n");
        int k=0;
        for (int i=0 ; i<3 ; i++){
            for (int j=0 ; j<3 ; j++){
                matrix[i][j] = final_array[k++];
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }

        // Free matrix memory
        for(int i=0 ; i<3; i++)
            free(matrix[i]);
        free(matrix);
    } else {
        printf("No magic square found.\n");
    }

    free(final_array);
    return 0;
}

void check_all_the_number (int * array, int * sol ,int * mark , int n , int pos , int * final_array, int *found){
    if (*found) return;

    int i;

    if (pos >= n){
        int **temp_matrix= change_array_to_matrix(sol,n);
        if (temp_matrix != NULL && check(temp_matrix,sqrt(n))) {
            for (int k=0;k<n;k++)
                final_array[k]=sol[k];
            *found = 1;

            // Free matrix memory before returning
            for(int j=0; j<sqrt(n); j++)
                free(temp_matrix[j]);
            free(temp_matrix);
            return;
        }

        // Free matrix memory
        if (temp_matrix != NULL){
            for(int j=0; j<sqrt(n); j++)
                free(temp_matrix[j]);
            free(temp_matrix);
        }
        return;
    }

    for(i=0 ; i<n ; i++){
        if (mark[i] ==0 ){
            mark[i]=1;
            sol[pos]=array[i];
            check_all_the_number(array,sol,mark,n,pos+1,final_array, found);
            if (*found) return;
            mark[i]=0;
        }
    }

    return;
}

int ** change_array_to_matrix(int * array,int size ){

    if (size <= 0)
        return  NULL;
    int dim=(int)sqrt(size);

    if ((dim*dim) != size){
        printf("your array cannot changed to a square matrix \n");
        return NULL;
    }

    int ** matrix=(int **)malloc(dim * sizeof(int*));

    if (matrix == NULL){
        printf("error of memory allocation. \n");
        return NULL;
    }

    for (int i=0 ; i<dim ; i++){
        matrix[i]=(int *)malloc(dim * sizeof(int));
        if (matrix[i] == NULL){
            printf("error of memory allocation. \n");
            for (int j=0; j<i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return NULL;
        }
    }

    int k=0;
    for (int i=0 ; i<dim ; i++)
        for (int j=0 ;j<dim ;j++)
            matrix[i][j]=array[k++];

    return matrix;
}

int check(int **matrix, int dim) {
    int i, j, sum, target;

    target = dim * (dim * dim + 1) / 2;

    // Check rows
    for (i = 0; i < dim; i++) {
        sum = 0;
        for (j = 0; j < dim; j++) {
            sum += matrix[i][j];
        }
        if (sum != target) return 0;
    }

    // Check columns
    for (j = 0; j < dim; j++) {
        sum = 0;
        for (i = 0; i < dim; i++) {
            sum += matrix[i][j];
        }
        if (sum != target) return 0;
    }

    // Check main diagonal
    sum = 0;
    for (i = 0; i < dim; i++) {
        sum += matrix[i][i];
    }
    if (sum != target) return 0;

    // Check secondary diagonal
    sum = 0;
    for (i = 0; i < dim; i++) {
        sum += matrix[i][dim - i - 1];
    }
    if (sum != target) return 0;

    return 1;
}