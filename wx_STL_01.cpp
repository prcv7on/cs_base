

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

//--------- Linux C C++ר�� ---------

//1 C++����ϵ��֮STL��1��---����List����Դ��

//1.1 �⺯������Ƶ�һλ��ͨ���ԣ�ģ��Ϊ���ṩ�˿��ܣ���׼ģ����е������㷨����������ͨ��ģ��ʵ�ֵġ�
//STL(��׼ģ���)�� C++������ɫ����ʵ�õĲ���֮һ��

//1.2 �ܽ�
//(1) �������ı�����һ���ڲ��࣬������һ�������ڲ����ݳ�Ա��һ��ָ��ڵ��ָ�룻
//(2) ��������->�����ط��ؽڵ��ڲ����ݵĵ�ַ�������ǽڵ�ĵ�ַ
//(3) ��������ÿ�����ݽṹ��ʵ�־�����ͬ��(Stack, queue, list...........)
//(4) �ռ�������: ���������ݽṹ���ԣ�ֻ��һ�ݣ����ã����룬�ͷſռ䣬���죬��������

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

//2 C++����ϵ��֮STL��2��---SGI�汾�ռ�������
//2.1 STL�еĿռ�������
//��STL�У��ռ�����������2�飬�ֱ�Ϊһ���Ͷ����ռ��������������Ƕ��и������õĳ���: һ���ռ�����������Ŀռ����128B����������ռ�С��128B
//2.2 SGI��STL�Ŀռ������������ѧ:
//(1) ��system heapҪ������ռ�
//(2) ���Ƕ��̵߳�״̬
//(3) �����ڴ治��ʱ��Ӧ���ʩ
//(4) ���ǹ���"С������"������ɵ��ڴ���Ƭ����

//2.3 һ���ռ�������
//2.3.1 ����: ģ��ʵ����set_new_handler����
//set_new_handler���Ƶ�ʵ��: (1)����һ������ָ�� (2)����һ������ (3)��ֵ�Ƚ�
//2.3.2 ��һ���ռ�����������: (1)��malloc��free�ļ򵥷�װ��(2)ģ��C++��set_new_handler()�Դ����ڴ治������

//2.3.3 �ܽ�:
//(1)һ���ռ���������ʵ����, ���Լ����ٿռ䣬Ҫ��ʧ����:
//(2)���ô���ռ�ʧ�ܵĺ����������ڲ����ȿ���������û��д�������Ĵ�����. ��ûд���쳣�׳����������;
//(3)Ҫ��д�ˣ��͵����Լ�д�ĺ������ڴη���ռ䣬������ѭ���У�ֱ���ռ����ɹ��������˳�ѭ��;

//2.3 SGI�ڶ����ռ�������
//(1)ά��16�����������ֱ���16��С��������������������ڴ治�㣬����һ���ռ�������(�����д������);
//(2)������ռ���������128B, �͵���һ���ռ���������
//2.3.1 �ܽ�:
//�����ռ�������(���ɽ��ˮ��)--->����һ���ռ�������---->(1)�׳��쳣 (2)�����Լ���д�Ĵ�����

//2.3.2 STL�ڴ�����˼�룺
//C++STL�����������ڴ棺
//(1) ��һ���������ڴ棬��֤������new-handler�Ļ��ƣ�
//(2) �ڶ�������С���ڴ棬Ϊ���ù����ڴ���Ƭ������16������������"��"��һ��һ��̶���С���ڴ棬��16������0��15���ֱ�"��"���ڴ���8��16��24��128������ϵ��
//��Ҫ�ڴ�ʱ����"����"������ȡ�ߣ���"����"�������ڴ治���ã����ڴ���ã����ڴ�ز����ã�������ʱheap���ã���heapҲ����ˣ��ͽ�����һ������������Ϊ����set_new-handler���ơ�
//(3) ���ԣ������ϵĶ�������֮�󣬵ĸϽ���������


//3 C++����ϵ��֮STL��3��---STL�Ŀ��ʵ��
//3.1 ģ����ػ�
//����ģ�� : �Ը��ֲ�ͬ�汾�����⻯����---->�ػ�;
//3.2 ��ȡ
//����ͬ�Ĵ�����ȡ��ͬ������;
//3.3 ����
//(1) vector�Ŀռ�����Ը���;
//(2) POD��Ҳ���Ǳ����ͱ�Ҳ���Ǵ�ͳ���ͱ𣬲�ȡ��հ�ȫ������, ���ù��캯��������Ļ������ǵ���ϵͳ�ģ��������;���true;
//(3) �չ�����2�����ͣ���Բ�ͬ��ȡ�õ���_false_type��_true_type; �Ϳ��Ե��ò�ͬ�ĺ��������пռ�ķ��䣬����Ч���ϵĲ���!!!
//_true_type��������ϵͳ����亯����Ч�ʱȽϸ�.
//(4) �������㷨������ʵ�֣��ؼ���ͨ���ԣ�ģ����һ�ֺܺõĽ�������������ؼ�֮������ : ��������ʵ��;
//(5) �ռ�������������䡢���տռ䣬ֻ��һ������������Բ�ͬ�������в�ͬ��ʵ�ַ���!!!

//class A {};
//int main() {
//	vector<A> va(10);
//	getchar();
//	return 0;
//}

//4 C++����ϵ��֮STL��4��---����������
//������ȡ����
//(1) �������Ѷ�Ԫ����������һ�������̶���ʹ֮תΪһԪ������C++��׼�����ṩ��2��Ԥ�����binder��������bind1st��bind2nd���ֱ���˵�һ�� / �ڶ���������
//(2) ȡ��������ת����������
//(3) һԪ���������1��������ֻ��һ������ֵ��
//	  ��Ԫ���������2��������ֻ��һ������ֵ��
//(4) ������Ե��ǲ������󶨺���ֵ���䣬ȡ�����������ȡ����
//(5) ��ͨ�����Թ��� - g����Դ�����������

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

//5 C++����ϵ��֮STL��5��---vector��deque��list��ز���
//5.1 vector
//(1)�Զ�̬����Ԫ�ص���Ӻ�ɾ������ȡ
//(2)vector�ĳ�ʼ��
//(3)vector�е�����������ͷ������
//(4)vector�е�Ԫ��ɾ������
//5.2 deuqe ˫������ �ֶ��������ڴ�ռ����洢Ԫ��
//5.3 stack
//5.4 queue

//5.5 priority_queue --> ����: priority_queue<Type, Container, Functional>
//Type: �������ͣ�Container: �������ͣ�Container����������ʵ�ֵ�������vector,deque�ȣ�������list��STLĬ��vector����Functional: �ȽϷ�ʽ
//�Զ�����������, ����Ҫ��������������ʹ�û�����������ʱ��ֻ�贫���������ͣ�Ĭ�ϴ󶥶�

//5.6 list
//(1)list�ı���
//(2)list��ɾ��

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

	//vector<int> v5(10);//ǰ10��Ԫ�س�ʼ��Ϊ0��
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
	//li.insert(it,100);//insert��������Ĭ��ǰ��
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

//6 C++����ϵ��֮STL��6��---set��map��ز���
//6.1 set
//(1) set��ɾ�����������
//set�ײ��Ǻ����,Ԫ��Ψһ,Ԫ��Ĭ�ϴ�С��������,Ԫ�ذ�����������,����ָ������λ��
//(2) set������
////���ڻ������ݿ��Խ�������,�����������͵�����------>�º������
//(3) set��Ϊ������������ʱ������
//(4) set�е�������ʹ��
//6.2 multiset
//6.3 map
//(1) mapԪ�ص���ӡ�������ɾ��
//(2) map��4�ֳ�ʼ���ķ���
//(3) map����
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
////�º�����������()
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

	//set<int> si1;////Ĭ�������С����
	//set<int, less<int> > si2;
	//set<int, greater<int> > si3;//�Ӵ�С�����;
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
	//Stu s5("s5", 31);////��ʱ,���ڱȽϵ���age,���Խ������ʧ��,��Ϊ�º������õ���age���ļ�ֵ;
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
	auto mypair = si.equal_range(5);//��һ�Ե�����pair  ��һ��ָ���׸� >=key��Ԫ�أ��ڶ���ָ���׸� >key��Ԫ�ء�
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
	//map<int, string> mis;//��Ϊmap��key-value�ṹ,���Կ�������pair(����)
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
	//	cout << "key 5 insert failed." << "\n";//��Ϊ��ֵ��ͬ,���Բ����ʧ��;
	//}
	//else {
	//	cout << "key 5 insert OK.\n";
	//	cout << mypair6.first->first << "," << mypair6.first->second << endl;
	//}
	////ǰ���ֳ�ʼ�������ķ���ֵ��Ϊ��pair(iterator, bool)
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

	//map�Ĳ��ң�����ֵ���ǵ�����
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
	cout << "development��������:" << cnt << endl;
	cout << "development����Ա����Ϣ" << endl;
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


//7 C++����ϵ��֮STL��7��---STLѧϰ˼��
//(1) ģ�棺����ע������ͷ���ֵ��ģ��
//(2) STLһϵ�е�API������ע�ⷵ��ֵ
//(3) �����ж���ֵ����, ����������, ��ִ�в���ʱ, �ڲ�ʵ�п���, ����STL�в�����ʱ, һ�㶼���룺�޲ι��캯��, �������캯��, ���� = �����, ������Լ���д, �ﵽ���!!!
//(4) һԪν�ʣ�����ֻ��һ������, ν�ʣ��������ķ���ֵ����Ϊbool����;
//	  ��Ԫν�ʣ�����ֻ�ж�������, ν�ʣ��������ķ���ֵ����Ϊbool����;
//(5) �㷨�;����������������룺ͨ����������(�º���)��ʵ�֣�����: ����ָ��!!!
//(6) �����;����������������룬ͨ��ģ��ʵ�ֵģ�
//(7) �������������Ӧ�ĵ��������з��ʣ�
//(8) ������������ͨ���ռ�������������ռ�ģ�
//(9) ������������һԪ����Ԫ: ���������İ󶨣�


//8 C++����ϵ��֮STL��8��---�º���
//���ʣ���һ������������������
//ԭ�������ڶ�()���������أ�
//�º����ͻص�����������

/*
template<typename T>
class ShowElem {
private:
	int n;
public:
	ShowElem() { n = 0; }
	void operator()(T& t) {		//��������(),��ʱ�ɽ�����������;
		++n;
		cout << t << endl;
	}
	void printN() { cout << "n=" << n << endl; }
};

void main1() {
	int a = 10;
	ShowElem<int> SEi;
	SEi(a);		//��������()��ִ��,����һ������;�����ֽ����º���;
                //��������ɸ������ĵ���һ��,ֱ�ӰѶ���������������ʹ��!!!
}

//�����������ͨ����������:
template<typename T>
void FuncShowElem1(T& t) {	//����ģ��
	cout << t << endl;
}

void FuncShowElem2(int& t) { //��ͨ����
	cout << t << endl;
}

void main2() {
	vector<int> vi;
	vi.push_back(1);
	vi.push_back(3);
	vi.push_back(5);
	for_each(vi.begin(),vi.end(), ShowElem<int>());//������������ �����º���;
	cout << "\n";
	for_each(vi.begin(), vi.end(), FuncShowElem2);//ͨ���ص�����;˭ʹ��for_each()
}

int main(void) {
	main1();
	main2();
	getchar();
	return 0;
}
*/


//9 C++����ϵ��֮STL��9��---find_if(),plus,for_each()���÷�
//9.1 find_if()
//9.2 plus��ʹ��
//plus Ԥ����õĺ�������,��ʵ�ֲ�ͬ���� + �㷨��
//ʵ�����������ͺ��㷨�ķ���======��ͨ������������ʵ�ֵ�;
//˼��,��ô֪��plus<type>��2������------>�࿴��Դ��;
//9.3 for_each()
//9.4 for_each()��transform()������
//for_each��transform�ı�������
//���ۣ�
//1��һ�������,for_each��ʹ�õĺ�������,����������,û�з���ֵ;
//2��transform��ʹ�õĺ�������,����һ�㲻ʹ������,���ǻ��з���ֵ;

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
	//for_each(vi.begin(), vi.end(), show_elem);//���õ��ǻص�����
	//cout << "\n--------------\n";
	//for_each(vi.begin(), vi.end(), MyShow());//���õ��Ǻ�������(�������������())
	//cout << "\n--------------\n";
	//MyShow my1= for_each(vi.begin(), vi.end(), MyShow());
	//my1.printNum();

	vector<int> v2 = vi;
	for_each(vi.begin(),vi.end(),ShowElem1);
	cout << "\n--------------\n";
	transform(v2.begin(),v2.end(),v2.begin(),ShowElem2);//transform�Իص�������Ҫ��;����ֵ������
	cout << "\n--------------\n";

	getchar();
	return 0;
}
*/


//10 C++����ϵ��֮STL��10��---STL���ҡ������滻�������㷨
//10.1 STL�����㷨
//10.2 STL�����㷨
//10.3 STL�����滻
//10.4 STL�����㷨

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
	main_adjacent_find();   //���ҵ�һ���ظ���Ԫ��;
	main_binary_search();  //���ַ�����ĳһ��Ԫ��;
	main_count();  //����ĳһ��Ԫ�س��ֵĴ���; ��Ի�����������
	main_count_if(); //��һ��һԪν��,���Բ��Ҵ���ĳһ�����ֵĸ���; ����Զ������������
	main_find();  //����ĳһ���ݣ�ͨ��������ָ��; ��Ի�����������
	main_find_if();  //����ĳһ���ݣ�ͨ��������ָ��; ����Զ�����������;

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
	main_merge(); //�鲢����
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
	main_copy();  //����
	main_replace();  //�滻 ������������
	main_replace_if();  //�滻��Χ �Զ�����������
	main_swap();  //���������е�����
	main_accumulate(); //��ͺ���
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



//---------�������·---------

//1 Vectorͬʱ���������ԭ����
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


//2 STL֮string���Ա����
//2.1 string��Ա����
//���庯��


//2.2 ���ú���
//2.2.1 ���캯��
//string strs //���ɿ��ַ���
//string s(str) //�����ַ���str�ĸ���Ʒ
//string s(str, stridx) //���ַ���str��ʼ��stridx�Ĳ�����Ϊ���캯���ĳ�ֵ
//string s(str, strbegin, strlen) //���ַ���str��ʼ��strbegin������Ϊstrlen�Ĳ�����Ϊ�ַ�����ֵ
//string s(cstr) //��C_string����cstr��Ϊ�ַ���s�ĳ�ֵ
//string s(cstr, char_len)    //��C_string����cstr��ǰchar_len���ַ�����Ϊ�ַ���s�ĳ�ֵ
//strings(num, c) //����һ���ַ���������num��c�ַ�
//strings(strs, beg, end)
//������[beg, end]�ڵ��ַ���Ϊ�ַ���s�ĳ�ֵ
//
//string s('x');    //����
//std::string s(1, 'x');    //��ȷ
//std::string s("x");    //��ȷ

//2.2.2 ��������
//~string() //���������ڴ棬�ͷ��ڴ�

//2.2.3 ������
//(1) const_iterator begin() const;
//iterator begin();                //����string����ʼλ��
//(2) const_iterator end() const;
//iterator end();                    //����string�����һ���ַ������λ��
//(3) const_iterator rbegin() const;
//iterator rbegin();                //����string�����һ���ַ���λ��
//(4) const_iterator rend() const;
//iterator rend();                    //����string��һ���ַ�λ�õ�ǰ��

//2.2.4 �ַ�����
//int capacity() const;    //���ص�ǰ��������string�в��������ڴ漴�ɴ�ŵ�Ԫ�ظ�����
//int max_size() const;    //����string�����пɴ�ŵ�����ַ����ĳ���
//int size() const;        //���ص�ǰ�ַ����Ĵ�С
//int length() const;       //���ص�ǰ�ַ����ĳ���
//bool empty() const;        //��ǰ�ַ����Ƿ�Ϊ��
//void resize(int len, char c);//���ַ�����ǰ��С��Ϊlen�������ַ�c��䲻��Ĳ���

//2.2.5 ������
//
//2.2.6 ����Ԫ��
//const char& operator[](int n) const;
//const char& at(int n) const;
//char& operator[](int n);
//char& at(int n);

//2.2.7 �ַ����Ƚ�
//int compare(const string &s) const;//�Ƚϵ�ǰ�ַ�����s�Ĵ�С
//int compare(int pos, int n, const string &s)const;//�Ƚϵ�ǰ�ַ���pos��ʼ��n���ַ���ɵ��ַ�����s�Ĵ�С
//int compare(int pos, int n, const string &s, int pos2, int n2)const;//�Ƚϵ�ǰ�ַ�����pos��ʼn���ַ��ַ�����s��pos2��ʼn2���ַ��ַ����Ĵ�С
//int compare(const char *s) const;
//int compare(int pos, int n, const char *s) const;
//int compare(int pos, int n, const char *s, int pos2) const;

//2.2.8 ɾ��
//iterator erase(iterator first, iterator last);//ɾ��[first��last��֮��������ַ�������ɾ�����������λ��
//iterator erase(iterator it);//ɾ��itָ����ַ�������ɾ�����������λ��
//string& erase(int pos = 0, int n = npos);//ɾ��pos��ʼ��n���ַ��������޸ĺ���ַ���

//2.2.9 ��ֵ
//basic_string& assign(const E* s); //ֱ��ʹ���ַ�����ֵ
//basic_string& assign(const E* s, size_type n);
//basic_string& assign(const basic_string& str, size_type pos, size_type n);//��str���Ӵ���ֵ�����ô�
//basic_string& assign(const basic_string& str);    //ʹ���ַ����ġ����á��xֵ
//basic_string& assign(size_type n, E c); //ʹ�� n���ظ��ַ��xֵ
//basic_string& assign(const_iterator first, const_iterator last);    //ʹ�õ�������ֵ

//2.2.10 ����
//string& insert(int p0, const char *s);
//string& insert(int p0, const char *s, int n);
//string& insert(int p0, const string &s);
//string& insert(int p0, const string &s, int pos, int n);//��p0λ�ò���s��pos��ʼ��ǰn���ַ�

//string &insert(int p0, int n, char c);//��p0������n���ַ�c
//iterator insert(iterator it, char c);//��it�������ַ�c�����ز�����������λ��
//void insert(iterator it, const_iterator first, const_iterator last);//��it������[first��last��֮����ַ�
//void insert(iterator it, int n, char c);//��it������n���ַ�c

//2.2.11�滻
//string &replace(int p0, int n0, const char *s);		//ɾ��p0��ʼ��n0���ַ���Ȼ����p0�����봮s
//string &replace(int p0, int n0, const char *s, int n);//ɾ��p0��ʼ��n0���ַ���Ȼ����p0�������ַ���s��ǰn���ַ�
//string &replace(int p0, int n0, const string &s);		//ɾ��p0��ʼ��n0���ַ���Ȼ����p0�����봮s
//string &replace(int p0, int n0, const string &s, int pos, int n); //ɾ��p0��ʼ��n0���ַ���Ȼ����p0�����봮s�д�pos��ʼ��n���ַ�
//string &replace(int p0, int n0, int n, char c);					//ɾ��p0��ʼ��n0���ַ���Ȼ����p0������n���ַ�c
//string &replace(iterator first0, iterator last0, const char *s);			//��[first0��last0��֮���滻Ϊ�ַ���s
//string &replace(iterator first0, iterator last0, const char *s, int n);	//��[first0��last0��֮���滻Ϊs��ǰn���ַ�
//string &replace(iterator first0, iterator last0, const string &s);		//��[first0��last0��֮���滻Ϊ��s
//string &replace(iterator first0, iterator last0, int n, char c);			//��[first0��last0��֮���滻Ϊn���ַ�c
//string &replace(iterator first0, iterator last0, const_iterator first, const_iterator last);//��[first0��last0��֮��Ĳ����滻��[first��last��֮����ַ���

//2.2.12��ȡ
//string substr(int pos = 0, int n = npos) const;//����pos��ʼ��n���ַ���ɵ��ַ���
//2.2.13����

//int find(char c, int pos = 0) const;//��pos��ʼ�����ַ�c�ڵ�ǰ�ַ�����λ��
//int find(const char *s, int pos = 0) const;//��pos��ʼ�����ַ���s�ڵ�ǰ���е�λ��
//int find(const char *s, int pos, int n) const;//��pos��ʼ�����ַ���s��ǰn���ַ��ڵ�ǰ���е�λ��
//int find(const string &s, int pos = 0) const;//��pos��ʼ�����ַ���s�ڵ�ǰ���е�λ��
//���ҳɹ�ʱ��������λ�ã�ʧ�ܷ���string::npos��ֵ

//int rfind(char c, int pos = npos) const;//��pos��ʼ�Ӻ���ǰ�����ַ�c�ڵ�ǰ���е�λ��
//int rfind(const char *s, int pos = npos) const;
//int rfind(const char *s, int pos, int n = npos) const;
//int rfind(const string &s, int pos = npos) const;
//��pos��ʼ�Ӻ���ǰ�����ַ���s��ǰn���ַ���ɵ��ַ����ڵ�ǰ���е�λ�ã��ɹ���������λ�ã�ʧ��ʱ����string::npos��ֵ

//int find_first_of(char c, int pos = 0) const;//��pos��ʼ�����ַ�c��һ�γ��ֵ�λ��
//int find_first_of(const char *s, int pos = 0) const;
//int find_first_of(const char *s, int pos, int n) const;
//int find_first_of(const string &s, int pos = 0) const;
//��pos��ʼ���ҵ�ǰ���е�һ����s��ǰn���ַ���ɵ���������ַ���λ�á�����ʧ�ܷ���string::npos

//int find_first_not_of(char c, int pos = 0) const;
//int find_first_not_of(const char *s, int pos = 0) const;
//int find_first_not_of(const char *s, int pos, int n) const;
//int find_first_not_of(const string &s, int pos = 0) const;
//�ӵ�ǰ���в��ҵ�һ�����ڴ�s�е��ַ����ֵ�λ�ã�ʧ�ܷ���string::npos

//int find_last_of(char c, int pos = npos) const;
//int find_last_of(const char *s, int pos = npos) const;
//int find_last_of(const char *s, int pos, int n = npos) const;
//int find_last_of(const string &s, int pos = npos) const;
//int find_last_not_of(char c, int pos = npos) const;
//int find_last_not_of(const char *s, int pos = npos) const;
//int find_last_not_of(const char *s, int pos, int n) const;
//int find_last_not_of(const string &s, int pos = npos) const;
//find_last_of��find_last_not_of��find_first_of��find_first_not_of���ƣ�ֻ�����ǴӺ���ǰ����


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
//cout << st2.find("abcdefg",2,3) << endl;//6 ȡabcdefg��ǰ3���ַ���abc������ƥ�䣬�൱��st2.find("abc", 2)
//cout << st1.rfind('a',7) << endl;//6 ��ָ��λ������ǰ���ң�ֱ������

//string s6("bcgjhikl");
//string s7("kghlj");
//string s8("abcdefg");
////find_first_of-��Դ���д�λ��pos������ң�ֻҪ������Ŀ�괮������һ���ַ���ͬ����ֹͣ���ң����ظ��ַ���Դ����λ�ã�ƥ��ʧ�ܣ�����-1
//cout << s6.find_first_of(s7, 0) << endl;//2 ��str7�ĵ�0���ַ�b��ʼ�ң�g��str8�е�gƥ�䣬ֹͣ���ң�����g��str7�е�λ��2
//cout << s8.find_last_of("hjlywkcipn",6) << endl;//2
////find_first_not_of-��Դ���д�λ��pos������ң�ֻҪ������Ŀ�괮�е������ַ�������ͬ����ֹͣ���ң����ظ��ַ���Դ���е�λ�ã��������궼�Ҳ������򷵻�-1
//cout << s8.find_first_not_of("kiajbvehfgmlc", 0) << endl;//3 ��Դ��s8��λ��0(a)��ʼ���ң�Ŀ�괮����a��ƥ�䣬..,��d��Ŀ�괮��û��d����ƥ�䣩��ֹͣ���ң�����d��str�е�λ��3
//cout << s8.find_last_not_of("kiajbvehfgmlc", 6) << endl;//3
//------------------------------------------------------------------------

//string str("12345678");
//char ch[] = "abcdefgh";
//string a; //����һ�����ַ���
//string str1(str); //���캯����ȫ������
//string str2(str, 2, 5); //���캯�������ַ���str�ĵ�2��Ԫ�ؿ�ʼ������5��Ԫ�أ���ֵ��str_2
//string str3(ch, 5); //���ַ���ch��ǰ5��Ԫ�ظ�ֵ��str_3
//string str4(5, 'X'); //�� 5 �� 'X' ��ɵ��ַ��� "XXXXX" ��ֵ�� str_4
//string str5(str.begin(), str.end()); //�����ַ��� str ������Ԫ�أ�����ֵ�� str_5
//cout << "str="<<str << endl;
//cout << "a=" << a << endl;
//cout << "str1=" << str1 << endl;//12345678
//cout << "str2=" << str2 << endl;//34567
//cout << "str3=" << str3 << endl;//abcde
//cout << "str4=" << str4 << endl;//XXXXX
//cout << "str5=" << str5 << endl;//12345678
//-----------------------------------------------------

//string s1("The zip code of Hondelage in Germany is 38108.");
//string sd(s1.begin(), s1.end()); //���캯����ʹ�õ�����
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

////getline(istream &in, string &s); //���ڴ�������in�ж�ȡ�ַ�����s�У��Ի��з�'\n'�ֿ�
//string s11,s12;
//cout << "Input s11 s12: \n";
//getline(cin, s11); // ʵ���˶�ȡһ���ַ��������ո��Ʊ�����س����������ַ��ͷ��ţ���\n�ֿ�
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
////�����Ǹ��ֱȽϷ���
//int m = A.compare(B); //������A��B�ıȽ�
//int n = A.compare(1, 5, B, 4, 2); //"Bcdef"��"AbcdEf"�Ƚ�
//int p = A.compare(1, 5, B, 4, 2); //"Bcdef"��"Ef"�Ƚ�
//int q = C.compare(0, 3, D, 0, 3); //"123"��"123"�Ƚ�
//cout << "m = " << m << ", n = " << n << ", p = " << p << ", q = " << q << endl;//1 -1 -1 0
//------------------------------------------------

//string str1("123456");
//string str;
//str.assign(str1);				cout << str << endl;//123456 ֱ�Ӹ�ֵ
//str.assign(str1, 3, 3);			cout << str << endl;//456 ��ֵ���Ӵ�
//str.assign(str1, 2, str1.npos);	cout << str << endl;//3456 ��ֵ����λ�� 2 ��ĩβ���Ӵ�
//str.assign(5, 'X');				cout << str << endl; //XXXXX �ظ� 5 ��'X'�ַ�
//
//auto itB = str1.begin();
//auto itE = str1.end();
//str.assign(itB, (--itE)); //�ӵ� 1 ���������� 2 ��Ԫ�أ���ֵ���ַ��� str
//cout << str << endl;//12345
//------------------------------------------------

system("pause");
return 0;
}
*/


//3 STL֮����ʽ������array��vector��
//3.1 array
//array<T, N> ��N��T����Ԫ�صĹ̶����С���Ҫָ��Ԫ�ص����ͺ͸������ͳ�������û�в����Ȼ���������ӻ�ɾ��Ԫ�ء�
//(1) ��ʼ��
//(2) ����Ԫ��
//(3) ������
//(4) �Ƚϴ�С

//3.2 vector
//vector<T>:   T����Ԫ�ص�������������С���Զ��������ɰ�������������Ԫ��
//(1) ��ʼ��
//(2) ������С 
//capacity: �ڲ���������ڴ�, �ɱ�������Ԫ�ظ���
//size: ʵ����������Ԫ�ظ�������ֵԪ�صĸ���
//resize:

//(3) ����Ԫ��
// emplace(): ��һ�������ǵ�������ȷ���������ɵ�λ�á����󱻲��뵽��������ָ��Ԫ�صĺ��档����Ĳ���������Ϊ����Ԫ�صĹ��캯���Ĳ���
// insert(): ����vector�в���>=1��Ԫ�ء���һ����������һ��ָ������� const �� non-const ��������
//Ԫ�ر��嵽��һ��������ָԪ�ص�ǰ�棬�����һ��������һ�������������Ԫ�ر��嵽��������ָԪ�صĺ��档
// find(): ��ͷ��������ָ����һ��Ԫ���У���������������ָ����Ԫ�أ����ص�һ���ҵ���Ԫ��

//(4) ������
//(5) ����Ԫ��
//front() �� back(): ���������е�һ�������һ��Ԫ�ص����ã�
//data(): ����һ��ָ�������ָ�룬�����ڲ��������洢Ԫ��
//data() ����vector<T>������ T* ���͵�ֵ��

//(6) ɾ��Ԫ��
//clear()
//pop_back()
//shrink_to_fit()
//erase()
//remove()
//(7) ����Ԫ��

/*
int main() {
//array<int,100> data1;
//array<int,100> data2;
//array<double, 10> arr{0.5,1.0,1.5,2.0};
//arr.fill(3.2);

//arr[4] = arr[3] + 2.0*arr[1];//�����Խ��
////values.at(4) = values.at(3) + 2.0*values.at(1);//���Խ��
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
//vector<long> nums(20,99L);//20 ��Ԫ�ص�ֵ���� 99L��

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
//data.clear(); // Remove all elements ������������ 100��
//cout << data.size() << " " << data.capacity() << endl;

//vector<int> data = {1,2,3,4,5,6,7,8,9,10}; // Contains 10 elements initialized to 12
//data.pop_back(); // Remove the last element
//cout << data.size() << " " << data.capacity() << endl;//9 10

////����Ҫɾ�� data �еĵڶ���Ԫ��
//swap(data.begin() + 1, data.end() - 1);// Interchange 2nd element with the last
//data.pop_back();// Remove the last element
//cout << data.size() << " " << data.capacity() << endl;//8 10

////ȥ�������ж�������������粻���������������Ԫ�أ�����shrink_to_fit()ʵ�֣�
//data.shrink_to_fit(); // Reduce the capacity to that needed for elements
//cout << data.size() << " " << data.capacity() << endl;//8,8
//printVi(data);//1,2,3,4,5,6,7,8
//auto iter1 = data.erase(data.begin() + 1); //Delete the second element. ��ָ��ɾ��Ԫ�غ�һ��Ԫ��
//cout << "*iter1=" << *iter1 << endl;//3
//printVi(data);//1 3 4 5 6 7 8
//auto iter2 = data.erase(data.begin() + 1, data.begin() + 3);// Delete the 2nd and 3rd elements. �ڶ���������ָ�����Ԫ��ĩβ����һ��λ��
//printVi(data);//1 5 6 7 8

////����� remove() ��������� words �е�Ԫ�أ�ֻ�����ǰ 5 ��Ԫ�ء����� size() ���ص�ֵ��Ȼ�� 7��
////�����������Ԫ����Ȼ���ڣ��������Ǳ��滻���˿��ַ�������
//vector<string> words = { "one", "none","some", "all", "none", "most","many"};
//auto iter3 = remove(words.begin(), words.end(), "none");
//cout << words.size() << " " << words.capacity() << endl;//7,7
//printVs(words);//one some all most many
//words.erase(iter3, words.end());//Remove surplus elements
//cout << words.size() << " " << words.capacity() << endl;//7,7
//printVs(words);//one some all most many

////erase - remove��ִ��ɾ��������iter ָ�����һ��Ԫ��֮���λ�ã�
////��������ʶ�˱�ɾ�����еĵ�һ��Ԫ�أ���ɾ�����еĽ���λ���� end(words) ָ��
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
// Move string("adiabatic"�� into the vector
words1.push_back("cde"); // Move string("adiabatic")
printVs(words1);//ab cde

vector<string> words2;
words2.push_back(string("fghi")); // Calls string constructor & moves the string object
words2.emplace_back("jklmn");// Calls string constructor to create element in place		//emplace back() �� push_back() ����Ч��
printVs(words2);//fghi jklmn

// emplace_back() ��������ý������������� string ���캯�������� string ����
// Ȼ�������ӵ� words �����С����캯��������һ�������� 2 ��ʼ������ str �������ַ����Ӵ���
string str{ "polytech" };
words2.emplace_back(str, 2, 3);
printVs(words2);//fghi jklmn lyt
// Create string object corresponding to "leg" in place

system("pause");
return 0;
}
*/

//4 STL֮����ʽ������deque��list��
//4.1 deque
//deque<T>   ˫�˶�����֯Ԫ�أ���������ͷβ����Ч����ӻ�ɾ�����������vector�����ơ�
//(1) ��ʼ�������ʣ�����
//(2) �޸�Ԫ��
//(3) �ۺϾ���

//4.2 list
//list<T>	T���Ͷ����˫���������������κ�λ�ò����ɾ��Ԫ�ء�ȱ��: �޷�ͨ��λ����������ʣ�������������Ԫ��
//(1) ��ʼ��
//(2) ����Ԫ��
//(3) ɾ��Ԫ��
//remove(val)
//remove_if(naryPredicate p)//������һ�� lambda ���ʽ��Ҳ����һ����������
//unique()//�Ƴ��������ظ�Ԫ�أ��������еĵ�һ��

//(4) ����
//sort() ����ģ��Ҫ��������ʵ���������lis ����ֻ�ṩ˫�������.
//1) listģ�嶨���Լ��� sort() ������
//�������汾���޲�sort()������Ԫ���������С��ڶ����汾�� sort() ����һ����������� lambda ���ʽ�������ֲ���������һ���������Ƚ�����Ԫ��
//2) �ɽ��Զ���ĺ������󴫸�����,���� list ����
//3) ����Ҫ�ȽϷ�Ĭ������ʱ������Ҫһ����������

//(5) �ϲ�
//merge(list&& other, Compare comp): �鲢��������������Ϊһ������������������
//splice(): ��һ�� list ת��Ԫ�ظ���һ���������ƻ��ƶ�Ԫ�أ�����ָ����������ڲ�ָ��

//4.3 forward_list
//forward_list ��������ʽ�洢Ԫ�ء�
//forward_list �� list ����Ҫ������: �����ܷ������Ԫ�أ�ֻ�ܴ�ͷ��β������
//forward_list �� list ��Ҫ�죬ռ���ڴ����.

//�ص㣺
//�޷�ʹ�÷����������ֻ�ܴ����õ�const��non - constǰ�����������Щ�����������ܽ����ã�ֻ��������
//û�пɷ���βԪ�����õĳ�Ա����back(); ֻ�г�Ա����front();
//��Ϊֻ������ǰ��Ԫ�صĵ������������������յ㣬û��push_back()��pop_back()��emplace_back()

//(1) ��С
//forward_listֻ��ǰ����������޳�Ա����size()��������һ��ǰ���������ȥ��һ��

//(2) ����
//distance()����һ����������ʼ���������ڶ���������������������ָ��Ԫ�ط�Χ
//advance()����ǰ��������ƶ����λ��
//
//(3) ����
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
//ls3.splice(++ls3.begin(),ls4,++ls4.begin());//(ָ��Ŀ�������ĵ�����, Ԫ����Դ,��ճ��Ԫ�صĵ����������ᱻ�嵽�ײ���ָλ��֮ǰ)
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
//ls4.splice(ls4.end(),ls3);//��һ������Ҳ������ ls4.begin()
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


//5 STL֮������������stack,queue��priority_queue��
//������������Ҫ������:
//stack<T>: ��װ��deque<T> ��������������ģ�壬Ĭ��ʵ��һ�������ȳ���ѹ��ջ��
//queue<T>: ��װ��deque<T> ��������������ģ�壬Ĭ��ʵ��һ�������ȳ��Ķ��С���Ϊ��ָ��һ������ȷ�������Ļ���������
//priority_queue<T>: ��װ�� vector<T> ��������������ģ�壬Ĭ��ʵ��һ����Ԫ�����򣬱�֤���Ԫ��������ǰ��Ķ���

//5.1 stack
//ֻ�ܷ��� stack ������Ԫ�أ�ֻ�����Ƴ� stack ������Ԫ�غ󣬲��ܷ����·���Ԫ�ء�
//
//5.1.1 ��ʼ��
//(1) stack<string> words;
//(2) stack<string, list<string>> fruit;//ͨ��ָ���ڶ���ģ�����Ͳ���������ʹ���������͵ĵײ�����
//(3) list<double> values{ 1.414, 3.14159265, 2.71828 };
//stack<double, list<double>> my_stack(values);
//(4) stack<double, list<double>> copy_stack{ my_stack }//�������캯��
//
//5.1.2 ��������
//(1) top(): ����һ��ջ��Ԫ�ص����ã�����Ϊ T&�����ջΪ�գ�����ֵδ���塣
//(2) push(const T& obj): �����󸱱�ѹ��ջ����ͨ�����õײ�������push_back()�������
//(3) push(T&& obj): ���ƶ�����ķ�ʽ������ѹ��ջ����ͨ�����õײ�������ֵ���ò�����push_back()�������
//(4) pop(): ����ջ��Ԫ��
//(5) size(): ����ջ��Ԫ�ظ���
//(6) empty(): ��ջ��û��Ԫ�ص�����·��� true
//(7) emplace(): �ô���Ĳ������ù��캯������ջ�����ɶ���
//(8) swap(stack<T> & other_stack): ����ǰջ�кͲ����е�Ԫ�ؽ���������������Ԫ�ص����ͱ���͵�ǰջ����ͬ

//5.2 queue
//ֻ����������ĩβ�����Ԫ�أ�ֻ�ܴ�ͷ���Ƴ�Ԫ�ء�
//5.2.1 ��ʼ��
//(1) queue<string> words;
//(2) queue<string> copy_words{ words };//�������캯��
//(3) queue<string, list<string>> words;//ָ������ģ��
//5.2.2 ��������
//(1) front(): ���� queue ����Ԫ�ص����á���queue�ǳ��������س����ã���queueΪ�գ�����ֵδ����
//(2) back():  ���� queue ��βԪ�ص����á���queue�ǳ��������س����ã���queueΪ�գ�����ֵδ����
//(3) push(const T& obj): ��queueβ�����Ԫ�صĸ�����ͨ�����õײ������ĳ�Ա����push_back()���
//(4) push(T&& obj): ���ƶ��ķ�ʽ��queueβ�����Ԫ�ء�ͨ�����õײ������ľ�����ֵ���ò����ĳ�Ա����push_back()���
//(5) pop(): ɾ�� queue ����Ԫ��
//(6) size(): ���� queue ��Ԫ�ظ���
//(7) empty(): �� queue ��û��Ԫ�أ����� true��
//(8) emplace(): �ô���emplace()�Ĳ�������T�Ĺ��캯������queueβ�����ɶ���
//(9) swap(queue<T> &other_q): ����ǰqueue�е�Ԫ�غͲ���queue�е�Ԫ�ؽ���

//5.3 priority_queue --> �������������ṩ����ʱ�䣨Ĭ�ϣ����Ԫ�ز��ң��������۵Ĳ������ͳ���
//template <typename T, typename Container=vector<T>, typename Compare=less<T>> class priority_queue
//priority_queue ģ���� 3 ������������������Ĭ�ϵĲ�����
//(1) �洢��������ͣ�
//(2) �洢Ԫ�صĵײ�������
//(3) ����������������һ����������Ԫ��˳��Ķ��ԡ�
//
//5.3.1 ��ʼ��
//(1) priority_queue<string> words;
//(2) string wrds[]{ "one", "two", "three", "four" };//�ʵ����ͳ�ʼ������
//	  priority_queue<string> words{ begin(wrds),end(wrds) };
//(3) string wrds[]{ "one", "two", "three", "four" };
//	  priority_queue<string, vector<string>,greater<string>> words1{ begin(wrds) , end(wrds) };//���ȼ����ж����ǽ�������
//(4) vector<int> values{ 21, 22, 12, 3, 24, 54, 56 };
//    priority_queue<int> numbers{ less<int>(),values };
//(5) priority_queue<int, vector<int>, greater<int>> numbersl{ greater<int>(), values };//ָ��ȫ��ģ�����
//
//5.3.2 ��������
//(1) push(const T& obj): ��obj�ĸ����ŵ��������ʵ�λ�ã�����һ�����������
//(2) push(T&& obj): ��obj�ŵ��������ʵ�λ�ã�����һ�����������
//(3) emplace(T constructor a rgs...): ���ô�������Ĺ��캯���������е��ʵ�λ�ù���һ��T����Ϊά������˳����Ҫһ�����������
//(4) top(): �������ȼ���������Ԫ�ص�����
//(5) pop(): �Ƴ���Ԫ�ء�
//(6) size(): ���ض�����Ԫ�ظ���
//(7) empty(): ������Ϊ�գ�����true
//(8) swap(priority_queue<T>& other): �Ͳ�����Ԫ�ؽ��н�������������������ͱ�����ͬ��


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


//6 STL֮������������heaps��
//�ѵĵײ�ʵ������ȫ������: ���ڵ������ӽڵ�λ����ԡ��󶥶�: ���ڵ�>=�ӽڵ�; С����: ���ڵ�<=�ӽڵ�
//ע��: �������ڵ���ӽڵ㲻һ����˳�����С�
//
//6.1 ��ʼ��: 
//max_heap() ��������ʵ�����ָ����һ��Ԫ���������У�����һ���ѡ�Ĭ��ʹ�� < ����������ɴ󶥶ѡ�
//6.2 ���Ԫ��:		push_heap(begin,end)
//�Զ��庯�����:	push_heap(begin,end,greater<>())
//6.3 ɾ��Ԫ��:     pop_heap(begin,end) --> ����Ԫ���Ƶ���󣬲���֤ʣ�µ�Ԫ������һ����
//ɾ�����Ԫ�غ����Ԫ�ص�����Щ���ƣ��������������෴�ġ����ȵ��� pop_heap()��Ȼ����������Ƴ����Ԫ��
//�Զ��庯��ɾ��:   pop_heap(begin,end,greater<>())

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
	//	cout << "nums2 is a heap up to " << *it2 << endl;//1.5 ָ���׸����ڶ��ڵ�Ԫ��
	//nums2.pop_back(); printV(nums2);//2.5 6 3.5 6.5 8 12 10
	//sort_heap(nums2.begin(), nums2.end(), greater<>());//����ȷ��nums2�Ƕ�
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


//7 ͳ�Ƶ��ʸ���ԭ����������˼��
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


//8 STL֮����ʽ����map(һ)
//��������: �����λ��ȡ�������ļ�ֵ�����ǻ������ͣ������͡�
//map<K��T> ��ģ��: ���屣��T���Ͷ���� map����T���Ͷ�����K���͵ļ��������ڶ����λ���ɱȽϼ�������Ψһ��Ҫ����: ���������less<K>�Զ���ĺ����������
//8.1 ��ʼ��
//8.2 ����Ԫ�� --> ֻ�ܲ��� map �в����ڵ�Ԫ�ء�
//insert(): ����pair<iterator, bool>����
//�����Աfirst��һ������������ָ�����Ԫ�أ�����ֹ�����Ԫ�ء���map���ѱ���һ�����������ͬ�Ķ�����Ϊ���ߡ�
//�����Աsecond(������)�Ƿ��ض��󣬲���ɹ�������true
//8.2.1 ѭ������ --> Ԫ���Լ����������У���ΪmapĬ����less<string>����
//8.2.2 ������ͬԪ�� --> insert()����pair����ret_pr�����Ա����firstָ��map�����еĺͼ�ƥ���Ԫ�أ���Ա����secondΪfalse������Ԫ��û�в���ɹ�
//8.2.3 �ṩһ����ʾ���� ָ��Ԫ�ز���λ��
//insert() �ڶ�������ָ������Ԫ�ػᱻ���뵽��ʾ��ǰ�棬�������ܵؿ�����
//����������Ԫ������map�У������ʧ��
//ȷ��Ԫ�ز�����ʱ����ֻ�ṩ�����; ����ȷ������Ȼ��ʹ�ò������count()�����᷵��map��ָ������ӦԪ�ص���Ŀ��0��1
//count()��������0ʱ��insert()�ű����ã���˵����Ian��������map��
//8.2.4 �ⲿԴ�е�һ��Ԫ�ز��� map 
//��ЩԪ�ز���������һ��map��������ͱ����������е�Ԫ��ͬ����
//8.2.5���ܳ�ʼ���б���Ϊ������insert()�汾
//Ҳ�ɵ�������һ����ʼ���б�Ȼ������Ϊ�������ݸ�insert()����
//8.2.6 map ������Ԫ����pair<const Name��size_t> ���ͣ��������涨��ı����򻯴���

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


//9 STL֮����ʽ����map(��)
//9.3 ����Ԫ��
//(1) emplace() ���ʵ�λ��ֱ�ӹ�����Ԫ�أ����⸴�ƺ��ƶ�����
//������������Ԫ�صļ����Ԫ�صļ���ͬʱ���Żṹ�����Ԫ�ء�
//emplace()��insert() ���ص�pair�����ṩ��ָʾ��ͬ��pair�ĳ�Ա����firstָ��������ֹ����Ԫ�صĵ�����;��Ա����second�ǲ���ֵ������ɹ���secondΪtrue
//(2) emplace_hint()��emplace() ����Ԫ�صķ�ʽ�ڱ�����һ������ǰ�߱����ṩָʾԪ������λ�õĵ���������Ϊemplace_hint()���ײ�
//ʹ�������ʾ������Ԫ�ػ��ڴ�ָʾ����ʾ��λ��֮ǰ���ɣ��������ܿ������λ��
//emplace_hint() ����ֵ����pair��������Ԫ�ر����룬����ָ����Ԫ�صĵ�����; û�в��룬���غʹ˼�ƥ�������Ԫ�صĵ�����
//(3) size(): ��ȡmap�ж�ӦԪ�ص�����, �����mapԪ�����ӵ�����
//
//9.4 ��ȡԪ��
//at() ���ز�������Ӧ�Ķ������˼������ڣ��򒁳�out_of_range�쳣
//Ĭ�Ϲ��캯�����ü��ͼ��������Ķ�������һ����Ԫ�أ����������Ķ����ǻ����������ͣ���ֵΪ 0
//
//9.5 �ۺ�Ӧ��
//����ͨ�����������沢�����������ԡ���Ȼ��һ�����˻��кܶ����ԣ������Ҫͨ�������������������ԡ�
//������map�����б����ظ��ļ������ɽ�����������װ�˶�����ԵĶ�����
//
//9.6 ����Ԫ��
//find() ����һ��Ԫ�صĵ���������Ԫ�صļ�ֵ�Ͳ���ƥ��
//��û�кͲ���ƥ���Ԫ�أ�find()���������Ľ����������������ʹ�ô˵�����֮ǰ�������ȼ����
//
//9.7 ɾ��Ԫ��
//(1) erase() �Ƴ����Ͳ���ƥ���Ԫ�أ������Ƴ�Ԫ�صĸ���
//map �����ķ���ֵֻ����0��1��0����Ԫ�ز���������
//Ҳ����ָ��ɾ��Ԫ�صĵ�������erase()��������ʱ�����صĵ�����ָ��ɾԪ�ص���һλ�á��˲�����������������Ч�������������ǽ�����������������������ָ������βԪ�أ��򷵻ؽ���������
//(2) �Ƴ��������������������巶Χ�ڵ�Ԫ�ء�
//���صĵ�����ָ�� ���Ԫ�������һ����ɾ����Ԫ�ء�
//��Ҫɾ������������Ԫ�أ��ɵ��ó�Ա����clear()


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
	cin >> std::ws >> name;//std::ws �����ո�
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

	auto itr = people.erase(people.begin());//ָ��ɾ��Ԫ�ص���һ��λ��
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


//10 STL֮����ʽ����(pair,tuple��multimap)
//10.1 Pair
//10.1.1 ��ʼ��
//make_pair<T1��T2> ����ģ����һ���������������ɲ�����pair<T1��T2> ����
//pair ����Ҳ���Ը��ƻ��ƶ��������Ա����
//10.1.2 �Ƚϴ�С
//pair ������ȫ�׵������ == �� != ��<�� <= ��>�� >= .
//����<,>�Ƚϣ�pair ����ĳ�Ա�������ֵ�˳��Ƚ�
//10.1.3 ����Ԫ��
//swap() ���Ժ���Ϊ�����������һ�� pair ���󽻻����Ա���� first �� second����Ȼ��������������ͬ���͡�
//ִ������ swap()������ָ���ԭ����ֵ

//10.2 tuple --> �����������һ�����󴫸�������tuple ���ͺ�����
//10.2.1 ��ʼ��
//make_tuple(): ���ܲ�ͬ����,��������Ĳ��������ص�tuple�����ɲ��������;���
//tuple����Ĺ��캯���ṩ�˿��ܻ��õ���ÿһ��ѡ��
//prl ��Ա���� first �� second �������� const char*��������Ϳ�����ʽת��Ϊ string���� pr2 ��Ա���������ͣ���˿��Գɹ���ֵ�������Щ���Ͳ�����ʽת����������ֵ�����޷�ͨ�����롣
//10.2.2 �Ƚϴ�С
//�����καȽ���������Ƚ���ͬ���͵� tuple ����tuple �����е�Ԫ�ذ��ֵ�˳��Ƚ�
//(1) tuple �����е�Ԫ�������αȽϵģ���һ����ͬ��Ԫ�ؾ����˱ȽϽ����
//(2) ������ȱȽϣ��κ�һ�Բ���ȵĶ�ӦԪ�ض���ʹ�ȽϽ��Ϊ false
//10.2.3 ����Ԫ�� swap()
//tuple ������Ԫ�ص����Ͷ�����ɽ���
//10.2.4 ����Ԫ��
//tuple �еĶ�����Ŀ���̶������Է������ǵĻ��Ʊ����������������������ģ�� get<>()�ɷ���tuple�е�һ��Ԫ��
//���û������͵� get<>() �� tuple ��ȡԪ�أ���Ҫ�� tuple ��ֻ��һ���������͵�Ԫ�ء�
//��tuple�а�����get<>()���Ͳ���ֵ��Ԫ�ز�ֹһ�������޷�����ͨ��
//10.2.5 tie<>()
//ȫ�ֵ� tie<>() �ṩ�˷��� tuple Ԫ�ص���һ�ַ�ʽ���ɰ�tuple�е�Ԫ��ֵת��Ϊ�� �ɰ󶨵�tie<>()����ֵ����
//ignore ������ tuple �У������������ tie() ������Ҫ�����Ե�ֵ.
//Ҳ���� tie() ������ʵ�ֶ�������ݳ�Ա���ֵ�Ƚϡ�

//10.3 multimap
//��ʹ��multimap�����Կ϶�����������ظ���Ԫ��; ���򣬾�Ӧ��ʹ�� map
//multimap ���������������ļ�/ֵ�ԣ��ɱ�����ظ���Ԫ�ء�multimap�л���־�����ͬ����Ԫ�����У����ǻᱻ��ӵ�������
//10.3.1 ����Ԫ��
//(1) insert(): ����һ������Ԫ�أ����Ҳ������ǳɹ�������ָ�����Ԫ�صĵ�������
//(2) emplace(): �����������ʵ�λ�ù���Ԫ�ء�
//(3) emplace_hint(): ���������ͬ����Ԫ�أ������ṩ��������ʽ����ʾ��, ������Ԫ�ص�����λ��
//����������������һ��ָ�����Ԫ�صĵ�������emplace_hint()�����ܽ������ײ���ָλ�õ�ǰ�棬����һ����Ԫ�ء���ֻʹ��emplace()������ "Mopsy"�������ܻᱻ���뵽��ǰ���м�Ϊ "rabbit" ��Ԫ�صĺ��档
//10.3.2 ����Ԫ��
//��֧���±����������Ϊ������ȷ��һ��ΨһԪ�ء��� map ���ƣ�multimap Ҳ����ʹ�� at() ������
//find(): ����һ�����Ͳ���ƥ���Ԫ�صĵ�������
//��δ�ҵ���������һ������������������Ӧ�����Ǽ�鷵��ֵ
//(1) equal_range(): ����һ����װ��������������pair������������������Χ��Ԫ�صļ��Ͳ���ֵ��ȡ�
//equal_range() �Ĳ��������Ǻͼ�ͬ���ͣ���ͬ���͵��ɺͼ��ȽϵĶ��󡣷��ص� pair ����ĳ�Ա���� first �ǵ���������ָ���һ��>=������Ԫ�أ�������Ͳ�����ȵ�Ԫ�ش��ڣ������׸����Ͳ�����ͬ��Ԫ�ء����������ڣ�pair�ĳ�Ա����first�������Ľ���������
//(2) lower_bound(): ����һ������������ָ���ֵ�Ͳ���==��>�����ĵ�һ��Ԫ�أ�����ָ�������������
//(3) upper_bound(): ����һ������������ָ���ֵ>�����������׸�Ԫ�أ���������Ԫ�ز����֣������ǽ�����������
//������һ��������ȼ�ʱ����Щ�����᷵��һ����ʼ��һ��������������ָ���˺Ͳ���ƥ���Ԫ�صķ�Χ�����equal_range() ���صĵ���������ͬ�ġ�
//(4)count(): �ж��ٸ�Ԫ�صļ��͸����ļ���ͬ��

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
	//itr = mmss.emplace_hint(itr, "rabbit", "Mopsy");//itrǰ������һ����Ԫ�ء�
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
		auto itr = pets.lower_bound(type);//���������ĵڶ����Լ�����Ԫ�ز��뵽��������е�ǰ��
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






























