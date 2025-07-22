#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100
enum { WHITE, GRAY, BLACK };

void BFS(int G[][MAX], int n, int s) {

    int color[MAX], dist[MAX], pred[MAX];
    int queue[MAX], front = 0, rear = -1;

    for (int i = 0; i < n; i++) {
        color[i] = WHITE;
        dist[i]  = INT_MAX;
        pred[i]  = -1;
    }

    color[s] = GRAY;
    dist[s]  = 0;
    pred[s]  = -1;
    queue[++rear] = s;

    while (front <= rear) {
        int u = queue[front++];

        for (int v = 0; v < n; v++) {
            if (G[u][v] && color[v] == WHITE) {
                color[v] = GRAY;
                dist[v]  = dist[u] + 1;
                pred[v]  = u;
                queue[++rear] = v;
            }
        }

        color[u] = BLACK;
    }

    printf("\nVertex  Distance  Predecessor\n");
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            printf("  %2d      ∞        %3d\n", i, pred[i]);
        else
            printf("  %2d      %2d        %3d\n", i, dist[i], pred[i]);
    }
}
