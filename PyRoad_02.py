

# 四、Python三大利器
# Python中的三大利器包括：迭代器，生成器，装饰器，利用好它们才能开发出最高性能的Python程序.
# 涉及到的内置模块 itertools提供迭代器相关的操作。

#04_01 寻找第n次出现位置
# def search_n(s, c, n):
#     size = 0
#     for i, x in enumerate(s):
#         if x == c:
#             size += 1
#         if size == n:
#             return i
#     return -1
# print(search_n("fdasadfadf", "a", 3))# 结果为7，正确
# print(search_n("fdasadfadf", "a", 30))# 结果为-1，正确

#04_02 斐波那契数列前n项
# def fibo(n):
#     a, b = 1, 1
#     for i in range(n):
#         yield a
#         a, b = b, a + b
# r=fibo(5)
# print(r)        
# print(list(r))  # [1, 1, 2, 3, 5]

#04_03 找出所有重复元素
# from collections import Counter
# def find_all_duplicates(lst):
#     c=Counter(lst)
#     return list(filter(lambda k: c[k]>1,c))
# print(find_all_duplicates([1,2,2,3,3,3]))

#04_04 联合统计次数
# from collections import Counter
# a = ['apple', 'orange', 'computer', 'orange']
# b = ['computer', 'orange']
# ca = Counter(a)
# cb = Counter(b)
# c1=ca+cb

# 进一步抽象，实现多个列表内元素的个数统计
# def sumc(*c):
#     if (len(c) < 1):
#         return
#     mapc = map(Counter, c)
#     # print('mapc=',list(mapc))
#     s = Counter([])
#     for ic in mapc: # ic 是一个Counter对象
#         s += ic
#     return s
# r=sumc(a, b, ['abc'], ['face', 'computer'])
# print('r[\'computer\']=',r['computer'])
# print('r=',r)

#04_05 groupby单字段分组
# from itertools import groupby
# a = [{'date': '2019-12-15', 'weather': 'cloud'},
#      {'date': '2019-12-13', 'weather': 'sunny'},
#      {'date': '2019-12-14', 'weather': 'cloud'}]
# a.sort(key=lambda x: x['weather'])
# for k, items in  groupby(a,key=lambda x:x['weather']):
#      print(k)
#      for i in items:
#          print(i)

#04_06 itemgetter和key函数
# from operator import itemgetter
# from itertools import groupby
# a = [{'date': '2019-12-15', 'weather': 'cloud'},
#      {'date': '2019-12-13', 'weather': 'sunny'},
#      {'date': '2019-12-14', 'weather': 'cloud'}]
# # a.sort(key=itemgetter('weather'))
# a.sort(key=itemgetter('weather','date'))
# for k, items in groupby(a, key=itemgetter('weather')):
#      print(k)
#      for i in items:
#          print(i)

#04_08 sum函数计算和聚合同时做
# 生成器每迭代一步吐出(yield)一个元素并计算和聚合后，进入下一次迭代，直到终点。
# a=[1,2,3,4]
# genobj=(i+1 for i in a) #list , 得到一个生成器(generator)对象
# sa=sum(genobj)
# print('sa=',sa) #14

#04_09 list分组(生成器版)
# from math import ceil
# def divide_iter(lst, n):
#     if n <= 0:
#         yield lst
#         return
#     i, div = 0, ceil(len(lst) / n)
#     while i < n:
#         yield lst[i * div: (i + 1) * div]
#         i += 1

# l1=list(divide_iter([1, 2, 3, 4, 5,6,7], 0))  # [[1, 2, 3, 4, 5]]
# l2=list(divide_iter([1, 2, 3, 4, 5,6,7], 3))  # [[1, 2, 3], [4, 5, 6], [7]]
# print('l1=',l1)
# print('l2=',l2)

#04_10 列表全展开（生成器版）
#多层列表展开成单层列表
# a=[1,2,[3,4,[5,6],7],8,["python",6],9]
# def function(lst):
#     for i in lst:
#         if type(i)==list:
#             yield from function(i)
#         else:
#             yield i
# print(list(function(a))) # [1, 2, 3, 4, 5, 6, 7, 8, 'python', 6, 9]

#04_11 测试函数运行时间的装饰器
# import time
# def timing_func(fn):
#     def wrapper():
#         start=time.time()
#         fn()   #执行传入的fn参数
#         stop=time.time()
#         return (stop-start)
#     return wrapper

# @timing_func
# def test_list_append():
#     lst=[]
#     for i in range(0,100000):
#         lst.append(i)  

# @timing_func
# def test_list_compre():
#     [i for i in range(0,100000)]  #列表生成式

# a=test_list_append()
# c=test_list_compre()
# print("test list append time:",a)
# print("test list comprehension time:",c)
# print("append/compre:",round(a/c,3))

#04_12 统计异常出现次数和时间的装饰器
# 写一个装饰器，统计某个异常重复出现指定次数时，经历的时长。
# import time
# import math

# def excepter(f):
#     i=0
#     t1=time.time()
#     def wrapper():
#         try:
#             f()
#         except Exception as err:
#             nonlocal i
#             i += 1
#             print(f'{err.args[0]}: {i}')
#             t2=time.time()
#             if i==n:
#                 print(f'spending time:{round(t2-t1,2)}')
#     return wrapper

# n=10
# @excepter
# def divide_zero_except():
#     time.sleep(0.1)
#     j = 1/(40-20*2)    
# for k in range(n):
#     divide_zero_except()

# @excepter
# def outof_range_except():
#     a = [1,3,5]
#     time.sleep(0.1)
#     print(a[3])
# for _ in range(n):
#     outof_range_except()    

#04_14 装饰器通俗理解
#1 装饰器写法
#它必须接受一个函数f，然后返回另外一个函数g.
# def call_print(f):
#     def g():
#         print('you\'re calling %s function'%(f.__name__))
#     return g

# @call_print
# def func1():
#     pass

# @call_print
# def func2():
#     pass

# func1()
# func2()

#2 普通写法
# def func1():
#   pass

# def func2():
#   pass

# def call_print(f):
#   def g():
#     print('you\'re calling %s function'%(f.__name__,))
#   return g

# func1=call_print(func1)
# func2=call_print(func2)
# func1()
# func2()

#04_15 定制递减迭代器
#编写一个迭代器，通过循环语句，实现对某个正整数的依次递减1，直到0.
# from collections.abc import Iterator
# class Descend(Iterator):
#     def __init__(self,N):
#         self.N=N
#         self.a=3
#     def __iter__(self):
#         return self 
#     def __next__(self):
#         while self.a<self.N:
#             self.N-=1
#             return self.N
#         raise StopIteration
    
# descend_iter=Descend(10)
# print(list(descend_iter))



#五、Python绘图
# Python常用的绘图工具：matplotlib, seaborn, plotly等，以及专用于绘制某类图如词云图等的包，描绘绘图轨迹的turtle包等。

#05_01  turtle绘制奥运五环图
# import turtle as p
# def drawCircle(x,y,c='red'):
#     p.pu()# 抬起画笔
#     p.goto(x,y) # 绘制圆的起始位置
#     p.pd()# 放下画笔
#     p.color(c)# 绘制c色圆环
#     p.circle(30,360) #绘制圆：半径，角度

# p.pensize(3)
# drawCircle(0,0,'blue')
# drawCircle(60,0,'black')
# drawCircle(120,0,'red')
# drawCircle(90,-30,'green')
# drawCircle(30,-30,'yellow')    
# p.done()

#05_04 plotly画柱状图和折线图
# import plotly.graph_objects as go
# fig = go.Figure()
# fig.add_trace(
#     go.Scatter(
#         x=[0, 1, 2, 3, 4, 5],
#         y=[1.5, 1, 1.3, 0.7, 0.8, 0.9]
#     ))
# fig.add_trace(
#     go.Bar(
#         x=[0, 1, 2, 3, 4, 5],
#         y=[2, 0.5, 0.7, -1.2, 0.3, 0.4]
#     ))
# fig.show()

#05_06 matplotlib折线图
# import matplotlib.pyplot as plt
# import numpy as np
# import example_utils

# x = np.linspace(0, 10, 100)

# fig, axes = example_utils.setup_axes()
# for ax in axes:
#     ax.margins(y=0.10)

# # 子图1 默认plot多条线，颜色系统分配
# for i in range(1, 6):
#     axes[0].plot(x, i * x)

# # 子图2 展示线的不同linestyle
# for i, ls in enumerate(['-', '--', ':', '-.']):
#     axes[1].plot(x, np.cos(x) + i, linestyle=ls)

# # 子图3 展示线的不同linestyle和marker
# for i, (ls, mk) in enumerate(zip(['', '-', ':'], ['o', '^', 's'])):
#     axes[2].plot(x, np.cos(x) + i * x, linestyle=ls, marker=mk, markevery=10)

# # example_utils.title(fig, '"ax.plot(x, y, ...)": Lines and/or markers', y=0.95)
# fig.savefig('plot_example.png', facecolor='none')
# plt.show()

#05_0 matplotlib散点图
# import numpy as np
# import matplotlib.pyplot as plt
# import example_utils

# # 随机生成数据
# np.random.seed(1874)
# x, y, z = np.random.normal(0, 1, (3, 100))
# t = np.arctan2(y, x)
# size = 50 * np.cos(2 * t)**2 + 10

# fig, axes = example_utils.setup_axes()

# # 子图1
# axes[0].scatter(x, y, marker='o',  color='darkblue', facecolor='white', s=80)
# example_utils.label(axes[0], 'scatter(x, y)')

# # 子图2
# axes[1].scatter(x, y, marker='s', color='darkblue', s=size)
# example_utils.label(axes[1], 'scatter(x, y, s)')

# # 子图3
# axes[2].scatter(x, y, s=size, c=z,  cmap='gist_ncar')
# example_utils.label(axes[2], 'scatter(x, y, s, c)')
# example_utils.title(fig, '"ax.scatter(...)": Colored/scaled markers',y=0.95)

# fig.savefig('scatter_example.png', facecolor='none')
# plt.show()



# 六、 Python之坑

#06_01 含单个元素的元组
# c=(5,)
# print(type(c)) #tuple
# print('c=',c)

#06_02 默认参数设为空
# 含有默认参数的函数，如果类型为容器.这是可变类型的默认参数之坑，请务必设置此类默认参数为None：
# def f(a,b=[]):
#     print('b=',b)
#     return b
# ret=f(1)
# ret.append(1)
# ret.append(2)
# f(1)

# def f(a,b=None):
#     print('b=',b)
#     return b
# ret=f(1)
# f(1)

#06_03 共享变量未绑定
# 有时想要多个函数共享一个全局变量，但却在某个函数内试图修改它为局部变量：
# i=1
# def f():
#     global i
#     i += 1

#06_04 lambda自由参数
# 排序和分组的key函数常使用lambda，表达更加简洁
# 定义lambda使用的i被称为自由参数，它只在调用lambda函数时，值才被真正确定下来
#1 错误写法：
# a=[lambda x: x+i for i in range(3)]
# for f in a:
#     print(f(1))
#2 正确做法： 转化自由参数为lambda函数的默认参数
# a=[lambda x,i=i: x+i for i in range(3)]
# for f in a:
#     print(f(1))

#06_05 各种参数使用
# Python强大多变，原因之一在于函数参数类型的多样化。方便的同时，也为使用者带来更多的约束规则。
# 总结主要的参数使用规则:

#规则1：位置参数必须一一对应，缺一不可
#位置参数的定义：函数调用时根据函数定义的参数位（形参）置来传递参数，是最常见的参数类型。
# def f(a):
#     return a
# f(1) #位置参数

#位置参数不能缺少：
# def f(a,b):
#     pass
# # f(1)
# f(1,2)

#规则2：关键字参数必须在位置参数右边
# 在函数调用时，通过‘键--值’方式为函数形参传值，不用按照位置为函数形参传值。
# def f(a):
#     print(f'a:{a}')
# f(a=1)

#规则3：对同一个形参不能重复传值
# 在定义函数时，可为形参提供默认值。
# 对于有默认值的形参，调用函数时如果为该参数传值，则使用传入的值，否则使用默认值。
# f(1,width=20.,width=30.) #SyntaxError: keyword argument repeated

#规则4：无论是函数的定义还是调用，默认参数的定义应该在位置形参右面
# 只在定义时赋值一次；默认参数通常应该定义成不可变类型

# def f(a,b=1):
#     print(f'a={a},b={b}')
# f(a=10)

#1 可变位置参数
# def f(*a):
#     print('a=',a)
#     return a
# a1=f(1)
# a2=f(1,2,3)   
# print(type(a1)) #tuple
# print(type(a2)) #tuple
#f(a=1) --> 错误

#2 可变关键字参数
# def f(**a):
#     print('a=',a)
# f(a=1)
# f(a=1,b=2,width=3)
# f(1) --> TypeError: f() takes 0 positional arguments but 1 was given

#06_06 列表删除
# 删除一个列表中的元素，此元素可能在列表中重复多次：
# def del_item(lst,e):
#     d=dict(zip(range(len(lst)),lst)) --> 构造字典
#     print('d=',d)
#     return [v for k,v in d.items() if v!=e]
# l1=[1,3,3,3,5]
# l2=del_item(l1,3)
# print('l2=',l2)

#06_07 列表快速复制
#1 在python中*与列表操作，实现快速元素复制：
# l=[1,3,5]*3
# print('l=',l)
# l[0]=10
# print('l=',l)

#2 列表元素为列表或字典等复合类型：结果出乎意料，l[1[0]等也被修改为10
#因为*复制的复合对象都是浅引用.  id(a[0])与id(a[2])门牌号是相等的
# l = [[1,3,5],[2,4]] * 3
# print('l=',l)
# l[0][0]=10
# print('l=',l)

#06_08 字符串驻留
# a='something'
# b='some'+'thing'
# print(id(a)==id(b))

# a = '@zglg.com'
# b = '@zglg'+'.com'
# print(id(a)==id(b))

#06_09 相同值的不可变对象
# 具有相同值的不可变对象在Python中始终具有相同的哈希值
# 由于存在哈希冲突，不同值的对象也可能具有相同的哈希值。
# d={}
# d[1]='abcd'
# d[1.0]='1234'
# print('d=',d)
# print('d[1]=',d[1])
# print('d[1.0]=',d[1.0])

#06_10 对象销毁顺序
# 调用id函数, Python 创建一个 SE 类的实例，并使用id函数获得内存地址后，销毁内存丢弃这个对象。
# 当连续两次进行此操作, Python会将相同的内存地址分配给第二个对象，所以两个对象的id值是相同的.
# 但是is行为却与之不同，
# class SE(object):
#   def __init__(self):
#     print('init')
#   def __del__(self):
#     print('del')
# print(SE() is SE()) #False
# print(id(SE()) == id(SE())) #True

#06_11 充分认识for
# 为什么不是执行一次就退出？
# range(5)生成的下一个元素被解包，并赋值给目标列表的变量i.
# for i in range(5):
#     print('i=',i)
#     i=10

#06_12 认识执行时机
# array = [1, 3, 5]
# g = (x for x in array if array.count(x) > 0)

# array = [1, 3, 5]
# g = (x for x in array if array.count(x) > 0)
# array = [5, 7, 9]

# 原因在于：生成器表达式中, in 子句在声明时执行, 而条件子句则是在运行时执行。
# g = (x for x in [1,3,5] if [5,7,9].count(x) > 0)

# print('g=',list(g)) #[5]

#06_13 创建空集合错误
# a={}  #<class 'dict'>
# a=set() #<class 'set'>
# print(type(a)) 



#八、基础算法入门


#08_01










