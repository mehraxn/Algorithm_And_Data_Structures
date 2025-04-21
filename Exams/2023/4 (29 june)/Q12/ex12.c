#include <stdio.h>
#include <stdlib.h>


typedef struct node_t node_t;

struct node_t {
    int key;
    node_t *first_child;
    node_t *brother;
};

node_t *newNode(int key);
void visitTree(node_t *root);
int countLevel(node_t *root, int l, int maxL, int maxC);
int getDepth(node_t *root, int l);
void recursiveCountLevel(node_t *root, int *levelCounter, int l);
int display_crowded_depth (node_t *root);
void printLevel(node_t *root, int levelToPrint, int l);

int main() {

    node_t *root;
    root = newNode(17);
        root->first_child = newNode(22);
            root->first_child->first_child = newNode(1);
                root->first_child->first_child->first_child = newNode(9);
            root->first_child->first_child->brother = newNode(5);
        root->first_child->brother = newNode(2);
            root->first_child->brother->first_child = newNode(12);
        root->first_child->brother->brother = newNode(31);
            root->first_child->brother->brother->first_child = newNode(7);
                root->first_child->brother->brother->first_child->first_child = newNode(3);
            root->first_child->brother->brother->first_child->brother = newNode(4);
                root->first_child->brother->brother->first_child->brother->first_child = newNode(15);


    printf("Depth: %d\n", getDepth(root, 0));
    printf("Maximum level: %d\n", display_crowded_depth(root));

    return 0;
}

node_t *newNode(int key) {
    node_t *n;
    n = malloc(sizeof(node_t));
    n->key = key;
    n->brother = NULL;
    n->first_child = NULL;
    return n;
}

void visitTree(node_t *root) {
    if(root == NULL)
        return;

    node_t *tmp;
    tmp = root;
    while(tmp != NULL) {
        printf("%d\n", tmp->key);
        visitTree(tmp->first_child);
        tmp = tmp->brother;
    }
    return;
}

//Returns the depth of the tree
int getDepth(node_t *root, int l) {
    if(root == NULL ) return l-1;

    int maxL = -1;
    int tmpL = -1;
    node_t *tmp;
    tmp = root;

    tmpL = getDepth(root->first_child, l+1);
    if(tmpL > maxL ) maxL = tmpL;

    tmpL = getDepth(root->brother, l);
    if(tmpL > maxL ) maxL = tmpL;


    return maxL;
}

//Returns the depth of the level with the most amount of nodes
int display_crowded_depth (node_t *root) {
    int maxL = 0;
    int *levelCounter = calloc(getDepth(root, 0)+1, sizeof(int));   //Array with the same size as the depth of the tree, containting the number of nodes in each level
    if(levelCounter == NULL) return -1;
    recursiveCountLevel(root, levelCounter, 0);         //Fills the array with the number of nodes in each level
    for(int i = 0; i < getDepth(root, 0)+1; i++)        //For each element in the array
        if(levelCounter[i] > levelCounter[maxL])          //If the i-th level has more nodes than the current level with the most nodes
            maxL = i;                                     //The i-th level becomes the new maxL

    printLevel(root, maxL, 0);               //We then print all the nodes at the specified level
    free(levelCounter);
    return maxL;
}

void recursiveCountLevel(node_t *root, int *levelCounter, int l) {
    if(root == NULL) return;

    levelCounter[l]++;                                                  //We add 1 to the counter for our current level
    recursiveCountLevel(root->brother, levelCounter, l);           //We then recursively pass to our brother within the same level
    recursiveCountLevel(root->first_child, levelCounter, l+1);  //And finally to our first_child to the next level
    return;
}

void printLevel(node_t *root, int levelToPrint, int l) {
    if(root == NULL) return;

    if(l == levelToPrint)                                      //If the level of the node we are currently on is the level we want to print
        printf("%d ", root->key);                       //We print the key of the current node

    printLevel(root->brother, levelToPrint, l);           //We then call recursively to our brother
    printLevel(root->first_child, levelToPrint, l+1);  //And to our first child
    return;
}