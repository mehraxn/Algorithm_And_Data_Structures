#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
 };

int count (struct TreeNode *root){
    if (root==NULL)
        return 0;

    int l,r ;

    l=count(root->left);
    r=count(root->right);

    return r+l+1;
}

void in_order (int * array , int * pos , struct TreeNode* root ){

    if (root==NULL)
        return;
    in_order(array,pos,root->left);
    array[(*pos)]=root->val;
    (*pos)++;
    in_order(array,pos,root->right);


    return;
}

int check(int *array , int size){
    int flag=1;
    for(int i =0 ; i<size-1 ; i++){
        if (array[i]<array[i+1])
            continue;
        else
            flag=0;


    }
    return flag;

}

bool isValidBST(struct TreeNode* root) {
    int count_node =count(root);
    int *arr = (int *)malloc(count_node * sizeof(int)) ;
    int pos=0;
    in_order(arr,&pos,root->left);
    arr[pos++]=root->val;

    in_order(arr,&pos,root->right);
    int flag= check(arr,count_node);

    free(arr);
    if (flag)
        return true;
    else
        return false;


}