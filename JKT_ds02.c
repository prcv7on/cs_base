

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>


//23 二叉树基础（上）：什么样的二叉树适合用数组来存储？

typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
}TN;

void printArr(int* a, int n) {
    printf("arr= ");
    for (int i=0;i<n;++i) {
        printf("%2d ",a[i]);
    }
    printf("\n");
}

//思考题：二叉树有哪几种存储方式？什么样的二叉树适合用数组来存储？
//23.1 树（Tree）
//23.1.1 几个概念
//(1)Height: 节点高度:节点到叶子节点的最长路径(边数); 树高:根节点高度
//(2)Depth: 节点深度:根节点到此节点经历的边数
//(3)Level: Depth(node)+1

//23.2 二叉树（Binary Tree）
//23.2.1 满二叉树: 叶子节点全在最底层，除叶子节点外，各节点都有左右两个子节点
//23.2.2 完全二叉树: 叶子节点都在最底两层，最后一层的叶子节点都靠左，并且除最后一层，其他层的节点个数都达到最大
//23.2.3 如何表示（或存储）一棵二叉树？
//(1)基于指针或引用的二叉链式存储法: 各节点有3个字段，分别是数据，左右节点指针
//(2)基于数组的顺序存储法: 根节点下标i=1, 左右节点下标为2*i, 2*i+1, 父节点i/2
//23.2.4 完全二叉树的存储
//数组是最节省内存的方式，因为其无需存储左右节点指针，仅浪费下标为0的位置。
//也是为什么完全二叉树要求叶子节点都靠左的原因。
//堆: 一种完全二叉树，最常用的存储方式就是数组。

//23.3 二叉树的遍历
//23.3.1 遍历方式
//(1)前序: 根左右
//(2)中序: 左根右
//(3)后序: 左右根
//23.3.2 遍历是一个递归的过程
//各节点最多访问2次: 时间复杂度O(n)

/*
void PreOrder(TN* p) {
    if (p==NULL) return;
    printf("%d ",p->val);
    PreOrder(p->left);
    PreOrder(p->right);
}

void MidOrder(TN* p) {
    if (p==NULL) return;
    MidOrder(p->left);
    printf("%d ",p->val);
    MidOrder(p->right);
}

void PostOrder(TN* p) {
    if (p==NULL) return;
    PostOrder(p->left);
    PostOrder(p->right);
    printf("%d ",p->val);
}
*/

//23.4 解答开篇 & 内容小结
//平时最常用的树就是二叉树
//有两种特殊的树: 满二叉树和完全二叉树。满二叉树又是完全二叉树的一种特殊情况。
//二叉树可用链式/数组顺序存储。
//数组顺序存储比较适合完全二叉树，其他类型的二叉树用数组存储比较浪费空间。

//23.5 课后思考
//(1) 给定一组数据，比如 1，3，5，6，9，10。你来算算，可以构建出多少种不同的二叉树？
//(2) 按层遍历，如何实现?

/*
//队列
#define MAXSIZE 16
void bfs(TN* p, int** rt, int* col, int i, int* maxh) {
    if (p) {
        rt[i][col[i]]=p->val;
        ++col[i];
        if (i+1 > *maxh) *maxh=i+1;
        bfs(p->left, rt,col,i+1,maxh);
        bfs(p->right,rt,col,i+1,maxh);
    }
}

int** LevelOrder(TN* p, int* sz, int** csz) {
    if (p==NULL) return NULL;

    int bn=MAXSIZE*sizeof(int);//byte num
    int** rt=(int**)malloc(MAXSIZE*sizeof(int*));
    *csz=(int*)malloc(bn);//必须初始化为0
    memset(*csz,0,bn);
    for (int i=0;i<MAXSIZE;++i) {
        rt[i]=(int*)malloc(bn);
    }
    *sz=0;
    bfs(p,rt,*csz,0,sz);
    return rt;
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
    //int* arr=PreOrder(&a,&sz); //346758
    //int* arr=MidOrder(&a,&sz); //647385
    //int* arr=PostOrder(&a,&sz); //674853
    //printArr(arr,sz);

    int row=0;
    int* col;
    int** rt=LevelOrder(&a,&row,&col);
    printf("row=%d,*col=%d\n",row,*col);
    for (int i=0;i<row;++i) {
        for (int j=0;j<col[i];++j) {
            printf("%2d ",rt[i][j]);
        }
        printf("\n");
    }

    return 0;
}
*/


//24 二叉树基础（下）：有了如此高效的散列表，为什么还需要二叉树？
//二叉查找树最大的特点: 支持动态数据集合的快速插入、删除、查找操作。
//散列表也支持这些操作，且更加高效。
//是否有地方是散列表不行，只能用二叉树？

//24.1 二叉查找树（Binary Search Tree）
//特殊结构: 对于树中任意节点p, p->left->val < p->val < p->right->val
//24.1.1 查找
//判断根节点与key大小
//if (p->val < key) p=p->left; 递归
//if (p->val > key) p=p->right; 递归

//24.1.2 插入
//从根节点开始，依次比较要插入的数据和节点的大小关系。

//24.1.3 删除
//(1)p没有子节点: p的父节点中指向p的指针设置为NULL
//(2)p只有1个子节点: 更新父节点中，指向p的指针，让它指向p的子节点
//(3)p有2个子节点: 找到p的右子树中最小节点，把它替换到p节点上。然后删除这个最小节点，因为最小节点肯定没有左子节点
//(4)查找最大/最小/前驱/后继节点
//中序遍历二叉查找树，可输出有序数据，时间复杂度O(n)，非常高效  -->  二叉排序树

/*
TN* createTN(int val) {
    TN* p=(TN*)malloc(sizeof(TN));
    p->val=val;
    p->left=p->right=NULL;
    return p;
}

TN* findKey(TN* root, int key) {
    TN* p=root;
    while (p) {
        if (key == p->val) return p;
        else if (key < p->val) p=p->left;
        else p=p->right;
    }
    return NULL;
}

void insertKey(TN* root, int key) {
    printf("beg insertkey.\n");
    TN* newNode=createTN(key);
    if (root==NULL) {
        root=newNode;
        return;
    }

    printf(" root != NULL---\n");
    TN* p=root;
    while (p) {
        if (key > p->val) {
            if (p->right == NULL) {
                p->right=newNode;
                return;
            }
            p=p->right;
        }
        else {
            if (p->left == NULL) {
                p->left=newNode;
                return;
            }
            p=p->left;
        }
    }
}

void deleteKey(TN* root, int key) {
    TN* p=root;
    TN* pp=NULL;
    while (p && p->val != key) {
        pp=p;
        if (key > p->val) p=p->right;
        else p=p->left;
    }
    if (p==NULL) return;

    //p节点有两个子节点
    if (p->left != NULL && p->right != NULL) {
        TN* minP=p->right;
        TN* minPP=p;
        while (minP->left != NULL) {
            minPP=minP;
            minP=minP->left;
        }
        p->val=minP->val;
        p=minP; //下面就删除minP
        pp=minPP;
    }

    //p是叶子节点或仅有一个子节点
    TN* child;
    if (p->left != NULL) child=p->left;
    else if (p->right != NULL) child=p->right;
    else child=NULL;

    if (pp==NULL) root=child;
    else if (pp->left == p) pp->left=child;
    else pp->right=child;
}

TN* findMax(TN* root) {
    if (root == NULL) return NULL;
    TN* p=root;
    while (p->right != NULL) p=p->right;
    return p;
}

TN* findMin(TN* root) {
    if (root == NULL) return NULL;
    TN* p=root;
    while (p->left != NULL) p=p->left;
    return p;
}
*/

//24.2 支持重复数据的二叉查找树
//在BST中存储的，是一个包含很多字段的对象, 根据某个字段的键值 Key 构建二叉查找树。 对象中的其他字段叫作卫星数据。
//24.2.1 键值相同
//(1)通过链表和支持动态扩容的数组等数据结构，把值相同的数据存在同一个节点上
//(2)各节点只存一个数据，若要插入的值key与某节点p的值相同， 则把key放到p的右子树。即，把新插入的数据当作 > 这个节点的值来处理。
//查找时，遇到相同值的节点，不停止，继续在右子树中查找。直到叶子节点，才停止。 可把键值等于key的所有节点都找出来
//对于删除操作，先找到每个要删除的节点，再按前面讲的删除方法，依次删除。

//24.3 二叉查找树的时间复杂度分析
//第k层节点个数: 2^(k-1)
//完全二叉树的高度 <= log2(n)
//平衡二叉查找树高度 ~= log(n)  -->  插入/删除/查找/的时间复杂度/比较稳定O(logn)

//24.4 解答开篇
//(1)散列表中数据无序，为输出有序数据，需先排序。而BST的中序遍历就可在O(n)时间复杂度内，得到有序数据。
//(2)散列表扩容耗时很多，当遇到散列冲突时，性能不稳定。工程中，最常用的平衡二叉查找树的性能非常稳定O(logn)
//(3)尽管散列表的查找等操作的时间复杂度O(1)， 但因为哈希冲突的存在，这个常量不一定比 logn 小
//实际查找速度可能不一定比 O(logn) 快
//(4)散列表的构造复杂, 要考虑散列函数的设计、冲突解决办法、扩容、缩容等。
//平衡二叉查找树只需考虑平衡性这一个问题，而且这个问题的解决方案比较成熟、固定。
//(5)为避免过多散列冲突，散列表装载因子不能太大，特别是基于开放寻址法解决冲突的散列表，不然会浪费一定的存储空间。
//(6)两者的存在并不冲突。应该具体分析。

//24.5 内容小结
//二叉查找树: 支持快速查找、插入、删除操作。
//没有重复数据: 每个节点的值都大于左子树节点值，小于右子树节点值
//二叉查找树: 查找、插入、删除等操作的时间复杂度, 跟树的高度成正比
//为了避免时间复杂度的退化, 平衡二叉查找树，时间复杂度稳定O(logn)

//24.6 课后思考
//编程，求出一棵给定二叉树的确切高度

//递归求深度
// int treeDepth(TN* root) {
//     if (root==NULL) return 0;
//     TN* p=root;
//     int ld=treeDepth(p->left);
//     int rd=treeDepth(p->right);
//     int depth= ld > rd ? ld+1 : rd+1;
//     return depth;
// }

/*
int* midorder(TN* root, int* sz) {
    printf("midorder---------\n");
	*sz = 0;
	if (!root) return 0;
	if (!root->left && !root->right) {
		*sz = 1;
		return &(root->val);
	}
	int* ret = (int*)malloc(64 * sizeof(int));
	TN** stk = (TN**)malloc(64 * sizeof(TN*));
    memset(ret,0,64 * sizeof(int));
    memset(stk,0,64 * sizeof(int));
	int top = -1;
	while (root || top != -1) {
		while (root) {
			stk[++top] = root;
			root = root->left;
		}
		root = stk[top--];
		ret[(*sz)++] = root->val;
		root = root->right;
	}
	free(stk);
	return ret;
}

int main(void) {
    TN a, b, c, d, e, f;
	a.val = 40; a.left = &b; a.right = &c;
	b.val = 20; b.left = &d; b.right = &e;
	c.val = 60; c.left = &f; c.right = NULL;
	d.val = 10; d.left = NULL; d.right = NULL;
	e.val = 30; e.left = NULL; e.right = NULL;
	f.val = 50; f.left = NULL; f.right = NULL;

    // TN* p=findKey(&a,3);
    TN* pmin=findMin(&a);
    TN* pmax=findMax(&a);
    //printf("p->val= %d\n",p->val);//3
    printf("pmin->val= %d\n",pmin->val);//
    printf("pmax->val= %d\n",pmax->val);//
    // insertKey(&a,55);
    // deleteKey(&a,30);
    // int sz=0;
    // int* arr=midorder(&a,&sz);
    // printArr(arr,sz);

    // int td=treeDepth(&a);
    // printf("d=%d\n",td);
    return 0;
}
*/



//25 红黑树（上）：为什么工程中都用红黑树这种二叉树？
//26 红黑树（下）：掌握这些技巧，你也可以实现一个红黑树



//27 递归树：如何借助树来求解递归算法的时间复杂度？
//27.1 递归树与时间复杂度分析
//归并排序每次将数据一分为二.
//分解操作，需时间常量1. 归并操作较耗时。
//每一层归并操作消耗的时间总和是一样的，跟要排序的数据规模有关  -->  时间复杂度O(n*h)
//归并排序递归树是一棵满二叉树, 树高为h=O(logn)  -->  时间复杂度O(n*logn)

//27.2 实战1：分析快速排序的时间复杂度
//(1)快速排序过程中，每次分区都要遍历待分区间的所有数据，所以，各层分区所遍历的数据个数之和==n, 只要求得递归树的高度h, 则时间复杂度为O(n*h)
//(2)假设平均情况，每次分区之后，两个分区的大小比例为1:k, 则从根节点到叶子节点的路径范围是 [log10(n), log10/9(n)]  
//-->  遍历的数据总和为 [n*log10(n), n*log10/9(n)]  -->  时间复杂度O(n*logn)

//27.3 实战2：分析斐波那契数列的时间复杂度
//(1)每次分解，数据规模 −1 或 −2， 从根节点到叶子节点，各路径长短不一， 路径范围是 [n/2, n] 
//(2)每次分解后的合并，需1次加法， 若路径长度为n, 则总的时间==1+2+2^2+...+2^(n-1)==2^n-1; 若路径长度为n/2,则总时间==2^(n/2)-1
//时间复杂度范围: O(2^n)~O(2^(n/2))

//27.4 实战3：分析全排列的时间复杂度
//时间复杂度范围: [O(n!), O(n*n!)]

//27.5 内容小结
//(1)时间复杂度分析适合用递推公式: 归并，快排最好
//(2)时间复杂度分析适合用递归树: 快排平均
//(3)都不适合用: 二叉树的递归前中后序遍历
//灵活应用学到的复杂度分析方法，来分析现有代码，并不简单. 平时要多实战、多分析

//27.6 课后思考
//1个细胞的生命周期3 小时，1小时分裂一次。求n小时后，容器内有多少细胞？
//用递归时间复杂度的分析方法，分析一下这个递归问题的时间复杂度
//f(n)=2*f(n-1)-f(n-4)  -->  时间复杂度O(2^n)



//28 堆和堆排序：为什么说堆排序没有快速排序快？
//原地，时间复杂度O(n*logn)比快排稳定
//在实际开发中，快排的性能比堆排序好，为什么？

//28.1 如何理解“堆”？
//堆是一种特殊的树，满足两点就是堆:
//(1)堆是一个完全二叉树: 除最后一层，其他层的节点个数都是满的，最后一层的节点都靠左
//(2)堆中各节点值都必须 >= 或 <= 其子树中各节点值 <--> 堆中各节点值都 >= 或 <= 其左右子节点值

//28.2 如何实现一个堆？
//完全二叉树适合用数组存储，下标就可找到左右子节点和父节点
//对于下标为i的节点，其左右子节点和父节点下标为: 2*1, 2*i+1, i/2

//28.3 往堆中插入一个元素
//插入新元素后，需要使堆继续满足2个特性。需要调整(堆化heapify)使其重新满足。
//heapify: 从下往上(这节课)和从上往下  -->  顺着节点所在路径，向上或向下，对比，然后交换。
//28.4 删除堆顶元素
//堆顶: 堆中的最大/最小值
//从上往下的堆化: 把最后一个节点放到堆顶，然后重复同样的父子节点对比,互换方法。直到父子节点间满足大小关系为止
//不会出现空洞: 移除的是数组中最后一个元素,堆化过程都是交换操作
//
//有n个节点的完全二叉树，树高h<=log2(n). 
//堆化的过程: 顺着节点所在路径比较交换, 堆化的时间复杂度与h成正比，即O(logn)
//插入和删除堆顶的主要逻辑: 堆化。 它们的时间复杂度为O(logn)

/*
typedef struct _Heap {
    int* arr;
    int sz;
    int maxsz;
}Heap;

void mswap(int* a, int i, int j) {
    if (a[i] != a[j]) {
        a[i] ^= a[j];
        a[j] ^= a[i];
        a[i] ^= a[j];
    }
}

Heap* InitHeap(int maxsz) {
    Heap* p=malloc(sizeof(Heap));
    p->arr=(int*)malloc(sizeof(int) * (maxsz+1));
    memset(p->arr, 0, sizeof(int) * (maxsz+1));
    p->maxsz=maxsz;
    p->sz=0;
    return p;
}

void InsertKey(Heap* p, int key) {
    if (p->sz >= p->maxsz) return;
    p->arr[++p->sz]=key;
    int i=p->sz;
    while (i/2 > 0 && p->arr[i] > p->arr[i/2]) {
        mswap(p->arr, i, i/2);
        i=i/2;
    }
}

void heapify(int* a, int n, int i) {
    while (1) {
        int maxPos=i;
        if (2*i <= n && a[2*i] > a[i]) maxPos=2*i;
        if (2*i+1 <= n && a[2*i+1] > a[maxPos]) maxPos=2*i+1;
        if (maxPos == i) break;
        mswap(a,i,maxPos);
        i=maxPos;
    }
}

void RemoveMax(Heap* p) {
    if (p->sz == 0) return;
    p->arr[1]=p->arr[p->sz--];
    heapify(p->arr, p->sz, 1);
}
*/

//28.5 如何基于堆实现排序？
//时间复杂度稳定: O(n*logn)

//28.5.1 建堆
//(1)在堆中插入元素: 起初堆中只含下标为 1 的数据。然后，将下标2 到 n 的数据依次插到堆中
//从前往后处理数据，并且各数据插入堆中时，都是从下往上堆化
//(2)从后往前处理数组，并且各数据从上往下堆化  -->  本节详细代码
//完全二叉树: 下标从 n/2​+1 到 n 的节点是叶子节点。所以，只对n/2到1的节点堆化
//各节点堆化的时间复杂度O(logn)
//各节点堆化过程中，需要比较和交换的节点个数，跟这个节点的高度 k 成正比
//建堆的总时间T(n)=2^(h+1)-h-2 ,h=log2(n)  --> 时间复杂度O(n)
//
//28.5.2 排序
//建堆结束之后，数组中的数据已按大顶堆的特性来组织。数组首元素是堆顶，即最大元素
//把堆顶与最后元素交换，通过堆化将剩余n-1个元素重新构建成堆， 再次堆化后，重复前面的过程。直到只剩下标为1的元素。
//28.5.3
//(1) 整个堆排序过程: 只需极个别临时存储空间，所以是原地排序算法
//(2) 堆排序包括建堆和排序两个操作: 时间复杂度分别是O(n), O(n*logn) --> 堆排序整体的时间复杂度O(n*logn)
//(3) 不是稳定排序: 将最后一个节点跟堆顶互换，可能改变值相同数据的原始相对顺序。

// void BuildHeap(Heap* p) {
//     int n=p->sz;
//     for (int i=n/2; i>=1; --i) {
//         heapify(p->arr, n, i);
//     }
// }
// //
// void SortHeap(Heap* p) {
//     BuildHeap(p);
//     int h=p->sz;
//     while (h>1) {
//         mswap(p->arr,1,h);
//         --h;
//         heapify(p->arr,h,1);
//     }
// }

//28.6 解答开篇
//在实际开发中，为什么快速排序比堆排序性能好？
//(1)堆排序数据访问的方式没有快速排序友好
//快排中的数据是顺序访问的。 堆排序中的数据是跳着访问的，不能充分利用CPU的缓存。
//(2)同样的数据，在排序过程中，堆排序的数据交换次数更多
//对于基于排序的比较算法，这个排序过程由比较和交换/移动两个操作组成。
//快排交换的次数 <= 逆序度
//堆排序的建堆步骤会打乱数据相对顺序，降低原数据的有序度

//28.7 内容小结
//(1)最大的特性: 各节点的值 >= 或 <= 其子树节点值
//(2)插入和删除都需要堆化。时间复杂度都是O(logn)
//插入: 把新数据放到数组最后，然后从下往上堆化
//删除: 把数组最后一个元素放到堆顶，然后从上往下堆化
//(3)堆排序包含两个过程，建堆和排序。
//将下标为n/2到1的节点，依次从上到下堆化， 将数组中数据组织成堆。
//迭代地将堆顶放到末尾，并将堆大小减一，然后再堆化，重复这个过程，直到堆中只剩一个元素，整个数组就都有序

//28.8 课后思考
//(1)完全二叉树: 下标从 n/2​+1 到 n 的节点是叶子节点 推导?
//(2)堆的其他应用
// 1.topK
// 2.流里面的中值
// 3.流里面的中位数

/*
int main(void) {
    Heap* p = InitHeap(15);
    int arr[13]={33,17,21,16,13,15,9,5,6,7,8,1,2};
    for (int i=0; i<13; ++i) {
        p->arr[i+1]=arr[i];
    }
    p->sz=13;
    //printArr(p->arr,16);
    // InsertKey(p,22); printArr(p->arr,p->sz+1);
    // RemoveMax(p); printArr(p->arr,p->sz+1);
    SortHeap(p); printArr(p->arr,p->sz+1);//0  1  2  5  6  7  8  9 13 15 16 17 21 33

    return 0;
}
*/



//29 堆的应用：如何快速获取到Top 10最热门的搜索关键词？
//29.1 堆的应用一：优先级队列
//出队顺序: 按优先级，优先级最高，最先出队
//用堆来实现是最直接、最高效
//很多数据结构和算法都依赖它: 赫夫曼编码、图的最短路径、最小生成树算法等

//29.1.1 合并有序小文件
//有100个小文件，各文件的大小100MB，各文件中存储有序的字符串。将这些小文件合并成一个有序的大文件。
//整体思路: 类似归并排序中的合并函数
//(1) 将从小文件中取出的字符串放到小顶堆，那堆顶元素就是优先级队列队首. 
//(2) 将此字符串放到大文件中，并将其从堆中删除。
//(3) 再从小文件中取下一个字符串，放入到堆中。循环这个过程
//(4)删除/插入数据的时间复杂度O(logn)
//
//29.1.2 高性能定时器
//有个定时器，定时器中维护了很多定时任务，各任务都设定了一个要触发执行的时间点
//(1)每过很小单位时间（比如 1 秒），就扫描一遍任务，看是否有任务到达设定的执行时间。如果到达了，就拿出来执行。
//这种做法低效，因为:
//1) 下次任务还有很长时间，前面的很多扫描是无用的。
//2) 若任务列表很大，则每次扫描这个列表会比较耗时。
//(2) 按照任务设定的执行时间，将它们存储在优先级队列中，队列首部（小顶堆的堆顶）存储最先执行的任务
//时间间隔T == 队首任务时间 - 当前时间

//29.2 堆的应用二：利用堆求 Top K
//29.2.1 静态数据: 数据集合事先确定，不会再变。
//在包含 n 个数据的数组中，查找前K大数据:
//(1)维护大小为 K 的小顶堆，顺序遍历数组，从数组中取出数据与堆顶元素比较
//(2)若当前数据大于堆顶，则删除堆顶，将当前数据插到堆中。否则，继续遍历。遍历完后，堆中数据就是前 K 大数据
//时间复杂度: n*O(log(K))==O(n*logK)
//
//29.2.2 动态数据: 数据集合事先不确定，有数据动态地加入集合中
//一直都维护大小K的小顶堆。
//当有数据添加到集合中时，拿它与堆顶对比。
//无论何时需要查询当前的前 K 大数据，都可立刻返回

//29.3 堆的应用三：利用堆求中位数
//求动态数据集合中的中位数, 大小为n，则中位数是n/2+1(奇数)，n/2(偶数)
//29.3.1 静态数据: 先排序，直接返回中位数
//29.3.2 动态数据: 维护两个堆，一个大顶堆，一个小顶堆。
//(1) 大顶堆存储前半部分数据，小顶堆存储后半部分数据，且小顶堆的数据 > 大顶堆的数据
//n是偶数: 从小到大排序，前n/2个数据在大顶堆中，后n/2个数据在小顶堆中  -->  中位数==大顶堆的堆顶
//n是奇数: 前n/2+1个数据在大顶堆中，后n/2个数据在小顶堆中
//(2)新增数据key: 若key <= 大顶堆的堆顶，则key插入到大顶堆; 否则，加到小顶堆
//此时，两个堆中的数据个数不符合前面约定  -->  从一个堆中不停地将堆顶元素移动到另一个堆
//插入数据涉及堆化，时间复杂度O(logn); 求中位数，时间复杂度O(1)
//29.3.3
//有n个数据，将数据从小到大排列，99百分位数大约是第 n*99% 个数据
//维护两个堆，一个大顶堆，一个小顶堆。大顶堆保存 n*99% 个数据，小顶堆保存 n*1% 个数据  -->  大顶堆堆顶即99% 响应时间
//后续操作与上面相同

//29.4 解答开篇
//(1)首先要统计各搜索关键词出现的频率。
//通过散列表、平衡二叉查找树或其他一些支持快速查找、插入的数据结构，来记录关键词及其出现的次数。
//再根据前面用堆求 Top K 的方法，建立大小为 10 的小顶堆，遍历散列表，
//散列表因为要避免频繁冲突，不会选择太大的装载因子. 无法一次性将所有搜索关键词加到内存中
//(2) 将关键词先通过哈希算法分片到 10 个文件中
//相同数据经过哈希算法得到的哈希值是一样
//对个文件，利用散列表和堆，分别求出 Top 10。 再把10个top10放在一起求top10

//29.5 内容小结
//思路都一样: 利用两个堆，大/小顶堆，随着数据的动态添加，动态调整两个堆中的数据，最后大顶堆的堆顶是要求的数据

//29.6 课后思考
//有一个访问量非常大的新闻网站，希望将点击量排名Top10的新闻摘要，滚动显示在网站首页 banner 上，并且每隔 1 小时更新一次。



//31 深度和广度优先搜索：如何找出社交网络中的三度好友关系？
//35 Trie树：如何实现搜索引擎的搜索关键词提示功能？

//37 贪心算法：如何用贪心算法实现Huffman压缩编码？
//算法思想，原理解释起来很简单，但要真正掌握且灵活应用，并不容易.
//结合具体问题，让你自己感受算法是怎么工作的，是如何解决问题的，带你在问题中体会这些算法的本质。
//今天讲霍夫曼编码，看它是如何用贪心算法来实现对数据压缩编码，有效节省数据存储空间的。

//37.1 如何理解“贪心算法”？
//37.1.1 贪心算法解决问题的步骤:
//(1)看到这类问题，首先联想到贪心算法: 针对一组数据，定义了限制值和期望值，希望从中选出几个数据，在满足限制值的情况下，期望值最大。
//(2)看下此问题是否可用贪心算法解决: 每次选择当前情况下，在对限制值同等贡献量的情况下，对期望值贡献最大的数据。
//(3)举几个例子看下产生的结果是否最优: 实际上，用贪心算法解决问题的思路，并不总能给出最优解。
//贪心算法不工作的主要原因: 前面的选择，会影响后面的选择。

//37.2 贪心算法实战分析
//掌握贪心算法的关键是多练习。只要多练习几道题，自然就有感觉了。
//37.2.1 分糖果
//有m个糖果和n个孩子(m<n). 各糖果大小不等(s1,s2,......,sm). 各孩子对糖果的需求不一样(g1,g2,......gn)
//如何分配糖果，能尽可能满足最多数量的孩子？
//问题抽象成: 从n个孩子中，抽取一部分孩子分配糖果，让满足的孩子个数（期望值）最大。问题的限制值是糖果个数m
//解决方案: 每次从剩下孩子中，找出对糖果大小需求最小的，然后发给他剩下糖果中能满足他的最小的糖果
//
//37.2.2 钱币找零
//有1、2、5、10、20、50、100这些面额的纸币，张数分别是 c1、c2、c5、c10、c20、c50、c100。现在要用这些钱支付 K 元，最少要用多少张纸币？
//先用面值最大的，如果不够，就继续用更小一点面值，以此类推
//
//37.2.3 区间覆盖
//有n个区间，区间的起始/结束端点分别是: [l1, r1]，[l2, r2]，[l3, r3]，……，[ln, rn]。从这 n 个区间中选出一部分区间，这部分区间两两不相交（端点相交的情况不算相交），最多能选出多少个区间
//假设这n个区间中最左端点lmin，最右端点rmax
//问题相当于: 选择几个不相交的区间，从左到右将[lmin, rmax]覆盖上。按照起始端点从小到大, 对这n个区间排序
//解决方案: 每次选择，左端点跟前面已覆盖的区间不重合的，右端点又尽量小的，这样可让剩下的未覆盖区间尽可能大，就可放置更多区间

//37.3 解答开篇
//有包含1000个字符的文件，各字符占1个byte（1byte=8bits），存储这1000个字符共需要8000bits，有没有更加节省空间的存储方式
//(1) 只包含6种不同字符，假设它们分别是a、b、c、d、e、f。而3个二进制位就可表示8个不同的字符
//各字符用3个二进制位表示，则只需3000bit
//(2) 霍夫曼编码,压缩率通常在 20%～90% 之间
//有多少个不同字符及其频率，根据频率的不同，选择不同长度的编码  -->  高频字符短编码，低频字符长编码
//解压缩比较复杂: 各字符的编码之间，不会出现某个编码是另一个编码前缀的情况
//解压缩时，每次读取尽可能长的可解压的二进制串，所以在解压缩时也不会歧义
//(3) 如何根据字符出现频率的不同，给不同的字符进行不同长度的编码？
//每个字符看作一个节点，并且附带着把频率放到优先级队列中。
//给每条边加上画一个权值，指向左/右子节点的边统统标记为0、1，那从根节点到叶节点的路径  叶节点对应字符的霍夫曼编码

//37.4 内容小结
//(1)贪心算法适用的场景有限。更多的是指导设计基础算法。比如最小生成树算法、单源最短路径算法
//(2)不要刻意去记忆贪心算法的原理，多练习才是最有效的学习方法
//(3)最难: 如何将要解决的问题抽象成贪心算法模型

//37.5 课后思考
//(1) 在一个非负整数 a 中，希望从中移除 k 个数字，让剩下的数字值最小，如何选择移除哪 k 个数字
//(2) 假设有 n 个人等待被服务，但服务窗口只有一个，每个人需要被服务的时间长度不同，如何安排被服务的先后顺序，才能让这 n 个人总的等待时间最短？

// char* removeKdigits(char* a, int k){
//     int n=strlen(a),top=-1,i=0;
//     char* stk=(char*)malloc(sizeof(char) * (n+1));
//     for (i=0; i<n; ++i) {
//         while (top != -1 && stk[top] > a[i] && k>0) {
//             --top;
//             --k;
//         }
//         if (a[i] != '0' || top != -1) stk[++top]=a[i];
//     }
//     while (k>0 && top>-1) {
//         --top;
//         --k;
//     }
//     if (top == -1) stk[++top]='0';
//     stk[++top]='\0';
//     return stk;
// }
// //
// int main(void) {
//     char* arr="1432219";//7
//     char* rt=removeKdigits(arr,3);
//     printf("rt=%s\n", rt);
//     return 0;
// }



//38 分治算法：谈一谈大规模计算框架MapReduce中的分治思想
//MapReduce 看起来很高深, 实际上，万变不离其宗，它的本质就是分治。
//38.1 如何理解分治算法？
//38.1.1 核心思想: 分而治之
//将原问题分成 n 个规模较小，并且结构与原问题相似的子问题，递归解决这些子问题，然后合并结果，就得到原问题的解。
//分治算法是一种处理问题的思想，递归是一种编程技巧。
//实际上，分治算法适合用递归实现. 每层递归都会涉及这样3个操作:
//(1)分解：将原问题分解成一系列子问题；
//(2)解决：递归地求解各子问题，若子问题足够小，则直接求解；
//(3)合并：将子问题的结果合并。
//38.1.2 分治算法能解决的问题,满足:
//(1)原问题与分解成的小问题具有相同的模式
//(2)子问题可独立求解，子问题之间没有相关性. 这是它与DP的重要区别。
//(3)具有分解终止条件，当问题足够小时，可直接求解
//(4)可将子问题合并成原问题，而合并的复杂度不能太高

//38.2 分治算法应用举例分析
//(1) 求出一组数据的有/逆序对个数
//借助归并排序，在合并两个有序数组时，就可计算逆序对个数。
//(2) 二维平面上有 n 个点，如何快速计算出两个距离最近的点对？
//(3) 有两个 n*n 的矩阵 A，B，如何快速求解两个矩阵的乘积 C=A*B？

/*
int num=0;
void MergeTwo(int* a, int l, int m, int r) {
    int i=l, j=m+1, k=0;
    int* tmp=(int*)malloc(sizeof(int) * (r-l+1));
    while (i<=m && j<=r) {
        if (a[i] <= a[j]) tmp[k++]=a[i++];
        else {
            num += (m-i+1); //统计l-m之间，比a[j]大的元素个数
            tmp[k++]=a[j++];
        }
    }
    while (i<=m) tmp[k++]=a[i++];
    while (j<=r) tmp[k++]=a[j++];
    for (i=0; i<=r-l; ++i) a[l+i]=tmp[i];
}

void MergeSortCnting(int* a, int l, int r) {
    if (l>=r) return;
    int m=l+(r-l)/2;
    MergeSortCnting(a,l,m);
    MergeSortCnting(a,m+1,r);
    MergeTwo(a,l,m,r);
}

int InverseCount(int* a, int n) {
    num=0;
    MergeSortCnting(a,0,n-1);
    return num;
}
*/

//38.3 分治思想在海量数据处理中的应用
//数据量大到内存装不下的问题，就可用分治的思想
//根据某种方法，分为几个小的数据集合，各数据集合单独加载到内存来解决，然后再将小数据集合并成大数据集
//不仅能克服内存限制，还能利用多线程者多机处理，加快处理速度
//注意: 数据的存储与计算所在的机器是同一个或在网络中靠的很近. 否则会因为数据的访问速度，导致整个处理过程变慢

//38.4 解答开篇
//利用集群并行处理显然是大势所趋。
//MapReduce 框架只是一个任务调度器，底层依赖GFS存储数据，依赖Borg管理机器。
//利用 MapReduce 提供高可靠、高性能、高容错的并行计算框架，并行处理这几十亿、上百亿的网页。

//38.5 内容小结
//(1)分而治之: 将原问题分成 n 个规模较小而结构相似的子问题，递归地解决这些子问题，然后再合并结果，就得到原问题的解。
//(2)应用场景
//指导编码，降低问题求解的时间复杂度
//解决海量数据处理
//(3)创新的源泉来自对事物本质的认识
//无数优秀架构设计的思想来源都是: 基础的数据结构和算法，这本身就是算法的一个魅力所在。

//38.6 课后思考
//还有没有其他用到分治算法的地方
//将零散的知识提炼成体系

// int main(void) {
//     int arr[6]={1,5,6,2,3,4};
//     int cnt=InverseCount(arr,6);
//     printf("cnt=%d\n",cnt);//6
//     return 0;
// }



//39 回溯算法：从电影《蝴蝶效应》中学习回溯算法的核心思想
//DFS利用了回溯算法思想
//经典的数学问题: 数独、八皇后、0-1 背包、图的着色、旅行商问题、全排列等

//39.1 如何理解“回溯算法”？
//主要应用: 在一组可能的解中，搜索满足期望的解
//39.1.1 回溯的处理思想: 类似枚举搜索. 枚举所有的解，找到满足期望的解
//(1) 为了有规律地枚举所有可能的解，避免遗漏和重复，把问题求解的过程分为多个阶段。
//(2) 各阶段，都会面对一个岔路口，先随意选一条路，当发现这条路走不通（不符合期望的解），就回退到上一个岔路口，另选一种走法继续走。
//39.1.2 八皇后问题
//回溯算法非常适合用递归实现

/*
int rt[8]={0};
int cnt=0;
void printQueens(int* rt) {
    printf("cnt = %d\n", ++cnt);
    for (int i=0; i<8; ++i) {
        for (int j=0; j<8; ++j) {
            if (rt[i] == j) printf("Q ");
            else printf("* ");
        }
        printf("\n");
    }
    printf("\n");
}

bool isOK(int* rt, int row, int col) {
    int leftup=col-1,rightup=col+1;
    for (int i=row-1; i>=0; --i) {
        if (rt[i] == col) return false;
        if (leftup >= 0) {
            if (rt[i] == leftup) return false;
        }
        if (rightup < 8) {
            if (rt[i] == rightup) return false;
        }
        --leftup;
        ++rightup;
    }
    return true;
}

void EightQueens(int* rt, int row) {
    if (row==8) {
        printQueens(rt);
        return;
    }
    for (int col=0; col<8; ++col) {
        if (isOK(rt,row,col)) {
            rt[row] = col;
            EightQueens(rt, row+1);
        }
    }
}
*/

//39.2 两个回溯算法的经典应用
//39.2.1 0-1 背包
//很多场景可以抽象成这个问题模型。此问题可用DP求解。回溯法没有那么高效。
//总承载重量W。现有n个物品，各物品重量不等，并且不可分割。现期望选几件物品，装到背包中。在<=W的前提下，如何让背包中物品总重量最大？
//解决方案:
//(1)背包问题: 物品可分割. 而这里不可分割，贪心算法不能用。
//(2)总共的装法有2^n种。要去除大于W, 如何不重复地穷举出所有方法？
//把物品依次排列，整个问题分解为n个阶段，各阶段对应一个物品怎么选择。先处理第一个物品，选择装或不装，然后递归地处理剩下物品
//技巧: 搜索剪枝

// int maxW=INT_MIN;
// void f(int i, int cw, int* a, int n, int W) {
//     if (cw==W || i==n) {
//         if (cw > INT_MIN) maxW=cw;
//         return;
//     }
//     f(i+1, cw, a, n, W);//当前物品不装
//     if (cw+a[i] <= W) {
//         printf("a[%d] = %d\n", i, a[i]);
//         f(i+1, cw+a[i], a, n, W);//当前物品装
//     }
// }

//39.2.2 正则表达式
//正则表达式里最重要的一种算法思想就是回溯。
//背景假设: 只有2个通配符*和?, 分别匹配>=0个字符， 0/1个字符
//用回溯算法，判断一个给定的文本，能否跟给定的正则表达式匹配？
//(1)依次考察正则表达式中的各字符，非通配符时，直接跟文本的字符匹配，相同则继续往下处理；不同则回溯。
//(2)遇到特殊字符，所谓的岔路口。先随意选择一种匹配方案，然后考察剩下字符。如果中途发现无法继续匹配下去，回到这个岔路口，重新选择一种匹配方案，再继续匹配剩下字符

/*
typedef struct Pattern {
    bool matched;
    char* str;
    int sz;
}Ptn;

Ptn* createPtn(char* s, int sz) {
    Ptn* p=(Ptn*)malloc(sizeof(Ptn));
    p->matched=false;
    p->str=s;
    p->sz=sz;
    return p;
}

void rMatch(Ptn* p, int ti, int pj, char* text, int n) {
    if (p->matched) return;
    if (pj == p->sz) {
        if (ti == n) p->matched=true;
        return;
    }
    if (p->str[pj] == '*') {
        for (int k=0; k<=n-ti; ++k)
            rMatch(p, ti+k, pj+1, text, n);
    }
    else if (p->str[pj] == '?') {
        rMatch(p, ti, pj+1, text, n);
        rMatch(p, ti+1, pj+1, text, n);
    }
    else if (ti<n && p->str[pj] == text[ti])
        rMatch(p, ti+1, pj+1, text, n);
}

bool isMatch(Ptn* p, char* text, int n) {
    p->matched=false;
    rMatch(p, 0, 0, text, n);
    return p->matched;
}
*/

//39.3 内容小结
//用来解决广义搜索问题: 从一组可能的解中，选出一个满足要求的解
//回溯算法适合用递归实现，剪枝是提高回溯效率的一种技巧。
//可解决很多问题: DFS、八皇后、0-1 背包问题、图的着色、旅行商问题、数独、全排列、正则表达式匹配等等。
//如果这几个问题都能实现，你基本就掌握了回溯算法

//39.4 课后思考
//如果每个物品不仅重量不同，价值也不同。如何在不超过背包重量的情况下，让背包中的总价值最大？

/*
int main(void) {
    //EightQueens(rt, 0);
    // for (int i=0;i<8;++i) {
    //     printf("%d ",rt[i]);
    // }
    // printf("\n");
    
    // int arr[6]={10,8,7,6,4,2};
    // f(0,0,arr,6,100);
    // printf("maxW = %d\n", maxW);//37
    
    Ptn* p = createPtn("china*", 7);
    bool b1=isMatch(p, "china11", 8);
    printf("b1=%d\n", b1);//1

    return 0;
}
*/



//40 初识动态规划：如何巧妙解决“双十一”购物时的凑单问题？
//40.1 动态规划学习路线
//DP适合求解最优问题，比如求最大/最小值等
//它可显著降低时间复杂度，提高代码执行效率

//40.2 0-1 背包问题
//对于一组不同重量、不可分割的物品，选择一些装入背包，在满足背包最大重量限制的前提下，背包中物品最大总重量？
//40.2.1 回溯算法的时间复杂度高，是指数级别。如何降低时间复杂度？
//将回溯求解过程画成递归树，各节点(i,cw)表示一种状态: i表示将要决策第几个物品是否装入背包，cw 表示当前背包中物品的总重量
//发现，有些子问题的求解重复。可借助递归那节"备忘录"的形式。记录已经算好的f(i,cw),再次计算时直接从备忘录中提取。
//此方法跟DP的执行效率基本上没有差别
//
//40.2.2 DP求解方法
//(1) 把整个求解过程分为n个阶段，各阶段会决策一个物品是否放入。各物品决策后，cw会有多种情况/状态，对应到递归树中，很多不同的节点
//(2) 合并各层重复的节点，只记录不同的状态。基于上一层的状态集合，推导下一层的状态集合。
//保证各层不同状态的个数 <= W个  -->  避免每层状态个数的指数级增长
//(3) states[n][w+1]: 每层可以达到的不同状态
//直到考察完所有物品后，整个 states 状态数组都计算好了
//只需在最后一层，找一个值为 true 的最接近 W（这里是 9）的值，就是背包中物品总重量的最大值
//(4)DP思路
//把问题分解为多个阶段，各阶段对应一个决策。记录各阶段可达的状态集合（去掉重复），然后通过当前阶段的状态集合，推导下一个阶段的状态集合，动态地往前推进。
//时间复杂度: O(n*W)
//空间复杂度: O(n*(W+1))  -->  可以降低为 W+1

/*
int maxW=INT_MIN;
int weight[]={2,2,4,6,3};
int n=5;
int W=9;
bool mem[5][10]={0};
void f(int i, int cw) {
    if (cw == W || i == n) {
        if (cw > maxW) maxW=cw;
        return;
    }
    if (mem[i][cw]) return;
    f(i+1,cw);
    if (cw+weight[i] <= W) f(i+1,cw+weight[i]);
}

int package1(int* weight, int n, int W) {
    bool** states=(bool**)malloc(sizeof(bool*) * n);
    for (int i=0; i<n; ++i) {
        states[i]=(bool*)malloc(sizeof(bool) * (W+1));
        memset(states[i], 0, sizeof(bool) * (W+1));
    }
    states[0][0]=true;
    if (weight[0] < W) states[0][weight[0]]=true;

    for (int i=1; i<n; ++i) {
        for (int j=0; j<=W; ++j) {
            if (states[i-1][j] == true) states[i][j]=states[i-1][j];
        }
        for (int j=0; j<=W-weight[i]; ++j) {
            if (states[i-1][j] == true) states[i][j+weight[i]]=true;
        }
    }
    for (int i=W; i>=0; --i) {
        if (states[n-1][i] == true) return i;
    }
    return 0;
}

int package2(int* weight, int n, int W) {
    bool* states=(bool*)malloc(sizeof(bool) * (W+1));
    memset(states, 0, sizeof(bool) * (W+1));
    states[0]=true;
    if (weight[0] < W) states[weight[0]]=true;

    for (int i=1; i<n; ++i) {
        for (int j=W-weight[i]; j>=0; --j) {
             if (states[j]==true) states[j+weight[i]] = true;
        }
    }
    for (int i=W; i>=0; --i) {
        if (states[i] == true) return i;
    }
    return 0;
}
*/

//40.3 0-1 背包问题升级版
//一组不同重量/价值、不可分割的物品，选择将某些物品装入背包，在满足背包最大重量限制的前提下，背包中可装入物品的最大总价值？
//40.3.1 回溯法
//递归树中各节点表示一个状态(i,cw,cv): i表示要决策第 i 个物品是否装入，cw表示当前背包中物品的总重量，cv表示当前背包中物品的总价值
//有几个节点的 i 和 cw 完全相同, 可以舍弃其中cv较小的。
//40.3.2 DP
//把整个求解过程分为n个阶段，各阶段会决策一个物品是否放入。各阶段决策完后，背包中的物品的总重量及总价值，会有多种情况、会达到多种不同的状态。
//states[n][W+1]: 每层可达到的不同状态, 其值==当前状态对应的最大总价值
//合并各层(i, cw) 重复的状态/节点，只记录 cv 值最大的那个状态，然后基于这些状态来推导下一层状态
//(1)时间复杂度: O(n*W)
//(2)空间复杂度: O(n*W)  -->  优化为 W+1

/*
int package3(int* weight, int* val, int n, int W) {
    int** states=(int**)malloc(sizeof(int*) * n);
    for (int i=0; i<n; ++i) {
        states[i]=(int*)malloc(sizeof(int) * (W+1));
        memset(states[i], -1, sizeof(int) * (W+1));
    }
    states[0][0]=0;
    if (weight[0] <= W) {
        states[0][weight[0]] = val[0];
    }

    for (int i=1; i<n; ++i) {
        for (int j=0; j<=W; ++j) {
            if (states[i-1][j] >= 0) states[i][j]=states[i-1][j];
        }
        for (int j=0; j<=W-weight[i]; ++j) {
            if (states[i-1][j] >= 0) {
                int v=states[i-1][j] + val[i];
                if (v > states[i][j+weight[i]])
                    states[i][j+weight[i]]=v;
            }
        }
    }

    int maxVal=-1;
    for (int j=0; j<=W; ++j) {
        if (states[n-1][j] > maxVal) 
            maxVal = states[n-1][j];
    }
    return maxVal;
}
*/

//38.4 解答开篇
//0-1 背包问题中，我们找的是小于等于 w 的最大值，x 就是背包的最大承载重量 w+1
//这个问题，要找的是 >=200（满减条件）的值中最小的, 可以设置为1001
//利用 states 数组，倒推出被选择的商品序列。
//(1) 状态(i, j)只可能从 (i-1, j) 或 (i-1, j-value[i]) 两个状态推导过来, 所以检查它们是否可达，即 states[i-1][j]或 states[i-1][j-value[i]]是否是 true
//(2) 如果states[i-1][j]可达，说明没有购买第i个商品; 如果states[i-1][j-value[i]]可达，说明购买第i个商品
//从中选择一个可达的状态（都可达，就随意选择一个），然后，继续迭代地考察其他商品是否有选择购买。

/*
void double11(int* val, int n, int W) {
    bool** states=(bool**)malloc(sizeof(bool*) * n);
    for (int i=0; i<n; ++i) {
        states[i]=(bool*)malloc(sizeof(bool) * (3*W+1));
        memset(states[i], 0, sizeof(bool) * (3*W+1));
    }    
    states[0][0]=true;
    if (val[0] <= 3*W) {
        states[0][val[0]]=true;
    }

    for (int i=1; i<n; ++i) {
        for (int j=0; j<=3*W; ++j) {
            if (states[i-1][j] == true) states[i][j] = states[i-1][j];
        }
        for (int j=0; j<=3*W-val[i]; ++j) {
            if (states[i-1][j] == true) states[i][j+val[i]] = true;
        }
    }

    int j;
    for (int j=W; j<3*W+1; ++j) {
        if (states[n-1][j] == true) break;
    }
    if (j == 3*W+1) return;
    for (int i=n-1; i>=1; --i) {
        if (j-val[i] >= 0 && states[i-1][j-val[i]] == true) {
            printf("%d ", val[i]);
            j -= val[i];
        }
    }
    if (j != 0) printf("%d \n", val[0]);
}
*/

//38.5 内容小结
//(1)只要真正搞懂这两个问题，基本上动态规划已经入门一半了
//(2)大部分DP能解决的问题，都可通过回溯算法来解决. 空间换时间,DP提高了执行效率。
//(3)贪心、分治、回溯、动态规划，这四个算法思想有关的理论知识，大部分都是“后验性”
//在解决问题过程中，往往先想到如何用某个算法思想解决问题，然后才用算法理论知识，去验证这个算法思想解决问题的正确性
//
// 贪心：一条路走到黑，就一次机会，只能哪边看着顺眼走哪边
// 回溯：一条路走到黑，无数次重来的机会，还怕我走不出来 (Snapshot View)
// 动态规划：拥有上帝视角，手握无数平行宇宙的历史存档， 同时发展出无数个未来 (Versioned Archive View)

//38.6 课后思考
//改造杨辉三角，各位置的数字可随意填写，经过某个数字只能到达下面一层相邻的两个数字。
//假设你站在第一层，往下移动，把移动到最底层所经过的所有数字之和，定义为路径长度。
//编程求出从最高层移动到最底层的最短路径

/*
int main(void) {
    // f(0,0);
    // printf("maxW = %d\n", maxW);//9
    
    int weight[]={2,2,4,6,3};
    int value[]={3,4,8,9,6};
    int n=5;
    int W=9;    
    //int r1=package1(weight, n, W);
    //int r2=package2(weight, n, W);
    //int r3=package3(weight, value, n, W);
    //printf("r3 = %d\n", r3);//9,9,18
    //double11(value, n, W);
    
    return 0;
}
*/



//41 动态规划理论：一篇文章带你彻底搞懂最优子结构、无后效性和重复子问题
//41.1 “一个模型三个特征”理论讲解
//DP能解决的问题有什么规律?
//41.1.1 一个模型: 多阶段决策最优解模型. 一般用DP解决最优问题
//解决问题的过程，需经历多个决策阶段。各决策阶段都对应着一组状态。然后寻找一组决策序列，经过这组决策序列，能够产生最终期望求解的最优值。
//41.1.2 三个特征
//(1)最优子结构: 可通过子问题的最优解，推导出问题的最优解。 -->  可通过前面阶段的状态 推导 后面阶段的状态
//(2)后效性: 推导i+1阶段的状态时，只关心i阶段的状态值。i阶段状态确定后，不受后续阶段状态的影响。
//这个要求比较宽松。只要满足前面的DP模型，都会满足。
//(3)重复子问题: 不同的决策序列，到达某个相同的阶段时，可能会产生重复的状态。

//41.2 “一个模型三个特征”实例剖析
//有一个矩阵int w[n][n]; 每次只能向右或向下, 从左上角到右下角的最短路径长度?
//解决过程:
//(1) 从(0, 0)走到(n-1, n-1)，总共要走 2*(n-1) 步，即 2*(n-1) 个阶段。各阶段都有向右、向下2种决策，并且各阶段都对应一个状态集合
//从(0,0)到(i,j)的最短路径min_dist(i,j):  i 表示行，j 表示列  -->  这是一个多阶段决策最优解问题，符合DP的模型
//(2)问题中存在重复子问题: 从左上角到节点对应的位置，有多种路线
//前面阶段的状态确定后，不会被后面阶段的决策所改变
//min_dist(i,j) 可通过 min_dist(i,j-1) 和 min_dist(i-1,j) 两个状态推导出来
//min_dist(i,j) = w[i][j] + min(min_dist(i,j-1), min_dist(i-1,j))

//41.3 两种动态规划解题思路总结
//41.3.1 状态转移表法
//能用DP解决的问题，都可用回溯算法的暴力搜索解决.
//可先用简单的回溯算法，然后定义状态，各状态表示一个节点，然后对应画出递归树。
//根据递归树， 可判断是否存在重复子问题，以及重复子问题如何产生。以此寻找规律，看是否能用DP解决
//(1)直接用回溯加“备忘录”，来避免重复子问题
//(2)先画一个状态表。一般都是二维. 各状态包含3个变量，行、列、数组值。
//根据决策的先后过程，从前往后，根据递推关系，分阶段填充状态表中的各状态。最后，将递推填表的过程，翻译成代码，就是DP代码
//(3)无重复又不遗漏地穷举出所有走法?
//写出回溯代码
//画出递归树，节点中(i,j,dist)不重复，但(i,j)有很多重复，我们只需选择其中的最小dist节点
//41.3.2 状态转移方程法
//需要分析，某个问题如何通过子问题来递归求解，即最优子结构。根据最优子结构，写出递归公式，即状态转移方程
//状态转移方程的实现方法:
//(1)递归加“备忘录”
//(2)迭代递推
//状态转移方程是解决DP的关键, 写出状态转移方程，那DP问题就解决一大半.
//但是很多DP问题的状态不好定义，状态转移方程也就更不好想到。
//(3)不是每个问题都同时适合这两种解题思路, 根据具体题目， 看哪种思路清晰就用哪种方法。

/*
#define min(a,b) (((a) < (b)) ? (a) : (b))
int minDist=INT_MAX;
void minDistBT(int i, int j, int dist, int (*w)[4], int n) {
    if (i==n && j==n) {
        if (dist < minDist) minDist=dist;
        return;
    }
    if (i<n) minDistBT(i+1, j, dist+w[i][j], w, n);
    if (j<n) minDistBT(i, j+1, dist+w[i][j], w, n);
}

int minDistDP(int (*m)[4], int n) {
    int** states=(int**)malloc(sizeof(int*) * n);
    for (int i=0; i<n; ++i) {
        states[i]=(int*)malloc(sizeof(int) * n);
        memset(states[i], 0, sizeof(int) * n);
    }
    int sum=0;
    for (int j=0; j<n; ++j) {
        sum += m[0][j];
        states[0][j]=sum;
    }
    sum=0;
    for (int i=0; i<n; ++i) {
        sum += m[i][0];
        states[i][0]=sum;
    }

    for (int i=1; i<n; ++i) {
        for (int j=1; j<n; ++j)
            states[i][j] = m[i][j] + min(states[i][j-1], states[i-1][j]);
    }

    return states[n-1][n-1];
}

int matrix[4][4]={{1,3,5,9}, {2,1,3,4}, {5,2,6,7}, {6,8,4,3}};
int mem[4][4]={0};
int n=4;
int minDistT(int (*m)[4], int i, int j) {
    if (i==0 && j==0) return m[0][0];
    if (mem[i][j] > 0) return mem[i][j];
    int minLeft=INT_MAX;
    int minUp=INT_MAX;
    if (j>=1) minLeft=minDistT(m,i,j-1);
    if (i>=1) minUp=minDistT(m,i-1,j);

    mem[i][j] = m[i][j] + min(minLeft, minUp);
    return mem[i][j];
}
*/

//41.4 四种算法思想比较分析
//(1)贪心、回溯、动态规划: 可以抽象成多阶段决策最优解模型
//(2)分治: 尽管大部分也是最优解问题，但是，大部分都不能抽象成多阶段决策模型。
//(3)回溯是个“万金油”。基本上能用的动态规划、贪心解决的问题，都可用回溯解决, 相当于穷举搜索。
//时间复杂度非常高，是指数级别. 只能解决小规模数据问题。
//41.1.2 DP和分治的区别
//(1)DP: 可用DP解决的问题， 需满足3个特征，最优子结构、无后效性和重复子问题. --> DP高效地原因: 回溯算法实现中存在大量的重复子问题。
//(2)分治: 要求分割成的子问题，不能有重复子问题，而DP正好相反
//41.1.3 贪心
//DP的一种特殊情况
//能解决的问题需满足3个条件: 最优子结构、无后效性和贪心选择性
//贪心选择性: 通过局部最优的选择，能产生全局的最优选择。
//每一个阶段，都选择当前看起来最优的决策，所有阶段的决策完成后，最终由这些局部最优解构成全局最优解

//41.5 内容小结
//(1)状态转移方程法: 找最优子结构 - 写状态转移方程 - 将状态转移方程翻译成代码
//(2)状态转移表法: 回溯算法实现 - 定义状态 - 画递归树 - 找重复子问题 - 画状态转移表 - 根据递推关系填表 - 将填表过程翻译成代码
//(3)要想真的把这些理论知识理解透，化为己用，还需自己多思考，多练习。等你做了足够的题目后，自然就能自己悟出一些东西，这样再回过头来看理论，就会非常容易看懂。

//41.6 课后思考
//新的硬币找零问题。假设有几种不同币值的硬币 v1，v2，...... ，vn（单位是元）。如果要支付 w 元，求最少需要多少个硬币。


// int main(void) {
//     //int w[4][4]={{1,3,5,9}, {2,1,3,4}, {5,2,6,7}, {6,8,4,3}};
//     // minDistBT(0,0,0,w,n);
//     //int mindist=minDistDP(w,4);
//     int mindist=minDistT(matrix, 4-1, 4-1);
//     printf("mindist = %d\n", mindist);//19,19,19
//     return 0;
// }



//42 动态规划实战：如何实现搜索引擎中的拼写纠错功能？
//42.1 如何量化两个字符串的相似度？
//编辑距离Edit Distance: 将一个字符串转化成另一个字符串，需要的最少编辑次数(增加，删除，替换)
//计算方式:
//(1)Levenshtein distance: 两个字符串差异的大小  --> 增加、删除、替换字符这3个编辑操作
//(2)Longest common substring length: 两个字符串相似程度的大小  -->  只允许增加、删除字符这两个编辑操作

//42.2 如何编程计算莱文斯坦距离？
//多阶段决策最优解模型: 求解过程涉及多个决策阶段，需依次考察字符串中的各字符，跟另一个字符串是否匹配。
//匹配/不匹配石，分别如何处理。
//42.2.1 回溯
//根据回溯代码画出递归树，看是否有重复子问题。
//各节点表示一个状态(i,j,edist). 其中edist表示已执行的编辑操作的次数
//(i,j)相同的节点，只需保留edist最小的。
//状态(i,j)可能从(i-1,j),(i,j-1),(i-1,j-1)过来
//42.2.2 复杂算法问题的解决思路
//(1) 拿到问题，先单纯考虑人脑会如何解决，把抽象问题具体化。 -->  实例化几个测试数据，人脑分析具体实例的解，然后总结规律，再尝试套用学过的算法，看是否能够解决。
//(2) 多练。做多题目后，自然会有感觉，看到问题，立马就能想到能否用DP解决

// char* a="mitcmu";
// char* b="mtacnu";
// int n=6, m=6;
/*
int minDist=INT_MAX;
void lwstDist(int i, int j, int edist) {
    if (i==n || j==m) {
        if (j<n) edist += (n-i);
        if (j<m) edist += (m-j);
        if (edist < minDist) minDist=edist;
        return;
    }
    if (a[i] == b[j]) lwstDist(i+1, j+1, edist);
    else {
        lwstDist(i+1, j, edist+1);
        lwstDist(i, j+1, edist+1);
        lwstDist(i+1, j+1, edist+1);
    }
}

int minv(int x, int y, int z) {
    int v=x;
    if (y < v) v=y;
    if (z < v) v=z;
    return v;
}

int lwstDP(char* a, char* b, int n, int m) {
    int** minDist=(int**)malloc(sizeof(int*) * n);
    for (int i=0; i<m; ++i) {
        minDist[i]=(int*)malloc(sizeof(int) * m);
        memset(minDist[i], 0, sizeof(int) * m);
    }
    for (int j=0; j<m; ++j) {
        if (a[0] == b[j]) minDist[0][j]=j;
        else if (j != 0) minDist[0][j] = minDist[0][j-1] + 1;
        else minDist[0][j]=1;
    }
    for (int i=0; i<n; ++i) {
        if (a[i] == b[0]) minDist[i][0]=i;
        else if (i != 0) minDist[i-1][0] = minDist[i][0] + 1;
        else minDist[i][0]=1;
    }

    for (int i=1; i<n; ++i) {
        for (int j=1; j<m; ++j) {
            if (a[i]==b[j]) 
                minDist[i][j] = minv(minDist[i-1][j]+1, minDist[i][j-1]+1, minDist[i-1][j-1]);
            else 
                minDist[i][j] = minv(minDist[i-1][j]+1, minDist[i][j-1]+1, minDist[i-1][j-1]+1);
        }
    }
    return minDist[n-1][m-1];
}
*/

//42.3 如何编程计算最长公共子串长度？
//状态(i,j,max_lcs): 其中max_lcs表示a[0...i]和b[0...j]最长公共子串长度。
//42.3.1 回溯
//从 a[0]和 b[0]开始，依次考察两个字符串中的字符是否匹配:
//(1) 如果 a[i]与 b[j]互相匹配，我们将最大公共子串长度加一，并且继续考察 a[i+1]和 b[j+1]。
//(2) 如果 a[i]与 b[j]不匹配，最长公共子串长度不变，这个时候，有2个不同的决策路线:
//(2.1) 删除 a[i]，或者在 b[j]前面加上一个字符 a[i]，然后继续考察 a[i+1]和 b[j]；
//(2.2) 删除 b[j]，或者在 a[i]前面加上一个字符 b[j]，然后继续考察 a[i]和 b[j+1]。
//42.3.2
//状态(i,j)从(i-1,j-1),(i-1,j),(i,j-1)转移过来

// int maxv(int x, int y, int z) {
//     int v=x;
//     if (y > v) v=y;
//     if (z > v) v=z;
//     return v;
// }
// int lcs(char* a, char* b, int n, int m) {
//     int** mlcs=(int**)malloc(sizeof(int*) * n);
//     for (int i=0; i<m; ++i) {
//         mlcs[i]=(int*)malloc(sizeof(int) * m);
//         memset(mlcs[i], 0, sizeof(int) * m);
//     }
//     for (int j=0; j<m; ++j) {
//         if (a[0] == b[j]) mlcs[0][j]=1;
//         else if (j != 0) mlcs[0][j] = mlcs[0][j-1];
//         else mlcs[0][j]=0;
//     }
//     for (int i=0; i<n; ++i) {
//         if (a[i] == b[0]) mlcs[i][0]=1;
//         else if (i != 0) mlcs[i-1][0] = mlcs[i][0];
//         else mlcs[i][0]=0;
//     }
//     for (int i=1; i<n; ++i) {
//         for (int j=1; j<m; ++j) {
//             if (a[i]==b[j]) 
//                 mlcs[i][j] = maxv(mlcs[i-1][j], mlcs[i][j-1], mlcs[i-1][j-1]+1);
//             else 
//                 mlcs[i][j] = maxv(mlcs[i-1][j], mlcs[i][j-1], mlcs[i-1][j-1]);
//         }
//     }
//     return mlcs[n-1][m-1];
// }

//42.4 解答开篇
//(1)拼写纠错最基本的原理: 将拼写错误的单词和词库比较，给出编辑距离最小的单词，提示用户。
//(2)优化思路:
//(2.1)取出编辑距离最小的TOP10, 再根据其他参数，决策哪个单词给用户。
//(2.2)多种编辑距离最小Top10,取交集
//(2.3)统计用户的搜索日志，先在最常被拼错单词列表中查找。一旦找到，直接返回对应的正确的单词
//(2.4)引入个性化因素。先在用户常用的搜索关键词中，查找编辑距离最小的单词。
//(3)万变不离其宗。掌握了核心原理，就是掌握了解决问题的方法，剩下就靠自己的灵活运用和实战操练

//42.5 内容小结
//(1)DP的理论并不复杂: 是“一个模型三个特征”。但是，要想灵活应用并不简单。要真正理解、掌握DP，只有多练习。
//(2)这8个问题都非常经典，是精心筛选出来的。很多DP问题都可抽象成这几个问题模型，所以，一定要多看几遍，多思考一下，争取真正搞懂它们。
//只要弄懂了这几个问题，一般的DP问题，应该都可应付

//42.6 课后思考
//有一个数字序列包含 n 个不同的数字，如何求出这个序列中的最长递增子序列长度？
//比如 2, 9, 3, 6, 5, 1, 7 这样一组数字序列，它的最长递增子序列就是 2, 3, 5, 7，所以最长递增子序列的长度是 4。

/*
#define max(a,b) (((a) > (b)) ? (a) : (b))
// int lengthOfLIS(int* a, int n){
//     if (a==NULL || n==0) return 0;
//     int* dp=(int*)malloc(sizeof(int) * n);
//     for (int i=0; i<n; ++i) {
//         dp[i]=1;
//     }
//     for (int i=0; i<n; ++i) {
//         for (int j=0; j<i; ++j) {
//             if (a[j] < a[i]) dp[i]= max(dp[i], dp[j]+1);
//         }
//     }
//     int maxl=dp[0];
//     for (int i=1; i<n; ++i) {
//         if (dp[i] > maxl) maxl=dp[i];
//     }
//     return maxl;
// }

int lengthOfLIS(int* a, int n) {
    if (a==NULL || n==0) return 0;
    int* arr=(int*)malloc(sizeof(int)*n);
    memset(arr, 0, sizeof(int)*n);
    arr[0]=a[0];
    int k=0;
    for (int i=1; i<n; ++i) {
        if (a[i] > arr[k]) {
            arr[++k]=a[i];
            continue;
        }
        int l=0, r=k;
        while (l <= r) {
            int m=l+(r-l)/2;
            if (a[i] > arr[m]) l=m+1;
            else if (a[i] < arr[m]) r=m-1;
            else {
                l=m;
                break;
            }
        }
        arr[l]=a[i];
    }
    printArr(arr,n);
    return k+1;
}

int main(void) {
    // lwstDist(0,0,0);
    //int mindist=lwstDP(a,b,n,m);
    // int mindist=lcs(a,b,n,m);
    // printf("mindist = %d\n", mindist);//3,3

    //int arr[8]={10,9,2,5,3,7,101,18};
    int arr[6]={4,10,4,3,8,9};
    int len=lengthOfLIS(arr,6);
    printf("len = %d\n", len);//4,
    return 0;
}
*/

