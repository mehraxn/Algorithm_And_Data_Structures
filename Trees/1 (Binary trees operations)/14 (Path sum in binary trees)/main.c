#include <stdbool.h>
#include <stdio.h>


struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };


bool hasPathSum(struct TreeNode *, int );
void pre_order(struct TreeNode * ,int  ,int *);


bool hasPathSum(struct TreeNode* root, int targetSum){

    if (root==NULL)
        return false;
    else if (targetSum==root->val && root->right == NULL && root->left==NULL)
        return true;
    else
        targetSum=targetSum-(root->val);


    int flag=0;
    pre_order(root->right,targetSum,&flag);
    pre_order(root->left,targetSum,&flag);

    if (flag==0)
        return false;
    else if (flag==1)
        return true;
    else
        return false;
}


void pre_order(struct TreeNode * root ,int target ,int * flag){

    if (root==NULL)
        return;

    else if (root->right==NULL && root->left==NULL && root->val == target)
        (*flag)=1;

    pre_order(root->right,target - root->val,flag);
    pre_order(root->left,target - root->val,flag);


}