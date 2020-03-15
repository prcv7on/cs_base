/*
 * @lc app=leetcode.cn id=105 lang=c
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
#include <stdbool.h>
#include <math.h>

// struct TreeNode {
// 	int val;
// 	struct TreeNode *left;
// 	struct TreeNode *right;
// };
typedef struct TreeNode TN;

TN* buildTree(int* preorder, int psz, int* midorder, int msz) {
    if (psz <= 0) return NULL;
    TN* root = (TN*)malloc(sizeof(TN));
    root->val = preorder[0];
    int idx = 0;
    while (idx < midorder && midorder[idx] != preorder[0]) ++idx;

    root->left = buildTree(preorder + 1, idx, midorder, idx);
    root->right = buildTree(preorder + 1 + idx, psz - (idx + 1), midorder + idx + 1, msz - (idx + 1));

    return root;
}


// @lc code=end


int main() {
    // TN a,b,c,d,e,f;
    // a.val=3; a.left=&b;  a.right=&c;
    // b.val=9; b.left=NULL;b.right=NULL;
    // c.val=20;c.left=&d;  c.right=&e;
    // d.val=15;d.left=&f;d.right=NULL;
    // e.val=7; e.left=NULL;e.right=NULL;
    // f.val=6; f.left=NULL;f.right=NULL;

    int pa[5]={3,9,20,15,7};
    int ma[5]={9,3,15,20,7};

    TN* btree = buildTree(pa,5,ma,5);


    return 0;
}


