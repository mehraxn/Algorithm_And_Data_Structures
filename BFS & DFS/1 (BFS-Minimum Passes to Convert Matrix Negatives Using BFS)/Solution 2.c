#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Define a structure for the queue
typedef struct {
    int x, y;
} Point;

typedef struct {
    Point points[MAX * MAX];
    int front, rear;
} Queue;

// Queue functions
void enqueue(Queue *q, int x, int y) {
    q->points[q->rear].x = x;
    q->points[q->rear].y = y;
    q->rear++;
}

Point dequeue(Queue *q) {
    return q->points[q->front++];
}

int is_empty(Queue *q) {
    return q->front == q->rear;
}

// BFS function to find the minimum passes
int minimumPasses(int matrix[MAX][MAX], int rows, int cols) {
    Queue queue = {.front = 0, .rear = 0};
    int total_negatives = 0, passes = 0;
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Step 1: Initialize the queue with all positive cells and count negatives
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] > 0) {
                enqueue(&queue, i, j);
            } else if (matrix[i][j] < 0) {
                total_negatives++;
            }
        }
    }

    // If there are no negatives, return 0 passes
    if (total_negatives == 0) {
        return 0;
    }

    // Step 2: BFS to spread positivity
    while (!is_empty(&queue)) {
        int size = queue.rear - queue.front;
        int converted = 0;

        for (int i = 0; i < size; i++) {
            Point p = dequeue(&queue);

            for (int d = 0; d < 4; d++) {
                int nx = p.x + directions[d][0];
                int ny = p.y + directions[d][1];

                // Check bounds and convert negative to positive
                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && matrix[nx][ny] < 0) {
                    matrix[nx][ny] = 1;  // Convert to positive
                    enqueue(&queue, nx, ny);
                    total_negatives--;
                    converted = 1;
                }
            }
        }

        if (converted) {
            passes++;
        }
    }

    // Step 3: Check if all negatives were converted
    return total_negatives == 0 ? passes : -1;
}

// Main function to test the code
int main() {
    int matrix[MAX][MAX] = {
            {0, -1, -3, 2, 0},
            {1, -2, -5, -1, -3},
            {3,  0,  0, -4, -2}
    };
    int rows = 3, cols = 5;

    int result = minimumPasses(matrix, rows, cols);
    printf("Minimum passes required: %d\n", result);

    return 0;
}
