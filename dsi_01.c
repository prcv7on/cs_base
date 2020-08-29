

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>


//01 数组内存及数组面试常问算法全面解析
//1.1 数组结构

//1.2 数组常用方法
//1.2.1 数组的声明: 先声明后使用
//1.2.2 数组常用的属性和方法
//1.2.3 数组的实践

//1.3 数组的内存解析
//数组初始化完成，对应的空间大小就固定不变。

//1.4 小试牛刀
//1.4.1 移除元素
//要求: 不用额外的数组空间，必须仅用 O(1) 额外空间并 原地 修改输入数组
//元素的顺序可以改变。不需要考虑数组中超出新长度后面的元素。

// int removeKey(int* a, int len, int key) {
//     int i=0;
//     while (i<len) {
//         if (a[i] == key) {
//             a[i]=a[len-1];
//             --len;
//         }
//         else ++i;
//     }
//     return len;
// }

//1.4.2 搜索插入位置
//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不在数组中，返回它顺序插入的位置。
//假设数组中无重复元素。

// int searchInsert(int* a, int n, int key) {
//     int l=0, r=n-1, idx=n;
//     while (l<=r) {
//         int mid= l + ((r-l)>>1) ;
//         if (key <= a[mid]) {
//             idx=mid;
//             r=mid-1;
//         }
//         else l=mid+1;
//     }
//     return idx;
// }

//1.4.3 盛最多的水
//找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
//不能倾斜容器，且 n>=2
//规律总结：两线段距离越远，同时较短线段长度越大，面积越大。

// int maxArea(int* a, int n) {
//     int maxA=0,l=0,r=n-1;
//     while (l<r) {
//         maxA = fmax(maxA, (r-l) * fmin(a[l], a[r]));
//         if (a[l] < a[r]) ++l;
//         else --r;
//     }
//     return maxA;
// }

//1.4.4 两数之和
//给定整数数组 arr 和 目标值 key 两个 整数，并返回他们的数组下标。
//假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

/*
typedef struct Stu {
	int val;
	int idx;
}St;

int cmp(const void* a, const void* b) {
	return ((St*)a)->val - ((St*)b)->val;
}

int* twoSum(int* nums, int sza, int key, int* szb) {
	int i, j;
	int* p = NULL;
	*szb = 0;
	St* mys = (St*)malloc(sza * sizeof(St));
	for (i = 0; i < sza; ++i) {
		mys[i].val = nums[i];
		mys[i].idx = i;
	}
	qsort(mys, sza, sizeof(St), cmp);

	for (i = 0, j = sza - 1; i < j;) {
		if (mys[i].val + mys[j].val < key)
			++i;
		else if (mys[i].val + mys[j].val > key)
			--j;
		else if (mys[i].val + mys[j].val == key) {
			*szb = 2;
			p = (int*)malloc(2*sizeof(int));
			p[0] = mys[i].idx;
			p[1] = mys[j].idx;
			break;
		}
	}
	free(mys);	

	return p;
}
*/

//1.4.5 三数之和（二数之和进阶版）
// 给定一个包含 n 个整数的数组arr，判断arr 中是否存在三个元素 a、b、c，使得 a+b+c=0？
// 找出所有满足条件且不重复的三元组。注意：答案中不可包含重复的三元组

/*
int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int** threeSum(int* a, int asz, int* rsz, int** csz){
    *rsz=0;
    if (asz == 0) return 0;
    int** ret=(int**)malloc(sizeof(int*) * asz * 6);
    int l=0,r=asz-1;

    *csz=malloc(sizeof(int) * asz * 6);
    qsort(a,asz,sizeof(int),cmp);
    ret[*rsz]=malloc(sizeof(int)*3);

    while (l+1 < r) {
        int i=l+1,j=r,sum=0;
        while (i<j) {
            sum=a[l]+a[i]+a[j];
            if (sum < 0) ++i;
            else if (sum > 0) --j;
            else {
                ret[*rsz][0]=a[l];
                ret[*rsz][1]=a[i];
                ret[*rsz][2]=a[j];
                (*csz)[*rsz]=3;
                ++(*rsz);
                ret[*rsz]=malloc(sizeof(int)*3);

                while(i<j && a[i] == a[++i]);
                while(i<j && a[j] == a[--j]);
            }
        }
        while (l+1<r && a[l] == a[++l]);
    }

    return ret;
}
*/

// void printArr(int* a, int n) {
//     printf("arr = ");
//     for (int i=0;i<n;++i) {
//         printf("%d ",a[i]);
//     }
//     printf("\n");
// }

// //最简单的动态规划题
// //状态转移方程：dp[i] = max(nums[i], nums[i] + dp[i-1])。
// int maxSubArray(int* a, int n){
//     // int dp[n];
//     // dp[0]=a[0];
//     // int i=0;
//     // for (i=1;i<n;++i) {
//     //     dp[i]=fmax(a[i],a[i]+dp[i-1]);
//     // }
//     // int sa=dp[0];
//     // for (i=1;i<n;++i) {
//     //     if (dp[i] > sa) sa=dp[i];
//     // }
//
//     int subsum=0,sa=INT_MIN;
//     for (int i=0;i<n;++i) {
//         subsum += a[i];
//         if (subsum>sa) sa=subsum;
//         if (subsum<0) subsum=0;
//     }
//     return sa;
// }

/*
int main(void) {
    //int arr[9]={1,3,5,7,9,2,3,6,3};
    //int n=removeKey(arr,9,3);

    // int arr[6]={1,2,4,6,7,9};
    // int idx=searchInsert(arr,6,3);
    // printf("idx=%d\n",idx);//2

    // int arr[9]={1,8,6,2,5,4,8,3,7};
    // int maxA=maxArea(arr,9);
    // printf("maxA=%d\n",maxA);//49

    // int a[10] = {1,3,5,7,2,4,11,8,9,6};
	// int b = 19;
	// int bsz;
	// int* s = twoSum(a,10,b,&bsz);
    // printArr(s,2);//7 6
	// free(s);

    // int arr[9]={-2,1,-3,4,-1,2,1,-5,4};
    // int sa=maxSubArray(arr,9);
    // printf("sa=%d\n",sa);

    int arr[6]={-1, 0, 1, 2, -1, -4};
    int rsz;
    int n;
    int* csz=&n;
    int** ret=threeSum(arr,6,&rsz,&csz);
    for (int i=0;i<rsz;++i) {
        printf("%d %d %d\n",ret[i][0], ret[i][1], ret[i][2]);
    }
    
    //printArr(arr,n);
    return 0;
}
*/


//1.5 小结
// 数组结构
// 数组常用方法
// 数组的内存解析
// 面试常问数组算法题

//1.6 具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
// 输入：[-2,1,-3,4,-1,2,1,-5,4]
// 输出：6
// 解释：连续子数组 [4,-1,2,1] 的和最大，为 6。





//02 单向链表、双向链表和循环链表
//链表的节点除了存储数据还会存储下个节点地址
//插入和删除数据时，时间复杂度都是O(1)
//2.1 单向链表
//2.1.1 单向链表结构原理
//2.1.2 单向链表实现

/*
typedef struct SingleNode {
    int data;
    struct SingleNode* next;
}sNode;

typedef struct SingleList {
    sNode* head;
    int size;
}sList;

sNode* create_sNode(int data) {
    sNode* p=(sNode*)malloc(sizeof(sNode));
    p->data=data;
    p->next=NULL;
    return p;
}

sNode* getHead(sList* ps) {
    return ps->head;
}

sNode* add(sList* ps, int data, int idx) {
    if (idx > ps->size) {
        printf("out of size! \n");
        return NULL;
    }
    sNode* cur=ps->head;
    for (int i=1;i<idx;++i) {
        cur=cur->next;
        //printf("i=%d\n",i);
    }
    //printf("cur->data=%d\n",cur->data);
    sNode* p=create_sNode(data);
    cur->next=p;
    ++ps->size;
    return p;
}

sNode* addTail(sList* ps, int data) {
    return add(ps, data, ps->size);
}

void addsNode(sList* ps, sNode* p) {
    sNode* cur=ps->head;
    while (cur->next != NULL) {
        cur=cur->next;
    }
    cur->next=p;
    while (p != NULL) {
        ++ps->size;
        p=p->next;
    }
}

int remove_sNode(sList* ps, int idx) {
    if (idx > ps->size - 1 || idx < 0) {
        printf("index out of range! \n");
        return -1;
    }
    sNode* cur=ps->head;
    for (int i=0;i<idx;++i) {
        cur=cur->next;
    }
    sNode* tmp=cur->next;
    cur->next=tmp->next;
    tmp->next=NULL;
    --ps->size;
    return tmp->data;
}

int removeTail(sList* ps) {
    return remove_sNode(ps, ps->size - 1);
}

void removeDuplicateNodes(sList* ps) {
    sNode* cur=ps->head->next;
    while (cur != NULL) {
        sNode* tmp=cur;
        while (tmp != NULL && tmp->next != NULL) {
            if (cur->data == tmp->next->data) {
                sNode* duplicateNode=tmp->next;
                tmp->next=duplicateNode->next;
                duplicateNode->next=NULL;
                --ps->size;
            }
            tmp=tmp->next;
        }
        cur=cur->next;
    }
}

sNode* getEndK(sList* ps, int k) {
    sNode* p1=ps->head->next;
    sNode* p2=ps->head->next;
    for (int i=1;i<k;++i) {
        if (p1 != NULL) p1=p1->next;
    }
    if (p1 != NULL) {
        while (p1 != NULL && p1->next != NULL) {
            p1=p1->next;
            p2=p2->next;
        }
        return p2;
    }
    return NULL;
}

int getSize(sList* ps) {
    return ps->size;
}


int main(void) {
    sNode n1,n2,n3;
    n1.data=1; n1.next=&n2;
    n2.data=2; n2.next=&n3;
    n3.data=3; n3.next=NULL;
    sList sl;
    sl.size=3;
    sl.head=&n1;
    addTail(&sl,4); addTail(&sl,5);
    int sz=getSize(&sl);
    printf("sz=%d\n",sz);//4

    return 0;
}
*/

//2.2 双向链表
//2.2.1 双向链表结构原理
//2.2.2  双向链表实现

/*
typedef struct DoubleNode {
    int val;
    struct DoubleNode* pre;
    struct DoubleNode* next;
}dNode;

typedef struct DoubleList {
    dNode* head;
    int size;
}dList;

dNode* create_dNode(int val) {
    dNode* p=(dNode*)malloc(sizeof(dNode));
    p->val=val;
    p->pre=p->next=NULL;
}

bool isEmpty(dList* pd) {
    return pd->head->pre == NULL;
}

//在链表最前面插入新节点
void addHead(dList* pd, int val) {
    dNode* p=create_dNode(val);
    if (pd->head != NULL) {
        pd->head->pre=p;
        p->next=pd->head;
    }
    pd->head=p;
    ++pd->size;
}

//在链表最后面插入新节点
void addTail(dList* pd, int val) {
    dNode* p=create_dNode(val);
    if (pd->head == NULL) pd->head=p;
    else {
        dNode* cur=pd->head;
        while (cur->next != NULL) {
            cur=cur->next;
        }
        cur->next=p;
        p->pre=cur;
    }
    ++pd->size;
}

//插入当前节点的前驱节点
void addPre(dList* pd, dNode* cur, int val) {
    if (pd->head == NULL || cur == pd->head) addHead(pd,val);
    dNode* p=create_dNode(val);
    cur->pre->next=p;
    p->next=cur;
    p->pre=cur->pre;
    cur->pre=p;
    ++pd->size;
}

//插入当前节点的后继节点
void addNext(dList* pd, dNode* cur, int val) {
    if (pd->head == NULL || cur == pd->head) addTail(pd,val);
    dNode* p=create_dNode(val);
    cur->next->pre=p;
    p->pre=cur;
    p->next=cur->next;
    cur->next=p;
    ++pd->size;
}

//删除当前节点的前驱节点
void deletePre(dList* pd, dNode* cur) {
    if (pd->head == cur) return;
    dNode* p=cur->pre;
    p->pre->next=cur;
    cur->pre=p->pre;
    p->pre=p->next=NULL;
    --pd->size;
}

// deleteNext:删除当前节点的后继节点
void deleteNext(dList* pd, dNode* cur) {
    if (cur->next == NULL) return;
    dNode* p=cur->next;
    cur->next=p->next;
    p->next->pre=cur;
    p->pre=p->next=NULL;
    --pd->size;
}

// deleteKey:删除当前节点
void deleteKey(dList* pd, int key) {
    dNode* cur=pd->head;
    while (cur->val != key) {
        cur=cur->next;
        if (cur==NULL) {
            printf("key not exist! \n");
            return;
        }
    }
    dNode* p=cur->pre;
    dNode* q=cur->next;
    if (cur==pd->head)
        q->pre=NULL;
    else if (cur->next == NULL)
        p->next=NULL;
    else {
        p->next=q;
        q->pre=p;
    }
    cur->pre=NULL;
    cur->next=NULL;
    --pd->size;
}

// : 打印当前节点的前驱节点值
void displayPre(dList* pd, dNode* cur) {
    dNode* p=cur->pre;
    if (p==NULL) {
        printf("pre node not exist! \n");
        return;
    }
    printf("cur <- ");
    while (p != NULL) {
        printf("%d <- ", p->val);
        p=p->pre;
    }
    printf("NULL\n");
}

// :打印当前节点的后继节点值
void displayNext(dList* pd, dNode* cur) {
    dNode* q=cur->next;
    if (q==NULL) {
        printf("next node not exist! \n");
        return;        
    }
    printf("cur -> ");
    while (q != NULL) {
        printf("%d -> ", q->val);
        q=q->next;
    }
    printf("NULL\n");
}

int getSize(dList* pd) {
    return pd->size;
}

void PrintdList(dList* pd) {
    dNode* p=pd->head;
    while (p != NULL) {
        printf("%d -> ",p->val);
        p=p->next;
    }
    printf("NULL\n");
}

int main(void) {
    dNode n0,n1,n2,n3;
    n0.val=0; n0.pre=NULL; n0.next=&n1;
    n1.val=1; n1.pre=&n0; n1.next=&n2;
    n2.val=2; n2.pre=&n1; n2.next=&n3;
    n3.val=3; n3.pre=&n2; n3.next=NULL;
    dList dl;
    dl.head=&n0;
    dl.size=4;
    addTail(&dl,4); addTail(&dl,5); addTail(&dl,6);
    deleteKey(&dl,5);
    displayPre(&dl,&n3);
    displayNext(&dl,&n3);
    PrintdList(&dl);

    return 0;
}
*/

//2.3 循环链表
//2.3.1 循环链表结构原理
//与单链表相似，只是尾节点的next指向头节点。
//特点：
//空链表: 当前节点指向自己
//非空循环链表: 将 dataN 的指针域指向 data0

/*
typedef struct CircleNode {
    int data;
    struct CircleNode* next;
}cNode;

typedef struct CircleList {
    struct CircleNode* head;
    int size;
}cList;

cNode* create_cNode(int data) {
    cNode* p=(cNode*)malloc(sizeof(cNode));
    p->data=data;
    p->next=NULL;
}

cNode* addKey(cList* pc, int key) {
    cNode* p=create_cNode(key);
    if (pc->head == NULL) pc->head=p;
    else {
        p->next=pc->head->next;
        pc->head->next=p;
    }
    ++pc->size;
    return p;
}

cNode* insertKey(cList* pc, int idx, int key) {
    if (idx >= pc->size) {
        printf("index out of range! \n");
        return NULL;
    }
    cNode* p=create_cNode(key);
    if (idx==0) {
        p->next=pc->head;
        pc->head=p;
    }
    else {
        cNode* cur=pc->head;
        cNode* pre=pc->head;
        int i=0;
        while (i != idx) {
            pre=cur;
            cur=cur->next;
            ++i;
        }
        pre->next=p;
        p->next=cur;
    }
    ++pc->size;
    return p;
}

cNode* removeHead(cList* pc) {
    if (pc->head == NULL) {
        printf("Can not remove head, head==NULL\n");
        return NULL;
    }
    else {
        cNode* tail=pc->head;
        while (tail->next != pc->head) {
            tail=tail->next;
        }
        pc->head=pc->head->next;
        tail->next=pc->head;
        --pc->size;
        return pc->head;
    }
}

cNode* removeIndex(cList* pc, int idx) {
    if (idx >= pc->size) {
        printf("index out of range! \n");
        return NULL;
    }
    cNode* p=pc->head;
    if (idx==0) pc->head=pc->head->next;
    else {
        cNode* cur=pc->head;
        cNode* pre=pc->head;
        int i=0;
        while (i != idx) {
            pre=cur;
            cur=cur->next;
            ++i;
        }
        pre->next=cur->next;
        p=cur;
    }
    --pc->size;
    return p;
}

cNode* removeKey(cList* pc, int key) {
    cNode* cur=pc->head;
    cNode* pre=pc->head;
    if (cur->data == key)
        pc->head=pc->head->next;
    else {
        while (cur->data != key) {
            pre=cur;
            cur=cur->next;
        }
        pre->next=cur->next;
        cur->next=NULL;
    }
    --pc->size;
    return cur;
}

cNode* findcNode(cList* pc, int key) {
    cNode* cur=pc->head;
    while (cur != NULL) {
        if (cur->data != key) cur=cur->next;
        else return cur;
    }
    return NULL;
}

void printcList(cList* pc) {
    printf("cList = ");
    if (pc->head == NULL) printf("NULL\n");
    else {
        cNode* cur=pc->head;
        while (cur->next != pc->head) {
            printf("%d -> ",cur->data);
            cur=cur->next;
        }
        printf("%d -> head\n",cur->data);
    }
}

int getSize(cList* pc) {
    return pc->size;
}


int main(void) {
    cNode n0,n1,n2;
    n0.data=0; n0.next=&n1;
    n1.data=1; n1.next=&n2;
    n2.data=2; n2.next=&n0;
    cList cl;
    cl.head=&n0;
    cl.size=3;

    addKey(&cl,3); addKey(&cl,4); addKey(&cl,5);
    removeKey(&cl,4);
    removeHead(&cl);
    printcList(&cl);
    int sz=getSize(&cl);
    printf("sz=%d\n",sz);

    return 0;
}
*/

//2.4 小试牛刀
//2.4.1 删除链表的中间节点
//2.4.2 如何找出有环链表的入环点？
//2.4.3 环形单链表约瑟夫问题
//2.4.4 链表相交

//2.5 小结
// 单向链表
// 双向链表
// 循环链表
// 小试牛刀

//2.6 运用以上知识判断一个链表是否为回文链表。
// 示例 1:
// 输入: 1->2
// 输出: false



//03 用双向链表实现LRU淘汰机制

// struct sNode {
//     int data;
//     struct sNode* next;
// };
// typedef struct sNode SN;

// void print_List(SN* node) {
//     while (node!= NULL) {
//         printf("%d -> ",node->data);
//         node=node->next;
//     }
//     printf("NULL\n");
// }

//3.1 反转一个单链表
//时间复杂度 O(n)
//空间复杂度 O(1)

/*
SN* reverse_List(SN* head) {
    SN* prv=NULL;
    SN* cur=head;
    while (cur != NULL) {
        SN* tmp = cur->next;
        cur->next=prv;
        prv=cur;
        cur=tmp;
    }
    return prv; //返回新的头引用
}

int main(void) {
    SN n1,n2,n3,n4,n5;
    n1.data=1; n2.data=2; n3.data=3; n4.data=4; n5.data=5; 
    n1.next=&n2; n2.next=&n3; n3.next=&n4; n4.next=&n5; n5.next=NULL;
    print_List(&n1);
    SN* rsn=reverse_List(&n1);
    print_List(rsn);
    return 0;
}
*/

//3.2 反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
//1 ≤ m ≤ n ≤ 链表长度
// 输入: 1->2->3->4->5->NULL, m = 2, n = 4
// 输出: 1->4->3->2->5->NULL

//3.3 旋转链表. 将链表每个节点向右移动 k 个位置，其中 k 是非负数。
// 找到旧的尾部并将其与链表头相连 old_tail.next = head，整个链表闭合成环，同时计算出链表的长度 n。
// 找到新的尾部，第 (n - k % n - 1) 个节点 ，新的链表头是第 (n - k % n) 个节点。断开环 newtail.next = None，并返回新的链表头 newhead。

/*
SN* rotate_right(SN* head, int k) {
    if (head == NULL) return NULL;
    if (head->next == NULL) return head;
    SN* old_tail=head;
    SN* new_tail=head;
    int i;
    for (i=1; old_tail->next != NULL; ++i) {
        old_tail=old_tail->next;
    }
    old_tail->next=head; //旧尾部与链表头相连, 此时链表长度为i
    for (int j=0;j<(i-k % i-1); ++j) {
        new_tail=new_tail->next;
    }
    SN* new_head=new_tail->next;
    new_tail->next=NULL;
    return new_head;
}

int main(void) {
    SN n1,n2,n3,n4,n5;
    n1.data=1; n2.data=2; n3.data=3; n4.data=4; n5.data=5; 
    n1.next=&n2; n2.next=&n3; n3.next=&n4; n4.next=&n5; n5.next=NULL;
    SN* head=rotate_right(&n1,2);
    print_List(head);
    return 0;
}
*/


//04 栈与队列的定义
//4.1 栈 LIFO，Last In First Out
//暂时存储数据的地方
//定义：限定仅在表尾进行插入和删除操作的线性表
//可通过数组或链表来实现，根据实现的数据结构不同，分别称为顺序栈和链式栈。

//4.1.1
// 栈顶（top）：允许进行数据插入和删除的一端
// 栈底（bottom）：栈顶的另一端
// 出栈（pop，弹栈）：删除栈顶的元素
// 入栈（push，压栈）：在栈顶插入新的元素
// 空栈：栈中元素个数为零
//4.1.2
//(1) 动态内存区，在CPU与内存之间， 栈起到了一个跨媒介的交互的作用
//(2) 管道(pipeline): CPU 运行程序前，从系统中获取应用程序规定的栈入口线性地读取执行指令
//程序运行过程本质就是一个压栈过程，因此栈还可用来存储调用函数时产生的断点信息
//(3) 在操作系统中，压栈使得栈顶地址减小，弹栈使得栈顶地址变大
//(4)栈帧: 保存了一个函数调用时所需维护的信息:
//1)函数的返回地址和参数
//2)临时变量：包括函数的非静态局部变量 及 编译器自动生成的其他临时变量


//4.2 队列 FIFO，First In First Out
//操作受限制的线性表
//可通过数组或链表来实现，根据实现的数据结构不同，分别称为顺序队列和链式队列
//用来存放 等待处理元素 的集合，一般用于缓冲、并发访问

//4.2.1 
// 队头（front）：只允许队列进行删除操作的一端
// 队尾（rear）：只允许队列进行插入操作的一端
// 入队（enqueue）：在队列后端中插入一个队列元素称为入队
// 出队（dequeue）：在队列前端删除一个队列元素称为出队
// 空队列：队列中没有元素
//4.2.2
//处理时间极短的即时消息处理是用不到队列的, 可以通过直接阻塞式的函数调用就可以解决。
//在大数据处理的应用场景下，一些消息处理会非常耗时，新消息传输过来，系统基本处于阻塞状态.
//这种场景下引入队列，把消息放在队列中，然后再使用新的线程进行处理，就能完美解决消息堵塞的问题

//4.3 牛刀小试
//4.3.1 线程的基本组成是什么？
//寄存器堆栈。

//4.3.2 OS 中的堆栈是什么？
// 栈（操作系统）：由编译器自动分配释放 ，存放函数的参数值，局部变量的值等。操作方式类似数据结构中的栈，栈使用一级缓存，被调用时处于存储空间中，调用完立即释放
// 堆（操作系统）：一般由程序员分配释放， 若不释放，程序结束时可能由OS回收，分配方式类似链表。堆则存放在二级缓存中，生命周期由虚拟机的垃圾回收算法决定（并不是一旦成为孤儿对象就能被回收）。所以调用这些对象的速度较慢
// 堆（数据结构）：堆可以被看成是一棵树，如：堆排序。
// 栈（数据结构）：一种后进先出的数据结构。

//4.3.3 堆栈用什么数据结构实现比较好？
// 静态数组：特点是长度固定，且长度在编译时候就确定。优点是结构简单，实现方便而不易出错。缺点是不够灵活以及固定长度不易控制，适用于知道明确长度的场合。
// 动态数组：特点是长度可在运行时确定 以及 可更改原数组长度。优点是灵活，缺点是由此会增加程序的复杂性。
// 链式结构：特点是无长度上线，需要时再申请分配内存空间，可最大程度实现灵活性。缺点是链式结构的链接字段需消耗一定内存，在链式结构中访问一个特定元素的效率不如数组

//4.4 课后思考
//队列相较于栈在实现其基本功能时有哪些差异，又是为什么造成了这些差异？



//05 栈与队列的存储结构与实现
//5.1 栈的多种存储结构以及实现 --> 数组和链表
//5.1.1 栈与队列的存储结构与实现
//顺序栈的实现形式也就是线性表顺序存储的实现形式-数组。
//因为栈底的变化最小，所以将数组下标为 0 的一端作为栈底，同时还要定义一个变量，表示栈顶元素在数组中的位置。
//5.1.2 顺序栈的各类功能实现
//5.1.3 栈的链式存储结构 --> 通过链表连接起来
//栈顶元素放在链表头部。通常，栈链无需头结点
//栈链与数组栈的区别： 充分利用内存中的零碎空间 VS 占据内存中的大块空间
//5.1.4 栈链的各类功能实现

/*
struct stack {
    int maxSize;
    int top;
    int* pa;
};
typedef struct stack stk;

void initial_stk(stk* ps, const int sz) {
    if (sz >= 0) {
        int* arr = (int*)malloc(sz*sizeof(int));
        ps->maxSize=sz;
        ps->top=-1;
        ps->pa=arr;
    }
    else {
        printf("stack initialize failed.\n");
    }
}

bool isEmpty(stk* ps) {
    return ps->top == -1;
}

bool isFull(stk* ps) {
    return ps->maxSize == ps->top;
}

void push(stk* ps, int val) {
    if (!isFull(ps)) {
        printf("push %d into stack.\n", val);
        ps->pa[++ps->top]=val;
    }
    else printf("stack is Full! \n");
}

int pop(stk* ps) {
    if (!isEmpty(ps)) return ps->pa[ps->top--];
    else {
        printf("stack is Empty! pop failed. \n");
        return -1;
    }
}

int getPeek(stk* ps) {
    if (ps->top>=0) return ps->pa[ps->top];
    else {
        printf("stack top is Empty! \n");
        return -1;
    }
}

void printStack(stk* ps) {
    if (ps->top>=0) {
        printf("stak= ");
        for (int i=ps->top; i>=0; --i)
            printf("%d ",ps->pa[i]);
        printf("\n");
    }
    else printf("stack is Empty!\n");
}

int getPeekN(stk* ps, int n) {
    if (n<ps->top) return ps->pa[n];
    else printf("getpeekN failed. \n");
}

int main(void) {
    stk mstk;
    initial_stk(&mstk, 10);
    push(&mstk,2); push(&mstk,4); push(&mstk,6); push(&mstk,8);
    pop(&mstk); pop(&mstk); 
    printStack(&mstk);
    int topdata=getPeek(&mstk);
    printf("topdata=%d\n",topdata);//4

    return 0;
}
*/

/*
struct stack_node {
    int data;
    struct stack_node* next;
};
typedef struct stack_node stknode;

void initialStack1(stknode* ps) {
    ps->data=-1;
    ps->next=NULL;
}

void initialStack2(stknode* ps, int val) {
    ps->data=val;
    ps->next=NULL;
}

void clearStack(stknode* ps) {
    ps->next=NULL;
}

int stackLength(stknode* ps) {
    stknode* psn=ps->next;
    int i;
    for (i=1; psn != NULL; ++i) {
        psn=psn->next;
    }
    return i;
}

int getTop(stknode* ps) {
    if (ps->next == NULL) return -1;

    return ps->data;
}

void push(stknode* ps, int val) {
    stknode sn;
    initialStack2(&sn,val);
    sn.next=ps;
    ps=&sn;
}

int pop(stknode** pps) {
    if ((*pps)->next == NULL) return -1;
    stknode* psn=(*pps)->next;
    (*pps)->next=NULL;
    int val = (*pps)->data;
    *pps=psn; //更新栈顶ps
    return val;
}

void printStack(stknode* ps) {
    printf("stack= ");
    while (ps != NULL) {
        printf("%d -> ",ps->data);
        ps=ps->next;
    }
    printf("NULL\n");
}

int main(void) {
    stknode n1,n2,n3,n4,n5;
    stknode* ps=&n1;
    stknode** pps=&ps;
    n1.data=1; n2.data=2; n3.data=3; n4.data=4; n5.data=5; 
    n1.next=&n2; n2.next=&n3; n3.next=&n4; n4.next=&n5; n5.next=NULL;
    push(ps,6); push(ps,7); push(ps,8); printStack(ps);
    pop(pps); printStack(*pps);
    int len=stackLength(*pps);
    printf("len=%d\n",len);//4

    return 0;
}
*/

//5.2 队列的多种存储结构以及实现
//5.2.1 队列的顺序存储结构
//必须静态内存分配或动态地申请一块连续内存空间，然后再设置2个内存指针进行空间管理
//队头指针front,队尾指针tail. 
//当队列进行插入删除操作时，队列元素的个数不断变化，队列所占存储空间在队列初始分配的连续空间中移动。
//首尾索引改为可来回变化的索引，就能极大提升队列性能
//(1) 假溢出 --> 加入新元素，队列产生数组越界错误，然后队列中还有很多位置空闲
//"下溢"现象：当队列为空时，出队运算产生的溢出现象。“下溢”是正常现象，常用作程序控制转移的条件。
//"真上溢"现象：当队列满时，做进栈运算产生空间溢出的现象。“真上溢”是一种出错状态，应设法避免。
//(2)循环顺序队列 --> 将顺序队列看成是首尾相接的循环结构 --> 解决假溢出
//如何判断队列是空还是满?
// 方案1：设置一个标志（flag）用来指示队列的满与空的状态。初始时设置flag=0，当入队操作成功就设置flag=1；当出队操作成功就设置flag=0。那么对列为空的判断条件是：rear==front && tag==0；队列满的判断条件是：rear==front && tag==1。
// 方案2：保留一个元素的存储空间。此时队列满时的判断条件为(rear+1)%maxsize==front；队列为空的判断条件还是front==rear。
// 方案3：可以设计一个计数器count，统计队列中的元素个数。此时，队列满的判断条件为：count>0 && rear==front；判断队列为空的条件为count==0
//需要注意:
// front的+1操作：front=(front+1)%maxsize
// tail的+1操作：rear=(rear+1)%maxsize
// 判断队列为空的条件：rear=front
// 判断队列为满的条件：(rear+1)%maxsize=front
// 队列元素个数：(rear-front+maxsize)%maxsize
// 相关参数的含义：front表示队头，rear表示队尾，两者的范围是：0 ~ maxsize-1

//5.2.2 顺序队列各类功能实现

/*
struct queue {
    int maxSize;
    int front;
    int tail;
    int* pd;
};
typedef struct queue qe;

void initialQueue(qe* pq, int sz) {
    pq->pd=(int*)malloc(sz*sizeof(int));
    pq->maxSize=sz;
    pq->front=pq->tail=-1;
}

bool isEmpty(qe* pq) {
    return pq->front == pq->tail;
}

bool isFull(qe* pq) {
    return (pq->front == -1 && pq->tail == pq->maxSize - 1) || (pq->tail + 1) % pq->maxSize == pq->front;
}

bool enQueue(qe* pq, int val) {
    if (!isFull(pq)) {
        pq->tail=(pq->tail+1)%pq->maxSize;
        pq->pd[pq->tail]=val;
        return true;
    }
    return false;
}

int deQueue(qe* pq) {
    if (!isEmpty(pq)) {
        pq->front=(pq->front+1)%pq->maxSize;
        return pq->pd[pq->front];
    }
    else return -1;
}

int peek(qe* pq) {
    if (!isEmpty(pq)) return pq->pd[pq->front];
    else return -1;
}

int size(qe* pq) {
    return (pq->tail - pq->front + pq->maxSize) % pq->maxSize;
}

void printQueue(qe* pq) {
    int front=pq->front;
    int tail=pq->tail;
    while (front != tail) {
        printf("%d -> ",pq->pd[front]);
        front=(front+1)%pq->maxSize;
    }
    printf("%d -> NULL\n",pq->pd[front]);
}


int main(void) {
    qe mque;
    initialQueue(&mque,16);
    enQueue(&mque,19); enQueue(&mque,2); enQueue(&mque,3); enQueue(&mque,4); 
    printQueue(&mque);
    deQueue(&mque); printQueue(&mque);
    int pk=peek(&mque);
    printf("pk=%d\n",pk);

    return 0;
}
*/

//5.2.3 队列的链式存储结构
//单链表，这根单链表只能在头部删除节点，在尾部添加节点。
//5.2.4 链式队列各类功能实现

/*
struct queue_node {
    int data;
    struct queue_node* next;
};
typedef struct queue_node qnode;

struct queue {
    int size;
    qnode* front;
    qnode* tail;
};
typedef struct queue qe;

void initialQnode(qnode* pqn, int val, qnode* next) {
    pqn->data=val;
    pqn->next=next;
}

void initialQueue1(qe* pqe) {
    pqe->size=0;
    pqe->front=NULL;
    pqe->tail=NULL;
}

void initialQueue2(qe* pqe, qnode* pqn, int val) {
    initialQnode(pqn,val,NULL);
    pqe->tail=pqe->front=pqn;
    ++pqe->size;
}

int length(qe* pqe) {
    return pqe->size;
}

bool isEmpty(qe* pqe) {
    return pqe->size == 0;
}

//向 tail 端队尾插入元素
void add(qe* pqe, qnode* pqn, int val) {
    initialQnode(pqn,val,NULL);
    if (isEmpty(pqe)) {
        pqe->tail=pqe->front=pqn;
    }
    else {
        pqe->tail->next=pqn;
        pqe->tail=pqe->tail->next;
    }
    ++pqe->size;
}

//从 front 端队首移除元素
int removeFront(qe* pqe) {
    if (isEmpty(pqe)) printf("queue is Empty! \n");
    qnode* poldNode=pqe->front;
    pqe->front=pqe->front->next;
    poldNode->next=NULL;
    --pqe->size;
    return poldNode->data;
}

int getFront(qe* pqe) {
    return pqe->front->data;
}

void clear(qe* pqe) {
    pqe->front=NULL;
    pqe->tail=NULL;
    pqe->size=0;
}

void printQueue(qe* pqe) {
    qnode* front=pqe->front;
    qnode* tail=pqe->tail;
    while (front != tail) {
        printf("%d -> ",front->data);
        front=front->next;
    }
    printf("%d -> NULL\n",front->data);
}


int main(void) {
    qe mqe;
    mqe.size=0;
    qnode n1,n2,n3,n4;
    initialQueue2(&mqe,&n1,1); 
    add(&mqe,&n2,2); add(&mqe,&n3,3); add(&mqe,&n4,4); 
    printQueue(&mqe); //1 -> 2 -> 3 -> 4 -> NULL
    removeFront(&mqe);
    printQueue(&mqe); //2 -> 3 -> 4 -> NULL

    return 0;
}
*/

//5.3 牛刀小试
//5.3.1 C++内存分配，堆栈区别，堆栈存储哪个存储更大？
//(1) C++内存分配
// 栈区（stack）—  由编译器自动分配释放，存放函数的参数值，局部变量的值等。其操作方式类似于数据结构中的栈。
// 堆区（heap） —  一般由程序员分配释放，若程序员不释放，程序结束时可能由 OS（操作系统）回收。注意它与数据结构中的堆是两回事，分配方式倒是类似于链表。
// 全局区（静态区）（static）—，全局变量和静态变量的存储是放在一块的，初始化的全局变量和静态变量在一块区域，未初始化的全局变量和未初始化的静态变量在相邻的另一块区域。程序结束后由系统释放。
// 文字常量区  —常量字符串就是放在这里的。程序结束后由系统释放。
// 程序代码区—存放函数体的二进制代码。
//(2) 堆栈区
// 管理方式不同；
// 空间大小不同；
// 能否产生碎片不同；
// 生长方向不同；
// 分配方式不同；
// 分配效率不同；
//(3) 堆栈空间大小
// 一般来讲在 32 位系统下，堆内存可以达到 4G 的空间，从这个角度来看堆内存几乎是没有什么限制的。
// 但是对于栈来讲，一般都是有一定的空间大小的，例如，在 VC6 下面，默认的栈空间大小是 1M（好像是，记不清楚了）。
// 当然，我们可以修改：打开工程，依次操作菜单如下：Project->Setting->Link，在 Category 中选中 Output，然后在 Reserve 中设定堆栈的最大值和 commit。
// 注意：reserve 最小值为 4Byte；commit 是保留在虚拟内存的页文件里面，它设置的较大会使栈开辟较大的值，可能增加内存的开销和启动时间。

//5.3.2 堆栈存储的数据分别是什么？

// 栈（操作系统）：由编译器自动分配释放 ，存放函数的参数值，局部变量的值等。其操作方式类似数据结构中的栈，栈使用一级缓存， 他们被调用时处于存储空间中，调用完立即释放
// 堆（操作系统）：一般由程序员分配释放， 若不释放，程序结束时可能由 OS 回收，分配方式类似链表。堆则存放在二级缓存中，生命周期由虚拟机的垃圾回收算法来决定（并不是一旦成为孤儿对象就能被回收）。所以调用这些对象的速度较慢。

//5.3.3 堆栈在线程进程中的区别？
//进程拥有独立的堆栈空间和数据段，每当启动一个新的进程必须给它分配一个独立地址空间，建立众多的数据表来维护它的代码段、堆栈段和数据段。
//线程拥有独立的堆栈空间，但是共享数据段。

//5.4 思考题
//栈与队列的两种不同的结构在计算机存储空间的利用率方面有哪些差异呢？



//06 栈与队列的应用

//6.1 栈的应用
//6.1.1 递归
//递归定义：通过不断调用函数自身进行压栈，直至终止条件，将其结果计算出来进行弹栈，并将结果返回给弹栈之后的栈顶，一直弹栈到栈空为止。
//如何应用栈实现递归？
//最重要的就2点：调用自己和终止条件

//6.1.2 符号成对出现

/*
bool isValid(char* pc, int len) {
    if (pc == NULL) return false;
    int stk[len];
    int top=-1;
    int cnt=0;//括号出现的次数
    char ch;

    for (int i=0;i<len;++i) {
        ch=pc[i];
        if (ch == '(' || ch=='[' || ch=='{') {
            ++cnt;
            stk[++top]=ch;
        }
        else if (ch == ')' || ch==']' || ch=='}') {
            ++cnt;
            if (top == -1) return false;
            if (ch-stk[top] == 1 || ch-stk[top] == 2) --top;
            else return false;
        }
    }

    return cnt>0 && top==-1;

}

int main(void) {
    char a[5]={'{','}','2',']','}'};
    bool b1=isValid(a,5);
    printf("b1=%d\n",b1);
    return 0;
}
*/

//6.1.3  四则运算
//难点: 让计算机知道加减乘除的优先级 以及 括号带来的优先级改变。
//逆波兰表示法Reverse Polish Notation,RPN --> 后缀表达式计算法
//规则是：从左到右遍历后缀表达式中各元素，遇到数字就进栈，遇到符号，就将位于栈顶的两个元素出栈，进行计算，计算的结果再进栈，最终得到结果。
//中缀表达式： 所有运算符号都在两个数字之间
//按照后缀转化规则，就可得到后缀表达式。具体规则是：
//从左到右遍历中缀表达式各数字和符号，是数字就输出，是符号就判断栈顶符号与其优先级，如果是右括号或优先级较低，则栈顶元素出栈并输出，并将当前符号入栈，一直这样的操作，直至后缀表达式输出为止

/*
bool toPostfix(char* pc, char* ps, char* pfix, int len) {
    int top=-1;
    int k;
    char ch,chf;
    for (int i=0;i<len;++i) {
        ch=pc[i];
        if (ch>='0' && ch<='9') pfix[k++]=ch;
        else if (ch == '(' || ch=='[' || ch=='{') ps[++top]=ch;
        else if (ch == ')' || ch==']' || ch=='}') {
            chf=ps[top--];
            if (chf == '(' || chf=='[' || chf=='{') break;
            else pfix[k++]=chf;
        }
        else if (ch == '+' || ch=='-' || ch=='*' || ch=='/') {
            if (top==-1) ps[++top]=ch;
            else {
                chf=ps[top];
                if ( (chf == '(' || chf=='[' || chf=='{') || fabs(chf-44)>fabs(ch-44))
                    ps[++top]=ch;
                else if ( !(chf == '(' || chf=='[' || chf=='{') && fabs(chf-44)<=fabs(ch-44))
                    pfix[k++]=chf;
            }
        }
        else {
            printf("expression is unright!\n");
            return false;
        }
    }

    while (top != -1) {
        ch=ps[top--];
        if (ch == '+' || ch=='-' || ch=='*' || ch=='/')
            pfix[k++]=ch;
        else break;
    }
    return false;
}

int calculate(char* pfix, int len) {
    int stk[len];
    int top=-1;
    int op1,op2,tmp;
    char ch;

    for (int i=0;i<len;++i) {
        ch=pfix[i];
        if (ch<='9' && ch>='0') stk[++top]=ch-'0';
        else {
            op1=stk[top--];
            op2=stk[top--];
            switch (ch) {
            case '+':
                tmp=op1+op2;
                break;
            case '-':
                tmp=op1-op2;
                break;
            case '*':
                tmp=op1*op2;
                break;
            case '/':
                tmp=op1/op2;
                break;
            }
            stk[++top]=tmp;
        }
    }
    return stk[top--];
}

int main(void) {
    char arr[9]="1+6*3/2-4";
    char postfix[9];
    char opStk[9];
    toPostfix(arr,opStk,postfix,9);
    int ret=calculate(postfix,9);
    printf("ret=%d\n",ret);//16 error
    return 0;
}
*/

//6.2 队列的应用
// 2.1 两个栈实现一个队列
//注意2点:
//(1) StackA向StackB压入元素，必须保证一次性全部压栈。
//(2) 从队列中取出元素，必须保证该元素是从StackB中弹出的，也就是决不能在StackB非空的时候，对StackB进行压栈。

/*
struct twoStackQueue {
    int sa[8];
    int sb[8];
    int t1;
    int t2;
};
typedef struct twoStackQueue qe;

bool add(qe* pqe, int val) {
    pqe->sa[++pqe->t1]=val;
    return true;
}

int poll(qe* pqe) {
    if (pqe->t1 == -1 && pqe->t2 == -1)
        return -1;
    if (pqe->t2 == -1) {
        while (pqe->t1 != -1) {
            pqe->sb[++pqe->t2]=pqe->sa[pqe->t1--];
        }
    }
    return pqe->sb[pqe->t2--];
}

int peek(qe* pqe) {
    if (pqe->t1 == -1 && pqe->t2 == -1)
        return -1;
    if (pqe->t2 == -1) {
        while (pqe->t1 != -1) {
            pqe->sb[++pqe->t2]=pqe->sa[pqe->t1--];
        }
    }
    return pqe->sb[pqe->t2];
}

void printSa(qe* pqe) {
    int t1=pqe->t1;
    for (int i=0;i<=t1;++i) {
        printf("%d -> ",pqe->sa[i]);
    }
    printf("NULL\n");
}

void printSb(qe* pqe) {
    int sz=pqe->t2+1;
    for (int i=sz;i>=0;--i) {
        printf("%d -> ",pqe->sb[i]);
    }
    printf("NULL\n");
}

int main(void) {
    qe mqe;
    mqe.t1=mqe.t2=-1;
    add(&mqe,1); add(&mqe,2); add(&mqe,3); add(&mqe,4); add(&mqe,5);
    printf("mqe.t1=%d\n",mqe.t1);//4
    printSa(&mqe);//1 -> 2 -> 3 -> 4 -> 5 -> NULL
    poll(&mqe);
    // int pk=peek(&mqe);
    // printf("pk=%d\n",pk);//2
    printSb(&mqe); //1 -> 2 -> 3 -> 4 -> NULL

    return 0;
}
*/

// 2.2 两个队列实现一个栈
//唯一的事情就是判断目前出队的值是否是按照放入元素顺序
//2.2.1 需要注意的2点是：
// 出栈操作时：将QueueA出队到QueueB，需要保留一个元素用来弹出。
// 入栈操作时：需要保证QueueA为空，同时将新元素加入到非空队列中。
//2.2.2 操作要点：
// 通过两个队列实现一个栈的过程中，任何时候都要保证其中一个队列是空的。
// 添加元素总是向非空队列中添加新元素
// 弹栈的时候，需要将其中一个队列中非队列尾的所有元素导入到另一个空队列中，然后将队尾元素出栈、

/*
struct twoQueueStack {
    int q1[8];
    int q2[8];
    int f1;
    int f2;
};
typedef struct twoQueueStack stk;

int push(stk* ps, int val) {
    if (ps->f1 != -1) {
        printf("q1 入队 %d\n", val);
        ps->q1[++ps->f1]=val;
    }
    else if (ps->f2 != -1) {
        printf("q2 入队 %d\n", val);
        ps->q2[++ps->f2]=val;
    }
    else {
        printf("q1 入队 %d\n", val);
        ps->q1[++ps->f1]=val;       
    }
}

int pop(stk* ps) {
    printf("---------------\n");
    if (ps->f1 == -1 && ps->f2 == -1) return -1;
    int ret=0;
    // printf("ps->f1=%d\n",ps->f1);
    // printf("ps->f2=%d\n",ps->f2);
    int i=-1;
    if (ps->f1 != -1) {
        while (ps->f1 != -1) {
            ret=ps->q1[++i];
            --ps->f1;
            if (ps->f1 != -1) {
                printf("从q1出队, q2入队 %d\n",ret);
                ps->q2[++ps->f2]=ret;
            }
        }
        // printf("i=%d\n",i);
        // for (int k=0;k<i;++k) {
        //     printf("ps->q2[%d]=%d\n", k, ps->q2[k]);
        // }
        printf("q1 出队 %d\n", ret);
    }
    else {
        while (ps->f2 != -1) {
            ret=ps->q2[++i];
            --ps->f2;
            if (ps->f2 != -1) {
                printf("从q2出队, q1入队 %d\n",ret);
                ps->q1[++ps->f1]=ret;
            }
        }
        // for (int k=0;k<i;++k) {
        //     printf("ps->q1[%d]=%d\n", k, ps->q1[k]);
        // }
        printf("q2 出队 %d\n", ret);        
    }
    // printf("ps->f1=%d\n",ps->f1);
    // printf("ps->f2=%d\n",ps->f2);
    printf("---------------\n");
    return ret;
}


int main(void) {
    stk mstk;
    mstk.f1=mstk.f2=-1;
    push(&mstk,1); push(&mstk,2); push(&mstk,3); push(&mstk,4);
    pop(&mstk); pop(&mstk); pop(&mstk); pop(&mstk);

    return 0;
}
*/

// 2.3 杨辉三角


//6.3 牛刀小试
//6.3.1 使用堆栈来模拟队列的功能，要求数据必须存储在堆栈内部。需要实现入队、出队、判断为空三个功能？

// 假定输出序列为Y，对于n个元素的输入序列X，若按照如下过程进行操作：
//(1) X 中元素按序全部顺序进入 S1 中；
//(2) 依次将 S1 中元素出栈并压入 S2 栈中，直到 S1 栈空为止；
//(3) 依次将 S2 中元素出栈并送输出序列 Y，直到 S2 栈空为止。

// 则输出序列的顺序与输入序列 X 完全相同，符合队列先进先出的特点。进一步分析可知，若将 X 从左向右分成若干段，按从左到右的顺序对每个段作上述操作，亦可得到同样的结果。
//所以，用两个栈模拟队列三个功能的操作过程可描述如下：

//(1) enqueue（入 队）：入队元素直接放入 S1 栈中（Push）。
//(2) dequeue（出队）：若 S2 栈不为空，则取 S2 栈的栈顶元素（Pop）作为出队元素；否则将栈 S1 中元素全部搬到 S2 中，再取 S2 栈的栈顶元素（Pop）作为出队元素（这可视为将入队元素分段地通过 S1 和 S2 栈）。
//(3) isEmpty（判空）：若 S1 和 S2 两个栈均为空，则队列为空；否则不为空。

//6.4 小结
// 栈的应用：递归、符号成对出现、四则运算、汉诺塔。
// 队列的应用：两个栈实现一个队列、两个队列实现一个栈、杨辉三角。

//6.55 课后思考
//在具体工程实现中，可以使用递归十分简洁地实现栈的相关功能，但是为什么我们依然不推荐在工程中使用呢？



//07 算法性能衡量的好坏
//算法Algorithm: 解题方案的准确而完整的描述，是一系列解决问题的清晰指令，算法代表着用系统的方法描述解决问题的策略机制。
//能够对一定规范的输入，在有限时间内获得所要求的输出。
//算法就是能解决问题，处理数据的指令. 在给予输入，然后给出正确的结果，处理这过程的方法就是算法

//7.1 时间复杂度
//T(n)=O(f(n)) --> 处理原则是: 不要低阶项，只要高阶项，且忽略高阶项的系数
//真正难的在于我们怎么通过算法分析与数学归纳运算得到T(n)
//7.1.1 总结规则，简单的分成四类:
//(1)嵌套循环
//循环体的时间复杂度是O(n), 循环次数为m, 时间复杂度是O(n_m)
//(2)多层嵌套
//外层循环的时间复杂度是O(n), 内层分别是O(a),O(b),...... 总的时间复杂度O(n*a*b*...)==O(n*n*1)
//(3)条件判断语句: 其中时间复杂度最大的路径的实际复杂度
//(4)顺序执行语句: 其中最大的时间复杂度的时间复杂度。
//7.1.2 基本策略是：
//从内向外分析，从最深层开始分析。如果遇到函数调用，要深入函数进行分析。

//7.2 空间复杂度
//同时间复杂度一样，只是对于趋势的度量
//O(1): 算法执行所需的临时空间不随着每个变量 n 的大小变化而变化
//O(N): 所分配的空间大小随着变量增大就增大

//7.3 排序算法的稳定性
//序列排序之后，序列中数的相对位置保持不变.
//快速排序是不稳定的，而归并排序是稳定的。

//7.4 外排序和内排序
//7.4.1 概念
// 内部排序：待排序记录存放在内存, 进行的排序过程。
// 外部排序：待排序记录的数量很大，内存不能一次容纳全部记录，所以在排序中需对外存进行访问的排序过程
//7.4.2 衡量效率的方法
// 内部排序：比较次数，也就是时间复杂度。
// 外部排序：IO 次数，也就是读写外存的次数。
//7.4.3 排序方法
//内部排序：插入排序、快速排序、选择排序、归并排序、基数排序等
//外部排序: 由两个相对独立的阶段组成
//(1)按可用内存大小，将外存上含 n 个记录的文件分成若干长度为 l 的子文件或段，依次读入内存并利用有效的内部排序方法对他们进行排序，并将排序后得到的有序子文件重新写入外存，通常称这些有序子文件为归并段
//(2)对这些归并段进行逐趟归并，使归并段逐渐由小至大，直至得到整个有序文件为止。

//7.5 小试牛刀
//7.5.1 求下面式子的时间复杂度。
//7.5.2 求下面式子的时间复杂度。

//7.6 小结
//7.6.1 时间复杂度：衡量算法计算过程中对于时间成本消耗的趋势。
//7.6.2 空间复杂度：衡量算法计算过程中对于空间成本消耗的趋势。
//7.6.3 稳定性：排序算法过程中，保持数之间是相对位置不变的算法我们称为稳定算法，否则为不稳定。
//7.6.4 内外部排序：排序过程中我们只需要使用内存即可完成排序工作我们认为是内部排序，而借用到外存来完成则是外部排序。

//7.7 课后思考
//对数阶O(logN)和线性对数阶O(nlogN)这两个，能否举个简单的例子场景



//08 基础排序算法
//8.1 选择排序
//对于给定序列，第一轮得到最小的元素，然后将该记录与首元素的位置交换。然后在剩下元素中找到最小元素，将它与序列第二个元素交换。
//如此重复执行，直到所有元素排好序。
//就是不断地选择剩下记录中最小的元素。
//(1)时间复杂度: (N-1)+(N-2)+......+2+1=N(N-1)/2 ~ O(N^2)
//(2)特点: 数据移动最小，移动一次是 N；运行时间与输入无关，每次循环不会为下次循环带来信息，执行的次数和时间都相同

/*
void printArr(int* a, int n) {
    printf("arr= ");
    for (int i=0;i<n;++i) {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void mswap(int* a, int i, int j) {
    // a[i] ^= a[j]; 
    // a[j] ^= a[i];
    // a[i] ^= a[j];
    int tmp=a[i];
    a[i]=a[j];
    a[j]=tmp;
}
*/

/*
void selectSort(int* a, int len) {
    if (a==NULL || len<2) return;
    int minIdx;
    for (int i=0;i<len-1;++i) {
        minIdx=i;
        for (int j=i+1;j<len;++j) {
            minIdx = a[j] < a[minIdx] ? j : minIdx;
        }
        if (minIdx != i) mswap(a,minIdx,i);
    }
}
*/

//8.2 插入排序
//类似于传统意义上的玩扑克，将扑克一张一张的插入到有序的牌的适当位置。
//对于给定的一组记录，初始时假设第一个数是一个有序序列，其余后面的数是无序序列。然后从第二个数开始，依次按照大小将数插入到前一个有序序列中，直到最后一个数插入到有序序列中
//插入排序所需的时间取决于输入中元素的初始顺序:
//(1)所有的元素都是有序: 那么内层嵌套不需要进行移动和插入的操作，就减少了极多的交换和比较的次数
//(2)完全乱序移动次数是 N-1 次
//平均需要N2/4 交换，最坏需要N2/2 交换，最好需要 N-1 次比较和 0 次交换
//在实际应用中, 常用于某些类型的非随机数组很有效，就比如对于相对有序的数组，进行插入排序，可以尽可能的减少元素移动的。

// void insertSort(int* a, int len) {
//     if (a==NULL || len<2) return;
//     for (int i=1;i<len;++i) {
//         for (int j=i-1; a[j] > a[j+1] && j>0; --j) {
//             //if (a[j] > a[j+1]) mswap(a,j,j+1);
//             mswap(a,j,j+1);
//         }
//     }
// }

//8.3 冒泡排序
//基本思想：类似于水中的泡泡，大的泡泡自动往上冒；
//对于给定的n个记录，从第一个记录开始，依次对第一个记录进行比较，当前面大于后面时，交换位置，一轮比较和换位后，n个记录中最大值交换到最后一个n位置，然后从新开始比较第 0 个到第 n-1 个，
//以此类推，每一轮找到最大的元素排列到后排位置。
//简单描述：冒泡排序与选择排序恰恰相反，每一次遍历，将最大的元素移动序列末尾。
//时间复杂度: O(n^2)
//空间复杂度: O(1)

/*
void bubbleSort(int* a, int len) {
    if (a==NULL || len<2) return;
    for (int i=len-1; i>0; --i) {
        for (int j=0;j<i;++j) {
            if (a[j] > a[j+1]) mswap(a,j,j+1);
        }
    }
}

int main(void) {
    int arr[9]={1,3,5,7,9,2,4,6,8};
    //selectSort(arr,9);
    //insertSort(arr,9);
    bubbleSort(arr,9);
    printArr(arr,9);
    return 0;
}
*/

//8.4 小试牛刀
//实现冒泡排序算法
//若用冒泡排序对关键字序列 {10,8,6,4,2}，进行从小到大的排序，所需进行的关键字比较总次数是

//8.5 小结

//8.6 课后思考
//三个算法的时间与空间复杂度，小伙伴能自行推导吗？



//09 排序算法进阶
//9.1 归并排序
//9.1.1 采用经典的分治策略（divide-and-conquer）：
//(1) 将问题分（divide）成一些小的问题然后递归求解，
//(2) 治（conquer）的阶段: 将分的阶段得到的各答案“修补”在一起，即分而治之。
//9.1.2 本文的归并排序采用递归（也可用迭代）：
//分阶段：递归拆分子序列，递归深度为log(2n)
//合并相邻有序子序列: 比较两个序列中的第一个数，谁小先取谁，然后再依次比较，如果序列为空，那么直接将另一有序序列的数据依次取出

/*
void merge(int* a, int i, int mid, int j) {
    int len=j-i+1;
    int b[len];
    int idx=0;
    int p1=i,p2=mid+1;
    while (p1<=mid && p2<=j) b[idx++] = a[p1] < a[p2] ? a[p1++] : a[p2++];
    while (p1<=mid) b[idx++] = a[p1++];
    while (p2<=j) b[idx++] = a[p2++];
    for (int k=0;k<len;++k) {
        a[i+k]=b[k];
    }
}

void mergeSort(int* a, int i, int j) {
    static int cnt=0;
    printf("cnt=%d\n",cnt++);
    if (i == j) return;
    int mid=i+((j-i)>>1);
    mergeSort(a,i,mid);
    mergeSort(a,mid+1,j);
    merge(a,i,mid,j);
}

void mSort(int* a, int len) {
    if (a==NULL || len<2) return;
    mergeSort(a,0,len-1);
}
*/

//9.2 快速排序
//基本思想：通过一趟排序将序列分成独立的两部分，其中一个序列均比另一序列小，则可分别对这两个序列排序，依次类推，以达到整个序列有序。
// 用分治法来把一个串（list）分为两个子串（sub-lists）。描述如下：
//(1) 从数列中挑出一个元素，称为“基准”（pivot）；
//(2) 重排数列，所有比基准值小的摆放在基准前面，大的在基准的后面（相同的可到任一边）。这个分区退出后，该基准处于数列的中间。这个称为分区（partition）操作；
//(3) 递归地（recursive）把小于基准值元素的子数列 和 大于基准值元素的子数列排序。

/*
//选择第一个为轴pivot
int partion(int* a, int l, int r) {
    if (l>=r) return -1;
    int pi=l;
    int li=l+1;
    int ri=r;

    while (ri>=li) {
        if (a[li] > a[pi]) mswap(a,ri--,li);
        else ++li;
    }
    pi=li-1;
    mswap(a,l,pi);
    return pi;
}

void quickSort(int* a, int l, int r) {
    if (l>=r) return;
    int mid=partion(a,l,r);
    quickSort(a,l,mid-1);
    quickSort(a,mid+1,r);
}
*/

//9.3 堆排序
//堆积是一个近似完全二叉树的结构，并同时满足堆积的性质：即子结点的键值或索引总是小于（或大于）它的父节点。
//9.3.1 完全二叉树: 除了末层，都达到最大节点数。尾层所有的结点， 都连续集中在最左边
//9.3.2 大根堆与小根堆
//9.3.3 算法描述,主要有如下两个过程:
//(1)HeapInsert
// 遍历堆，所有节点跟父节点比较，父节点小则交换，得到大根堆。
// 将最大值移动到数组的最后一位，数组下标减少 1。
//(2)Heapify
//从头节点开始，左右子节点大的与头结点进行比较，大于头结点的交换，从头结点开始往下，与子节点比较，数组依次循环，得到局部最大值，将最大值移出，数组下标减少1

// int main(void) {
//     int arr[5]={1,5,4,3,2};
//     //mSort(arr,5);
//     //qSort(arr,5);//error
//     quickSort(arr,0,4);
//     //hSort(arr,5);//to add
//     printArr(arr,5);
//     return 0;
// }

//9.4 小试牛刀
//9.4.1 使用堆排序方法排序（45,78,57,25,41,89），初始堆为
//9.4.2
//输入为两行。 第一行一个整数 n(1 ≤ n ≤ 100000)，表示一共有 n 个元素 第二行为 n 个数，即每个元素,每个整数都在 32 位 int 范围内。以空格分隔。
//输出一行，即排序之后的数组，以空格分隔，行末无空格
//利用quickSort

//9.5 小结

//9.6 课后思考
//分析快速排序、归并排序是否是稳定排序算法？利用第一章的时间与空间复杂度的知识，分析这三个算法的性能。



//10 排序算法性能比较与实际应用
//10.1 算法重温
//10.1.1 插入排序
//基本思想: 通过构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。
//形象的可以理解为打扑克抓牌的过程

//10.1.2 选择排序(升序)
//每次从无序数组中选择出最小数, 把他放到数组的最前面。
//再依次找次小的数字， 放到数组无序区的最前。直到数组为有序。

//10.1.3 堆排序(大堆，升序)
//更加优化的选择排序的版本，它利用了堆的特性。
//父结点的值大于子结点，且满足完全二叉树，大大提高了选择排序的效率。

//10.1.4 冒泡排序(升序)
//基本思想: 相近两个数字比较，小前大后，按照这个规则从头向后比较，最大数被换到数组尾

//10.1.5 快速排序
//应用场景是大规模的数据排序，并且实际性能要好于归并排序。
//基本原理：
//从数组中选取一个元素，把所有>这个元素的数都放到它的后面，所有<这个元素的数都放到它的前面，然后这个元素把数组切分成了两个部分
//再分别对这两个部分进行同样操作，直到数组不能再切分，此时数组有序

//10.1.6 归并排序
//“归并”: 将>=2个的有序表组合成一个新的有序表
//归并排序和快排一样, 采用分治思想
//基本原理: 若干有序的序列合并为一个有序序列

//10.2 比较
//稳定性: 若干相等数字，经排序后，它们相对次序保持不变

//排序算法      平均时间复杂度      最坏复杂度      空间复杂度      稳定性
//冒泡排序      O(n^2)            O(n^2)        O(1)            Y
//选择排序      O(n^2)            O(n^2)        O(1)            N      
//插入排序      O(n^2)            O(n^2)        O(1)            Y
//快速排序      O(nlogn)          O(n^2)        O(logn)         N
//归并排序      O(nlogn)          O(nlogn)      O(1)            Y
//堆排序        O(nlogn)          O(nlogn)      O(1)            N
//希尔排序      O(nlogn)          O(n^s)        O(1)            N

//10.3 应用场景
//(1)n<=50 直接插入或直接选择排序
//(2)初始状态基本有序(正序)： 直接插人、冒泡或快速排序为宜；
//(3)n较大，采用时间复杂度为O(nlogn): 快速排序、堆排序或归并排序。 
//快速排序是目前基于比较的内部排序中最好的，序列随机分布时，快速排序的平均时间最短；
//堆排序所需的辅助空间少于快速排序，并且不会出现快速排序可能出现的最坏情况。
//(4)先用直接插入排序求得较长有序子序列，然后再两两归并之。因为直接插入排序是稳定的，所以改进后的归并排序是稳定的



//11 二叉树的实现以及存储结构
//11.1 为什么需要树这种数据结构

//从二分查找到二叉树

//11.2 树的定义

//11.3 二叉树定义
//完全二叉树

//11.4 二叉树的存储结构
//顺序存储结构
//链式存储结构

//11.5 小试牛刀
//高度为 7 的完全二叉树的节点总数不可能是
//什么样的二叉树适合用数组来存储？
//给定一个数组，比如 1，2，3，4，5。可以构建出多少种不同的二叉树？
//求出一个二叉树的深度。
//给出一个完全二叉树，求出其节点个数。

//11.6 小结
// 二分查找
// 从二分查找引出二叉树：从一个侧面讲述我们为什么设计出树这种数据结构
// 树以及二叉树的定义
// 二叉树的存储结构：数组和链表存储

//11.7 课后思考
//本文通过完全二叉树这个特殊的二叉树串联起来了二叉树的理论和存储结构这两个部分，
//那么，你知道如何通过编程，来判断一棵树是不是完全二叉树呢？










