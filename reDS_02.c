

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



//11 递归：如何利用递归求解汉诺塔问题？
//数据结构: 数据组织形式 --> 降低时间复杂度
//算法思维: 数据处理 --> 降低时间复杂度

//11.1 什么是递归
//11.1.1 递归有两层含义
//(1)递归问题必须可分解为若干规模较小、与原问题形式相同的子问题。并且这些子问题可用完全相同的解题思路来解决；
//(2)递归问题的演化过程是一个对原问题从大到小进行拆解的过程，并且会有一个明确的终点
//最后，从这个临界点开始，把小问题的答案按原路返回，原问题便得以解决
//11.1.2 基本思想
//把规模大的问题转化为规模小的相同的子问题
//因为大小问题是一样的,解决大小问题的方法也一样，产生了函数调用它自身的情况
//这个解决问题的函数必须有明确的结束条件，否则会导致无限递归
//11.1.3 递归的实现2个部分
//(1)递归主体
//(2)终止条件

//11.2 递归的算法思想
//递归的数学模型就是数学归纳法
//11.2.1 当采用递归算法时, 围绕2个步骤:
//(1)如何将大规模问题分解为小规模的相同问题
//(2)终止条件如何定义
//11.2.2 可用递归法求解的问题，具有以下2个条件:
//(1)可拆解为更小规模的，求解思路完全相同的子问题；
//(2)存在终止条件。
//11.2.3 写出递归代码的步骤
//(1)找到将大问题分解成小问题的规律, 写出递推公式
//(2)找出终止条件, 即到达最简单问题时，如何写出答案。
//(3)将递推公式和终止条件翻译成代码

//11.3 递归的案例
//古老而又经典的汉诺塔问题
//11.3.1 拆解
//(1) 把从小到大的 n-1 个盘子，从 x 移动到 y；
//(2) 接着把最大的一个盘子，从 x 移动到 z；
//(3) 再把从小到大的 n-1 个盘子，从 y 移动到 z。
//其中，(1)(3)就是汉诺塔问题。
//11.3.2 终止条件
//移动最小的那个盘子
//11.3.3 翻译成代码
//hanio(n,x,y,z): 把 n 个盘子由 x 移动到 z
//递归体包含 3 个步骤:
//(1) 把从小到大的 n-1 个盘子从 x 移动到 y，代码是 hanio(n-1, x, z, y)；
//(2) 再把最大盘子从 x 移动到 z，那么完成一次移动就可；
//(3) 再把从小到大的 n-1 个盘子从 y 移动到 z，代码是 hanio(n-1, y, x, z)。
//对于终止条件则需判断 n 的大小。如果 n == 1，那么直接移动就可

// void hanio(int n, char x, char y, char z) {
//     if (n<1) printf("must n>=1 !\n");
//     else if (n==1) {
//         printf("move: %c -> %c\n",x,z);
//         return;
//     }
//     else {
//         hanio(n-1,x,z,y);
//         printf("move: %c -> %c\n",x,z);
//         hanio(n-1,y,x,z);
//     }
// }

//11.4 总结
//核心思想: 把大问题转化为小的相似的子问题
//分治策略、快速排序等， 都要用到递归

//11.5 练习题
//输入 x，输出斐波那契数列中第 x 位的元素

/*
int fib(int n) {
    if (n==1) return 0;
    if (n==2 || n==3) return 1;
    return fib(n-1)+fib(n-2);
}

int main(void) {
    // char x='x';
    // char y='y';
    // char z='z';
    // hanio(3,x,y,z);

    int n=fib(9);
    printf("n=%d\n",n);//21

    return 0;
}
*/


//12 分治：如何利用分治法完成数据查找？
//递归的思想: 函数自我调用缩小问题规模
//分治的核心思想是“分而治之”:
//(1)把一个大规模、高难度的问题，分解为若干小规模、低难度的子问题
//通常， 这些子问题互相独立、形式相同
//(2)采用同一种解法， 递归解决这些子问题
//(3)合并小问题的答案，得到原问题的答案
//快速排序和归并排序。都以分治法作为其基础思想。

//12.1 分治法是什么？
//核心思想就是分而治之
//将难以解决的大问题，递归分割成容易解决的小问题，直至各子问题都能直接求解。
//12.1.1 分治法的价值
//只有在大数据集上，分治法的价值才能显现
//复杂度为O(logn) 相比 复杂度O(n) 的算法，在大数据集合中性能有着爆发式的提高。

//12.2 分治法的使用方法
//12.2.1 采用分治法的问题具备特征:
//(1)难度在降低: 问题的解决难度，随着数据的规模的缩小而降低
//(2)问题可分: 原问题可分解为若干规模较小的同类型问题 --> 前提
//(3)解可合并: 所有子问题的解，可合并出原问题的解 --> 能否用分治法完全取决于这个特征
//(4)相互独立: 相互不会影响
//分治法需要递归地分解问题，再去解决问题。
//分治法在每轮递归上，都包含了分解问题、解决问题和合并结果这 3 个步骤。
//12.2.2 二分查找
//利用分治法去解决查找问题。最大的复杂度O(logn)
//前提: 数列有序

//12.3 分治法的案例
//在数组 { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 } 中，查找 8 是否出现过。

// bool isAppeared(int* a, int n, int key) {
//     int l=0,mid=0,r=n-1;
//     while (l<=r) {
//         mid=l+(r-l)/2;
//         if (a[mid] == key) {
//             printf("%d find in arr.\n", key);
//             return true;
//         }
//         else if (a[mid] > key) r=mid-1;
//         else l=mid+1;
//     }
//     return false;
// }

//12.3.1 快速找到解决方案，做好技术选型的经验:
//(1)二分查找的时间复杂度O(logn), 分治法大多如此。若问题要求时间复杂度O(logn)或O(nlogn), 考虑分治法。
//(2)二分查找的循环次数不确定。 多数会用 while循环加break跳出的代码结构
//(3)二分查找要求原问题有序，若数据环境有序，考虑分治。

//12.4 练习题
//在一个有序数组中，查找出第一个大于 9 的数字，假设一定存在。
//例如，arr = { -1, 3, 3, 7, 10, 14, 14 }; 则返回 10。

// int firstBiger(int* a, int n, int key) {
//     int l=0,mid=0,r=n-1;
//     int data=-100;
//     while (l<=r) {
//         mid=l+(r-l)/2;
//         if (a[mid] > key && (mid==0 || a[mid-1] <= key)) {
//             data=a[mid];
//             break;
//         }
//         else if (a[mid] > key) r=mid-1;
//         else l=mid+1;
//     }
//     return data;
// }

//12.5 总结
//(1)显著区别于遍历查找方法的优势, 分治法常用在海量数据处理中
//(2)分治法的先决条件:
//1) 原问题的数据是否有序
//2) 预期时间复杂度是否带有logn项
//3) 是否可通过小问题答案合并出原问题的答案

// int main(void) {
//     // int arr[10]={1,2,3,4,5,6,7,8,9,10};
//     // bool b1=isAppeared(arr,10,8);
//     // printf("b1=%d\n",b1);//1
//
//     int arr[7]={-1, 3, 3, 7, 10, 14, 14};
//     int data=firstBiger(arr,7,9);
//     printf("data=%d\n", data);
//     return 0;
// }



//13 排序：经典排序算法原理解析与优劣对比
//13.1 什么是排序问题?
//排序: 让一组无序数据变成有序的过程。
//13.1.1 衡量排序算法优劣的3个角度:
//(1) 时间复杂度: 最好/最坏/平均 时间复杂度
//(2) 空间复杂度: 如果空间复杂度为 1，也叫原地排序
//(3) 稳定性: 是指相等的数据对象，在排序后，顺序能否保证不变

//13.2 常见的排序算法及其思想

//13.2.1 冒泡排序
//(1)原理
//从第一个数据开始，依次比较相邻元素大小。如果前>后，则交换，把大元素往后换。多轮迭代，直到没有交换操作为止
//每次把最大数传递到最后
//(2)性能
//最好时间复杂度O(n)
//最坏时间复杂度O(n*n)
//平均时间复杂度O(n*n)
//空间复杂度O(1)
//元素相同时不交换 --> 稳定

// void bubbleSort(int* a, int n) {
//     for (int i=1; i<n; ++i) {
//         for (int j=0; j<n-i; ++j) {
//             if (a[j] > a[j+1]) {
//                 a[j]   ^= a[j+1];
//                 a[j+1] ^= a[j];
//                 a[j]   ^= a[j+1];
//             }
//         }
//     }
// }

//13.2.2 插入排序
//(1)原理
//选取未排序的元素，插入到已排序区间的合适位置，直到未排序区间为空。
//从左到右维护一个已有序的序列。直到所有数据全都完成插入动作
//(2)性能
//最好时间复杂度O(n)
//最坏时间复杂度O(n*n)
//平均时间复杂度O(n*n)
//空间复杂度O(1)
//稳定

// void insertSort(int* a, int n) {
//     for (int i=0;i<n;++i) {
//         int j=i-1;
//         for (;j>=0;--j) {
//             if (a[j] > a[i]) a[j+1]=a[j];
//             else break;
//         }
//         a[j+1]=a[i];
//     }
// }

//13.2.3 小结：插入排序和冒泡排序算法的异同点
//(1) 相同点
//平均时间复杂度都是O(n*n), 都是稳定排序算法。原地排序
//(2) 差异点
//冒泡排序: 每轮的交换操作是动态的，所以需要3个赋值操作
//插入排序: 每轮的交换动作会固定待插数据，因此只需一步赋值

//13.2.4 归并排序
//(1)原理
//分治法:
//1) 将数组不断二分，直到最后各部分只含 1 个数据
//2) 每部分分别排序
//3) 将排序好的相邻的两部分合并
//(2)性能
//归并排序的复杂度==(二分*合并)==O(logn)*O(n)==O(nlogn)
//最好、最坏、平均时间复杂度: O(nlogn) <-- 执行频次与输入序列无关
//空间复杂度O(n) --> 每次合并都需要开辟基于数组的临时内存空间
//稳定 --> 合并时，相同元素的前后顺序不变

// void mergeTwo(int* a, int* b, int l, int mid, int r) {
//     int p1=l,p2=mid+1,k=l;
//     while (p1<=mid && p2<=r) {
//         if (a[p1]<=a[p2]) b[k++]=a[p1++];
//         else b[k++]=a[p2++];
//     }
//     while (p1<=mid) b[k++]=a[p1++];
//     while (p2<=r) b[k++]=a[p2++];
//     for (int i=l; i<=r; ++i)
//         a[i]=b[i]; //复制回原数组
// }
// //
// void mergeSort(int* a, int* b, int beg, int end) {
//     if (beg < end) {
//         int mid=beg+(end-beg)/2;
//         mergeSort(a,b,beg,mid);//左侧子序列进行递归排序
//         mergeSort(a,b,mid+1,end);//右侧子序列进行递归排序
//         mergeTwo(a,b,beg,mid,end);//合并
//     }
// }

//13.2.5 快速排序
//(1)原理
//分治法
//1)每轮迭代，选取数组中任意一个数据作为分区点，将小于它的放左侧，大于它的放右侧
//2)再利用分治思想，继续分别对左右两侧进行同样的操作，直至每个区间缩小为 1
//3)完成排序。
//(2)性能
//最好时间的复杂度O(n*logn) --> 每次选取分区点时，都能选中中位数, 和归并一样
//最坏时间复杂度O(n*n) --> 每次分区都选中了最小值或最大
//平均时间复杂度O(n*logn)
//空间复杂度O(1)
//不稳定 --> 分区过程涉及交换操作

// void quickSort(int* a, int l, int r) {
//     if (l>=r) return;
//     int i=l,j=r;
//
//     while (i<j) {
//         while (a[l] <= a[j] && i<j) --j;
//         while (a[l] >= a[i] && i<j) ++i;
//         // printf("a[i]=%d, a[j]=%d\n",a[i],a[j]);
//         if (a[i] != a[j]) {
//             a[i] ^= a[j];
//             a[j] ^= a[i];
//             a[i] ^= a[j];
//         }
//         // printf("a[i]=%d, a[j]=%d\n",a[i],a[j]);
//         // printf("----------------------\n");
//     }
//     if (a[i] != a[l]) {
//         a[l] ^= a[i];
//         a[i] ^= a[l];
//         a[l] ^= a[i];
//     }
//
//     quickSort(a,l,j-1);
//     quickSort(a,j+1,r);
// }

//13.3 排序算法的性能分析
//(1)最暴力(冒泡排序和插入排序): 时间复杂度O(n*n)
//(2)归并排序: 时间复杂度O(n*logn)
//需要额外开辟临时空间 --> 保证稳定性, 归并时在数组中插入元素导致数据挪移
//(3)快速排序: 交换操作，可解决插入元素导致的数据挪移 --> 降低了不必要的空间开销
//由于其动态二分的交换数据 --> 不稳定

//13.4 总结
//(1)没有绝对的好和坏，各有利弊
//(2)规模比较小的数据: 可选O(n*n)的算法，此时O(n*logn)与O(n*n)区别很小
//(3)规模比较大的数据: O(n*logn)
//归并排序的空间复杂度O(n)
//快速排序平均时间复杂度O(n*logn), 最坏时间逼近O(n*n)，不具备稳定性

/*
void printArr(int* a, int n) {
    printf("arr = ");
    for (int i=0; i<n; ++i) {
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main(void) {
    //int arr[10]={1, 0, 3, 4, 5, -6, 7, 8, 9, 10};
    //int arr[8]={2, 3, 5, 1, 23, 6, 78, 34};
    //int arr[8]={49, 38, 65, 97, 76, 13, 27, 50};
    int arr[10]={6, 1, 2, 7, 9, 11, 4, 5, 10, 8};
    //bubbleSort(arr,10);
    //insertSort(arr,8);
    //int b[8]={0};
    //mergeSort(arr,b,0,8-1);
    quickSort(arr,0,10-1);
    printArr(arr,10);
    return 0;
}
*/



//14 动态规划：如何通过最优子结构，完成复杂问题求解？
//分治法使用须满足4个条件:
//(1) 问题的解决难度与数据规模有关；
//(2) 原问题可被分解；
//(3) 子问题的解可合并为原问题的解；
//(4) 所有子问题相互独立。
//满足前 3 个条件，唯独不满足第 4 个条件。
//求解这类问题的动态规划算法

//14.1 什么是动态规划
//一种运筹学方法，是在多轮决策过程中的最优方法。
//多轮决策的每一轮都可看作一个子问题, 但子问题不独立。
//实际的工作中，使用频率并不高，不是所有的岗位都会用到动态规划。

//14.1.1 最短路径问题
//状态: 是个变量，而且受决策动作的影响

//14.2 动态规划的基本方法
//解题方法没有那么标准化, 需要因题而异，仔细分析问题
//14.2.1 宏观层面通用方法:
//k 表示多轮决策的第 k 轮
//(1)分阶段: 将原问题分成几个子问题。一个子问题是多轮决策的一个阶段，它们可以不满足独立性
//(2)找状态: 选择合适的状态变量Sk --> 具备描述多轮决策过程的演变，更像是决策可能的结果。
//(3)做决策: 确定决策变量Uk. 每一轮的决策就是每一轮可能的决策动作
//(4)状态转移方程: DP最重要的核心, s(k+1)=Uk(Sk)
//(5)定目标: 代表多轮决策目标的指标函数V(k,n)
//(6)寻找终止条件。
//14.2.2 DP的基本概念:
//(1)最优子结构: 原问题的最优解所包括的子问题的解也是最优的
//例如，某个策略使得 A 到 G 是最优。假设它途径 Fi，那么从 A 到 Fi 也一定是最优的。
//(2)无后效性: 某阶段的决策，无法影响先前的状态。可以理解为今天的动作改变不了历史。
//(3)有重叠子问题: 子问题之间不独立
//是DP区别于分治法的条件
//如果原问题不满足这个特征，也可用DP求解，无非是杀鸡用牛刀

//14.3 动态规划的案例
//最短路径问题

//14.4 练习题
//最大公共子串

//14.5 总结
//动态规划并不简单，适用范围也没有那么广。
//运筹优化领域的工作, 需要掌握。



//15 定位问题才能更好地解决问题：开发前的复杂度分析与技术选型

//15.1 问题定位和技术选型
// 面对一个实际的算法问题,思考以下2方面:
//(1)明确目标: 用尽可能低的时间/空间复杂度，解决问题并写出代码
//(2)定位问题: 更高效地解决问题,包括:
//1)问题是什么类型（排序、查找、最优化）
//2)最低的时间复杂度
//3)用哪些数据结构或算法思维，能把这个问题解决

//15.2 通用解题的方法论
//(1)复杂度分析。估算问题中复杂度的上限和下限。
//(2)定位问题。根据问题类型，确定何种算法思维。
//(3)数据操作分析。根据增、删、查和数据顺序关系去选择合适的数据结构，利用空间换取时间。
//(4)编码实现。

//15.3 案例

//15.3.1 例 1
//在一个数组 a = [1,3,4,3,4,1,3] 中，找到次数最多的数字。如果并列存在多个，随机输出一个。
//解决方案总结为以下2点:
//(1)预期的时间复杂度是 O(n)，这就意味着编码采用一层的 for 循环，对原数组进行遍历。
//(2)额外设计哈希表，其中key是数组元素，value是频次。可支持O(1)时间复杂度的查找

// int maxCount(int* a, int n) {
//     int b[n];
//     int val=a[0],cnt=1;
//     for (int i=0;i<n;++i) {
//         if (a[i] == val) ++cnt;
//         else if (--cnt == 0) {
//             cnt=1;
//             val=a[i];
//         }
//     }
//     return val;
// }

//15.3.2 例 2
//two sums。给定整数数组arr和目标值 target，请在该数组中找出加和等于目标值的两个整数，并返回它们在原数组中的下标。
//解决方案，分析如下:
//(1) 预期时间复杂度O(n)，采用一层for循环，对原数组遍历
//(2) 数据结构需要额外设计哈希表，其中key是target - arr[i]，value是index。可支持O(1)时间复杂度的查找

// typedef struct Stu {
// 	int val;
// 	int idx;
// }St;
// //
// int cmp(const void* a, const void* b) {
// 	return ((St*)a)->val - ((St*)b)->val;
// }
// //
// int* twoSum(int* a, int sza, int target, int* szb) {
// 	int i, j;
// 	int* p = NULL;
// 	*szb = 0;
// 	St* mys = (St*)malloc(sza * sizeof(St));
// 	for (i = 0; i < sza; ++i) {
// 		mys[i].val = a[i];
// 		mys[i].idx = i;
// 	}
// 	qsort(mys, sza, sizeof(St), cmp);
//
// 	for (i = 0, j = sza - 1; i < j;) {
// 		if (mys[i].val + mys[j].val < target)
// 			++i;
// 		else if (mys[i].val + mys[j].val > target)
// 			--j;
// 		else if (mys[i].val + mys[j].val == target) {
// 			*szb = 2;
// 			p = (int*)malloc(2*sizeof(int));
// 			p[0] = mys[i].idx;
// 			p[1] = mys[j].idx;
// 			break;
// 		}
// 	}
// 	free(mys);	
//
// 	return p;
// }

//15.4 总结
//开发前，一定要分析问题的复杂度，做好技术选型。这就是定位问题的过程。
// 解决绝大多数代码问题的基本步骤：
//(1) 复杂度分析。估算问题中复杂度的上限和下限。
//(2) 定位问题。根据问题类型，确定采用何种算法思维。
//(3) 数据操作分析。根据增、删、查和数据顺序关系去选择合适的数据结构，利用空间换取时间。
//(4) 编码实现。

//15.5 练习题
//使用一个 for 循环完成结果的查找

/*
int main(void) {
    // int arr[9]={1,3,5,7,9,3,5,7,3};
    // int val=maxCount(arr,9);
    // printf("val=%d\n",val);//3

	int a[10] = {1,3,5,7,2,4,11,8,9,6};
	int b = 19;
	int bsz;
	int* s = twoSum(a,10,b,&bsz);

	printf("s = ");
    for (int i = 0; i < bsz; ++i) {
		printf("%d ",s[i]);
	}
    printf("\n");
	free(s);

    return 0;
}
*/


//16 真题案例（一）：算法思维训练
//16.1 例题1：斐波那契数列
//写一个函数，输入x，输出斐波那契数列中第 x 位的元素. 要求：需要用递归的方式来实现
//解题步骤详细分析:
//(1)复杂度分析: 递归次数与x有关，时间复杂度时高于x的函数
//(2)问题定位: 使用递归f(n)=f(n-1)+f(n-2), 终止条件:f(0)=0, f(1)=f(2)=1;
//(3)数据操作方面: 只是求和，无需复杂数据结构。
//(4)实现代码

// int fib(int n) {
//     if (n==1) return 0;
//     if (n==2 || n==3) return 1;
//     return fib(n-1)+fib(n-2);
// }

//16.2 例题2：判断一个数组中是否存在某个数
//给定一个经过任意位数的旋转后的排序数组，判断某个数是否在里面。
//解题步骤详细分析:
//(1)复杂度分析: 复杂度极限是全部遍历地去查找，O(n)
//(2)问题定位: 查找问题。
//(3)数据操作方面: 原数组是有序, 二分查找O(logn), 可以通过递归来实现.
//每次递归关键点: 根据切分的点（最中间数字），确定向左/向右。
//中间元素作切分点, 两个子数组中，至少有一个数组有序
//(4)实现代码

// int binarySearch(int* a, int key, int beg, int end) {
//     if (beg==end) {
//         if (a[beg] == key) return beg;
//         else return -1;
//     }
//     int mid=beg+(end-beg)/2;
//     if (a[mid] == key) return mid;
//     if (a[beg] <= a[mid-1]) {       //左边有序
//         if (a[beg]<=key && key<=a[mid-1])  //判断 key 是否在有序区间内
//             return binarySearch(a,key,beg,mid-1);
//         else
//             return binarySearch(a,key,mid+1,end);
//     }
//     else {                          //右边有序
//         if (a[mid+1]<=key && key<=a[end])   //判断 key 是否在有序区间内
//             return binarySearch(a,key,mid+1,end);
//         else
//             return binarySearch(a,key,beg,mid-1);
//     }
// }

//16.3 例题3：求解最大公共子串
//输入两个字符串，用动态规划的方法，求解出最大公共子串。
//例如，输入a= "13452439"， b="123456"。由于字符串"345"同时在a和b中出现，且是同时出现在a和b中的最长子串。因此输出"345"
//DP的基本方法：分阶段、找状态、做决策、状态转移方程、定目标、寻找终止条件。
// DP的步骤：
//(1) 对于一个可能的起点，它后面的每个字符都是一个阶段。
//(2) 状态: 当前找到的相匹配的字符。
//(3) 决策: 当前找到的字符是否相等（相等则进入到公共子串中）。
//(4) 状态转移方程 S(k+1) = Uk(Sk)
//可理解为，如果 sk = "123"是公共子串，且在 a串和b串中，"123"后面的字符相等，假设为"4"，则决策要进入到公共子串中，S(k+1) = "1234"。
//如果 b[i] = a[j]，则 m[i,j] = m[i-1,j-1] + 1
//如果决策结果是相等，则状态增加一个新的字符，进行更新
//(5) 目标: 公共子串最长。
//(6) 终止条件: 决策到了不相等的结果。

// char* maxStr(const char* a, const char* b) {
//     size_t n1=strlen(a);
//     size_t n2=strlen(b);
//     int m[n2+1][n1+1];
//     for (int i=0;i<=n2+1;++i) {
//         for (int j=0;j<=n1+1;++j)
//             m[i][j]=0;//初始化
//     }
//     for (size_t i=1; i<=n2; ++i) {
//         for (size_t j=1; j<=n1; ++j) {
//             if (b[i-1] == a[j-1])
//                 m[i][j] = m[i-1][j-1] + 1;
//         }
//     }
//     int maxcnt=0,idx=0;
//     for (int i=0; i<=n2; ++i) {
//         for (int j=0; j<=n1; ++j) {
//             if (m[i][j] > maxcnt) {
//                 maxcnt=m[i][j];
//                 idx=i;
//             }
//         }
//     }
//     printf("maxcnt=%d, idx=%d\n", maxcnt, idx);
//     char* rt=(char*)malloc(maxcnt*sizeof(char));
//     strncpy(rt,b+idx-maxcnt,maxcnt);
//     return rt;
// }

//16.4 总结
//线上实时交互的系统, 递归不适用。

/*
int main(void) {
    // int val=fib(9);
    // printf("val=%d\n",val);//21

    // int arr[7]={4, 5, 6, 7, 0, 1, 2};
    // bool b1=binarySearch(arr,7,0,7-1);
    // printf("b1=%d\n",b1);//1

    char s1[]="13452439";
    char s2[]="123456";
    char* rt=maxStr(s1,s2);
    printf("rt=%s\n",rt);//345

    return 0;
}
*/



//17 真题案例（二）：数据结构训练
//17.1 例题 1：反转字符串中的单词
//解题步骤分析:
//(1)复杂度: 拆模块, 做翻转
//(2)定位问题: 各单词必须顺序，单词间必须逆序
//(3)数据操作分析: 按照句子中单词顺序，将各单词依次入栈

// char* reverseWords(char* s) {
//     while (*s == ' ') ++s;//消除前面多余空格
//     size_t n=strlen(s)-1;
//     if (n<0) return s;
//     while (s[n] == ' ') s[n--]='\0';//消除后面的空格
//
//     char* ret=(char*)malloc(sizeof(char)*n);
//     char* stk=(char*)malloc(sizeof(char)*n);
//     int i=n,t=0,k=0;
//     while (i>=0) {
//         while (s[i] != ' ') stk[t++]=s[i--];
//         while (t>0) ret[k++]=stk[--t];
//         ret[k++]=' ';
//         while(s[--i] == ' ');
//         //printf("i=%d\n",i);
//     }
//     free(stk);
//     return ret;
// }

//17.2 例题 2：树的层序遍历
//解析:
//(1)结果对上下级关系的顺序非常敏感
//(2)左边的优先级大于右边大于下边。
//(3)结果序列对顺序敏感，且没有逆序操作 --> 队列
//(4)入队列的原则: 上层父节点先进，左孩子再进，右孩子最后进。
//解决方案: 
//根结点入队，随后循环执行节点出队并打印结果，左孩入队，右孩入队。直到队列为空。

/*
typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
}TN;

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
    if (p==NULL) return NULL;

    int bn=MAXSIZE*sizeof(int*);//byte number
    int** rt=(int**)malloc(bn);
    *csz=(int*)malloc(bn);
    for (int i=0;i<MAXSIZE;++i) {
        rt[i]=(int*)malloc(bn);
    }
    *sz=0;
    
    bfs(p,rt,*csz,0,sz);
    return rt;
}
*/

//17.3 例题 3：查找数据流中的中位数
//在一个流式数据中，查找中位数。如果是偶数个，则返回偏左边的那个元素。
//解析:
//(1)复杂度: 快排的时间复杂度O(n*logn)
//(2)查找问题: 非常重要的特点, 上一轮已得到有序数组, 下一轮仅需插入新数据即可。复杂度O(n)
//(3)数据的操作: 只需找到 < x的n/2个数字和 > x的n/2个数字
//维护一个最小(最大)的 n/2 个数字的集合，左边多存一个元素
//原问题最核心的瓶颈: 新增数据后，两个数据结构如何更新
//(4)题目只要中位数, 中位数左/右边是否有序不重要。 --> 大顶堆和小顶堆
//中位数左边的数据在大顶堆中，中位数右边的数据在小顶堆中. 两侧数据个数只差<=1
//插入新数据的时间复杂度O(logn), 新的中位数必定是大顶堆的顶元素

//void heapSort(int* a, int n) {}

//17.4 总结

/*
int main(void) {
    // char str[]="   This   is  a  good  example   ";
    // char* rt=reverseWords(str);
    // printf("rt = %s\n",rt);

    TN n1,n2,n3,n4,n5,n6,n7,n8;
    n1.val=1; n1.left=&n2;  n1.right=&n3;
    n2.val=2; n2.left=&n4;  n2.right=&n5;
    n3.val=3; n3.left=NULL; n3.right=&n6;
    n4.val=4; n4.left=NULL; n4.right=NULL;
    n5.val=5; n5.left=NULL; n5.right=NULL;
    n6.val=6; n6.left=&n7;  n6.right=&n8;
    n7.val=7; n7.left=NULL; n7.right=NULL;
    n8.val=8; n8.left=NULL; n8.right=NULL;
    int row=0;
    int* col;
    int** rt=LevelOrder(&n1,&row,&col);
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



//18 真题案例（三）：力扣真题训练
//18.1 例题 1：删除排序数组中的重复项
//给定一个有序数组，原地删除重复元素，使得各元素只出现一次，返回移除后的数组和新长度，不需考虑数组中超出新长度后面的元素。
//要求：空间复杂度 O(1)，不用额外数组空间

// int removeDuplicates(int* a, int n) {
//     int val=a[0];
//     int sz=1;
//     for (int i=1; i<n; ++i) {
//         if (a[i] != val) {
//             val=a[i];
//             a[sz++]=a[i];
//         }
//     }
//     return sz;
// }

//18.2 例题 2：查找两个有序数组合并后的中位数
//给定两个大小m和n的正序（从小到大）数组 arr1 和 arr2. 找出这两个数组合后的中位数，且要求时间复杂度O(log(m + n))
//你可以假设 arr1 和 arr2 不同时为空，所有数字全都不等。可以再假设，如果数字为偶数个，中位数是中间偏左的那个
//解析:
//(1)复杂度: 归并排序O(m+n)不满足O(log(m + n)) 的要求
//(2)问题的定位: 查找问题, 二分查找O(logn)
//(3)数据结构: 若干个指针，去约束查找范围. 空间复杂度O(1) 

/*
double findMid(int* a, int n1, int* b, int n2){
    int i=0,j=0,k=0;
    double pre=0, cur=0;
    int mid=(n1+n2)/2;

    for (k=0;k<=mid;++k) {
        pre=cur;
        if (i<n1 && j<n2) {
            if (a[i] > b[j]) cur=b[j++];
            else cur=a[i++];
        }
        else if (j<n2) cur=b[j++];
        else if (i<n1) cur=a[i++];
    }

    if ((n1+n2) & 1) return cur;
    else return (pre+cur)/2;
}
*/

//18.3 总结

/*
void printArr(int* a, int n) {
    printf("arr = ");
    for (int i=0; i<n; ++i) {
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main(void) {
    // int arr[10]={0,0,1,1,1,2,2,3,3,4};
    // int sz=removeDuplicates(arr,10);
    // printArr(arr,sz);

    int arr1[5]={1, 3, 5, 7, 9};
    int arr2[4]={2, 4, 8, 12};
    double midval=findMid(arr1,5,arr2,4);
    printf("midval = %.2f\n", midval);
    return 0;
}
*/

//18.4 练习题
//给定一个链表，删除链表的倒数第 n 个节点。
//例如，给定一个链表: 1 -> 2 -> 3 -> 4 -> 5, 和 n = 2。当删除倒数第二个节点，链表变为 1 -> 2 -> 3 -> 5
//要求, 在一趟扫描中实现，即时间复杂度是 O(n)


//19 真题案例（四）：大厂真题实战演练
//19.1 例题 1：判断数组中所有的数字是否只出现一次
//判断数组 arr 中是否所有的数字都只出现过一次。约束时间复杂度为 O(n)
//解析:
//(1)复杂度: 遍历数组复杂度O(n)
//(2)定位问题
//(3)数据操作: 每轮迭代需要去判断当前元素在先前已扫描过的区间内是否出现过 --> 查找
//哈希表, 能在O(1)时间内完成查找
//时间复杂度降低为O(n), 空间复杂度提高为O(n)

// int cmp (const void * a, const void * b) {
//   return *(int*)a - *(int*)b;
// }
// //
// bool isUnique(int* a, int n) {
//     qsort(a,n,sizeof(int),cmp);
//     for (int i=1;i<n;++i) {
//         if (a[i] == a[i-1])
//             return false;
//     }
//     return true;
// }

//19.2 例题 2：找出数组中出现次数超过数组长度一半的元素
//可以假设一定存在此数子。
//要求时间复杂度O(n)，空间复杂度O(1)

// int majorityElement(int* a, int n) {
//     int val=a[0];
//     int k=1;
//     for (int i=1;i<n;++i) {
//         if (a[i] != val) --k;
//         else ++k;
//         if (k == 0) {
//             k=1;
//             val=a[i];
//         }
//     }
//     return val;
// }
//
// int cmp(const void *a, const void *b) {
//     return *(int *)a - *(int *)b;
// }
//
// int majorityElement(int *a, int n) {
//     qsort(a, n, sizeof(int), cmp);
//     return a[n / 2];
// }

//19.3 例题 3：给定一个方格棋盘，从左上角出发到右下角有多少种方法
//在一个方格棋盘里，左上角是起点，右下角是终点。每次只能向右或向下，移向相邻的格子。同时，棋盘中有若干个格子是陷阱，不可经过，必须绕开行走。
//要求用DP，求出从起点到终点总共有多少种不同的路径。
//DP解题方法: 分阶段、找状态、做决策、状态转移方程、定目标、寻找终止条件。
//(1)决策: 每一个移动动作
//(2)状态: 移动后到达的新的格子
//(3)状态转移方程: V(m[i][j])=V(m[i-1][j]) + V(m[i][j-1])
//V(m[i][j]): 从起点到 m[i][j] 的可行路径总数
//(4)终止条件: V(m[0][0])=1; V(m[-][])=0; V(m[][-])=0; 
//若m[i][j]=-1, 则V(m[i][j])=0;
//(5)可以用递归来实现

// int pathCount(int (*m)[6], int i, int j) {
//     if (m[i][j] == -1) return 0;
//     if (i>0 && j>0) 
//         return pathCount(m,i-1,j)+pathCount(m,i,j-1);
//     else if (i==0 && j>0)
//         return pathCount(m,i,j-1);
//     else if (i>0 && j==0)
//         return pathCount(m,i-1,j);
//     else return 1;
// }

//19.4 总结
//一定要加强问题解决方法论的沉淀。
//更关注问题解决过程的步骤、方法或体系，不仅是结果

/*
int main(void) {
    // int arr[9]={1,3,5,7,9,2,4,6,1};
    // bool b1=isUnique(arr,9);
    // printf("b1=%d\n",b1);

    // int arr[9]={1,4,1,5,2,3,2,2,7};
    // int val=majorityElement(arr,9);
    // printf("val=%d\n", val);

    int m[3][6] = {{ 1, 1, 1, 1, 1, 1}, 
                    {1, 1,-1,-1, 1, 1}, 
                    {1, 1,-1, 1,-1, 1}};
    int cnt=pathCount(m,2,5);
    printf("cnt=%d\n", cnt);//2
    return 0;
}
*/

//19.5 练习题
//计算前缀表达式, 用栈的数据结构进行存储


//20 代码之外，技术面试中你应该具备哪些软素质？


//21 面试中如何建立全局观，快速完成优质的手写代码？



//22 课后练习题详解
//22.01 复杂度：如何衡量程序运行的效率？

//22.02 数据结构：将“昂贵”的时间复杂度转换成“廉价”的空间复杂度

//22.03 增删查：掌握数据处理的基本操作，以不变应万变
//把这个数组元素的顺序翻转过来
//大量的基于索引位置的查找动作

//22.04 如何完成线性表结构下的增删查？
//给定一个包含 n 个元素的链表，现在要求每 k 个节点一组进行翻转，打印翻转后的链表结果。
//利用 3 个指针，prv、cur、next，执行链表翻转，每得到 k 个翻转的结点就打印

//22.05 栈：后进先出的线性表，如何实现增删查？
//只要涉及翻转动作的题目，都是使用栈的强烈信号

//22.06 数组：如何实现基于索引的查找？

//22.07 哈希表：如何利用好高效率查找的“利器”？

//22.08 递归：如何利用递归求解汉诺塔问题？

//22.09 分治：如何利用分治法完成数据查找？
//在一个有序数组中，查找出第一个大于 9 的数字，假设一定存在。
//例如，arr = { -1, 3, 3, 7, 10, 14, 14 }；则返回 10。

//22.10 动态规划：如何通过最优子结构，完成复杂问题求解？

//22.11 定位问题才能更好地解决问题：开发前的复杂度分析与技术选型

//22.12 真题案例（一）：算法思维训练
//实时系统，必须在O(1)时间复杂度内返回结果。
//预先就计算完，并且保存在数组里。

//22.13 真题案例（二）：数据结构训练
//建立两个栈s1和s2。进栈顺序: s1先右后左，s2先左后右。两个栈交替出栈的结果是s形遍历

//22.14 真题案例（三）： 力扣真题训练
//slow 和 fast 并同时指向 header
//fast先走n步。接着，二者保持同样的速度，一起往前走。
//fast先到达终点，并指向NULL. slow就是倒数第n个结点

//22.15 真题案例（四）：大厂真题实战演练


// typedef struct SingleNode {
//     int val;
//     struct SingleNode* next;
// }SN;

/*
void printList(SN* p) {
    for (int i=0;i<3;++i) {
        if (p!=NULL) {
            printf("%d ",p->val);
            p=p->next;
        }
    }
}

void reverse_KList(SN* p, int k) {
    SN* cur=p;
    SN* prv=NULL;
    SN* next=NULL;
    int cnt=0;
    while (cur) {
        next=cur->next;
        cur->next=prv;
        prv=cur;
        cur=next;
        if ((++cnt)%k == 0) {
            printList(prv);
        }
    }
    printf("\n");
}

void printSTK(int* a, int n) {
    for (int i=n-1; i>=0; --i) {
        printf("%d ", a[i]);
    }
}

void reverse_Klist(SN* p, int k) {
    SN* cur=p;
    int stk[k];
    int top=-1,cnt=0;
    while (cur != NULL) {
        while (cur!=NULL && cnt<k) {
            stk[++top]=cur->val;
            cur=cur->next;
            ++cnt;
        }
        //printf("cnt=%d\n",cnt);//3
        printSTK(stk, cnt);
        cnt=0;
        top=-1;
    }
    printf("\n");
}
*/

/*
typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
}TN;

int* SnakeOrder(TN* p) {
    TN* stk1[8];
    TN* stk2[8];
    int t1=-1,t2=-1;
    int* a=(int*)malloc(sizeof(int)*8);
    a[0]=p->val;
    int k=0;
    stk1[++t1]=p;

    while (t1 == -1 || t2 == -1) {
        if (t1==-1 && t2==-1) break;
        if (t2 == -1) {
            while (t1 != -1) {
                if (stk1[t1]->right != NULL) {
                    a[++k]=stk1[t1]->right->val;
                    stk2[++t2]=stk1[t1]->right;
                }
                if (stk1[t1]->left != NULL) {
                    a[++k]=stk1[t1]->left->val;
                    stk2[++t2]=stk1[t1]->left;
                }
                --t1;
            }
        }
        else {
            while (t2 != -1) {
                if (stk2[t2]->left != NULL) {
                    a[++k]=stk2[t2]->left->val;
                    stk1[++t1]=stk2[t2]->left;
                }
                if (stk2[t2]->right != NULL) {
                    a[++k]=stk2[t2]->right->val;
                    stk1[++t1]=stk2[t2]->right;
                }
                --t2;
            }
        }
    }
    return a;
}

void printArr(int* a, int n) {
    printf("arr = ");
    for (int i=0;i<n;++i) {
        printf("%d ",a[i]);
    }
    printf("\n");
}
*/

/*
void printsList(SN* p) {
    printf("sList = ");
    SN* cur=p;
    while (cur != NULL) {
        printf("%d -> ", cur->val);
        cur=cur->next;
    }
    printf("NULL\n");
}

void removeEndK(SN* p, int k) {
    SN* fast=p;
    SN* slow=p;
    SN* prv=p;
    for (int i=0;i<k;++i) {
        fast=fast->next;
    }
    while (fast != NULL) {
        fast=fast->next;
        prv=slow;
        slow=slow->next;
    }
    prv->next=slow->next;
}

int main(void) {
    SN n1,n2,n3,n4,n5,n6,n7;
    n1.val=1; n1.next=&n2;
    n2.val=2; n2.next=&n3;
    n3.val=3; n3.next=&n4;
    n4.val=4; n4.next=&n5;
    n5.val=5; n5.next=&n6;
    n6.val=6; n6.next=&n7;
    n7.val=7;n7.next=NULL;
    // //reverse_KList(&n1,3);
    // reverse_Klist(&n1,3);

    // TN n1,n2,n3,n4,n5,n6,n7,n8;
    // n1.val=1; n1.left=&n2;  n1.right=&n3;
    // n2.val=2; n2.left=&n4;  n2.right=&n5;
    // n3.val=3; n3.left=NULL; n3.right=&n6;
    // n4.val=4; n4.left=NULL; n4.right=NULL;
    // n5.val=5; n5.left=NULL; n5.right=NULL;
    // n6.val=6; n6.left=&n7;  n6.right=&n8;
    // n7.val=7; n7.left=NULL; n7.right=NULL;
    // n8.val=8; n8.left=NULL; n8.right=NULL;
    // int* arr=SnakeOrder(&n1);
    // printArr(arr,8);

    removeEndK(&n1,3);
    printsList(&n1);

    return 0;
}
*/


//23 勤修内功，构建你的核心竞争力
//23.1 酥者，看似很硬，一碰即碎
//你取得成绩的天花板，取决于你对事情的认知
//必须对技术原理有充分的理解和认知
//23.1.1 勤修内功:
//(1) 勤，即次数多，可理解为是持续不断的意思。
//(2) 修，即炼，可理解为预习、学习、复习。
//(3) 内功，即认知，是你对这项技术的理解深度。
//23.1.2 外功: 技巧性的东西
//勤修内功: 不断温习技术原理，持续加强技术认知。

//23.2 勤修
//学而时习之，不亦说乎
//通过不断复习来加深对所学知识的理解
//经过多次学习，你对作者的态度可能会从崇拜转变为质疑，这个过程就是你的成长。

//23.3 内功
//重要的内功就是如何降低复杂度: 算法思维和数据结构
//有的能力则是慢功夫:
//(1) 对数据结构的理解能力
//(2) 算法能力
//(3) 技术选型的判断力
//这些都是经过长期积累、反复学习，才能有所收获。
//长期竞争力一定是来自的内功，也就是数据结构与算法这门学科的基本功。

//23.4 写在最后
//更加高效地掌握数据结构与算法知识，真正掌握程序开发、代码优化的方法论，完成从掌握理论知识到解决实际问题的转变。
//虽然复杂难懂，但想要学好也没那么困难。
//它有通用的解题思路和宏观层面的方法论，重点在于学以致用。
//只有不断地发现/提出/解决问题，才能真正将书本上的知识活学活用。
//输出是对掌握最好的检验


