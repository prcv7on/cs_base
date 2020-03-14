

#include <iostream>
#include <vector>
#include <string>
//#include <typeinfo>

using namespace std;

//------��̳�籦------

//#include <queue>
//#include <stack>
//ջ�Ͷ��еĹ�����໥ʵ�֡���Сջ
//1.1ʹ������ʵ�̶ֹ����ȵ�ջ

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

//1.2ʹ������ʵ�̶ֹ����ȵĶ���
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
//1.3ֻ�ö���ʵ��һ��ջ
//����������q1��q2��ʵ�����ջ
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

//1.4ֻ��ջʵ��һ������
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

//1.5 ʵ��һ����Сջ����������Сֵ������ջ
//����һ��ջ���洢��Сֵ
//������ջ���еĴ棬��Сջ���Ⱥ�����ջһ�£������ݴ���ͬ�ȳ����µ�ջ����Сֵ��
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



//------�������------

//01 Ϊʲô˵++i��Ч�ʱ�i++�ߣ�
//1.1 ++i��i++������
//a++�Ľ��������ֵ����++b�Ľ������ֵ��
//��ֵ���������󣬿ɸ�ֵ
//��ֵ����ʱ���󣬲��ɱ���ֵ
//
//1.2 ���������
//�����������ͣ�ǰ���������ض�������ã������������ض����ԭֵ��������ֵ����
//class A {
//public:
//	A& operator++();		//ǰ������
//	const A operator++(int);//��������
//private:
//	int curpos;//��ǰλ��
//};
//A& A::operator++() {
//	++curpos;
//	return *this;
//}
////Ϊ����ǰ�����ֿ�������һ��int������������û�ù�
//const A A::operator++(int) {
//	A tmp = *this;
//	++curpos;
//	return tmp;
//}
//
//�����и�ֵ������£���������ǰ�úͺ��������Ļ�඼��һ��
//��ֵ������£����Ҳ������������Ż������ǵĻ����뻹���в���
//

/*
int main() {
	//int a = 0;
	//int b = 0;
	//int c = a++;
	//int d = ++b;
	//cout << "c=" << c << ",d=" << d << endl;
	//int *c = &(a++);//����&Ҫ����ֵ
	//int *d = &(++b);

	system("pause");
	return 0;
}
*/


//2 C++��C�е�const�ؼ����кβ��
//2.1 ������ͨ����--ֻ��
//C���������������ֻ���ģ�Ȼ����Υ�������Ȼ�ܸı䡣
//C++��ʹ��const�ؼ��ֶ����b������ֵ�ڱ��ı�ʱ�ᱻ��⡣
//���ǵ�����Ҳ��һ���ģ�����һ��ֻ����������ϣ�����޸ģ�һ�����޸ģ����������ᱨ��
//
//2.2 �����ڳ�Ա����-���ı��Ա����
//const���γ�Ա��������static�ؼ���ͬ��
//static void printA() const --> ���󣬲��ܼ�const

//class A {
//private:
//	int val;
//public:
//	void printA() const {
//		val = 10;//����ͨ������������ʡ�val��������޷���������޸�
//	}
//};

//2.3 �������Ա����--���캯���г�ʼ��
//�������Ա���������ڹ��캯���г�ʼ��
//class A {
//private:
//	const int a_val;
//public:
//	A(int val) :a_val(val) {}
//};

//2.4 ��������
//
//2.5 �ܽ�
//const�ؼ��֣�������������ǰ���ֲ��ײ�������⡣
//
//3 ӵ������ָ�룬����ڴ�й¶
//3.1 C��C++�е��ڴ�й©
//�����ˣ������ͷ�;
//���ͷ���ȥ���ʣ�
//ĳЩ�����׳��쳣,ʹ��delete�޷�ִ�е��������ڴ�й©��
//JAVA:�������ղ����������ģ�ʱ��Ҳ��ȷ����ͬʱ���ջ��ƱȽϸ��ӣ���ռ�ÿռ��ʱ�俪�����Ͼ�C/C++ע��Ч��
//
//3.2 ����ָ��
//3.2.1 shared_ptr
//��̬������һƬ�ڴ棬�����ڶ���ط��õ�
//���ü���Ϊ0�����Զ��ͷ��ڴ档
//����ʵ��Ҫ���Ǻܶ����أ��������ԭ�ӵ��������ü���������ָ�뿪��Ҫ��
//
//3.2.2 unique_ptr
//ר��ĳ��������Դ.�����ܱ����ƣ������ר��������ʹ�ã��Ϳ��Զ��ͷ��ڴ�
//
//3.2.3 weak_ptr
//
//4 ����д���ʽ�����ͣ�����auto��
//4.1 auto�����ã�������������ȥ�������ʽ�����͡�
//������ǰ����auto����ı����г�ֵ
//
//4.2 auto�÷�
//const�ؼ������ε������Ƶ�
//auto����Զ���const�������ǳ�������int *cosnt p���������ײ�const��ָ��Ķ����ǳ�������const int* p��
//auto�����������������͡����������ֵ����������const��
//
//4.3 ��һ��
//
//4.4 �ܽ�
//ʹ��auto���ע�������Ƶ�����
//ĳЩ���auto�õ������Ϳ��ܲ�������Ҫ��
//һ��Ҫ����ʹ�á�

/*
int main() {
	//const int a = 10;
	//int* pa = &a;//����invalid conversion from ��const int*�� to ��int*��
	//*pa = 20;

	//A a;
	//a.printA();

	//A a(1);

	//const int a = 10;
	////int& ra1 = a;
	//const int& ra2 = a;//����Գ���������

	//const int ci = 10;
	//auto aci = ci;
	//const auto ca = ci;

	//const int arr[] = {11};
	//auto p = arr;

	//cout << "type(ci) =" << typeid(ci).name() << endl;//int��
	//cout << "type(aci)=" << typeid(aci).name() << endl;//int
	//cout << "type(ca) =" << typeid(ca).name() << endl;//int?
	//cout << "type(p)=" << typeid(p).name() << endl;//const int*���ͣ�����˵��int const*����ָ��Ķ�����ֻ����

	//vector<int> vec;
	//auto sz = vec.size();
	//cout << "tyep(sz)=" << typeid(sz).name() << endl;


	system("pause");
	return 0;
}
*/


//5 Ϊ������ѡ��unique_ptr��������ָ�룿
//#include <memory>
//5.1 ����ʹ��
//һ��unique_ptr������ָ��Ķ���һ��unique_ptrֻ��ָ��ͬһ�����󣬵���unique_ptr������ʱ��ָ��Ķ���Ҳ�漴�����١�
//
//���ٶ���ʱ��������delete�����٣�Ҳ����ָ���ķ�ʽ���١�
//unique_ptr<T, D> up(t,d);
//unique_ptr<T, D> up(t);//�յ�unique_ptr
//T unique_ptr����Ķ�������
//D ɾ��������
//t unique_ptr����Ķ���
//d ɾ�������� / function����ȣ������ͷŶ���ָ��
//
//��shared_ptr��ͬ��unique_ptr�ڱ���ʱ��ɾ����������������ʱ������
//
//5.1.1 �ͷ�ָ��Ķ���
//unique_ptr������ʱ�����뿪�����򣩣������Զ��ͷţ�Ҳ��ͨ��������ʽ��ʾ�ͷŶ����磺
//up = nullptr;//��Ϊ�գ��ͷ�upָ��Ķ���
//up.release();//��������Ȩ��������ָ�룬����up��Ϊ��
//up.reset();//�ͷ�upָ��Ķ���
//release��reset����: ǰ���ͷſ���Ȩ��������ָ�룬���ɼ���ʹ�á�����ֱ���ͷ�ָ��Ķ���
//
//5.1.2 unique_ptr��֧����ͨ�Ŀ����͸�ֵ
//��Ȼunique_ptr�Ƕ�������κο��ܱ�����Ĳ������������������ƶ�
//unique_ptr<int> up0;
//unique_ptr<int> up1(new int(10));
//up0 = up1;//���󣬲��ɸ�ֵ
//unique_ptr<int> up2(up1);//���󣬲��ɿ���
//
//5.1.3 �ƶ�unique_ptr�Ķ��� --> ת�ƿ���Ȩ
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
//5.2 �ں����е�ʹ��
//5.2.1 ��Ϊ����
//unique_ptr����ֱ����Ϊ��������Ϊ������������
//������������ָͨ�룬get�����ɻ�ȡ��ָ��
//ʹ��������Ϊ����
//���ⲿ����ʹ�ã�����ת�ƣ������󽻸����õĺ���������ʹ��move����
//5.2.2 ��Ϊ����ֵ
//
//5.3 Ϊʲô����ѡ��unique_ptr
//5.3.1 �����ڴ�й¶: �Զ���������Ҫʱ���ͷ�
//5.3.2 ���������: �����shared_ptr��������С������ָ���൱������ά�����ü�����ԭ�Ӳ�����
//������ܣ�����unique_ptr

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


//6 decltype--�ӱ��ʽ�ƶ�����
//6.1 ����
//�ӱ��ʽ����,�ƶ�Ҫ����ı�������
//����,�������������β����͵ĺ���ģ��
//decltype����Ա��ʽ��ֵ��
//
//6.2 �÷�
//���ʽ�����ǽ����ã��õ��������͡�
//����˫�����ţ����յõ��������͡�
//
//6.3 ����Ӧ�ó���
//���ͱ���У��������������β�������أ��������£�

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
	//cout << "type(f)=" << typeid(f).name() << endl;//int? Ӧ����int&

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



//------����ԳCpp------

//1 ����C++��׼��-��1��
//C++��׼��������C��׼��, C99�������еİ汾.
//C��׼����15��ͷ�ļ�����
//01 cassert	���ԡ�������ʽ������0�򲻴������������쳣�˳�������ʾ�쳣��Ϣ��
//����<cassert>ͷ�ļ�������ǰ����NDEBUG�꣬assert�겻�������á��Ӷ����������ڵ��Գ���ʱ�����쳣�����ڷ�������ʱ�����׵Ĺر�assert�ꡣ
//02 cctype		�жϺ�ת��char�͵ĺ�����
//03 cerrno		errno�Ǵ�����룬������C��׼�⺯����������ʱ��ͨ�����������Ի�ȡ������Ϣ��
//04 cfloat		�ṩ��һ��꣬�������ڸ���������Ϣ��
//05 climits	�ṩ��һ��꣬�������ڸ������͵ļ�ֵ��Ϣ��
//�ڲ�ͬ�Ļ����£����͵ķ�Χ���ܲ�ͬ��ͨ����Щ�꣬������ʵ�ֿ���ֲ�Ĵ��롣
//06 clocale	�������úͲ�ѯ���ػ��������������ڸ�ʽ�����ҷ��š��ַ����ȵȡ���������ʱ����Ĭ�����뱾�ػ����޹ص�C������
//07 cmath		cmath�кܶຯ��������Ը�������Ƶģ����������ذ汾��float��double��long double����
//��Ҫ�ֶ���������ǿ��ת��Ϊ������������֮һ
//08 csetjmp	�����԰������ƹ��������úͷ��ع���Ӧ������ʹ�ø�ͷ�ļ�
//09 csignal	�����źŴ������������źš�
//10 cstdarg	�ṩ��va_list���͡�va_start��va_arg��va_end�����ꡣ��������ʵ�ֿɱ����������
//C++11�����˿ɱ����ģ��(variadic templates)�����cstdargǿ��ܶ�
//11 cstddef	�����˼���������͡�
//ptrdiff_t   size_t   wchar_t   NULL   offsetof
//12 cstdio		�ṩ��C��׼������������ļ���д���Ƶȹ���
//13 cstdlib	�ṩ��һ�鹤�ߺ�����
//14 cstring	�ַ�������������
//15 ctime		��ȡ�Ͳ���ʱ��ĺ�����

//��д����<cstdio>  --> ����C��׼��ĺ�����������std�����ռ���
//��д����<stdio.h> --> C��׼��ĺ�����������ȫ�ֿռ���
//
//2 C++���������⣬����C++��׼��ĺ������ݡ�
//ֻ���ܹؼ����֣�STL��C++��׼I / O����String������ָ�롣
//2.1 STL
//(1) ����: ������ݣ�
//(2) ������: �����������ݣ�
//(3) ������: �����ڴ������ƣ�
//(4) �㷨: �޸ġ�������ɾ��������������ȣ�
//(5) �º���: �Զ����㷨��
//(6) ������: ���������������㷨����չ��
//
//�м������⣺STLΪʲôҪ����ģ�壿���ʵ���㷨�����ݽṹ���룿���ʹ�㷨�߱���չ�ԣ�
//��һ����Ϊ����Ҫ�ܴ洢���ָ��������ݣ��㷨Ҫ֧�ָ������͵ĵ�����������ģ����STLӦ�õĵ��ͳ�������Ŀ�Ƿ�����
//�ڶ����㷨ͨ�������������������ݣ�����������������ʵ�֡����仰˵���㷨ֻ�Ե��������Ҫ�������������������ͣ�����㷨�������Ƕ����ġ�
//�������󲿷��㷨�����Զ����㷨���ԣ��Ӷ�ʵ���㷨�Ŀ���չ�ԣ�����ͨ���㷨���������ܹ���̬��װ�㷨��
//
//2.2 STL����
//������λ�÷֣��ɷ�Ϊ���С�����������
//�����λ�÷֣��ɷ�Ϊ�����ͷ������ڴ�������������ָ���ڴ��������ֲ�
//2.2.1 ��������
//(1) array	�����ڴ����� ��ԭ���������ƣ�Ԫ�ظ����̶���
//��֧�ֶ�̬����ɾ��Ԫ�ء��ṩ��Ԫ�ظġ���ķ�����
//
//(2) vector Ԫ�ظ����ɱ䣬Ԫ�ش洢�ڶ��ϡ�
//vector�Ŀռ䶯̬����.��������ʱ��vector����������һ��������ڴ棬����������Ԫ�أ���ή��Ч�ʡ�
//vector���ṩͷ�庯��������ͷ�����룬��Ҫ������Ԫ������ƶ�
//vector�ṩ��Ԫ������ɾ���ġ���ķ�����
//
//(3) deque	�ֶ����������������п�������
//�ŵ��ǣ�����������ʱ��ֻ��Ҫ�����µ��ڴ棬����Ҫ�ƶ�Ԫ�ء�
//
//(4) forward_list ǰ����������ʱֻ��ǰ�������ܺ��ˡ�
//
//(5) list ˫����������˫���ƶ�����������Ҳ�ṩ����ɾ�Ĳ�ķ�����
//
//2.2.2 ��������
//(1) �����������: set/multiset��map/multimap
//Ԫ�ذ���С˳�����С�����keyֵ��������
//multi��ָkeyֵ�����ظ������⣬set��multiset��map��multimapû������
//set�洢ֻ��keyֵ��Ԫ�ء�
//map�洢��key ��value���ɵ�Ԫ�أ�����Ԫ�ذ�keyֵ�Զ�����
//set��map�ĵײ���RB - tree�������������һ�ָ߶�ƽ��Ķ�������ʹ���ҡ����롢ɾ���ĸ��Ӷȶ���log N
//
//(2) ������������У�unordered_set / unordered_multiset��unordered_map / unordered_multimap��
//unordered_set��unordered_map: ��ϣ������Ԫ�ز�����С���У���keyֵ��hashֵ�ŷš���ϣ�����Ĳ������Ӷ���O(1)
//ԭ����: ��ͬhashֵ��Ԫ�ط��ڲ�ͬ�������У�����Ԫ��keyֵ��hashֵ���ܿ��ȡԪ�����ڵ�����
//
//3 STL��������iterators��
//��������һ�ֳ������Ƹ��������ģʽ�Ķ��壺�ṩһ�ַ�����ʹ��������η���ĳ���ۺ��������������Ԫ�أ����Ҳ���Ҫ�˽�ۺ����ʵ�ַ�ʽ��
//STL����˼�룺���������㷨�ֿ����˴˶��������ͨ�������������Ǵ��������������������STL�е�����
//Ū��STL��������ʵ��ԭ�������ڸ�����ⷺ�ͱ�̡�
//���������ܷ�������Ϊ��ͬ�������ڴ沼�ֲ�һ�������ʷ������ڲ��졣��ͬ���͵���������������ͬ������������Ҫ�Լ��ĵ�����
//
//3.1 ������ʵ��
//��������һ������ָ��Ķ������ڷ���������Ա����˾߱������ã�dereference���ͳ�Ա����(member access)���ܡ���ˣ�����������ʵ��operator*��operator->��������
//ʵ��һ���򵥵�List���������������
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
////list�ڵ�ʵ��
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
////List�ĵ�����ʵ��
//template<typename T>
//class ListIter {
//public:
//	ListIter(T* p);
//	T& operator*() { return *pNode; }
//	T* operator->() { return pNode; }
//	ListIter& operator++() { pNode = pNode->next(); return *this; }
//private:
//	T* pNode;//ָ��list�ڵ�
//};

//3.2 �������ͱ�
//3.2.1 ��ȡ����������ģ���Ƶ�������ȡ���͵ĸ�����Ϣ��
//template<typename T>
//class trait {
//	// ��ȡ�����ͱ�
//	typedef typename T::value_type value_type;
//};
//
//template<typename T>
//class Iterator
//{
//public��
//	typedef T value_type;//ͨ����Ƕ���ͱ��Ԫ������
//};
//
////���ص�������ָ�Ķ�������
//template<typename Iter>
//tarit<Iter>::value_type func() {}

//�����Ϳɻ�ȡ��������ָ�ķ���ֵ���ͣ��������ȡ���ơ�Ҫ��֤��ȡ������Ч���У�ÿ�ֵ�����Ҫ���չ涨�ṩ��Ƕ���͡�
//
//3.2.2 STL�涨�������������ṩ5����Ӧ�ͱ�
//(1) ��ָ�ͱ�(value type):				��������ָ�Ķ��������
//(2) �����������ͱ�(difference type):	����������֮��ľ��������
//(3) �����ͱ�(reference type):			��������ָ�Ķ����ܷ��޸�,��Ϊ�����ͷǳ���������
//(4) ָ���ͱ�(pointer type):			��������ָ�Ķ����ָ������
//(5) ����������(iterator_category): 
//1) ֻ������������ָ�����ܱ�����޸ģ�ֻ����֧��operator++��
//2) ֻд��������ֻд��֧��operator++��
//3) ǰ����������ɶ���д��ֻ��ǰ���ƶ���֧��operator++��
//4) ˫����������ɶ���д����˫���ƶ���֧��operator--��
//5) ������������ɶ���д��������ƶ���֧���������㣬iter + n��iter1<iter2�ȡ�
//�������ڴ沼�֣���ͬ�����ṩ�ĵ������ͱ�ͬ��vector��deque�ṩ�����������list�͹��������ṩ˫���������forward_list�ṩǰ���������
//
//����ô���ͱ�����㷨Ч�ʣ�STL׷���µ�Ч�ʡ�
//��advancedΪ������������������������iter������n����iterǰ��n�����롣��ͬ���͵ĵ�������������ʵ�ַ�ʽ��α�������£�

////ֻ���������汾
//void advance_II(InputIterator& p, Dist n) {
//	while (n-- > 0) ++p;
//}
//
////˫��������汾
//void advance_BI(BidirectionalIterator& p, Dist n) {
//	if (n >= 0)
//		while (n--) ++p;
//	else
//		while (n++) �Cp;
//}
//
////����������汾
//void advance_RI(RandomIterator& p, Dist n) {
//	p += n;
//}

//ͨ���������أ��ڱ����ھͿ�ѡ�����ŵĺ�����

////ֻ���������������ذ汾
//void _advance(InputIterator& p, Dist n, input_iterator) {
//	advance_II(p, n);
//}
//
////˫��������������ذ汾
//void _advance(BidirectionalIterator& p, Dist n, bidirectional_iterator) {
//	advance_BI(p, n);
//}
//
////����������������ذ汾
//void _advance(RandomIterator& p, Dist n, random_iterator) {
//	advance_RI(p, n);
//}
//
////�ṩ���û��Ľӿ�
//void advanced(Iterator& p, Dist n) {
//	//ͨ����ȡ���ƻ�ȡ�������ͱ𣬴Ӷ�ʵ�����ؾ���
//	_advance(p, n, iterator_trait<Iterator>::iterator_category());
//}

//��ƺ��ʵĵ������������������Σ�ֻ������������߲�֪����α����Լ����������Ӧ�߱������ͱ�
//�㷨��ȫ�����������͵�����֮��: ���͵�����ӿڱ�̡�
//
//3.2.3 ������ʧЧ
//vector������ʧЧ�������ɾ��Ԫ�أ������ɾ��λ��֮������е�������ʧЧ������Ԫ�ص���vector�������·��䣬���е�������ʧЧ��
//deque������ʧЧ����β���벻�����κε�����ʧЧ����βɾ��Ԫ��ֻ�ᵼ�±�ɾ��Ԫ�صĵ�����ʧЧ������λ�õĲ����ɾ����ʹ���е�����ʧЧ��
//list��set��map������ʧЧ�����벻�ᵼ���κε�����ʧЧ��ɾ��ֻ�ᵼ�±�ɾ��Ԫ�صĵ�����ʧЧ��
//
//4 STL�㷨
//4.1 �ʱ��㷨: ���޸�����Ԫ�����ݡ�
//�������������滻����䣬ɾ����������ϣ��ָ������ţ�������ת
//
//4.2 ���ʱ��㷨
//���ң��������������Ƚϣ����Ҽ�ֵ
//
//STL�㷨ǰ�����β�ͨ����first��end����ʾ�㷨�Ĳ�������[first, end)��
//���ʱ���ȿ���STL�㷨���������Լ�ʵ�֡�
//�������ⲻ�ǲ���ʹ���㷨�����Ǹ�����֪���㷨�Ĵ��ڡ�
//
//5 �ռ������
//�����Ĵ�С�ɱ䣬��Ҫ�ռ��������Ϊ��Ԫ�ض�̬����ռ�
//STL�ṩĬ�ϵĿռ�����������ܣ���̬�����ڴ棬���ù��캯�������������������ͷ��ڴ档
//������Ҫ����Ŀռ������������Ƶ��������ͷ��ڴ棬��ʹ�û����ڴ�صĿռ��������������ڴ������и������
//
//6 �º���
//������������ȴ�Ǹ��ࡣ��Ϊ�º�����������"()"��������
//
//6.1 ���еķº���������������ʽ:
//class Functor {
//public:
//	void operator(int a) {
//		//����()�����
//	}
//};
////ʹ�÷º���
//Functor func;
//func(1);
//
//6.2 �º�����STL������򵥡�������ʵ�ֵ������������STL�㷨����
//�ܶ�STL�㷨֧���Զ�����ԣ����������¸�ʽ��
//algorithm(first, last, functor) {
//	functor(��);
//}
//
//7 ������
//��������һ�����ģʽ���ܸı�ԭclass�Ľӿڣ�ʹ��ӿڲ��ܼ��ݵ�class�ܹ�Эͬ������
//7.1 ����������������: queue��stack�����ʶ���deque������
//7.2 ������������: ����������,ʹ��ֵ��Ϊ�������; ����������,ʹ�������н�������ת; ��������,��I/O����ȡ��д�����
//7.3 �º���������: ��ϸ��ַº�����ͨ���󶨡���ϣ�������ֿ��ܵı��ʽ

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



//------CPP������------

//1 C++ �������������ָ��
//1.1 ��������: ���������Ԫ���Ƕ��� �����������ݳ�Ա�����һ��к�����Ա
//���� ������[�±���ʽ];
//1.2 ʹ�ö�������ʱҲֻ�ܷ��ʵ�������Ԫ��, Ҳ����һ������, ͨ���������, Ҳ���Է��ʵ����Ĺ��г�Ա
//������[�±�].��Ա��
//1.3 �轨��ĳ��Ķ������飬��ƹ��캯��ʱ,Ҫ��ֿ���Ԫ�س�ʼ������Ҫ��
//(1) ��Ԫ�س�ֵҪ����ͬ�������ж��岻���������ȱʡ����ֵ�Ĺ��캯����
//(2) ��Ԫ�س�ֵҪ��ֵͬ,������β�(��ȱʡֵ)�Ĺ��캯����
//(3) �����������ʱ����ͨ����ʼ������и�ֵ��
//
//2 ����ָ��
//�����ʼ���󶼻����ڴ���ռ��һ���Ŀռ䡣��ͨ��������������ַ,����һ������
//����ָ���Ŷ����ַ�ı�������������ָ�룺����* ����ָ����;
//2.1 ��ָ����ʵ��������Ա
//
//2.2 �ö���ָ����ʶ�������
//��ĳ�Ա����Ҳ��һЩ���������������ȡ�
//ָ���Ա��ָ��,ֻ�ܷ��ʹ������ݳ�Ա�ͳ�Ա������
//ʹ��Ҫ���������ٸ�ֵ��Ȼ����ʡ�
//
//2.2.1 ָ�����ݳ�Ա��ָ��
//������ ����˵���� ����:: *���ݳ�Աָ����
//��ֵ�� ���ݳ�Աָ������&����::���ݳ�Ա��
//ʹ��
//������. *���ݳ�Աָ����
//����ָ����->*���ݳ�Աָ����
//
//2.2.2 ָ���Ա������ָ��
//������ ����˵����(������ *ָ����)(������);
//��ֵ�� ��Ա����ָ���� = �����˳�Ա������;
//ʹ��
//(������.*��Ա����ָ����)(������);
//(����ָ���� -> *��Ա����ָ����) (������);

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

//2 C++ const ��ʹ��
//2.1
//2.1.1 const �����һ����ʽ
//(1)������ const ������[(����ʵ�α���)];
//(2)const ������ ������[(����ʵ�α���)];
//���������Ҫ�г�ֵ����Ϊ�Ժ��ܸ�ֵ�ˣ���
//2.1.2 �޶�����
//����Ϊconst�Ķ�����������ݳ�Ա��ֵ�����ܱ��޸ġ�
//���÷�const��Ա������������󡣵����캯�����⡣
//2.1.3 mutable��Ա
//�����ݳ�Ա����Ϊmutable���ױ�ģ�ʱ����ʹ��const������Ȼ�����޸ĸ����ݳ�Աֵ��

//2.2 �������Ա
//2.2.1 �����ݳ�Ա
//���������˳����ݳ�Ա, ���캯��ֻ��ͨ����ʼ���б��ʼ�������ݳ�Ա, �����������ܶԸó�Ա��ֵ��
//2.2.2 ����Ա���� --> �������ùؼ���const˵���ĺ���
//����˵���� ������(������) const;
//���һ����������Ϊ�����󣬸ö���ֻ�ܵ��ó���Ա���������ܵ�����ͨ��Ա���������ҳ���Ա����Ҳ���ܸ��¶�������ݳ�Ա��
//����Ա����ֻ�����ñ�������ݳ�Ա�������޸����ǡ���ע�⣺�ɸ�mutable��Ա��
//
//2.2.3 ����Ա��ʹ��
//a) ����һ�����У���Щ���ݳ�Ա��ֵ����ı䣬��һЩ���ݳ�Ա��ֵ������ı䣬��ɽ��������ݳ�Ա����Ϊconst���Ա�֤��ֵ�����ı䣬���÷�const�ĳ�Ա����������Щ���ݳ�Ա��ֵ�����޸ķ�const���ݳ�Ա��ֵ��
//b) ��Ҫ���������ݳ�Ա��ֵ��������ı䣬��ɽ����е����ݳ�Ա����Ϊconst���򽫶�������Ϊconst(������)��Ȼ����const��Ա�����������ݳ�Ա���𵽡�˫���ա������ã���ʵ��֤���ݳ�Ա�����޸ġ�
//c) ���Ѷ�����һ����������ֻ�ܵ���const��Ա���������ܵ��÷�const��Ա����(������Щ�����Ƿ���޸Ķ����е�����)������Ҫ���ʶ����е����ݳ�Ա���ɽ������������г�Ա����������Ϊconst��Ա��������Ӧȷ���ں����в��޸Ķ����е����ݳ�Ա��
//
//2.4 ָ�򳣶����ָ�����
//2.4.1 ָ�򳣶����ָ�������һ����ʽ
//const ���� *ָ�������
//
//2.4.2 ����ָ�򳣶����ָ�������˵��
//(1)ָ�򳣶��󣨱�������ָ�����������ͨ�������ı���ָ��Ŀ������ֵ����ָ�������ֵ�ɱ�
//(2)���������Ϊ�����󣨱�������ֻ����ָ�򳣶��󣨱�������ָ�����ָ����
//(3)ָ�򳣶��󣨱�������ָ����˿���ָ�򳣶��󣨱������⣬������ָ��δ������Ϊconst�Ķ��󣨱���������ʱ����ͨ����ָ������ı�ñ�����ֵ��
//(4)ָ�򳣶��󣨱�������ָ���ָ��const�ͷ�const�͵Ķ��󣨱���������ָ���const������ָ��ֻ��ָ���const�Ķ��󣨱�������
//(5)�������β�ָ���const������ָ�룬ʵ��ֻ����ָ���const������ָ�룬��������ָ��const������ָ�룬�������ɸı��β�ָ����ָ����(Ҳ����ʵ��ָ����ָ��ı���)��ֵ��
//(6)�����β�ָ��const������ָ�룬����ʵ����const���constָ�롣
//(7)��������ϣ����������ʱ�����ֵ�����޸ģ��βζ���Ϊָ�򳣶����ָ�룬ͬʱ�ö���ĵ�ַ��ʵ��(���������const���const��)��
//Ҫ��ö��󲻽��ڵ��ú��������в����ı䣬����Ҫ�����ڳ���ִ�й����ж����ı�,��Ӧ��������Ϊ const��
//
//2.5 ����ĳ�����
//��ָ��ͳ������������������ܱ�֤���ݰ�ȫ��ʹ���ݲ��ܱ������޸ģ��ڵ��ú���ʱ���ؿ���ʵ�Σ���߳���Ч��
//
//2.6 const�����ݵ�С��
//class Time {
//public:
//	Time(int h,int m,int s) :hour(h),minute(m),sec(s) {}// ͨ��������ʼ����Գ����ݳ�Աhour��ʼ��
//	//Time(int h) { hour = h; }//����
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
//void fun1(Time &t){ // t �Ƕ�������
//	t.hour = 18;
//}
//void fun2(const Time &t){ // t Ϊ������
//	t.hour = 18; // ���� 
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
	//const int* pa = &a;//��ȷ
	//int* pb = &b;//���󣺷� const ��ָ��

	//pa = &b;//Ҳ��ָ��� const �͵ı���
	//*pa = 30;//ָ��const�͵�ָ�벻�ܸ�Ŀ��ֵ

	//void f(Time* pt);
	//Time* p1;
	//const Time* p2;
	//f(p1);//��ȷ
	////f(p2);//����

	//void g(const Time* pt);
	//Time* p1;
	//const Time* p2;
	//g(p1);//��ȷ
	//g(p2);//��ȷ

	//Time t1(10, 13, 56);
	//fun1(t1);
	//cout << t1.hour << endl;

	Sample a(10, 20); //��Ϊ:const Sample a(10,20);
	a.setvalue(40);//�����޸ĳ���������ݳ�Ա
	a.m = 30; //�����޸ĳ���������ݳ�Ա
	a.disply();//�������ܵ�����ͨ��Ա����

	system("pause");
	return 0;
}
*/


//3 C++ vector ʹ��ע������
//#include <algorithm>
//3.1 ��ʼ��
//c++ 11����������{}��ʼ����ʽ��ע����()������

//3.2 push_back
//ͨ��push_back����µ�Ԫ�ؽ���vector��vector���ڴ���ʱ��ᷢ���仯����ȡ����size��capacity��С
//3.2.1 ����stl�����������г�Ա��
//begin()  //��ʼλ�� 
//end() //����λ�� 
//size() //��ǰ��С 
//capacity() //��ǰ����������������ڴ��С
//3.2.2 
//vector�����ڴ棬��������ʶ�ڴ��λ�ã�start��end��finish�� size = end - start�� capacity = finish - start

//3.3 erase,remove
//����vector, removeʹ����������ƶ���ɾ������δɾ����Ԫ�ط���ǰ�棬������ָ����λ�õĵ�����


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
	//remove(v1.begin(),v1.end(),3);//��δɾ��Ԫ��ǰ��
	v1.erase(remove(v1.begin(),v1.end(),3),v1.end());//������ɾ��
	cout << "v1.size()= " << v1.size() << endl;
	cout << "v1.capacity()= " << v1.capacity() << endl;
	printvec(v1);

	system("pause");
	return 0;
}
*/


//4 �� C++ std::shared_ptr ԭ��������ջ�����Σ��
//4.1 shared_ptrʵ�ְ����������֣�
//ָ����ϴ����Ķ������ָ�룬raw_ptr
//ָ���ڲ����صġ�����Ĺ������share_count_object
//4.2 
//use_count����ǰ������϶��󱻶��ٶ��������ˣ����ü�����			  ���"���������"����������
//weak_count�����������󱻶��ٸ�����ָ�빲���ˣ������������ü��������"  �������"����������

//5 C++ 11 ���ԣ�auto �ؼ���

//5.1 �ڶ���ģ�庯��ʱ��������������ģ������ı������͡�
//template <typename _Tx, typename _Ty>
//void Multiply(_Tx x, _Ty y){
//	auto v = x*y;
//	std::cout << v;
//}

//5.2 ģ�庯��������ģ������ķ���ֵ
//auto����:����ֵռλ��ֻ��Ϊ��������ֵռ��һ��λ�ã������ķ���ֵ��decltype(_Tx*_Ty)��
//template <typename _Tx, typename _Ty>
//auto multiply(_Tx x, _Ty y)->decltype(_Tx*_Ty){
//	return x*y;
//}

//5.3 ע������
//(1) auto ���������ڶ���ʱ��ʼ������������const�ؼ��֡�
//(2) ��ʼ�����ʽ�����ã���ȥ���������塣
//(3) ��ʼ�����ʽΪconst��volatile������У������ȥconst / volatile���塣
//(4) auto�ؼ��ִ���&����ȥ��const���⡣
//(5) ��ʼ�����ʽΪ���飬auto�Ƶ�����Ϊָ�롣
//(6) ���ʽΪ������auto����&���Ƶ�����Ϊ���顣
//(7) ������ģ��������ܱ�����Ϊauto
//(8) auto����һ��ռλ��������һ������������

/*
int main() {
	//int a = 10;
	//int &b = a;
	//auto c = b;//c������Ϊint����int&��ȥ�����ã�
	//auto &d = b;//��ʱc�����Ͳ�Ϊint&

	//const int a1 = 10;
	//auto  b1 = a1; //b1������Ϊint����const int��ȥ��const��
	//const auto c1 = a1;//��ʱc1������Ϊconst int
	//b1 = 100;//�Ϸ�
	////c1 = 100;//�Ƿ�

	//const int a2 = 10;
	//auto &b2 = a2;//��Ϊauto����&���ʲ�ȥ��const��b2����Ϊconst int
	//b2 = 10; //�Ƿ�
	//cout << "type(b2)=" << typeid(b2).name() << endl;//int ? Ӧ����const int

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


//6 Ӧ���˽��һЩ C++ ����

//6.1 auto ���� --> �ñ������ڱ���ʱ�Զ��ƶ���������
//��ʹ�� auto ʱ������ȷ����������ͨ��ĳ�ַ�ʽ�ƶ��������͡�

//6.2 lambda ���ʽ
//û�������ĺ������󣬿��ڲ�ͬ�����򲶻�����������Է����������
//������[]��Ϊlambda ���ʽ�Ŀ�ʼ�����庯�������򣬼����Ծֲ������Ͷ����ж���Ȩ�ޡ�
//(1)�ۣݴ���ա������� lambda ���ʽ��ʹ���ⲿ������ľֲ�������ֻ��ʹ�ò�����
//(2)�ۣ���ͨ��ֵ��ȡ�������ڵľֲ����󣨾ֲ������Ͳ�������ֻ��ʹ�ò����޸ġ�
//(3)��&��ͨ�����û�ȡ�������ڵľֲ����󣨾ֲ������Ͳ��������������������������һ���޸�����
//(4)��this�ݿ�ͨ��ֵ��ȡ this ָ�롣
//(5)��a, &b��ͨ��ֵ��ȡ���� a, ͨ�����û�ȡ���� b��
//����ʵ��һЩС���ܵ�������Ϊ�˵�����д��������ʱ��lambda �ǳ����á���һ�ַǳ��ձ��Ӧ���ǽ�����Ϊ�ȽϺ�����

//6.3 ����ʱִ�� constexpr
//��һЩ���ʽҪ���㣬����ֵһ����ʼ���Ͳ��䡣��Ԥ�ȼ����ֵ����Ϊ����ʹ�á����߿�ʹ�� constexpr��
//(1) ����Ϊ constexpr �ĺ����ǳ���Ҫ��һ�㣬���������� constexpr �� const�����򣬸ú���������ͨ����һ��ִ�У��������ڱ���ʱԤ�ȼ��㡣
//(2) ����Ҳͬ�������� constexpr��
//(3)  c++17�У������� constexpr-if �� constexpr-lambda

//6.4 tuple
//tuple ��һ������������͵Ĺ̶���С�ļ���

//6.5 ��ģ������ƶ�
//c++17 ��ʼ�������ƶ�Ҳ�����ڱ�׼��ģ�档��ǰ��������ֻ֧�ֺ���ģ�档

//6.6 ����ָ��


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
	//for_each(vi.begin(), vi.end(), [&m](int& val) {  //int& val --> �����ı� vector
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


//7 C++ ���Ĭ�Ϻ���
//7.1 ��C++�У�һ�����а˸�Ĭ�Ϻ�����
//(1) Ĭ�Ϲ��캯����
//(2) Ĭ�Ͽ������캯����
//(3) Ĭ������������
//(4) Ĭ�����ظ�ֵ�����������
//(5) Ĭ������ȡַ�����������
//(6) Ĭ������ȡַ�����const������
//(7) Ĭ���ƶ����캯����C++11����
//(8) Ĭ�������ƶ���ֵ������������C++11����

//ֻ����һ�����࣬�����κ����飬�������Զ�����1��2��4��3����Щ����ֻ�ڵ�һ�α�����ʱ���Żᱻ������������
//��ЩĬ�Ϻ�����ʵ�־���ʲô����������Щ��������inline��public

//7.2 C++11������ʶ��default��delete,������ЩĬ�Ϻ����Ƿ�ʹ�á�
//(1) default��ʹ�����Ĭ����Ϊ���磺A() = default;
//(2) delete�����ã��磺A() = delete;
//(3) override��ǿ����д�����麯����
//(4) final����ֹ��д�����麯����

//class A {
//public:
//	A();
//	A(const A&);//Ĭ�Ͽ������캯��
//	~A();
//	A& operator=(const A&); //Ĭ�����ظ�ֵ���������
//	A* operator&();				//Ĭ������ȡַ���������
//	const A* operator& () const;//Ĭ������ȡַ�����const����
//	A(A&&);					//Ĭ���ƶ����캯��
//	A& operator=(const A&&);//Ĭ�������ƶ���ֵ������
//	
//};













// ------C������C++���------

//1 C/C++ָ�롢���úͳ���
//1.1 ����ָ���ָ�볣��
//����ָ��: ָ������ָ��
//ָ�볣��: ����
//ָ������ָ�볣��

//1.2 ���úͳ�������
//���������õĳ�ʼֵ�Ǳ�������ͨ�������޸ĳ�����
//			����ʼֵ��const,�����޸�

//ʹ�����ó������ݲ��� --> upper(char* const &a);
//��������ú����޸ı���, ʹ�ó������ã���Ϊ��ֵ���ں����ڴ�������������Ч�ʡ�

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






















































