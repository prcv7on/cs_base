/*
 * @lc app=leetcode.cn id=102 lang=c
 *
 * [102] 二叉树的层次遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1024
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
typedef struct TreeNode TN;

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(TN* root, int* sz, int** csz) {
    if (root==NULL) {
        *sz=0;
        return NULL;
    }
    TN* qe[MAXSIZE];//环形队列qe
    int beg=0,tail,i=0,k=0,num;
    int** rt=(int**)malloc(MAXSIZE*sizeof(int*));
    *csz=(int*)malloc(MAXSIZE*sizeof(int));
    tail=1;
    qe[tail]=root;
    while (beg != tail) {
        num=(tail-beg+MAXSIZE)%MAXSIZE;
        (*csz)[k]=num;
        rt[k]=(int*)malloc(num*sizeof(int));
        for (i=0;i<num;++i) {
            beg=(beg+1)%MAXSIZE;
            rt[k][i]=qe[beg]->val;
            if (qe[beg]->left != NULL) {
                tail=(tail+1)%MAXSIZE;
                qe[tail]=qe[beg]->left;
            }
            if (qe[beg]->right != NULL) {
                tail=(tail+1)%MAXSIZE;
                qe[tail]=qe[beg]->right;
            }
        }
        ++k;
    }
    *sz=k;
    return rt;
}


// @lc code=end

int main(void) {
    TN a,b,c,d,e,f;
    a.val=3; a.left=&b;  a.right=&c;
    b.val=9; b.left=NULL;b.right=NULL;
    c.val=20;c.left=&d;  c.right=&e;
    d.val=15;d.left=NULL;d.right=NULL;
    e.val=7; e.left=NULL;e.right=NULL;
    int row=0;
    int* col;
    int** rt=levelOrder(&a,&row,&col);
    //printf("row=%d,*col=%d\n",row,*col);
    for (int i=0;i<row;++i) {
        for (int j=0;j<col[i];++j) {
            printf("%2d ",rt[i][j]);
        }
        printf("\n");
    }

    // int a=1023;
    // int b1=a%1024;
    // int b2=a & 1023;
    // printf("b1=%d,b2=%d\n",b1,b2);


    return 0;
}