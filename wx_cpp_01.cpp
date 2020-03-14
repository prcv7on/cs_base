

#include <iostream>
#include <vector>
#include <string>
//#include <typeinfo>

using namespace std;

//------编程充电宝------

//#include <queue>
//#include <stack>
//栈和队列的构造和相互实现、最小栈
//1.1使用数组实现固定长度的栈

/*
class Stack {
public:
	Stack(int len) {
		arr.resize(len);
		size = 0;
	}
	void push(int num) {
		if (size == arr.size) throw "stack is full!";
		arr[size++];
	}
	int pop() {
		if (size == 0) throw "stack is empty!";
		return arr[--size];
	}
private:
	vector<int> arr;
	int size;
};

//1.2使用数组实现固定长度的队列
class Queue {
public:
	Queue(int size) {
		arr.resize(size);
		size = 0;
		beg = 0;
		end = 0;
	}
	void push(int num) {
		++size;
		arr[end] = num;
		end = (size==arr.size()-1) ? 0 : end+1;
	}
	int pop() {
		if (size == 0) {
			throw "queue is empty!";
			return -1;
		}
		int tmp = beg;
		--size;
		beg = (beg==arr.size()-1) ? 0 : beg + 1;
		return arr[tmp];
	}

private:
	vector<int> arr;
	int size;
	int beg;
	int end;
};
*/

/*
//1.3只用队列实现一个栈
//用两个队列q1和q2来实现这个栈
class Stack{
	void push(int num) {
		q1.push(num);
	}
	int pop() {
		if (q1.empty()) {
			cout << "stack is empty!" << endl;
			return -1;
		}
		while (q1.size() > 1) {
			q2.push(q1.front());
			q1.pop();
		}
		int res = q1.front();
		q1.pop();
		myswap();
		return res;
	}
	void myswap() {
		queue<int> tmp = q1;
		q1 = q2;
		q2 = tmp;
	}

private:
	queue<int> q1;
	queue<int> q2;
};

//1.4只用栈实现一个队列
class Stack {
public:
	void push(int num) {
		stk1.push(num);
	}
	int pop() {
		if (stk2.empty()) push2pop();
		if (stk1.empty()) {
			cout << "queue is empty!" << endl;
			return -1;
		}
		int top = stk2.top();
		stk2.pop();
		return top;
	}

private:
	stack<int> stk1;
	stack<int> stk2;
	void push2pop() {
		while (!stk1.empty()) {
			stk2.push(stk1.top());
			stk1.pop();
		}
	}
};

//1.5 实现一个最小栈，即返回最小值函数的栈
//再拿一个栈来存储最小值
//和数据栈并行的存，最小栈长度和数据栈一致，各数据代表同等长度下的栈的最小值。
class MinStack {
public:
	void push(int num) {
		if (min_stk.empty()) min_stk.push(num);
		else if (min_stk.top()<num) min_stk.push(min_stk.top());
		else min_stk.push(num);
		data_stk.push(num);
	}
	int top() { return data_stk.top(); }
	int pop() {
		int top = data_stk.top();
		min_stk.pop();
		data_stk.pop();
		return top;
	}
	int getMin() { return min_stk.top(); }

private:
	stack<int> data_stk;
	stack<int> min_stk;
};
*/



//------编程珠玑------

//01 为什么说++i的效率比i++高？
//1.1 ++i与i++的区别
//a++的结果并非左值。但++b的结果是左值。
//左值，有名对象，可赋值
//右值，临时对象，不可被赋值
//
//1.2 运算符重载
//对于内置类型，前置自增返回对象的引用，后置自增返回对象的原值（但非左值）。
//class A {
//public:
//	A& operator++();		//前置自增
//	const A operator++(int);//后置自增
//private:
//	int curpos;//当前位置
//};
//A& A::operator++() {
//	++curpos;
//	return *this;
//}
////为了与前置区分开，多了一个int参数，但从来没用过
//const A A::operator++(int) {
//	A tmp = *this;
//	++curpos;
//	return tmp;
//}
//
//不进行赋值的情况下，内置类型前置和后置自增的汇编都是一样
//赋值的情况下，并且不开启编译器优化，它们的汇编代码还是有差别的
//

/*
int main() {
	//int a = 0;
	//int b = 0;
	//int c = a++;
	//int d = ++b;
	//cout << "c=" << c << ",d=" << d << endl;
	//int *c = &(a++);//错误，&要求左值
	//int *d = &(++b);

	system("pause");
	return 0;
}
*/


//2 C++与C中的const关键字有何差别？
//2.1 修饰普通变量--只读
//C语言里，表面上它是只读的，然而你违规操作仍然能改变。
//C++中使用const关键字定义的b变量的值在被改变时会被检测。
//它们的作用也是一样的，声明一个只读变量，不希望被修改，一旦被修改，编译器将会报错。
//
//2.2 作用在成员函数-不改变成员变量
//const修饰成员函数不与static关键字同用
//static void printA() const --> 错误，不能加const

//class A {
//private:
//	int val;
//public:
//	void printA() const {
//		val = 10;//错误，通过常量对象访问“val”，因此无法对其进行修改
//	}
//};

//2.3 修饰类成员变量--构造函数中初始化
//修饰类成员变量还可在构造函数中初始化
//class A {
//private:
//	const int a_val;
//public:
//	A(int val) :a_val(val) {}
//};

//2.4 修饰引用
//
//2.5 总结
//const关键字，借助编译器提前发现不易察觉的问题。
//
//3 拥抱智能指针，告别内存泄露
//3.1 C与C++中的内存泄漏
//申请了，忘了释放;
//已释放仍去访问，
//某些操作抛出异常,使得delete无法执行到，导致内存泄漏。
//JAVA:垃圾回收并不是立即的，时机也不确定，同时回收机制比较复杂，会占用空间和时间开销，毕竟C/C++注重效率
//
//3.2 智能指针
//3.2.1 shared_ptr
//动态申请了一片内存，可能在多个地方用到
//引用计数为0，则自动释放内存。
//它的实现要考虑很多因素，例如如何原子地增加引用计数。比裸指针开销要大
//
//3.2.2 unique_ptr
//专属某个对象资源.它不能被复制，当这个专属管理不再使用，就可自动释放内存
//
//3.2.3 weak_ptr
//
//4 不想写表达式的类型？试试auto吧
//4.1 auto的作用：编译器替我们去分析表达式的类型。
//分析的前提是auto定义的变量有初值
//
//4.2 auto用法
//const关键字修饰的类型推导
//auto会忽略顶层const（本身是常量，如int *cosnt p），保留底层const（指向的对象是常量，如const int* p）
//auto还可以设置引用类型。如果是字面值，则必须加上const。
//
//4.3 想一想
//
//4.4 总结
//使用auto最好注意类型推导规则
//某些情况auto得到的类型可能不是你想要的
//一定要合理使用。

/*
int main() {
	//const int a = 10;
	//int* pa = &a;//错误，invalid conversion from ‘const int*’ to ‘int*’
	//*pa = 20;

	//A a;
	//a.printA();

	//A a(1);

	//const int a = 10;
	////int& ra1 = a;
	//const int& ra2 = a;//定义对常量的引用

	//const int ci = 10;
	//auto aci = ci;
	//const auto ca = ci;

	//const int arr[] = {11};
	//auto p = arr;

	//cout << "type(ci) =" << typeid(ci).name() << endl;//int？
	//cout << "type(aci)=" << typeid(aci).name() << endl;//int
	//cout << "type(ca) =" << typeid(ca).name() << endl;//int?
	//cout << "type(p)=" << typeid(p).name() << endl;//const int*类型，或者说是int const*，它指向的对象是只读的

	//vector<int> vec;
	//auto sz = vec.size();
	//cout << "tyep(sz)=" << typeid(sz).name() << endl;


	system("pause");
	return 0;
}
*/


//5 为何优先选用unique_ptr而不是裸指针？
//#include <memory>
//5.1 基本使用
//一个unique_ptr独享它指向的对象。一个unique_ptr只能指向同一个对象，当此unique_ptr被销毁时，指向的对象也随即被销毁。
//
//销毁对象时，都是用delete来销毁，也可用指定的方式销毁。
//unique_ptr<T, D> up(t,d);
//unique_ptr<T, D> up(t);//空的unique_ptr
//T unique_ptr管理的对象类型
//D 删除器类型
//t unique_ptr管理的对象
//d 删除器函数 / function对象等，用于释放对象指针
//
//与shared_ptr不同，unique_ptr在编译时绑定删除器，避免了运行时开销。
//
//5.1.1 释放指向的对象
//unique_ptr被销毁时（如离开作用域），对象自动释放，也可通过其他方式显示释放对象。如：
//up = nullptr;//置为空，释放up指向的对象
//up.release();//放弃控制权，返回裸指针，并将up置为空
//up.reset();//释放up指向的对象
//release和reset区别: 前者释放控制权，返回裸指针，还可继续使用。后者直接释放指向的对象
//
//5.1.2 unique_ptr不支持普通的拷贝和赋值
//既然unique_ptr是独享对象，任何可能被共享的操作都不允许，但可以移动
//unique_ptr<int> up0;
//unique_ptr<int> up1(new int(10));
//up0 = up1;//错误，不可赋值
//unique_ptr<int> up2(up1);//错误，不可拷贝
//
//5.1.3 移动unique_ptr的对象 --> 转移控制权
//unique_ptr<int> up1(new int(42));
//unique_ptr<int> up2(up1.release());
//
//unique_ptr<int> up1(new int(42));
//unique_ptr<int> up2;
//up2.reset(up1.release);
//
//unique_ptr<int> up1(new int(42));
//unique_ptr<int> up2(std::move(up1));
//
//5.2 在函数中的使用
//5.2.1 作为参数
//unique_ptr不能直接作为参数，因为它不允许被复制
//可向函数传递普通指针，get函数可获取裸指针
//使用引用作为参数
//若外部不再使用，可以转移，将对象交给调用的函数管理，可使用move函数
//5.2.2 作为返回值
//
//5.3 为什么优先选用unique_ptr
//5.3.1 避免内存泄露: 自动管理，不需要时即释放
//5.3.2 避免更大开销: 相比于shared_ptr，开销更小，和裸指针相当，无需维护引用计数的原子操作等
//如果可能，优先unique_ptr

//void f1(unique_ptr<int>& p) {
//	*p = 10;
//}
//
//void f2(unique_ptr<int> p) {
//	*p = 10;
//}
//
//unique_ptr<int> f3(int i) {
//	return unique_ptr<int>(new int(i));
//}

/*
int main() {
	//unique_ptr<int> up(new int(42));
	//f1(up);
	//cout << "*up=" << *up << endl;

	//unique_ptr<int> up(new int(42));
	////f2(unique_ptr<int>(up.release()));
	//f2(std::move(up));

	//unique_ptr<int> up = f3(10);
	//cout << "*up=" << *up << endl;

	system("pause");
	return 0;
}
*/


//6 decltype--从表达式推断类型
//6.1 作用
//从表达式类型,推断要定义的变量类型
//声明,返回类型依赖形参类型的函数模板
//decltype不会对表达式求值。
//
//6.2 用法
//表达式内容是解引用，得到引用类型。
//加了双重括号，最终得到引用类型。
//
//6.3 常见应用场景
//泛型编程中，若返回类型与形参类型相关，可以如下：

/*
template<typename T>
auto add(T x, T y) -> decltype(x) {
	return x + y;
}

int main() {
	//int a = 123;
	//decltype(a) b;
	//const char ch = 'a';
	//decltype(ch) d = 'b';

	//int& ra = a;
	//int g = 12;
	//decltype(ra) f = g;

	//cout << "type(b) =" << typeid(b).name() << endl;//int
	//cout << "type(f)=" << typeid(f).name() << endl;//int? 应该是int&

	//int a = 10;
	//int& ra = a;
	//int* pa = &a;
	//decltype(*pa) c = a;
	//cout << "type(c) =" << typeid(c).name() << endl;//int
	//cout << "type(ra) =" << typeid(ra).name() << endl;//int

	int a1 = 10;
	int a2 = 20;
	auto a3 = add(a1,a2);
	cout << "a3=" << a3 << endl;

	system("pause");
	return 0;
}
*/



//------程序猿Cpp------

//1 掌握C++标准库-第1讲
//C++标准库纳入了C标准库, C99是最流行的版本.
//C标准库由15个头文件构成
//01 cassert	断言。如果表达式不等于0则不处理；否则程序会异常退出并且显示异常信息。
//当在<cassert>头文件被包含前定义NDEBUG宏，assert宏不再起作用。从而方便我们在调试程序时捕获异常，并在发布程序时很容易的关闭assert宏。
//02 cctype		判断和转换char型的函数。
//03 cerrno		errno是错误代码，当调用C标准库函数发生错误时，通过错误代码可以获取错误信息。
//04 cfloat		提供了一组宏，描述关于浮点数的信息。
//05 climits	提供了一组宏，描述关于各类整型的极值信息。
//在不同的环境下，整型的范围可能不同。通过这些宏，有助于实现可移植的代码。
//06 clocale	可以设置和查询本地化环境。比如日期格式、货币符号、字符集等等。程序启动时采用默认且与本地环境无关的C环境。
//07 cmath		cmath中很多函数都是针对浮点型设计的，有三个重载版本（float、double、long double）。
//需要手动将整型型强制转换为上面三种类型之一
//08 csetjmp	它可以帮助你绕过函数调用和返回规则。应当慎重使用该头文件
//09 csignal	设置信号处理函数并产生信号。
//10 cstdarg	提供了va_list类型、va_start、va_arg、va_end三个宏。其作用是实现可变参数函数。
//C++11引入了可变参数模板(variadic templates)，这比cstdarg强大很多
//11 cstddef	定义了几个宏和类型。
//ptrdiff_t   size_t   wchar_t   NULL   offsetof
//12 cstdio		提供了C标准输入输出流、文件读写控制等功能
//13 cstdlib	提供了一组工具函数。
//14 cstring	字符串操作函数。
//15 ctime		获取和操作时间的函数。

//新写法：<cstdio>  --> 所有C标准库的函数被声明于std命名空间内
//旧写法：<stdio.h> --> C标准库的函数被声明于全局空间内
//
//2 C++面向对象类库，这是C++标准库的核心内容。
//只介绍关键部分：STL、C++标准I / O流，String，智能指针。
//2.1 STL
//(1) 容器: 存放数据；
//(2) 迭代器: 访问容器数据；
//(3) 分配器: 容器内存分配控制；
//(4) 算法: 修改、拷贝，删除、遍历、计算等；
//(5) 仿函数: 自定义算法；
//(6) 适配器: 容器、迭代器、算法的扩展。
//
//有几个问题：STL为什么要基于模板？如何实现算法与数据结构分离？如何使算法具备扩展性？
//第一：因为容器要能存储各种各样的数据；算法要支持各种类型的迭代器，这是模板在STL应用的典型场景，其目是泛化。
//第二：算法通过迭代器访问容器数据，迭代器由容器负责实现。换句话说，算法只对迭代器提出要求，它不关心容器的类型，因此算法和容器是独立的。
//第三：大部分算法都可自定义算法策略，从而实现算法的可扩展性，并且通过算法适配器，能够动态组装算法。
//
//2.2 STL容器
//按插入位置分，可分为序列、关联容器。
//按存放位置分，可分为连续和非连续内存容器，连续是指在内存中连续分布
//2.2.1 序列容器
//(1) array	连续内存容器 与原生数组类似，元素个数固定。
//不支持动态插入删除元素。提供了元素改、查的方法。
//
//(2) vector 元素个数可变，元素存储在堆上。
//vector的空间动态增长.容量不够时，vector会重新申请一个更大的内存，并拷贝所有元素，这会降低效率。
//vector不提供头插函数，若在头部插入，需要将所有元素向后移动
//vector提供了元素增、删、改、查的方法。
//
//(3) deque	分段连续的容器，由中控器管理。
//优点是，当容量不够时，只需要申请新的内存，不需要移动元素。
//
//(4) forward_list 前向链表，访问时只能前进，不能后退。
//
//(5) list 双向链表，可以双向移动。两种链表也提供了增删改查的方法。
//
//2.2.2 关联容器
//(1) 有序关联容器: set/multiset、map/multimap
//元素按大小顺序排列。按照key值进行排序。
//multi是指key值可以重复。此外，set和multiset、map和multimap没有区别。
//set存储只有key值的元素。
//map存储由key ，value构成的元素，所有元素按key值自动排序。
//set和map的底层是RB - tree（红黑树），是一种高度平衡的二叉树，使查找、插入、删除的复杂度都是log N
//
//(2) 无序关联容器有：unordered_set / unordered_multiset、unordered_map / unordered_multimap。
//unordered_set和unordered_map: 哈希容器，元素不按大小排列，按key值的hash值排放。哈希容器的操作复杂度是O(1)
//原理是: 不同hash值的元素放在不同的链表中，根据元素key值的hash值，很快获取元素所在的链表。
//
//3 STL迭代器（iterators）
//迭代器是一种抽象的设计概念，迭代器模式的定义：提供一种方法，使外界能依次访问某个聚合物（容器）中所有元素，并且不需要了解聚合物的实现方式。
//STL核心思想：将容器和算法分开，彼此独立，最后通过迭代器将它们撮合起来。即，迭代器是STL中的桥梁
//弄懂STL迭代器的实现原理，有助于更深理解泛型编程。
//迭代器不能泛化。因为不同容器的内存布局不一样，访问方法存在差异。不同类型的容器，迭代器不同。各种容器需要自己的迭代器
//
//3.1 迭代器实现
//迭代器是一种类似指针的对象。用于访问容器成员，因此具备解引用（dereference）和成员访问(member access)功能。因此，迭代器必须实现operator*和operator->操作符。
//实现一个简单的List容器和其迭代器：
//template<typename T>
//class List {
//public:
//	void insert_front(T value);
//	void insert_end(T value);
//private:
//	ListNode<T>* begin;
//	ListNode<T>* end;
//};
//
////list节点实现
//template<typename T>
//class ListNode {
//public:
//	T value();
//	ListNode* next();
//private:
//	T value;
//	ListNode* next;
//	ListNode* front;
//};
//
////List的迭代器实现
//template<typename T>
//class ListIter {
//public:
//	ListIter(T* p);
//	T& operator*() { return *pNode; }
//	T* operator->() { return pNode; }
//	ListIter& operator++() { pNode = pNode->next(); return *this; }
//private:
//	T* pNode;//指向list节点
//};

//3.2 迭代器型别
//3.2.1 萃取机制是利用模板推导，来获取泛型的各种信息。
//template<typename T>
//class trait {
//	// 萃取类型型别
//	typedef typename T::value_type value_type;
//};
//
//template<typename T>
//class Iterator
//{
//public：
//	typedef T value_type;//通过内嵌类型表达元素类型
//};
//
////返回迭代器所指的对象类型
//template<typename Iter>
//tarit<Iter>::value_type func() {}

//这样就可获取迭代器所指的返回值类型，这就是萃取机制。要保证萃取机制有效运行，每种迭代器要按照规定提供内嵌类型。
//
//3.2.2 STL规定，迭代器必须提供5种相应型别：
//(1) 所指型别(value type):				迭代器所指的对象的类型
//(2) 迭代器距离型别(difference type):	两个迭代器之间的距离的类型
//(3) 引用型别(reference type):			迭代器所指的对象能否被修改,分为常量和非常量迭代器
//(4) 指针型别(pointer type):			迭代器所指的对象的指针类型
//(5) 迭代器类型(iterator_category): 
//1) 只读迭代器：所指对象不能被外界修改，只读，支持operator++。
//2) 只写迭代器：只写，支持operator++。
//3) 前向迭代器：可读可写，只能前向移动，支持operator++。
//4) 双向迭代器：可读可写，可双向移动，支持operator--。
//5) 随机迭代器：可读可写，可随机移动，支持算术运算，iter + n，iter1<iter2等。
//受制于内存布局，不同容器提供的迭代器型别不同，vector、deque提供随机迭代器，list和关联容器提供双向迭代器，forward_list提供前向迭代器。
//
//有这么多型别，提高算法效率，STL追求极致的效率。
//以advanced为例，接受两个参数，迭代器iter和正数n，将iter前进n个距离。不同类型的迭代器，有三种实现方式，伪代码如下：

////只读迭代器版本
//void advance_II(InputIterator& p, Dist n) {
//	while (n-- > 0) ++p;
//}
//
////双向迭代器版本
//void advance_BI(BidirectionalIterator& p, Dist n) {
//	if (n >= 0)
//		while (n--) ++p;
//	else
//		while (n++) –p;
//}
//
////随机迭代器版本
//void advance_RI(RandomIterator& p, Dist n) {
//	p += n;
//}

//通过函数重载，在编译期就可选定最优的函数。

////只读迭代器类型重载版本
//void _advance(InputIterator& p, Dist n, input_iterator) {
//	advance_II(p, n);
//}
//
////双向迭代器类型重载版本
//void _advance(BidirectionalIterator& p, Dist n, bidirectional_iterator) {
//	advance_BI(p, n);
//}
//
////随机迭代器类型重载版本
//void _advance(RandomIterator& p, Dist n, random_iterator) {
//	advance_RI(p, n);
//}
//
////提供给用户的接口
//void advanced(Iterator& p, Dist n) {
//	//通过萃取机制获取迭代器型别，从而实现重载抉择
//	_advance(p, n, iterator_trait<Iterator>::iterator_category());
//}

//设计合适的迭代器，是容器的责任，只有容器的设计者才知道如何遍历自己，其迭代器应具备何种型别。
//算法完全独立于容器和迭代器之外: 典型的面向接口编程。
//
//3.2.3 迭代器失效
//vector迭代器失效：插入或删除元素，插入和删除位置之后的所有迭代器都失效；插入元素导致vector容器重新分配，所有迭代器都失效。
//deque迭代器失效：首尾插入不会有任何迭代器失效；首尾删除元素只会导致被删除元素的迭代器失效，其他位置的插入和删除将使所有迭代器失效。
//list、set、map迭代器失效：插入不会导致任何迭代器失效；删除只会导致被删除元素的迭代器失效。
//
//4 STL算法
//4.1 质变算法: 会修改容器元素内容。
//拷贝，交换，替换，填充，删除，排列组合，分割，随机重排，排序，旋转
//
//4.2 非质变算法
//查找，计数，遍历，比较，查找极值
//
//STL算法前两个形参通常是first和end，表示算法的操作区间[first, end)。
//编程时首先考虑STL算法，而不是自己实现。
//最大的问题不是不会使用算法，而是根本不知道算法的存在。
//
//5 空间分配器
//容器的大小可变，需要空间分配器，为给元素动态分配空间
//STL提供默认的空间分配器，功能：动态申请内存，调用构造函数，调用析构函数，释放内存。
//可能需要特殊的空间分配器：不想频繁申请和释放内存，可使用基于内存池的空间分配器；或想对内存分配进行更多控制
//
//6 仿函数
//用起来像函数，却是个类。因为仿函数类重载了"()"操作符。
//
//6.1 所有的仿函数都具有以下形式:
//class Functor {
//public:
//	void operator(int a) {
//		//重载()运算符
//	}
//};
////使用仿函数
//Functor func;
//func(1);
//
//6.2 仿函数在STL中是最简单、最容易实现的组件，它能让STL算法更灵活，
//很多STL算法支持自定义策略，类似于以下格式。
//algorithm(first, last, functor) {
//	functor(…);
//}
//
//7 适配器
//适配器是一种设计模式，能改变原class的接口，使因接口不能兼容的class能够协同工作。
//7.1 容器适配器的例子: queue和stack，本质都是deque容器。
//7.2 迭代器适配器: 插入适配器,使赋值变为插入操作; 反向适配器,使迭代器行进方向逆转; 流适配器,从I/O流读取和写入对象
//7.3 仿函数适配器: 组合各种仿函数，通过绑定、组合，创造各种可能的表达式

/*
//#include <list>
//#include <algorithm>
int main() {
	//int arr[7] = {0,1,2,3,4,5,6};
	//vector<int> vi(arr,arr+7);
	//list<int> li(arr,arr+7);

	//auto it1 = find(vi.begin(),vi.end(),3);
	//if (it1 != vi.end()) cout << "*it1= " << *it1 << endl;

	//auto it2 = find(li.begin(), li.end(), 6);
	//if (it2 != li.end()) cout << "*it2= " << *it2 << endl;

	system("pause");
	return 0;
}
*/



//------CPP开发者------

//1 C++ 对象数组与对象指针
//1.1 对象数组: 对象数组的元素是对象， 不仅具有数据成员，而且还有函数成员
//类名 数组名[下标表达式];
//1.2 使用对象数组时也只能访问单个数组元素, 也就是一个对象, 通过这个对象, 也可以访问到它的公有成员
//数组名[下标].成员名
//1.3 需建立某类的对象数组，设计构造函数时,要充分考虑元素初始化的需要；
//(1) 各元素初值要求相同，在类中定义不带参数或带缺省参数值的构造函数；
//(2) 各元素初值要求不同值,定义带形参(无缺省值)的构造函数。
//(3) 定义对象数组时，可通过初始化表进行赋值。
//
//2 对象指针
//对象初始化后都会在内存中占有一定的空间。可通过对象名或对象地址,访问一个对象
//对象指针存放对象地址的变量。声明对象指针：类名* 对象指针名;
//2.1 用指针访问单个对象成员
//
//2.2 用对象指针访问对象数组
//类的成员自身也是一些变量、函数或对象等。
//指向成员的指针,只能访问公有数据成员和成员函数。
//使用要先声明，再赋值，然后访问。
//
//2.2.1 指向数据成员的指针
//声明： 类型说明符 类名:: *数据成员指针名
//赋值： 数据成员指针名＝&类名::数据成员名
//使用
//对象名. *数据成员指针名
//对象指针名->*数据成员指针名
//
//2.2.2 指向成员函数的指针
//声明： 类型说明符(类名∷ *指针名)(参数表);
//赋值： 成员函数指针名 = 类名∷成员函数名;
//使用
//(对象名.*成员函数指针名)(参数表);
//(对象指针名 -> *成员函数指针名) (参数表);

//class exam {
//public:
//	exam() { x = 123; }
//	exam(int n) { x = n; }
//	void set_x(int n) { x = n; }
//	int get_x() { return x; }
//private:
//	int x;
//};

//class Pt {
//public:
//	Pt(int n, int m) {
//		x = n;
//		y = m;
//	}
//	~Pt() { cout << "~Pt()\n"; }
//	int get_x() { return x; }
//	int get_y() { return y; }
//
//private:
//	int x, y;
//};

//class exeam {
//public:
//	void set_a(int a) { x = a; }
//	void show_a() { cout << "x="<<x << "\n"; }
//private:
//	int x;
//};

//class A {
//public:
//	A(int i) { z = i; }
//	int z;
//};

//class Coord {
//public:
//	Coord(int a = 0, int b = 0) { x = a; y = b; }
//	int getx() { return x; }
//	int gety() { return y; }
//private:
//	int x, y;
//};


/*
int main() {
	//exam arr[4];
	//int i;
	//for (i = 0; i < 4; ++i) {
	//	arr[i].set_x(i);
	//}
	//for (i = 0; i < 4; ++i) {
	//	cout << arr[i].get_x() << " ";
	//}
	//cout << endl;

	//exam a1[4] = {11,22,33,44};
	//exam a2[4] = {55,66};
	//exam a3[4] = { exam(11),exam(22),exam(33),exam(44) };
	//exam a4[4] = { exam(55),exam(66) };
	//a4[2] = exam{77};
	//a4[3] = exam{ 88 };

	//int i;
	//for (i = 0; i<4; i++)
	//	cout << a1[i].get_x() << ' ';
	//cout << endl;
	//for (i = 0; i<4; i++)
	//	cout << a2[i].get_x() << ' ';
	//cout << endl;
	//for (i = 0; i<4; i++)
	//	cout << a3[i].get_x() << ' ';
	//cout << endl;
	//for (i = 0; i<4; i++)
	//	cout << a4[i].get_x() << ' ';
	//cout << endl;

	//Pt p[3][2] = {
	//	Pt(1,2),Pt(3,4),
	//	Pt(5,6),Pt(7,8),
	//	Pt(9,10),Pt(11,12)
	//};
	//for (int i = 0; i < 3; ++i) {
	//	cout << p[i][0].get_x() << " ";
	//	cout << p[i][0].get_y() << "\n";
	//	cout << p[i][1].get_x() << " ";
	//	cout << p[i][1].get_y() << "\n";
	//}
	//cout << "\n";

	//exeam ob, *p;
	//ob.set_a(2);
	//ob.show_a();
	//p = &ob;
	//p->show_a();

	//exeam ob[2], *p;
	//ob[0].set_a(10);
	//ob[1].set_a(20);
	//p = ob;
	//p->show_a();
	//++p;
	//p->show_a();

	//Pt op[4] = {Pt(1,2),Pt(3,4), Pt(5,6), Pt(7,8)};
	//Pt* p = &op[3];
	//for (int i = 0; i < 4; ++i) {
	//	cout << "x= " << p->get_x() << " ";
	//	cout << "y= " << p->get_y() << "\n";
	//	--p;
	//}
	//cout << "\n";

	//A a(5);
	//A* p1 = &a;
	//int A::*p2 = &A::z;
	//cout << a.*p2 << endl;
	//cout << p1->*p2 << endl;
	//cout << a.z << endl;

	Coord op(5,6);
	Coord* p1 = &op;
	int (Coord::*p_getx)();
	p_getx = &Coord::getx;
	cout << p1->getx() << endl;
	cout << op.getx() << endl;
	cout << (op.*p_getx)() << endl;
	cout << (p1->*p_getx)() << endl;

	system("pause");
	return 0;
}
*/

//2 C++ const 的使用
//2.1
//2.1.1 const 对象的一般形式
//(1)类型名 const 对象名[(构造实参表列)];
//(2)const 类型名 对象名[(构造实参表列)];
//常对象必须要有初值（因为以后不能改值了）。
//2.1.2 限定作用
//定义为const的对象的所有数据成员的值都不能被修改。
//调用非const成员函数，编译错误。但构造函数除外。
//2.1.3 mutable成员
//对数据成员声明为mutable（易变的）时，即使是const对象，仍然可以修改该数据成员值。

//2.2 常对象成员
//2.2.1 常数据成员
//类中声明了常数据成员, 构造函数只能通过初始化列表初始化该数据成员, 其他函数不能对该成员赋值。
//2.2.2 常成员函数 --> 在类中用关键字const说明的函数
//类型说明符 函数名(参数表) const;
//如果一个对象声明为常对象，该对象只能调用常成员函数，不能调用普通成员函数。而且常成员函数也不能更新对象的数据成员。
//常成员函数只能引用本类的数据成员，不能修改它们。（注意：可改mutable成员）
//
//2.2.3 常成员的使用
//a) 若在一个类中，有些数据成员的值允许改变，另一些数据成员的值不允许改变，则可将部分数据成员声明为const，以保证其值不被改变，可用非const的成员函数引用这些数据成员的值，并修改非const数据成员的值。
//b) 若要求所有数据成员的值都不允许改变，则可将所有的数据成员声明为const，或将对象声明为const(常对象)，然后用const成员函数引用数据成员，起到“双保险”的作用，切实保证数据成员不被修改。
//c) 若已定义了一个常对象，则只能调用const成员函数，不能调用非const成员函数(不论这些函数是否会修改对象中的数据)。若需要访问对象中的数据成员，可将常对象中所有成员函数都声明为const成员函数，但应确保在函数中不修改对象中的数据成员。
//
//2.4 指向常对象的指针变量
//2.4.1 指向常对象的指针变量的一般形式
//const 类型 *指针变量名
//
//2.4.2 关于指向常对象的指针变量的说明
//(1)指向常对象（变量）的指针变量，不能通过它来改变所指向目标对象的值，但指针变量的值可变
//(2)如果被声明为常对象（变量），只能用指向常对象（变量）的指针变量指向它
//(3)指向常对象（变量）的指针除了可以指向常对象（变量）外，还可以指向未被声明为const的对象（变量）。此时不能通过此指针变量改变该变量的值。
//(4)指向常对象（变量）的指针可指向const和非const型的对象（变量），而指向非const变量的指针只能指向非const的对象（变量）。
//(5)函数的形参指向非const变量的指针，实参只能用指向非const变量的指针，而不能用指向const变量的指针，这样，可改变形参指针所指变量(也就是实参指针所指向的变量)的值。
//(6)函数形参指向const变量的指针，允许实参是const或非const指针。
//(7)基本规则：希望函数调用时对象的值不被修改，形参定义为指向常对象的指针，同时用对象的地址作实参(对象可以是const或非const型)。
//要求该对象不仅在调用函数过程中不被改变，而且要求它在程序执行过程中都不改变,则应把它定义为 const型
//
//2.5 对象的常引用
//常指针和常引用作函数参数。能保证数据安全，使数据不能被随意修改，在调用函数时不必拷贝实参，提高程序效率
//
//2.6 const型数据的小结
//class Time {
//public:
//	Time(int h,int m,int s) :hour(h),minute(m),sec(s) {}// 通过参数初始化表对常数据成员hour初始化
//	//Time(int h) { hour = h; }//错误
//	void show_Time() const;
//private:
//	const int hour;
//	int minute;
//	int sec;
//};
//void Time::show_Time() const{
//	cout << hour << minute << sec << endl;
//}


//class Date {
//public:
//	Date(int y, int m, int d);
//	void showDate();
//	void showDate() const;
//	//const int &r;
//private:
//	const int year;
//	const int month;
//	const int day;
//};
//Date::Date(int y, int m, int d) :year(y), month(m), day(d) { }
//inline void Date::showDate() {
//	cout << "ShowDate1:\n";
//	cout << year << "." << month << "." << day << endl;
//}
//inline void Date::showDate() const{
//	cout << "ShowDate2:\n";
//	cout << year << "." << month << "." << day << endl;
//}

//int add(const int& i, const int& j) {
//	return i + j;
//}

//class Time {
//public:
//	Time() {
//		hour = 0;
//		minute = 0;
//	}
//	void set_Hour(int h) const { hour = h; }
//	void set_Minute(int m) { minute = m; }
//	void show_Time() const {
//		cout << hour << ":" << minute << endl;
//	}
//private:
//	mutable int hour;
//	int minute;
//};

//class Time {
//public:
//	Time(int, int, int);
//	int hour;
//	int minute;
//	int sec;
//};
//Time::Time(int h, int m, int s){
//	hour = h;
//	minute = m;
//	sec = s;
//}
//void fun1(Time &t){ // t 是对象引用
//	t.hour = 18;
//}
//void fun2(const Time &t){ // t 为常引用
//	t.hour = 18; // 错误 
//}

//class Sample {
//public:
//	int m;
//	Sample(int i, int j) { m = i; n = j; }
//	void setvalue(int i) { n = i; }
//	void disply() {
//		cout << "m=" << m << endl;
//		cout << "n=" << n << endl;
//	}
//private:
//	int n;
//};


/*
int main() {
	//Date date1(2000,1,2);
	//date1.showDate();

	//int a = 10;
	//int b = 20;
	//cout << a << "+" << b << "=" << add(a,b) << endl;

	//Date date1(1998, 4, 28);
	//date1.showDate();
	//const Date date2(2002, 11, 14);
	//date2.showDate();

	//const int a = 10, b = 20;
	//const int* pa = &a;//正确
	//int* pb = &b;//错误：非 const 型指针

	//pa = &b;//也可指向非 const 型的变量
	//*pa = 30;//指向const型的指针不能改目标值

	//void f(Time* pt);
	//Time* p1;
	//const Time* p2;
	//f(p1);//正确
	////f(p2);//错误

	//void g(const Time* pt);
	//Time* p1;
	//const Time* p2;
	//g(p1);//正确
	//g(p2);//正确

	//Time t1(10, 13, 56);
	//fun1(t1);
	//cout << t1.hour << endl;

	Sample a(10, 20); //若为:const Sample a(10,20);
	a.setvalue(40);//不能修改常对象的数据成员
	a.m = 30; //不能修改常对象的数据成员
	a.disply();//常对象不能调用普通成员函数

	system("pause");
	return 0;
}
*/


//3 C++ vector 使用注意事项
//#include <algorithm>
//3.1 初始化
//c++ 11新增大括号{}初始化方式，注意与()的区别

//3.2 push_back
//通过push_back添加新的元素进入vector后，vector的内存有时候会发生变化，这取决于size和capacity大小
//3.2.1 对于stl的容器，都有成员：
//begin()  //起始位置 
//end() //结束位置 
//size() //当前大小 
//capacity() //当前容量，即已申请的内存大小
//3.2.2 
//vector连续内存，有三个标识内存的位置，start，end，finish， size = end - start， capacity = finish - start

//3.3 erase,remove
//对于vector, remove使迭代器向后移动来删除，将未删除的元素放在前面，并返回指向新位置的迭代器


/*
void printvec(vector<int>& v) {
	auto it = v.begin();
	for (; it != v.end(); ++it) {
		cout << *it << " ";
	}
	cout << "\n";
}


int main() {
	//vector<int> v1(5);
	//vector<int> v2{ 5 };
	//printvec(v1);
	//cout << "\n";
	//printvec(v2);

	vector<int> v1 = {1,2,3,4,5,3,7,8,9};
	//remove(v1.begin(),v1.end(),3);//将未删除元素前移
	v1.erase(remove(v1.begin(),v1.end(),3),v1.end());//真正的删除
	cout << "v1.size()= " << v1.size() << endl;
	cout << "v1.capacity()= " << v1.capacity() << endl;
	printvec(v1);

	system("pause");
	return 0;
}
*/


//4 从 C++ std::shared_ptr 原理来看看栈溢出的危害
//4.1 shared_ptr实现包含了两部分，
//指向堆上创建的对象的裸指针，raw_ptr
//指向内部隐藏的、共享的管理对象。share_count_object
//4.2 
//use_count，当前这个堆上对象被多少对象引用了，引用计数。			  标记"被管理对象"的生命周期
//weak_count，这个管理对象被多少个智能指针共享了，管理对象的引用计数。标记"  管理对象"的生命周期

//5 C++ 11 特性：auto 关键字

//5.1 在定义模板函数时，用于声明依赖模板参数的变量类型。
//template <typename _Tx, typename _Ty>
//void Multiply(_Tx x, _Ty y){
//	auto v = x*y;
//	std::cout << v;
//}

//5.2 模板函数依赖于模板参数的返回值
//auto作用:返回值占位，只是为函数返回值占了一个位置，真正的返回值是decltype(_Tx*_Ty)。
//template <typename _Tx, typename _Ty>
//auto multiply(_Tx x, _Ty y)->decltype(_Tx*_Ty){
//	return x*y;
//}

//5.3 注意事项
//(1) auto 变量必须在定义时初始化，这类似于const关键字。
//(2) 初始化表达式是引用，则去除引用语义。
//(3) 初始化表达式为const或volatile（或兼有），则除去const / volatile语义。
//(4) auto关键字带上&，则不去除const语意。
//(5) 初始化表达式为数组，auto推导类型为指针。
//(6) 表达式为数组且auto带上&，推导类型为数组。
//(7) 函数或模板参数不能被声明为auto
//(8) auto仅是一个占位符，不是一个真正的类型

/*
int main() {
	//int a = 10;
	//int &b = a;
	//auto c = b;//c的类型为int而非int&（去除引用）
	//auto &d = b;//此时c的类型才为int&

	//const int a1 = 10;
	//auto  b1 = a1; //b1的类型为int而非const int（去除const）
	//const auto c1 = a1;//此时c1的类型为const int
	//b1 = 100;//合法
	////c1 = 100;//非法

	//const int a2 = 10;
	//auto &b2 = a2;//因为auto带上&，故不去除const，b2类型为const int
	//b2 = 10; //非法
	//cout << "type(b2)=" << typeid(b2).name() << endl;//int ? 应该是const int

	//int a3[3] = { 1, 2, 3 };
	//auto b3 = a3;
	//cout << typeid(b3).name() << endl;//int*

	//int a7[3] = { 1, 2, 3 };
	//auto& b7 = a7;
	//cout << typeid(b7).name() << endl;//int[3]
	
	system("pause");
	return 0;
}
*/


//6 应该了解的一些 C++ 特性

//6.1 auto 概念 --> 让编译器在编译时自动推断数据类型
//当使用 auto 时，必须确保编译器可通过某种方式推断数据类型。

//6.2 lambda 表达式
//没有命名的函数对象，可在不同作用域捕获变量，还可以分配给变量。
//方括号[]作为lambda 表达式的开始。定义函数作用域，即它对局部变量和对象有多少权限。
//(1)［］代表空。不能在 lambda 表达式中使用外部作用域的局部变量。只能使用参数。
//(2)［＝］通过值获取作用域内的局部对象（局部变量和参数），只可使用不可修改。
//(3)［&］通过引用获取作用域内的局部对象（局部变量和参数），即你可以像下面例子中一样修改它。
//(4)［this］可通过值获取 this 指针。
//(5)［a, &b］通过值获取对象 a, 通过引用获取对象 b。
//快速实现一些小功能但并不想为此单独编写整个函数时，lambda 非常有用。另一种非常普遍的应用是将其作为比较函数。

//6.3 编译时执行 constexpr
//有一些表达式要计算，它的值一旦初始化就不变。可预先计算该值并作为宏来使用。或者可使用 constexpr。
//(1) 声明为 constexpr 的函数非常重要的一点，参数必须是 constexpr 或 const。否则，该函数会像普通函数一样执行，即不会在编译时预先计算。
//(2) 变量也同样可以是 constexpr。
//(3)  c++17中，引入了 constexpr-if 和 constexpr-lambda

//6.4 tuple
//tuple 是一组各种数据类型的固定大小的集合

//6.5 类模版参数推断
//c++17 开始，参数推断也适用于标准类模版。此前，该特性只支持函数模版。

//6.6 智能指针


//#include <map>
//#include <algorithm>
//#include <tuple>

//void populate(auto& data) {
//	data.insert({ "a",{1,4} });
//	data.insert({ "b",{ 3,1 } });
//	data.insert({ "c",{ 2,3 } });
//}
//
//auto merge(auto data, auto other_data) {
//	auto ret = data;
//	for (auto it : other_data) {
//		ret.insert(it);
//	}
//	return ret;
//}

//constexpr long long fib(int n) {
//	if (n == 1) return 1;
//	return fib(n-1)*n;
//}


/*
int main() {
	//map<string, pair<int, int>> data;
	//map<string, pair<int, int>> other_data;
	//populate(data);
	//other_data.insert({ "d",{5,3} });
	//auto ret_data = merge(data,other_data);

	//for (auto itr : ret_data) {
	//	auto v1 = itr.second.first;
	//	auto v2 = itr.second.second;
	//	cout << itr.first << "" << v1 << "" << v2 << endl;
	//}

	//vector<pair<int, int>> data = { {1,3},{5,7},{9,11} };
	//sort(data.begin(), data.end(), [](auto a, auto b) {
	//	return a.second < b.second;
	//});
	////vector<int> data = {1,2,3,4,5};

	//for (auto it : data) {
	//	cout << it.first << "," << it.second << " ";
	//}
	//cout << "\n";

	//vector<int> vi = {1,3,5,7,9,2,4,6,8};
	//int m = 9;
	//for_each(vi.begin(), vi.end(), [&m](int& val) {  //int& val --> 真正改变 vector
	//	val *= m--;
	//});
	//for (int& val : vi) {
	//	cout << val << " ";
	//}
	//cout << "\n";

	//const long long bigval = fib(20);
	//cout << bigval << endl;

	//auto user_info = make_tuple("M","abcde",25);
	//cout << get<0>(user_info) << endl;
	//cout << get<1>(user_info) << endl;
	//cout << get<2>(user_info) << endl;
	//string first_name, last_name;int age;
	//tie(first_name, last_name, age) = user_info;
	//cout << first_name << " " << last_name << " " << age << endl;

	//pair<string, int> user1 = { "M", 25 }; // previous
	//pair user2 = { "M", 25 }; // C++17

	// previous
	//tuple<string, string, int> user("M", "Chy", 25);
	//// deduction in action! 
	//tuple user2("M", "Chy", 25);

	system("pause");
	return 0;
}
*/


//7 C++ 类的默认函数
//7.1 在C++中，一个类有八个默认函数：
//(1) 默认构造函数；
//(2) 默认拷贝构造函数；
//(3) 默认析构函数；
//(4) 默认重载赋值运算符函数；
//(5) 默认重载取址运算符函数；
//(6) 默认重载取址运算符const函数；
//(7) 默认移动构造函数（C++11）；
//(8) 默认重载移动赋值操作符函数（C++11）。

//只声明一个空类，不做任何事情，编译器自动生成1、2、4和3。这些函数只在第一次被调用时，才会被编译器创建。
//这些默认函数的实现就是什么都不做。这些函数都是inline和public

//7.2 C++11新增标识符default和delete,控制这些默认函数是否使用。
//(1) default：使用类的默认行为，如：A() = default;
//(2) delete：禁用，如：A() = delete;
//(3) override：强制重写基类虚函数；
//(4) final：禁止重写基类虚函数；

//class A {
//public:
//	A();
//	A(const A&);//默认拷贝构造函数
//	~A();
//	A& operator=(const A&); //默认重载赋值运算符函数
//	A* operator&();				//默认重载取址运算符函数
//	const A* operator& () const;//默认重载取址运算符const函数
//	A(A&&);					//默认移动构造函数
//	A& operator=(const A&&);//默认重载移动赋值操作符
//	
//};













// ------C语言与C++编程------

//1 C/C++指针、引用和常量
//1.1 常量指针和指针常量
//常量指针: 指向常量的指针
//指针常量: 常量
//指向常量的指针常量

//1.2 引用和常量引用
//当常量引用的初始值是变量，可通过变量修改常量，
//			当初始值是const,不能修改

//使用引用常量传递参数 --> upper(char* const &a);
//如果不想让函数修改变量, 使用常量引用，因为传值会在函数内创建副本，降低效率。

/*
int main() {
	int a = 10;
	const int& b = a;
	cout << "b= " << b << "\n";//10
	a = 20;
	cout << "b= " << b << "\n";//20

	const int& c = a * 2;
	cout << "c= " << c << "\n";//40
	a = 30;
	cout << "c= " << c << "\n";//40

	system("pause");
	return 0;
}
*/






















































