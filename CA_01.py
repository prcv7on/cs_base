#01 为什么我们要学习编程？

#1.1 编程的核心是什么？
# 从语言特征（词汇、语法等）的角度来讲，最复杂的编程语言远比最简单的自然语言简单得多。
# 编程的核心在于, 通过各种各样的算法去实现具体的业务逻辑，把繁杂的过程抽象化、可计算化。
# 从纯粹软件的角度讲，甚至可以说：算法 + 数据 == 计算机程序。

#1.2 经得起时间考验的通识技能
# 用数值表达现实事物，用运算描述任务目标，再通过算法处理数据找到达到目标的最优化路径——这个思维的形成过程，远比学会模型本身更为难得。
# 经过这种思考训练内化出的思维能力，也是学习者可以相伴终身的助力。

#1.3 本专栏讲了些什么？
# 在大学计算机系课程中，本课程所讲述的内容被拆分在几门课里：
# 程序设计语言（Python）
# 数据结构
# 计算机组成原理和体系结构


#02 又回到最初的起点：软件和程序
#2.1 软件是什么
#软件可以简单的被认为是一组程序，这组程序相互配合，通过接受输入、产生输出，来为我们每一个人解决问题或完成任务。
#2.2 程序又是什么？
#软件就像一条完整的流水线，能够把原材料加工成最终产品，一个个程序则像其中的一道道工序，这些工序的联合协作，完成了整个生产过程。


#03 安静的程序，淘气的程序和编写程序
#3.1 静态程序 --- 程序的源代码
#程序的源代码: 用编程语言编写出来的程序的逻辑，是静态文本，暂且称为 安静的程序，一般被存储为以特定字符串为后缀的文件。
#3.2 让程序跑起来 --- 运行程序
#涉及到运行环境，不同的编程语言的具体需求不一样，这里又涉及到编译执行、解释执行等概念。
#3.3 跑动的程序 --- 运行时程序
# 程序的源代码是一些静态的文字和符号，以文本文件形式存储在计算机的存储部件上。
# 在程序的运行过程中，那些动态的、临时性存在于计算机核心部件中，并通过外围设备和用户进行交互的指令和数据才是真正的程序！
#在下面的课程中我们用“程序”来指代静态的源代码，而用“运行时程序”指代动态的程序。

#3.4 编程的步骤
#编程就是从无到有创造出一个可以正常运行的程序的过程。
# Step1 编写：把程序写出来。
# Step2 编译：编译是将编程语言描述的、人类可读的程序源代码（source code， 或简称code）转化为二进制代码（binary code）的过程。
#这一步不一定进行，关键在于编程语言是编译还是解释执行
# Step3 测试: 也就是试运行程序。
# Step4 问题修复: 如果上一步发现了问题，也就是程序员们常挂在嘴上的Bug，当然不能放任不管，需要将问题修复才能正式投入使用。

#3.5 把程序写出来
#虽然编程实际上指的是一个从空白到有一个程序正确运行的全过程，但很多时候“编程”会被用来简化地指 Step-1：编写程序。

#3.6 程序编辑器
#虽然不同编程语言写出来的程序后缀名不同，不过说到底，这些都是文本文件

#3.7 集成开发环境
#IDE 除了提供编辑器，还提供编译运行以及debug环境. IDE 会提示有没有语法错误等


#04 算法究竟是个啥东西？
#4.1 广义算法
#广义而言，做一件事情/解决一个问题的方法，就是算法。
# 所有的算法都体现为一个过程：
#(1) 这个过程由若干工序（或称为步骤）组成；
#(2) 这些步骤按照一定的流程来加工某些原料；
#(3) 最终产生某种结果。
#关心的是：那些能够为我们完成任务或者解决问题的方法。换言之，讨论的算法一定有明确的目标，最终的产出也是为了达到目标
#总结一下，算法的几个重点要素: 目标 流程 原料 产出
#流程中的步骤必须是有限的。这一点也叫做算法的有限性。

#4.2 狭义的算法
#4.2.1 计算机算法的任何步骤都需要：
#(1) 有确切的定义 —— 确定性。
#(2) 能够被分解为计算机可执行的基本操作，并且每个操作都能可以在有限时间内完成 ——可行性。
#4.2.2 综合起来，计算机算法就是（划重点）：
#(1) 一个有限的、通过计算机指令实现的可执行操作序列；
#(2) 这个序列接受输入；
#(3) 对输入数据进行有限步骤的处理；
#(4) 最终产生确定的输出，用以实现算法的目标。

# 从外面看起来，总不过是输入问题->运作->输出答案而已。
# 从内里看，算法 = 数据结构 + 控制流程

#4.3 数据结构 --> 数据的组织方式
#数据的组织方式 --> 许多具体的数值按照一定的相对位置和相互关系组合起来。
#4.4 控制流程 --> 程序运行的步骤历程
#控制流程和数据结构有关系。换言之，同样目标的算法，数据结构不同，会造成运行、求值的步骤顺序的不同。


#05 程序、编程和算法之间到底有什么三角关系？
#5.1 算法与程序
# 数据结构是数据的组织形式。描述算法时，只需要知道将来要处理的数据是如何组织.
# 基于数据的组织形式，定义一个运算/操作的历程，这就是算法的实现。算法实现的结果，就是程序。
#算法是静态程序的内容，而算法 + 数据 = 动态程序。

#5.2 算法与编程 --> 所谓编程，就是实现算法的过程！

#5.3 对编程的误解 --> 编程语言等同于自然语言

#5.4 学习编程的目的 
# 从微观角度说, 让数据发生变化就需要运算，而运算的过程就是算法。
# 从宏观角度说，算法是对解决某类问题/完成某类任务的方法的描述。

#5.5 经典算法 --> 算法是编程的核心！
# 逻辑层面的基础问题，在大多数应用领域都会用到。应用层繁多的花样，最终对应的都是共同的基础问题。

#5.6 经典算法著作


#06 学编程到底有啥用？
#6.1 学习算法和编程的用处
# 算法的两大要素：
#(1) 控制流程描绘事物发生发展的过程；
#(2) 数据结构对事物组织的形式高度抽象。
# 这都是逻辑思维的最基础

#6.2 对应不同层次的讲解方法
#真的到现实中去运用，将理论知识转化为实践经验，就不是仅仅依靠书本可以做到的了。必须要实践！

#6.3 算法驱动编程
#沿着Level-1到Level-4的顺序，在介绍一个算法时，先讲它的作用，优缺点，原理（怎么能够达到目标功效的），然后再通过画流程图、写程序代码的方式展现算法的全部细节。

#6.4 算法的难点：从原理到实现
#就算是仅仅为了把算法学清楚，也有必要写代码。
#难点在于：如何从概括性的原理，转换为与具体数据结构结合可以一步步实施并直接对应为计算机指令的控制流程。
#这一难点，正是本课的核心所在！
#不仅（1）要讲抽象原理，还要（2）将其拆解成数据结构+控制流程，（3）详细推演整个运行过程的细节，再（4）将整个流程写成代码，然后（5）在运行环境中执行。


#07 万事的抽象：控制流程

#7.1 顺序 --> 一个接着一个顺序进行

#7.2 条件（分支）
#有些时候，一件事的发展并不完全确定，可能要在某个步骤上，根据某种具体的条件进行判断，要么这样，要么那样。

#7.3 条件（分支）结构
#根据某条件成立与否, 将后续结果分为不同分支的流程结构，也称为分支（Branch）结构。

#7.4 循环（迭代）--> 循环的次数必须是有限的
#不断重复的流程结构就叫做循环（Loop）结构，也叫做迭代（Iteration）结构
# (1) do…while循环: 特点是无论如何先执行一次循环体，然后再判断条件，看接下来是否重复执行。
# (2) for循环: 特点是重复执行固定次数。
#几种循环，虽然细节上有所不同，但其实是完全可以相互转化的，


#08 用最最简单的结构表达复杂的过程：控制结构的排列和嵌套
#8.1 什么是流程图？
#表示算法或工作流的框图。它用不同类型的框代表不同种类的步骤，每两个步骤之间则以箭头连接。
#8.2 极简版流程图符号表
#控制流程的3种基本结构: 顺序结构，条件结构，循环结构。
#8.3 最简单的流程图 --> 只有一个事件（或者操作），才能够独立存在构成流程图。
#8.4 流程图的粒度与嵌套
#8.5 条件结构和循环结构的嵌入
#8.6 粒度均衡的流程图 --> 描述同一个算法/过程的流程图也并非唯一


#09 万物的抽象：数据结构
#9.1 数字化 --> 将信息转换成数字格式的过程
#严格来说，任何把模拟源转换为任意类型数字格式的过程，都可以叫数字化
#9.2 数字化生存 --> 预测未来的最好办法就是创造未来
#9.3 数据化
#计算机的分层技术已经解决了将实际存储的信息形式和显示信息的形式分离.
#在计算机中存储的信息，统一称之为数据，不再用“数字”一词。故而，数字化，又可称为“数据化”
#将事物、概念数据化，是今天所有的这一切得以实现的最基础。
#9.4 数据的组织
#虽有差异但根本原则十分接近的组织数据的方法。
#9.5 数据结构 --> 数据的组织方式
#将数据结构想象成一个容器, “容器”本身都差不多，都是计算机内部的一块存储空间，而造成数据结构之间差距的，则是内部数据的相互关联方式和对其进行操作的限制。
#目标都是共同的：让被组织起来的数据可以以一种高效的方式被访问和修改。


#10 最简单的数据结构开始：数组和链表
#关注的是逻辑层面的数据组织方式和其上操作的运行方式。

#10.1 数据结构的定义
#10.1.1 数组
#数组的下标是从0开始计数(C/C++,Python)
#10.1.2 链表
#是一种线性表，通常由一连串节点组成，各节点包含数据和1或2个用来指向上个/或下个节点的位置的链接（links）
#(1)非循环链表 --> 由若干元素组成的有限序列
#存在一个唯一没有前驱的（头）元素；存在一个唯一的没有后继的（尾）元素；此外，每一个元素均有一个直接前驱和一个直接后继元素
#单向非循环链表： 各节点包含两个域：一个信息域和一个连接域，前者用于承载数据元素；后者内则保存着一个链接，这个链接指向列表中的下一个节点，而尾节点的链接则指向一个空值。
#双向非循环链表： 各节点有一个信息域和两个连接域。有两个链接：一个指向前一个节点（头节点的这个链接指向空值）；而另一个指向后一个节点（尾节点的这个链接指向空值）。
#(2)循环链表 --> 头节点和尾节点连在一起，这种方式在单向和双向链表中皆可实现
#(3)更复杂的链表 --> 还可以很复杂，比如多向链表，每个节点可包括两个以上的连接域，这些连接可以将链表中的元素按任意顺序组合。
#最简单的最常用。多数情况下，用的都是单向非循环链表。

#10.2 直观理解数据结构

#10.3 数组 & 单向链表 --> 序列结构
#10.3.1 直观一维数组
#10.3.2 直观单向链表
#10.3.3 相同之处
#(1) 都有一些固定的“位置”，其中各数据元素占据一个独立的位置
#(2) 元素都是从前到后一个挨着一个，排成一队。不一定有序。
#10.3.4 不同之处
#数组和链表最基本的区别，是静态和动态的区别。
#10.3.5 访问（读）和更新（写）
#数组适合频繁访问
#链表适合频繁增加，删除
#数据结构的设计并非天马行空虚构出来的，而是要结合计算机硬件的限制考虑。


#11 计算机是咋运行的：冯诺依曼结构
#数组、链表这些结构限制条件的根本原因来自于 计算机硬件的体系结构。

#11.1 电子计算机的前世今生
#图灵机（Turing machine）的抽象计算模型,从理论上证明了通用计算的可行. 成为了现代电子计算机的计算模型。
#该论文标志着二进制电子电路设计和逻辑门应用的开始，为人们制造模拟图灵机的物理机器提供了基础元器件。

#11.2 冯·诺依曼结构
# (1)计算机硬件由运算器、控制器、存储器、输入设备和输出设备五大部分组成，其中运算器和控制器组成了中心处理单元（CPU）；
# (2)指令——指令是单个的CPU操作，一款CPU能够进行哪些操作是在设计时就确定了的，和数据都以二进制编码；
# (3)存储器中既存储数据又存储指令。
#将存储设备与处理单元（运算器、控制器）分开，依此结构设计出的计算机又称: 存储程序型计算机。
#将运算操作转化成一串程序指令，又将程序指令当成一种特别类型的数据和其他数据一起存储在存储器中。这样，一台存储程序型计算机可像变更数据一样改变程序

#11.3 存储空间的地址和内容
#11.3.1 存储空间 --> 存储器在逻辑上是一个空间
#存储空间被分为若干存储单元，各存储单元又分为两个部分：
#(1) 地址：各存储单元对应的序号，标识内容在存储空间中位置的编码
#(2) 内容：存储单元中存放的信息
#地址,内容均以二进制的形式表示
#存储空间线性编址，按地址访问，存储在其中的每一条指令或数据，都是空间里存放的内容，它们都拥有自己的地址。

#11.3.2 类比仓库
#存储空间类比成仓库，里面有许多货架，相当于许多存储单元，各货架有自己的编号（存储单元地址），货架上的货物（存储单元的内容）
#总结：
#(1) 货架上的“货物”，可能是指令，数据；
#(2) “拿货”读操作，“放置”写操作；
#(3) 指令和数据可被读、被写、被修改；变更指令或数据，只要修改存储空间内的内容，无须变更硬件设置。

#11.4 一条指令是怎么被执行的？
#由运算器和控制器组成的CPU，是计算机的“执行机构”。CPU负责顺序执行程序的每一条指令
#(1)取指令（Instruction Fetch，IF）：根据指令地址，从存储器里取出相应指令；
#(2)指令解码（Instruction Decode，ID）：分析指令的操作类型（读/写操作，输入/输出操作，或者算术逻辑运算操作等）和获取操作数的方法；
#(3)执行（Execute，EX）：完成指令功能（例如控制运算器对操作数进行运算），并控制数据在CPU、存储器和输入/输出设备之间流动；
#(4)写回（Writeback，WB）：将运算结果写入CPU或存储器。
#一个完整的指令执行过程所需要的时间，称作一个指令周期。

#11.5 冯诺依曼结构的直观解释
#冯诺依曼结构的计算机就像一家餐厅

#11.6 冯诺依曼结构的应用
#(1) 红框里的CPU——运算器、控制器；
#(2) 黄框里的内存条——存储器；
#(3) 绿框里的键盘接口和显卡——输入设备和输出设备。

#11.7 冯·诺依曼结构的瓶颈
#11.7.1 导致瓶颈的原因
# 现实当中不同计算机部件的客观性能：
#(1) CPU的处理速度特别快
#(2) CPU与存储器之间的数据传输速率与存储器的容量相比起来相当小
#表现：CPU的高效工作与低速的数据传输之间不平衡，CPU不得不在数据输入输出时闲置，严重影响整体效率
#11.7.2 通过直观例子理解瓶颈
#11.7.3 缓解瓶颈的办法
#(1) 在CPU与存储器之间加入高速缓存
#(2) 采用分支预测（branch prediction）算法
#(3) 通过编程方式的改变（现代的函数式编程以及面向对象编程），在宏观上减少将大量数值从存储器搬入搬出的操作；

#11.8 哈佛结构 --> 将指令和数据区别对待，分开存储
#因为指令和数据分别放在不同的存储器中，可同时读取两者 --> 效率更高
#高效的代价很大: --> 限制了哈佛结构的推广
#(1) 哈佛结构比冯诺依曼结构要复杂得多；
#(2) 在动态加载程序时，需先将静态程序代码作为数据读入数据存储器，再将其传输到指令存储器中去. 增加了存储传输负担
# 日常使用的计算机，在整体体系结构上基本上都采用冯诺依曼结构。
# 许多CPU内核，会采取类哈佛结构的设计，在CPU内的缓存中区分指令缓存和数据缓存--> 两种结构的一种折中。


#12 预留给货物的固定货架：内存中的数组
#12.1 存储空间
#无论指令还是数据，物理上都存储在存储器里面，逻辑上都在存储空间之中。

#12.2 数组：一块连续的存储空间
#数组创建时分配到一块存储空间，空间大小和两个因素有关：
#数组中每个元素的大小,由其数据类型决定
#数组的长度

#12.3 分配存储空间
#创建一个数组的时候，需要指定它的长度。

#12.4 数组的下标
# 存储单元的绝对地址 --> 地址空间中各存储单元都有对应的固定不变的地址
# 数组元素的相对位置标号 --> 各元素相对数组头部的偏差值，这些相对位置，在数组创建时就已确定
# 数组、数组的存储和元素下标 --> 从0开始，逐个递增1

#12.5 数组中的元素
# 数组元素
# 数组元素值 a[i]

#12.6 数组的特性
#12.6.1 固定存储空间
# 数组占据的存储空间大小固定，不能改变
# 占据的存储空间是专用的，不能被其他信息占据
# 占据的存储空间是连续的，中间不能间隔其他信息
# 数组中的各元素可用数组名和下标直接访问
#12.6.2 优点 --> 要访问某元素，知道下标，就能一步到位，直接访问对应元素
#12.6.3 缺点
#(1)太占地: 一开始就要申请所有要用的存储空间，就算装不满，也不许存入其他信息。空置空间很可惜
#(2)修改困难: 新元素只能加在尾部，要插入到中间位置，就要移动一些元素
#12.6.4 连续存储惹的祸
#这些限制，都是因为数组是连续的一块存储空间，且各元素由下标标识
#读取任务，数组有得天独厚的优势


#13 见缝插针地摆放货物：内存中的链表
#13.1 链表 --> 按需分配. 有货物要存储，才临时申请正好放这些货物的货架，随时加减
# 单向链表: 由若干链接在一起的节点（node）构成，各节点包含两部分：本节点的数据，下个节点的起始地址
# 单向循环链表： 尾节点指向头节点的起始位置
# 双向循环链表：每个节点包括三个部分：本节点的数据，前，后节点的起始地址

#13.2 插入节点
#链表中节点的逻辑顺序和实际存放的物理顺序无关。
#13.3 删除节点
#(1) 找到被删节点的前序，将前序的后序改成被删节点的后序
#(2) 把被删节点直接删除（将其原本占据的存储空间释放出来）。

#13.4 特性各异的链表与数组
#13.4.1 实现方式导致特征差异 --> 数据结构表现出来的差异，是由其在存储系统中的实现方式导致的
# 数据结构的发展
#高级语言对数据的管理能力越来越强，出现多种大小可变、硬件无关的数据类型。这使得结合数组和链表两者的优点
#13.4.2 结合数组与链表的优点
# 数组: 每个元素可以通过下标直接访问
# 链表: 长度不受限制,可灵活地插入删除数据
#List(列表): Python 语言定义了一种融合数组和链表的数据结构
#长度随时可变，既可在结尾处添加新元素，也可在序列中间插入或删除元素


#14 复杂些的数据结构：树和图
#14.1 抽象数据模型
#抽象数据模型(ADT): 计算机科学中数据结构的数学模型或者语义。
#方便用来简化描述算法，也便于初学者理解复杂数据结构。

#14.2 图
# 图论中的图
# 有向图和无向图: 只要包含一条单向边，就是有向图。图中所有边都无向，才能叫无向图。
# 图的相关概念和算法
#环的定义很直接：在图中的一条由边组成的路径，从一个顶点出发可以回到它自身
# 柯尼斯堡七桥问题
# 欧拉与图论: 图的遍历问题本身就是一个大问题，其中包含若干子问题，

#14.3 树
#14.3.1 数学中的树
#树Tree是一种无向图，其中任意两个顶点间存在唯一一条路径。或者，只要没有回路的连通图就是树。
#数学上的树: 是图的一个子集，是一种特殊的图。
#14.3.2 计算机领域的树
#和图论中的树并不完全相同，计算机领域的树是可有方向（也可没有），而且作为数据结构的树一般都是有根树（rooted tree）
#树的高度: 有根树的层数
#有根树被构建出来以后，各节点的孩子的数量确定了。n叉树。

#14.3.3 二叉树 --> 各节点最多可有两个孩子的有根树
#二叉树的分支具有左右次序，不能随意颠倒。
#这些限制的加持，使得二叉树具备独特性质，支持许多高效算法。
#二叉树本身还分为多种细化类型，每一种都有一些特殊的性质。


#15 树和图的现实意义、区别与联系
#15.1 二叉树树的遍历
#15.1.1 树的遍历和图的遍历
#树的遍历: 按照某种规则，不重复地访问树的所有节点的过程。
#因为树是图的一个子集，因此，树的遍历，也属于图遍历的子集。图遍历的原则主要有深度优先和广度优先两种。

#15.1.2 二叉树的深度优先遍历算法
#在实际应用中，对二叉树而言，深度优先用得更多。
#都是从根节点开始“往下“走，往深层次走，所以叫做深度优先遍历。
#先、中、后序遍历实际上是先根序，中根序和后根序遍历。
# 但无论那种遍历，都要：
#(1) 把一棵树拆成左子树、右子树和根三个部分；
#(2) 再将左右子树分别作为两棵树划分左右子树和根，如此层层深入下去；
#(3) 直到一棵子树只有一个节点为止。

#15.1.3 中序遍历: 左子树->根->右子树
#15.1.4 先序遍历: 根->左子树->右子树
#15.1.5 后序遍历: 左子树->右子树->根
#15.1.6 二叉树的广度优先遍历算法 --> 按层次遍历
#先访问离根节点最近的节点
#从根节点开始，每一层从左到右，把当前层都遍历完再进入下一层，每层都从最左侧节点开始
#关于树和二叉树的操作还有多种，比如：构建、查找、旋转等等。每个都有相应的一种或多种算法，也都很重要，不过遍历是所有算法中的最基础。

#15.2 树和图的现实意义 --> 在现实当中，很多事物的抽象结果，就是树或者图
# 图的抽象
# 树的抽象

#15.3 图 vs 树
#树为图的真子集
#(1)树中不同节点间的连接有方向: 都是从根开始，向叶子蔓延
#(2)树中没有环。

#15.4 树相对于图更加严谨
#相对于图，树的限制更多，因此树形结构相对于典型的图（非树的那些图），更加严整、严谨。


#16 从最简单的算法开始学：顺序查找
#16.1 查找算法（Search Algorithm）
#16.1.1 找东西: 找到这个东西，确定是否存在这个东西，确定其位置
#16.1.2 找数据: 我们的重点是查找过程和操作，而不是数据本身
#16.1.3 查找算法的要素
#输入数据分成两类: 待查数集合, 目标数
#查找算法目的: 确定待查数集合中目标数的存在性及位置
#输出数据: 目标数在待查集合中的位置
#查找算法的过程:
#(1) 遍历待查数集合
#(2) 遍历过程中，各元素，则将依次和目标数比较，一致，则记录该元素位置
#查找算法最主要的两个操作：遍历集合，比较个体
#待查数集合的数据结构，决定遍历方式


#16.2 顺序查找(线性查找) --> 无序查找算法的一种
#16.2.1 原理
#适合线性数据结构，如数组和链表。
#基本原理: 从待查数列的一端开始，依次比较各元素数值与目标数，相等则查找成功；若遍历结束仍未找到，则失败。

#16.2.2 数据结构: 用数组存放待查数集合
#16.2.3 控制流程: 循环结构


#17 为啥有的算法好？有的算法坏？
#17.1 性能指标
#最主要的是两个：时间复杂度和空间复杂度。

#17.2 时间复杂度
#17.2.1 运算速度的表达
#时间复杂度f(n): 自变量是问题的规模,输入数据的数量;因变量是算法运行时间.
#定义的算法性能，与具体的程序执行脱节，仅讨论理论上的时间消耗。算法中基本操作的个数(步数)
#17.2.2 顺序查找的步数: 真正关心的是运算量的量级，而非精确数字
#17.2.3 大O记号: 描述了一个函数在其参数达到某一特定值或无穷大时的极限行为。体现了函数的增长率
#17.2.4 常见算法的时间复杂度
#大O记号作用: 聚焦主要因素，忽略次要因素。
#常用的算法的时间复杂度都是O(nlog(n))或nlog(n)量级

#17.3 空间复杂度
#在绝大多数情况下，待处理数据所需存储空间 >> 非数据部分
#关心的实际上是消耗的额外存储空间: 除了输入数据之外，还需要消耗的存储空间。
#既非程序体控制流程占据，也非输入数据占据。而是，算法过程中临时性存储数据的缓存空间。

#空间复杂度也用大O记号表达
#衡量一个算法性能，主要是时间复杂度


#18 跟你的计算机聊会儿天：编程语言
#18.1 语言、自然语言和编程语言的定义及性质
#(1) 语言是信息的载体。
#语言的性质: 媒介性、规范性和抽象性
#(2) 自然语言还具备: 演进性,冗余多义性,一词（语）多义、一义多词（语）
#(3) 编程语言: 与自然语言相对，是人造的语言. 人为设计出语素、语法、语义和语用的符号系统；也是人-机通讯的工具，专门用来表达计算机程序。
#继承了自然语言的演进性，但却尽量避免冗余多义性。

#18.2 编程语言的分类标准
#18.3 从低级语言到高级语言
#18.3.1 低级语言
#机器码（Machine Code）, 汇编语言（Assembly Language）
#汇编语言和机器码基本是一一对应, 直接提供操作码和地址码，是面向机器的编程语言
#在某些处理器简单存储容量小的设备（主要是特种嵌入式设备）上，汇编语言有着不可替代的优势
#18.3.2 高级语言 --> 独立于机器的编程语言
#FORTRAN I 是第一个高级语言, 通过编译机制彻底脱离了机器

#18.4 编译（Complie）和解释（Interpret）
#18.4.1 编译执行
#需要先把源代码写好，提交给编译器(一个软件)，由编译器将其编译成目标代码(机器码)
#执行程序时，是目标代码，而不是源代码，被加载到存储器，进行运行
#18.4.2 解释执行: 对源程序的翻译与执行由解释器(一个软件)一次性完成，不生成可存储的目标代码。
#18.4.3 编译 vs 解释
#要相信，凡事代价和收益都是平衡的。
#目标码需要编译生成，而且和硬件绑定，但却也经过了针对当前硬件环境的优化，而且在执行过程中控制权在用户程序自己。
#解释执行，跳过了编译那步,但运行时的控制权归解释器所有. 很难通过改进程序来优化其效率

#18.4.4 Java & Python
#两者通常被当作是解释型语言, 因为它们各有一个虚机起到和解释器很类似的作用
#其实Java或者Python程序也需要编译，只是没有直接编译成机器码，而是一种特殊的字节码，然后在虚拟机上用解释方式执行字节码。
#严格来讲，Java和Python在计算方式上是混合型的。


#19 各种花式编程语言大放送
# 编程范型programming paradigms
#19.1 定义和分类
#编程范型: 程序组织和实现计算的模式，一种编程的风格
#19.1.1命令式imperative：程序一句句地告诉机器该去干什么
#(1)过程式procedural: 把一组组指令封装成过程，程序的组织形式是：算法过程 + 数据结构。
#(2)面向对象object-oriented: 把数据和针对数据的操作封装成对象，程序是互相通信的对象的集合。
#19.1.2宣言式declarative: 程序告诉计算机它想要什么样的结果，而不是获得结果的过程
#函数式functional：把运算过程封装成函数，程序是各种函数的组合。
#逻辑式logic：通过设置答案须匹配的规则来解决问题，程序是规则的组合

#19.2 范型的演进与重合
#Python同时支持: 过程式,函数式,面向对象

#19.3 直观感受不同的编程语言
#(1) 汇编语言：低级语言，直接书写操作码和地址码。
#(2) Fortran于1957年诞生在IBM，成了世界上第一款被正式采用的高级语言。
# 为了满足数值计算的需求，Fortran的语法形式接近数学公式的自然描述，在计算机里具有很高的执行效率；很多专用的大型数值运算计算机针对Fortran做了优化
# 至今仍然广泛地应用于并行计算和高性能计算领域
#(3) Lisp开创了很多先驱性的概念，包括：树结构、自动存储器管理、动态类型、条件表达式、递归等等
# Lisp后来则常被作为“函数式语言”提起。
#(4) PASACAL语言设计初衷在于推广结构化编程和数据结构的使用。虽然在软件开发的实践中并不出彩，但因为其结构的清晰和严谨，因此作为“教学语言”著称于世。
#(5) C是一款高效、灵活、功能丰富、表达力强的开发语言，广泛应用于软件开发工作中。
#(6) Erlang支持函数式编程，以及并发和分布式程序设计机制，还提供了脚本运行的方式。总体上，Erlang被认为是一种典型的函数式编程语言，主要应用在通讯领域。f
#特点可以用四个字概括：极其别扭。
#(7) Java语言对于面向对象范型的强支持，垃圾自动回收机制的易用性，以及通过虚拟机运行的跨平台特征，使得它在互联网时代大放异彩，逐渐成为几乎是最重要的网络编程语言。
#大部分的Web服务和应用后端，都是用Java开发的。
#最初被认为是一种改良的Lisp，又具备了一些其它语言的有点，例如动态类型和垃圾回收机制等。
#支持多种（几乎所有））编程范型，还拥有一个巨大的支持库。目前被大量应用于Web开发，数据处理和人工智能领域。
#(8) Scratch其实并不是一种语言，而是一个编程平台，发布于2006年，旨在让小白用户不需学习编程语言语法就能编写程序。


#20 一条可爱的小蟒蛇：Python 语言
#20.1 多姿多彩的编程语言
#20.2 主流编程语言
#20.3 为什么选Python
#20.4 Python的特性
#(1) 它是一种解释型语言；
#(2) 对过程式、面向对象、函数式编程都有支持；
#(3) 支持动态类型，不需要专门声明变量类型，而可以直接赋值；
#(4) 提供垃圾自动回收机制，能够自动管理内存；
#(5) 它的解释器几乎可以在所有的操作系统中运行，这使得Python具备了跨平台属性
#20.4.2 设计哲学是：优雅、明确、简单 --> 强调代码的可读性和语法简洁
#20.4.3 设计者希望：
#(1) 能用尽量少的代码表达想法，而无须顾忌底层实现
#(2) 同样功能，不同的人实现起来最好代码尽量一致
#可把重点放在程序的逻辑上，不必一边担心怎么实现功能，一边还要考虑这些数据放在内存哪里，有没有操作会互相影响等
#20.4.4 还有一个很重要的特征：可扩展性
# 语言核心只包含最基本的特性和功能. 大量复杂的针对性功能, 都由其标准支持库来实现。
# 提供丰富的API和工具，能用C、C++等语言编写扩展模块，再通过API与Python集成。正是如此，Python又被成为“胶水语言”
#20.4.5 
#最大的缺点: 慢！它的解释执行机制、动态数据类型设定、可扩展性等设计都造成它运行效率低下

#20.5 Python的编辑、运行环境
# 顺序安装
# 创建项目
# 开始编写第一个程序


#21 让 Python 小蟒蛇动起来
#21.1 你好世界 --> 一则测试环境，二则也是给初学者一个最基础的代码示例。
#21.2 运行Python程序的几种方式
#(1) 在IDE中直接运行
#优势: 非常直接，可在IDE中逐步Debug，十分方便
#缺点：在IDE中运行程序，相当于在原程序外面又“包”了一层。这样，Python程序受运行环境和IDE的影响，运行效率有所下降，甚至因为IDE的bug导致原本正确程序出问题
#(2) 命令行运行Python文件: python 文件的相对或绝对路径
# 所有的输出都在命令行界面直接显示，适合需要反复运行的Python脚本
#(3) 运行Python命令
#只要出现了">>>"，就说明已经进入了运行环境. 每输入一个Python语句，对应的输出就会直接显示在下一行。
#用来运行一两个临时语句；验证某条语句语法的正确性；或者查看某个支持库是否被安装等。

#21.3 Python的print()函数
#内置函数: 在Python最核心的运行环境中已被实现了功能，无须安装任何额外的支持库，就可拿来就用的函数
#python大部分功能都靠支持库来实现，真正的内置函数还不到70个。

#21.4 功能强大的print()函数
#21.4.1 字符串拼接
# 用“ + ”连缀字符串，被相加的字符串首尾相接。
# 用“ ，”分割多个字符串，不过字符串之间多一个空格
# 用 "%s" 符号将一些小字符串嵌入到一个大字符串中。
#print()函数打印字符串的时候，被打印字符串需要被引号引起来。反斜杠（\）转义符，用于打印引号
#21.4.2 打印数字
#直接在print()函数的括号内放置算式
#21.4.3 打印数字与字符串的混合
#数字嵌入字符串，在嵌入位置可以用“%s”标识，也可以用“%d”标识。
#(1) 用%s标识，则数字完全被当作字符串处理；
#(2) 用%d标识，则对应数字的整数部分会被作为字符串输出，而小数部分则根本不会输出。
#21.4.4 数字与字符串的拼接
#(1)用“+”: 需要将数字也转化为字符串 -- 具体方法是用另一个Python内置函数：str()；
#(2)用“，”: 数字可直接作为一个分项，无需事先转化为字符串
#21.4.5 记住print()函数的用法


#22 彰显地位的缩进和作为限制的类型

#22.1 Python的缩进（indent）
#22.1.1 结构特征
#Python使用空格缩进(indent)划分代码块,等于放弃显性划分，而是采用半隐性的形式，容易混淆代码块的起止
#22.1.2 代码块(block/code block)
#是一个词法结构，里包含一行或多行代码（程序语句）
#是程序的一种基础结构，代码块中的各条语句按顺序依次执行,它们之间是平等的。

#22.1.3 代码块的起止
#Python直接用缩进标识代码块。增加缩进表示代码块的开始，减少缩进表示代码块的结束
#缩进成为Python语法的一部分。违反缩进规则的程序根本不能被解释器通过，也就无法执行
#Python官方的规定: 每级的缩进都必须使用4个空格来表示
#Python的一行代码结尾时没有任何标点符号

#22.1.4 代码块的嵌套 --> 控制流程的条件和循环结构就是通过代码块的嵌套来实现的

#22.2 数据值和数据类型
#22.2.1 数据的抽象和具象含义
#前者是统称，泛指所有的具体数据。抽象的数据是计算机加工处理的对象。
#具体的一条数据，则表现为数据值。值是对事物形态、特征的表达和度量，包含的内容十分广泛。

#22.3 数据类型
#本课的范围内，只关心整型、浮点型、字符型、布尔型、字符串，以及整型数组、浮点型数组、字符数组和字符串数组

#22.4 数据类型的作用
#编程语言依据不同类型对一类数据值进行一致的操作

#22.5 针对数据类型的数据存储分配
#22.5.1 了解数据占位的重要性
#不同语言，不同操作系统，不同硬件体系还不一样


#23 数字为什么长这样儿：说说进位制
#23.1 进位制(简称进制)
#首先会设定一组有限的数字符号
#进位制的基数: 可以使用的数字符号的个数
#数字符号的运用规则:
#(1) 每个数字符号表示一个特定的数目
#(2) 一个数值可以由多个数字符号组成
#(3) 组成同一个数值的数字符号之间依据各自的相对位置而拥有不同的权重
#(4) 数字符号所组成数值等于各个数字符号与它自己位权乘积的总和

#23.2 十进制和二进制
#23.3 二进制与十进制的转换
#十进制转二进制：“除以2取余，逆序排列”（除二取余法）
#二进制转十进制：“按权展开求和”

#23.4 其他进制

#23.5 童话中的进制问题
#n进制最直观的特点就是：满n进位。

#23.6 为什么1进制不存在？ --> 根本连有和无都区分不了


#24 货物不能乱堆放：数据的占位和溢出
#24.1 溢出
#24.1.1 限定位数的数值表达
#在位数不受限制的情况下，利用进位制，我们可以使用有限种数字符号来表示所有的数值。

#24.1.2 计算机中的溢出问题
#溢出: 放不下非要硬放，于是出现错误，把最高位“挤没了”
#编程语言给某一特定类型的数据值分配的存储空间大小是固定

#24.1.3 二进制数的溢出

#24.2 Python的整型
#24.2.1 Python2 --> 长整型的界限也就是整型的界限 8bytes
#24.2.2 Python3 --> 整型值变得没有界限（unbounded) ,即整型是一种任意精度(arbitrary precision)数据类型
#24.2.3 从整型数据看Python语言的特点
#不同的编程语言运行在同一台计算机上，Python3可以不必关心整型溢出的问题
# Python3的运行环境（解释器）做了额外的处理，避免了使用固定长度字节来存储整型变量。
# 负担的功能多了，效率自然也要降低。写程序方便了，程序的运行速度就会下降
#多·快·好·省不可能同时存在。


#25 迈出看似简单的一步：字面量、常量、变量和赋值
#25.1 字面量 --> 名字和取值是合为一体
#直接量: 它是某些数据的名字，同时也是这些数据本身
#字面量的表示（名字）就是它的值，并且直接暴露它的数据类型
#(1) Boolean: True False
#(2) Special: None
#(3) Number: 整型、实型数值
#(4) String: 字符或者字符串
#(5) Collections: 列表、元组、字典和集合

#25.2 标识符 --> 常量和变量的名字和取值是相互分离
#标识符(identifier): 选用一个具有特定含义的词或符号，规定该词或符号代表某一个数据
#这个名字是程序员给这个数据取的，叫什么都可以 --> 最好采用能够表达该数据意义的单词
#25.3.1 Python则对下划线有专门规定
#(1) 以单下划线开头（_foo）的代表不能直接访问的类属性，需通过类提供的接口进行访问，不能用“from xxx import *”导入；
#(2) 以双下划线开头的（__foo）代表类的私有成员
#(3) 以双下划线开头和结尾的（__ foo）代表Python里特殊方法专用的标识，如__init() 代表类的构造函数。

#25.3 数据和它的标识符（名字）
#(1) 编写程序时，数据的具体取值未知。
#(2) 某一个标识符对应的值，在程序运行的过程中不断变化
#(3) 这个数值有着特殊的含义，在一次运行中不变或不同运行中可能改变。一则表明含义，二则也适合做修改。

#25.4 变量和赋值
#25.4.1 变量
#变量是一个有类型，但没有固定值的标识符，它可以代表该类型内的任何值。
# 它的值可以随时改变，改变变量值的过程，就叫做赋值
#25.4.2 直观看变量名、变量值和赋值
# 变量名、变量值与存储单元地址和存储内容一一对应：
#(1) 变量名(标识符): 就是存储单元地址(货架编号)的文字化表达
#(2) 变量值: 存储在该单元里面的内容(放在货架上的货物)
#(3) 赋值就是把货物放到货架上的过程！
#25.4.3 赋值符号
#25.4.4 Python的赋值语句 --> 被赋值变量 = 赋值变量(字面量/常量)
#25.4.5 变量的多次赋值
#只要经过新的一轮赋值，就会变成新值,原值被覆盖。

#25.5 常量 --> 值不能被更新的变量
#25.5.1 “不变的变量”: 把数据值和一个标识符绑定，一旦这种关系被建立，就不再被修改。
#25.5.2 常量的定义
# 常量也是由标识符和数据值组成
# 被常量修饰符修饰过的标识符，一般都要求被立刻赋值，而且一旦赋值后，就无法再更新其数据值。
# 在语法上，Python不存在常量


#26 Python 中的类型系统和“数组”
#26.1 编程语言的类型系统
#程序中的每一个变量都有它的数据类型。
#在大多数编程语言里，一个变量是什么数据类型，是需要被声明的。
#C以及其他很多语言都类似，当变量首次出现时，都要显性地写出它的数据类型

#26.2 无须声明变量类型的Python
#通过第一次赋值，使得被赋值变量在被赋予一个数据值的同时，拥有了和赋值变量、常量或字面量一致的数据类型。

#26.3 类型系统的特征
#类型检查: 变量被赋值和被声明的类型是否一致。防止代码中的无意义操作。
#检查必须做，具体检查的时机，各语言自由选择:
#26.3.1 静态类型 vs 动态类型
#(1) 静态类型语言: 各变量都由程序员显示指定类型，编译时类型检查
#(2) 动态类型语言: 仅有数据值有固定类型，变量一般不指明类型,运行时类型检查
#26.3.2 强类型 vs 弱类型
#不同类型的数据之间是否存在兼容关系，决定了数据类型的“强度”
#(1) 弱类型语言: 变量可隐式地转换成其它数据类型。
#(2) 强类型语言: 变量有严格的类型，要转换成其他类型，必须要显式转换。
#C就是一种弱类型语言
#Python则是强类型语言

#26.4 Python中的数组
#26.4.1 逻辑上的数组
#Python的序列类型变量: 由一组元素组成，各元素都有一个位置信息（索引/下标）
#序列类型都可进行索引，切片，加，乘，检查成员等操作
#Python的列表类型(是Python内置的6个序列类型之一) --> 表示逻辑上的数据结构——数组
#26.4.2 列表和元素
# 数组的最后一个元素: arr[-1] 或 arr[len(arr)-1]
#26.4.3 列表的赋值和赋值
# 一个列表量和通常的变量一样，有一个名字（标识符）表示它。
#(1) 可以直接给它赋值
#(2) 两个列表之间可以互相赋值
#(3) 列表中的某一个元素也可以被单独赋值
# arr = [1,5,8,19,3,2,14,6,8,22,44,95,78]
# arr_new = arr #arr_new成了arr的别名
# arr_new = arr.copy() #生成一个当前值和arr一摸一样的新List
# arr[0] = -3


#27 从流程图到程序：用 Python 编写顺序查找算法
#27.1 关键字与控制结构
#27.1.1 关键字(保留字/Reserved Word)
#在语言的格式说明里被预先定义，通常具有特殊的语法意义 --> 用来识别代码块、函数和流程控制结构
#27.1.2 Python3的33个关键字
# import keyword
# print(keyword.kwlist)
#分类：
# 布尔类型字面量： True False
# 表示“不存在”的特殊型字面量： None
# 关于流程控制： if elif else for while break continue
# 关于逻辑判断： and or not
# 关于函数： def return yield lambda
# 关于类型判断： is
# 关于面向对象编程： class pass
# 关于代码块控制： with … as
# 关于List操作： del in
# 关于变量作用域： global nonlocal
# 关于异常处理： assert except finally raise try
# 关于导入模块： from import

#27.2 Python中的三种控制结构
#27.2.1 顺序结构
#27.2.2 条件结构: if和else,elif
#if语句的结尾是一个冒号,必须有.  else后面只有一个冒号
#27.2.3 循环结构: while或者for.   break或continue(前者终止循环跳到循环之外，后者跳过此轮循环，继续下一轮循环)
#所有用for构造的循环都可用while重写。
#遇到break要注意，循环体中一旦遇到break语句，直接跳出，而且不会再回头执行while中的条件判断。
#27.2.4 不同类型结构的嵌套
#(1) 每个被嵌入到其他结构中的结构都是一个完整的结构体。
# 可以是简化的,但不能是残缺的
#(2) 把每个被嵌入的结构都当作一个语句来对待。

#27.3 用Python实现顺序查找算法
# 代码实现
# 流程图和代码的对照


#28 不该忘记的算法：二分查找

#28.1 for循环和while循环
#28.1.1 等价的两个循环

# for n in range(1,1001):
#     print(n)

# n=1
# while (n < 1001):
#     print(n)
#     n = n + 1

#28.1.2 Python中的循环关键字：for
# for iterative_var in sequence:
#    statements(s)

#28.1.3 range() 函数 --> for最常用的是用整型itervative_var和range()相结合
# for i in range(1, 11):
#     print(i)

#28.1.4 基于for循环的游戏解法
# tn = 165
# found = False
# for i in range(1,1001):
#     if i == tn:
#         print("secrete number is ", i)
#         found = True
#         break
# if not found:
#     print("failed")

#28.1.5 for循环 vs while循环
#(1) 所有能用for表达的循环，都可以用while表达。
#(2) 所有能够用while表达的循环，不一定都能用for表达.如果在循环体内部加上复杂的判断，也可让for和while做到等价

#28.2 从“挨着找”到“跳着找”
# 必须要“跳”
# 确定“跳”的方向
# 确定“跳”的距离


#29 二分查找：从原理到形式化描述
#29.1 二分查找原理: 在有序数列中查找某一特定元素
#每次将待查区域平分成两份， 每次循环要查找的区域都只有上一次循环的一半。
# 最初的待查数列和目标数由用户定义
# 查找过程是一个迭代（循环）过程
#     待查数列不为空时进入循环，否则查找失败
#     每次循环从待查数列的中心元素开始
#         中心元素正好等于目标数，则查找成功
#         目标数大于或者小于中心元素，则在数列大于或者小于中心元素的那一半成为新的待查数列

# 结构化的自然语言描述——流程图
#在编写经典算法代码之前，先画出清晰的流程图
#控制流程的精髓: 用最简单、最少量的固定基础结构去组合复杂的状况
#惟其如此，才具备易检查，不易错的特性，也才有在数学层面被严格证明的可能。

#29.2 形式化描述第一步——变量和赋值
#29.2.1 待查数列和目标数: 初始化arr和tn
#29.2.2 限定查找区域: low和high来界定每次循环的查找区域
#29.2.3 获得查找区域的中心元素值
# 内置函数int((low + high)/2) --> 下取整
#如果low和high都是很大很大的整数,可能出现溢出
#改为: m= int((high – low)/2) + low --> 中心元素的值arr[m]


#30 二分查找的编程实现
#30.1 流程控制
#30.1.1 比较查找区域中心元素和目标数: arr[m] == tn
#30.1.2 调整查找区域
#30.1.3 两重嵌套的条件结构: arr[m] < tn
#30.1.4 界定下一轮的查找区域
# low = m + 1   # high不变就不用重新赋值了。
# high = m - 1 # low不变就不用重新赋值了。

#30.1.5 确定查找区域是否为空
# 查找区域里还剩下2个元素，中心元素是前面那个
# 区域里只剩下1个元素了，它自己就是中心元素
#看low和high的关系，low <= high，则查找区域存在，否则不存在

#30.1.6 确定查找失败
#查找区域都不存在了，还没找到和tn相等的元素，则查找失败

#30.2 二分查找形式化的流程图
#30.3 二分查找算法代码

# arr = [3, 5, 9, 7, 12, 15, 18, 32, 66, 78, 94, 103, 269] # 可以随便改
# tn = 5 # 可以随便改，arr里有没有都可以
# low = 0
# high = len(arr) -1
# while(low <= high):
#     m = int((high - low)/2) + low
#     if (arr[m] == tn):
#         print("Succeeded! The target index is: ", m)
#         break
#     else:
#         if (arr[m] < tn):
#             low = m + 1
#         else:
#             high = m - 1
# if (low > high):
#     print("Search failed.")

#30.4 二分(折半)查找的时间复杂度: O(log(n))

#30.5 二分查找的空间复杂度
#算法所占用的额外空间与待查找数列的长度无关:O(1)


#31 用 Python 小蟒蛇编写一个小游戏
#31.1 猜数游戏与二分查找

# arr = list(range(1, 1001)) # 生成一个List，里面顺序存储着1-1000这一千个元素
# tn = 635  # 可以随便改
# low = 0
# high = len(arr) - 1
# while (low <= high):
#     m = int((high - low) / 2) + low
#     if (arr[m] == tn):
#         # 把打印出目标数所在的位置下标改成直接打印出目标数
#         print("Succeeded! The target number is: ", arr[m]) 
#         break
#     else:
#         if (arr[m] < tn):
#             low = m + 1
#         else:
#             high = m - 1
# if (low > high):
#     print("Search failed.")

#31.2 编写猜数游戏攻击者辅助程序
#31.2.1 由输入输出控制的二分查找
# 1）每次计算出中间数后，将其打印出来，并询问与猜测数的大小关系；
# 2）读取用户输入，以确定当前猜测数和目标数的大小关系。
#让用户用输入1，2或者3来代替“猜中了”，“太小了”，和“太大了”！
#31.2.2 加入变量inputNum记录输入次数，输入只允许出错三次，超过3次直接退出

# low = 1
# high = 1000
# loopNum = 0 #记录循环轮数
# while low <= high:

#     m = int((high - low) / 2) + low
#     print("My guess is", m)

#     # userInput是循环条件中被判断的变量，因此需要在循环之前先有个值，否则循环会出错。
#     userInput = ""
#     inputNum = 0

#     while userInput != '1' and userInput != '2' \
#           and userInput != '3' and inputNum < 4:
#         if inputNum == 3:
#             print("You input too many invalid options. Game over!")
#             exit(0)
#         print("\t\t 1) Bingo! %s is the secret number! \n\
#          2) %s < the secret number.\n\
#          3) %s > the secret number." % (m, m, m))
#         userInput = input("Your option:")
#         userInput = userInput.strip()
#         inputNum += 1

#     loopNum += 1

#     if userInput == '1':
#         print("Succeeded! The secret number is %s.\n\
#         It took %s round to locate the secret number. \n" % (m, loopNum))
#         break
#     else:
#         if userInput == '2':
#             low = m + 1
#         else:
#             high = m - 1

# if low > high:
#     print("Failed！")


#32 要解决 bug
# 打印变量中间值

#33 和 bug 的斗智斗勇
#33.1 bug 的产生原因
# 实现错误: 具体写成代码时，出错。
# 设计错误: 对于程序要处理的问题、要执行的任务理解不够，导致程序的业务逻辑不严密或与实际不相符.

#33.2 避免 bug 危害的方法
#33.2.1 代码层（静态）--> 代码评审Code Review
#对于静态程序的阅读和逻辑推演，来判断代码对于目标功能的实现程度并争取发现 bug
#33.2.2 运行层（动态）--> 软件测试Software Test
#实际运行代码，并提供各种的输入，验证输出是否符合预期来确认程序的正确性和有效性。
#在此仅强调：任何一个写程序的人，都必须具备测试自己程序的能力。任何一个程序，在编写后都需要进行测试。
#33.2.3 开发层
#意即跳出程序之外，从人员配置、流程安排等人和组织管理的角度去降低 bug 发生的概率。


#35 计算机程序里的函数
#35.1 变的和不变的代码
#把应该不变的查找过程，和随时可变的数列及目标数的代码分隔开
#35.2 数学中的函数
#在数学里，函数是两个集合之间的一个映射(对应关系)。输入集合中各元素都能对应唯一的一个输出元素。反之未必。
#35.3 编程中的函数 --> 一系列指令组成的操作
#把变的（动态的）和不变的（静态）的代码分开
#不变的部分描述: 一个特定的功能，变的部分: 指代这个特定功能所加诸的对象

#35.4 函数的定义
#是一个命令序列，一个代码块, 有严格的开头和结尾格式
#函数四要素: 函数名,参数,函数体,返回值
#函数名和函数体必须有，参数和返回值则可以没有

#35.5 函数的调用
#调用函数的过程,3步: (1)在函数定义完成后的某处，“写下”函数的名字; (2)把参数传递给函数; (3) 把返回值赋值给一个变量
#(1)必须有，(2)(3)可以没有

#35.6 二分查找函数的定义和调用
# def binarySearch(arr, tn):
#     low = 0
#     high = len(arr) - 1

#     while low <= high:
#         m = int((high - low) / 2) + low
#         if arr[m] == tn:
#             return m
#         else:
#             if arr[m] < tn:
#                 low = m + 1
#             else:
#                 high = m - 1

#     if low > high:
#                 return -1
#调用
# arr = [3, 5, 9, 7, 12, 15, 18, 32, 66, 78, 94, 103, 269]
# tn = 5
# result = binarySearch(arr, tn)
# if (result >= 0):
#     print("Succeeded! The target index is: ", result)
# else:
#     print("Search failed.")

#35.7 函数存在的意义 --> 重用、抽象和封装
#35.7.1 重用 --> 定义一次，调用多次
#35.7.2 抽象&封装
#使用一个函数时，需要知道: 函数的功能,函数名,参数,返回值.
#封装和抽象是共生的.  无法实现有效的抽象和封装是许多Bug产生的根本原因
#许多编程语言的特征（例如函数的重载、覆盖）都是为了更好地实现抽象和封装
#编程语言之所以衍生出不同的编程范型，很多是为了达到操作的抽象与封装

#35.8 从程序之外获得数据
#35.8.1 用户输入数据 --> 让用户在程序运行时输入（部分）运算数据
#35.8.2 持续接受用户接受的数据
#交互式模式: 让用户输入数据，运算，然后告知运算结果的程序运行模式

#35.8.3 从文件中获得数据
#文件和Python程序放在一个目录下时，相对路径为空，直接以文件名作为路径即可。
#否则可以写上相对路径或者绝对路径。
# filePath = 'sequences_for_search.txt' 
# with open(filePath) as fp:
#    line = fp.readline()
#    while line:
#        tmps = line.strip().split('|') #将读入的一行以’|’为分隔截为两段
#        if (len(tmps) != 2): # 如果格式不对，则忽略此行
#            continue

#        arrStrs = tmps[0].strip().split(',') #将‘|‘前的部分在以逗号为分割切分
#        arr = list(map(int, arrStrs)) #转化为整型list
#        tn = int(tmps[1]) #将’|‘后的部分读取为整型

#        result = binarySearch(arr, tn)
#        if (result >= 0):
#            print("Succeeded! The target index is: ", result)
#        else:
#            print("Search failed.")

#        line = fp.readline()


#36 二分查找变形记：重复数列二分查找
#36.1 包含重复元素数列的二分查找
#36.2 重复元素数列二分查找的变形 --> 要求找到首个或最后一个与目标数相同的元素
# 查找重复数字串的“头”或“尾”
#delta: 负往前找，正一往后找
# delta = -1
# while(arr[m + delta] == tn):
#     m = m + delta

#36.3 流程图
#36.3.1 (含)重复数字数列二次查找函数
# def repeatingSequenceBinarySearch(arr, tn, delta):
#     low = 0
#     high = len(arr) - 1
#     while low <= high:
#         m = int((high - low) / 2) + low
#         if (arr[m] == tn):
#             while (arr[m + delta] == tn):
#                 m += delta  # m = m + delta的另一种写法
#             return m
#         else:
#             if (arr[m] < tn):
#                 low = m + 1
#             else:
#                 high = m - 1

#     if (low > high):
#         return -1
# #调用
# arr = [3, 3, 3, 5, 5, 5, 5, 9, 7, 12, 15, 15, 18, 32, 66, 78, 94, 103, 269, 269]
# tn = 5
# result = repeatingSequenceBinarySearch(arr, tn, -1)
# if (result >= 0):
#     print("Succeeded! The target index is: ", result)
# else:
#     print("Search failed.")

#36.3.2 Bug Fix
#对于Python的List而言，有效下标是-1到len(arr)-1
# m范围: 0~(len(arr)-1) --> (m+delta)最大值为len(arr),不属于List下标的有效范围。
# def repeatingSequenceBinarySearch(arr, tn, delta):
#     low = 0
#     high = len(arr) - 1
#     while low <= high:
#         m = int((high - low) / 2) + low
#         if arr[m] == tn:
#             while m + delta >= 0 and m + delta < len(arr) and arr[m + delta] == tn:
#                 m += delta  # m = m + delta的另一种写法
#             return m
#         else:
#             if (arr[m] < tn):
#                 low = m + 1
#             else:
#                 high = m - 1

#     if (low > high):
#         return -1


#37 让变形更高效：与经典二分查找相同的时间复杂度
#37.1 重复元素数列二分查找的时间复杂度

#37.2 新代码的时间复杂度
#新加进去的代码,顺序前行或后退，其时间复杂度O(n)

#37.3 时间复杂度的计算
# 顺序前推（后退）的时间复杂度 --> 平均移动次数对应量级为O(n)
# 两个循环
#接续累加的关系, 时间复杂度O(log(n))+O(n) --> O(n)

#37.4 重复元素数列二分查找的O(logn)算法
# 算法提速
# def quickRepeatingSequenceBinarySearch(arr, tn, delta):
#     low = 0
#     high = len(arr) - 1
#     while low <= high:
#         m = int((high - low) / 2) + low
#         if (arr[m] == tn):
#             if m + delta >= 0 and m + delta < len(arr) and arr[m + delta] == tn:
#                 if (delta < 0):
#                     high = m - 1
#                 else:
#                     low = m + 1
#             else:
#                 return m                
#         else:
#             if (arr[m] < tn):
#                 low = m + 1
#             else:
#                 high = m - 1

#     if (low > high):
#         return -1
# #调用
# arr = [ 3, 5, 5, 5, 5, 9, 7, 12, 15, 18, 32, 66, 78, 94, 103, 269]
# tn = 5
# result = quickRepeatingSequenceBinarySearch(arr, tn, -1)
# if (result >= 0):
#     print("Succeeded! The target index is: ", result)
# else:
#     print("Search failed.")

# 特快 vs 普快
# 当前区间的中心元素与目标数相等，且它前面的元素也与目标数相等。
#    将当前区间二分，新区间以当前位置的前一位为结尾


#38 二分查找算法再变形：旋转数列二分查找
#38.1 有序数列的旋转

#38.2 无重复数的旋转数列的二分查找
# 套用经典二分查找

#38.3 算法实现
# 代码
# def binarySearchInRotatedSequence(arr, tn):
#     low = 0
#     high = len(arr)-1
#     while low <= high :
#         m = int((high - low)/2) + low
#         if arr[m] == tn:
#             return m
#         else:
#             if (arr[m] < tn):
#                 if (arr[m] < arr[low]):
#                     if (arr[low] <= tn):
#                         high = m - 1
#                     else:
#                         low = m + 1
#                 else:
#                     low = m + 1
#             else: # arr[m] > tn
#                 if (arr[m] > arr[high]):
#                     if (arr[high] >= tn):
#                         low = m + 1
#                     else:
#                         high = m - 1
#                 else:
#                     high = m - 1

#     if (low > high):
#         return -1

# 代码优化
# def binarySearchInRotatedSequence(arr, tn):
#     low = 0
#     high = len(arr) - 1
#     while low <= high :
#         m = int((high - low)/2) + low
#         if arr[m] == tn:
#             return m
#         else:
#             if arr[m] < tn:
#                 if arr[m] < arr[low] and arr[low] <= tn:
#                         high = m - 1
#                 else:
#                     low = m + 1
#             else:
#                 if arr[m] > arr[high] and arr[high] >= tn:
#                         low = m + 1
#                 else:
#                     high = m - 1

#     if low > high:
#         return -1
# #调用
# arr = []
# for i in range(11, 21):
#     arr.append(i)
# for i in range(1, 11):
#     arr.append(i)
# tnList = [1, 2, 7, 10, 11, 15, 20]
# for tn in tnList:
#     r = binarySearchInRotatedSequence(arr, tn)
#     if (r == -1):
#         print("Failed to search", tn)
#     else:
#         print(tn, "is found in position", r)


#38.4 带重复元素的旋转数列查找
# 结合经典二分查找和重复数列二分查找
# delta来控制搜索方向。-1往前找，去搜索最靠前；+1往后找，找到最靠后
#注意: 对于头尾元素需特殊处理，因为旋转，头和尾的数值可能是一样的

# def binarySearchInRotatedRepeatingSequence(arr, tn, delta):
#     low = 0
#     high = len(arr) - 1

#     if (delta < 0 and arr[0] == tn):
#         return 0
#     if (delta > 0 and arr[len(arr) -1] == tn):
#         return len(arr) -1

#     while (low <= high ):
#         m = int((high - low)/2) + low
#         if (arr[m] == tn):
#             if (m + delta >= 0 and m+ delta < len(arr) and arr[m + delta] == tn):
#                 if (delta < 0):
#                     high = m - 1
#                 else:
#                     low = m + 1
#             else:
#                 return m
#         else:
#             if (arr[m] < tn):
#                 if (arr[m] < arr[low]) and (arr[low] <= tn):
#                         high = m - 1
#                 else:
#                     low = m + 1
#             else:
#                 if (arr[m] > arr[high]) and (arr[high] >= tn):
#                     low = m + 1
#                 else:
#                     high = m - 1

#     if (low > high):
#         return -1

# #调用
# arr = [10]
# for i in range(11, 21):
#     arr.append(i)
#     arr.append(i)
# for i in range(1, 11):
#     arr.append(i)
#     arr.append(i)
# tnList = [1, 2, 7, 10, 11, 15, 20]
# for tn in tnList:
#     r = binarySearchInRotatedRepeatingSequence(arr, tn, -1)
#     if (r == -1):
#         print("Failed to search", tn)
#     else:
#         print(tn, "is found in position", r)


#39 怎么才算学会了一个算法？
#39.1 感性认识Level-5
# def closestSqrt(n):    
#     if n <= 0:
#         print("input number is not invalid")
#         return -1
#     low = 1
#     high = n
#     while low <= high:
#         m = int((high - low) / 2) + low

#         if m * m == n:
#             return m
#         elif m * m < n and (m + 1)* (m + 1) > n :
#             if n - m * m  > (m + 1)* (m +1 ) - n:
#                 return m + 1
#             else:
#                 return m
#         else:
#             if m * m  >  n:
#                 high = m - 1
#             else:
#                 low = m + 1

#     return -1
#不要刻意背诵算法流程，要首先搞清楚原理，然后逐步推导出流程，再从流程对应到代码。
#微创新：在现有算法的基础上进一步优化，以扩展功能，减低时间或空间复杂度










