# coding=UTF-8

#003 列表和元组，到底用哪一个？

# l=[1,2,'hello','world']
# tup=('jason',22)
# print(tup)

# l=[1,2,3,4]
# l[3]=40
# print(l)
# l.append(5)
# print(l)

# tup=(1,2,3,4)
# new_tup=tup+(5,)
# print(new_tup)

# l=[1,2,3,4]
# print(l[-1])
# print(l[1:3])

# tup=(1,2,3,4)
# print(tup[-1])
# print(tup[1:3])

# l1=[[1,2,3],[4,5]]
# l2=list((1,2,3))
# print(l1)
# print(l2)

# tup1=((1,2,3),(4,5,6))
# tup2=tuple([1,2,3])
# print(tup1)
# print(tup2)

# l=[3,2,3,7,8,1]
# print(l.count(3)) #2
# print(l.index(7)) #3
# l.reverse()
# print(l)
# l.sort()
# print(l) 

# tup=(3,2,3,7,8,1)
# print(tup.count(3))
# print(tup.index(7))
# l2=list(reversed(tup))
# print(l2)
# print(sorted(tup))

# l=[1,2,3]
# print(l.__sizeof__()) #64

# tup=(1,2,3)
# print(tup.__sizeof__()) #48

# l=[]
# print(l.__sizeof__())
# l.append(1)
# print(l.__sizeof__())
# l.append(2)
# print(l.__sizeof__())
# l.append(3)
# print(l.__sizeof__())
# l.append(4)
# print(l.__sizeof__())
# l.append(5)
# print(l.__sizeof__())


#004  字典、集合，你真的了解吗？

# d1={'name':'jason','age':20,'gender':'male'}
# d2=dict({'name':'jason','age':20,'gender':'male'})
# d3=dict([('name','jason'),('age',20),('gender','male')])
# d4=dict(name='jason',age=20,gender='male')
# print(d1==d2==d3==d4)

# s1={1,2,3}
# s2=set([1,2,3])
# print(s1==s2)

# s={1,'hello',5.0}

# d={'name':'jason','age':20}
# print(d['name'])
# print(d.get('name'))
# print(d.get('location'))

# s={1,2,3}
# print(1 in s)
# print(10 in s)

# d={'name':'jason','age':20}
# print('name' in d)
# print('location' in d)

# d={'name':'jason','age':20}
# d['gender']='male'
# d['dob']='1999-02-01'
# print(d)
# d['dob']='1998-01-01'
# d.pop('dob')
# print(d)

# print('\n')
# s={1,2,3}
# s.add(4)
# print(s)
# s.remove(4)
# print(s)

# d={'b':1,'a':2,'c':10}
# d_sort_by_key=sorted(d.items(),key=lambda x: x[0])
# d_sort_by_value=sorted(d.items(),key=lambda x: x[1])
# print(d_sort_by_key)
# print(d_sort_by_value)

# s={3,4,1,2}
# sorted(s)
# print(s)


#005  深入浅出字符串

# s1='hello'
# s2="hello"
# s3="""hello"""
# s4="I'am a student"
# print(s1==s2==s3)
# print(s4)

# s='a\nb\tc'
# print(s)
# print(len(s))

# name='jason'
# print(name[0])
# print(name[1:3])
# for c in name:
#     print(c)

# s='hello'
# s1='H'+s[1:]
# s2=s.replace('h','H')
# print(s)
# print(s1)
# print(s2)

# l=[]
# for n in range(0,10):
#     l.append(str(n))
# print(l)
# l=' '.join(l)
# print(l)

# def query_data(namespace, table):
#     """    
#     given namespace and table, query database to get corresponding
#     data             
#     """

# path = 'hive://ads/training_table'
# namespace = path.split('//')[1].split('/')[0] # 返回'ads'
# table = path.split('//')[1].split('/')[1] # 返回 'training_table'
# data = query_data(namespace, table)
# print(type(data))
# print(data)

# s=' my name is jason '
# print(s.strip())

# id='123'
# name='jason'
# print('no data available for person with id: {}, name: {}'.format(id, name))
# print('no data available for person with id: %s, name: %s' % (id, name))

# s = " ".join(map(str, range(0, 10)))
# print(s)


#006 Python “黑箱”：输入与输出

# name=input('your name:')
# gender=input('you are a boy?(y/s)')
# welcome_str='Welcome to the matrix {prefix} {name}.'
# welcome_dic= {
#     'prefix':'Mr.' if gender=='y' else 'Mrs'
#     'name': name
# }
# print('authorizing...')
# print(welcome_str.format(**welcome_dic))

# a=input()
# b=input()
# print('a + b = {}'.format(a + b))
# print('type of a is {},type of b is {}'.format(type(a),type(b)))
# print('a + b = {}'.format(int(a)+int(b)))

# import re

# def parse(text):
#     text = re.sub(r'[^\w ]', ' ', text)
#     text=text.lower()
#     world_list=text.split(' ')
#     world_list=filter(None,world_list)

#     word_cnt={}
#     for word in world_list:
#         if word not in word_cnt:
#             word_cnt[word]=0
#         word_cnt[word] += 1
    
#     sorted_word_cnt=sorted(word_cnt.items(),key=lambda kv: kv[1],reverse=True)
    
#     return sorted_word_cnt

# with open('in.txt','r') as fin:
#     text=fin.read()

# word_and_freq=parse(text)

# with open('out.txt','w') as fout:
#     for word,freq in word_and_freq:
#         fout.write('{} {}\n'.format(word,freq))

# import json
# params= {
#     'symbol':'123456',
#     'type':'limit',
#     'price':123.4,
#     'amount':23
# }

# params_str=json.dumps(params)
# print('after json serialization')
# print('type of params_str={},params_str={}'.format(type(params_str),params))
# print('\n')

# original_params=json.loads(params_str)
# print('after json serialization')
# print('type of original_params={},original_params={}'.format(type(original_params),params))

# import json
# params= {
#     'symbol':'123456',
#     'type':'limit',
#     'price':123.4,
#     'amount':23
# }

# with open('params.json','w') as fout:
#     params_str=json.dump(params,fout)

# with open('params.json','r') as fin:
#     original_params=json.load(fin)

# print('after json deserialization')
# print('type of original_params={},original_params={}'.format(type(original_params),params))


#007  修炼基本功：条件与循环

# l=[1,2,3,4]
# for item in l:
#     print(item)

# d={'name':'jason','dob':'2000-01-01','gender':'male'}
# for k in d:
#     print(k)
# print('\n')

# for v in d.values():
#     print(v)
# print('\n')

# for k,v in d.items():
#     print('key:{},value:{}'.format(k,v))
# print('\n')

# l=[1,2,3,4,5,6,7]
# for index in range(0,len(l)):
#     if index<5:
#         print(l[index])
# print('\n')

# l=[1,2,3,4]
# index=0
# while index<len(l):
#     print(l[index])
#     index += 1
# print('\n')

# y=[value*2+5 if value>0 else -value*2+5 for value in x]
# [(xx,yy) for xx in x for yy in y if xx != yy]

# text=' Monday, is, Sunday'
# text_list=[s.strip() for s in text.split(',') if len(s.strip())>5]
# print(text_list)
# print('\n')

# attributes = ['name', 'dob', 'gender']
# values = [
# ['jason', '2000-01-01', 'male'], 
# ['mike', '1999-01-01', 'male'],
# ['nancy', '2001-02-01', 'female']
# ]

# l=[]
# for val in values:
#     d={}
#     for i in range(3):
#         d[attributes[i]]=val[i]
#     l.append(d)

# l=[dict(zip(attributes,val)) for val in values]

# for i in range(3):
#     print(l[i])
#     print('\n')


#008 异常处理：如何提高程序的稳定性
# try:
#     s=input('please input two numbers separated by comma: ')
#     num1=int(s.split(',')[0].strip())
#     num2=int(s.strip(',')[1].strip())
# except ValueError as err:
#     print('Value Error: {}'.format(err))
# except IndexError as err:
#     print('Index Error: {}'.format(err))    
# except ExceptionError as err:   #except:
#     print('Other Error: {}'.format(err)) 
# print('continue')

# class MyInputError(Exception):
#     """Exception raised when there're errors in input"""
#     def __init__(self,value):
#         self.value=value
#     def __str__(self):
#         return ("{} is invalid input".format(repr(self.value)))

# try:
#     raise MyInputError(1)
# except MyInputError as err:
#     print('error: {}'.format(err))

#在异常处理时，如果 try block 中有多处抛出异常，需要我们使用多个 try except block 吗？
#以数据库的连接、读取为例
# try:
#     db=DB.connect('<db path>')
#     raw_data=DB.queryData('<viewer_id>')
# except (DBConnectionError,DBQueryDataError) as err:
#     print('Error: {}'.format(err))


#009 不可或缺的自定义函数
# def my_func(message):
#     print('Got a message: {}'.format(message))
# my_func('hello world')

# def my_sum(a,b):
#     return a+b

# ret=my_sum(3,5)
# print(ret)
# print(my_sum([1,2],[3,4]))
# print(my_sum('hello','world'))

# def find_max_element(l):
#     if not isinstance(l,list):
#         print('input is not type of list')
#         return
#     if len(l)==0:
#         print('empty input')
#         return
#     max_element=l[0]
#     for item in l:
#         if item>max_element:
#             max_element=item
#     print('max element is: {}'.format(max_element))

# find_max_element([8,1,-3,2,0])

# def my_func(msg):
#     my_sub_func(msg)

# def my_sub_func(msg):
#     print('Got a message: {}'.format(msg))

# my_func('hello world')

# def f1():
#     print('hello')
#     def f2():
#         print('world')
#     f2()
# f1()

#函数的嵌套
# def connect_DB():
#     def get_DB_configuration():
#         ...
#         return host,username,password
#     conn=connector.connect(get_DB_configuration())
#     return conn


# def factorial(input):
#     # validation check
#     if not isinstance(input, int):
#         raise Exception('input must be an integer.')
#     if input < 0:
#         raise Exception('input must be greater or equal to 0' )

#     def inner_factorial(input):
#         if input <= 1:
#             return 1
#         return input * inner_factorial(input-1)
#     return inner_factorial(input)

# print(factorial(5))

# MIN_VALUE=1
# MAX_VALUE=10
# def validation_check(value):
#     global MIN_VALUE
#     MIN_VALUE += 1

# validation_check(5)

# def outer():
#     x="local"
#     def inner():
#         nonlocal x  #SyntaxError: invalid syntax
#         x='nonlocal'
#         print("inner:",x)
#     inner()
#     print("outer:",x)    
# outer()

# def outer():
#     x="local"
#     def inner():
#         x='nonlocal'
#         print("inner:",x)
#     inner()
#     print("outer:",x)    
# outer()

#闭包
# def nth_power(exponent):
#     def exponent_of(base):
#         return base ** exponent
#     return exponent_of

# square=nth_power(2)
# cube=nth_power(3)
# square
# cube
# print(square(2))
# print(cube(2))


#010 简约不简单的匿名函数
# square=lambda x:x**2
# print(square(3))

# print([(lambda x: x*x)(x) for x in range(10)])

# l=[(1,20),(3,0),(9,10),(2,-1)]
# l.sort(key=lambda x: x[1])
# print(l)

# print(map(lambda x: x**2,[1,2,3,4,5]))

# from tkinter import Button, mainloop
# button = Button(
#     text='This is a button',
#     command=lambda: print('being pressed')) # 点击时调用lambda函数
# button.pack()
# mainloop()

# def multiply_2(l):
#     for idx in range(0,len(l)):
#         l[idx] *= 2
#     return l

# l=[1,2,3,4,5]
# print(multiply_2(l))
# print(l)

# def multiply_2_pure(l):
#     new_list=[]
#     for item in l:
#         new_list.append(item*2)
#     return new_list

# l=[1,2,3,4,5]
# print(multiply_2_pure(l))
# print(l)

# l=[1,2,3,4,5]
#new_list=map(lambda x:x*2,l)
# new_list=filter(lambda x:x%2==0,l)
# new_list=reduce(lambda x,y:x*y,l)
# print(new_list)


#011 面向对象（上）：从生活中的类比说起
# class Document():
#     def __init__(self,title,author,context):
#         print('init function called')
#         self.title=title
#         self.author=author
#         self.__context=context #私有成员

#     def get_context_length(self):
#         return len(self.__context)

#     def intercept_context(self,length):
#         self.__context=self.__context[:length] #含义？

# harry_potter_book=Document('Harry Potter', 'J. K. Rowling','... Forever Do not believe any thing is capable of thinking independently ...')
# print(harry_potter_book.title)
# print(harry_potter_book.author)
# print(harry_potter_book.get_context_length)
# harry_potter_book.intercept_context(10)
# print(harry_potter_book.get_context_length())
# print(harry_potter_book.__context)


# class Document():
#     WELCOME_STR='Welcome! The context for this book is {}.'

#     def __init__(self,title,author,context):
#         print('init function called')
#         self.title=title
#         self.author=author
#         self.__context=context #私有成员    

#     @classmethod    #类函数
#     def create_empty_book(cls,title,author):
#         return cls(title=title,author=author,context='nothing')

#     def get_context_length(self):   #成员函数
#         return len(self.__context)    

#     @staticmethod   #静态函数
#     def get_welcome(context):
#         return Document.WELCOME_STR.format(context)

# empty_book=Document.create_empty_book('What Every Man Thinks About Apart from Sex', 'Professor Sheridan Simove')
# print(empty_book.get_context_length())
# print(empty_book.get_welcome('indeed nothing'))


# class Entity():
#     def __init__(self,obj_type):
#         print('parent class init called')
#         self.obj_type=obj_type

#     def get_context_length(self):
#         raise Exception('get_context_length not implemented')

#     def print_title(self): 
#         print(self.title)

# class Document(Entity):
#     def __init__(self,title,author,context):
#         print('Document class init called')
#         Entity.__init__(self,'document')
#         self.title=title
#         self.author=author
#         self.__context=context #私有成员     

#     def get_context_length(self):
#         return len(self.__context)

# class Video(Entity):
#     def __init__(self,title,author,video_length):
#         print('Video class init called')
#         Entity.__init__(self,'video')
#         self.title=title
#         self.author=author
#         self.__video_length=video_length #私有成员     

#     def get_context_length(self):
#         return self.__video_length

# harry_potter_book = Document('Harry Potter(Book)', 'J. K. Rowling', '... Forever Do not believe any thing is capable of thinking independently ...')
# harry_potter_movie = Video('Harry Potter(Movie)', 'J. K. Rowling', 120)

# print(harry_potter_book.obj_type)
# print(harry_potter_movie.obj_type)
# harry_potter_book.print_title()
# harry_potter_movie.print_title()
# print(harry_potter_book.get_context_length())
# print(harry_potter_movie.get_context_length())


#012 面向对象（下）：如何实现一个搜索引擎
# import re
# class SearchEngineBase(object):
#     def __init__(self):
#         pass

#     def add_corpus(self,file_path):
#         with open(file_path,'r') as fin:
#             text=fin.read()
#         self.process_corpus(file_path,text)

#     def process_corpus(self,id,text):
#         raise Exception('process_corpus not implemented.')

#     def search(self,query):
#         raise Exception('search not implemented.')

# def main(search_engine):
#     #basepath='/media/tom_jack/本地磁盘/Projects/Python_code/JKT_Python核心/'
#     for file_path in ['1.txt','2.txt','3.txt','4.txt','5.txt']:
#         search_engine.add_corpus(file_path)

#     while True:
#         query=input()
#         #query='little'
#         #query='freedom children'
#         # query='i have a dream'
#         print(query)
#         results=search_engine.search(query)
#         print('found {} result(s):'.format(len(results)))
#         for ret in results:
#             print(ret)
#         # break

# class SimpleEngine(SearchEngineBase):
#     def __init__(self):
#         super(SimpleEngine,self).__init__()
#         self.__id_to_texts={}

#     def process_corpus(self, id, text):
#         self.__id_to_texts[id]=text

#     def search(self,query):
#         results=[]
#         for id,text in self.__id_to_texts.items():
#             if query in text:
#                 results.append(id)
#         return results

# search_engine=SimpleEngine()
# main(search_engine)

# class BOWEngine(SearchEngineBase):
#     def __init__(self):
#         super(BOWEngine,self).__init__()
#         self.__id_to_words={}

#     def process_corpus(self, id, text):
#         self.__id_to_words[id]=self.parse_text_to_words(text)

#     def search(self,query):
#         query_words=self.parse_text_to_words(query)
#         results=[]
#         for id,words in self.__id_to_words.items():
#             if self.query_match(query_words,words):
#                 results.append(id)
#         return results

#     @staticmethod
#     def query_match(query_words,words):
#         for query_word in query_words:
#             if query_word not in words:
#                 return False
#         return True

#     @staticmethod
#     def parse_text_to_words(text):
#         text = re.sub(r'[^\w ]', ' ', text)
#         text=text.lower()
#         word_list=text.split(' ')
#         word_list=filter(None,word_list)
#         return set(word_list)            

# search_engine=BOWEngine()
# main(search_engine)

# base_path='/media/tom_jack/本地磁盘/Projects/Python_code/JKT_Python核心/'
# file_path=['1.txt','2.txt','3.txt','4.txt','5.txt']
# for fp in file_path:
#     print(base_path+fp)


#013 搭建积木：Python 模块化

#014 答疑（一）：列表和元组的内部实现是怎样的
# x=[1]
# def func():
#     x.append(2)
# func()
# print('x={}'.format(x))    



