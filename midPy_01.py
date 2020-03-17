

#001 *args和**kwargs

#1 *args
# *args 和 **kwargs 主要用于函数定义。 可将不定数量的参数传给函数。
# 不定：预先不知道, 函数使用者会传递多少个参数,此时使用这两个关键字。
#  *args用于，发送一个非键值对的，可变数量的参数列表，给一个函数.
# def test_var_args(f_arg,*argv):
#     print("first normal arg:", f_arg)
#     for arg in argv:
#         print("another arg through *argv:", arg)

# test_var_args('a','b','c','d')

#2 **kwargs
# 允许将不定长度的键值对作为参数,传递给一个函数。 要在一个函数里处理带名字的参数, 应使用**kwargs
# 怎样在一个函数里, 处理一个键值对参数
# def greet_me(**kwargs):
#     for key,val in kwargs.items():
#         print("{0} == {1}".format(key,val))

# greet_me(name='a')

#3 使用 args 和 *kwargs 来调用函数
# def test_args_kwargs(arg1, arg2, arg3):
#     print("arg1:", arg1)
#     print("arg2:", arg2)
#     print("arg3:", arg3)

# args=("two",3,5)
# test_args_kwargs(*args)

# kwargs={"arg3":3, "arg2":"two", "arg1":5}
# test_args_kwargs(**kwargs)

# 标准参数与*args、**kwargs在使用时的顺序
# 在函数里同时使用所有这三种参数， 顺序是这样的：
# some_func(fargs, *args, **kwargs)

#4 啥时候使用它们
# 看需求而定。最常见用例:在写函数装饰器的时候（会在另一章里讨论）。
# 可用来做猴子补丁(monkey patching)。猴子补丁:在程序运行时(runtime)修改某些代码。

#002 调试 Debugging
#1 从命令行运行
# python -m pdb my_script.py

#2 从脚本内部运行
# 可在脚本内部设置断点，在某些特定点查看变量和各种执行时信息
#2.1 命令列表：
# c: 继续执行
# w: 显示当前正在执行的代码行的上下文信息
# a: 打印当前函数的参数列表
# s: 执行当前代码行，并停在第一个能停的地方（相当于单步进入）
# n: 继续执行到当前函数的下一行，或者当前行直接返回（单步跳过）
#2.2 
# 单步进入s: 进入当前行调用的函数内部并停在里面
# 单步跳过n: 全速执行完当前行调用的函数，并停在当前函数的下一行

# import pdb

# def make_bread():
#     pdb.set_trace()
#     return "I don't have time"

# print(make_bread())

#3 生成器 Generators
# 首先要理解迭代器(iterators):一个遍历一个容器（特别是列表）的对象。
# 然而，迭代器在遍历并读取容器的数据元素时，不会执行一个迭代。
#3.1 可迭代对象(Iterable)
# Python中任意的对象，只要它定义了可返回一个迭代器的__iter__方法，或定义了支持下标索引的__getitem__方法，它就是一个可迭代对象。
# 可迭代对象:能提供迭代器的任意对象
#3.2 迭代器(Iterator)
# 迭代器： 定义了next(Python2)或__next__方法的任意对象
#3.3 迭代(Iteration)
# 从某个地方（比如一个列表）取出一个元素的过程。
# 当使用一个循环来遍历某个东西时，这个过程就叫迭代。
#3.4 生成器(Generators)
# 生成器也是一种迭代器，但是你只能对其迭代一次。--> 这是因为它们并没有把所有的值存在内存中，而是在运行时生成值。
# 你通过遍历来使用它们，要么用一个“for”循环，要么将它们传递给任意可以进行迭代的函数和结构。
# 大多数时候生成器是以函数来实现的。然而，它们并不返回一个值，而是yield(暂且译作“生出”)一个值。
# 生成器最佳应用场景：不想同一时间,将所有计算出来的大量结果集分配到内存中，特别是结果集里还包含循环。

# 许多Python 2里的标准库函数都会返回列表，而Python 3都修改成了返回生成器，因为生成器占用更少的资源。

# 内置函数next(): 获取一个序列的下一个元素。
# 内置函数iter(): 根据一个可迭代对象返回一个迭代器对象

# def generator_func():
#     for i in range(6):
#         yield i
# for item in generator_func():
#     print(item)

# def fibon(n):
#     a=b=1
#     for i in range(n):
#         yield a
#         a,b=b,a+b
# for x in fibon(10):
#     print(x)

# def generator_func():
#     for i in range(3):
#         yield i
# gen=generator_func()
# print(next(gen))
# print(next(gen))
# print(next(gen))
# print(next(gen))

# mystr="123abc"
# myiter=iter(mystr)
# print(next(myiter))


#004 Map，Filter 和 Reduce 三个函数为函数式编程提供便利
#4.1 Map将一个函数映射到一个输入列表的所有元素上。
#规范   map(function_to_apply, list_of_inputs)
#4.2 大多数时候，要把列表中所有元素逐个地传递给一个函数(一列表的函数)，并收集输出。
# items=[1,2,3,4,5]
# squared=[]
# for i in items:
#     squared.append(i**2)
## squared=list(map(lambda x:x**2,items))
# print("squared={}".format(squared))

# def mul(x):
#     return (x*x)

# def add(x):
#     return (x+x)

# funcs=[mul,add]
# for i in range(5):
#     val=map(lambda x:x(i),funcs)
#     print(list(val))

#4.3 Filter
# filter:过滤列表中的元素，并返回一个由所有符合要求的元素所构成的列表. 符合要求: 即函数映射到该元素时,返回True. 
# filter类似于for循环，是一个内置函数，并且更快。
# 优雅的话，可以看看另外一章：列表/字典/元组推导式。

# num_list=range(-5,5)
# less_zero=filter(lambda x: x<0,num_list)
# print(list(less_zero))

#4.4 Reduce
# 当需要对一个列表进行一些计算并返回结果时，Reduce非常有用
# 可能会用for循环

# from functools import reduce
# product=reduce((lambda x,y: x*y),[1,2,3,4,5])
# print("product={}".format(product))

#5 set 数据结构
# 与列表(list)的行为类似，区别在于set不能包含重复的值。
# 检查列表中是否包含重复的元素:for循环,更简单更优雅set

# some_list=['a', 'b', 'c', 'b', 'd', 'm', 'n', 'n']
# duplicates=[]
# for val in some_list:
#     if some_list.count(val) > 1:
#         if val not in duplicates:
#             duplicates.append(val)
## duplicates=set([x for x in some_list if some_list.count(x) > 1])
# print("duplicates={}".format(duplicates))

# valid=set(['yellow', 'red', 'blue', 'green', 'black'])
# input_set=set(['red','brown'])
# print(input_set.intersection(valid))
# print(input_set.difference(valid))

# a_set={'red','blue','green'}
# print(type(a_set))

#6 三元运算符 条件表达式
# is_fat=True
# state = "fat" if is_fat else "not fat"
# print("Ali is ",state)

#007 装饰器
# 简单地说：他们是修改其他函数的功能的函数。他们有助于让代码更简短，也更Pythonic（Python范儿）。
#7.1 一切皆对象
# def hi(name="bob"):
#     return "hi "+name
# print(hi())
# greet=hi
# print(greet())
# del hi
# print(hi())
# print(greet())

#7.2 在函数中定义函数 --> 可以创建嵌套的函数
# def hi(name="abcd"):
#     print("inside hi() function")
#     def greet():
#         return "in greet() function"
#     def welcome():
#         return "in welcome function"    
#     print(greet())
#     print(welcome())
#     print("back in hi() function")
# hi()

#7.3 从函数中返回函数
# 在if/else语句中,返回greet和welcome，而不是greet()和welcome()。
# 这是因为把小括号放在后面，函数就会执行；如果后面不放括号，那它可被到处传递，并且可赋值给别的变量而不去执行它。
# def hi(name="abcd"):
#     def greet():
#         return "in greet() function"
#     def welcome():
#         return "in welcome function"  
#     if name=="abcd":
#         return greet
#     else:
#         return welcome    
# a=hi()
# print(a)
# print(a())

#7.4 将函数作为参数传给另一个函数
# def hi():
#     return "hi abcd!"
# def doSthBeforeHi(func):
#     print("do sth before hi()")
#     print(func())
# doSthBeforeHi(hi)

#7.5 你的第一个装饰器
# 装饰器做的事情: 封装一个函数，并用各种方式来修改它的行为。
# @符号: 只是一个简短的方式，生成一个被装饰的函数。
# @wraps接受一个函数来进行装饰，并加入了复制函数名称、注释文档、参数列表等功能。这可在装饰器中访问装饰之前的函数属性
# def a_new_decorator(a_func):
#     def warpTheFunction():
#         print("before a_func()")
#         a_func()
#         print("after a_func()")
#     return warpTheFunction
# def function_need_decorate():
#     print("a function need decorate")
# @a_new_decorator
# def function_need_decorate():
#     print("a function need decorate")

# function_need_decorate()
# print("------------")
# function_need_decorate=a_new_decorator(function_need_decorate)
# function_need_decorate()

# from functools import wraps

# def a_new_decorator(a_func):
#     @wraps(a_func)
#     def warpTheFunction():
#         print("before a_func()")
#         a_func()
#         print("after a_func()")        
#     return warpTheFunction

# @a_new_decorator
# def function_need_decorate():
#     print("a function need decorate")

# print(function_need_decorate.__name__)

#蓝本规范:
# from functools import wraps
# def decorator_name(f):
#     @wraps(f)
#     def decorated(*args, **kwargs):
#         if not can_run:
#             return "Function will not run"
#         return f(*args, **kwargs)
#     return decorated

# @decorator_name
# def func():
#     return("Function is running")

# can_run = True
# print(func())
# # Output: Function is running

# can_run = False
# print(func())
# # Output: Function will not run

#7.6 使用场景：授权
# from functools import wraps
# def requires_auth(f):
#     @warps(f)
#     def decorated(*args,**kwargs)
#         auth=request.authorization
#         if not auth or not check_auth(auth.username,auth.password):
#             authenticate()
#         return f(*args,**kwargs)    
#     return decorated

#7.7 使用场景：日志
# from functools import wraps
# def logit(func):
#     @wraps(func)
#     def with_logging(*args,**kwargs):
#         print(func.__name__+" was called")
#         return func(*args,**kwargs)
#     return with_logging    

# @logit
# def addition_func(x):
#     return x+x

# res=addition_func(4)
# print("res=",res)

#7.8 带参数的装饰器
# 使用@my_decorator语法时，是在应用一个,以单个函数作为参数,的一个包裹函数。
#7.8.1 在函数中嵌入装饰器
# from functools import wraps
# def logit(logfile='out.log'):
#     def logging_decorator(func):
#         @wraps(func)
#         def wrapped_function(*args, **kwargs):
#             log_string = func.__name__ + " was called"
#             print(log_string)
#             # 打开logfile，并写入内容
#             with open(logfile, 'a') as opened_file:
#                 # 现在将日志打到指定的logfile
#                 opened_file.write(log_string + '\n')
#             return func(*args, **kwargs)
#         return wrapped_function
#     return logging_decorator

# @logit()
# def myfunc1():
#     pass

# myfunc1()
# # Output: myfunc1 was called
# # 现在一个叫做 out.log 的文件出现了，里面的内容就是上面的字符串

# @logit(logfile='func2.log')
# def myfunc2():
#     pass

# myfunc2()
# # Output: myfunc2 was called
# # 现在一个叫做 func2.log 的文件出现了，里面的内容就是上面的字符串

#7.8.2 装饰器类
# 只想打日志到一个文件。想把问题发送到一个email，同时也保留日志，留个记录。这是一个使用继承的场景
# from functools import wraps
# class logit(object):
#     def __init__(self, logfile='out.log'):
#         self.logfile = logfile

#     def __call__(self, func):
#         @wraps(func)
#         def wrapped_function(*args, **kwargs):
#             log_string = func.__name__ + " was called"
#             print(log_string)
#             with open(self.logfile, 'a') as opened_file:
#                 opened_file.write(log_string + '\n')
#             self.notify()       # 现在，发送一个通知
#             return func(*args, **kwargs)
#         return wrapped_function

#     def notify(self):
#         pass        # logit只打日志，不做别的

# @logit()
# def myfunc1():
#     pass

# class email_logit(logit):
#     def __init__(self, email='admin@myproject.com', *args, **kwargs):
#         self.email = email
#         super(email_logit, self).__init__(*args, **kwargs)

#     def notify(self):
#         # 发送一封email到self.email
#         # 这里就不做实现了
#         pass

#008 Global和Return
# global变量意味着,可在函数外的区域访问这个变量
# 实际的编程时，应避开global关键字，因为它引入了多余的变量到全局作用域
# def add(val1,val2):
#     #ret变量只能在创建它的函数内部才允许访问，除非它是全局的(global)。
#     global ret
#     ret=val1+val2
# add(2,4)
# print("ret=",ret)

#8.1 多个return值
# 在函数结束时，返回一个包含多个值的tuple(元组)，list(列表)或者dict(字典)
# def profile():
#     name="abcd"
#     age=30
#     # return (name,age)
#     return name, age
# profile_data=profile()
# print(profile_data[0])
# print(profile_data[1])

#009 对象变动 Mutation
# 可变(mutable)与不可变(immutable)的数据类型让新手很是头痛
# 可变(mutable)意味着"可以被改动"，而不可变(immutable)的意思是“常量(constant)”。
#9.1 
# 这是对象可变性(mutability)在作怪。
# 将一个变量赋值为另一个可变类型的变量时，对这个数据的任意改动,会同时反映到这两个变量上
# 新变量只是老变量的一个别名
# foo=['hi']
# print('foo=',foo)

# bar=foo
# bar += ['bye']
# print('foo=',foo)

#9.2
# 定义Python函数时，默认参数只会运算一次，而不是每次被调用时都会重新运算。
# 你永远不要定义可变类型的默认参数，除非你知道你正在做什么。
# def add_to(num,target=[]):
#     target.append(num)
#     return target
# print(add_to(1))
# print(add_to(2))
# print(add_to(3))

# def add_to(element,target=None):
#     if target is None:
#         target=[]
#     target.append(element)
#     return target  
# print(add_to(1))
# print(add_to(2))
# print(add_to(3))

#010 slots魔法
# 在Python中，每个类都有实例属性。默认,用字典保存对象的实例属性。这非常有用，因为它允许在运行时设置任意的新属性。
# 然而，对于有已知属性的小类，它可能是个瓶颈。这个字典浪费了很多内存。
# Python不能在对象创建时,直接分配固定量的内存,来保存所有的属性。
# 使用__slots__来告诉Python不要使用字典，而且只给一个固定集合的属性分配空间。

#011 虚拟环境 Virtualenv
#1 Virtualenv 是一个工具，它能创建一个独立(隔离)的Python环境。
#2 针对每个程序创建独立（隔离）的Python环境，而不是在全局安装所依赖的模块。
#3 在创建virtualenv时，必须选择：这个virtualenv是使用系统全局的模块，还是只使用这个virtualenv内的模块。
# 默认情况下，virtualenv不会使用系统全局模块。

#012 容器 Collections
# Python附带一个模块，它包含许多容器数据类型，名字叫作collections

#12.1 defaultdict
# 与dict类型不同，你不需要检查key是否存在
# 在字典中对一个键进行嵌套赋值时，这个键若不存在，会触发keyError异常。 defaultdict用一个聪明的方式绕过这个问题
#12.2 counter
# Counter是一个计数器,针对某项数据进行计数
#12.3 deque
# 用法像python的list，并提供了类似的方法
# 双端队列，可从头/尾两端添加或删除元素。
# 可以限制这个列表的大小，当超出设定的限制时，数据会从对队列另一端被挤出(pop)。
#12.4 namedtuple
# 元组是不可变的列表，可存储数据序列，它和命名元组(namedtuples)非常像，但有几个关键的不同.
#1 主要相似点: 都不像列表，不能修改元组中的数据。为获取元组中的数据，你需要使用整数作为索引.
#2 namedtuples是什么呢？它把元组变成,针对简单任务的容器。
#(1) 可像字典(dict)一样访问namedtuples，但namedtuples不可变 --> 属性值在namedtuple中不可变
#(2) 可用名字来访问namedtuple中的数据.有两个必需的参数: 元组名称和字段名称。
#(3) namedtuple的每个实例没有对象字典，所以它们很轻量，不需要更多的内存。这使它们比字典更快。
#(4) 应该使用命名元组来让代码自文档，它们向后兼容于普通的元组，这意味着你可以既使用整数索引，也可以使用名称来访问namedtuple
#12.5 enum.Enum
# 另一个有用的容器是枚举对象，它属于enum模块.Enums(枚举类型)是一种组织各种东西的方式。

# from collections import defaultdict
# from collections import Counter
# colors = (
#     ('a','Yellow'),
#     ('b','Blue'),
#     ('c','Green'),
#     ('b','Black'),
#     ('a','Red'),
#     ('d','Silver')
# )
# favourite_colors=defaultdict(list)
# for name,color in colors:
#     favourite_colors[name].append(color)
# print(favourite_colors)
# favs=Counter(name for name,color in colors)
# print("type(favs)=",type(favs))
# print(favs)

# import collections
# import json
# tree = lambda: collections.defaultdict(tree)
# print("type_tree=",type(tree)) #<class 'function'>
# some_dict=tree()
# some_dict['colors']['favourite']="yellow"
# print(json.dumps(some_dict))

# from collections import Counter
# with open('test_Counter.txt','rb') as f:
#     line_cnt=Counter(f)
# print(line_cnt)

# from collections import deque
# d=deque()
# d.append('1')
# d.append('2')
# d.append('3')
# print("len(d)=",len(d))
# print("d[0]=",d[0]) #1
# print("d[-1]=",d[-1])#3

# d=deque(range(5))
# print("len(d)=",len(d))
# print(d.popleft()) #0
# print(d.pop()) #4
# print(d)

# d = deque(maxlen=3)
# d.append('1')
# d.append('2')
# d.append('3')
# d.append('4')
# print(d) #deque(['2', '3', '4'], maxlen=3)

# d=deque([1,2,3,4,5])
# d.extendleft([0])
# print(d)
# d.extend([6,7,8])
# print(d)

# man=('a',30)
# print("man[0]=",man[0])

# from collections import namedtuple
# Animal=namedtuple('Animal','name age type')
# perry=Animal(name='perry',age=31,type='cat')
# print(perry)
# print(perry.name)
# print(perry[0]) #perry
# print(perry[1]) #31
# print(perry[2]) #cat
# print(perry._asdict())

# from collections import namedtuple
# from enum import Enum
# class Species(Enum):
#     cat = 1
#     dog = 2
#     horse = 3
#     aardvark = 4
#     butterfly = 5
#     owl = 6
#     platypus = 7
#     dragon = 8
#     unicorn = 9

#     # 但我们并不想关心同一物种的年龄，所以我们可以使用一个别名
#     kitten = 1  # (译者注：幼小的猫咪)
#     puppy = 2   # (译者注：幼小的狗狗)

# Animal = namedtuple('Animal', 'name age type')
# perry = Animal(name="Perry", age=31, type=Species.cat)
# drogon = Animal(name="Drogon", age=4, type=Species.dragon)
# tom = Animal(name="Tom", age=75, type=Species.cat)
# charlie = Animal(name="Charlie", age=2, type=Species.kitten)

# # print(charlie.type==tom.type)
# # print(charlie.type)
# print(Species(1))
# print(Species['cat'])
# print(Species.cat)

#013 枚举 Enumerate
# 遍历数据并自动计数
# enumerate也接受一些可选参数，定制从哪个数字开始枚举
# 还可用来创建包含索引的元组列表

# some_list=['a', 'b', 'c', 'b', 'd', 'm', 'n', 'n']
# # for cnt,val in enumerate(some_list):
# for cnt,val in enumerate(some_list,5):
#     print(cnt,val)
# cnt_list=list(enumerate(some_list,1))
# print(cnt_list)

#014 对象自省
# 自省(introspection): 运行时来判断一个对象的类型。它是Python的强项之一。
# Python中,一切都是一个对象，而且可仔细勘察那些对象。

#14.1 dir
# 它返回一个列表，列出一个对象拥有的属性和方法。
# 运行dir()不传入参数，返回当前作用域的所有名字。
# l1=[1,2,3]
# print(dir(l1))

#14.2 type和id
# type函数返回一个对象的类型。
# id()函数返回任意不同种类对象的唯一ID
# print(type(''))
# print(type([]))
# print(type({}))
# print(type(dict))
# print(type(3))
# name="abcd"
# print(id(name))

#14.3 inspect模块
# inspect模块获取活跃对象的信息.
# import inspect
# print(inspect.getmembers(str))

#015 推导式 Comprehension
# 推导式（又称解析式是Python的一种独有特性。可从一个数据序列构建另一个新的数据序列的结构体。
#15.1 列表推导式 又称列表解析式
# 结构是在一个中括号里包含一个表达式，然后是一个for语句，然后是0个或多个for或者if语句。
# 那个表达式是任意的，可在列表中放入任意类型的对象。
# 这将对快速生成列表非常有用。
# 有些人甚至更喜欢使用它而不是filter函数。
# 列表推导式在有些情况下超赞，特别是用for循环生成一个新列表。

# multiples=[i for i in range(30) if i%3 is 0]
# print(multiples)

# squared=[]
# for x in range(10):
#     squared.append(x**2)
# squared=[x**2 for x in range(10)]
# print(squared)

#15.2 字典推导式
# 字典推导和列表推导的使用方法类似
# mcase={'a':10,'b':34,'A':7,'Z':3}
# mcase_freq={k.lower(): mcase.get(k.lower(),0) + mcase.get(k.upper(),0) for k in mcase.keys()}
# print(mcase_freq)

# mcase={'a':10,'b':34,'A':7,'Z':3}
# dict_new={v:k for k,v in mcase.items()}
# print(dict_new)

#15.3 集合推导式
# 跟列表推导式也是类似的。 唯一的区别,它们使用大括号{}。
# squared = {x**2 for x in [1, 1, 2]}
# print(squared)

#016 异常
# try/except从句。可能触发异常的代码放到try语句块，而处理异常的代码在except语句块里实现。
#16.1 处理多个异常
# 第1种方法: 把所有可能发生的异常放到一个元组里。
# 第2种方法: 对每个单独的异常在单独的except语句块中处理
# 第3种方法: 捕获所有异常

# try:
#     file = open('test.txt', 'rb')
# except (IOError, EOFError) as e:
#     print("An error occurred. {}".format(e.args[-1]))

# try:
#     file = open('test.txt', 'rb')
# except EOFError as e:
#     print("An EOF error occurred.")
#     raise e
# except IOError as e:
#     print("An error occurred.")
#     raise e

# try:
#     file = open('test.txt', 'rb')
# except Exception:
#     # 打印一些异常日志，如果你想要的话
#     raise

#16.2 finally从句
# 主程序代码包裹进try从句。一些代码包裹进except从句，它会在try从句中的代码触发异常时执行。
# 第三个从句finally从句。包裹到finally从句中的代码,不管异常是否触发都将会被执行。在脚本执行之后清理工作。
# try:
#     file = open('test.txt', 'rb')
# except IOError as e:
#     print('An IOError occurred. {}'.format(e.args[-1]))
# finally:
#     print("This would be printed whether or not an exception occurred!")

#16.3 try/else从句
# 想在没有触发异常时,执行一些代码。使用一个else从句
# 大多数人并不使用else从句，我自己也没有大范围使用。
# else从句只会在无异常时执行，它会在finally语句之前执行。
# try:
#     print('I am sure no exception is going to occur!')
# except Exception:
#     print('exception')
# else:
#     # 这里的代码只会在try语句里没有触发异常时运行,
#     # 但是这里的异常将 *不会* 被捕获
#     print('This would only run if no exception occurs. And an error here '
#           'would NOT be caught.')
# finally:
#     print('This would be printed in every case.')

#017 lambda表达式
# lambda表达式是一行函数。被称为匿名函数。
#lambda 参数:操作(参数)
# add=lambda x,y: x+y
# print(add(3,5))

# a = [(1, 2), (4, 1), (9, 10), (13, -3)]
# a.sort(key=lambda x: x[1])
# print(a)

#列表并行排序
# l1=[1,3,2,4]
# l2=[10,36,18,20]
# data=zip(l1,l2)
# data=sorted(data)
# l1,l2=map(lambda t: list(t),zip(*data))
# print("l1=",l1)
# print("l2=",l2)

#018 一行式
# 漂亮的打印,可以在Python REPL漂亮的打印出列表和字典
# from pprint import pprint
# my_dict={'name': 'Yasoob', 'age': 'undefined', 'personality': 'awesome'}
# print(my_dict)

# 快速漂亮的从文件打印出json数据
# cat file.json | python -m json.tool

# 脚本性能分析 这可能在定位你的脚本中的性能瓶颈时，会非常奏效：
# python -m cProfile my_script.py

# CSV转换为json
# python -c "import csv,json;print json.dumps(list(csv.reader(open('csv_file.csv'))))"

# 列表辗平
# import itertools
# list1=[[1,2],[3,4],[5,6]]
# print(list(itertools.chain.from_iterable(list1)))

# 一行式的构造器,避免类初始化时大量重复的赋值语句
# class A(object):
#     def __init__(self, a, b, c, d, e, f):
#         self.__dict__.update({k: v for k, v in locals().items() if k != 'self'})

#019 For - Else
# fruits = ['apple', 'banana', 'mango']
# for fruit in fruits:
#     print(fruit.capitalize())
#19.1 else语句
# 有个常见的构造是跑一个循环，并查找一个元素。当元素被找到或循环结束，循环完成。
# 想知道哪一个才是，导致循环完成的原因。一个方法是先设置一个标记，然后在循环结束时打上标记。另一个是使用else从句。
# 这就是for/else循环的基本结构：
# for item in container:
#     if search_something(item):
#         # Found it!
#         process(item)
#         break
# else:
#     # Didn't find anything..
#     not_found_in_container()

# for n in range(2,10):
#     for x in range(2,n):
#         if n%x == 0:
#             print(n,'==',x,'*',n/x)
#             break
#         else:
#             print(n,'is a prime number')    

#020 使用C扩展
#1 有三种方法可在Python中调用C函数-ctypes，SWIG，Python/C API。每种方式各有利弊。
#2 为什么要在Python中调用C？
#(1) 提升代码运行速度，C比Python快50倍以上
#(2) C有很多传统类库，而且有些正是你想要的，但你又不想用Python去重写
#(3) 想访问,从内存到文件接口这样的底层资源

#20.1 CTypes
# ctypes模块提供了和C兼容的数据类型和函数来加载dll/so文件，调用时无需修改源文件
# 虽简单清晰，却很受限。例如，不能在C中操作对象。
#20.2 SWIG --> Simplified Wrapper and Interface Generator
# 在这个方法中，必须写一个额外的接口文件作为SWIG(终端工具)的入口。
# 一般不会采用，因为大多数会带来不必要的复杂。而当你有一个C/C++代码库需要被多种语言调用时，这将是个非常不错的选择。
#20.3 Python/C API
# 最广泛使用的方法。不仅简单，而且可在C代码中操作Python对象。
# 需要以特定的方式编写C代码以供Python去调用它。Python对象都被表示为叫做PyObject的结构体，Python.h中提供了各种操作它的函数。
# 大部分对Python原生对象的基础函数和操作在Python.h中都能找到。
# 这种方法看似复杂，一旦习惯，将变的非常有效。
# Python调用C代码的另一种方式,用Cython让Python编译的更快。

#021 open函数
# 为确保不管异常是否触发，文件都能关闭，将其包裹成with语句:
# with open('photo.jpg', 'r+') as f:
#     jpgdata = f.read()
#21.1 open的第一个参数是文件名。第二个(mode 打开模式)决定了这个文件如何被打开。
# r :读取文件
# r+:读取并写入
# w :覆盖写入
# a :在文件末尾附加
#21.2 以二进制模式来打开:在mode字符串后加一个b
# 以文本模式打开,还必须知道要用哪种编码。对于计算机来说，文件都是字节，而不是字符。
# 没有检测编码的简单方式。不同的编码中，同样的字节，可表示不同、但同样有效的字符。
# 文件格式将编码定义成UTF-8

# import io
# with open('test0.jpg', 'rb') as inf:
#     jpgdata = inf.read()

# if jpgdata.startswith(b'\xff\xd8'):
#     text = u'This is a JPEG file (%d bytes long)\n'
# else:
#     text = u'This is a random file (%d bytes long)\n'

# with io.open('summary.txt', 'w', encoding='utf-8') as outf:
#     outf.write(text % len(jpgdata))

#024 函数缓存
# 函数缓存允许,将函数对于给定参数的返回值缓存起来。
# 当一个I/O密集的函数,被相同的参数频繁调用，函数缓存可节约时间。
# 有个lru_cache的装饰器，将函数的返回值快速缓存或取消缓存。
# maxsize参数是告诉lru_cache，最多缓存最近多少个返回值。

# from functools import lru_cache
# @lru_cache(maxsize=32)
# def fib(n):
#     if n<2:
#         return n
#     return fib(n-1)+fib(n-2)    
# ret_list=list(fib(n) for n in range(10))
# print(ret_list)
# fib.cache_clear()

#025 上下文管理器
# 上下文管理器允许，精确地分配和释放资源。
# 使用上下文管理器最广泛的就是with语句。
# 有两个需要结对执行操作，还要在它们中间放置一段代码。上下文管理器就是专门让你做这种事情的。
# with语句的主要优势，确保文件会被关闭，不用关注嵌套代码如何退出。
# 一个常见用例，是资源的加锁和解锁，以及关闭已打开的文件

#25.1 基于类的实现
# 一个上下文管理器的类，最起码要定义__enter__和__exit__方法。
# 构造我们自己的开启文件的上下文管理器:
# class File(object):
#     def __init__(self,file_name,method):
#         self.file_obj=open(file_name,method)
#     def __enter__(self): 
#         return self.file_obj
#     def __exit__(self,type,value,traceback):
#         print("Exception has been handled")
#         self.file_obj.close()
#         return True #返回了True,因此没有异常会被with语句抛出。

# with File('demo.txt','w') as opened_file:
#     opened_file.write('Hola!')

#25.2 处理异常
#25.2.1 
#(1) with语句先暂存了File类的__exit__方法
#(2) 然后它调用File类的__enter__方法
#(3) __enter__方法打开文件并返回给with语句
#(4) 打开的文件句柄被传递给opened_file参数
#(5) 我们使用.write()来写文件
#(6) with语句调用之前暂存的__exit__方法
#(7) __exit__方法关闭了文件
# 在第4步和第6步之间，如果发生异常，会将异常的type,value和traceback传递给__exit__方法。它让__exit__方法来决定如何关闭文件以及是否需要其他步骤。
# with File('demo.txt', 'w') as opened_file:
#     opened_file.undefined_function('Hola!')

#25.3 基于生成器的实现
# 还可用装饰器(decorators)和生成器(generators)来实现上下文管理器。
# contextlib模块专门用于这个目的。可用生成器函数来实现上下文管理器，而不是使用类。
# from contextlib import contextmanager
# @contextmanager
# def open_file(name):
#     f=open(name,'w')
#     yield f
#     f.close()

# with open_file('some_file.txt') as f:
#     f.write('hola!')










