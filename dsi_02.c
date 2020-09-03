
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
// #include <math.h>


//11 二叉树的实现以及存储结构

//11.1 为什么需要树这种数据结构
//分层次的组织具有更高的效率
//静态查找: 要查找的数据固定不变
//动态查找: 要查找的数据动态变化

//11.1.1 从二分查找到二叉树
//静态查找中，顺序查找的时间复杂度为O(n)
//二分查找时间复杂度为O(logn), 需要让数据排好序，使得查找过程更加高效
//查找树和二分查找在效率上一样，其最大优点: 在树里面新增和删除元素要比数组方便的多，所以，树这种结构不仅查找效率高，而且可以很好的实现动态查找

//二分查找基本步骤:
//(1) 给出要查找的元素 key，将第一个元素置为 low，下标为 0；最后一个元素置为 high，下标为 length-1
//(2) mid=(low+high)/2 将 key 与序列中下标为 mid 的元素进行比较。
//(3) 若 key 的值与下标为 mid 值相等，返回 mid
//(4) 如果 key 的值>下标为 mid 的值，则 low=mid+1；若果 key 的值<下标的值，则 high=mid-1
//(5) 再将 key 与 mid 的值比较，重复 3、4 步骤，直至找出与 key 相等的元素的下标
//(6) 如果序列中不存在这样一个元素与 key 的值相等，则返回 -1

/*
//递归
int binarySearch1(int* a, int l, int r, int x) {
    if (r>=l) {
        int mid=l+((r-l)>>1);
        if (a[mid] == x) return mid;
        else if (a[mid] > x) return binarySearch1(a,l,mid-1,x);
        else return binarySearch1(a,mid+1,r,x);
    }
    return -1;
}
//迭代
int binarySearch2(int* a, int l, int r, int x) {
    while (r>=l) {
        int mid=l+((r-l)>>1);
        if (a[mid] == x) return mid;
        else if (a[mid] > x) r = mid-1;
        else l = mid+1;
    }
    return -1;
}
*/

//11.2 树的定义: 由n个有限节点组成一个具有层次关系的集合。
// 具有以下的特点：
//(1) 每个节点都只有有限个子节点或无子节点；
//(2) 没有父节点的节点称为根节点；
//(3) 每一个非根节点有且只有一个父节点；
//(4) 除了根节点外，每个子节点可以分为多个不相交的子树；
//(5) 树里面没有任何的环路。

//11.3 二叉树的定义
//二叉树最多有2棵子树
//满二叉树: 一颗二叉树，其所有的分支节点都有左子树和右子树，并且所有的叶子节点都在同一层上。

//11.3.1 完全二叉树
//完全二叉树是由满二叉树引出来的。
//对于深度K，有n个结点的二叉树，当且仅当其每一个结点都与深度为 K 的满二叉树中编号从 1 至 n 的结点一一对应时称之为完全二叉树。
//完全二叉树要求最后一层的子节点都靠左

//11.4 二叉树存储结构
//11.4.1 顺序存储结构
//不是二叉树，想用数组存储很困难. 完全二叉树很容易用数组来存储它
//下面的结论:
//(1)非根节点i, 父节点序号floor(i/2)
//(2)节点i, 左孩子序号2^i
//(3)节点i, 右孩子序号2^i+1

//11.4.2 链式存储结构

// typedef struct TreeNode {
//     int val;
//     struct TreeNode* left;
//     struct TreeNode* right;
// }TN;
//对于完全二叉树，用数组无需存储额外的左右子节点指针，节省内存。

//11.5 小试牛刀
//(1) 高度为 7 的完全二叉树的节点总数不可能是: h=7,则应该[127,255]
//(2) 什么样的二叉树适合用数组来存储？ --> 完全二叉树，那用对其用数组来存储无疑是最节省内存且最优的一种方式。
//(3) 给定一个数组，比如 1，2，3，4，5。可以构建出多少种不同的二叉树？   n!
//(4) 求出一个二叉树的深度。

// int getTreeDepth(TN* p) {
//     if (p==NULL) return 0;
//     int l=getTreeDepth(p->left);
//     int r=getTreeDepth(p->right);
//     return l>=r ? l+1 : r+1;
// }

//(5) 给出一个完全二叉树，求出其节点个数。
//在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最后一层的节点全部靠向左边。
//可将问题简化为: 计算完全二叉树最后一层有多少个节点。

/*
int computeDepth(TN* p) {
    int d=0;
    while (p->left != NULL) {
        p=p->left;
        ++d;
    }
    return d;
}

bool exists(int idx, int d, TN* p) {
    int l=0, r = (1<<d) -1;
    int pivot;
    for (int i=0;i<d;++i) {
        pivot=l+((r-l)>>1);
        if (idx<=pivot) {
            p=p->left;
            r=pivot;
        }
        else {
            p=p->right;
            l=pivot+1;
        }
    }
    return p!=NULL;
}

int countNodes(TN* p) {
    if (p==NULL) return 0;
    int d=computeDepth(p);
    if (d==0) return 1;
    
    int l=1, r = 1<<d - 1;
    int pivot;
    while (l<=r) {
        pivot=l+((r-l)>>1);
        if (exists(pivot,d,p)) l=pivot+1;
        else r=pivot-1;
    }

    return (1<<d)-1+l;
*/

//11.6 小结
// 二分查找
// 从二分查找引出二叉树：从一个侧面讲述我们为什么设计出树这种数据结构
// 树以及二叉树的定义
// 二叉树的存储结构：数组和链表存储

//11.7 思考
// 本文通过完全二叉树这个特殊的二叉树串联起来了二叉树的理论和存储结构这两个部分，
// 那么，你知道如何通过编程，来判断一棵树是不是完全二叉树呢？

/*
int main(void) {
    //int arr[9]={0,2,4,5,16,20,35,40,59};
    // int idx1=binarySearch1(arr,0,8,40);
    // int idx2=binarySearch2(arr,0,8,40);
    // printf("idx1=%d, idx2=%d\n",idx1,idx2);//7,7

    // TN n1,n2,n3,n4,n5,n6;
    // n1.val=1; n2.val=2; n3.val=3; n4.val=4; n5.val=5; n6.val=6;
    // n1.left=&n2; n1.right=&n3;
    // n2.left=&n4; n2.right=NULL;
    // n3.left=&n5; n3.right=NULL;
    // n4.left=NULL; n4.right=&n6;
    // n5.left=NULL; n5.right=NULL;
    // n6.left=NULL; n6.right=NULL;
    // int d= getTreeDepth(&n1);
    // printf("d=%d\n",d);

    TN n1,n2,n3,n4,n5,n6;
    n1.val=1; n2.val=2; n3.val=3; n4.val=4; n5.val=5; n6.val=6;
    n1.left=&n2; n1.right=&n3;
    n2.left=&n4; n2.right=&n5;
    n3.left=&n6; n3.right=NULL;
    n4.left=NULL; n4.right=NULL;
    n5.left=NULL; n5.right=NULL;
    n6.left=NULL; n6.right=NULL;
    int cnt_node=countNodes(&n1);
    printf("cnt_node=%d\n",cnt_node);

    return 0;
}
*/



//12 二叉树的四大遍历方法
//树遍历是对树中的每个节点只访问一次的过程。
//不同的遍历方法把树的节点展开成列表的方式，而每种遍历方法都能从树中更加直观的提取出来一些信息。

// typedef struct TreeNode {
//     int val;
//     struct TreeNode* left;
//     struct TreeNode* right;
// }TN;

//12.1 前序遍历： 根->左->右
//(1) 递归
//(2) 栈代替递归函数的函数栈。主要思想: 
//先将根节点压入栈，然后根节点出栈并访问根节点，而后依次将根节点的右孩子、左孩子入栈，直到栈为空

/*
// void PreOrder(TN* p, int* a, int* idx) {
//     if (p==NULL) return;
//     a[(*idx)++]=p->val;
//     PreOrder(p->left,a,idx);
//     PreOrder(p->right,a,idx);
// }

// int* PreOrderTraversal(TN* p, int* sz) {
//     int idx=0;
//     int* arr=(int*)malloc(16*sizeof(int));
//     memset(arr,0,16*sizeof(int));
//     PreOrder(p,arr,&idx);
//     *sz=idx;
//     return arr;
// }

int* PreOrderTraversal(TN* p, int* sz) {
    if (p==NULL) return 0;
    if (p->left==NULL && p->right==NULL) {
        *sz=1;
        return &(p->val);
    }
    int* arr=(int*)malloc(16*sizeof(int));
    TN** stk=(TN**)malloc(16*sizeof(TN*));
    int top=-1;
    stk[++top]=p;
    while (top != -1) {
        p=stk[top--];
        arr[(*sz)++]=p->val;
        if (p->right) stk[++top]=p->right;
        if (p->left) stk[++top]=p->left;
    }
    free(stk);
    return arr;
}
*/

//12.2 中序遍历： 左->根->右
//(1) 递归
//(2) 栈代替递归函数的函数栈。主要思想: 
//将根节点开始直到最左叶子节点这条路径上所有的节点压入栈，然后最左叶子节点出栈并访问它，
//而后，同样方法去处理该叶子节点的右子树，直到栈为空

/*
// void MidOrder(TN* p, int* a, int* idx) {
//     if (p==NULL) return;
//     MidOrder(p->left,a,idx);
//     a[(*idx)++]=p->val;
//     MidOrder(p->right,a,idx);
// }

// int* MidOrderTraversal(TN* p, int* sz) {
//     int idx=0;
//     int* arr=(int*)malloc(16*sizeof(int));
//     memset(arr,0,16*sizeof(int));
//     MidOrder(p,arr,&idx);
//     *sz=idx;
//     return arr;
// }

int* MidOrderTraversal(TN* p, int* sz) {
    if (p==NULL) return 0;
    if (p->left==NULL && p->right==NULL) {
        *sz=1;
        return &(p->val);
    }
    int* arr=(int*)malloc(16*sizeof(int));
    TN** stk=(TN**)malloc(16*sizeof(TN*));
    int top=-1;
    while (p || top != -1) {
        while (p) {         //将根节点开始直到最左叶子节点, 这条路径上所有节点压入栈
            stk[++top]=p;
            p=p->left;
        }
        p=stk[top--];
        arr[(*sz)++]=p->val;
        p=p->right;
    }
    free(stk);
    return arr;
}
*/

//12.3 后序遍历： 左->右->根
//(1) 递归
//(2) 栈代替递归函数的函数栈。主要思想: 
//略微不同的是，遍历到某节点前，要将该节点的左右子树的所有节点都完成入栈和出栈操作。

/*
// void PostOrder(TN* p, int* a, int* idx) {
//     if (p==NULL) return;
//     PostOrder(p->left,a,idx);
//     PostOrder(p->right,a,idx);
//     a[(*idx)++]=p->val;
// }

// int* PostOrderTraversal(TN* p, int* sz) {
//     int idx=0;
//     int* arr=(int*)malloc(16*sizeof(int));
//     memset(arr,0,16*sizeof(int));
//     PostOrder(p,arr,&idx);
//     *sz=idx;
//     return arr;
// }

// int* postorderTraversal(TN* root, int* sz) {
// 	*sz = 0;
// 	if (!root) return 0;
// 	if (!root->left && !root->right) {
// 		*sz = 1;
// 		return &(root->val);
// 	}
// 	int* ret = (int*)malloc(90 * sizeof(int));
// 	TN** stack = (TN**)malloc(90 * sizeof(TN*));
// 	TN* pre = NULL;
// 	int cnt = -1;
// 	while (root || cnt != -1) {
// 		while (root) {
// 			stack[++cnt] = root;
// 			root = root->left;
// 		}
// 		root = stack[cnt];
// 		if (root->right && root->right != pre) { //栈顶右子树存在且没被访问
// 			root = root->right;
// 		}
// 		else {									 //栈顶右子树不存在或已被访问过
// 			--cnt;
// 			ret[(*sz)++] = root->val;
// 			pre = root;
// 			root = NULL;		//防止栈顶左子树重复进栈
// 		}
// 	}
// 	return ret;
// }

int* PostOrderTraversal(TN* p, int* sz) {
    if (p==NULL) return 0;
    if (p->left==NULL && p->right==NULL) {
        *sz=1;
        return &(p->val);
    }
    int* arr=(int*)malloc(16*sizeof(int));
    TN** stk=(TN**)malloc(16*sizeof(TN*));
    TN* cur=NULL;
    int top=-1;
    stk[++top]=p;
    while (p || top != -1) {
        printf("val=%d, top=%d\n",p->val, top);
        if (top==-1) break; //回到根节点，立即退出。
        cur=stk[top];
        if (cur->left && p!=cur->left && p!=cur->right)
            stk[++top]=cur->left;
        else if (cur->right && p!=cur->right)
            stk[++top]=cur->right;
        else {
            arr[(*sz)++]=stk[top--]->val;
            p=cur;
        }
    }
    free(stk);
    return arr;
}
*/

//12.4 广度优先遍历（层次遍历）
//(1) 递归
//(2) 队列存储数据
//注意: 要获取并得到每一层的节点数量，在得到一个子链表之后，队列中应存储下一层的所有节点

/*
#define MAXSIZE 16
void bfs(TN* p, int** rt, int* csz, int i, int* maxh) {
    if (p) {
        rt[i][csz[i]]=p->val;
        ++csz[i];
        if (i+1 > *maxh) *maxh=i+1;
        bfs(p->left, rt,csz,i+1,maxh);
        bfs(p->right,rt,csz,i+1,maxh);
    }
}

int** LevelOrder(TN* p, int* sz, int** csz) {
    int bn=MAXSIZE*sizeof(int*);
    int** rt=(int**)malloc(bn);
    *csz=(int*)malloc(bn);
    for (int i=0;i<MAXSIZE;++i) {
        rt[i]=(int*)malloc(bn);
    }
    *sz=0;
    if (p==NULL) return NULL;
    bfs(p,rt,*csz,0,sz);
    return rt;
}

// int** levelOrder(TN* root, int* sz, int** csz) {
//     if (root==NULL) {
//         *sz=0;
//         return NULL;
//     }
//     TN* qe[MAXSIZE];//环形队列qe
//     int beg=0,tail,i=0,k=0,num;
//     int** rt=(int**)malloc(MAXSIZE*sizeof(int*));
//     *csz=(int*)malloc(MAXSIZE*sizeof(int));
//     tail=1;
//     qe[tail]=root;
//     while (beg != tail) {
//         num=(tail-beg+MAXSIZE)%MAXSIZE;
//         (*csz)[k]=num;
//         rt[k]=(int*)malloc(num*sizeof(int));
//         for (i=0;i<num;++i) {
//             beg=(beg+1)%MAXSIZE;
//             rt[k][i]=qe[beg]->val;
//             if (qe[beg]->left != NULL) {
//                 tail=(tail+1)%MAXSIZE;
//                 qe[tail]=qe[beg]->left;
//             }
//             if (qe[beg]->right != NULL) {
//                 tail=(tail+1)%MAXSIZE;
//                 qe[tail]=qe[beg]->right;
//             }
//         }
//         ++k;
//     }
//     *sz=k;
//     return rt;
// }
*/

//12.5 四种遍历的选择
//(1) 前、中、后以及广度优先遍历都能视为是一个递归的过程。
//(2) 二叉树的前、中、后遍历都可以归结为深度优先遍历，即先访问根结点，后选择一子结点访问并访问该节点的子结点，持续深入后再依序访问其他子树。
//而广度优先遍历会先访问离根节点最近的节点。
//(3) 四种遍历中每个节点最多会被访问两次. 时间复杂度，跟节点的个数 n 成正比, O(n)
//(4) 针对不同的应用场景我们可以使用不同的遍历方法来解决问题
//对于查找二叉树，对其中序遍历可得到一个有序序列

//12.6 小试牛刀
//12.6.1 已知中序和后序求前序
//已知二叉树的中序遍历顺序为 DBAGEHCF，后序遍历顺序为 DBGHEFCA，求该二叉树的前序遍历。
//ABCDEGHF

//12.6.2 已知前序和中序求后序
//前序：1, 2, 3, 4, 5, 6
//中序：3, 2, 4, 1, 6, 5
//342651

//12.6.3 编程实现 ZigZag 遍历

//12.7 小结
// 前序遍历介绍和实现
// 中序遍历介绍和实现
// 后序遍历介绍和实现
// 层次遍历介绍和实现

//12.8 课后思考
//你能再举出一些你在平时遇到的二叉树遍历的应用实例吗？

/*
void printArr(int* a, int n) {
    printf("ret= ");
    for (int i=0;i<n;++i) {
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main(void) {
    TN a, b, c, d, e, f;
	a.val = 3; a.left = &b; a.right = &c;
	b.val = 4; b.left = &d; b.right = &e;
	c.val = 5; c.left = &f; c.right = NULL;
	d.val = 6; d.left = NULL; d.right = NULL;
	e.val = 7; e.left = NULL; e.right = NULL;
	f.val = 8; f.left = NULL; f.right = NULL;

    int sz=0;
    //int* arr=PreOrderTraversal(&a,&sz); //346758
    //int* arr=MidOrderTraversal(&a,&sz); //647385
    //int* arr=PostOrderTraversal(&a,&sz); //674853
    //printArr(arr,sz);

    int row=0;
    int* col;
    int** rt=LevelOrder(&a,&row,&col);
    //printf("row=%d,*col=%d\n",row,*col);
    for (int i=0;i<row;++i) {
        for (int j=0;j<col[i];++j) {
            printf("%2d ",rt[i][j]);
        }
        printf("\n");
    }

    return 0;
}
*/



//



//13 二叉查找树的优势
//二叉查找树: 将链表插入、删除的灵活性以及有序数组查找的高效性结合
//二叉查找树具有以下属性：
//(1) 节点的左子树仅包含小于该节点的其他节点。
//(2) 节点的右子树仅包含大于该节点的其他节点。
//(3) 节点的左，右子树都必须是二叉查找树。

// typedef struct BinarySearchTree {
//     int key;
//     struct BinarySearchTree* left;
//     struct BinarySearchTree* right;
// }BST;

//13.1 二叉查找树的插入
//如果查找二叉树为空，直接将新元素作为根节点；
//如果元素已存在，则不再插入

/*
//递归
BST* insertKey(BST* root, int Key) {
    if (root==NULL) {
        BST* root=(BST*)malloc(sizeof(BST));
        root->key=Key;
        root->left=root->right=NULL;
        return root;
    }
    if (Key < root->key) root->left=insertKey(root->left, Key);
    if (Key > root->key) root->right=insertKey(root->right, Key);
    return root; //指向根节点
}

//迭代
// BST* insertKey(BST* root, int Key) {
//     BST** p=&root;
//     while (p[0]) {
//         p = p[0]->key > Key ? &(p[0]->left) : &(p[0]->right);
//     }
//     p[0]=(BST*)malloc(sizeof(BST));
//     p[0]->key=Key;
//     p[0]->left=p[0]->right=NULL;
//     return p[0]; //指向被插入的节点
// }
*/

//13.2 二叉查找树的删除
//13.2.1 删除搜索二叉树的叶子节点
//(1) 要删除的节点仅存在一个子节点
//只需让该节点的父结点指向该节点的子节点，然后删除该节点
//(2) 要删除的节点仅存在2个子节点
//(2.1)从右子树中选择一个值替换被删除的节点
//由于被删节点右子树的值都大于被删节点的值，所以将右子树最小值(即最左孩子)复制被删节点位置（或与被删节点交换），然后再删除此右子树中的最小值节点
//同样，删除此右子树中的最小值节点同样又分为3种情况，即要删除的元素是搜索二叉树的叶子节点、被删元素存在1/2个子节点。如此循环，就完成了对该节点的删除
//(2.2)从左子树中选择一个值替换被删除的节点
//(3)中序遍历二叉查找树，可输出有序序列，时间复杂度O(n)
//二叉查找树 也称 二叉排序树

/*
int minValue(BST* root) {
    int minv=root->key;
    while (root->left != NULL) {
        minv=root->left->key;
        root=root->left;
    }
    return minv;
}

BST* deleteBST(BST* root, int key) {
    if (root == NULL) return root;
    if (key < root->key) root->left=deleteBST(root->left,key);
    else if (key > root->key) root->right=deleteBST(root->right,key);
    else {
        if (root->left == NULL) return root->right;
        else if (root->right == NULL) return root->left;
        root->key=minValue(root->right);
        root->right=deleteBST(root->right,root->key);
    }
    return root;
}

void deleteKey(BST* root, int key) {
    root=deleteBST(root,key);
}
*/

//13.3 二叉树中的最大二叉搜索树
//问题的具体描述：给定一个二叉树，找到其中最大的二叉搜索树（BST）子树的节点个数，最大是指子树节点数最多
//to do

/*
int* MidOrderTraversal(BST* p, int* sz) {
    if (p==NULL) return 0;
    if (p->left==NULL && p->right==NULL) {
        *sz=1;
        return &(p->key);
    }
    int* arr=(int*)malloc(16*sizeof(int));
    BST** stk=(BST**)malloc(16*sizeof(BST*));
    int top=-1;
    while (p || top != -1) {
        while (p) {         //将根节点开始直到最左叶子节点, 这条路径上所有节点压入栈
            stk[++top]=p;
            p=p->left;
        }
        p=stk[top--];
        arr[(*sz)++]=p->key;
        p=p->right;
    }
    free(stk);
    return arr;
}

void printTree(int* a, int n) {
    printf("tree= ");
    for (int i=0;i<n;++i) {
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main(void) {
    BST a,b,c,d;
    a.key=4; a.left=&b; a.right=&c;
    b.key=2; b.left=&d; b.right=NULL;
    c.key=5; c.left=NULL; c.right=NULL;
    d.key=1; d.left=NULL; d.right=NULL;
    // BST* p=insertKey(&a,3);
    deleteKey(&a,2);
    // printf("p->key=%d\n",p->key);

    int sz=0;
    int* arr=MidOrderTraversal(&a,&sz);//1 2 3 4 5
    printTree(arr,sz);
    
    return 0;
}
*/

//13.4 小试牛刀
//(1) 判断一棵树是不是二叉查找树
//中序遍历，如果其是有序的，说明是二叉查找树，反之，则不是。
//(2) 对一个二叉查找树如何进行范围查找
//中序遍历返回一个有序数组，然后可以根据这个数组来范围查找
//(3) 二叉查找树效率问题
//查找效率十分依赖于树中节点的拓扑结构，也就是节点间的布局关系。

//13.5 小结</h3>
// 为什么设计二叉查找树
// 二叉查找树的插入操作
// 二叉查找树的删除操作（分三种情况讨论）

//13.6 课后思考
//几个问题：二叉查找树的插入和删除等操作的性能和什么有关呢？
//什么情况下，二叉查找树的插入、删除、查找操作的时间复杂度最差呢？你能想到什么办法来解决这种问题呢？



//14 平衡查找树AVL的强大威力
//14.1 有了查找二叉树，为什么还需要平衡二叉树?
//只有查找二叉树中的节点以扇形结构散开，在查找节点时，每次比较操作都会将剩余节点数减少一半。即，时间复杂度为O(logn)
//同样的，对该查找二叉树的插入、删除和查找操作都可达到最优的运行时间 O(logn)
//(1)节点的高度: 该节点到叶子节点的最长路径
//(2)AVL树: 任意节点的2棵子树的高度差<=1

typedef struct BlancedBinaryNode {
    int key,height;
    struct BlancedBinaryNode* left;
    struct BlancedBinaryNode* right;
}BBT;

BBT* createNode(int d) {
    BBT* p=(BBT*)malloc(sizeof(BBT));
    p->key=d;
    p->height=1;
}

//14.2 平衡二叉树的插入操作
//(1)查找二叉树的插入操作
//(2)二叉树重新平衡

//14.2.1 x节点左旋
//(1)现x右孩  <-- 原x右孩的左孩
//(2)现x父亲  <-- 原x右孩
//14.2.2 y节点右旋 --> 对于根节点y,经过旋转后，其位于现根节点x右边
//(1)现y左孩  <-- 原y左孩的右孩
//(2)现y父亲  <-- 原x左孩

//14.2.3 平衡操作的所有情况
//左左
//左右
//右右
//右左

/*
int height(BBT* p) {
    if (p==NULL) return 0;
    return p->height;
}

int maxh(int h1, int h2) {
    return (h1>h2) ? h1 : h2;
}

int height_diff(BBT* p) {
    if (p==NULL) return 0;
    return height(p->left) - height(p->right);
}

BBT* RotateRight(BBT* y) {
    BBT* x=y->left;
    BBT* xr=x->right;
    x->right=y;
    y->left=xr;
    y->height=maxh(height(y->left), height(y->right)) + 1;
    x->height=maxh(height(x->left), height(x->right)) + 1;
    return x; //新根节点
}

BBT* RotateLeft(BBT* x) {
    BBT* y=x->right;
    BBT* yl=y->left;
    y->left=x;
    x->right=yl;
    x->height=maxh(height(x->left), height(x->right)+1);
    y->height=maxh(height(y->left), height(y->right)+1);
    return y; //新根节点
}

BBT* insertKey(BBT* p, int key) {
    if (p==NULL) return createNode(key);
    if (key < p->key) p->left=insertKey(p->left,key);
    else if (key > p->key) p->right=insertKey(p->right,key);
    else return p;

    p->height= 1 + maxh(height(p->left), height(p->right));
    int dh=height_diff(p);

    if (dh>1 && key < p->left->key)     //左左
        return RotateRight(p);
    if (dh<-1 && key > p->right->key)   //右左
        return RotateLeft(p);
    if (dh>1 && key > p->left->key) {   //左右
        p->left=RotateLeft(p->left);
        return RotateRight(p);
    }
    if (dh<-1 && key < p->right->key) { //右右
        p->right=RotateRight(p->right);
        return RotateLeft(p);
    }

    return p;
}
*/

//14.3 平衡二叉树的删除操作
//(1)查找二叉树的删除操作
//(2)二叉树重新平衡

/*
BBT* minKeyNode(BBT* root) {
    BBT* p=root;
    while (p->left != NULL) {
        p=p->left;
    }
    return p;
}

BBT* deleteKey(BBT* root, int key) {
    if (root==NULL) return root;
    if (key < root->key) root->left=deleteKey(root->left,key);
    else if (key > root->key) root->right=deleteKey(root->right,key);
    else {
        if (root->left==NULL || root->right==NULL) {
            BBT* p=NULL;
            p = root->left == NULL ? root->right : root->left;
            if (p==NULL) {
                p=root;//指向待删节点
                root=NULL;
            }
            else root=p;
        }
        else {
            BBT* p=minKeyNode(root->right);
            root->key=p->key;
            root->right=deleteKey(root->right, p->key);
        }
    }
    if (root==NULL) return root;

    root->height=maxh(height(root->left), height(root->right)) + 1;
    int dh=height_diff(root);
    if (dh>1 && height_diff(root->left)>=0)     //左左
        return RotateRight(root);
    if (dh>1 && height_diff(root->left)<0) {    //左右
        root->left=RotateLeft(root->left);
        return RotateRight(root);
    }
    if (dh<-1 && height_diff(root->right)<=0)   //右右
        return RotateLeft(root);
    if (dh<-1 && height_diff(root->right)>0) {  //右左
        root->right=RotateRight(root->right);
        return RotateLeft(root);
    }
    return root;//新根节点
}
*/

//14.4 时间复杂度分析
//(1)查找: AVL树是严格平衡的。其查找效率稳定为O(logn)
//(2)插入: 若一次插入数据，使得树不平衡，则必须旋转
//事实上，AVL每次插入结点最多只需旋转1次（单旋转或双旋转）。因此，总体插入代价为O(log(n))
//(3)删除: 删除节点后必须检查从该节点到根节点路径上各节点是否平衡。代价稍大。
//每次删除最多需要 O(logN) 次旋转。因此，删除的时间复杂度为：O(log(n))+O(log(n))=O(2log(n))

//14.5 小试牛刀
//14.5.1 二叉树是否是平衡二叉树
//遍历树的每个节点, 左右子树的深度差<=1

/*
int getTreeDepth(BBT* p) {
    if (p==NULL) return 0;
    int l=getTreeDepth(p->left);
    int r=getTreeDepth(p->right);
    return l>=r ? l+1 : r+1;
}

bool isBBT(BBT* root) {
    if (root==NULL) return true;
    int d1=getTreeDepth(root->left);
    int d2=getTreeDepth(root->right);
    int diff=d1-d2;
    if (diff>1 || diff<-1) return false;
    return isBBT(root->left) && isBBT(root->right);
}
*/

//14.5.2 有序数组生成一棵平衡二叉树
//重点是确定平衡二叉树的根节点，然后用这个数左边的数生成左子树，用右边数生成右子树

/*
// BBT* generate(int* a, int beg, int end) {
//     if (beg>end) return NULL;
//     int mid=(beg+end)>>1;
//     BBT* head=createNode(a[mid]);
//     head->left=generate(a,beg,mid-1);
//     head->right=generate(a,mid+1,end);
//     return head;
// }

// BBT* generateBBT(int* a, int len) {
//     if (a==NULL) return NULL;
//     return generate(a,0,len-1);
// }
*/

//14.5.3 为什么还需要平衡二叉树
//散列表可视为哈希表，其插入、删除、查找操作的时间复杂度可做到O(1)，非常高效
//相比较于二叉树，其中数据是无序的，需要输出有序数据时，散列表效率很低；还有，散列表的构造要复杂很多，需要考虑冲突解决办法、扩容、缩容等；
//如上所述，对散列表扩容会很耗时，当遇到散列冲突时，性能不稳定；
//结合具体的需求来选择使用

//14.6 小结</h3>
// 为什么设计平衡二叉树
// 节点左旋、右旋
// 平衡二叉树插入操作
// 平衡二叉树删除操作
// 时间复杂度分析

//14.7  课后思考</h3>
//排序后数组和平衡二叉排序树都可以 O(log2N) 代价，快速根据key定位到value。
//那么为什么不用数组来做这件事，而要选择使用平衡二叉排序树呢？

/*
int* MidOrderTraversal(BBT* p, int* sz) {
    if (p==NULL) return 0;
    if (p->left==NULL && p->right==NULL) {
        *sz=1;
        return &(p->key);
    }
    int* arr=(int*)malloc(16*sizeof(int));
    BBT** stk=(BBT**)malloc(16*sizeof(BBT*));
    int top=-1;
    while (p || top != -1) {
        while (p) {         //将根节点开始直到最左叶子节点, 这条路径上所有节点压入栈
            stk[++top]=p;
            p=p->left;
        }
        p=stk[top--];
        arr[(*sz)++]=p->key;
        p=p->right;
    }
    free(stk);
    return arr;
}

void printTree(int* a, int n) {
    printf("n=%d\n",n);
    printf("tree= ");
    for (int i=0;i<n;++i) {
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main(void) {
    // BBT a,b,c,d,e,f,g;
    // a.key=10; a.left=&b; a.right=&c;
    // b.key= 5; b.left=&d; b.right=&e;
    // //c.key=19; c.left=&f; c.right=NULL;
    // c.key=15; c.left=&f; c.right=NULL;
    // d.key= 2; d.left=NULL; d.right=NULL;
    // e.key= 8; e.left=&g; e.right=NULL;
    // //f.key=14; f.left=NULL; f.right=NULL;
    // f.key=13; f.left=NULL; f.right=NULL;
    // //g.key= 7; g.left=NULL; g.right=NULL;
    // g.key= 6; g.left=NULL; g.right=NULL;

    // BBT* p=insertKey(&a,6);
    // p=insertKey(&a,17);
    // printf("p->key=%d\n",p->key);
    //BBT* p=deleteKey(&a,13);

    int a[9]={1,2,3,4,5,6,7,8,9};
    BBT* p=generateBBT(a,9);

    int sz=0;
    int* arr=MidOrderTraversal(p,&sz);//2 5 6 7 8 10 14 17 19
    //2 5 6 8 10 15
    //1 2 3 4 5 6 7 8 9
    printTree(arr,sz);
    return 0;
}
*/



//15 红黑树的实现和性质
//(1)平衡二叉查找树(AVL)树: 每次插入和删除时，都要进行调整，比较耗时。
//(2)红黑树: 插入、删除、查找等性能稳定。

//15.1 红黑树的性质
//平衡二叉查找树：二叉树中任意一个节点的左右子树高度相差<=1
//15.1.1 R-B Tree除了AVL树的一般要求，还有额外的限定:
//(1) 各节点是红/黑色
//(2) 根节点黑色
//(3) 父节点，子节点之间不能出现连续两个红
//(4) 任何一个节点向下遍历到叶子节点，所经过的黑节点个数必须相等
//(5) 空节点是黑
//15.1.2 强制了红黑树的关键性质：从根到叶子的最长路径 <= 2 * 最短路径
//关键性质导致红黑树大致平衡, 查找、插入、删除某个节点的最坏时间复杂度与树高成比例.
//15.1.3 表格
//
//二叉查找树BST     O(N)    O(logN)     O(logN)     查找的最佳时间复杂度为O(logN), 最坏O(N)
//                                                 插入删除，时间复杂度与查找差不多
//AVL            O(logN)  O(logN)     O(2*logN)   查找的时间复杂度维持在O(logN)
//                                                删除操作时间复杂度O(2*logN)  
//RBTree        O(logN)     O(logN)     O(logN)   查找最好时间复杂度O(logN), 最坏比 AVL 稍微差, 但远比 BST 好
//                                                插入和删除, 改变树的平衡性的概率 << AVL
//                                                插入一个节点最多只需旋转2次，删除最多只需旋转3次

//15.2 红黑树及其操作的实现

//15.2.1 旋转操作
//目的: 使树的颜色符合定义，使其保持平衡。
//(1)c左旋: c节点从右边上升到父节点
//(2)b右旋: b节点从左边上升到父节点

//15.2.2 查找操作
//相等即当、小于即右。大于即左。
//查找操作时，先与当前节点比较：
//(1)相等, 返回当前节点
//(2)<当前节点, 继续查找当前节点的左节点
//(3)>当前节点, 继续查找当前节点的右节点
//cur==NULL || cur=key 查找结束。

//15.2.3 插入操作
//注意两个问题：树的平衡、颜色要求。
//即，插入新节点后，需要按照红黑树的性质对树旋转和颜色修正。
//插入红色节点，插入调整颜色操作若遇到黑色父节点，则修复结束。 只有父节为红色时， 需要插入修复操作。
//
//(1) 不变色是父暗
//(2) 父红，叔不空，叔祖与父换
//(3) 父红，右叔空，右旋，祖与父换
//(4) 叔空，不在一线，旋一线，按 3 换

//(case 1)：叔叔节点红色
//具体操作: 将父节点，叔叔节点与祖父节点的颜色互换。
//操作完成后A变成新节点。若A的父节点不是黑，就重复前面操作
//(case 2)：叔叔节点为空，同时祖父节点、父节点和新节点在一条斜线上
//(2.1)B,C都是左节点: B右旋，并且和父节点A互换颜色
//(2.2)B,C都是右节点: B左旋，并且和父节点A互换颜色
//(case 3)：叔叔节点为空，同时祖父节点、父节点和新节点不在一条斜线上
//(3.1)B是A的左子树，C是B的右子树: C左旋，就成为case2, 再处理。
//(3.2)B是A的右子树，C是B的左子树: C右旋，就成为case2, 再处理。

//插入后调整颜色是向根节点回溯，只要涉及到的节点都符合红黑树定义，颜色调整结束

//15.2.4 删除操作
//总体思路: 从兄弟节点借调黑色节点使得整个树保持局部的平衡，局部平衡达到后，然后再看整体树是否平衡，若不平衡就接着向上回溯进行调整。
//
//(1) 兄红，兄升，借调孩子
//(2) 兄黑，兄子黑，兄变色
//(3) 兄黑，兄左子黑，兄变色，兄树右旋
//(4) 兄黑，右子红，删除，左旋

//(case 1): 待删节点的兄弟是红
//兄弟节点是红色，无法借调黑色节点, 来填补待删的黑色节点
//所以要将兄弟提升到父亲节点, 兄弟的子节点是黑, 从它的子节点借调
//转换后,变成case2,3,4
//上升操作需要将C节点左旋/右旋

//(case 2): 待删节点的兄弟是黑，且兄弟之子是黑
//将待删节点的兄弟变红，使得树的局部复合颜色定义。
//将父节点A变成新节点，继续向上回溯，调整颜色， 直到整个树的颜色符合定义。

//(case 3): 待调整颜色的节点的兄弟是黑，且兄弟的左子节点是红，右节点是黑(兄弟节点在右边)
//如果兄弟节点在左边，兄弟的右子节点是红，左节点是黑
//case3是一个中间步骤， 目的: 借调左边的红色节点，转换为case4
//因为根据定义: 下图是不平衡的，它是case2操作后向上回溯出现的状态。
//case3,4的出现原因: 借助侄子节点的红色变成黑色，来符合定义。

//(case 4): 待调整颜色的节点的兄弟是黑，且右子节点是红(兄弟节点在右边)
//如果兄弟节点在左边，则对应的是左节点是红
//真正的节点借调操作
//目的: 借调两个黑节点 --> 删除了黑色节点，整个树仍符合定义， 因为黑色节点的个数没有改变
//借调兄弟及兄弟的右子节点，将兄弟的右子节点变红

//删除操作总结:
//(1)比较复杂。待删节点黑色时，如何从兄弟节点去借调，从而保持树的颜色符合定义
//(2)删除操作: 在遇到待删节点为红，或追溯调整到根节点，这时删除的颜色调整操作结束。

/*
typedef struct RedBlackNode {
    int val;
    bool isRed;
    struct RedBlackNode* parent;
    struct RedBlackNode* left;
    struct RedBlackNode* right;
}RBN;

RBN* createRBN(int val) {
    RBN* p=(RBN*)malloc(sizeof(RBN));
    p->val=val;
    p->isRed=false;
    p->parent=p->left=p->right=NULL;
    return p;
}

RBN* findKey(RBN* root, int key) {
    while (1) {
        if (root == NULL) break;
        if (root->val == key) return root;
        else if (root->val > key) root=root->left;
        else root=root->right;
    }
    return NULL;
}

void insertKey(RBN* root, int key) {
    RBN* p=createRBN(key);
    RBN* parent=NULL;
    while (1) {
        if (root==NULL) break;
        parent=root;
        if (key <= root->val) root=root->left;
        else root=root->right;
    }
    if (parent != NULL) {
        if (key <= parent->val) parent->left=p;
        else parent->left=p;
    }
}

void RotateLeft(RBN* root, RBN* p) {
    RBN* right = p->right;
    if (right==NULL) {
        printf("right node == NULL !\n");
        return;
    }
    RBN* par=p->parent;
    par->right=p->left;
    p->left->parent=par;
    p->left=par;
    par->parent=p;
    if (par==NULL) {
        root->left=right;
        right->parent=NULL;
    }
    else {
        if (par->left == p) par->left=right;
        else par->right=right;
        right->parent=par;
    }
}
*/

//15.3 大厂面试题
//15.3.1 问：以下哪个数据结构底层是用红黑树实现的？（map ）
//map
//vector: 顺序表，表示的是一块连续的内存。
//list: 双向链表，在内存中不一定连续
//deque: 顺序表，但是在内存空间中是双开口的内存存储机制

//15.3.2 问：采用插入方式构建一颗大小为 n 的红黑树的时间复杂度是多少？
//插入一个元素到红黑树的时间为 log(n)
//采用插入方式构建元素个数为 n 的红黑树 --> n*logn

//15.3.3 关于红黑树和 AVL 树，以下哪种说法不正确？
//红黑树和 AVL 树都属于自平衡二叉树；
//两者查找、插入、删除的时间复杂度相同；
//包含 n 个内部结点的红黑树的高度是 log(n)；
//TreeMap 是一个红黑树的实现，能保证插入的值保证排序。

//15.4 小结
//红黑树的五个性质
//三种操作：查找、插入、删除。

//15.5 课后总结
//证明红黑树的高度最多为 2logN，并证明这个界实质上不能再降低。



//16 B+、B- 树的实现和性质
//二分查找要求数据有序，二叉树查找只能应用于二叉查找树。
//数据库系统，使用一个叫索引的数据结构来查找, 索引的底层原理

//16.1 平衡二叉树
//16.1.1 基于二分法的一种查找速度很快的二叉树结构:
//(1) 所有非叶子结点至多拥有两个子节点（Left 和 Right）；
//(2) 所有结点存储一个关键字；
//(3) p->left->val < p->val < p->right->val
//16.1.2 二叉搜索树
//所有非叶子节点的左右子树的节点数平衡，则B树搜索性能逼近二分查找。
//与连续内存空间的二分查找优点: 改变二叉搜索树结构（插入与删除结点）不需要移动大段内存数据，通常是常数开销。
//不足: 二叉搜索树在经过多次插入与删除后，有可能导致不同的结构
//16.1.3 “平衡”问题
//使用二叉搜索树, 尽可能让 B树保持平衡
//平衡二叉树: 二叉搜索树 + 平衡算法
//(1)平衡算法: 在二叉搜索树中插入和删除结点的策略。
//(2)作用: 保持 B树结点分布均匀
//16.1.4 平衡二叉树的特点:
//(1) 非叶子节点最多拥有两个子节点
//(2) 非叶子节值大于左边子节点、小于右边子节点
//(3) 树的左右两边的层级数相差不会大于 1
//(4) 没有值相等重复的节点

//16.2 B树（B-树）
//16.2.1 概念
//一种多路搜索树, 属于多叉树又名平衡多路查找树
//16.2.2 规则
//16.2.3 搜索
//从根结点开始，对结点内的关键字(有序)序列进行二分查找，命中则结束，否则进入查询关键字所属范围的子结点；重复，直到所对应的子节点指针为空，或已是叶子结点
//16.2.4 插入节点流程
//B-树特性:
//(1) 关键字集合分布在整颗树中
//(2) 任何一个关键字出现且只出现在一个结点中
//(3) 搜索有可能在非叶子结点结束
//(4) 其搜索性能等价于在关键字全集内的二分查找
//(5) 自动层次控制
//16.2.5 最低搜索性能:Omin=O(logN)
//限制了除根结点外的非叶子结点，有>= M/2 个儿子，确保了结点的至少利用率
//(1) M 为设定的非叶子结点最多子树个数，N 为关键字总数；
//(2) 所以 B- 树的性能总是 <---> 二分查找（M值无关），也就没有 B树平衡的问题；
//(3) 由于 M/2 的限制，插入结点时，若结点已满，需将结点分裂为两个各占 M/2 的结点；删除结点时，需将两个不足 M/2 的兄弟结点合并。

//16.3 B+树
//16.3.1 概念
//B-树的变体, 一种多路搜索树, 更充分的利用了节点的空间，让查询速度更加稳定，其速度完全接近于二分法查找。
//16.3.2 规则
//(1) B+树的非叶子节点不保存关键字记录的指针，只进行数据索引，大大增加了B+树各非叶子节点所能保存的关键字。
//(2) B+树叶子节点保存了父节点的所有关键字记录的指针，所有数据地址必须到叶子节点才能获取。所以， 每次数据查询的次数都一样。
//(3) B+树叶子节点的关键字从小到大有序排列，左边结尾数据都会保存右边节点开始数据的指针。
//(4) 非叶子节点的子节点数=关键字数。
//16.3.3 搜索
//与B树基本相同，区别是B+树只有达到叶子结点才命中。
//其搜索性能也等价于: 在关键字全集内的二分查找
//16.3.4 特性
//(1)层级更少: 每个非叶子节点存储的关键字数更多
//(2)查询速度更稳定: 所有关键字数据地址都在叶子节点上，所以每次查找的次数都相同
//(3)天然具备排序功能: 所有叶子节点数据构成一个有序链表，在查询大小区间的数据时更方便，数据紧密性很高，缓存命中率比B树高
//(4)全节点遍历更快: 只需遍历所有叶子节点即可，不需像 B树遍历每一层，这有利于数据库做全表扫描
//16.3.5 B树相对于 B+ 树的优点
//如果经常访问的数据离根节点很近, 这种数据检索要比 B+树快

//16.4 小结
// 二叉搜索树：二叉树，各结点只存储一个关键字，等于则命中，小于走左结点，大于走右结点。
// B(B-)树：多路搜索树，各结点存储 M/2 到 M 个关键字，非叶子结点存储指向关键字范围的子结点；所有关键字在整颗树中出现，且只出现一次，非叶子结点可以命中。
// B+树：在 B-树基础上，为叶子结点增加链表指针，所有关键字都在叶子结点中出现，非叶子结点作为叶子结点的索引；B+ 树总是到叶子结点才命中。



//17 B+、B- 树的应用场景
//17.1 每一种数据结构都有它的使命
//链表: 构成缓存容器实现数据的暂时存放，
//B+、B-树: 作为数据库搜索引擎的索引提高读取效率

//17.1.1  为什么在数据库中使用索引？
//二叉树的最坏搜索时间复杂度: O(logn)
//数据库的索引就是利用了这一原理，大大的加速了数据查询的速度

//17.2 B+ 树在数据库中的应用
//在工业上主要用于 MySQL 的 InnoDB 引擎索引。
//(1) B+树作为数据库索引，此数据结构具有键，且具有与该键关联的值。该值是对实际数据记录的引用。键和值一起称为有效负载。
//(2) 每个节点称为页(磁盘块), MySQL 中数据读取的基本单位都是页
//(3) 所有记录都存储在 B+树的叶节点中，索引用作创建 B+树的键。 每个叶节点都引用树中的下一条记录。
//(4) B+树非叶子节点上不存数据，仅存键值. 因为数据库中页的大小固定, 这样做可存更多键值，树的阶数（节点的子节点树）更大，树会更矮更胖
//查找数据进行磁盘的 IO 次数减少，查询的效率提高

//17.3 B-树在数据库中的应用
//17.3.1 主要在 MongoDB 中使用较为广。
//MongoDB 是聚合型数据库，而 B- 树恰好 key 和 data 域聚合在一起。
//MongoDB 是一种 NoSQL，也存储在磁盘上，被设计用在 数据模型简单，性能要求高的场合。
//17.3.2 B+树查找复杂度固定为O(logn)
//B-树查找复杂度与key在树中的位置有关，最好为O(1)，尽可能少的磁盘IO是提高性能的有效手段。
//17.3.3 B-树特点
//(1) 所有键值分布在整颗树中；
//(2) 任何一个关键字出现且只出现在一个结点中；
//(3) 搜索有可能在非叶子结点结束；
//(4) 在关键字全集内做一次查找，性能逼近二分查找。

//17.4 为什么数据库不用红黑树结构作为索引？
//为了磁盘或其它存储设备而设计的一种平衡多路查找树
//相同数据下，B/B+树的高度 << 红黑树高度，这样在磁盘查找数据时，磁臂定位次数越少，查询效率越高。
//B/B+树操作时间 == 存取磁盘的时间 + CPU计算时间
//所以, B树操作效率取决于磁盘访问次数，关键字总数相同下 B树的高度越小，磁盘I/O所花时间越少。

//17.5 为什么数据库不用 Hash 表作为索引？
//从业务和性能两点考虑:
//(1)查询一条数据, Hash存储更快.
//B+树的优势: 业务中更多的区间/批量查询. 因为B+树叶节点有链表结构，支持区间查询，比 Hash查询效率更高
//(2)内存: 如果一张表有几千万的数据，不能一次性将所有 Hash 值导入内存，但B树可以分批加载。

//17.6  B+ 树中，将叶子节点串起来的链表，是单链表还是双向链表？为什么？
//如何能保证查询出来的数据有序?
//选择双向链表, 空间换时间, 大量减少链表的遍历时间。

//17.7 小结
// B+ 树
// B- 树
// 为什么数据库不用红黑树结构作为索引？
// 为什么数据库不用 Hash 表作为索引？

//17.8 课后思考
//是否可以无限增加 B 树的路数以降低树的高度来获得更高的效率呢？
//不是，有上界



//18 专栏总结和我们过往经验分享
//应用到实际的学习和工作中去，解决实际的开发问题。
//需要很好的对数据结构的理解以及丰富的实际工作经验。

//18.1 熟知经典的数据结构和算法
//熟知: 数据结构和算法的功能、特点、时间空间复杂度
//算法题和实际工程上的问题相差很远。
//做题，可以对数据结构相关的理论知识有一个更深的理解。

//18.2 通过实际问题中的数据特征来选择数据结构和算法
//分析一个实际的工程问题:
//将实际问题抽象简化为数据的特征问题，并以此为基础来确定如何访问数据 以及 选择什么样的数据结构和算法
//

//18.3 善用封装好的类，避免造轮子
//常用的数据结构和算法，编程语言几乎都提供了类和函数实现。经过很多人不断修改和验证, 性能有保证。
//深入理解背后的数据结构和算法的原理， 有助于更好地应用这些编程语言提供的类和函数。

//18.4 不要过于追求性能
//(1) 要放在实际场景和问题中来看待性能。 在实际的场景中，时间和空间复杂度 ！= 性能
//大规模的数据处理，还要考虑数据的读取性能以及CPU执行效率；
//小规模数据处理，算法的执行效率不一定跟时间复杂度成正比，有时成反比。
//(2) 不要去盲目使用数据结构和算法来优化程序。
//复杂的算法和数据结构来优化执行时间, 可能代码量大幅上升，抬高代码的维护成本。

//18.5 总结
//(1) 熟知经典的数据结构和算法
//(2) 通过实际问题中的数据特征来选择数据结构和算法
//(3) 善用封装好的类，避免造轮子
//(4) 不要过于追求性能



















