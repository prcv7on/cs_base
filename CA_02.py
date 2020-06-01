#40 人生处处排行榜：认识排序算法
#40.1 什么是排序（Sorting）
#将一串数据按照某种特定的方式进行排列
#排序算法的输出是输入的一种排列或重组, 输出按照递增(递减)的顺序进行排列

#40.2 无处不在的排行榜
#40.2.1 排序算法的江湖地位
#基础算法是软件的核心，而查找和排序算法则是基础算法的核心！
#40.2.2 排序算法的分类
#比较排序, 非比较排序

#40.3 比较排序
#40.3.1 比较排序的定义
#比较排序Comparison Sorting: 通过比较操作来确定两个元素中哪个应放在前面
#数据之间根据特定原则进行比较，任意两个数据相比都会有>、==、<之一，再根据比较结果确定两者的相对位置。
#40.3.2 全序集
#传递性: a<=b,b<=c, 必有a<=c
#安全性: 任意a,b,只有a<=b和a>=b之一

#40.3.3 比较排序的局限
#全序集的模糊代数结构决定了，每次比较操作获得的信息有限。者导致比较排序性能上的根本限制
#最差情况下，任何一种比较排序的时间复杂度，至少是O(n*log(n))
#非比较排序,可能有O(n)的时间复杂度。在某些情况下，更有性能优势。
#40.3.4 比较排序的优势
#(1) 可以控制比较原则，因此可以对任何类型的数据进行排序
#(2) 更好第控制如何排序
#(3) 对数据进行比较这一点，也与现实当中的许多问题契合
#而且，非比较排序的使用限制比较多，适用面相对窄。比较排序算法成为排序的主流



#41 排序算法的基本操作：两两交换数组中元素
#41.1 查找 vs 排序
#41.1.1 比较查找与排序算法
#41.1.2 相同之处
# 都有“比大小”（比较）这个步骤
#(1) 比较排序原本就是按照元素比较的结果来决定相对位置
#(2) 查找也要通过比较才知道是否相等
#都是对序列的操作
#41.1.3 不同之处
#(1)查找算法: 只能读取数组中的元素值，结束后数组不变。
#(2)排序算法: 读写数组元素，改变原数组中元素相对位置。

#41.2 两两交换数组内的元素
# 一个排序算法的基础操作 --> 两两交换元素

#41.2.2 用“一只手”交换“鸡蛋”
#(1) 将元素A放到一个临时存储空间里
#(2) 把元素B放到原来元素A所在的位置
#(3) 把元素A放到原来元素B所在的位置
#条件、循环结构只是把有内在规律和分支选择的指令用一种简化、形式化的方式来描述。实际运行的指令，仍然是一条条从前到后执行

#41.2.3 swap()函数
# def swap(arr, i, j):
#     if (len(arr) < 2):
#         return
#     if (i < 0 or i >= len(arr) or j < 0 or j >= len(arr)):
#         return
#     if (i == j):
#         return
#     tmp = arr[i]
#     arr[i] = arr[j]
#     arr[j] = tmp
#     return

#41.2.4 没有返回值的swap()函数
#swap(arr, startPosition, minPosition)



#42 函数的参数和变量

#42.1 函数的参数和其值的变化
#42.1.1 两段代码
# #代码1
# def testScalarParam(a):
#     a = a * 2
#     return a
# x = 3
# y = testScalarParam(x)
# print("x=", x)
# print("y=", y)
# #代码2
# def testListParam(arr):
#     for i in range(0, len(arr)):
#         arr[i] = arr[i] * 2
#     return arr
# xArr = [1,2,3,4,5]
# yArr = testListParam(xArr)
# print("xArr=", xArr)
# print("yArr=", yArr)

#42.1.2 代码输出
#42.1.3 函数参数值得变化

#42.2 几个概念
#42.2.1 参数传递问题
#一个变量作为一个函数的参数，被“传递”进函数，在函数体内重新赋值，函数结束后，变量的值是否改变的问题
#42.2.2 传值 vs 传引用（*)
#(1)传值: 把参数的副本给到函数，函数对副本的修改不影响原参数
#(2)传引用: 把参数本身给到函数，函数对参数操作有影响原参数

#42.2.3 传对象 vs 传对象引用 --> Python 的函数参数传递
#Python中一切都是对象，分为可变（mutable）对象和不可变（immutable）对象
#可变对象在传递给函数后，可在函数内部修改，不可变对象则不行
#(1)可变对象: List,Dict,Set
#(2)不可变对象: int,float,bool,string,tuple
#Python 的参数传递
#要彻底搞清楚可变,不可变对象，以及传对象vs传对象引用的问题，要去学习Pytho 的执行模型（execution model

#42.3 煮()函数和混合煮()函数
#42.3.1 传对象 --> 传入函数体的参数，是一个不可变对象
#将对象拷贝一份，传到函数的时对象的副本，对副本的操作不影响原对象
#42.3.2 传对象引用 --> 参数是一个可变对象
#将对象自身传递给函数，函数内的操作会改变此对象
#42.3.3 函数参数问题的简化理解
#函数的参数的数据类型:
#(1)整型变量: 不影响原参数值
#(2)列表变量: 类别中元素值可能改变
# def testListParam(arr):
#     for i in range(0, len(arr)):
#         arr[i] = arr[i] * 2
#     return
# xArr = [1,2,3,4,5]
# print("Before function:", xArr)
# testListParam(xArr)
# print("After function:",xArr)
#程序里的几个列表变量，指向同一个列表对象 --> 这也就是为什么，上一章swap()没有返回值的原因



#43 超级简单的排序方法：选择排序
#43.1 扑克牌小游戏
#排序要解决的问题: 将一组无序的元素序列调整为有序的过程
#很多隐含的限制条件
# 1）能够保证的出正确结果；
# 2）过程中不接受异常；
# 3）要尽量节约空间和时间。

#43.2 基于直觉的排序算法
# 一个人类学实验
# 每次选出当前最小值

#43.3 选择排序（Selection Sort）
#43.3.1 算法原理
#一个迭代算法，每次迭代从待排序的元素中选择最小的，排到最后；如此循环，直到所有元素排完为止
#43.3.2 数据结构: 就用一个列表承载所有数据，排序过程就在这个列表中进行
#43.3.3 算法步骤
#找到当前最小待排数，将它与第k个位置的元素交换
#43.3.4 编程实现
# def selectionSort(arr):
#     # startPosition 表示本次迭代的起始位置下标，与前述步骤中的k相对应：startPosition == k - 1
#     for startPosition in range(0, len(arr)): 
#         minPosition = startPosition # minPosition用来记录本次迭代中最小数值所在位置下标
#         # 和其后所有位置上的数字比较，如果有哪个位置上的数字更小，则用该位置替代当前的minPosition
#         for i in range(startPosition+1, len(arr)): 
#             if (arr[i] < arr[minPosition]):
#                 minPosition = i
#         swap(arr, startPosition, minPosition) #经过一轮比较，当前的minPosition已经是当前待排序数字中的最小值，将它和本次迭代第一个位置上的数字交换
#     return
# #调用
# arr = [3,2,1,5,8,7,9,10,13]
# selectionSort(arr)
# print(arr)



#44 纸牌屋里喝可乐：起泡排序和插入排序
#44.1 起泡排序（Bubble Sort）
#44.1.1 算法原理
#(1) 起泡排序是一个迭代过程；
#(2) 每次迭代都将所有待排序元素从头至尾（或从尾到头）走访一遍；
#(3) 在每次走访过程中，比较相邻的元素，若两者相对顺序错误就交换，否则前进一步去比较下一对相邻元素
#(4) 迭代至没有再需要交换的元素为止。
#每次迭代中最小的元素会经由一次次地交换慢慢“浮”到数列的顶端
#44.1.2 算法步骤
#44.2 编程实现
# from utilities import swap
# def bubbleSort(arr):
#     for i in range(0, len(arr) - 1):
#         for j in range(len(arr) -1, i, -1):
#             if (arr[j] < arr[j - 1]):
#                 swap(arr, j, j-1)
#     return
# #调用
# arr = [3, 9, 4, 11, 7]
# bubbleSort(arr)
# print(arr)

# 算法优化
#若在某次（假设第n次）从尾到第n个元素的访问中，swap()没有发生，则说明数列已经正序，排序结束
# def bubbleSort(arr):
#     for i in range(0, len(arr) - 1):
#         swapped = False
#         for j in range(len(arr) -1, i, -1):
#             if (arr[j] < arr[j - 1]):
#                 swap(arr, j, j-1)
#                 swapped = True
#         if (not swapped):
#             return
#     return

#44.3 插入排序（Insertion Sort）
# 算法原理：又见扑克牌

#44.4 在数组中插入元素
# 算法步骤
#(1) 初始：将待数组中的首元素认为是排好序的有序序列；
#(2) 迭代：
#(2.1) 取出有序序列后的首元素为待排的新元素；
#(2.2) 在有序序列中从后向前扫描，如果有序序列中的某个元素大于新元素，将该元素移到下一位置；
#(2.3) 重复2.2直至，有序序列中的元素小于等于新元素为止；
#(2.4) 将新元素插入2.3中止的位置；
#(3) 反复迭代多轮，至数组中全部元素有序。
#(4) 编程实现

# def insertionSort(arr):
#     if (len(arr) == 1):  # 因为要从第一个元素之后的元素迭代，因此，如果整个序列长度为1，则直接返回
#         return
#     for i in range(1, len(arr)):
#         # 此处也是倒着访问list，不过不是从尾巴开始，而是从当前位置开始，也是两两交换，此处与bubbleSort颇有些相似
#         for j in range(i, 0, -1):
#             if arr[j] < arr[j - 1]:
#                 swap(arr, j, j - 1)
#             else:
#                 break
#     return
# #调用
# arr = [2,1,5,8,7,13]
# insertionSort(arr)
# print(arr)



#45 概括说说简单排序
#45.1 简单排序算法 --> 直观、易理解的排序算法的总和
#选择排序、起泡排序和插入排序

#45.2 时间复杂度
#45.2.1 排序的时间复杂度
#区分最好(有序)，最坏(倒序)和一般情况
#45.2.2 最坏时间复杂度: O(n^2)
#45.2.3 最好时间复杂度: 选择O(n^2),起泡和插入O(n)
#45.2.4 平均时间复杂度: O(n^2)

#45.3 空间复杂度: O(1)

#45.4 简单排序算法性能总结



#46 与二分查找共组双子星座：快速排序
#46.1 一个“笑话”

#46.2 快速排序Quick Sort --> 划分交换排序（Partition-Exchange Sort）
#46.2.1 算法原理
#(1) 将待排数列分割成两部分，其中一部分的所有数据比另一部分的所有数据都小；
#(2) 按此方法对分割出的两部分继续进行分割；如此迭代，直到整个数列有序为止。
#46.2.2 江湖地位: 所有排序算法中最重要,面试题
#(1) 简单直接，好理解，易实现
#(2) 多数情况下，平均复杂度不错
#(3) 在大部分计算机体系架构上高效实现
#46.2.3 算法步骤
#(1)对待排数列进行分区
# (1.1)选轴
# 从待排序数列中挑一个作为“轴”（pivot）。由于数列本身是无序,虽可选任意一个，方便起见选原数列的首个元素为轴。
# (1.2)分区
# 将待排数列中“轴”之外其他元素分别与“轴”比较，然后:
#     比“轴”小的元素都放在“轴”之前（左边），形成左区
#     比“轴”大的元素则放在“轴”之后（右边），形成右区
#     与“轴”相等元素,一律都放在左区
# (2)左区和右区成为两个新的待排数列，分别进行分区
# (3)重复1-2步，反复迭代，直到分区操作得出的左右区数列大小是0或1

#46.3 快速排序的时间复杂度
#46.3.1 时间复杂度的计算: O(nX), X轮分区
#46.3.2 最佳时间复杂度: 每次切成两半， O(log(n)) * O(n)==O(n*log(n))
#46.3.3 最差时间复杂度: n*O(n)==O(n^2)
#46.3.4 一般情况时间复杂度
#整体平均时间复杂度: 2*2log(n)*O(n)==O(n*4*log(n)) --> O(n*log(n))



#47 认识分治，并实现迭代式快速排序算法

#47.1 快速排序的空间复杂度
#分区函数的时间复杂度，和具体的实现方法有关。不同的实现方法，差别巨大。

#47.2 简单粗暴的分区函数 --> 为各子分区新开辟一块空间，要多少开多少

# def partition(arr):
#     if (len(arr) < 2): # 待分区数列长度为1或者0
#         return arr, None, None # 直接返回其本身作为左分区，再返回一个空的轴和一个空list作为右分区
#     leftPartition = []
#     rightPartition = []
#     pivot = arr[0] # 将当前数列中的第一个元素作为“轴”
#     for i in range(1, len(arr)):
#         if (arr[i] <= pivot):
#             leftPartition.append(arr[i]) # 小于等于轴的元素放到左分区
#         else:
#             rightPartition.append(arr[i])# 大于轴的元素放到右分区
#     return leftPartition, pivot, rightPartition # 顺序返回左分区,轴和右分区
# arr = [3,9,7,8,2,4,1,6,5,17]
# print(partition(arr))

#47.2.2 修改分区函数 --> 每次都要对整个输入列表分区
# 把输出修改一下，让原本存储在一个列表中的数字仍在这个列表里，顺序变了。同时告知分区后轴的位置
# def partition(arr):
#     if (len(arr) < 2):
#         return -1

#     leftPartition = []
#     rightPartition = []
#     pivot = arr[0] # 将当前数列中的第一个元素作为“轴”

#     for i in range(1, len(arr)):
#         if (arr[i] <= pivot):
#             leftPartition.append(arr[i]) # 小于等于轴的元素放到左分区
#         else:
#             rightPartition.append(arr[i])# 大于轴的元素放到右分区

#     llen = len(leftPartition)
#     arr[0:llen] = leftPartition[0:llen]
#     arr[llen] = pivot
#     arr[llen + 1: len(arr)] = rightPartition[0:len(rightPartition)]
#     return llen

# arr = [3,9,7,8,2,4,1,6,5,17]
# p = partition(arr)
# print("pivot index=", p)
# print('arr=',arr)

#47.2.3 只想对其中一段分区 --> 输入参数:low和high划分待分区区域,分别代表待分区间最左和最右元素的下标
#返回值: 此次轴在分区后，在列表中的下标
# def partition(arr, low, high):
#     if low >= high:
#         return -1

#     leftPartition = []
#     rightPartition = []
#     pivot = arr[low]
#     for i in range(low + 1, high + 1):
#         if (arr[i] <= pivot):
#             leftPartition.append(arr[i])
#         else:
#             rightPartition.append(arr[i])

#     llen = len(leftPartition)
#     rlen = len(rightPartition)

#     for i in range(0, llen):
#         arr[i + low] = leftPartition[i]
#     arr[low + llen] = pivot
#     for i in range(0, rlen):
#         arr[i + low + llen + 1] = rightPartition[i]
#     return low + llen

# arr = [3,9,7,8,2,4,1,6,5,17]
# p = partition(arr, 0, len(arr) - 1)
# print("pivot index=", p)
# print('arr=',arr)

#47.3 分治策略
#47.3.1 算法策略(解决问题的思路) --> 常用常见的，不过就是分治、贪心、动态规划等几种
#快速排序是一种分治算法。
#47.3.2 策略之一：分儿治之Divide and Conquer
# (1)Divide: 将要问题分解为若干小规模但类似原问题的子问题；一直迭代分下去，直到分出来的子问题可简单直接求解为止。
# (2)Conquer: 对子问题分别求解，然后再将这些子问题的解合并作为原问题的解

#47.4 快速排序实现
#47.4.1 分治算法
#(1) 分
# 分区：将待排数列分成左区、轴和右区；
# 对分出来的左区和右区再分别进行分区，持续迭代，直到分出来的子区长度为 1 或 0 为止。
#(2) 治
# 每次分区后，当次的“轴”元素都在数列中找到了它最终应位于的位置；
# 当分出来的分区长度为 1 时，整个子数列中只有一个元素，这个元素已经归于了正确位置，无须再分了。
#47.4.2 确定每一轮的待分区域
#把所有待分区间用一个二维列表维护,各行是长度为2的一维列表，存储区域的起始和中止元素下标（low和high）
# 每次迭代，都这样做：
# (1)沿着这个二维列表依次取出一行 --> 一个待分区域
# (2)处理当前分区：
#    若区域长度<=1，则直接略过，说明本区域已有序，无须再分
#    若区域长度>1，则给此待分区域分区
# (3)若存在新分出来的左区和右区，再添加到二维列表的尾部去
# 如此一来，只要前面的分区还能分新区，二维列表就不会空。反之，如果它空了，则说明所有区域都已经完成了“治”，有序结果已经产生

#47.4.3 直观联想 --> 这个二维列表就好像是一堆文件
#47.4.4 实现代码
#里面用到了循环, 迭代式快速排序, 区别与另一种快速排序实现方法,递归式快速排序
# def qSortIteration(arr, low, high):
#     if low >= high:
#         return
#     regions = [[low, high]]
#     i = 0
#     while i < len(regions):
#         low = regions[i][0]
#         high = regions[i][1]
#         p = partition(arr, low, high)
#         if p != -1:
#             regions.append([low, p-1])
#             regions.append([p+1, high])
#         i += 1
#     return
# arr = [2,1,5,8,7,13,26,4,39,0]
# qSortIteration(arr, 0, len(arr) -1)
# print('arr=',arr)



#48 像“贪吃蛇”一样“吃掉”自己——递归
#48.1 递归（Recursion）
#自食其尾的蛇揭示了递归的根本：递归是一个过程，在此过程中有一个步骤援引了整个过程本身

#48.2 有效递归和无效递归
# 无效递归 --> 每次自我援引，没有减小问题规模，问题自始至终都是那么大，所以永远也解决不了
# 有效递归 --> 能够解决问题的递归




#48.3 数学中的递归
#48.3.1 分形（Fractal）--> 数学对自然界中存在的一类事物形态的抽象
#通俗定义: 一个几何形状，可分成多个部分，且各部分都是整体缩小后的形状
#分形是一种典型的递归结构。
#48.3.2 斐波那契数列（Fibonacci sequence）
#F(0)=0,F(1)=1
#F(n)=F(n-1)+F(n-2) ,n>=2
#48.3.3 数学归纳法
#递归与数学归纳法本质是相同的



#49 构造递归函数，顺便说说动态规划
#49.1 计算机领域的递归
#49.1.1 递归和分治
#算法策略：分治。分治策略常用数学归纳法来验证，其计算多数通过求解递归关系式来判定 --> 很多分治策略的算法，采用递归的方式实现
# 分治策略、算法和递归的关系如下
#(1) 分治策略是一种算法策略——很多种算法指导思想的统称
#(2) 某一种分治算法: 一种采用了分治策略的算法
#(3) 递归方法: 某些分治算法的一种常用实现方式
#49.1.2 递归函数 --> 自己调用自己的函数
#所谓“自己调用自己”，就是在某函数的函数体中，有一个步骤是对它自身的调用
#49.1.3 最简单的递归函数 --> 是一个无效递归，因为它每一次的问题规模未变。
# def recursionTest():
#     recursionTest()
#     return
#49.1.4 Python 限制递归深度
#理论上递归是无限的，调用深度任意.但是，计算机的软硬件资源有限，Python系统对调用深度有专门限制
# import sys
# print(sys.getrecursionlimit()) #1000

#49.1.5 限制运行次数的递归函数
# def recursionTest(depth):
#     print("recursion depth=", depth)
#     if (depth < 997):
#         recursionTest(depth + 1)
#     return
#49.1.6 运行环境和 IDE 的影响
#递归深度限制: 与当前运行的Python程序相关的所有程序的调用深度，而不仅对recursionTest()函数本身的额调用

#49.2 递归实现斐波那契数计算
# 定义
# 根据定义实现算法
# def Fibonacci(n):
#     if n < 0:
#         print("Incorrect input")
#     elif n == 0: 
#         return 0
#     elif n == 1: 
#         return 1
#     else:
#         return Fibonacci(n-1) + Fibonacci(n-2)
# print(Fibonacci(10))

#49.3 动态规划Dynamic Programming
#49.3.1 动态规划策略
#基本思想：要解决一个问题，先将其分成多个子问题，再根据子问题的解得出原问题的解——看起来和分治很像
#动态规划所解决问题的子问题大都有很多重叠,一个子问题可能会被多次求解
#对于各子问题，仅求解一次，然后将其解存储，下次可直接查找获得。

#49.3.2 动态规划的实现
#分治和动态规划都是算法策略，它们是并列的概念。
#动态规划所解决的问题是分治所解决问题的一个子集。此子集用动态规划来解决，比标准分治节省时间
#可以笼统地认为：动态规划 = 分治 + 重用
#动态规划的具体实现可理解为: 递归+存储后查找

#49.3.3 斐波那契数的动态规划实现
#函数参数除了n之外，还有一个名为results的列表，其中已经存储了一些数对应的斐波那契数    
# def FibonacciDP(n, results): 
#     if n < 0:
#         print("Incorrect input")
#     # 如果能够查到之前已经计算出的斐波那契数，就直接返回     
#     elif results[n] is not None: 
#         return results[n]
#     elif n == 0: 
#         return 0
#     elif n == 1: 
#         return 1
#     else:
#         # 计算出新的斐波那契数后，除了直接返回，还要将其存储到results里面，以备后续查找
#         results[n] = FibonacciDP(n-1, results) + FibonacciDP(n-2, results)                 
#     return results[n]

# def FibonacciDPWrap(n):
#         results = []
#         results[0: n + 1] = [None] * (n + 1)
#         return FibonacciDP(n, results)

# print(FibonacciDPWrap(10))

#49.3.4 动态规划与递归
#动态规划和分治（只有递归，没有重用）策略的两种斐波那契计数函数有什么区别？
#从用户的角度老看，最主要区别在于速度。
#动态规划存储了以前的结果



#50 实现递归式快速排序算法
#50.1 递归式快速排序
#50.1.1 快速排序原理 --> 可分为“分”、“治”两步：
# (1)分 
# (1.1)分区：将待排数列分成左区、轴和右区 
# (1.2)对分出来的左区和右区再分别进行分区，持续迭代 --> 援引整个算法本身——这正是递归适合处理
# (2)治：当分出来的分区长度为1或0时，无须再分，至此，本区域的分区迭代停止
#50.1.2 从原理到实现
#50.1.3 递归式快排的编程实现
# 三个参数：arr，low 和 high：
# arr: 自始至终存储所有数字的列表
# low和high: 列表中两个单元的下标，分别指向待排区域的起始坐标
# 如此设置，就可在递归过程中限制递归的作用域，并使得待解决的问题越来越小，直到待排区域长度为1或0（low >= high）为止。

# def qSortRecursion(arr, low, high):
#     if low >= high:
#         return
#     p = partition(arr, low, high)
#     qSortRecursion(arr, low, p - 1)
#     qSortRecursion(arr, p + 1, high)
#     return
# arr = [7, 9, 6, 8, 10, 3, 2, 1, 4, 5]
# qSortRecursion(arr, 0, len(arr) - 1)
# print(arr)

#50.2 递归式快排 vs 迭代式快排
#50.2.1 时间复杂度
#时间复杂度一样,但迭代式快排整体上略快。因为递归的内部实现使用了堆栈。
#50.2.2 空间复杂度
#都是取决于分区函数， 只有分区函数才需要额外缓存空间。

#50.3 分区函数
#50.3.1 丑陋的实现
#需要的额外存储空间和整个待分区域一样大，时间复杂度O(n)
# def partition(arr, low, high):
#     if low >= high:
#         return -1

#     leftPartition = []
#     rightPartition = []
#     pivot = arr[low]

#     for i in range(low + 1, high + 1):
#         if (arr[i] <= pivot):
#             leftPartition.append(arr[i])
#         else:
#             rightPartition.append(arr[i])

#     llen = len(leftPartition)
#     rlen = len(rightPartition)

#     for i in range(0, llen):
#         arr[i + low] = leftPartition[i]
#     arr[low + llen] = pivot
#     for i in range(0, rlen):
#         arr[i + low + llen + 1] = rightPartition[i]

#     return low + llen

#50.3.2 优化分区函数
#(1)改进时间复杂度
#快排的分区函数，因为可能重置待排区域中的任何一个元素，因此至少各元素要扫描一遍 --> 时间复杂度>=O(n)
#(2)改进空间复杂度
#要移动列表内的元素，最少需要一个缓存空间 --> 空间复杂度O(1)
#(3)额外缓存空间为 1 的快排分区函数

# def partitionV2(arr, low, high):
#     if low >= high:
#         return -1

#     pi = low    
#     li = low + 1
#     ri = high
#     while ri >= li:
#         if arr[li] > arr[pi]:
#             swap(arr, ri, li)
#             ri -= 1
#         else:
#             li += 1
#     pi = li - 1
#     swap(arr, low, pi)

#     return pi

# arr：一个用来承载所有待排数字的列表；
# low：待排区间的起始下标；
# high：待排区间的终止下标。
# pi：分区完成后轴所在位置的下标



#51 解读算法源代码
#51.1 待解读源代码

#51.2 源代码解读方法

#51.3 “人肉计算机”法
# 推演源码
# “人肉运行”

#51.4 分区函数工作原理

#51.5 打印解读法
# 打印变量中间结果
# 打印分区函数中间变量
#对于分区函数，主要关心 pi，ri，li 和 arr 在运行过程中的变化

# def partitionV2(arr, low, high):
#     if low >= high:
#         return -1
# pi = low
# li = low + 1
# ri = high
# print("original list=", arr)

# while ri >= li:
#     print("\n[in loop] -- pi=", pi, "li=", li, "ri=", ri)
#     if arr[li] > arr[pi]:
#         swap(arr, ri, li)
#         print("\nswapped list=", arr)
#         ri -= 1
#     else:
#         li += 1

# print ("\n[out of loop] -- arr=", arr)
# print("[out of loop] -- pi=", pi, "li=", li, "ri=", ri)
# pi = li - 1
# swap(arr, low, pi)
# print("\n[final] arr=", arr)
# print("[final] pi=", pi)
# return pi

# #调用
# arr = [19,11,27,8]
# partitionV2Print(arr, 0, len(arr) - 1)

#51.6 阅读源代码，了解算法细节
#这种从看似简单的代码里了解到其复杂，再从复杂回归简单，让一团乱麻变成清晰可描述逻辑的过程，是对思维的训练。
#也是学习算法最有意义的地方



#52 测试算法实现
#52.1 测试软件/程序
#之所以要验证程序功能，不是为了验证算法原理，而是要验证具体实现的正确性。
#最简单直接的方式就是构造多个测试数据，“灌进去”运行

#52.2 测试排序算法
#52.2.1 构造数据集: 随机数列, 正序数列, 倒序数列

# import random    
# def generateTestData(start, end, len = None):
#     arrRandom = None
#     if len is not None:
#         arrRandom = [random.randint(start, end) for x in range(0, len)]
#     arrSeq = [x for x in range(start, end + 1)]
#     arrReverse = [ end + 1 - x for x in range(start, end + 1)]
#     return arrRandom, arrSeq, arrReverse

# # 调用
# arrRandom, arrSeq, arrReverse = generateTestData(1, 10, 5)
# print('arrRandom=',arrRandom)
# print('arrSeq=',arrSeq)
# print('arrReverse=',arrReverse)

# #52.2.2 安装 pip 和用 pip 安装模块
# #52.2.3 用生成数据测试快速排序
# #新的递归式快排算法:
# def qSortRecursionV2(arr, low, high):
#     if low >= high:
#         return
#     p = partitionV2(arr, low, high) #调用新的分区函数
#     qSortRecursionV2(arr, low, p - 1)
#     qSortRecursionV2(arr, p + 1, high)
#     return

# #用生成的数据来测试新的递归式快排算法:
# _, _, arrReverse = generateTestData(1, 1000)
# qSortRecursionV2(arrReverse, 0, len(arrReverse) - 1)
# print("sorted=", arrReverse)

#52.2.4 分区函数带来的差异
#仅改变了分区函数，就导致同样的递归限制下，一个可处理997个数字的倒序数列，另一个只能处理1496个
#partition() 每次都是让一个元素“归位”，partitionV2() 却可能多移动一些数据

#52.2.5 收获总结
#就算是相同的算法，策略，实现细节不同，也会影响程序效果
#递归这种“取巧”的策略，虽实现省事，却有额外限制，反而是迭代算法实现，虽实现更麻烦，却适用情况更广


#53 期末总结：我们从本课学到了什么？
#53.1 一门讲授知识的课程
#53.2 课程内容
#53.3 规划下一步学习



#54 如何自学算法
#54.1 自学三要素

#54.2 学习目标
#54.2.1 学习材料和内容
#自学最难的一点: 制定学习框架——如果要使某个领域的知识框架有效且高效，需要对相应领域有相当深入的理解
#最简单的方法就是：找一本经典的算法书籍，作为自学的底本。

#54.2.2 学习目的和深度 --> 真正的问题在于：要学到什么深度！
# 建议是：对于核心经典算法
# 至少达到level4（实现）——能够用编程语言编写出无逻辑错误的算法实现的地步。
# 最好达到level5（应用）——能够在解决实际问题中应用算法，也就是可以很自然的应对原算法的变形、变换，以及针对现实问题的抽象。
#应该从最简单的开始，由浅到深，各个击破，吃透一个再看下一个，不要贪多嚼不烂。

#54.3 学习方法
#54.3.1 通过阅读代码学习算法 --> 阅读别人写的算法代码是必须的！
# 练习与实践
#54.3.2 “读”是“学”，“练”是“习”。无论什么知识，学而实习之才是王道。算法也是如此。
# (1)从重写他人的实现开始, 读了别人代码之后将过程抽象成步骤，自己“咀嚼”、“消化”后，重新实现一遍。
# (2)有了算法“感觉”（sense）之后，先不看别人的代码，对照自然语言描述的原理或步骤实现程序
# 再和经典实现对比，发现不同，总结差距。如此反复，是实打实的提高之道
# (3)经典算法之外，还可通过做一些练习题来考察、练习逻辑思维和算法运用能力

#54.3.3 说说刷题
#题的解法和实现是要自己想、自己写的！不是去背人家的结果。
# 能够想出解法的基础，是对数据结构和基础经典算法的掌握。
# 先把经典算法学会、学通——扎好算法的“马步”，最基本的拳招、步法练到精熟；然后再去套招（刷题）。如此练习，才可能有实战能力



#55 遇到读不懂的代码应该怎么办？
#55.1 如何阅读代码
#55.1.1 读一个函数/代码块
#55.1.2 基于代码结构理解代码功能
# 阅读代码，需要先构造出代码的结构，然后基于结构理解其功能
# 具体分3步：
#(1) 从程序入口点开始，推导出其中函数的层层调用过程；
#(2) 从最小粒度的函数（调用其他自定义函数越少的函数粒度越小）开始，搞清楚各函数的具体功能和时空复杂度；
#(3) 层层递进，逐步推导出全局的完整过程和整体时空复杂度。
#55.1.3 边看边学编程语言

#55.2 代码阅读实例：以一种确保数据不会溢出的方式来计算 100 的阶乘
#55.2.1 完整源代码
#55.2.2 找到入口点
#Python 不像编译型语言那样先将程序编译成二进制再运行，而是动态逐行解释运行，所以它可以没有显示指示的入口点。
#明确指出一个入口点，Python 解释器就会直接跳到入口点开始运行:
# if __name__ == "__main__": 
# 当前模块被直接运行时，模块名为 _main_
#当 factorial.py 被直接运行时，本行以下代码块被运行。当它被其他程序作为模块导入时，此代码块不被运行。

#55.2.3 函数间的调用关系
#55.2.4 搞清最小粒度函数的功能
#55.2.5 主函数：factorial()
#55.2.6 验证对程序的理解

# def convertIntToList(n):
#     nArr = []
#     while n >= 1:
#         nArr.append(n % 10)
#         n = int(n / 10)
#     return nArr

# def times(aArr, bArr):
#     result = []
#     resultLen = max(len(aArr), len(bArr)) * 2
#     result[0: resultLen] = [0] * resultLen

#     for j in range(0, len(bArr)):
#         carry = 0
#         for i in range(0, len(aArr)):
#             offset = i
#             sum = result[offset + j] + aArr[i] * bArr[j] + carry
#             unitSum = sum % 10
#             if (sum < 10):
#                 carry = 0
#             else:
#                 carry = int((sum - unitSum) / 10)
#             result[offset + j] = unitSum
#         if carry > 0:
#             result[offset + j + 1] += carry

#     for i in range(len(result) -1, -1, -1):
#         if int(result[i]) != 0:
#             break
#         else:
#             result.pop(i)

#     return result        

# def factorial(n):
#     fResult = []
#     fResult[0:n] = [0] * n
#     fResult[0] = 1
#     for i in range(2, n + 1):
#         factor = convertIntToList(i)
#         fResult = times(fResult, factor)
#     factorial = ''.join(str(x) for x in reversed(fResult))

#     return factorial

# if __name__ == "__main__":
#     print(factorial(5))



#56 用编程解决实际问题
#56.1 用编程解决实际问题

#56.2 例子 1：如果你有 1000 万，躺着花够花多少年？

#56.3 例子2：天使魔鬼过河问题






















































































































































































































































































