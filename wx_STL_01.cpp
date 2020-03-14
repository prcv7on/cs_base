

#include <iostream>
//#include <sstream>
#include <vector>
#include <string>
//#include <list>
//#include <queue>
//#include <deque>
//#include <stack>
//#include <set>
#include <map>
//#include <algorithm>
//#include <functional>
//#include <numeric>
//#include <random>
//#include <iterator>
//#include <utility>
//#include <iomanip>

//#include <stdlib.h>
//#include "vector.h"
//#include <cstring>
#include <cctype>
//#include "customer.h"
//#include "checkout.h"
#include "name.h"
#include "quotations.h"

using namespace std;
//using distribution = uniform_int_distribution<>;

//--------- Linux C C++专栏 ---------

//1 C++进阶系列之STL（1）---剖析List部分源码

//1.1 库函数的设计第一位是通用性，模板为其提供了可能；标准模板库中的所有算法和容器都是通过模板实现的。
//STL(标准模板库)是 C++最有特色，最实用的部分之一。

//1.2 总结
//(1) 迭代器的本质是一个内部类，它将是一个对象，内部数据成员是一个指向节点的指针；
//(2) 迭代器对->的重载返回节点内部数据的地址，而不是节点的地址
//(3) 迭代器对每种数据结构的实现均不相同，(Stack, queue, list...........)
//(4) 空间配置器: 对所有数据结构而言，只有一份，作用：申请，释放空间，构造，析构对象；

/*
int main(void) {
	list<int> li;
	for (int i = 1; i < 11; ++i) {
		li.push_back(i);
	}
	auto it = li.begin();
	while (it != li.end()) {
		cout << *it++ << "-->";
	}
	cout << "nullptr\n";

	getchar();
	return  0;
}
*/

//2 C++进阶系列之STL（2）---SGI版本空间配置器
//2.1 STL中的空间配置器
//在STL中，空间配置器分了2组，分别为一级和二级空间配置器，但它们都有各自运用的场合: 一级空间配置器分配的空间大于128B，二级分配空间小于128B
//2.2 SGI中STL的空间配置器设计哲学:
//(1) 向system heap要求申请空间
//(2) 考虑多线程的状态
//(3) 考虑内存不足时的应变措施
//(4) 考虑过多"小型区块"可能造成的内存碎片问题

//2.3 一级空间配置器
//2.3.1 本质: 模仿实现了set_new_handler机制
//set_new_handler机制的实现: (1)定义一个函数指针 (2)定义一个函数 (3)赋值比较
//2.3.2 第一级空间配置器就是: (1)对malloc、free的简单封装；(2)模拟C++的set_new_handler()以处理内存不足的情况

//2.3.3 总结:
//(1)一级空间配置器其实就是, 先自己开辟空间，要是失败了:
//(2)调用处理空间失败的函数，在其内部，先看在外面有没有写针对这个的处理函数. 若没写，异常抛出，程序结束;
//(3)要是写了，就调用自己写的函数，在次分配空间，进入死循环中，直到空间分配成功，方可退出循环;

//2.3 SGI第二级空间配置器
//(1)维护16个自由链表，分别有16种小型区块的配置能力；若内存不足，调用一级空间配置器(那里有处理程序);
//(2)若申请空间的需求大于128B, 就调用一级空间配置器。
//2.3.1 总结:
//二级空间配置器(最后山穷水尽)--->调用一级空间配置器---->(1)抛出异常 (2)调用自己编写的处理函数

//2.3.2 STL内存配置思想：
//C++STL是两级配置内存：
//(1) 第一级管理大块内存，保证有类似new-handler的机制；
//(2) 第二级管理小块内存，为更好管理内存碎片，建立16个链表，各链表"穿"着一块一块固定大小的内存，这16个链表（0至15）分别"穿"的内存是8、16、24…128倍数关系。
//需要内存时，从"合适"的链表取走，若"合适"的链表内存不够用，从内存池拿，若内存池不够用，从运行时heap里拿，若heap也溢出了，就交给第一级配置器，因为它有set_new-handler机制。
//(3) 所以，当堆上的东西用完之后，的赶紧还回来。


//3 C++进阶系列之STL（3）---STL的框架实现
//3.1 模板的特化
//泛化模板 : 对各种不同版本的特殊化处理---->特化;
//3.2 萃取
//拿相同的代码提取不同的类型;
//3.3 分析
//(1) vector的空间灵活性更高;
//(2) POD：也就是标量型别，也就是传统的型别，采取最保险安全的做法, 调用构造函数；否则的话，就是调用系统的，基本类型就是true;
//(3) 空构造了2个类型，针对不同萃取得到其_false_type或_true_type; 就可以调用不同的函数，进行空间的分配，存在效率上的差异!!!
//_true_type：将调用系统的填充函数，效率比较高.
//(4) 容器、算法单独好实现，关键是通用性，模板是一种很好的解决方案，真正关键之处还在 : 迭代器的实现;
//(5) 空间配置器负责分配、回收空间，只有一个；迭代器针对不同的容器有不同的实现方法!!!

//class A {};
//int main() {
//	vector<A> va(10);
//	getchar();
//	return 0;
//}

//4 C++进阶系列之STL（4）---函数适配器
//绑定器和取反器
//(1) 绑定器：把二元函数对象中一个参数固定，使之转为一元函数，C++标准库中提供了2种预定义的binder适配器，bind1st、bind2nd，分别绑定了第一个 / 第二个参数；
//(2) 取反器：翻转的适配器；
//(3) 一元函数：针对1个参数，只有一个返回值；
//	  二元函数：针对2个参数，只有一个返回值；
//(4) 绑定器针对的是参数，绑定后其值不变，取反器对其进行取反；
//(5) 可通过调试工具 - g；对源码进行剖析；

/*
int main(void) {
	int a[] = { 1,2,3,4,5,6,7,8,9 };
	int n = sizeof(a) / sizeof(int);
	int cnt = count(a,a+n,4);
	cout << "cnt=" << cnt << endl;//1

	//cnt = count_if(a,a+n,bind2nd(greater<int>(),4));//x>4
	//cout << "cnt=" << cnt << endl;//5
	//cnt = count_if(a, a + n, bind1st(less<int>(), 4));//4<x
	//cout << "cnt=" << cnt << endl;//5
	cnt = count_if(a, a + n, bind(greater<int>(),placeholders::_1,4));
	cout << "cnt=" << cnt << endl;//5

	getchar();
	return 0;
}
*/

//5 C++进阶系列之STL（5）---vector，deque，list相关操作
//5.1 vector
//(1)对动态数组元素的添加和删除、获取
//(2)vector的初始化
//(3)vector中迭代器的正向和反向遍历
//(4)vector中的元素删除操作
//5.2 deuqe 双端数组 分段连续的内存空间来存储元素
//5.3 stack
//5.4 queue

//5.5 priority_queue --> 定义: priority_queue<Type, Container, Functional>
//Type: 数据类型，Container: 容器类型（Container必须是数组实现的容器，vector,deque等，但不能list。STL默认vector），Functional: 比较方式
//自定义数据类型, 才需要传入三个参数，使用基本数据类型时，只需传入数据类型，默认大顶堆

//5.6 list
//(1)list的遍历
//(2)list的删除

/*
template<typename T>
void printV(vector<T>& v) {
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	}
	cout << "\n";
}

int main() {
	//vector<int> vi;
	//vi.push_back(2);
	//vi.push_back(3);
	//vi.push_back(4);
	//vi.emplace_back(5);
	//cout << "vi.size()=" << vi.size() << endl;//4
	//cout << "vi.front()=" << vi.front() << endl;//2
	//vi.front() = 22;
	//vi.back() = 55;
	//while (vi.size() > 0) {
	//	cout << vi.back() << " ";
	//	vi.pop_back();
	//}
	//cout << "\n";

	//vector<int> v1;
	//v1.push_back(2);
	//v1.push_back(3);
	//v1.push_back(4);
	//v1.emplace_back(5);
	//vector<int> v2 = v1;
	//vector<int> v3(v1.begin(),v1.begin()+2);
	//printV(v1);

	//vector<int> v5(10);//前10个元素初始化为0；
	//v5.push_back(100);
	//v5.push_back(200);
	//printV(v5);

	//vector<int> v1(10);
	//for (int i = 0; i < 10; ++i) {
	//	v1[i] = i + 1;
	//}

	//auto it = v1.begin();
	//while (it != v1.end()) {
	//	cout << *it++ << " ";
	//}
	//cout << "\n";

	//auto rit = v1.rbegin();
	//while (rit != v1.rend()) {
	//	cout << *rit++ << " ";
	//}
	//cout << "\n";

	vector<int> v1(10);
	for (int i = 0; i < 10; ++i) {
		v1[i] = i + 1;
	}
	v1.erase(v1.begin(),v1.begin()+3);
	printV(v1);//4 5 6 7 8 9 10
	v1.erase(v1.begin());
	printV(v1);//5 6 7 8 9 10
	v1[1] = 2;
	v1[3] = 2;
	auto it = v1.begin();
	while (it != v1.end()) {
		if (*it == 2) {
			it=v1.erase(it);
		}
		++it;
	}
	printV(v1);//5 7 9 10
	v1.insert(v1.begin(),100);
	v1.insert(v1.end(),200);
	printV(v1);//100 5 7 9 10 200

	getchar();
	return 0;
}
*/

/*
template<typename T>
void printD(deque<T>& d) {
	auto it = d.begin();
	while (it != d.end()) {
		cout << *it++ << " ";
	}
	cout << "\n";
}

int main() {
	deque<int> d1;
	d1.push_back(1);
	d1.push_back(3);
	d1.push_back(5);
	d1.push_front(2);
	d1.push_front(4);
	d1.push_front(6);
	printD(d1);//6 4 2 1 3 5
	cout << "d1.front()=" << d1.front() << endl;//6
	cout << "d1.back()=" << d1.back() << endl;//5
	d1.pop_front();
	printD(d1);//4 2 1 3 5
	d1.pop_back();
	printD(d1);//4 2 1 3

	auto it = find(d1.begin(),d1.end(),3);
	if (it != d1.end())
		cout << "idx=" << distance(d1.begin(), it);
	else
		cout << "not found.";
	cout << "\n";

	getchar();
	return 0;
}
*/

/*
class Teacher {
public:
	void printS() {
		cout << "age=" << age << endl;
	}
public:
	int age;
	char name[15];
};

int main() {
	Teacher t1, t2, t3;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;
	stack<Teacher*> st;
	st.push(&t1);
	st.push(&t2);
	st.push(&t3);
	while (!st.empty()) {
		st.top()->printS();
		st.pop();
	}

	getchar();
	return 0;
}
*/

/*
class Teacher {
public:
	int age;
	char name[25];
	void printQ() {
		cout << "age=" << age << endl;
	}
};

int main() {
	Teacher t1, t2, t3;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;
	queue<Teacher*> qt;
	qt.push(&t1);
	qt.push(&t2);
	qt.push(&t3);
	while (!qt.empty()) {
		qt.front()->printQ();
		qt.pop();
	}

	getchar();
	return 0;
}
*/

/*
template<typename T>
void printPQ(T& pq) {
	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << "\n";
}

int main() {
	priority_queue<int> pq1;
	//priority_queue<int, vector<int>, less<int> > pq2;
	priority_queue<int, vector<int>, greater<int> > pq3;
	pq1.push(33);
	pq1.push(11);
	pq1.push(22);
	pq1.push(77);
	pq1.push(55);
	pq1.push(99);
	cout << "pq1.top()=" << pq1.top() << endl;//99
	cout << "pq1.size()=" << pq1.size() << endl;//6
	printPQ(pq1);//99 77 55 33 22 11

	pq3.push(33);
	pq3.push(11);
	pq3.push(22);
	pq3.push(77);
	pq3.push(55);
	pq3.push(99);
	cout << "pq3.top()=" << pq3.top() << endl;//11
	cout << "pq3.size()=" << pq3.size() << endl;//6
	printPQ(pq3);//11 22 33 55 77 99

	getchar();
	return 0;
}
*/

/*
template<typename T>
void printL(list<T>& lt) {
	for (auto it = lt.begin(); it != lt.end(); ++it) {
		cout << *it << " ";
	}
	cout << "\n";
}

int main(void) {
	//list<int> li;
	//cout << "li.size()=" << li.size() << endl;
	//for (int i = 1; i < 10; ++i) {
	//	li.push_back(i);
	//}
	//cout << "li.size()=" << li.size() << endl;
	//printL(li);//1 2 3 4 5 6 7 8 9

	//auto it = li.begin();
	//++it; ++it; ++it;
	//li.insert(it,100);//insert方法都是默认前插
	//printL(li);//1 2 3 100 4 5 6 7 8 9

	list<int> li;
	for (int i = 1; i < 10; ++i) {
		li.push_back(i);
	}
	auto it = li.begin();
	advance(it,3);
	li.erase(li.begin(),it);
	printL(li);//4 5 6 7 8 9

	li.insert(li.begin(),100);
	li.insert(li.begin(), 100);
	li.insert(li.begin(), 100);
	printL(li);//100 100 100 4 5 6 7 8 9
	li.remove(100);
	printL(li);//4 5 6 7 8 9

	getchar();
	return 0;
}
*/

//6 C++进阶系列之STL（6）---set，map相关操作
//6.1 set
//(1) set的删除、插入操作
//set底层是红黑树,元素唯一,元素默认从小到大排列,元素按排序规则插入,不能指定插入位置
//(2) set的排序
////对于基础数据可以进行排序,复杂数据类型的排序------>仿函数解决
//(3) set中为复杂数据类型时的排序
//(4) set中迭代器的使用
//6.2 multiset
//6.3 map
//(1) map元素的添加、遍历、删除
//(2) map中4种初始化的分析
//(3) map查找
//6.4 multimap


//template<typename T>
//void printSet(T& st) {
//	auto it = st.begin();
//	while (it != st.end()) {
//		cout << *it++ << " ";
//		//cout << it->age << " " << it->name << "\n";
//		//++it;
//	}
//	cout << "\n";
//}

//class Stu {
//public:
//	int age;
//	char name[25];
//	Stu(const char* name, int age) {
//		strcpy_s(this->name,name);
//		this->age = age;
//	}
//};
//
////仿函数：重载了()
//struct FunStu {
//	bool operator()(const Stu& left, const Stu& right) {
//		return left.age < right.age ? true : false;
//	}
//};

/*
int main(void) {
	//set<int> si;
	//for (int i = 0; i < 5; ++i) {
	//	si.insert(34);
	//	si.insert(24);
	//	si.insert(14);
	//	si.insert(84);
	//	si.insert(-4);
	//}
	//si.insert(100);
	//si.insert(100);
	//printSet(si);//-4 14 24 34 84 100

	//while (!si.empty()) {
	//	cout << *si.begin() << " ";
	//	si.erase(si.begin());
	//}
	//cout << "\n";//-4 14 24 34 84 100

	//set<int> si1;////默认排序从小到大
	//set<int, less<int> > si2;
	//set<int, greater<int> > si3;//从大到小的输出;
	//si3.insert(11);
	//si3.insert(45);
	//si3.insert(99);
	//si3.insert(77);
	//si3.insert(66);
	//printSet(si3);//99 77 66 45 11

	//Stu s1("s1", 31);
	//Stu s2("s2", 22);
	//Stu s3("s3", 55);
	//Stu s4("s4", 11);
	//Stu s5("s5", 31);////此时,由于比较的是age,所以将会插入失败,因为仿函数中用的是age做的键值;
	//set<Stu, FunStu> ssf;
	//auto pair1 = ssf.insert(s1);
	//cout << (pair1.second == true ? "insert s1 OK." : "insert s1 failed.") << "\n";//OK

	//ssf.insert(s2);
	//ssf.insert(s3);
	//ssf.insert(s4);
	//auto pair5= ssf.insert(s5);
	//cout << (pair5.second == true ? "insert s5 OK." : "insert s5 failed.") << "\n";//failed
	//printSet(ssf);

	set<int> si;
	for (int i = 0; i < 10; ++i) {
		si.insert(i + 1);
	}
	printSet(si);//1 2 3 4 5 6 7 8 9 10

	auto it1 = si.find(5);
	int num = si.count(5);
	auto it2 = si.lower_bound(5);
	cout << "*it1=" << *it1 << endl;//5
	cout << "num=" << num << endl;//1
	cout << "*it2=" << *it2 << endl;//5
	si.erase(5);
	auto mypair = si.equal_range(5);//含一对迭代器pair  第一个指向首个 >=key的元素，第二个指向首个 >key的元素。
	cout << *mypair.first << ", " << *mypair.second << endl;//6,6

	getchar();
	return 0;
}
*/

/*
template<typename T>
void printMS(multiset<T>& ms) {
	auto it = ms.begin();
	while (it != ms.end()) {
		cout << *it++ << " ";
	}
	cout << "\n";
}

int main() {
	multiset<int> msi;
	int tmp = 0;
	cout << "Input values in multiset: ";
	cin >> tmp;
	while (tmp!=0){
		msi.insert(tmp);
		cout << "Input values in multiset: ";
		cin >> tmp;
	}
	printMS(msi);//1 2 3 3 4 5 7 7 9 9
	while (!msi.empty()) {
		cout << *msi.begin() << " ";
		msi.erase(msi.begin());
	}
	cout << "\n";//1 2 3 3 4 5 7 7 9 9

	getchar();
	getchar();
	return 0;
}
*/

/*
template<typename T1, typename T2>
void printMAP(map<T1, T2>& m) {
	cout << "print map: \n";
	auto it = m.begin();
	while (it != m.end()) {
		cout << it->first << "," << it->second << "\n";//key,value
		++it;
	}
}

int main() {
	//map<int, string> mis;//因为map是key-value结构,所以可以做成pair(对组)
	//mis.insert(pair<int, string>(1, "teacher01"));
	//mis.insert(pair<int, string>(2, "teacher02"));
	//mis.insert(make_pair(3, "teacher03"));
	//mis.insert(make_pair(4, "teacher04"));
	//mis.insert(map<int, string>::value_type(5, "teacher05"));
	//mis.insert(map<int, string>::value_type(6, "teacher06"));
	//mis[7] = "teacher07";
	//mis[8] = "teacher08";
	//printMAP(mis);

	//while (!mis.empty()) {
	//	auto it = mis.begin();
	//	cout << it->first << "," << it->second << "\n";
	//	mis.erase(it);
	//}

	//map<int, string> mis;
	//pair<map<int, string>::iterator, bool> mypair1 = mis.insert(pair<int, string>(1, "teacher01"));
	//mis.insert(pair<int, string>(2, "teacher02"));
	//pair<map<int, string>::iterator, bool> mypair3 = mis.insert(make_pair(3, "teacher03"));
	//mis.insert(make_pair(4, "teacher04"));
	//pair<map<int, string>::iterator, bool> mypair5 = mis.insert(map<int, string>::value_type(5, "teacher05"));
	//if (mypair5.second != true) {
	//	cout << "key 5 insert failed." << "\n";
	//}
	//else {
	//	cout << "key 5 insert OK.\n";
	//	cout << mypair5.first->first << "," << mypair5.first->second << endl;
	//}
	//pair<map<int, string>::iterator, bool> mypair6 = mis.insert(map<int, string>::value_type(5, "teacher06"));
	//if (mypair6.second != true) {
	//	cout << "key 5 insert failed." << "\n";//因为键值相同,所以插入会失败;
	//}
	//else {
	//	cout << "key 5 insert OK.\n";
	//	cout << mypair6.first->first << "," << mypair6.first->second << endl;
	//}
	////前三种初始化方法的返回值都为：pair(iterator, bool)
	//mis[7] = "teacher07";
	//mis[7] = "teacher08";
	//printMAP(mis);

	map<int, string> mis;
	mis.insert(pair<int, string>(1, "teacher01"));
	mis.insert(pair<int, string>(2, "teacher02"));
	mis.insert(make_pair(3, "teacher03"));
	mis.insert(make_pair(4, "teacher04"));
	mis.insert(map<int, string>::value_type(5, "teacher05"));
	mis.insert(map<int, string>::value_type(6, "teacher06"));
	mis[7] = "teacher07";
	mis[8] = "teacher08";
	printMAP(mis);

	//map的查找，返回值都是迭代器
	auto it1 = mis.find(2);
	if (it1 == mis.end())
		cout << "key 2 not found." << endl;
	else
		cout << "key 2 found.\t"<<it1->first << "," << it1->second << "\n";

	//pair<map<int, string>::iterator, map<int, string>::iterator> mypair = mis.equal_range(5);
	auto mypair = mis.equal_range(5);
	if (mypair.first == mis.end())
		cout << "the first iterator is postion >=5, not found.\n";
	else
		cout << "postion >=5 found.\t"<<mypair.first->first << "," << mypair.first->second << endl;
	if (mypair.second==mis.end())
		cout << "the first iterator is postion >5, not found.\n";
	else
		cout << "postion >5  found.\t"<<mypair.second->first << "," << mypair.second->second << endl;


	getchar();
	return 0;
}
*/

/*
class Person {
public:
	string name;
	string tel;
	int age;
	double saly;
};

int main(void) {
	Person p1, p2, p3, p4, p5;
	p1.name = "a1";p1.age = 31;
	p2.name = "a2";p2.age = 32;
	p3.name = "b3";p3.age = 33;
	p4.name = "b4";p4.age = 34;
	p5.name = "c5";p5.age = 35;
	multimap<string, Person> mmsp;
	mmsp.insert(make_pair("sale", p1));
	mmsp.insert(make_pair("sale", p2));
	mmsp.insert(make_pair("development", p3));
	mmsp.insert(make_pair("development", p4));
	mmsp.insert(make_pair("financial",p5));

	for (auto it = mmsp.begin(); it != mmsp.end(); ++it) {
		if (it->second.age == 32) {
			it->second.name = "name32";
		}
		cout << it->first << "\t" << it->second.name << endl;
	}
	cout << "transverse finished." << "\n";

	int cnt = mmsp.count("development");
	cout << "development部门人数:" << cnt << endl;
	cout << "development部门员工信息" << endl;
	auto it = mmsp.find("development");
	while (it != mmsp.end() && cnt) {
		cout<< it->first << "\t" << it->second.name << endl;
		++it;
		--cnt;
	}

	getchar();
	return 0;
}
*/


//7 C++进阶系列之STL（7）---STL学习思想
//(1) 模版：必须注意参数和返回值的模版
//(2) STL一系列的API：必须注意返回值
//(3) 容器中都是值拷贝, 而不是引用, 在执行插入时, 内部实行拷贝, 所以STL中插入类时, 一般都必须：无参构造函数, 拷贝构造函数, 重载 = 运算符, 必须的自己重写, 达到深拷贝!!!
//(4) 一元谓词：函数只有一个参数, 谓词：代表函数的返回值必须为bool类型;
//	  二元谓词：函数只有二个参数, 谓词：代表函数的返回值必须为bool类型;
//(5) 算法和具体的数据类型相分离：通过函数对象(仿函数)来实现，本质: 函数指针!!!
//(6) 容器和具体的数据类型相分离，通过模板实现的；
//(7) 各容器都有其对应的迭代器进行访问；
//(8) 所有容器都是通过空间配置器来分配空间的；
//(9) 函数适配器有一元、二元: 函数参数的绑定；


//8 C++进阶系列之STL（8）---仿函数
//本质：是一个对象，用起来像函数；
//原因：在类内对()进行了重载；
//仿函数和回调函数的区别

/*
template<typename T>
class ShowElem {
private:
	int n;
public:
	ShowElem() { n = 0; }
	void operator()(T& t) {		//类重载了(),此时可叫做函数对象;
		++n;
		cout << t << endl;
	}
	void printN() { cout << "n=" << n << endl; }
};

void main1() {
	int a = 10;
	ShowElem<int> SEi;
	SEi(a);		//函数对象()的执行,很像一个函数;所以又叫做仿函数;
                //函数对象可跟函数的调用一样,直接把对象当作函数名称来使用!!!
}

//函数对象和普通函数的区别:
template<typename T>
void FuncShowElem1(T& t) {	//函数模版
	cout << t << endl;
}

void FuncShowElem2(int& t) { //普通函数
	cout << t << endl;
}

void main2() {
	vector<int> vi;
	vi.push_back(1);
	vi.push_back(3);
	vi.push_back(5);
	for_each(vi.begin(),vi.end(), ShowElem<int>());//匿名函数对象 匿名仿函数;
	cout << "\n";
	for_each(vi.begin(), vi.end(), FuncShowElem2);//通过回调函数;谁使用for_each()
}

int main(void) {
	main1();
	main2();
	getchar();
	return 0;
}
*/


//9 C++进阶系列之STL（9）---find_if(),plus,for_each()的用法
//9.1 find_if()
//9.2 plus的使用
//plus 预定义好的函数对象,能实现不同数据 + 算法；
//实现了数据类型和算法的分离======》通过函数对象技术实现的;
//思考,怎么知道plus<type>是2个参数------>多看看源码;
//9.3 for_each()
//9.4 for_each()和transform()的区别
//for_each和transform的本质区别：
//结论：
//1、一般情况下,for_each所使用的函数对象,参数是引用,没有返回值;
//2、transform所使用的函数对象,参数一般不使用引用,而是还有返回值;

//template<typename T>
//class IsDiv {
//private:
//	T divisor;
//public:
//	IsDiv(const T& divisor) {
//		this->divisor = divisor;
//	}
//	bool operator()(T& t) {
//		return t%divisor == 0;
//	}
//};

//void main21() {
//	plus<int> intAdd;
//	int x = 10;
//	int y = 20;
//	int z = intAdd(x,y);
//	cout << "z=" << z << endl;//30
//
//	plus<string> strAdd;
//	string s1 = "aaa";
//	string s2 = "bbb";
//	string s3 = strAdd(s1,s2);
//	cout << "s3=" << s3 << endl;//aaabbb
//
//	vector<string> vs;
//	vs.push_back("bbb");
//	vs.push_back("aaa");
//	vs.push_back("ccc");
//	vs.push_back("zzz");
//	vs.push_back("ccc");
//	vs.push_back("ccc");
//	sort(vs.begin(),vs.end(),greater<string>());
//	for (auto it = vs.begin(); it != vs.end(); ++it) {
//		cout << *it << " ";
//	}
//	cout << "\n";//zzz ccc ccc ccc bbb aaa
//
//	string sc = "ccc";
//	int cnt = count_if(vs.begin(), vs.end(), bind(equal_to<string>(),placeholders::_1,sc));
//	cout << "cnt=" << cnt << endl;//3
//}

/*
int main(void) {
	//vector<int> vi;
	//for (int i = 10; i < 33; ++i) {
	//	vi.push_back(i);
	//}

	//int a = 4;
	//IsDiv<int> myDiv(a);
	//auto it1 = find_if(vi.begin(),vi.end(),myDiv);
	//cout << (it1 == vi.end() ? "a1 not found." : "a1 found.") << "\n";

	//auto it2 = vi.begin();
	//it2 = find_if(vi.begin(), vi.end(), IsDiv<int>(a));
	//cout << (it2 == vi.end() ? "a2 not found." : "a2 found.") << "\n";

	main21();

	getchar();
	return 0;
}
*/


//template<typename T>
//void printV(vector<T>& v) {
//	for (auto it = v.begin(); it != v.end(); ++it) {
//		cout << *it << " ";
//	}
//	cout << "\ntransverse finished.\n";
//}
//
//void show_elem(int& n) {
//	cout << n << " ";
//}
//
//class MyShow {
//private:
//	int num;
//public:
//	MyShow() { num = 0; }
//	void operator()(int& n) {
//		++num;
//		cout << n << " ";
//	}
//	void printNum() {
//		cout << "num=" << num << endl;
//	}
//};


/*
void ShowElem1(int& n) {
	cout << n << " ";
}

int ShowElem2(int& n) {
	cout << n << " ";
	return n;
}

int main(void) {
	vector<int> vi;
	vi.push_back(1);
	vi.push_back(3);
	vi.push_back(5);

	//printV(vi);
	//for_each(vi.begin(), vi.end(), show_elem);//利用的是回调函数
	//cout << "\n--------------\n";
	//for_each(vi.begin(), vi.end(), MyShow());//利用的是函数对象(这个类中重载了())
	//cout << "\n--------------\n";
	//MyShow my1= for_each(vi.begin(), vi.end(), MyShow());
	//my1.printNum();

	vector<int> v2 = vi;
	for_each(vi.begin(),vi.end(),ShowElem1);
	cout << "\n--------------\n";
	transform(v2.begin(),v2.end(),v2.begin(),ShowElem2);//transform对回调函数的要求;返回值必须有
	cout << "\n--------------\n";

	getchar();
	return 0;
}
*/


//10 C++进阶系列之STL（10）---STL查找、排序、替换、集合算法
//10.1 STL查找算法
//10.2 STL排序算法
//10.3 STL拷贝替换
//10.4 STL集合算法

/*
void main_adjacent_find() {
	vector<int> vi = {1,2,2,3,5};
	auto it = adjacent_find(vi.begin(),vi.end());
	if (it == vi.end())
		cout << "duplicate not found." << "\n";
	else
		cout << *it << "\n";//2
	ptrdiff_t idx = distance(vi.begin(),it);
	cout << "idx=" << idx << "\n";//1
}

void main_binary_search() {
	vector<int> vi = {1,3,5,7,9};
	bool b = binary_search(vi.begin(), vi.end(), 7);
	cout << (b==true ? "found." : "not found.") << "\n";//found
}

void main_count() {
	vector<int> vi = {1,3,5,7,7,9,7};
	ptrdiff_t cnt = count(vi.begin(), vi.end(), 7);
	cout << "cnt=" << cnt << "\n";//3
}

bool GreaterThree(int num) {
	return num > 3 ? true : false;
}

void main_count_if() {
	vector<int> vi = {1,3,5,7,9};
	ptrdiff_t num = count_if(vi.begin(), vi.end(), GreaterThree);
	cout << "count_if=" << num << "\n";//3
}

void main_find() {
	vector<int> vi = { 1,3,5,7,9 };
	auto it = find(vi.begin(), vi.end(), 5);
	cout << "find=" << *it << "\n";//5
}

void main_find_if() {
	vector<int> vi = { 1,3,5,7,9 };
	auto it = find_if(vi.begin(), vi.end(), GreaterThree);
	cout << "find_if=" << *it << "\n";//5
}


int main(void) {
	main_adjacent_find();   //查找第一个重复的元素;
	main_binary_search();  //二分法查找某一个元素;
	main_count();  //查找某一个元素出现的次数; 针对基础数据类型
	main_count_if(); //用一个一元谓词,可以查找大于某一个数字的个数; 针对自定义的数据类型
	main_find();  //查找某一数据，通过迭代器指出; 针对基础数据类型
	main_find_if();  //查找某一数据，通过迭代器指出; 针对自定义数据类型;

	getchar();
	return 0;
}
*/

//template<typename T>
//void printV(vector<T>& v) {
//	for (auto it = v.begin(); it != v.end(); ++it) {
//		cout << *it << " ";
//	}
//	cout << "\n";
//}

/*
void main_merge() {
	vector<int> v1 = {1,3,5};
	vector<int> v2 = { 2,4,6 };
	vector<int> v3;
	v3.resize(v1.size()+v2.size());
	merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());
	printV(v3);//1 2 3 4 5 6
}

class Stu {
public:
	string m_name;
	int m_id;
	Stu(string name, int id) {
		m_name = name;
		m_id = id;
	}
};

bool cmp(Stu s1, Stu s2) {
	return (s1.m_id < s2.m_id);
}

void main_sort() {
	Stu s1("one",1);
	Stu s2("two", 2);
	Stu s3("three", 3);
	Stu s4("four", 4);
	vector<Stu> v1 = {s4,s1,s3,s2};
	for (auto it = v1.begin(); it != v1.end(); it++) {
		cout << it->m_id << "\t" << it->m_name << endl;
	}
	sort(v1.begin(),v1.end(),cmp);
	for (auto it = v1.begin(); it != v1.end(); it++) {
		cout << it->m_id << "\t" << it->m_name << endl;
	}
}

void main_random_shuffle() {
	vector<int> vi = {1,3,5,7};
	random_shuffle(vi.begin(),vi.end());
	printV(vi);
	string str = "abcdefg";
	random_shuffle(str.begin(),str.end());
	cout << "str=" << str << "\n";
}

void main_reverse() {
	vector<int> vi = {1,3,5,7};
	reverse(vi.begin(), vi.end());
	printV(vi);//7 5 3 1
}

int main() {
	main_merge(); //归并排序
	main_sort();
	main_random_shuffle();
	main_reverse();

	getchar();
	return 0;
}
*/

/*
void main_copy() {
	vector<int> v1 = {1,3,5};
	vector<int> v2;
	v2.resize(v1.size());
	copy(v1.begin(),v1.end(),v2.begin());
	printV(v2);//1 3 5
}

void main_replace() {
	vector<int> vi = {1,3,3,3,5};
	replace(vi.begin(),vi.end(),3,8);
	printV(vi);//1 8 8 8 5
}

bool great_equal(int& n) {
	return (n>=5 ? true: false);
}

void main_replace_if() {
	vector<int> vi = {1,8,8,8,5};
	replace_if(vi.begin(), vi.end(),great_equal,2);
	printV(vi);//1 2 2 2 5
}

void main_swap() {
	vector<int> v1 = {1,3,5};
	vector<int> v2 = { 2,4,6 };
	swap(v1,v2);
	printV(v1);// 2 4 6
}

void main_accumulate() {
	vector<int> vi = {1,3,5};
	int tmp = accumulate(vi.begin(),vi.end(),100);
	cout << "tmp=" << tmp << "\n";//109
}

void main_fill() {
	vector<int> vi = { 1,3,5 };
	fill(vi.begin(), vi.end(),8);
	printV(vi);//8 8 8
}


int main(void) {
	main_copy();  //拷贝
	main_replace();  //替换 基础数据类型
	main_replace_if();  //替换范围 自定义数据类型
	main_swap();  //交换容器中的内容
	main_accumulate(); //求和函数
	main_fill();

	getchar();
	return 0;
}
*/

//int main(void) {
//	vector<int> v1 = {1,3,5};
//	vector<int> v2 = { 1,1,1};
//	vector<int> v3;
//	v3.resize(v1.size()+v2.size());
//	set_union(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());
//	printV(v3);//1 1 1 3 5 0
//
//	getchar();
//	return 0;
//}



//---------码出名企路---------

//1 Vector同时返回排序和原索引
//bool cmp1(pair<int, int>& a, pair<int, int>& b) {
//	return a.second < b.second ? true : false;
//}

//template<typename T>
//vector<int> sort_Index(vector<T>& data) {
//	vector<int> idx(data.size());
//	iota(idx.begin(),idx.end(),0);
//	sort(idx.begin(), idx.end(), 
//		[&data](int i, int j) {return data[i] < data[j]; });
//	sort(data.begin(),data.end());
//	return idx;
//}

//void print(const int& tmp) {
//	cout << tmp << "\n";
//}

//struct Node {
//	pair<int,int> value;
//	size_t index;
//};

//bool cmp(struct Node& a, struct Node& b) {
//	return a.value.second < b.value.second ? true : false;
//}

//template<typename T>
//void sort_Index(vector<int>& index, vector<T>& data) {
//	size_t dsz = data.size();
//	Node* _data = new Node[dsz];
//	for (size_t i = 0; i < dsz; ++i) {
//		_data[i].value = data[i];
//		_data[i].index = i;
//	}
//	sort(data.begin(),data.end(),cmp1);
//	sort(_data,_data+dsz,cmp);
//	for (size_t i = 0; i < dsz; ++i) {
//		index.push_back(_data[i].index);
//	}
//	delete[] _data;
//}


/*
int main() {
//using namespace placeholders;
//vector<int> vi = {13,11,14,12,15};
//for (size_t i = 0; i < vi.size(); ++i) {
//	cout << vi[i] << " ";
//}
//cout << "\n-----------------\n";

//for_each(vi.begin(),vi.end(),print);
//auto loc_index1 = find(vi.begin(),vi.end(),12);
//auto loc_index2 = find_if(vi.begin(), vi.end(), bind(greater<int>(), _1, 14));
//cout << loc_index1 - vi.begin() << endl;//3
//cout << loc_index2 - vi.begin() << endl;//4
//cout << "\n-----------------\n";

//vector<int> index=sort_Index(vi);
//for (size_t i = 0; i < vi.size(); ++i) {
//	cout << vi[i] << " ";
//}
//cout << "\n-----------------\n";
//for (size_t i = 0; i < index.size(); ++i) {
//	cout << index[i] << " ";
//}
//cout << "\n-----------------\n";

vector<pair<int, int>> data;
data.push_back(make_pair(3, 2));
data.push_back(make_pair(1, 1));
data.push_back(make_pair(2, 3));
data.push_back(make_pair(4, 5));
data.push_back(make_pair(5, 4));
size_t dsz = data.size();

for (size_t i = 0; i < dsz; ++i) {
cout << data[i].second << " ";
}
cout << "\n-----------------\n";

vector<int> index;
sort_Index(index,data);
for (size_t i = 0; i < dsz; ++i) {
cout << data[i].second << " ";
}
cout << "\n-----------------\n";
for (size_t i = 0; i < index.size(); ++i) {
cout << index[i] << " ";
}
cout << "\n-----------------\n";

system("pause");
return 0;
}
*/


//2 STL之string类成员函数
//2.1 string成员函数
//总体函数


//2.2 常用函数
//2.2.1 构造函数
//string strs //生成空字符串
//string s(str) //生成字符串str的复制品
//string s(str, stridx) //将字符串str中始于stridx的部分作为构造函数的初值
//string s(str, strbegin, strlen) //将字符串str中始于strbegin、长度为strlen的部分作为字符串初值
//string s(cstr) //以C_string类型cstr作为字符串s的初值
//string s(cstr, char_len)    //以C_string类型cstr的前char_len个字符串作为字符串s的初值
//strings(num, c) //生成一个字符串，包含num个c字符
//strings(strs, beg, end)
//以区间[beg, end]内的字符作为字符串s的初值
//
//string s('x');    //错误
//std::string s(1, 'x');    //正确
//std::string s("x");    //正确

//2.2.2 析构函数
//~string() //销毁所有内存，释放内存

//2.2.3 迭代器
//(1) const_iterator begin() const;
//iterator begin();                //返回string的起始位置
//(2) const_iterator end() const;
//iterator end();                    //返回string的最后一个字符后面的位置
//(3) const_iterator rbegin() const;
//iterator rbegin();                //返回string的最后一个字符的位置
//(4) const_iterator rend() const;
//iterator rend();                    //返回string第一个字符位置的前面

//2.2.4 字符长度
//int capacity() const;    //返回当前容量（即string中不必增加内存即可存放的元素个数）
//int max_size() const;    //返回string对象中可存放的最大字符串的长度
//int size() const;        //返回当前字符串的大小
//int length() const;       //返回当前字符串的长度
//bool empty() const;        //当前字符串是否为空
//void resize(int len, char c);//把字符串当前大小置为len，并用字符c填充不足的部分

//2.2.5 输入流
//
//2.2.6 访问元素
//const char& operator[](int n) const;
//const char& at(int n) const;
//char& operator[](int n);
//char& at(int n);

//2.2.7 字符串比较
//int compare(const string &s) const;//比较当前字符串和s的大小
//int compare(int pos, int n, const string &s)const;//比较当前字符串pos开始的n个字符组成的字符串与s的大小
//int compare(int pos, int n, const string &s, int pos2, int n2)const;//比较当前字符串从pos开始n个字符字符串与s中pos2开始n2个字符字符串的大小
//int compare(const char *s) const;
//int compare(int pos, int n, const char *s) const;
//int compare(int pos, int n, const char *s, int pos2) const;

//2.2.8 删除
//iterator erase(iterator first, iterator last);//删除[first，last）之间的所有字符，返回删除后迭代器的位置
//iterator erase(iterator it);//删除it指向的字符，返回删除后迭代器的位置
//string& erase(int pos = 0, int n = npos);//删除pos开始的n个字符，返回修改后的字符串

//2.2.9 赋值
//basic_string& assign(const E* s); //直接使用字符串赋值
//basic_string& assign(const E* s, size_type n);
//basic_string& assign(const basic_string& str, size_type pos, size_type n);//将str的子串赋值给调用串
//basic_string& assign(const basic_string& str);    //使用字符串的“引用”賦值
//basic_string& assign(size_type n, E c); //使用 n个重复字符賦值
//basic_string& assign(const_iterator first, const_iterator last);    //使用迭代器赋值

//2.2.10 插入
//string& insert(int p0, const char *s);
//string& insert(int p0, const char *s, int n);
//string& insert(int p0, const string &s);
//string& insert(int p0, const string &s, int pos, int n);//在p0位置插入s从pos开始的前n个字符

//string &insert(int p0, int n, char c);//在p0处插入n个字符c
//iterator insert(iterator it, char c);//在it处插入字符c，返回插入后迭代器的位置
//void insert(iterator it, const_iterator first, const_iterator last);//在it处插入[first，last）之间的字符
//void insert(iterator it, int n, char c);//在it处插入n个字符c

//2.2.11替换
//string &replace(int p0, int n0, const char *s);		//删除p0开始的n0个字符，然后在p0处插入串s
//string &replace(int p0, int n0, const char *s, int n);//删除p0开始的n0个字符，然后在p0处插入字符串s的前n个字符
//string &replace(int p0, int n0, const string &s);		//删除p0开始的n0个字符，然后在p0处插入串s
//string &replace(int p0, int n0, const string &s, int pos, int n); //删除p0开始的n0个字符，然后在p0处插入串s中从pos开始的n个字符
//string &replace(int p0, int n0, int n, char c);					//删除p0开始的n0个字符，然后在p0处插入n个字符c
//string &replace(iterator first0, iterator last0, const char *s);			//把[first0，last0）之间替换为字符串s
//string &replace(iterator first0, iterator last0, const char *s, int n);	//把[first0，last0）之间替换为s的前n个字符
//string &replace(iterator first0, iterator last0, const string &s);		//把[first0，last0）之间替换为串s
//string &replace(iterator first0, iterator last0, int n, char c);			//把[first0，last0）之间替换为n个字符c
//string &replace(iterator first0, iterator last0, const_iterator first, const_iterator last);//把[first0，last0）之间的部分替换成[first，last）之间的字符串

//2.2.12抽取
//string substr(int pos = 0, int n = npos) const;//返回pos开始的n个字符组成的字符串
//2.2.13查找

//int find(char c, int pos = 0) const;//从pos开始查找字符c在当前字符串的位置
//int find(const char *s, int pos = 0) const;//从pos开始查找字符串s在当前串中的位置
//int find(const char *s, int pos, int n) const;//从pos开始查找字符串s中前n个字符在当前串中的位置
//int find(const string &s, int pos = 0) const;//从pos开始查找字符串s在当前串中的位置
//查找成功时返回所在位置，失败返回string::npos的值

//int rfind(char c, int pos = npos) const;//从pos开始从后向前查找字符c在当前串中的位置
//int rfind(const char *s, int pos = npos) const;
//int rfind(const char *s, int pos, int n = npos) const;
//int rfind(const string &s, int pos = npos) const;
//从pos开始从后向前查找字符串s中前n个字符组成的字符串在当前串中的位置，成功返回所在位置，失败时返回string::npos的值

//int find_first_of(char c, int pos = 0) const;//从pos开始查找字符c第一次出现的位置
//int find_first_of(const char *s, int pos = 0) const;
//int find_first_of(const char *s, int pos, int n) const;
//int find_first_of(const string &s, int pos = 0) const;
//从pos开始查找当前串中第一个在s的前n个字符组成的数组里的字符的位置。查找失败返回string::npos

//int find_first_not_of(char c, int pos = 0) const;
//int find_first_not_of(const char *s, int pos = 0) const;
//int find_first_not_of(const char *s, int pos, int n) const;
//int find_first_not_of(const string &s, int pos = 0) const;
//从当前串中查找第一个不在串s中的字符出现的位置，失败返回string::npos

//int find_last_of(char c, int pos = npos) const;
//int find_last_of(const char *s, int pos = npos) const;
//int find_last_of(const char *s, int pos, int n = npos) const;
//int find_last_of(const string &s, int pos = npos) const;
//int find_last_not_of(char c, int pos = npos) const;
//int find_last_not_of(const char *s, int pos = npos) const;
//int find_last_not_of(const char *s, int pos, int n) const;
//int find_last_not_of(const string &s, int pos = npos) const;
//find_last_of和find_last_not_of与find_first_of和find_first_not_of相似，只不过是从后向前查找


/*
int main() {
//string s1 = "hello";
//string* s2 = new string("Bei");
//string s3 = "Jing";

//size_t len = s1.length();
//string s4 = s1 + s3;
//auto it = s1.begin();
//cout << "s1.begin()=" << *it << endl;//h
//reverse(s1.begin(),s1.end());

//string s5 = "abc123";
//char* arr = new char[20];
//strcpy_s(arr,20,s5.c_str());

//cout << "s1[1]=" << s1[1] << endl;//l
//cout << "s1.at(1)=" << s1.at(1) << endl;//l
//cout << "len_s1=" << len << endl;//5
//cout << "s4=" << s4 << endl;
//cout << "s1=" << s1 << endl;//0lleh
//cout << "arr=" << arr << endl;

//string st1("babbabab");
//cout << "st1=" << st1 << endl;
//cout << st1.find('a') << endl;//1
//cout << st1.find('a', 2) << endl;//4
//cout << (st1.find('c', 0) == -1) << endl;//1

//string st2("aabcbcabcbabcc");
//s1 = "abc";
//cout << "st2=" << st2 << endl;
//cout << st2.find(s1,2) << endl;//6
//cout << st2.find("abcdefg",2,3) << endl;//6 取abcdefg得前3个字符（abc）参与匹配，相当于st2.find("abc", 2)
//cout << st1.rfind('a',7) << endl;//6 从指定位置起向前查找，直到串首

//string s6("bcgjhikl");
//string s7("kghlj");
//string s8("abcdefg");
////find_first_of-在源串中从位置pos往后查找，只要遇到与目标串中任意一个字符相同，就停止查找，返回该字符在源串的位置；匹配失败，返回-1
//cout << s6.find_first_of(s7, 0) << endl;//2 从str7的第0个字符b开始找，g与str8中的g匹配，停止查找，返回g在str7中的位置2
//cout << s8.find_last_of("hjlywkcipn",6) << endl;//2
////find_first_not_of-在源串中从位置pos往后查找，只要遇到与目标串中的任意字符都不相同，就停止查找，返回该字符在源串中的位置；若遍历完都找不到，则返回-1
//cout << s8.find_first_not_of("kiajbvehfgmlc", 0) << endl;//3 从源串s8的位置0(a)开始查找，目标串中有a，匹配，..,找d，目标串中没有d（不匹配），停止查找，返回d在str中的位置3
//cout << s8.find_last_not_of("kiajbvehfgmlc", 6) << endl;//3
//------------------------------------------------------------------------

//string str("12345678");
//char ch[] = "abcdefgh";
//string a; //定义一个空字符串
//string str1(str); //构造函数，全部复制
//string str2(str, 2, 5); //构造函数，从字符串str的第2个元素开始，复制5个元素，赋值给str_2
//string str3(ch, 5); //将字符串ch的前5个元素赋值给str_3
//string str4(5, 'X'); //将 5 个 'X' 组成的字符串 "XXXXX" 赋值给 str_4
//string str5(str.begin(), str.end()); //复制字符串 str 的所有元素，并赋值给 str_5
//cout << "str="<<str << endl;
//cout << "a=" << a << endl;
//cout << "str1=" << str1 << endl;//12345678
//cout << "str2=" << str2 << endl;//34567
//cout << "str3=" << str3 << endl;//abcde
//cout << "str4=" << str4 << endl;//XXXXX
//cout << "str5=" << str5 << endl;//12345678
//-----------------------------------------------------

//string s1("The zip code of Hondelage in Germany is 38108.");
//string sd(s1.begin(), s1.end()); //构造函数中使用迭代器
//cout << "s1=" << s1 << endl; //The zip code of Hondelage in Germany is 38108
//cout << "sd=" << sd << endl;//The zip code of Hondelage in Germany is 38108

//string sd1;
//string sd2;
//auto rit = sd.rbegin();
//sd1.append(sd.begin(),sd.end()-7);
//while (rit != sd.rend()) {
//	sd2.push_back(*rit++);
//}
//cout << "sd1=" << sd1 << endl;//The zip code of Hondelage in Germany is
//cout << "sd2=" << sd2 << endl;//.80183 si ynamreG ni egalednoH fo edoc piz ehT

//sd2.erase(0,15);
//cout << "sd21=" << sd2 << endl;//eG ni egalednoH fo edoc piz ehT
//auto it2 = sd2.begin();
//string sd3 = string("12345678");
//sd2.insert(sd2.begin(), sd3.begin(), sd3.end());
//cout << "sd22=" << sd2 << endl;//12345678eG ni egalednoH fo edoc piz ehT
//sd2.replace(sd2.begin(), sd2.end(), "This is an Exarrple of Replace");
//cout << "sd23=" << sd2 << endl;//This is an Exarrple of Replace
//--------------------------------------------------

//size_t size = 0;
//size_t length = 0;
//size_t maxsize = 0;
//size_t capacity = 0;
//string str("12345678");
//string str_custom;
//str_custom = str;
//str_custom.resize(5);
//size = str_custom.size();
//length = str_custom.length();
//maxsize = str_custom.max_size();
//capacity = str_custom.capacity();
//cout << "size = " << size << endl;			//5
//cout << "length = " << length << endl;		//5
//cout << "maxsize = " << maxsize << endl;	//4294967294
//cout << "capacity = " << capacity << endl;	//15
//--------------------------------------------------------

//string input("hello,this is a test");
//istringstream is(input);
//string s1, s2, s3, s4;
//is >> s1 >> s2 >> s3 >> s4;//s1="hello,this",s2="is",s3="a",s4="test"
//ostringstream os;
//os << s1 << " "<<s2 << " "<<s3 << " "<<s4;
//cout << os.str();

////getline(istream &in, string &s); //用于从输入流in中读取字符串到s中，以换行符'\n'分开
//string s11,s12;
//cout << "Input s11 s12: \n";
//getline(cin, s11); // 实现了读取一行字符，包括空格、制表符、回车符等行内字符和符号，以\n分开
//getline(cin, s12, ' ');
//cout << "s11=" << s11 << endl;
//cout << "s12=" << s12 << endl;
//--------------------------------------------------------

//string s1 = "c.biancheng.net";
//string s2("abcde");
//char tmp0, tmp1, tmp2, tmp3, tmp4, tmp5;
//tmp0 = s2[2];
//tmp1 = s2.at(2);
//tmp2 = s2[s2.length()];
//tmp3 = s1[s1.length()];
//cout << "tmp0=" << tmp0 << endl;//c
//cout << "tmp1=" << tmp1 << endl;//c
//cout << "tmp2=" << tmp2 << endl;//
//cout << "tmp3=" << tmp3 << endl;//

//string s1 = "abcde";
//cout << "s1=" << s1 << endl;
//char& r = s1[2];
//char* p = &s1[3];
//r = 'X';
//*p = 'Y';
//cout << "s1=" << s1 << endl;//abXYe

//s1 = "12345678";
//r = 'X';
//*p = 'Y';
//cout << "s1=" << s1 << endl;//12XY5678
//-------------------------------------------

//string A("aBcdef");
//string B("AbcdEf");
//string C("123456");
//string D("123dfg");
////下面是各种比较方法
//int m = A.compare(B); //完整的A和B的比较
//int n = A.compare(1, 5, B, 4, 2); //"Bcdef"和"AbcdEf"比较
//int p = A.compare(1, 5, B, 4, 2); //"Bcdef"和"Ef"比较
//int q = C.compare(0, 3, D, 0, 3); //"123"和"123"比较
//cout << "m = " << m << ", n = " << n << ", p = " << p << ", q = " << q << endl;//1 -1 -1 0
//------------------------------------------------

//string str1("123456");
//string str;
//str.assign(str1);				cout << str << endl;//123456 直接赋值
//str.assign(str1, 3, 3);			cout << str << endl;//456 赋值给子串
//str.assign(str1, 2, str1.npos);	cout << str << endl;//3456 赋值给从位置 2 至末尾的子串
//str.assign(5, 'X');				cout << str << endl; //XXXXX 重复 5 个'X'字符
//
//auto itB = str1.begin();
//auto itE = str1.end();
//str.assign(itB, (--itE)); //从第 1 个至倒数第 2 个元素，赋值给字符串 str
//cout << str << endl;//12345
//------------------------------------------------

system("pause");
return 0;
}
*/


//3 STL之序列式容器（array和vector）
//3.1 array
//array<T, N> 有N个T类型元素的固定序列。需要指定元素的类型和个数，和常规数组没有差别。显然，不能增加或删除元素。
//(1) 初始化
//(2) 访问元素
//(3) 迭代器
//(4) 比较大小

//3.2 vector
//vector<T>:   T类型元素的序列容器，大小可自动增长，可包含任意数量的元素
//(1) 初始化
//(2) 容量大小 
//capacity: 在不分配更多内存, 可保存的最多元素个数
//size: 实际所包含的元素个数，有值元素的个数
//resize:

//(3) 插入元素
// emplace(): 第一个参数是迭代器，确定对象生成的位置。对象被插入到迭代器所指定元素的后面。后面的参数，都作为插入元素的构造函数的参数
// insert(): 可在vector中插入>=1个元素。第一个参数总是一个指向插入点的 const 或 non-const 迭代器。
//元素被插到第一个参数所指元素的前面，如果第一个参数是一个反向迭代器，元素被插到迭代器所指元素的后面。
// find(): 在头两个参数指定的一段元素中，搜索第三个参数指定的元素，返回第一个找到的元素

//(4) 迭代器
//(5) 访问元素
//front() 和 back(): 返回序列中第一个和最后一个元素的引用，
//data(): 返回一个指向数组的指针，它在内部被用来存储元素
//data() 返回vector<T>容器的 T* 类型的值。

//(6) 删除元素
//clear()
//pop_back()
//shrink_to_fit()
//erase()
//remove()
//(7) 增加元素

/*
int main() {
//array<int,100> data1;
//array<int,100> data2;
//array<double, 10> arr{0.5,1.0,1.5,2.0};
//arr.fill(3.2);

//arr[4] = arr[3] + 2.0*arr[1];//不检查越界
////values.at(4) = values.at(3) + 2.0*values.at(1);//检查越界
//double total{};
//for (auto val : arr) {
//	total += val;
//}
//array<string, 5> words{"one","two","three","four","five"};
//cout << get<3>(words) << endl;//four
//cout << "total=" << total << endl;//38.4
//-----------------------------------------------------------

//const unsigned int min_wt{ 100U };
//const unsigned int max_wt{ 250U };
//const unsigned int wt_step{ 10U };
//const size_t wt_count{ 1 + (max_wt - min_wt) / wt_step };
//const unsigned int min_ht{ 48U };
//const unsigned int max_ht{ 84U };
//const unsigned int ht_step{ 2U };
//const size_t ht_count{ 1 + (max_ht - min_ht) / ht_step };
//const double lbs_per_kg{ 2.20462 };
//const double ins_per_m{ 39.3701 };
//array<unsigned int, wt_count> weight_lbs;
//array<unsigned int, ht_count> height_ins;

//// Create weights from lOOlbs in steps of lOlbs
//for (size_t i{}, w{ min_wt }; i < wt_count; w += wt_step, ++i) {
//	weight_lbs.at(i) = w;
//}
////Create heights from 48 inches in steps of 2 inches
//unsigned int h{ min_ht };
//for (auto& height : height_ins) {
//	height = h;
//	h += ht_step;
//}
////Output table headings
//cout << setw(7) << " |";
//for (const auto& w : weight_lbs)
//	cout << setw(5) << w << "11";
//cout << "\n";
//// Output line below headings
//for (size_t i{ 1 }; i < wt_count; ++i)
//	cout << "---------";
//cout << "\n";
//-----------------------------------------------------------

//array<double, 5> ht = {1,2,3,4,5};
//unsigned int h{100U};
//int ht_step = 1, min_ht = 0;
//auto ht_beg = ht.begin();
//auto ht_end = ht.end();
//while (ht_beg != ht_end) {
//	*ht_beg++ = h;
//	h += ht_step;
//}

//unsigned int height{};
//generate(ht.begin(), ht.end(), [height, &min_ht, &ht_step]()mutable {return height += height == 0 ? min_ht : ht_step; });
//for (auto& hti : ht) {
//	cout << hti << " ";
//}
//cout << "\n";

//array<double, 4> values;
//iota(values.begin(),values.end(),12.3);
//for (auto& val : values) {
//	cout << val << " ";
//}
//cout << "\n";
//----------------------------------------------------

//array<double, 4> these{ 1.0, 2.0, 3.0, 4.0 };
//array<double, 4> those{ 1.0, 2.0, 3.0, 4.0 };
//array<double, 4> them{ 1.0, 3.0, 3.0, 2.0 };
//if (these == those) cout << "these and those are equal." << endl;
//if (those != them) cout << "those and them are not equal." << endl;
//if (those < them) cout << "those are less than them." << endl;
//if (them > those) cout << "them are greater than those." << endl;
//--------------------------------------------------------------------------

system("pause");
return 0;
}
*/

template<typename T>
void printV(vector<T>& v) {
	for (auto& i : v) {
		cout << i << " ";
	}
	cout << "\n";
}

/*
int main() {
////vector<double> values;
////values.reserve(20);
//vector<unsigned int> primes = { 2u, 3u, 5u, 7u, 11u, 13u, 17u, 19u };
////vector<double> values(20);
////vector<double> values{20};
//vector<long> nums(20,99L);//20 个元素的值都是 99L。

//array<string, 5> words = { "one", "two","three", "four", "five" };
//vector<string> words_copy1(words.begin(),words.end());
//vector<string> words_copy2{make_move_iterator(words.begin()),make_move_iterator(words.end()) };
//cout << "words.size="<<words.size() << endl;//5
//for (auto& wd : words) {
//	cout << wd << " ";
//}
//cout << "\n";
//-------------------------------------------

//vector<size_t> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23,29, 31, 37, 41 ,43 ,47 };
//primes.push_back(53);
//cout << "size=" << primes.size() << endl;//16
//cout << "capacity=" << primes.capacity() << endl;//22
//auto sz = primes.size();
//for (auto& prime : primes) {
//	prime *= 2;
//}

//vector<int> vals = {1,2,3};
//vals.resize(5); printV(vals); //1 2 3 0 0
//cout << "size1=" << primes.size() << " capacity1=" << primes.capacity() << endl;//16 22
//vals.resize(7,99); printV(vals);//1 2 3 0 0 99 99
//cout << "size2=" << primes.size() << " capacity2=" << primes.capacity() << endl;//16 22
//vals.resize(6); printV(vals);//1 2 3 0 0 99
//cout << "size3=" << primes.size() << " capacity3=" << primes.capacity() << endl;//16 22
//-----------------------------------------

//vector<string> words1 = {"one","two"};
//auto itr1 = words1.emplace(++words1.begin(),5,'A');
//cout << "*itr1=" << *itr1 << endl;//AAAAA
//printVs(words1);//one AAAAA two
//words1.emplace(++itr1,"$$$$");
//printVs(words1);//one AAAAA $$$$ two

//vector<string> words2 = {"one","three","eight"};
//auto itr2 = words2.insert(++words2.begin(),"two");
//cout << "*itr2=" << *itr2 << endl;//two
//printVs(words2);//one two three eight

//string more[] = { "five", "six", "seven" };
//itr2 = words2.insert(--words2.end(),begin(more),end(more));
//cout << "*itr2=" << *itr2 << endl;//five
//printVs(words2);//one two three five six seven eight
//itr2 = words2.insert(words2.end(),"ten");
//cout << "*itr2=" << *itr2 << endl;//ten
//printVs(words2);//one two three five six seven eight ten
//itr2 = words2.insert(words2.cend()-1,2,"nine");
//cout << "*itr2=" << *itr2 << endl;//nine
//printVs(words2);//one two three five six seven eight nine nine ten
//itr2 = words2.insert(words2.end(), { string{"twelve"},string{"thirdteen"} });
//cout << "*itr2=" << *itr2 << endl;//twelve
//printVs(words2);//one two three five six seven eight nine nine ten twelve thirdteen

//vector<string> vs = { "one", "two", "one", "three" };
//auto ritr = find(vs.rbegin(),vs.rend(),"one");
//vs.insert(ritr.base(),"five");
//printVs(vs);//one two one five three
//-----------------------------------------------

//vector<string> words;                     // Stores words to be sorted
//words.reserve(10);                        // Allocate some space for elements
//cout << "Enter words separated by spaces. Enter Ctrl+Z on a separate line to end:" << endl;
//copy(istream_iterator <string> {cin},istream_iterator <string> {}, back_inserter(words));
//cout << "Starting sort." << endl;
//bool out_of_order{ false };
//while (true) {
//	for (auto first = words.begin() + 1; first != words.end(); ++first) {
//		if (*(first - 1) > *first) {
//			std::swap(*first, *(first - 1));// Out of order so swap them
//			out_of_order = true;
//		}
//	}
//	if (!out_of_order)                      // If they are in order (no swaps necessary)...
//		break;                                // ...we are done...
//	out_of_order = false;                   // ...otherwise, go round again.
//}
//cout << "your words in ascending sequence:" << endl;
//copy(words.begin(), words.end(), ostream_iterator<string> {cout, " "}); cout << "\n";

//// Create a new vector by moving elements from words vector
//vector<string> words_copy{ make_move_iterator(words.begin()),make_move_iterator(words.end()) };
//cout << "\nAfter moving elements from words, words_copy contains:" << endl;
//copy(words.begin(), words.end(), ostream_iterator < string > {cout, " "}); cout << "\n";

//// See what's happened to elements in words vector...
//cout << "\nwords vector has " << words.size() << " elements\n";
//if (words.front().empty())
//	cout << "First element is empty string object." << endl;
//cout << "First element is \"" << words.front() << "\"" << endl;
//-------------------------------------------------

//vector<double> vals(20);
//vals[0] = 1.23;
//vals[1] = 5.0;
//vals[2] = 2.0*vals[0] * vals[1];
//cout << vals.front() << endl;
//cout << *(vals.data()) << endl;//1.23
//-----------------------------------------------

//vector<int> data(100, 99);// Contains 100 elements initialized to 99
//data.clear(); // Remove all elements 所以容量还是 100。
//cout << data.size() << " " << data.capacity() << endl;

//vector<int> data = {1,2,3,4,5,6,7,8,9,10}; // Contains 10 elements initialized to 12
//data.pop_back(); // Remove the last element
//cout << data.size() << " " << data.capacity() << endl;//9 10

////假设要删除 data 中的第二个元素
//swap(data.begin() + 1, data.end() - 1);// Interchange 2nd element with the last
//data.pop_back();// Remove the last element
//cout << data.size() << " " << data.capacity() << endl;//8 10

////去掉容器中多余的容量，例如不再向容器中添加新元素，可用shrink_to_fit()实现：
//data.shrink_to_fit(); // Reduce the capacity to that needed for elements
//cout << data.size() << " " << data.capacity() << endl;//8,8
//printVi(data);//1,2,3,4,5,6,7,8
//auto iter1 = data.erase(data.begin() + 1); //Delete the second element. 它指向被删除元素后一个元素
//cout << "*iter1=" << *iter1 << endl;//3
//printVi(data);//1 3 4 5 6 7 8
//auto iter2 = data.erase(data.begin() + 1, data.begin() + 3);// Delete the 2nd and 3rd elements. 第二个迭代器指向这段元素末尾的下一个位置
//printVi(data);//1 5 6 7 8

////如果在 remove() 操作后输出 words 中的元素，只会输出前 5 个元素。尽管 size() 返回的值仍然是 7，
////而且最后两个元素仍然存在，但是它们被替换成了空字符串对象。
//vector<string> words = { "one", "none","some", "all", "none", "most","many"};
//auto iter3 = remove(words.begin(), words.end(), "none");
//cout << words.size() << " " << words.capacity() << endl;//7,7
//printVs(words);//one some all most many
//words.erase(iter3, words.end());//Remove surplus elements
//cout << words.size() << " " << words.capacity() << endl;//7,7
//printVs(words);//one some all most many

////erase - remove，执行删除操作后，iter 指向最后一个元素之后的位置，
////所以它标识了被删除序列的第一个元素，被删除序列的结束位置由 end(words) 指定
//words.erase(remove(words.begin(), words.end(),"some"), words.end());//???
//cout << words.size() << " " << words.capacity() << endl;//4,7
//printVs(words);//one all most many
//-------------------------------------------------------

//vector <size_t> sizes;                    // Record numbers of elements
//vector <size_t> capacities;               // and corresponding capacities
//size_t el_incr{ 10 };                           // Increment to initial element count
//size_t incr_count{ 4 * el_incr };               // Number of increments to element count
//for (size_t nums{}; nums < incr_count; nums += el_incr) {
//	vector<int> values(nums);
//	cout << "\nAppending to a vector with " << nums << " initial elements:\n";
//	sizes.push_back(values.size());
//	size_t space{ values.capacity() };
//	capacities.push_back(space);
//	// Append elements to obtain capacity increases
//	size_t count{};                             // Counts capacity increases
//	size_t n_increases{ 10 };
//	while (count < n_increases) {
//		values.push_back(22);                      // Append a new element
//		if (space < values.capacity()) {            // Capacity increased...// ...so record size and capacity
//			space = values.capacity();
//			capacities.push_back(space);
//			sizes.push_back(values.size());
//			++count;
//		}
//	}
//	// Show sizes & capacities when increments occur
//	cout << "Size/Capacity: ";
//	for (size_t i{}; i < sizes.size(); ++i)
//		cout << sizes.at(i) << "/" << capacities.at(i) << " ";
//	cout << endl;
//	sizes.clear();                               // Remove all elements
//	capacities.clear();                          // Remove all elements
//}
//------------------------------------------------------

vector<double> values;
values.push_back(1.23);
vector<string> words1;
words1.push_back(string("ab"));
// Move string("adiabatic"） into the vector
words1.push_back("cde"); // Move string("adiabatic")
printVs(words1);//ab cde

vector<string> words2;
words2.push_back(string("fghi")); // Calls string constructor & moves the string object
words2.emplace_back("jklmn");// Calls string constructor to create element in place		//emplace back() 比 push_back() 更有效率
printVs(words2);//fghi jklmn

// emplace_back() 函数会调用接收三个参数的 string 构造函数，生成 string 对象，
// 然后把它添加到 words 序列中。构造函数会生成一个从索引 2 幵始、包含 str 中三个字符的子串。
string str{ "polytech" };
words2.emplace_back(str, 2, 3);
printVs(words2);//fghi jklmn lyt
// Create string object corresponding to "leg" in place

system("pause");
return 0;
}
*/

//4 STL之序列式容器（deque和list）
//4.1 deque
//deque<T>   双端队列组织元素，可在容器头尾部高效地添加或删除对象，相对于vector的优势。
//(1) 初始化，访问，插入
//(2) 修改元素
//(3) 综合举例

//4.2 list
//list<T>	T类型对象的双向链表。可在序列任何位置插入或删除元素。缺点: 无法通过位置来随机访问，即，不能索引元素
//(1) 初始化
//(2) 增加元素
//(3) 删除元素
//remove(val)
//remove_if(naryPredicate p)//参数是一个 lambda 表达式，也可是一个函数对象。
//unique()//移除连续的重复元素，留下其中的第一个

//(4) 排序
//sort() 函数模板要求随机访问迭代器。但lis 容器只提供双向迭代器.
//1) list模板定义自己的 sort() 函数。
//有两个版本：无参sort()将所有元素升序排列。第二个版本的 sort() 接受一个函数对象或 lambda 表达式，这两种参数都定义一个断言来比较两个元素
//2) 可将自定义的函数对象传给断言,来对 list 排序。
//3) 当需要比较非默认类型时，就需要一个函数对象。

//(5) 合并
//merge(list&& other, Compare comp): 归并二个已排序链表为一个。两个链表都是升序
//splice(): 从一个 list 转移元素给另一个。不复制或移动元素，仅重指向链表结点的内部指针

//4.3 forward_list
//forward_list 单链表形式存储元素。
//forward_list 和 list 最主要的区别: 它不能反向遍历元素；只能从头到尾遍历。
//forward_list 比 list 还要快，占用内存更少.

//特点：
//无法使用反向迭代器。只能从它得到const或non - const前向迭代器，这些迭代器都不能解引用，只能自增；
//没有可返回尾元素引用的成员函数back(); 只有成员函数front();
//因为只能自增前面元素的迭代器，来到达序列终点，没有push_back()、pop_back()、emplace_back()

//(1) 大小
//forward_list只有前向迭代器。无成员函数size()，不能用一个前向迭代器减去另一个

//(2) 访问
//distance()：第一个参数，开始迭代器；第二个参数，结束迭代器，指定元素范围
//advance()：将前向迭代器移动多个位置
//
//(3) 插入
//splice_after()

//template<typename T>
//void printD(deque<T>& di) {
//	for (auto& i : di) {
//		cout << i << " ";
//	}
//	cout << "\n";
//}

/*
int main() {
//deque<int> deque1;
//deque<int> deque2(10);
//deque<string> ds1 = { "one", "two", "three", "four","five","six", "seven"};
//deque<string> ds2{ds1};
//deque<string> ds3{ ds1.begin(),ds1.begin() + 5 };
//cout << ds1.at(2) << endl;//three

//deque<int> nums = {2,3,4};
//nums.push_front(11); printDi(nums);//11 2 3 4
//nums.push_back(12);  printDi(nums);//11 2 3 4 12
//nums.pop_front();	 printDi(nums);//2 3 4 12
//-----------------------------------------

//deque<string> ds1 = { "one", "two", "three", "four" };
//auto init_list = {string("seven"),string("eight"),string("nine")};
//ds1.assign(init_list);
//printD(ds1);//seven eight nine
//ds1.assign({"ten","eleven"});
//printD(ds1);//ten eleven

//vector<string> vs = { "this","that","these","those" };
//ds1.assign(vs.begin()+1,--vs.end());
//printD(ds1);//that these
//-----------------------------------------

//deque<string> names;
//cout << "Enter first names separated by spaces. Enter Ctrl+Z on a new line to end:\n";
//copy(istream_iterator<string>{cin}, istream_iterator<string>{},front_inserter(names));
//cout << "\nIn reverse order, the names you entered are:\n";
//copy(names.begin(), names.end(), ostream_iterator<string>{cout," "});
//cout << "\n";
//-----------------------------------------

system("pause");
return 0;
}
*/

//template<typename T>
//void printL(list<T>& di) {
//	for (auto& i : di) {
//		cout << i << " ";
//	}
//	cout << "\n";
//}
//
//template<typename T>
//void printFL(forward_list<T>& di) {
//	for (auto& i : di) {
//		cout << i << " ";
//	}
//	cout << "\n";
//}
//
//class my_greater {
//public:
//	bool operator() (const string& s1, const string& s2) {
//		return s1[0] == s2[0] ? s1.length() > s2.length() : s1 > s2;
//	}
//};


/*
int main() {
//list<string> ls1;
//list<string> ls2{10};//A list of 10 empty strings
//list<double> ls3(6,1.2);
//printL(ls3);//1.2 1.2 1.2 1.2 1.2 1.2
//list<double> ls4{ls3};
//list<double> ls5{++ls3.begin(),--ls3.end()};
//printL(ls5);//1.2 1.2 1.2 1.2

//list<string> names1{ "Jane", "Jim", "Jules", "Janet" };
//names1.push_front("lan1");
//names1.push_back("Kitty1");
//printL(names1);//lan1 Jane Jim Jules Janet Kitty1
//names1.emplace_front("lan2");
//names1.emplace_back("Kitty2");
//printL(names1);//lan2 lan1 Jane Jim Jules Janet Kitty1 Kitty2
//list<int> li1(10,12);
//li1.insert(++li1.begin(),23);
//printL(li1);//12 23 12 12 12 12 12 12 12 12 12

//auto itr = li1.begin();
//advance(itr,4);
//li1.insert(itr,3,88);
//printL(li1);//12 23 12 12 88 88 88 12 12 12 12 12 12 12

//vector<int> nums(10,5);
//li1.insert(--(--li1.end()),nums.cbegin(),nums.cend());
//printL(li1);//12 23 12 12 88 88 88 12 12 12 12 12 5 5 5 5 5 5 5 5 5 5 12 12

//list<string> names2{ "Jane", "Jim", "Jules", "Janet" };
//names2.emplace_back("Ann");
//string name("Alan");
//names2.emplace_back(std::move(name));	printL(names2);//Jane Jim Jules Janet Ann Alan
//names2.emplace_front("abc");			printL(names2);//abc Jane Jim Jules Janet Ann Alan
//names2.emplace(++names2.begin(),"Ha");  printL(names2);//abc Ha Jane Jim Jules Janet Ann Alan
//--------------------------------------------

//list<int> nums = { 2, 5, 2, 3, 6, 7, 8, 2, 9 };
//nums.remove(2);
//printL(nums);//5 3 6 7 8 9
//nums.remove_if([](int n) {return n % 2 == 0; });
//printL(nums);//5 3 7 9

//list<string> words = { "one", "two", "two", "two","three", "four", "four" };
//words.unique();
//printL(words);//one two three four
//---------------------------------------------

//list<string> names = { "Jane", "Jim", "Jules", "Janet" ,"Ann","Han"};
//names.sort(greater<string>());	printL(names);//Jules Jim Janet Jane Han Ann
//names.sort(less<>());			printL(names);//Ann Han Jane Janet Jim Jules
//names.sort(my_greater());		printL(names);//Janet Jules Jane Jim Han Ann
//names.sort([](const string& s1, const string& s2) {
//	return s1[0] == s2[0] ? s1.length() < s2.length() : s1 < s2;
//});
//printL(names);//Ann Han Jim Jane Janet Jules
//--------------------------------------------------

//list<int> li1 = {2,4,6,14};
//list<int> li2 = { -2,1,7,10 };
//li1.merge(li2);
//printL(li1);//-2 1 2 4 6 7 10 14
//cout << li2.empty() << endl;//1

//list<string> ls1 = { "three","six", "eight" };
//list<string> ls2 = { "seven", "four", "nine" };
//auto cmp_str = [](const string& s1, const string& s2) {return s1[0] < s2[0]; };
//ls1.sort(cmp_str);
//ls2.sort(cmp_str);
//ls1.merge(ls2,cmp_str);
//printL(ls1);//eight four nine six seven three

//list<string> ls3 = { "three","six", "eight" };
//list<string> ls4 = { "seven", "four", "nine" };
//ls3.splice(++ls3.begin(),ls4,++ls4.begin());//(指向目的容器的迭代器, 元素来源,被粘接元素的迭代器，它会被插到首参所指位置之前)
//printL(ls3);//three four six eight
//printL(ls4);//seven nine
//cout << "-------------------------------\n";
//ls4.splice(++ls4.begin(),ls3,ls3.begin(),ls3.end());
//printL(ls3);
//printL(ls4);//seven three four six eight nine
//cout << "-------------------------------\n";

//ls3.splice(ls3.begin(),ls4);
//printL(ls3);//seven three four six eight nine
//printL(ls4);
//cout << "-------------------------------\n";
//ls4.splice(ls4.end(),ls3);//第一个参数也可以是 ls4.begin()
//printL(ls3);
//printL(ls4);//seven three four six eight nine
//cout << "-------------------------------\n";
//------------------------------------------------

forward_list<string> fls1 = { "three", "six", "eight" };
auto cnt = distance(fls1.begin(),fls1.end());
cout << "cnt=" << cnt << endl;//3

forward_list<int> fli1 = { 10, 21, 43, 87, 175, 351 };
auto itr = fli1.begin();
size_t n = 3;
advance(itr,3);
cout << n + 1 << "th element is " << *itr << endl;//4,87

forward_list<string> fls2 = { "three", "six", "eight" };
forward_list<string> fls3 = { "seven", "four", "nine" };
fls2.splice_after(fls2.before_begin(),fls3,++fls3.begin());
printFL(fls2);//nine three six eight
printFL(fls3);//seven four
cout << "-------------------------------\n";
fls2.splice_after(fls2.before_begin(), fls3, fls3.begin(),fls3.end());
printFL(fls2);//four nine three six eight
printFL(fls3);//seven

system("pause");
return 0;
}
*/


//5 STL之容器适配器（stack,queue和priority_queue）
//容器适配器主要有三种:
//stack<T>: 封装了deque<T> 容器的适配器类模板，默认实现一个后入先出的压入栈。
//queue<T>: 封装了deque<T> 容器的适配器类模板，默认实现一个先入先出的队列。可为它指定一个符合确定条件的基础容器。
//priority_queue<T>: 封装了 vector<T> 容器的适配器类模板，默认实现一个对元素排序，保证最大元素总在最前面的队列

//5.1 stack
//只能访问 stack 顶部的元素；只有在移除 stack 顶部的元素后，才能访问下方的元素。
//
//5.1.1 初始化
//(1) stack<string> words;
//(2) stack<string, list<string>> fruit;//通过指定第二个模板类型参数，可以使用任意类型的底层容器
//(3) list<double> values{ 1.414, 3.14159265, 2.71828 };
//stack<double, list<double>> my_stack(values);
//(4) stack<double, list<double>> copy_stack{ my_stack }//拷贝构造函数
//
//5.1.2 基本操作
//(1) top(): 返回一个栈顶元素的引用，类型为 T&。如果栈为空，返回值未定义。
//(2) push(const T& obj): 将对象副本压入栈顶。通过调用底层容器的push_back()函数完成
//(3) push(T&& obj): 以移动对象的方式将对象压入栈顶。通过调用底层容器右值引用参数的push_back()函数完成
//(4) pop(): 弹出栈顶元素
//(5) size(): 返回栈中元素个数
//(6) empty(): 在栈中没有元素的情况下返回 true
//(7) emplace(): 用传入的参数调用构造函数，在栈顶生成对象
//(8) swap(stack<T> & other_stack): 将当前栈中和参数中的元素交换。参数所包含元素的类型必须和当前栈的相同

//5.2 queue
//只能在容器的末尾添加新元素，只能从头部移除元素。
//5.2.1 初始化
//(1) queue<string> words;
//(2) queue<string> copy_words{ words };//拷贝构造函数
//(3) queue<string, list<string>> words;//指定参数模板
//5.2.2 基本操作
//(1) front(): 返回 queue 中首元素的引用。若queue是常量，返回常引用；若queue为空，返回值未定义
//(2) back():  返回 queue 中尾元素的引用。若queue是常量，返回常引用；若queue为空，返回值未定义
//(3) push(const T& obj): 在queue尾部添加元素的副本。通过调用底层容器的成员函数push_back()完成
//(4) push(T&& obj): 以移动的方式在queue尾部添加元素。通过调用底层容器的具有右值引用参数的成员函数push_back()完成
//(5) pop(): 删除 queue 中首元素
//(6) size(): 返回 queue 中元素个数
//(7) empty(): 若 queue 中没有元素，返回 true。
//(8) emplace(): 用传给emplace()的参数调用T的构造函数，在queue尾部生成对象
//(9) swap(queue<T> &other_q): 将当前queue中的元素和参数queue中的元素交换

//5.3 priority_queue --> 容器适配器，提供常数时间（默认）最大元素查找，对数代价的插入与释出。
//template <typename T, typename Container=vector<T>, typename Compare=less<T>> class priority_queue
//priority_queue 模板有 3 个参数，其中两个有默认的参数；
//(1) 存储对象的类型，
//(2) 存储元素的底层容器，
//(3) 函数对象，它定义了一个用来决定元素顺序的断言。
//
//5.3.1 初始化
//(1) priority_queue<string> words;
//(2) string wrds[]{ "one", "two", "three", "four" };//适当类型初始化队列
//	  priority_queue<string> words{ begin(wrds),end(wrds) };
//(3) string wrds[]{ "one", "two", "three", "four" };
//	  priority_queue<string, vector<string>,greater<string>> words1{ begin(wrds) , end(wrds) };//优先级队列对他们进行排序
//(4) vector<int> values{ 21, 22, 12, 3, 24, 54, 56 };
//    priority_queue<int> numbers{ less<int>(),values };
//(5) priority_queue<int, vector<int>, greater<int>> numbersl{ greater<int>(), values };//指定全部模板参数
//
//5.3.2 基本操作
//(1) push(const T& obj): 将obj的副本放到容器的适当位置，包含一个排序操作。
//(2) push(T&& obj): 将obj放到容器的适当位置，包含一个排序操作。
//(3) emplace(T constructor a rgs...): 调用传入参数的构造函数，在序列的适当位置构造一个T对象。为维持优先顺序，需要一个排序操作。
//(4) top(): 返回优先级队列中首元素的引用
//(5) pop(): 移除首元素。
//(6) size(): 返回队列中元素个数
//(7) empty(): 若队列为空，返回true
//(8) swap(priority_queue<T>& other): 和参数的元素进行交换，所包含对象的类型必须相同。


//void histogram(const vector<int>& v, int min) {
//	string bar (60,'*');
//	for (size_t i= 0; i < v.size(); ++i) {
//		cout << setw(3) << i + min << " "
//			<< setw(4) << v[i] << " "
//			<< bar.substr(0, v[i])
//			<< (v[i] > static_cast<int>(bar.size()) ? "..." : "") << "\n";
//	}
//}

//template<typename T>
//void list_pq(priority_queue<T> pq, size_t cnt = 5) {
//	size_t n = cnt;
//	while (!pq.empty()) {
//		cout << pq.top() << " ";
//		pq.pop();
//		if (--n) continue;
//		cout << "\n";
//		n = cnt;
//	}
//	cout << "\n";
//}

/*
int main(void) {
	//priority_queue<string> words;
	//string word;
	//cout << "Enter words separated by spaces, enter Ctrl+Z on a separate line to end:\n";
	//while (true) {
	//	if ((cin >> word).eof())
	//		break;
	//	words.push(word);
	//}
	//cout << "You entered " << words.size() << " words:" << endl;
	//list_pq(words);

	random_device random_n;
	int service_t_min = 2, service_t_max = 15;
	int min_customers = 15, max_customers = 20;
	int min_arr_interval=1, max_arr_interval=5;
	distribution service_t_d{ service_t_min ,service_t_max};
	distribution n_1st_customers_d{ min_customers, max_customers };
	distribution arrival_interval_d{ min_arr_interval, max_arr_interval };

	size_t n_checkouts = 0;
	cout << "Enter the number of checkouts in the supermarket: ";
	cin >> n_checkouts;
	if (!n_checkouts) {
		cout << "Number of checkouts must be greater than 0. Setting to 1." << endl;
		n_checkouts = 1;
	}
	vector<Checkout> checkouts{ n_checkouts };
	vector<int> service_times(service_t_max - service_t_min + 1);

	// Add customers waiting when store opens
	int count{ n_1st_customers_d(random_n) };
	cout << "Customers waiting at store opening: " << count << endl;
	int added=0;
	int service_t=0;

	while (added++ < count) {
		service_t = service_t_d(random_n);
		min_element(checkouts.begin(), checkouts.end())->add(Customer(service_t));
		++service_times[service_t - service_t_min];
	}

	size_t time=0;
	const size_t total_time=600;
	size_t longest_q=0;
	// Period until next customer arrives
	int new_cust_interval{ arrival_interval_d(random_n) };

	// Run store simulation for period of total_time minutes
	while (time < total_time) {
		++time;
		// New customer arrives when arrival interval is zero
		if (--new_cust_interval == 0) {
			service_t = service_t_d(random_n);
			min_element(checkouts.begin(), checkouts.end())->add(Customer(service_t));

			++service_times[service_t - service_t_min];

			for (auto & checkout : checkouts)
				longest_q = max(longest_q, checkout.qlen());

			new_cust_interval = arrival_interval_d(random_n);
		}

		for (auto & checkout : checkouts)
			checkout.time_increment();
	}

	cout << "Maximum queue length = " << longest_q << endl;
	cout << "\nHistogram of service times:\n";
	histogram(service_times, service_t_min);
	cout << "\nTotal number of customers today: "
		<< accumulate(service_times.begin(), service_times.end(), 0)
		<< endl;

	//getchar();
	system("pause");
	return 0;
}
*/


//6 STL之容器适配器（heaps）
//堆的底层实现是完全二叉树: 各节点与其子节点位置相对。大顶堆: 父节点>=子节点; 小顶堆: 父节点<=子节点
//注意: 给定父节点的子节点不一定按顺序排列。
//
//6.1 初始化: 
//max_heap() 对随机访问迭代器指定的一段元素重新排列，生成一个堆。默认使用 < 运算符，生成大顶堆。
//6.2 添加元素:		push_heap(begin,end)
//自定义函数添加:	push_heap(begin,end,greater<>())
//6.3 删除元素:     pop_heap(begin,end) --> 将首元素移到最后，并保证剩下的元素仍是一个堆
//删除最大元素和添加元素到堆有些相似，但所做的事是相反的。首先调用 pop_heap()，然后从容器中移除最大元素
//自定义函数删除:   pop_heap(begin,end,greater<>())

/*
void show(deque<string>& words, size_t cnt = 5) {
	if (words.empty()) return;
	auto maxlen = max_element(words.begin(), words.end(), 
		[](const string& s1,const string& s2) {return s1.size() < s2.size(); })->size();
	size_t n = cnt;
	for (const auto& word : words) {
		cout << setw(maxlen + 1) << word << " ";
		if (--n) continue;
		cout << "\n";
		n = cnt;
	}
	cout << "\n";
}

int main(void) {
	//vector<double> nums1 = { 2.5, 10.0, 3.5, 6.5, 8.0, 12.0, 1.5, 6.0 };
	//vector<double> nums2 = nums1;
	//make_heap(nums1.begin(),nums1.end()); printV(nums1);//12 10 3.5 6.5 8 2.5 1.5 6
	//make_heap(nums2.begin(),nums2.end(),greater<>()); printV(nums2);//1.5 6 2.5 6.5 8 12 3.5 10
	//nums1.push_back(11); printV(nums1);//12 10 3.5 6.5 8 2.5 1.5 6 11
	//nums2.push_back(1.2); printV(nums2);//1.5 6 2.5 6.5 8 12 3.5 10 1.2
	//push_heap(nums1.begin(), nums1.end()); printV(nums1);//12 11 3.5 10 8 2.5 1.5 6 6.5
	//push_heap(nums2.begin(), nums2.end(), greater<>()); printV(nums2);//1.2 1.5 2.5 6 8 12 3.5 10 6.5
	//pop_heap(nums1.begin(), nums1.end()); printV(nums1);//11 10 3.5 6.5 8 2.5 1.5 6 12
	//pop_heap(nums2.begin(), nums2.end(), greater<>()); printV(nums2);//1.5 6 2.5 6.5 8 12 3.5 10 1.2
	//nums1.pop_back(); printV(nums1);//11 10 3.5 6.5 8 2.5 1.5 6
	//nums2.pop_back(); printV(nums2);//1.5 6 2.5 6.5 8 12 3.5 10
	//if (is_heap(nums2.begin(), nums2.end(),greater<>()))
	//	cout << "Great! We still have a heap2.\n";
	//else
	//	cout << "oh bother! We messed up the heap2.\n";

	//vector<double> nums2 = { 2.5, 10.0, 3.5, 6.5, 8.0, 12.0, 1.5, 6.0 };
	//make_heap(nums2.begin(), nums2.end(), greater<>());
	//pop_heap(nums2.begin(), nums2.end(), greater<>());
	//auto it2 = is_heap_until(nums2.begin(), nums2.end(), greater<>());
	//if (it2!=nums2.end())
	//	cout << "nums2 is a heap up to " << *it2 << endl;//1.5 指向首个不在堆内的元素
	//nums2.pop_back(); printV(nums2);//2.5 6 3.5 6.5 8 12 10
	//sort_heap(nums2.begin(), nums2.end(), greater<>());//必须确保nums2是堆
	//printV(nums2);//12 10 8 6.5 6 3.5 2.5

	deque<string> words;
	string word;
	cout << "Enter words separated by spaces, enter Ctrl+Z on a separate line to end:\n";
	while (true) {
		if ((cin >> word).eof()) {
			cin.clear();
			break;
		}
		words.push_back(word);
	}
	cout << "The words in the list are:\n";
	show(words);
	make_heap(words.begin(),words.end());
	cout << "\nAfter making a heap, the words in the list are:\n";
	show(words);

	cout << "\nYou entered " << words.size() << " words. Enter some more:\n";
	while (true) {
		if ((cin >> word).eof()) {
			cin.clear();
			break;
		}
		words.push_back(word);
		push_heap(words.begin(), words.end());
	}
	cout << "\nThe words in the list are now:\n";
	show(words);

	getchar();
	return 0;
}
*/


//7 统计单词个数原来还可以如此简洁
/*
int main(void) {
	cout << "Enter some text and enter * to end:\n";
	string text_in = "";
	getline(cin,text_in,'*');
	replace_if(text_in.begin(), text_in.end(), [](const char& ch) {return !isalpha(ch); }, ' ');

	istringstream text(text_in);
	istream_iterator<string> text_beg(text);
	istream_iterator<string> text_end;
	map<string, size_t> words;
	size_t max_len = 0;
	for_each(text_beg, text_end, [&max_len,&words](const string& word) {
		words[word]++;
		max_len = max(max_len,word.length());
	});

	size_t perline = 4, cnt = 0;
	for (const auto& w : words) {
		cout << left << setw(max_len + 1) << w.first << setw(3)
			 << right << w.second << " ";
		if (++cnt % perline == 0)
			cout << "\n";
	}
	cout << "\n";

	getchar();
	getchar();
	return 0;
}
*/


//8 STL之关联式容器map(一)
//关联容器: 对象的位置取决于它的键值。键是基本类型，类类型。
//map<K，T> 类模板: 定义保存T类型对象的 map，各T类型对象都有K类型的键。容器内对象的位置由比较键决定，唯一的要求是: 键必须可用less<K>自定义的函数对象替代
//8.1 初始化
//8.2 插入元素 --> 只能插入 map 中不存在的元素。
//insert(): 返回pair<iterator, bool>对象。
//对象成员first是一个迭代器，它指向插入元素，或阻止插入的元素。若map中已保存一个和这个键相同的对象，则为后者。
//对象成员second(布尔型)是返回对象，插入成功，返回true
//8.2.1 循环访问 --> 元素以键的升序排列，因为map默认用less<string>排序
//8.2.2 插入相同元素 --> insert()返回pair对象ret_pr，其成员变量first指向map中已有的和键匹配的元素，成员变量second为false，表明元素没有插入成功
//8.2.3 提供一个提示符， 指出元素插入位置
//insert() 第二个参数指定的新元素会被插入到提示符前面，并尽可能地靠近它
//如果被插入的元素已在map中，则插入失败
//确定元素不存在时，可只提供插入符; 若不确定，仍然想使用插入符，count()函数会返回map中指定键对应元素的数目，0或1
//count()函数返回0时，insert()才被调用，这说明“Ian”键不在map中
//8.2.4 外部源中的一段元素插入 map 
//这些元素不必来自另一个map，但必须和被插入容器中的元素同类型
//8.2.5接受初始化列表作为参数的insert()版本
//也可单独创建一个初始化列表，然后将它作为参数传递给insert()函数
//8.2.6 map 容器中元素是pair<const Name，size_t> 类型，可用下面定义的别名简化代码

//class Name {
//private:
//	string first_name{};
//	string second_name{};
//public:
//	Name() = default;
//	Name(string first, string second) :first_name(first), second_name(second) {};
//	bool operator<(const Name& name) {
//		return second_name < name.second_name || ((second_name==name.second_name) && (first_name<name.first_name));
//	}
//};

//map<string, size_t> people;
//map<string, size_t> people{ {"Ann",25},{"Bill",46},{"Jack",32},{"Jill",32} };
//map<string, size_t> people{make_pair("Ann",25),make_pair("Bill",46), make_pair("Jack",3), make_pair("Jill",32)};
//map<std::string, size_t> personnel{ people };
//map<std::string, size_t> personnel{ people.begin(),people.end() };
//map<std::string, size_t> personnel{++people.begin(),people.end()};


template<typename T1, typename T2>
void printMAP(map<T1, T2>& m) {
	cout << "print map: \n";
	auto it = m.begin();
	while (it != m.end()) {
		cout << it->first << "," << it->second << "\n";//key,value
		++it;
	}
}

/*
using Entry = std::pair<const Name, size_t>;
Entry get_entry() {
	cout << "Enter first and second names followed by the age: ";
	Name name;
	size_t age;
	cin >> name >> age;
	return make_pair(name,age);
}

void list_entries(const map<Name,size_t>& people) {
	for (auto& entry : people) {
		cout << left << setw(30) << entry.first 
			 << right << setw(4) << entry.second << "\n";
	}
}


int main(void) {
	//map<string, size_t> people{ make_pair("Ann",25),make_pair("Bill",46) , make_pair("Jack",32), make_pair("Jill",32) };
	//auto pr = make_pair("Fred",22);
	//auto ret_pr = people.insert(pr);
	//cout << ret_pr.first->first << " " << ret_pr.first->second << " " << boolalpha << ret_pr.second << endl;//Fred 22 true

	//for (const auto& p : people)
	//	cout << setw(10) << left << p.first << " " << p.second << "\n";

	//ret_pr = people.insert(make_pair("Bill", 48));
	//ret_pr = people.insert(pair<const string, size_t> {"Bill", 48});
	//cout << ret_pr.first->first << " " << ret_pr.first->second << " " << boolalpha << ret_pr.second << endl;//Bill 46 false

	//auto ret_pr = people.insert(make_pair("Jim",48));
	////cout << ret_pr.first->first << "\n";//Jim
	////people.insert(ret_pr.first, make_pair("Ian", 38));
	//if (!people.count("Ian"))
	//	people.insert(ret_pr.first, make_pair("Ian", 38));
	//printMAP(people);

	//map<string, size_t> crowd{ { "May", 55 },{ "Pat",66 },{ "Al", 22 },{ "Ben", 44 } };
	//crowd.insert({ { "Bert", 44 },{ "Ellen", 99}});
	//initializer_list<pair<const string, size_t>> init{ { "Bert", 44 },{ "Ellen", 99 } };
	//crowd.insert(init);
	//auto itr = people.begin();
	//advance(itr,4);
	//crowd.insert(++people.begin(),itr);
	//printMAP(crowd);
	
	map<Name, size_t> people{ { { "Ann", "Dante" }, 25 }, { { "Bill", "Hook" }, 46 }, { { "Jim", "Jams" }, 32 }, { { "Mark", "Time" }, 32 } };
	cout << "\nThe initial contents of the map is:\n";
	list_entries(people);
	char answer = 'Y';
	cout << "\nEnter a Name and age entry.\n";
	while (toupper(answer)=='Y') {
		Entry entry = get_entry();
		auto pr = people.insert(entry);
		if (!pr.second) {
			cout << "Key \"" << pr.first->first <<"\" already present. Do you want to update the age (Y or N)? ";
			cin >> answer;
			if (toupper(answer) == 'Y')
				pr.first->second = entry.second;
		}
		cout << "Do you want to enter another entry(Y or N)? ";
		cin >> answer;
	}
	cout << "\nThe map now contains the following entries:\n";
	list_entries(people);

	//getchar();
	system("pause");
	return 0;
}
*/


//9 STL之关联式容器map(二)
//9.3 构造元素
//(1) emplace() 在适当位置直接构造新元素，避免复制和移动操作
//当容器中现有元素的键与此元素的键不同时，才会构造这个元素。
//emplace()和insert() 返回的pair对象提供的指示相同。pair的成员变量first指向插入或阻止插入元素的迭代器;成员变量second是布尔值，插入成功，second为true
//(2) emplace_hint()和emplace() 生成元素的方式在本质上一样，但前者必须提供指示元素生成位置的迭代器，作为emplace_hint()的首参
//使用这个提示符，新元素会在此指示符表示的位置之前生成，并尽可能靠近这个位置
//emplace_hint() 返回值不是pair对象，若新元素被插入，返回指向新元素的迭代器; 没有插入，返回和此键匹配的现有元素的迭代器
//(3) size(): 获取map中对应元素的数量, 来检查map元素增加的数量
//
//9.4 获取元素
//at() 返回参数键对应的对象。若此键不存在，则拋出out_of_range异常
//默认构造函数会用键和键所关联的对象生成一个新元素，若键关联的对象是基本数据类型，其值为 0
//
//9.5 综合应用
//假设通过人名来保存并检索名人名言。显然，一个名人会有很多名言，因此需要通过单个键来保存多个名言。
//不能在map容器中保存重复的键，但可将键关联到封装了多个名言的对象上
//
//9.6 查找元素
//find() 返回一个元素的迭代器，此元素的键值和参数匹配
//若没有和参数匹配的元素，find()返回容器的结束迭代器，因此在使用此迭代器之前，必须先检查它
//
//9.7 删除元素
//(1) erase() 移除键和参数匹配的元素，返回移除元素的个数
//map 容器的返回值只能是0或1，0表明元素不在容器中
//也可用指向删除元素的迭代器作erase()参数。此时，返回的迭代器指向被删元素的下一位置。此参数必须是容器的有效迭代器，不能是结束迭代器。若迭代器参数指向容器尾元素，则返回结束迭代器
//(2) 移除两个迭代器参数所定义范围内的元素。
//返回的迭代器指向， 这段元素中最后一个被删除的元素。
//若要删除容器中所有元素，可调用成员函数clear()


/*
int  main(void) {
	//map<Name, size_t> people;
	//auto pr = people.emplace(Name{ "Dan","Druff" },77);
	//auto cnt = people.size();
	//auto itr = people.emplace_hint(pr.first, Name{ "Cal","Cutta" },62);
	//printMAP(people);
	//if (cnt < people.size())
	//	cout << "emplace_hint OK.\n";

	map<Name, size_t> people;
	people.emplace(Name{ "Dan","Druff" }, 77);
	//Name key;
	//try {
	//	key = Name{ "Dan", "Druff" };
	//	auto value = people.at(key);
	//	cout << key << "is aged " << value << endl;
	//	key = Name{ "Don", "Druff" };
	//	value = people.at(key);
	//	cout << key << " is aged " << value << endl;
	//}
	//catch (const out_of_range& e) {
	//	cerr << e.what() << '\n' << key << " was not found." << endl;
	//}
	//auto val = people[Name{"Ned","Kelly"}];
	//cout << "val=" << val << "\n";
	//people[Name{ "Ned","Kelly" }] = 39;
	//cout << "val=" << people[Name{ "Ned","Kelly" }] << "\n";

	getchar();
	return 0;
}
*/

/*
inline Name get_name() {
	Name name;
	cout << "Enter first name and second name: ";
	cin >> std::ws >> name;//std::ws 消除空格
	return name;
}

inline string get_quote(const Name& name) {
	cout << "Enter the quotation for " << name << ". Enter * to end:\n";
	string quote;
	getline(cin>>std::ws,quote,'*');
	return quote;
}


int main() {
	map<Name, Quotations> quotations;
	cout << "Enter 'A' to add a quote."
			"\nEnter 'L' to list all quotes."
			"\nEnter 'G' to get a quote."
			"\nEnter 'Q' to end.\n";
	Name name {};
	string quote {};
	char command {};
	while (command != 'Q') {
		cout << "\nEnter command: ";
		cin >> command;
		command = static_cast<char>(toupper(command));
		switch (command)
		{
		case 'Q':
			break;

		case 'A':
			name = get_name();
			quote = get_quote(name);
			quotations[name] << quote;
			break;

		case 'G':
			name = get_name();
			{
				const auto& quotes = quotations[name];
				size_t cnt = quotes.size();
				if (cnt == 0) {
					cout << "There are no quotes recorded for " << name << "\n";
					continue;
				}
				size_t idx=0;
				if (cnt > 1) {
					cout << "There are " << cnt << " quotes for " << name << ".\n" << "Enter an index from 0 to " << cnt - 1 << ": ";
					cin >> idx;
				}
				cout << quotations[name][idx] << "\n";
			}
			break;
			
		case 'L':
			if (quotations.empty())
				cout<< "\nNo quotations recorded for anyone." << endl;
			for (const auto& pr : quotations) {
				cout << "\n" << pr.first << "\n";
				for (const auto& quote : pr.second)
					cout << " " << quote << "\n";
			}
			break;

		default:
			cout << " Command must be 'A', 'G', 'L', or 'Q'. Try again.\n";
			continue;
			break;
		}
	}

	//getchar();
	system("pause");
	return 0;
}
*/

/*
int main(void) {
	map<string, size_t> people{ { "Fred", 45 },{ "Joan", 33 },{ "Jill", 22 },{"Bruce",20},{"Hero",99} };
	string name{ "Joan" };
	//auto itr = people.find(name);
	//if (itr == people.end())
	//	cout << "Not found.\n";
	//else
	//	cout << name << " is " << itr->second << "\n";

	if (people.erase(name))
		cout << name << " was removed." << "\n";
	else
		cout << name << " was not found" << "\n";
	printMAP(people);

	auto itr = people.erase(people.begin());//指向被删除元素的下一个位置
	if (itr==people.end())
		cout << "The last element was removed." << "\n";
	else
		cout << "The element preceding " << itr->first << "was removed." << "\n";
	printMAP(people);

	people.erase(++people.begin(),--people.end());


	getchar();
	return 0;
}
*/


//10 STL之关联式容器(pair,tuple和multimap)
//10.1 Pair
//10.1.1 初始化
//make_pair<T1，T2> 函数模板是一个辅助函数，生成并返回pair<T1，T2> 对象
//pair 对象也可以复制或移动构造其成员变量
//10.1.2 比较大小
//pair 对象有全套的运算符 == 、 != 、<、 <= 、>、 >= .
//对于<,>比较，pair 对象的成员变量按字典顺序比较
//10.1.3 交换元素
//swap() 可以和作为参数传入的另一个 pair 对象交换其成员变量 first 和 second。显然，参数必须是相同类型。
//执行两次 swap()，对象恢复成原来的值

//10.2 tuple --> 将多个对象当作一个对象传给函数，tuple 类型很有用
//10.2.1 初始化
//make_tuple(): 接受不同类型,任意个数的参数，返回的tuple类型由参数的类型决定
//tuple对象的构造函数提供了可能会用到的每一种选择。
//prl 成员变量 first 和 second 的类型是 const char*。这个类型可以隐式转换为 string，即 pr2 成员变量的类型，因此可以成功赋值。如果这些类型不能隐式转换，这条赋值语句就无法通过编译。
//10.2.2 比较大小
//可用任何比较运算符来比较相同类型的 tuple 对象。tuple 对象中的元素按字典顺序比较
//(1) tuple 对象中的元素是依次比较的，第一个不同的元素决定了比较结果。
//(2) 若是相等比较，任何一对不相等的对应元素都会使比较结果为 false
//10.2.3 交换元素 swap()
//tuple 中所有元素的类型都必须可交换
//10.2.4 访问元素
//tuple 中的对象数目不固定，所以访问它们的机制必须能满足这种情况。函数模板 get<>()可返回tuple中的一个元素
//可用基于类型的 get<>() 从 tuple 获取元素，但要求 tuple 中只有一个这种类型的元素。
//若tuple中包含的get<>()类型参数值的元素不止一个，则无法编译通过
//10.2.5 tie<>()
//全局的 tie<>() 提供了访问 tuple 元素的另一种方式。可把tuple中的元素值转换为， 可绑定到tie<>()的左值集合
//ignore 定义在 tuple 中，它被用来标记 tie() 函数中要被忽略的值.
//也可用 tie() 函数来实现对类的数据成员的字典比较。

//10.3 multimap
//若使用multimap，可以肯定它会包含键重复的元素; 否则，就应该使用 map
//multimap 容器保存的是有序的键/值对，可保存键重复的元素。multimap中会出现具有相同键的元素序列，它们会被添加到容器中
//10.3.1 插入元素
//(1) insert(): 插入一个或多个元素，而且插入总是成功。返回指向插入元素的迭代器。
//(2) emplace(): 可在容器的适当位置构造元素。
//(3) emplace_hint(): 插入具有相同键的元素，必须提供迭代器形式的提示符, 来控制元素的生成位置
//这两个函数都返回一个指向插入元素的迭代器。emplace_hint()尽可能近地在首参所指位置的前面，生成一个新元素。若只使用emplace()来插入 "Mopsy"，它可能会被插入到当前所有键为 "rabbit" 的元素的后面。
//10.3.2 访问元素
//不支持下标运算符，因为键不能确定一个唯一元素。和 map 相似，multimap 也不能使用 at() 函数。
//find(): 返回一个键和参数匹配的元素的迭代器。
//若未找到键，返回一个结束迭代器，所以应该总是检查返回值
//(1) equal_range(): 返回一个封装了两个迭代器的pair对象，这两个迭代器范围内元素的键和参数值相等。
//equal_range() 的参数可以是和键同类型，或不同类型但可和键比较的对象。返回的 pair 对象的成员变量 first 是迭代器，它指向第一个>=参数的元素；如果键和参数相等的元素存在，它是首个键和参数相同的元素。若键不存在，pair的成员变量first是容器的结束迭代器
//(2) lower_bound(): 返回一个迭代器，它指向键值和参数==或>参数的第一个元素，或者指向结束迭代器。
//(3) upper_bound(): 返回一个迭代器，它指向键值>函数参数的首个元素，若这样的元素不出现，它就是结束迭代器。
//当存在一个或多个相等键时，这些函数会返回一个开始和一个结束迭代器，指定了和参数匹配的元素的范围，这和equal_range() 返回的迭代器是相同的。
//(4)count(): 有多少个元素的键和给定的键相同。

/*
int main(void) {
	//string s1{ "one"}, s2{"two"};
	//pair<string, string> pair1(s1,s2);
	//pair<string, string> pair2{ string{"one"},string{"two"} };
	//pair<string, string> pair3{ "one" ,string{ "two" } };
	//pair<string, string> pair4{"one","two"};

	//auto pair1 = make_pair(s1,s2);
	//auto pair2 = make_pair(string{ "one" }, string{ "two" });
	//auto pair3 = make_pair<string, string>("one", string{ "two" });
	//auto pair4 = make_pair("one", "two");
	//pair<string, string> pair11{pair1};// Copy constructor

	//auto pr1 = make_pair("one","two");// Type pair<const char*, const char*>
	//pair<string, string> pr2;
	//pr2 = pr1;

	//pair<string, string> pss;
	//pss.first = "one";
	//pss.second = "two";
	//if (pss == pair<string, string>("one", "two"))
	//	cout << "Equality!\n";//"Equality!

	//pair<int, int> pii1{10,9};
	//pair<int, int> pii2{ 10,11 };
	//pair<int, int> pii3{ 11,9 };
	//cout << boolalpha << (pii1 < pii2) << " " << (pii1 > pii3) << " " << (pii3 > pii2) << "\n";//true false true
	//pii1.swap(pii2);
	//cout << "pii1=" << pii1.first << ", " << pii1.second << "\n";//10,11
	//cout << "pii2=" << pii2.first << ", " << pii2.second << "\n";//10,9

	getchar();
	return 0;
}
*/

/*
int main(void) {
	auto tup1 = make_tuple(Name{"one","two"}, 42, string{"13579"});
	//tuple<string, size_t> tup2;//Default initialization
	//tuple<Name, string> tup3{ Name{"three","four"},string{"coding"} };
	//tuple<Name, string> tup4{tup3};// Copy constructor
	//tuple<string, string> tup5{ "one","two" };// Implicit conversion

	//tuple<string, int> tup1{"abcd",12};
	//tuple<string, int> tup2{ "abcd",34 };
	//cout << boolalpha << (tup1<tup2) << "\n";//true
	//tup1.swap(tup2);
	//cout << get<0>(tup1) << "," << get<1>(tup1) << "\n";//abcd,34
	//cout << get<0>(tup2) << "," << get<1>(tup2) << "\n";//abcd,12

	//cout << get<Name>(tup1) << " age =" << get<int>(tup1) << ",tel= " << get<string>(tup1) << "\n";//one two age = 42, tel = 13579
	//Name name{};
	//size_t age{};
	//string phone{};
	//tie(name,age,phone) = tup1;
	//cout << "name=" << name << ",age=" << age << ",tel=" << phone << "\n";//name = one two, age = 42, tel = 13579
	//tie(name, ignore, phone) = tup1;
	//cout << "name=" << name << ",tel=" << phone << "\n";//name = one two, tel = 13579

	getchar();
	return 0;
}
*/


template<typename T1, typename T2>
void printMMAP(multimap<T1, T2>& m) {
	cout << "print multimap: \n";
	auto it = m.begin();
	while (it != m.end()) {
		cout << it->first << "," << it->second << "\n";//key,value
		++it;
	}
}

/*
int main(void) {
	//multimap <string, string> mmss;
	//auto itr = mmss.insert(pair<string, string>{string{"dog"}, string{"Fang"}});
	//itr = mmss.insert(itr,make_pair("dog","Spot"));
	////printMMAP(mmss);//dog,Spot	dog,Fang
	//mmss.insert(make_pair("cat", "Korky"));
	//mmss.insert({ { "rat", "Roland" },{ "pig", "Pinky" },{ "pig", "Perky" } });//Inserts list elements
	////printMMAP(mmss);
	//itr = mmss.emplace("rabbit","Flopsy");
	//itr = mmss.emplace_hint(itr, "rabbit", "Mopsy");//itr前面生成一个新元素。
	//printMMAP(mmss);

	multimap<string, size_t> people{ { "Ann",25 },{ "Bill", 46 },{ "Jack", 77 },{ "Jack", 32 },{ "Jill", 32 },{ "Ann", 35 } };
	//string name{ "Bill" };
	//auto itr = people.find(name);
	//if (itr != people.end())
	//	cout << name << "= " << itr->second << "\n";//Bill=46
	//itr = people.find("Ann");
	//if (itr != people.end())
	//	cout << itr->first << "= " << itr->second << "\n";//Ann=25

	//auto pr = people.equal_range("Ann");
	//if (pr.first != people.end()) {
	//	for (auto it = pr.first; it != pr.second; ++it)
	//		cout << it->first << "= " << it->second << "\n";//Ann=25,Ann=35
	//}
	//auto itr1 = people.lower_bound("Ann");
	//auto itr2 = people.upper_bound("Ann");
	//if (itr1 != people.end()) {
	//	for (auto it=itr1;it!=itr2;++it)
	//		cout << it->first << "= " << it->second << "\n";//Ann=25,Ann=35
	//}
	auto cnt = people.count("Jack");
	cout << "cnt=" << cnt << "\n";//cnt=2

	getchar();
	return 0;
}
*/

/*
using Pet_type = string;
using Pet_name = string;
int main(void) {
	multimap<Pet_type, Pet_name> pets;
	Pet_type type;
	Pet_name name;
	char more{'Y'};
	while (toupper(more) == 'Y') {
		cout << "Enter the type of your pet and its name: ";
		cin >> std::ws >> type >> name;
		auto itr = pets.lower_bound(type);//将给定键的第二个以及随后的元素插入到这个键序列的前面
		if (itr != pets.end())
			pets.emplace_hint(itr, type, name);
		else
			pets.emplace(type,name);
		cout << "Do you want to enter another(Y or N)? ";
		cin >> more;
	}
	printMMAP(pets);//cat, zl
					//cat, ls
					//dog, ww
					//dog, zs

	cout << "\nPet list by type:\n";
	auto it = pets.begin();
	while (it != pets.end()) {
		auto pr = pets.equal_range(it->first);
		cout << "\nPets of type " << it->first << " are:\n";
		for (auto& p = pr.first; p != pr.second; ++p)
			cout << " " << p->second;
		cout << "\n";
		it = pr.second;
	}

	//getchar();
	system("pause");
	return 0;
}
*/






























