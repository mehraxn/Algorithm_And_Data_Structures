#include <stdio.h>
#include <stdlib.h>

// Binary tree node definition
typedef struct node_s_binary {
    int key;
    struct node_s_binary *l, *r;
} node_t_binary;

// Fixed-size N-ary tree node definition
#define N 3
typedef struct node_s_fixed {
    int key;
    struct node_s_fixed *children[N];
} node_t_fixed;

// Dynamic-size N-ary tree node definition
typedef struct node_s_dynamic {
    int key;
    int degree;
    struct node_s_dynamic **children;
} node_t_dynamic;
