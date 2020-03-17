/*
 * @lc app=leetcode.cn id=515 lang=c
 *
 * [515] 在每个树行中找最大值
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
#include <limits.h>
#define MAXSIZE 1024
// struct TreeNode {
//     int val;
//     struct TreeNode *left;
//     struct TreeNode *right;
// };
typedef struct TreeNode TN;

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* largestValues(TN* root, int* sz) {
    if (!root) {*sz=0;return 0;}
    int* rt=(int*)malloc(MAXSIZE*sizeof(int));
    TN* qe[MAXSIZE];TN* p;
    int beg=0,tail=1,k=0,max,num,i;
    max=root->val;
    rt[k]=max;
    qe[0]=root;
    while (beg != tail) {
        num=(tail-beg+MAXSIZE) & 1023;
        for (i=0;i<num;++i) {
            p=qe[beg];
            max=p->val > max ? p->val : max;
            if (p->left != NULL) {
                qe[tail]=p->left;
                tail=(tail+1) & 1023;
            }
            if (p->right != NULL) {
                qe[tail]=p->right;
                tail=(tail+1) & 1023;
            }
            beg=(beg+1) & 1023;
        }
        rt[k++]=max;
        max=qe[beg] ? qe[beg]->val : INT_MIN;
    }
    *sz=k;
    return rt;
}


// @lc code=end


int main() {
    // TN a1,a2,a3,a4,a5,a6;
    // a1.val=1;a1.left=&a2; a1.right=&a3;
    // a2.val=3;a2.left=&a4; a2.right=&a5;
    // a3.val=2;a3.left=NULL;a3.right=&a6;
    // a4.val=5;a4.left=NULL;a4.right=NULL;
    // a5.val=3;a5.left=NULL;a5.right=NULL;
    // a6.val=9;a6.left=NULL;a6.right=NULL;

    TN a1,a2;
    a1.val= 0;a1.left=&a2;a1.right=NULL;
    a2.val=-1;a2.left=NULL;a2.right=NULL;

    int sz;
    int* maxv=largestValues(&a1,&sz);
    printf("sz=%d\n",sz);

    for (int i=0;i<sz;++i) {
        printf("%d ",maxv[i]);
    }
    printf("\n");


}
