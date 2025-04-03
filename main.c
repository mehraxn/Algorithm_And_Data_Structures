
#include <stdio.h>
#include <stdlib.h>

#define MAX_DIM 50

typedef struct {
    int row, col, height, width, area;
} Region;

void readMatrix(int matrix[MAX_DIM][MAX_DIM],
                 int *nr, int *nc) {
    FILE *file = fopen("mat.txt", "r");
    if (!file) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    fscanf(file, "%d %d", nr, nc);
    for (int i = 0; i < *nr; i++) {
        for (int j = 0; j < *nc; j++) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }

    fclose(file);
}



int main() {
    int matrix[MAX_DIM][MAX_DIM];
    int nr, nc;

    Region maxHeightRegion = {0, 0, 0, 0, 0};
    Region maxWidthRegion = {0, 0, 0, 0, 0};
    Region maxAreaRegion = {0, 0, 0, 0, 0};

    readMatrix(matrix, &nr, &nc);

    int visited[MAX_DIM][MAX_DIM] = {0};

    for (int i = 0; i < nr; i++) {
        for (int j = 0; j < nc; j++) {
            if (matrix[i][j] == 1 && !visited[i][j]) {
                int r = i, c = j, height = 0, width = 0;

                // Calculate width
                while (c < nc && matrix[r][c] == 1) {
                    c++;
                    width++;
                }

                // Calculate height
                c = j;
                while (r < nr && matrix[r][c] == 1) {
                    r++;
                    height++;
                }

                // Mark the region as visited
                for (int x = i; x < i + height; x++) {
                    for (int y = j; y < j + width; y++) {
                        visited[x][y] = 1;
                    }
                }

                int area = height * width;

                // Update max regions if necessary
                if (height > maxHeightRegion.height) {
                    //maxHeightRegion = {i, j, height, width, area};
                    maxHeightRegion.row = i;
                    maxHeightRegion.col = j;
                    maxHeightRegion.height = height;
                    maxHeightRegion.width = width;
                    maxHeightRegion.area = area;

                }
                if (width > maxWidthRegion.width) {
                    //maxWidthRegion = {i, j, height, width, area};
                    maxWidthRegion.row = i;
                    maxWidthRegion.col = j;
                    maxWidthRegion.height = height;
                    maxWidthRegion.width = width;
                    maxWidthRegion.area = area;
                }
                if (area > maxAreaRegion.area) {
                    //maxAreaRegion = {i, j, height, width, area};
                    maxAreaRegion.row = i;
                    maxAreaRegion.col = j;
                    maxAreaRegion.height = height;
                    maxAreaRegion.width = width;
                    maxAreaRegion.area = area;
                }
            }
        }
    }



    printf("Max-height region: upper left corner=(%d,%d), height=%d, width=%d, area=%d\n",
           maxHeightRegion.row, maxHeightRegion.col, maxHeightRegion.height,
           maxHeightRegion.width, maxHeightRegion.area);
    printf("Max-width region: upper left corner=(%d,%d), height=%d, width=%d, area=%d\n",
           maxWidthRegion.row, maxWidthRegion.col, maxWidthRegion.height,
           maxWidthRegion.width, maxWidthRegion.area);
    printf("Max-area region: upper left corner=(%d,%d), height=%d, width=%d, area=%d\n",
           maxAreaRegion.row, maxAreaRegion.col, maxAreaRegion.height,
           maxAreaRegion.width, maxAreaRegion.area);

    return 0;
}
