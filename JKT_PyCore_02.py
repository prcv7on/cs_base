#015 Python对象的比较、拷贝
# a=10
# b=10
# print('a==b : {}'.format(a==b))
# print('id(a)= {}'.format(id(a)))
# print('id(b)= {}'.format(id(b)))
# print('a is b : {}'.format(a is b))
# print('\n')

# a=257
# b=257
# print('a==b : {}'.format(a==b))
# print('id(a)= {}'.format(id(a)))
# print('id(b)={}'.format(id(b)))
# print('a is b : {}'.format(a is b))

# t1=(1,2,[3,4])
# t2=(1,2,[3,4])
# print('t1==t2 : {}'.format(t1==t2))
# t1[-1].append(5) #??
# print('t1={}'.format(t1)) #t1=(1, 2, [3, 4, 5])
# print('t2={}'.format(t2)) #t2=(1, 2, [3, 4])
# print('t1==t2 : {}'.format(t1==t2))

# l1=[1,2,3]
# l2=list(l1)
# print('l2={}'.format(l2))
# print('l1==l2 : {}'.format(l1==l2))
# print('l1 is l2 : {}'.format(l1 is l2))

# s1=set([1,2,3])
# s2=set(s1)
# print('s2={}'.format(s2))
# print('s1==s2 : {}'.format(s1==s2))
# print('s1 is s2 : {}'.format(s1 is s2))

# l1=[1,2,3]
# l2=l1[:]
# print('l1==l2 : {}'.format(l1==l2))
# print('l1 is l2 : {}'.format(l1 is l2))

# import copy
# l1=[1,2,3]
# l2=copy.copy(l1)
# print('l1==l2 : {}'.format(l1==l2))
# print('l1 is l2 : {}'.format(l1 is l2))

# t1=(1,2,3)
# t2=tuple(t1)
# print('t1==t2 : {}'.format(t1==t2))
# print('t1 is t2 : {}'.format(t1 is t2))

# l1=[[1,2],(30,40)]
# l2=list(l1)
# l1.append(100)
# l1[0].append(3)
# print('l1={}'.format(l1))
# print('l2={}'.format(l2))
# l1[1] += (50,60)
# print('l1={}'.format(l1))
# print('l2={}'.format(l2))

# import copy
# l1=[[1,2],(30,40)]
# l2=copy.deepcopy(l1) #l1 l2 完全独立
# l1.append(100)
# l1[0].append(3)
# print('l1={}'.format(l1))
# print('l2={}'.format(l2))

# import copy
# x=[1]
# x.append(x)

# y=copy.deepcopy(x)
# print('x==y : {}'.format(x==y)) #x和y是无限嵌套,出错

#016 值传递，引用传递or其他，Python里参数是如何传递的
# a=1
# b=a
# a=a+1
# print('a= {}'.format(a)) #2
# print('b= {}'.format(b)) #1

# l1=[1,2,3]
# l2=l1
# l1.append(4)
# print('l1={}'.format(l1))
# print('l2={}'.format(l2))

# def f1(b):
#     b=2
#     print('b= {}'.format(b)) #2

# a=1
# f1(a)
# print('a= {}'.format(a)) #1

# def f2(b):
#     b=2
#     return b

# a=1
# a=f2(a)
# print('a= {}'.format(a)) #2

# def f3(l2):
#     l2.append(4)

# l1=[1,2,3]
# f3(l1)
# print('l1={}'.format(l1)) #l1=[1, 2, 3, 4]

# def f4(l2):
#     l2=l2+[4]

# l1=[1,2,3]
# f4(l1)
# print('l1={}'.format(l1)) #l1=[1, 2, 3]

# def f5(l2):
#     l2=l2+[4]
#     return l2

# l1=[1,2,3]    
# l1=f5(l1)
# print('l1={}'.format(l1)) #l1=[1, 2, 3, 4]

# l1 = [1, 2, 3]
# l2 = [1, 2, 3]
# l3 = l2
# print('id(l1)= {}'.format(id(l1)))
# print('id(l2)= {}'.format(id(l2)))
# print('id(l3)= {}'.format(id(l3)))
#l2 l3指向同一个对象，l1不是

# def func(d):
#     d['a']=10
#     d['b']=20

# d={'a':1,'b':2}    
# func(d)
# print('d={}'.format(d))
#字典可变，函数内外的d指向同一个对象

# def func(d):
#     d['a'] = 10
#     d['b'] = 20
#     d={'a':1,'b':2}

# d={}
# func(d)
# print('d={}'.format(d)) #d={'a': 10, 'b': 20}


#017 强大的装饰器
#1 函数也是对象
# def func(msg):
#     print('Got a message: {}'.format(msg))

# send_message=func
# send_message('hello world')

#2 函数作为参数，传到另外一个函数中
# def get_message(msg):
#     return 'Got a message: '+msg

# def root_call(func,msg):
#     print(func(msg))

# root_call(get_message,'hello world')

#3 函数嵌套
# def func(msg):
#     def get_message(msg):
#         print('Got a message: {}'.format(msg))
#     return get_message(msg)

# func('hello world')

#4 函数的返回值也可以是函数对象（闭包）
# def func_closure():
#     def get_message(msg):
#         print('Got a message: {}'.format(msg))
#     return get_message

# send_message=func_closure()
# send_message('hello world')

#1 简单的装饰器
# def my_decorator(func):
#     def wrapper():
#         print('wrapper of decorator')
#         func()
#     return wrapper    

# def greet():
#     print('hello world')
# greet=my_decorator(greet)
# greet()
# @my_decorator
# def greet():
#     print('hello world')

# greet()

#2 带有参数的装饰器
# def my_decorator(func):
#     #def wrapper(msg):
#     def wrapper(*args,**kwargs):
#         print('wrapper of decorator')
#         #func(msg)
#         func(*args,**kwargs)
#     return wrapper

# @my_decorator
# def greet(msg):    
#     print(msg)

# greet('hello world')

#3 带有自定义参数的装饰器
# def repeat(num):
#     def my_decorator(func):
#         def wrapper(*args,**kwargs):
#             for i in range(num):
#                 print('wrapper of decorator')
#                 func(*args,**kwargs)
#         return wrapper
#     return my_decorator            

# @repeat(4)
# def greet(msg):    
#     print(msg)

# greet('hello world')
# print(greet.__name__)
# print(help(greet))

#4 原函数还是原函数吗？
# import functools

# def my_decorator(func):
#     @functools.wraps(func) #保留原函数的元信息
#     def wrapper(*args,**kwargs):
#         print('warpper of decorator')
#         func(*args,**kwargs)
#     return wrapper    

# @my_decorator
# def greet(msg):    
#     print(msg)

# print(greet.__name__)

#5 类装饰器
# class Count:
#     def __init__(self,func):
#         self.func=func
#         self.num_calls=0

#     def __call__(self,*args,**kwargs):
#         self.num_calls += 1
#         print('num_calls= {}'.format(self.num_calls))
#         return self.func(*args,**kwargs)

# @Count
# def example():
#     print('hello world')
# example()

#6 装饰器的嵌套
# import functools

# def my_decorator1(func):
#     @functools.wraps(func)
#     def wrapper(*args,**kwargs):
#         print('execute decorator1')
#         func(*args,**kwargs)
#     return wrapper    

# def my_decorator2(func):
#     @functools.wraps(func)
#     def wrapper(*args,**kwargs):
#         print('execute decorator2')
#         func(*args,**kwargs)
#     return wrapper  

# @my_decorator1
# @my_decorator2
# def greet(msg):
#     print(msg)

# greet('hello world')

#018 metaclass，是潘多拉魔盒还是阿拉丁神灯？
#1 metaclass 的超越变形特性有什么用
#YAML是家喻户晓的 Python 工具，可方便地序列化/逆序列化结构数据
#YAMLObject的一个超越变形能力，它的任意子类支持序列化和反序列化（serialization & deserialization）
#(1) 对于load(),dump() 的使用者，无需提前知道任何类型信息，这让超动态配置编程成了可能。--> 让引擎根据文本配置文件，动态加载所需的 Python 类
#(2) 对于YAML使用者，只要简单继承yaml.YAMLObject，就能让Python Object具有序列化和逆序列化能力。

# class Monster(yaml.YAMLObject):
#     yaml_tag = u'!Monster'
#     def __init__(self, name, hp, ac, attacks):
#         self.name = name
#         self.hp = hp
#         self.ac = ac
#         self.attacks = attacks
#     def __repr__(self):
#         return "%s(name=%r, hp=%r, ac=%r, attacks=%r)" % (
#             self.__class__.__name__, self.name, self.hp, self.ac,self.attacks)

# yaml.load("""
# --- !Monster
# name: Cave spider
# hp: [2,6]    # 2d6
# ac: 16
# attacks: [BITE, HURT]
# """)

# Monster(name='Cave spider', hp=[2, 6], ac=16, attacks=['BITE', 'HURT'])

# print yaml.dump(Monster(name='Cave lizard', hp=[3,6], ac=16, attacks=['BITE','HURT']))

#2 metaclass 的超越变形特性怎么用
#需要一个全局注册器，让YAML知道，序列化文本中的 !Monster需载入成Monster这个Python类型。
# # Python 2/3 相同部分
# class YAMLObjectMetaclass(type):
#   def __init__(cls, name, bases, kwds):
#     super(YAMLObjectMetaclass, cls).__init__(name, bases, kwds)
#     if 'yaml_tag' in kwds and kwds['yaml_tag'] is not None:
#       cls.yaml_loader.add_constructor(cls.yaml_tag, cls.from_yaml)
#   # 省略其余定义

# # Python 3
# class YAMLObject(metaclass=YAMLObjectMetaclass):
#   yaml_loader = Loader
#   # 省略其余定义

# # Python 2
# class YAMLObject(object):
#   __metaclass__ = YAMLObjectMetaclass
#   yaml_loader = Loader
#   # 省略其余定义

#3 Python 底层语言设计层面如何实现 metaclass ?
#第1，所有Python的用户定义类，都是 type类的实例。
#类本身不过是type类的实例。在Python的类型世界里，type类就是造物的上帝。
# class MyClass:
#     pass

# instance=MyClass()
# print(type(instance))
# print(type(MyClass))

#第2，用户自定义类，只是type类的__call__运算符重载。
#定义一个类的语句结束时，真正发生的是Python调用type的__call__运算符
# class MyClass1:
#     data=1

# instance1=MyClass1()
# print(MyClass1)
# print(instance1)
# print(instance1.data)
# print('\n')

# MyClass2=type('MyClass2',(),{'data':1})
# instance2=MyClass2()
# print(MyClass2)
# print(instance2)
# print(instance2.data)

#第3，metaclass是type的子类，通过替换type的__call__运算符重载机制，“超越变形”正常的类。
#正是 Python 的类创建机制，给了 metaclass 大展身手的机会。
#一旦把一个类MyClass的metaclass设置成MyMeta，MyClass就不再由原生的type创建，而是调用MyMeta的__call__运算符重载。

#4 使用 metaclass 的风险
#metaclass 会"扭曲变形"正常的 Python 类型模型。
#metaclass在开发框架层面的 Python 库时使用。而在应用层，metaclass 不是很好的选择。
#对初学者的科普和警告：不要轻易尝试 metaclass。


#019 深入理解迭代器和生成器

#1 你肯定用过的容器、可迭代对象和迭代器
# Python中一切皆对象，对象的抽象是类，对象的集合是容器。
# 对于容器，可想象成多个元素在一起的单元；不同容器的区别，正是内部数据结构的实现方法。
# 所有容器都是可迭代的（iterable）。这里的迭代，和枚举不完全一样。
# 严谨地说，迭代器（iterator）提供1个next方法。调用后，要么得到容器下一个对象，要么得到一个 StopIteration错误 --> 只需要知道，next 函数可以不重复不遗漏地一个一个拿到所有元素
# 可迭代对象，通过 iter() 函数返回一个迭代器，再通过 next() 函数就可实现遍历。for in 语句将此过程隐式化，
# 下面这段代码，主要展示怎么判断一个对象是否可迭代：
# def is_iterable(param):
#     try:
#         iter(param)
#         return True
#     except TypeError:
#         return False    

# params=[
#     1234,
#     '1234',
#     [1, 2, 3, 4],
#     set([1, 2, 3, 4]), 
#     {1:1, 2:2, 3:3, 4:4}, 
#     (1, 2, 3, 4)
# ]

# for param in params:
#     print('{} is iterable? {}'.format(param,is_iterable(param)))

#2 生成器，又是什么？
# 生成器是懒人版本的迭代器。
# 在迭代器中，要枚举它的元素，这些元素需要事先生成。
# 生成器的概念应运而生，调用 next() 函数时，才会生成下一个变量。生成器的写法是用小括号括起来
# 生成器不会像迭代器一样占用大量内存，只有在被使用的时才会调用。生成器在初始化的时候，无需运行一次生成操作 --> 耗时明显比迭代器短。
# import os
# import psutil

# # 显示当前 python 程序占用的内存大小
# def show_memory_info(hint):
#     pid=os.getpid()
#     p=psutil.Process(pid)

#     info = p.memory_full_info()
#     memory = info.uss / 1024. / 1024
#     print('{} memory used: {} MB'.format(hint, memory))

# def test_iterator():
#     show_memory_info('initing iterator') 
#     list_1 = [i for i in range(1000000)]  
#     show_memory_info('after iterator initiated')  
#     print(sum(list_1))   
#     show_memory_info('after sum called')

# def test_generator():    
#     show_memory_info('initing generator')   
#     list_2 = (i for i in range(1000000))   
#     show_memory_info('after generator initiated')  
#     print(sum(list_2))  
#     show_memory_info('after sum called')

# %time test_iterator()
# %time test_generator()

#3 生成器，还能玩什么花样？
#函数运行到yield这一行，程序从这里暂停，然后跳到next()函数。 i** k成了next()函数的返回值。
#每次 next(gen) 函数被调用时，暂停的程序又复活，从yield向下继续执行；同时局部变量 i 没有被清除，而是继续累加。
# 迭代器是一个有限集，生成器可以无限集。只管调用 next()，生成器根据运算自动生成新元素，然后返回
# def generator(k):
#     i=1
#     while True:
#         yield i**k
#         i += 1

# gen_1=generator(1)        
# gen_3=generator(3)  
# print(gen_1)
# print(gen_3)

# def get_sum(n):
#     sum_1,sum_3=0,0
#     for i in range(n):
#         next_1=next(gen_1)
#         next_3=next(gen_3)
#         print('next_1={},next_3={}'.format(next_1,next_3))
#         sum_1 += next_1
#         sum_3 += next_3
#     print(sum_1*sum_1)
#     print(sum_3)

# get_sum(8)

#index_generator 会返回一个 Generator 对象，需要使用 list 转换为列表后，才能用 print 输出。
#用更少、更清晰的代码实现相同功能，一直被推崇，因为这样能有效提高代码可读性,这里“更少”的前提是清晰

# def idx_normal(L,target):
#     ret=[]
#     for i,num in enumerate(L):
#         if num==target:
#             ret.append(i)
#     return ret        

# def idx_generator(L,target):
#     for i,num in enumerate(L):
#         if num==target:
#             yield i

# print(idx_normal([1, 6, 2, 4, 5, 2, 8, 6, 3, 2], 2))
# print(list(idx_generator([1, 6, 2, 4, 5, 2, 8, 6, 3, 2], 2)))


# def is_subsequence(a, b):  
#     b = iter(b)   
#     return all(i in b for i in a)

#先把这段代码复杂化
# def is_subsequence(a,b):
#     b=iter(b) #把列表 b 转化成了一个迭代器
#     print(b)

#     gen=(i for i in a) #产生一个生成器，这个生成器可遍历对象 a，因此能够输出 1, 3, 5
#     print(gen)
#     for i in gen:
#         print(i)

#     gen=((i in b) for i in a) #这里非常巧妙地利用生成器的特性，next() 函数运行时，保存了当前的指针
#     print(gen)
#     for i in gen:
#         print(i)

#     return all(((i in b) for i in a)) #判断一个迭代器的元素是否全部为 True

# print(is_subsequence([1, 3, 5], [1, 2, 3, 4, 5]))
#print(is_subsequence([1, 4, 3], [1, 2, 3, 4, 5]))

#4 总结
# 容器是可迭代对象，可迭代对象调用 iter() 函数，得到一个迭代器。迭代器可通过 next() 函数得到下一个元素，从而支持遍历。
# 生成器是一种特殊的迭代器。使用生成器，可写出更清晰的代码；合理使用生成器，可降低内存占用、优化程序结构、提高程序速度。
#思考题。对于一个有限元素的生成器，如果迭代完成后，继续调用 next() ，会发生什么呢？生成器可以遍历多次吗？
#生成器只能遍历一次，继续调用 next() 会 raise StopIteration。只有复位生成器才能重新进行遍历。


#024 带你解析 Python 垃圾回收机制
# Python 程序运行时，需要在内存中开辟一块空间，用于存放运行时产生的临时变量；计算完成后，再将结果输出到永久性存储器中。
# 数据量过大，内存空间管理不善，很容易出现 OOM（out of memory），俗称爆内存。
# 什么是内存泄漏?
# 程序本身没有设计好，导致程序未能释放已不再使用的内存。
# 代码在分配了某段内存后，因为设计错误，失去了对这段内存的控制，造成内存浪费。
#Python 是通过什么机制来回收这些空间的呢?

#1 计数引用 --> 当对象的引用计数（指针数为0，说明此对象永不可达，自然它也就成为了垃圾，需要被回收。
# Python 中一切皆对象。因此，你所看到的一切变量，本质都是对象的一个指针。


# import os
# import psutil

# 显示当前 python 程序占用的内存大小
# def show_memory_info(hint):
#     pid = os.getpid()
#     p = psutil.Process(pid)
    
#     info = p.memory_full_info()
#     memory = info.uss / 1024. / 1024
#     print('{} memory used: {} MB'.format(hint, memory))

#函数内部声明的列表 a 是局部变量，函数返回后，局部变量的引用会注销掉；此时，列表 a 所指代对象的引用数为 0，Python 便会执行垃圾回收
#新代码中，global a将 a 声明为全局变量。即使函数返回，列表的引用依然存在，于是对象就不会被垃圾回收掉，依然占用大量内存。
#如果把生成的列表返回，然后在主程序中接收，引用依然存在，垃圾回收不会被触发，大量内存仍然被占用着
# def func():
#     show_memory_info('initial')  
#     #global a 
#     a = [i for i in range(10000000)]  
#     show_memory_info('after a created')

# # func()
# a=func()
# show_memory_info('finished')


#深入看一下 Python 内部的引用计数机制
#sys.getrefcount() 这个函数，可以查看一个变量的引用次数。
#getrefcount 本身也会引入一次计数。
#函数调用发生时，会产生额外的两次引用，一次来自函数栈，另一个是函数参数。
# import sys
# a=[]
# print(sys.getrefcount(a)) # 两次引用，一次来自 a，一次来自 getrefcount

# def func(a):
#     print(sys.getrefcount(a)) # 四次引用，a，python 的函数调用栈，函数参数，和 getrefcount

# func(a)
# print(sys.getrefcount(a)) # 两次引用，一次来自 a，一次来自 getrefcount，函数 func 调用已经不存在

#a、b、c、d、e、f、g 这些变量全部指代同一个对象，sys.getrefcount() 函数统计一个对象被引用的次数
#偏偏想手动释放内存，应该怎么做呢？
#先调用del a删除对象的引用；然后强制调用 gc.collect()，清除没有引用的对象，即可手动启动垃圾回收。

# import sys
# a = []
# print(sys.getrefcount(a)) # 两次
# b = a
# print(sys.getrefcount(a)) # 三次
# c = b
# d = b
# e = c
# f = e
# g = d
# print(sys.getrefcount(a)) # 八次


#2 循环引用
#问题：如果有两个对象，它们互相引用，并且不再被别的对象所引用，那么它们应该被垃圾回收吗？
# 互相引用，导致它们的引用数都不为 0。依然有内存占用
#隐蔽的情况是出现一个引用环，
#Python 使用标记清除（mark-sweep）算法和分代收集（generational），来启用针对循环引用的自动垃圾回收。
#(1)标记清除算法:不可达节点,需要对它们进行垃圾回收 --> mark-sweep 使用双向链表维护了一个数据结构，并且只考虑容器类的对象
#(2)分代收集基于的思想是，新生对象更有可能被垃圾回收，存活更久的对象有更高概率继续存活. 节约不少计算量

# def func():
#     show_memory_info('initial')
#     a = [i for i in range(10000000)]
#     b = [i for i in range(10000000)]
#     show_memory_info('after a, b created')
#     a.append(b)
#     b.append(a)

# func()
# show_memory_info('finished')


#3 调试内存泄漏
#objgraph，一个非常好用的可视化引用关系的包。
# show_refs()，它可以生成清晰的引用关系图。

# import objgraph
# a = [1, 2, 3]
# b = [4, 5, 6]
# a.append(b)
# b.append(a)
# # objgraph.show_refs([a])
# objgraph.show_backrefs([a])

#总结
# 垃圾回收是 Python 自带的机制，用于自动释放不会再用到的内存空间；
# 引用计数是其中最简单的实现，不过切记，这只是充分非必要条件，因为循环引用需要通过不可达判定，来确定是否可回收；
# Python自动回收算法包括标记清除和分代收集，主要针对的是循环引用的垃圾收集；
# 调试内存泄漏方面， objgraph 是很好的可视化分析工具。


#答疑（二）：GIL与多线程是什么关系呢
#问题1：列表 self append 无限嵌套的原理
# x=[1]
# x.append(x)
# print('len(x)={}'.format(len(x)))

#问题2：装饰器的宏观理解
#装饰器的作用与意义，在于其可通过自定义的函数或类，在不改变原函数的基础上，改变原函数的一些功能。
#好处：
#代码更加简洁；逻辑更加清晰；程序的层次化、分离化更加明显。

# # 发表评论
# @authenticate
# def post_comment(request, ...):

# # 发表状态
# @authenticate
# def post_moment(request, ...):

#问题3：GIL 与多线程的关系
#GIL指同一时刻，程序只有一个线程运行；Python 中的多线程，是多个线程交替执行，造成“伪并行”的结果，但具体到某一时刻，仍然只有1个线程在运行

#问题4：多进程与多线程的应用场景
#(1)对 CPU 密集型任务加速，使用多线程是无效的，请使用多进程。
# Python 多线程的本质是多个线程互相切换，但同一时刻仍然只允许一个线程运行。
# 使用多线程，和使用一个主线程，没什么本质差别；在很多情况下，线程切换带来额外损耗，还会降低程序效率。
#(2)I/O 密集型任务加速，请优先使用多线程或 Asyncio。
# I/O 密集型任务,多数时间浪费在 I/O 等待上。
#若I/O 操作非常多、非常 heavy，需要建立的连接较多，一般选择 Asyncio。因为Asyncio 任务切换更加轻量化，它能启动的任务数>>多线程启动的线程数。











