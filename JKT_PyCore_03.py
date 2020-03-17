

#026 活都来不及干了，还有空注意代码风格？！

#1 统一的编程规范为什么重要？ --> 统一的编程规范能提高开发效率
#(1)阅读者的体验 >> 编程者的体验
# 命名必须有意义，不能是无意义的单字母。
# Python 代码中的 import 对象，只能是 package 或者 module。
#(2) 编程者的体验 >> 机器的体验
# 一个错误倾向，是过度简化
#(3) 机器的体验也很重要
# 最终希望代码能正确、高效执行。危险的编程风格，会影响程序正确性，代码效率。
# 特别强调了，何时使用 is， 何时使用 ==，何时使用隐式布尔转换。

#2 整合进开发流程的自动化工具
# 编程规范的终极目标是提高开发效率
# 如何执行呢？靠强制代码评审和强制静态或者动态 linter。
# 代码规范写进 Pylint ，能在每份代码提交前自动检查，不通过的无法提交。

#3 总结
# 代码风格之所以重要，是因为它关乎阅读者、编程者和执行代码的机器体验。
# 强调编程规范，最终是为了提高开发效率，而不是做额外功。

# # 错误示例
# if (a <= 0):
#    return
# elif (a > b):
#    return
# else:
#   b -= a

# # 正确示例
# if (transfer_amount <= 0):
#    raise Exception('...')
# elif (transfer_amount > balance):
#    raise Exception('...')
# else:
#   balance -= transfer_amount


# # 错误示例
# from mypkg import Obj
# from mypkg import my_func
# my_func([1, 2, 3])

# # 正确示例
# import numpy as np
# import mypkg
# np.array([6, 7, 8])

# # 错误示例
# result = [(x, y) for x in range(10) for y in range(5) if x * y > 10]
# # 正确示例
# result = []
# for x in range(10):
#   for y in range(5):
#      if x * y > 10:
#        result.append((x, y))


# # 错误示例
# x = 27
# y = 27
# print(x is y)
# x = 721
# y = 721
# print(x is y)

#已经清楚，is 比较对象的内存地址，在代码风格中，避免用is比较两个 Python 整数的地址。
# # 正确示例
# x = 27
# y = 27
# print(x == y)
# x = 721
# y = 721
# print(x == y)


# # 错误示例
# x = MyObject()
# print(x == None)

# # 正确示例
# x = MyObject()
# print(x is None) #和 None 比较时候永远使用 is:


# # 错误示例
# def pay(name, salary=None):
#  if not salary:
#    salary = 11
#  print(name, "is compensated", salary, "dollars")

# # 正确示例
# def pay(name, salary=None):
#  if salary is not None: #明确想比较对象是否是None，一定要显式地用 is None。
#    salary = 11
#  print(name, "is compensated", salary, "dollars")


# # 错误示例
# adict = {i: i * 2 for i in xrange(10000000)}

# for key in adict.keys():
#    print("{0} = {1}".format(key, adict[key]))

# # 正确示例
# for key in adict:
# #keys()会在遍历前生成临时列表，导致代码消耗大量内存并运行缓慢。正确是用默认的 iterator。


#027 学会合理分解代码，提高代码可读性
# 缩进规范：
#Python 和 C++ / Java 最大的不同，后者完全使用大括号区分代码块，前者依靠不同行和不同的缩进来进行分块。
# 1. 使用四空格缩进,不要用 Tab，更不要Tab和空格混着用。
# 2. 每行最大长度79个字符,不要迭代过深

# 空行规范：
# 1. 全局的(文件级别的)类和全局的函数上方要有两个空行
# 2. 类中的函数上方要有一个空行
# 3. 函数内部不同意群的代码块之间要有一个空行
# 4. 不要把多行语句合并为一行(即不要使用分号分隔多条语句)
# 5. 当使用控制语句if/while/for时，即使执行语句只有一行命令，也需要另起一行
# 6. 代码文件尾部有且只有一个空行

# 空格规范：
# 1. 函数的参数之间要有一个空格
# 2. 列表、元组、字典的元素之间要有一个空格
# 3. 字典的冒号之后要有一个空格
# 4. 使用#注释的话，#后要有一个空格
# 5. 操作符(例如+，-，*，/，&，|，=，==，!=)两边都要有一个空格，但括号(小括号、中括号和大括号)内的两端不需要空格

# 换行规范：
# 1. 一般通过逻辑拆分等手段,控制每行最大长度不超过79个字符，但有时单行代码还是会超过此限制，此时需换行来解决问题。
# 2. 两种实现换行的方法：
# 第一种，通过小括号进行封装，虽然跨行，但仍处于一个逻辑引用之下。比如函数参数列表、过长的运算语句
# 第二种，直接通过换行符(\)实现

# 文档规范：
# 1. 所有import尽量放在文件头部
# 2. 每行import只导入一个对象
# 3. 当使用from xxx import xxx时，import后面的对象是一个package(包对应代码目录)或者module(模块对应代码文件)，不要是一个类或者函数
# 采用 from module import func 这样的语句，请确保 func 在本文件中不会出现命名冲突
# 可通过 from module import func as new_func 重命名，避免冲突。

# 注释规范：
# 1. 代码块注释，在代码块上一行相同缩进处，以 # 开始书写注释
# 2. 代码行注释，在代码行尾部跟2个空格，以 # 开始书写注释，行注释尽量少写
# 3. 英文注释开头要大写，结尾要写标点符号，避免语法和逻辑错误，中文注释相同要求
# 4. 改动代码逻辑时，要及时更新相关的注释

# 文档描述规范：
#  三个双引号开始、三个双引号结尾；
#  首先用一句话简单说明这个函数做什么，然后跟一段话来详细解释；
# 再往后是参数列表、参数格式、返回值格式的描述。

# 命名规范：
# 1. 变量名，要全部小写，多个词用下划线连接，可用单字符变量名的场景，比如迭代 for i in range(n)
# 2. 类的私有变量名，前需加2个下划线
# 3. 常量名，全部大写，多个词用下划线连接
# 4. 函数名，全部小写，多个词用下划线连接
# 5. 类名，驼峰形式，首字母大写，多个词：各词首字母大写，直接拼接
# 6. 命名应名如其意，不要吝啬名字长度

# 代码分解技巧：
# 1. 不写重复代码，重复代码可用条件、循环、函数和类来解决
# 2. 减少迭代层数，让代码扁平化
# 3. 函数拆分，函数的粒度尽可能细，一个函数不要做太多事情
# 4. 类的拆分，如果一个类中有多个属性描述同一类事物，可把这些属性拆分，新建一个单独的类
# 5. 模块化，若项目偏大，为不同功能模块创建独立的目录或文件，通过import互相关联


#028 如何合理利用assert？
#1 什么是 assert？
# Python的assert 语句，是debug 的好工具，用于测试一个条件是否满足。
# 条件满足，相当于pass 语句；不满足，抛出异常 AssertionError，并返回具体的错误信息（optional）。
# (1)__debug__是一个常数。若执行时附带-O选项，如Python test.py -O，那所有assert语句失效，常数__debug__为 False；反之__debug__为 True。
# (2)不要在使用 assert 时加入括号,否则无论表达式对错，assert 检查永远不会 fail，程序只会给你 SyntaxWarning。
# (3)assert 的作用，是对代码做internal的self-check。使用 assert，就表示你很确定。这个条件一定会或者不会发生。

# assert 1 == 2
# 相当于
# if __debug__:
#     if not expression: raise AssertionError

# assert 1 == 2,  'assertion is wrong'
# 相当于
# if __debug__:
#     if not expression1: raise AssertionError(expression2)

# assert(1 == 2, 'This should fail')
# 正确写法如下：
# assert 1 == 2, 'This should fail'

#2 assert  的用法
# assert加入，可有效预防 bug ，提高程序健壮性。

#3 assert 错误示例
# assert 检查可被关闭,一旦被关闭,可能带来巨大安全漏洞
# assert 不适用 run-time error 检查

#正确做法是，用条件语句进行相应检查，并合理抛出异常：
# def delete_course(user, course_id):
#     if not user_is_admin(user):
#         raise Exception('user must be admin')
#     if not course_exist(course_id):
#         raise Exception('coursde id must exist')
#     delete(course_id)  

# 正确做法是进行异常处理，用 try 和 except 来解决：
# def read_and_process(path):
#     try:
#         with open(path) as f:
#             ...
#     except Exception as e:
#             ...  

#4 总结
# 使用 assert 时，不要加括号，否则无论表达式对错，assert 检查永远不会 fail。
# 程序中的 assert 语句，可通过-O等选项被全局 disable。
# 不能滥用 assert。不同情况都是意料之中，用条件语句判断更合适。程序中的 run-time error，记得使用异常处理。
#(1)assert的使用应该是，有无assert，程序都能正常运行，但有了assert可使代码后期维护更加方便


#029 巧用上下文管理器和With语句精简代码
#1 什么是上下文管理器？
# 资源管理操作很常见。资源都是有限的，必须保证资源用后释放，不然易造成资源泄露
# 上下文管理器，能帮助你自动分配并释放资源，其中最典型的应用是 with 语句。

#正确写法如下：
#每次打开文件并写入‘hello’之后，这个文件便自动关闭，相应资源也可得到释放，防止资源泄露。
# for x in range(10000000):
#     with open('test.txt', 'w') as f:
#         f.write('hello')

#finally block 尤其重要，哪怕写入文件发生错误异常，也可保证该文件最终被关闭
#与 with 语句相比，显得冗余，还容易漏写，因此更倾向with语句。
# f = open('test.txt', 'w')
# try:
#     f.write('hello')
# finally:
#     f.close()

# Python 中的 threading.lock 类
# 比如我想要获取一个锁，执行相应操作，完成后再释放，可写成这样：

# some_lock = threading.Lock()
# some_lock.acquire()
# try:
#     ...
# finally:
#     some_lock.release()

#with 语句可简化代码，有效避免资源泄露
# some_lock = threading.Lock()
# with somelock:
#     ...


#2 上下文管理器的实现

#2.1 基于类的上下文管理器
# 自定义一个上下文管理类 FileManager，模拟 Python 的打开、关闭文件操作：
# 参数“exc_type, exc_val, exc_tb”，分别表示 exception_type、exception_value 和 traceback。
# 执行含有上下文管理器的with语句时，若有异常抛出，异常信息就会包含在这三个变量中，传入方法“__exit__()”。

# class FileManager:
#     def __init__(self, name, mode):
#         print('calling __init__ method')
#         self.name = name
#         self.mode = mode 
#         self.file = None

#     def __enter__(self):
#         print('calling __enter__ method')
#         self.file = open(self.name, self.mode)
#         return self.file #返回需要被管理的资源

#     def __exit__(self, exc_type, exc_val, exc_tb): #释放、清理资源操作
#         print('calling __exit__ method')
#         if self.file:
#             self.file.close()

# with FileManager('test.txt', 'w') as f:
#     print('ready to write to file')
#     f.write('hello world')


# 若需处理可能发生的异常，可在“__exit__()”添加相应的代码
# class Foo:
#     def __init__(self):
#         print('__init__ called')        

#     def __enter__(self):
#         print('__enter__ called')
#         return self

#     def __exit__(self, exc_type, exc_value, exc_tb):
#         print('__exit__ called')
#         if exc_type:
#             print(f'exc_type: {exc_type}')
#             print(f'exc_value: {exc_value}')
#             print(f'exc_traceback: {exc_tb}')
#             print('exception handled')
#         return True #若确定异常已被处理，需要加上这句

# with Foo() as obj:
#     raise Exception('exception raised').with_traceback(None)


#数据库的连接操作，也常常用上下文管理器来表示
#写完DBconnectionManager这个类，程序每次连接数据库时，只需调用with语句，无需要关心数据库的关闭、异常等等，提高开发效率。
# class DBConnectionManager: 
#     def __init__(self, hostname, port): 
#         self.hostname = hostname 
#         self.port = port 
#         self.connection = None

#     def __enter__(self): 
#         self.connection = DBClient(self.hostname, self.port) 
#         return self

#     def __exit__(self, exc_type, exc_val, exc_tb): 
#         self.connection.close() 

# with DBConnectionManager('localhost', '8080') as db_client: 


#2.2 基于生成器的上下文管理器
# 可使用装饰器 contextlib.contextmanager，来定义所需的基于生成器的上下文管理器
# 不再定义“__enter__()”和“__exit__()”方法，但务必加上装饰器 @contextmanager

# from contextlib import contextmanager

# @contextmanager
# def file_manager(name, mode):
#     try:
#         f = open(name, mode)
#         yield f
#     finally:
#         f.close()

# with file_manager('test.txt', 'w') as f:
#     f.write('hello world')


#2.3 功能上是一致的
# 基于类的上下文管理器更加 flexible，适用于大型的系统开发；
# 而基于生成器的上下文管理器更加方便、简洁，适用于中小型程序。
# 必须在方法“__exit__()”或者 finally block 中释放资源，这一点尤其重要。


#3 总结
# 上下文管理器，常用于文件打开关闭和数据库的连接关闭，确保用过的资源迅速释放，提高程序的安全性
# 上下文管理器常和 with 语句一起使用，提高程序简洁度。


#030 真的有必要写单元测试吗？
# unit test,保证所写代码的稳定、高效、无误，才是我们工作的关键。
# 测试驱动开发（TDD）

#1 什么是单元测试？
# 单元测试，就是编写测试来验证某模块功能正确性，一般会指定输入，验证输出是否符合预期。
# 每一个模块的所有可能输入值进行测试, 提高代码质量，减小 bug
# 测试函数以‘test’开头，测试函数内部，常用 assertEqual()、assertTrue()、assertFalse()和assertRaise()等assert语句验证结果
# 高手和新手的最大差别，便是单元测试技巧的使用。


# import unittest
# # 将要被测试的排序函数
# def sort(arr):
#     l = len(arr)
#     for i in range(0, l):
#         for j in range(i + 1, l):
#             if arr[i] >= arr[j]:
#                 tmp = arr[i]
#                 arr[i] = arr[j]
#                 arr[j] = tmp

# # 编写子类继承unittest.TestCase
# class TestSort(unittest.TestCase):
#    # 以test开头的函数将会被测试
#    def test_sort(self):
#         arr = [3, 4, 1, 5, 6]
#         sort(arr)
#         # assert 结果跟我们期待的一样
#         self.assertEqual(arr, [1, 3, 4, 5, 6])

# if __name__ == '__main__':
#     #Jupyter下，请用如下方式运行单元测试
#     #unittest.main(argv=['first-arg-is-ignored'], exit=False)

#     # 命令行下运行，则：
#     unittest.main()


#2 单元测试的几个技巧
# 核心思想:用虚假的实现，替换被测试函数的依赖项，把更多精力放在被测试的功能上。

#2.1 mock
# 单元测试中最核心的一环.通过一个虚假对象，代替被测试函数或模块需要的对象。
# 主要使用 mock 或者 MagicMock 对象
# 真正工业化的代码，都是多层模块相互逻辑调用的一个树形结构。单元测试测的是某节点的逻辑功能，mock 掉相关的依赖项非常重要


# import unittest
# from unittest.mock import MagicMock
# class A(unittest.TestCase):
#     def m1(self):
#         val = self.m2()
#         self.m3(val)

#     def m2(self):
#         pass

#     def m3(self, val):
#         pass

#     def test_m1(self):
#         a = A()
#         a.m2 = MagicMock(return_value="custom_val")
#         a.m3 = MagicMock()
#         a.m1()
#         self.assertTrue(a.m2.called) #验证m2被call过
#         a.m3.assert_called_with("custom_val") #验证m3被指定参数call过

# if __name__ == '__main__':
#     #unittest.main(argv=['first-arg-is-ignored'], exit=False)
#     unittest.main()


#2.2 Mock Side Effect
# mock的函数，属性是可根据不同输入，返回不同数值，而不只是一个 return_value。
# from unittest.mock import MagicMock
# def side_effect(arg):
#     if arg < 0:
#         return 1
#     else:
#         return 2
# mock = MagicMock()
# mock.side_effect = side_effect

# print('mock(-1)={}'.format(mock(-1))) #1
# print('mock(1)={}'.format(mock(1)))  #2

#2.3 patch
#(1) 应用Python的decoration模式或context manager概念，快速mock所需函数
# from unittest.mock import patch
# @patch('sort')
# def test_sort(self, mock_sort):
#     ...
#     ...

#(2) mock 类的成员函数
#若一个类的构造函数非常复杂，测试其中一个成员函数不依赖所有初始化的object
#通过patch，将A类的构造函数mock为一个do nothing的函数，可方便地避免复杂的初始化（initialization）。
# with patch.object(A, '__init__', lambda x: None):
#       …

# 单元测试核心还是 mock，mock 掉依赖项，测试相应的逻辑或算法的准确性。
# 只要能掌握MagicMock 和 patch，编写绝大部分工作场景的单元测试不成问题

#3 高质量单元测试的关键
#3.1 Test Coverage
# 衡量代码中语句被 cover 的百分比。提高代码模块的 Test Coverage，基本等同于提高代码的正确性。
# 可用Python的coverage tool衡量Test Coverage，并显示每个模块被coverage的语句。

#3.2 模块化
# 高质量单元测试，不仅要提高Test Coverage，让写的测试能cover各模块中的每条语句；
# 还要求从测试的角度审视 codebase，去思考怎么模块化代码，以写出高质量的单元测试。
# 重构代码可使单元测试更加全面、精确

#4 总结
# 整体看，单元测试的理念是先模块化代码设计，然后针对每个作用单元，编写单独的测试去验证其准确性。
# 更好的模块化设计和更多的 Test Coverage，是提高代码质量的核心。
# 单元测试的本质：通过mock去除不影响测试的依赖项，把重点放在测试代码的核心逻辑上。
# 单元测试是个极其重要的技能，是保证代码质量和准确性的必要环节。

# pytest似乎比官方 unitest 更容易且更强大！


#031 pdb & cProfile：调试和性能分析的法宝

#1 用pdb进行代码调试
#1.1必要性
# 单一语言的 IDE，对混合代码并不支持 UI 形式的断点调试，或只支持某些功能模块
# Python的pdb，是其自带的调试库。为Python程序提供了交互式的源代码调试功能，是命令行版本的IDE断点调试器
#1.2如何使用
# 只需在程序中，加入“import pdb”和“pdb.set_trace()”这两行代码就行
# 打印，语法是"p <expression>"：
# 命令“n”，继续执行代码到下一行
# 命令”l“，列举出当前代码行上下11行源代码，方便开发者熟悉当前断点周围的代码状态
# 命令“s“， step into ，即进入相对应的代码内部。这时，命令行中会显示”--Call--“字样，执行完内部的代码块，命令行会出现”--Return--“字样
# 命令”r“， step out，继续执行，直到当前函数完成返回
# 命令”b ，[ ([filename:]lineno | function) [, condition] ]“用来设置断点
# 命令”c“，一直执行程序，直到遇到下个断点

# def func():
#     print('enter func()')

# a = 1
# b = 2
# import pdb
# pdb.set_trace()
# func()
# c = 3
# print(a + b + c)


#2 用cProfile进行性能分析
# profile是指对代码各部分动态分析，比如准确计算各模块消耗的时间。知道程序的瓶颈，对其修正或优化

# import cProfile
# def fib(n):
#     if n == 0:
#         return 0
#     elif n == 1:
#         return 1
#     else:
#         return fib(n-1) + fib(n-2)

# def fib_seq(n):
#     res = []
#     if n > 0:
#         res.extend(fib_seq(n-1))
#     res.append(fib(n))
#     return res
# cProfile.run('fib_seq(30)')

# 很多对 fib() 的调用，其实是重复的，那我们就可以用字典来保存计算过的结果，防止重复。
# import cProfile
# def memoize(f):
#     memo = {}
#     def helper(x):
#         if x not in memo:            
#             memo[x] = f(x)
#         return memo[x]
#     return helper

# @memoize
# def fib(n):
#     if n == 0:
#         return 0
#     elif n == 1:
#         return 1
#     else:
#         return fib(n-1) + fib(n-2)

# def fib_seq(n):
#     res = []
#     if n > 0:
#         res.extend(fib_seq(n-1))
#     res.append(fib(n))
#     return res

# cProfile.run('fib_seq(30)')

#3 总结
# pdb为Python程序提供了一种通用的、交互式的高效率调试方案；
# cProfile是提供了各代码块执行效率的详细分析，有助于对程序的优化与提高。


#032 答疑（三）：如何选择合适的异常处理方式

#1 问题一：应该使用哪种异常处理方式？
# 第一种，在代码中对数据进行检测，并直接处理与抛出异常。 --> 一旦抛出异常，程序就会终止
# 第二种，在异常处理代码中进行处理。 --> 抛出异常，会被程序捕获（catch），程序继续运行
# 到底使用哪一种方法，取决于具体场景。

#2 问题二：先写出能跑起来的代码，后期再优化可以吗？
# 双管齐下:代码功能完整和规范完整的优先级不分先后，应该同时进行

#3 问题三：代码中写多少注释才合适？
# 没有统一要求，要根据代码量和复杂度来决定

#4 问题四：项目的 API 文档重要吗？
# 规范的公司，通常要求写文档。项目的文档，主要是概述相应的系统、产品或功能模块,有助于后人理解


















































