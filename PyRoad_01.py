

#01_02
# print(all([1,0,3,6])) #False
# print(all([1,2,3]))   #True

#01_03
# print(any([0,0,[]])) #False
# print(any([0,0,1]))  #True

#01_04 ascii展示对象
# 调用对象的__repr__() 方法，获得该方法的返回值，如下例子返回值为字符串:
# class Stu():
#     def __init__(self,id,name):
#         self.id=id
#         self.name=name
#     def __repr__(self):
#         return 'id= ' + self.id + ', name= ' + self.name
#     def __call__(self):
#         print('I can be called')
#         print('my name is',self.name)

# xm=Stu(id='001',name='xiaoming')
# print(xm)
# print(ascii(xm))

#01_08
# print(bool([0,0,0]))
# print(bool([])) #False
# print(bool([1,0,1]))

#01_09
# s="abcd"
# print(bytes(s,encoding='utf-8'))

#01_10
# i=10
# print(str(i))

#01_11 是否可被调用
# 判断对象是否可被调用，能被调用的对象就是一个callable 对象
# print(callable(str))
# print(callable(int))
# xm=Stu(id='001',name='xiaoming')
# print(callable(xm))

#01_14 静态方法
#classmethod 装饰器对应的函数无需实例化，无需self参数，但第一个参数需要是表示自身类的 cls 参数，可调用类的属性，类的方法，实例化对象等。
# class Stu():
#     def __init__(self,id,name):
#         self.id=id
#         self.name=name
#     def __repr__(self):
#         return 'id= ' + self.id + ', name= ' + self.name
#     @classmethod
#     def f(cls):
#         print(cls)

# xm=Stu(id='001',name='xiaoming')

#01_15 执行字符串表示的代码
# 将字符串编译成python能识别或可执行的代码，也可以将文字读成字符串再编译。
# s  = "print('hello world')"
# r = compile(s,"<string>", "exec")
# print(r)
# exec(r)

#01_18 转为字典
# print(dict())
# print(dict(a='12ab',b='34cd'))
# print(dict(zip(['a','b'],[1,2])))
# print(dict([('a',1),('b',2)]))

#01_20 分别取商和余数
# a=divmod(11,3) #tuple
# print(a)

#01_21 返回一个可以枚举的对象，该对象的next()方法将返回一个元组。
# s=['a','b','c']
# for i,v in enumerate(s,1):
#     print(i,v)

#01_22 计算表达式
# 将字符串str 当成有效的表达式来求值并返回计算结果取出字符串中内容
# s='1+3+5'
# ret=eval(s)
# print(ret)

#01_23 查看变量所占字节数
# import sys
# a = {'a':1,'b':2.0}
# print(sys.getsizeof(a)) #248
# print(sys.getsizeof(a['a'])) #28
# print(sys.getsizeof(a['b'])) #24

#01_24 过滤器
# 在函数中设定过滤条件，迭代元素，保留返回值为True的元素：
# a=filter(lambda x: x>10,[1,11,2,45,7,6,13])
# print(list(a))

#01_25 转为浮点类型
# print(float(3))

#01_26 字符串格式化　
# 格式化输出字符串，format(value, format_spec)实质上是调用了value的__format__(format_spec)方法。
# print("i am {0}, age{1}".format("tom",18))

#01_28 动态获取对象属性　
# class Stu():
#     def __init__(self,id,name):
#         self.id=id
#         self.name=name
#     def __repr__(self):
#         return 'id= ' + self.id + ', name= ' + self.name

# xm=Stu(id='001',name='xiaoming')
# # xm_attr=getattr(xm,'name')
# xm_attr=xm.name
# print(xm_attr)

#01_29 对象是否有这个属性
# b1=hasattr(xm,'name')
# b2=hasattr(xm,'address')
# print('b1=',b1)
# print('b2=',b2)

#01_30 返回对象的哈希值
# 自定义的实例都是可哈希的，list, dict, set等可变对象都是不可哈希的(unhashable)

#01_31 一键帮助
# help(Stu)

#01_32 返回对象的内存地址
# l1=[1,2,3]
# print(id(l1))

#01_33 获取用户输入内容
# print('Input a: ')
# a=input()
# print('a=',a)

#01_34 转为整型
# print(int('11',2)) #3
# print(int('11',8)) #9
# print(int('11',16))#17

#01_35 isinstance
# 判断object是否为类classinfo的实例，是返回true

#01_37 创建迭代器类型
# 使用iter(obj, sentinel), 返回一个可迭代对象.sentinel可省略(一旦迭代到此元素，立即终止)
# lst=[1,3,5]
# for i in iter(lst):
#     print(i)

# class TestIter(object):
#     def __init__(self):
#         self.l=[1,3,2,3,4,5]
#         self.i=iter(self.l)
#     def __call__(self):
#         item=next(self.i)
#         print("__call__ is called, which would return",item)
#         return item
#     def __iter__(self):
#         print ("__iter__ is called!!")
#         return iter(self.l)

# t=TestIter() #因为实现了__call__，所以t实例能被调用
# print(t())
# for e in TestIter(): #因为实现了__iter__方法，所以t能被迭代
#     print(e)

#01_38 所有对象之根
# object 是所有类的基类
# print(type(object()))

#01_40 base为底的exp次幂，如果mod给出，取余
# a=pow(3,2,4)
# print('a=',a)

#01_41 打印
# lst=[1,3,5]
# print(lst)
# print(f'lst={lst}')
# print('lst={}'.format(lst))
# print('lst=',lst)

#01_42 创建属性的两种方式
#1 返回 property 属性，典型的用法：
# class C:
#     def __init__(self):
#         self._x=None
#     def getx(self):
#         return self._x
#     def setx(self,val):
#         self._x=val
#     def delx(self):
#         def self._x
#     x=property(getx,setx,delx,"I'm the 'x' property.")   # 使用property类创建 property 属性

#2 使用python装饰器，实现与上完全一样的效果代码：
# class C:
#     def __init__(self):
#         self._x=None
#     @property
#     def x(self):
#         return self._x
#     @x.settter
#     def x(self,val):
#         self._x=val
#     @x.deleter
#     def x(self):
#         def self._x    

#01_43 创建range序列
# range(stop)
# range(start, stop[,step])
# a=range(11) #list
# print(a)
# print(range(0,11,1))

#01_44 反向迭代器
# rev=reversed([1,2,3,4,5])
# for i in rev:
#     print(i)

#01_46 转为集合类型
# 返回一个set对象，集合内不允许有重复元素：
# a=[1,3,5,7,9]
# print(set(a))

#01_47 转为切片对象 --> class slice(start, stop[, step])
# 返回一个表示由 range(start, stop, step) 所指定索引集的 slice对象，它让代码可读性、可维护性变好。
# a=[1,2,3,4,5]
# my_slice=slice(0,5,2)
# print(a[my_slice])

#01_48 拿来就用的排序函数
# a=[1,4,2,3,1]
# b=sorted(a,reverse=True)
# print(a)
# print(b)

# a = [{'name':'xiaoming','age':18,'gender':'male'},
#      {'name':': xiaohong','age':20,'gender':'female'}]
# b=sorted(a,key=lambda x: x['age'],reverse=False)
# print(b)

#01_49 求和函数
# a=[1,3,5,7,9]
# print(sum(a)) #25
# print(sum(a,10)) #35

#01_50 转元组
# tuple() 将对象转为一个不可变的序列类型
# lst=[1,3,5]
# mytuple=tuple(lst)
# print(mytuple)

#01_51 查看对象类型 --> class type(name, bases, dict)
# 传入一个参数时，返回 object 的类型：
# class Stu():
#     def __init__(self,id,name):
#         self.id=id
#         self.name=name
#     def __repr__(self):
#         return 'id = '+ self.id + ', name = ' +self.name    
# xm=Stu(id='001',name='xiaoming')
# mytype=type(xm)
# print(mytype)
# print(tuple)
# print(tuple())

#01_52 聚合迭代器
# 创建一个来自每个可迭代对象中的元素的迭代器：
# x=[1,3,5]
# y=[2,4,6]
# print(list(zip(y,x)))

# a=range(5)
# b=list('abcde')
# c=[str(y)+str(x) for x,y in zip(a,b)]
# print(c)

#01_53 nonlocal用于内嵌函数中

#01_54 global 声明全局变量
# i=0
# def h():
#     global i
#     i += 1
# h()
# print('i=',i)    

#01_55 链式比较
# i = 3
# print(1 < i < 3)  # False
# print(1 < i <= 3)  # True

#01_56 不用else和if实现计算器
# from operator import *
# def calc(a,b,k):
#     return {
#         '+':add,
#         '-':sub,
#         '*':mul,
#         '/':truediv,
#         '**':pow,
#     }[k](a,b)
# print(calc(1,2,'+'))
# print(calc(3,4,'**'))

#01_58 交换两元素
# def myswap(a,b):
#     return b,a
# t= myswap(1,2) #tuple
# print(t)    

#01_59 去最求平均
# def score_mean(lst):
#     lst.sort()
#     print('lst =',lst)
#     lst2=lst[1:(len(lst)-1)]
#     print('lst2=',lst2)
#     return round((sum(lst2)/len(lst2)),1)
# lst=[9.1, 9.0, 8.1, 9.7, 19, 8.2, 8.6, 9.8]
# print(score_mean(lst)) # 9.1

#01_61 全展开
#实现flatten的递归版，两个参数分别表示待展开的数组，输出数组。
# from collections.abc import *
# def flatten(lst,out_lst=None):
#     if out_lst is None:
#         out_lst=[]
#     for i in lst:
#         if isinstance(i,Iterable):  
#             flatten(i,out_lst)
#         else:
#             out_lst.append(i)    
#     return out_lst
# print(flatten([[1,2,3],[4,5]]))
# print(flatten([[1,2,3],[4,5]], [6,7]))
# print(flatten([[[1,2,3],[4,5,6]]]))   

# numpy里的flatten与上面的函数实现有些微妙的不同：
# import numpy
# a=[[1,2,3],[4,5]]
# b=numpy.array(a)
# b.flatten()
# print('b=',b)

#01_62 列表等分
# from math import ceil
# def divide(lst, size):
#     if size <= 0:
#         return [lst]
#     return [lst[i * size:(i+1)*size] for i in range(0, ceil(len(lst) / size))]
# r1 = divide([1, 3, 5, 7, 9], 2)
# r2 = divide([1, 3, 5, 7, 9], 0)
# r3 = divide([1, 3, 5, 7, 9], -3)
# print('r1=',r1)
# print('r2=',r2)
# print('r3=',r3)

#01_63 列表压缩
# def filter_false(lst):
#     return list(filter(bool,lst))
# r = filter_false([None, 0, False, '', [], 'ok', [1, 2]])
# print(r)  # ['ok', [1, 2]]

#01_64 更长列表
# def max_length(*lst):
#     return max(*lst, key=lambda v:len(v)) #其中*的作用？
# r = max_length([1, 2, 3], [4, 5, 6, 7], [8])
# print(r)

#01_65 求众数
# def top1(lst):
#     return max(lst,default='list is empty.',key=lambda v: lst.count(v))
# lst = [1, 3, 3, 2, 1, 1, 2]
# r = top1(lst)
# print('r=',r)

#01_66 多表之最
# def max_lists(*lst):
#     return max(max(*lst,key=lambda v:max(v)))
# r=max_lists([1, 2, 3], [6, 7, 8], [4, 5])
# print('r=',r)

#01_67 列表查重
# def has_duplicates(lst):
#     return len(lst)==len(set(lst))
# x = [1, 1, 2, 2, 3, 2, 3, 4, 5, 6]
# y = [1, 2, 3, 4, 5]
# print(has_duplicates(x))  # False
# print(has_duplicates(y))  # True

#01_68 列表反转
# a=[1,2,3,4,5]
# b=a[::-1]
# print(b)

#01_70 按条件分组
# def bif_by(lst,f):
#     return [[x for x in lst if f(x)],[x for x in lst if not f(x)]]
# a=[25,89,31,34]
# b=bif_by(a,lambda x: x<80)
# print(b)

#01_71 map实现向量运算
# lst1=[1,3,5,7,9]
# lst2=[2,4,6,8,10]
# l3=list(map(lambda x,y:x*y+1,lst1,lst2))
# print(l3)

#01_72 值最大的字典
# def max_pairs(dic):
#     if len(dic)==0:
#         return dic
#     max_val=max(map(lambda v:v[1],dic.items()))   
#     return [item for item in dic.items() if item[1]==max_val] 
# r= max_pairs({'a': -10, 'b': 5, 'c': 3, 'd': 5})
# print('r=',r)

#01_73 合并两个字典
# def merge_dict(dic1, dic2):
#     return {**dic1, **dic2}  #  **作用？
# r=merge_dict({'a': 1, 'b': 2}, {'c': 3})  # {'a': 1, 'b': 2, 'c': 3}
# print('r=',r)

#01_74 topn字典
# from heapq import nlargest
# def topn_dict(d,n):
#     return nlargest(n,d,key=lambda k: d[k])
# r=topn_dict({'a': 10, 'b': 8, 'c': 9, 'd': 10}, 3)
# print('r=',r)

#01_76 逻辑上合并字典
#1 一般的字典合并写法
# dic1 = {'x': 1, 'y': 2 }
# dic2 = {'y': 3, 'z': 4 }
# dic3 = {**dic1, **dic2} # {'x': 1, 'y': 3, 'z': 4}
# print('dic3=',dic3)
# dic3['x']=10
# print('dic1=',dic1) #dic1中的x值不变，merged是重新生成的一个新字典。

#2 ChainMap却不同，它在内部创建了一个容纳这些字典的列表
# from collections import ChainMap
# dic4=ChainMap(dic1,dic2)
# print('dic4=',dic4)
# dic4['x']=10
# print('dic1=',dic1) #dic1中的x值改变

#01_77 命名元组提高可读性
# from collections import namedtuple
# Point = namedtuple('Point', ['x', 'y', 'z'])  # 定义名字为Point的元祖，字段属性有x,y,z
# lst = [Point(1.5, 2, 3.0), Point(-0.3, -1.0, 2.1), Point(1.3, 2.8, -2.5)]
# print(lst[0].y - lst[1].y)

#01_82 chain高效串联多个容器对象
# chain函数串联a和b，兼顾内存效率同时写法更加优雅。
# from itertools import chain
# a=[1,3,5]
# b=[2,4,6]
# c=chain(a,b)
# print(list(c))

#01_83 操作函数对象
# def f():
#     print('i\'m f')
# def g():
#     print('i\'m g')
# r=[f,g][1]()
# print('r=',r)

#01_84 生成逆序序列
# lst=list(range(10,3,-2))
# print(lst)

#01_85 函数的五类参数使用例子
# python五类参数：位置参数，关键字参数，默认参数，可变位置或关键字参数的使用。
#1
# def f(a,*b,c=10,**d):
#   print(f'a:{a}, b:{b}, c:{c}, d:{d}')
# f(1,2,5,width=10,height=20)

#2
# f(a=1,c=12)

#3
# from inspect import signature
# def f(*,a,**b):
#     print(f'a:{a},b:{b}')
# f(a=1,b=2)

#4
# for name,val in signature(f).parameters.items():
#     print(name,val.kind)

#5
# def f(a,**b):
#     print(f'a:{a},b:{b}')
# for name,val in signature(f).parameters.items():
#     print(name,val.kind)    

#01_86 使用slice对象
# cake1=list(range(15,0,-1))
# b=cake1[1:10:2] #下标1：10 step=2
# print('cake1=',cake1)
# print('b=',b)

# from random import randint
# cake2 = [randint(1,100) for _ in range(100)]
# d = cake2[1:10:2]
# print('d=',d)

# a1=[1,3,5,7,9,2,4,6,8]
# a2=a1[5:1:-1]
# b1=slice(5,1,-1)
# b2=a1[b1]
# print('a2=',a2)
# print('b2=',b2)



#二、Python字符串和正则

#02_01 反转字符串
# st="abcd"
# a=''.join(reversed(st))
# b=st[::-1]
# print('a=',a)
# print('b=',b)

#02_02 字符串切片 查找替换3或5的倍数
# st=[str("java"[i%3*4:] + "python"[i%5*6:] or i) for i in range(1,15)]
# print(st)

#02_03  join串联字符串
# st=['a','b','c','d']
# print('st=',st) # ['a','b','c','d']
# r=','.join(st) #用逗号连接字符串 --> a,b,c,d
# print('r=',r)

#02_04 字符串的字节长度
# def str_byte_len(mystr):
#     return len(mystr.encode('utf-8'))
# print(str_byte_len('abcd 123')) #8
# print(len('abcd 123')) #8

# import re
#02_05 查找第一个匹配串
# s='i love python very much.'
# pat='python'
# r=re.search(pat,s)
# rt=r.span() #tuple
# print(rt)
# print(type(rt))

#02_06 查找所有1的索引
# s = '山东省潍坊市青州第1中学高三1班'
# pat = '1'
# r = re.finditer(pat,s)
# print(type(r))
# for i in r:
#     print(i)

#02_07 \d 匹配数字[0-9]
# findall找出全部位置的所有匹配
# s = '一共20行代码运行时间13.59s'
# pat = r'\d+' # +表示匹配数字(\d表示数字的通用字符)1次或多次
# r = re.findall(pat,s)
# print(r)

#02_08 匹配浮点数和整数
# ?表示前一个字符匹配0或1次
# s = '一共5行代码运行时间13.59s'
# #pat = r'\d+\.?\d+' # ?表示匹配小数点(\.)0次或1次，这种写法有个小bug，不能匹配到个位数的整数
# pat = r'\d+\.\d+|\d+'
# r = re.findall(pat,s)
# print(r)

#02_09 ^匹配字符串的开头
# s2 = 'email for me is guozhennianhua@163.com'
# r=re.findall('^[emrt].*',s2)# 匹配以e,m,r,t开始的字符串，后面是多个任意字符
# print(r)

#02_10 re.I 忽略大小写
# s = 'That'
# pat = r't' 
# r = re.findall(pat,s,re.I)
# print(r)

#02_11 理解compile的作用
# 如果要做很多次匹配，可以先编译匹配串：
# pat = re.compile('\W+') # \W 匹配不是数字和字母的字符
# has_special_chars = pat.search('ed#2@edc') 
# print(type(has_special_chars))
# print(has_special_chars) #<re.Match object; span=(2, 3), match='#'>
# if has_special_chars:
#     print(f'str contains special characters:{has_special_chars.group(0)}')

# again_pattern = pat.findall('guozhennianhua@163.com')
# print(type(again_pattern))
# print(again_pattern) #['@', '.']
# if '@' in again_pattern:
#     print('possibly it is an email')

#02_12 使用()捕获单词，不想带空格
# s = 'This module provides regular expression matching operations similar to those found in Perl'
# pat = r'\s?([a-zA-Z]+)'  
# r = re.findall(pat,s)
# print(r)

#02_13 split分割单词
# s='This module 123 abcd.'
# pat=r'\s+'
# r=re.split(pat,s)
# print(r)

# s1=s.split(' ')
# print('s =',s) #s = This module 123 abcd.
# print('s1=',s1)#s1= ['This', 'module', '123', 'abcd.']

#02_14 match从字符串开始位置匹配
# 注意match,search等的不同：
# mystr='This'
# pat=re.compile('hi')
# r1=pat.match(mystr)
# r2=pat.match(mystr,1)
# print('r1=',r1)
# print('r2=',r2)

# mystr='This'
# pat=re.compile('hi')
# r1=pat.search(mystr)
# print('r1=',r1)

#02_15 替换匹配的子串
# sub函数实现对匹配子串的替换
# content="hello 123, world 456"
# pat=re.compile(r'\d+')
# m=pat.sub('666',content)
# print('m=',m)

#02_16 贪心捕获
# (.*)表示捕获任意多个字符，尽可能多的匹配字符
# content='abcd123#@456#def'
# # pat=re.compile(r'\d(.*)\W')
# pat=re.compile(r'\d(.?)\W') #非贪心捕获
# m=pat.findall(content)
# print('m=',m)

#02_18 常用元字符总结
# . 匹配任意字符  
# ^ 匹配字符串开始位置 
# $ 匹配字符串中结束的位置 
# * 前面的原子重复>=0次
# ? 前面的原子重复0,1次
# + 前面的原子重复>=1次
# {n} 前面的原子出现==n 次
# {n,} 前面的原子出现>= n 次
# {n,m} 前面的原子出现次数[n,m]
# ( ) 分组,需要输出的部分

#02_19 常用通用字符总结
# \s  匹配空白字符 
# \w  匹配任意字母/数字/下划线 
# \W  和小写 w 相反，匹配任意字母/数字/下划线以外的字符
# \d  匹配十进制数字
# \D  匹配除了十进制数以外的值 
# [0-9]  匹配一个0-9之间的数字
# [a-z]  匹配小写英文字母
# [A-Z]  匹配大写英文字母

#02_20 密码安全检查
# 密码安全要求：1)要求密码为6到20位; 2)密码只包含英文字母和数字
# pat=re.compile(r'[\da-zA-Z]{6,20}')
# r1=pat.findall('0passw0Rd')
# r2=pat.fullmatch('0passw0Rd')
# print('r1=',r1)
# print('r2=',r2)

#02_批量转化为驼峰格式(Camel)
# 数据库字段名批量转化为驼峰格式
# def camel(s):
#     s1 = re.sub(r"(\s|_|-)+", " ", s).title().replace(" ", "")
#     return s[0].lower() + s[1:]
# s1='student_id'
# print(camel(s1))

#02_23 str1是否为str2的permutation
# from collections import defaultdict
# def is_permutation(str1, str2):
#     if str1 is None or str2 is None:
#         return False
#     if len(str1) != len(str2):
#         return False
#     unq_s1 = defaultdict(int)
#     unq_s2 = defaultdict(int)
#     for c1 in str1:
#         unq_s1[c1] += 1
#     for c2 in str2:
#         unq_s2[c2] += 1  
#     return unq_s1 == unq_s2
# r = is_permutation('nice', '1ine')
# print(r)



#三、Python文件、日期和多线程

#03_01 获取后缀名
import os
# file_ext=os.path.splitext('./data/py/test.py')
# front,ext=file_ext
# print('front=',front) #./data/py/test
# print('ext=',ext) #.py

#03_02 文件读操作
# def mymkdir(path):
#     is_exists=os.path.exists(apth)
#     if not is_exists:
#         os.mkdir(path)

# def openfile(filename):
#     with open(filename) as f:
#         fdata=f.read()
#         return fdata

#03_03 文件写操作
# 写入文件信息
# w写入，如果文件存在，则清空内容后写入，不存在则创建
# f = open(r"./test1.txt", "w", encoding="utf-8")
# print(f.write("测试文件写入"))
# f.close

# a写入，文件存在，则在文件内容后追加写入，不存在则创建
# f = open(r"./test2.txt", "a", encoding="utf-8")
# print(f.write("测试文件写入"))
# f.close

# with关键字系统会自动关闭文件和处理异常
# with open(r"./test3.txt", "w") as f:
#     f.write("hello world!")

#03_04 路径中的文件名
# file_ext = os.path.split('./data/py/test.py')
# ipath,ifile = file_ext
# print('ipath=',ipath)
# print('ifile=',ifile)

#03_08 获取指定后缀名的文件
# def find_file(work_dir,extension='.md'):
#     lst = []
#     for filename in os.listdir(work_dir):
#         print(filename)
#         splits = os.path.splitext(filename)
#         ext = splits[1] # 拿到扩展名
#         print('ext=',ext)
#         print('-----------------')
#         if ext == extension:
#             lst.append(filename)
#     return lst

# r = find_file('.','.md') 
# print('r=',r) # 返回所有目录下的md文件





