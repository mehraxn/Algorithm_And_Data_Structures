#include <stdio.h> // This part is added to the code
#include <stdlib.h> // This part is added to the code
#include <limits.h>// This part is added to the code

typedef struct graph_s graph_t; // This part is added to the code
typedef struct edge_s edge_t; // This part is added to the code
typedef struct vertex_s vertex_t; // This part is added to the code

// This part is added to the code
struct graph_s {
    vertex_t *g;
    int nv;
};

// This part is added to the code
struct edge_s {
    int weight;
    vertex_t *dst;
    edge_t *next;
};

// This part is added to the code
struct vertex_s {
    int id;
    int color;
    int dist;
    int disc_time;
    int endp_time;
    int scc;
    vertex_t *pred;
    edge_t *head;
    vertex_t *next;
};



#define WHITE 0 // This part is added to the code
#define GREY 1 // This part is added to the code
#define BLACK 2 // This part is added to the code

// This part is added to the code
typedef struct queue_node {
    void* data;
    struct queue_node* next;
} queue_node_t;

// This part is added to the code
typedef struct queue_s {
    queue_node_t* front;
    queue_node_t* rear;
    int size;
    int capacity;
} queue_t;

// This part is added to the code
queue_t* queue_init(int capacity) {
    queue_t* q = (queue_t*)malloc(sizeof(queue_t));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    q->capacity = capacity;
    return q;
}

// This part is added to the code
int queue_empty_m(queue_t* q) {
    return q->size == 0;
}

// This part is added to the code
void queue_put(queue_t* q, void* data) {
    if (q->size >= q->capacity) return;
    queue_node_t* new_node = (queue_node_t*)malloc(sizeof(queue_node_t));
    new_node->data = data;
    new_node->next = NULL;
    if (queue_empty_m(q)) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
    q->size++;
}

// This part is added to the code
void queue_get(queue_t* q, void** data) {
    if (queue_empty_m(q)) return;
    queue_node_t* temp = q->front;
    *data = temp->data;
    q->front = q->front->next;
    free(temp);
    if (q->front == NULL) {
        q->rear = NULL;
    }
    q->size--;
}

// This part is added to the code
void queue_dispose(queue_t* q, void (*free_data)(void*)) {
    while (!queue_empty_m(q)) {
        void* data;
        queue_get(q, &data);
        if (free_data) {
            free_data(data);
        }
    }
    free(q);
}

// This part is added to the code
graph_t* graph_create(int nv) {
    graph_t* g = (graph_t*)malloc(sizeof(graph_t));
    g->nv = nv;
    g->g = NULL;
    return g;
}

// This part is added to the code
vertex_t* graph_find(graph_t* g, int id) {
    vertex_t* curr = g->g;
    while (curr != NULL) {
        if (curr->id == id) {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

// This part is added to the code
vertex_t* graph_add_vertex(graph_t* g, int id) {
    vertex_t* v = (vertex_t*)malloc(sizeof(vertex_t));
    v->id = id;
    v->color = WHITE;
    v->dist = 0;
    v->disc_time = 0;
    v->endp_time = 0;
    v->scc = 0;
    v->pred = NULL;
    v->head = NULL;
    v->next = g->g;
    g->g = v;
    return v;
}

// This part is added to the code
void graph_add_edge(vertex_t* src, vertex_t* dst, int weight) {
    edge_t* e = (edge_t*)malloc(sizeof(edge_t));
    e->dst = dst;
    e->weight = weight;
    e->next = src->head;
    src->head = e;
}

// This part is added to the code
void graph_attribute_init(graph_t* g) {
    vertex_t* v = g->g;
    while (v != NULL) {
        v->color = WHITE;
        v->dist = INT_MAX;
        v->disc_time = 0;
        v->endp_time = 0;
        v->scc = 0;
        v->pred = NULL;
        v = v->next;
    }
}

// This part is added to the code
graph_t* graph_load(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (!fp) return NULL;
    int nv, ne;
    fscanf(fp, "%d %d", &nv, &ne);
    graph_t* g = graph_create(nv);
    // Create all vertices
    for (int i = 0; i < nv; i++) {
        graph_add_vertex(g, i);
    }

    // Add all edges
   for (int i = 0; i < ne; i++) {
        int src_id, dst_id, weight;
        fscanf(fp, "%d %d %d", &src_id, &dst_id, &weight);
        vertex_t* src = graph_find(g, src_id);
        vertex_t* dst = graph_find(g, dst_id);
        if (src && dst) {
            graph_add_edge(src, dst, weight);
        }
    }
    fclose(fp);
    return g;
}

void graph_bfs(graph_t* g, vertex_t* n) {
    queue_t* qp;
    vertex_t* d;
    edge_t* e;

    qp = queue_init(g->nv);
    n->color = GREY;
    n->dist = 0;
    n->pred = NULL;
    queue_put(qp, (void*)n);

    while (!queue_empty_m(qp)) {
        queue_get(qp, (void**)&n);
        e = n->head;
        while (e != NULL) {
            d = e->dst;
            if (d->color == WHITE) {
                d->color = GREY;
                d->dist = n->dist + 1;
                d->pred = n;
                queue_put(qp, (void*)d);
            }
            e = e->next;
        }
        n->color = BLACK;
    }
    queue_dispose(qp, NULL);
}

// This part is added to the code
void graph_dispose(graph_t* g) {
    vertex_t* curr_v = g->g;
    vertex_t* next_v;
    while (curr_v != NULL) {
        edge_t* curr_e = curr_v->head;
        edge_t* next_e;
        while (curr_e != NULL) {
            next_e = curr_e->next;
            free(curr_e);
            curr_e = next_e;
        }
        next_v = curr_v->next;
        free(curr_v);
        curr_v = next_v;
    }
    free(g);
}

// This part is added to the code
int main(int argc, char* argv[]) {
    int i;
    graph_t* g;
    vertex_t* src;
    vertex_t* n;
    if (argc < 2) {
        printf("Usage: %s <graph_file>\n", argv[0]);
        return 1;
    }

    g = graph_load(argv[1]);
    printf("Initial vertex? ");
    scanf("%d", &i);
    src = graph_find(g, i);

    graph_attribute_init(g);
    graph_bfs(g, src);

    n = g->g;
    printf("List of vertices:\n");
    while (n != NULL) {
        if (n->color != WHITE) {
            printf("%2d: %d (%d)\n",
                   n->id, n->dist, n->pred ? n->pred->id : -1);
        }
        n = n->next;
    }

    graph_dispose(g);
    return 0;
}