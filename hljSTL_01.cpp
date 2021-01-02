

#include <iostream>
#include <string>
#include <vector>
// #include <deque>
// #include <list>
// #include <set>
// #include <map>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <functional>
// #include <utility>
// #include <cctype>

using namespace std;


//02 泛型程序设计
//2.1 程序设计范型及其演化
//2.1.1 过程式程序设计
//确定需要哪些过程，采用能够找到的最好方法
//重点: 流程
//
//2.1.2 模块程序设计
//确定需要哪些模块。将程序分为一些模块，使数据隐藏于模块中。
//重点: 对数据的组织
//重要的概念: 数据隐藏
//2.1.3 基于对象程序设计
//确定需要哪些类型，为每个类型提供完整的一组操作。
//重点: 抽象数据类型
//重要的概念: 封装，数据抽象
//2.1.4 面向对象程序设计
//确定需要哪些类，为每个类提供完整的一组操作。利用继承去明确表示共性。
//重要的概念: 多态，继承。
//2.1.5 范型/通用程序设计
//确定需要哪些算法。将它们参数化，使它们能够对各种适当的类型和数据工作。
//重点: 类型参数化。
//重要的概念: 容器类 --- 一个能保存某种类型元素集合的类。
//要点: 编写不依赖于具体数据类型的程序。
//将算法从特定的数据结构在抽象出来，成为通用的。
//
//2.2 C++中的泛型程序设计
//2.2.1 C++的模板为泛型程序设计奠定了关键的基础
//2.2.2
//(1) 概念concept: 用来界定具备一定功能的数据类型
//如“支持‘<’运算符”的数据类型构成Comparable这一概念
//(2) 模型model: 符合一个概念的数据类型称为该概念的模型
//如int型是Comparable概念的模型
//2.2.3 为概念赋予一个名称，并使用该名称作为模板参数名
//2.2.4 应用
//很多STL的实现代码就是使用概念来命名模板参数的



//03 STL结构概览
//3.1 STL主要组件
//(1)容器 container
//(2)算法 algorithm
//(3)迭代器 iterator
//(4)函数对象 function object
//
//3.2 容器
//定义: 容纳、包含一组元素的对象，支持了在软件设计中常用的线性群体.
//顺序容器: 一组具有相同类型的元素，以严格的线性形式组织 --> 向量vector、双端队列deque、表list（含队列queue、堆栈stack
//关联容器: 可根据索引快速提取的数据集合 --> 集合set、多重集合multiset、映射map、多重集合multimap
//
//3.3 迭代器
//定义: 提供顺序访问容器中每个元素的方法，含类似指针的用法
//s.begin(): 容器s的第一个元素
//s.end(): 容器s的末尾（最后一个元素之后的位置）
//ostream_iterator<int>(cout, " "): 构造出来的输出迭代器对象，通过cout输出int型数据，中间用空格(" ")隔开
//
//3.4 函数对象
//定义: 是1个行为类似函数的对象，可像调用函数一样调用，是一种泛化后的函数
//体会自定义函数对象
//
//3.5 算法
//定义: STL提供了大量具有统一性的算法，可广泛用于不同的对象和内置的数据类型
//
//3.6 STL结构概览小结
//(1)STL把迭代器作为算法的参数，通过迭代器来访问容器，而不是把容器直接作为算法的参数
//(2)STL把函数对象作为算法的参数，而不是把函数所执行的运算作为算法的一部分。
//                 function object     
//                      ^
//                      |
// container  -->  algorithm  --> container



//04 迭代器
//4.1 迭代器及其分类
//4.1.1 定义
//(1)迭代器是算法和容器的中间人
//(2)迭代器遍历容器中的元素序列，提供访问容器中各元素的方法。
//(3)指针是迭代器的一种。
//(4)迭代器是泛化的指针，提供了类似指针的操作(++, *, ->)
//(5)迭代器不仅仅是指针
//迭代器更为抽象。可指向容器中的一个位置，通过迭代器访问这个位置的元素， 而不必关心此位置对应的真正的物理地址。
//4.1.2 迭代器类型
//输入迭代器 Input Iterator
//输出迭代器 Output Iterator
//前向迭代器 Forward Iterator: 既是输入又是输出迭代器，可对序列单向的遍历
//双向迭代器 Bidirectional Iterator: 与前向迭代器相似，在两个方向上都可对数据遍历
//随机访问迭代器 Random Access Iterator: 也是双向迭代器，但能够在序列中任意两个位置间进行跳转
//
//4.2 迭代器的操作
//(1)输入迭代器: p1 == p2; p1 != p2; *p1; p1->m; *p1++;
//(2)输出迭代器: *p1=t; *p1++=t; p1++的返回值不确定
//(3)前向迭代器更加明确: *p1; p1++
//(4)双向迭代器新增: --p1; p1--;
//(5)随机访问迭代器新增: p1 += n; p1 -= n; p1+n / n+p1 / p1-n; p1-p2; p1比较运算符p2; p1[n];
//(6)两个迭代器表示一个区间: [p1, p2) 包含p1，但不包含p2
//STL算法常以迭代器的区间作为输入，传递输入数据
//
//4.3 输入流迭代器和输出流迭代器
//4.3.1 输入流、输出流
//标准类: istream, ostream
//实例: cin, cout
//4.3.2 输入流迭代器
//template<class T> istream_iterator<T>
//要求: T类型重载了运算符 >>
//以输入流为参数构造:
// istream_iterator<int>(cin);
// istream_iterator<int>();//指向输入流结束位置
//4.3.3 输出流迭代器
//template<class T> ostream_iterator<T>
//要求: T类型重载了运算符 >>
//以输出流为参数构造:
// ostream_iterator<int>(cout);
// ostream_iterator<int>(cout, 分隔符);//指向输入流结束位置
//
//4.4 迭代器的辅助函数
//(1)对pos执行n次自增操作: void advance(Iterator pos, int n)
//(2)计算两个迭代器first和last的距离: int distance(Iterator first, Iterator last)

/*
// double Square(double x) {
//     return x*x;
// }
//
template<class T, class InputIterator, class OutputIterator>
void mySort(InputIterator first, InputIterator last, OutputIterator result) {
    vector<T> s;
    for (; first != last; ++first) {
        s.push_back(*first);
    }
    sort(s.begin(), s.end());
    copy(s.begin(), s.end(), result);
}

int main(void) {
    // transform(istream_iterator<double>(cin), istream_iterator<double>(), ostream_iterator<double>(cout," "), Square);
    // cout<<endl;
    //
    // double a[5] = {1.2, 2.4, 0.8, 3.3, 3.2 };
    // mySort<double>(a, a+5, ostream_iterator<double>(cout, " "));
    // cout<<endl;
    // cout<<"Input data: ";
    // mySort<int>(istream_iterator<int>(cin), istream_iterator<int>(), ostream_iterator<double>(cout, " "));
    // cout<<endl;
    //

    return 0;
}
*/



//05 容器的分类与基本功能
//5.1 容器的分类
//5.1.1 容器类是容纳、包含一组元素或元素集合的对象
//5.1.2 七种基本容器
//(1)向量 vector
//(2)双端队列 deque
//(3)列表 list
//(4)集合 set
//(5)多重集合 multiset
//(6)映射 map
//(7)多重映射 multimap
//5.1.3 按容器中元素的组织方式
//顺序容器
//关联容器
//5.1.4 按与容器相关的迭代器类型
//可逆容器
//随机访问容器
//          Container
//  Sequence            Associative Container
//  list                    set/multiset; map/multimap
//  vector/deque
//
//5.2 容器的通用功能
//5.2.1 通用功能
//(1) 用默认构造函数构造空容器
//(2) 支持关系运算符：==、!=、<、<=、>、>=
//(3) begin(), end() : 获得容器首、尾迭代器
//(4) clear() : 将容器清空
//(5) empty() : 判断容器是否为空
//(6) size() : 得到容器元素个数
//(7) s1.swap(s2) : 将s1和s2两容器内容交换
//5.2.2 随机访问容器
//s[n] : 获得容器s的第n个元素
//5.2.3 相关迭代器类型
//(1) S::iterator：指向容器元素的迭代器类型
//(2) S::const_iterator：常迭代器类型
//
//5.3 可逆(双向)容器的功能
// S::reverse_iterator：逆向迭代器类型
// S::const_reverse_iterator：逆向常迭代器类型
// rbegin() ：指向容器尾的逆向迭代器
// rend()：指向容器首的逆向迭代器



//06 顺序容器(vector/deque/list)
//6.1 顺序容器的基本功能
//(1)构造 S s(n,t); S s(n); S s(q1,q2);
//(2)赋值 s.assign(n,t); s.assign(n); s.assign(q1,q2);
//(3)插入 s.insert(p1,t); s.insert(p1,n,t); s.insert(p1,q1,q2);
//s.push_front(t); s.push_front();//对list和deque
//s.push_back(t); s.push_back();
//(4)删除 s.erase(p1); s.erase(); s.clear();
//s.pop_front(); s.pop_back(); //对list和deque
//(5)首尾元素直接访问 s.front(); s.back();
//(6)改变大小 s.resize();
//
//6.2 Vector
//6.2.1 特点
//(1) 一个可以扩展的动态数组
//(2) 随机访问
//(3) 在尾部插入/删除元素快, 在中间/头部插入或删除元素慢
//6.2.2 向量的容量
//(1)容量capacity: 实际分配空间的大小
//(2)s.capacity(): 返回当前容量
//(3)s.reserve(n): 若容量小于n，则对s进行扩展，使其容量至少为n
//
//6.3 deque
//6.3.1 特点
//(1) 在两端插入/删除元素快
//(2) 在中间插入/删除元素慢
//(3) 随机访问较快，但比向量容器慢
//6.3.2 存储结构
//数组
//分段数组
//6.3.3 例题: 奇偶排序
//
//6.4 list
//6.4.1 特点
//(1) 在任意位置插入和删除元素都很快
//(2) 不支持随机访问
//6.4.2 splice
//s1.splice(p, s2, q1, q2): 把s2中[p1,p2)移动到s1中p1所指元素之前
//
//6.5 三种顺序容器的比较与选用
//(1)需要大量随机访问，当扩展容器时只需向容器尾部加入新元素 --> vector
//(2)需要少量随机访问，在容器两端插入、删除元素 --> deque
//(3)无需随机访问，需要在中间插入、删除元素 --> list
//
//6.6 顺序容器的插入迭代器
//(1)向容器头部、尾部或中间指定位置插入元素的迭代器
//(2)前插迭代器（front_inserter）、后插迭代器（back_insrter）和任意位置插入迭代器（inserter）

/*
template<typename T>
void PrintContainer(const char* msg, const T& s) {
    cout<<msg<<" : ";
    copy(s.begin(), s.end(), ostream_iterator<int>(cout, " "));
    cout<<endl;
}

int main(void) {
    // const int N=5;
    // vector<int> s;
    // s.reserve(5);
    // cout<<"capacity = "<<s.capacity()<<", size = "<<s.size()<<endl;
    // for (int i=0; i<N; ++i) {
    //     s.push_back(i);
    // }
    // s.insert(s.begin()+3, 9);
    // copy(s.begin(), s.end(), ostream_iterator<int>(cout, " ")); cout<<endl; //0 1 2 9 3 4
    // s.pop_back();
    // copy(s.begin(), s.end(), ostream_iterator<int>(cout, " ")); cout<<endl; //0 1 2 9 3
    
    // istream_iterator<int>it1(cin), it2;
    // vector<int> s1(it1, it2);
    // sort(s1.begin(), s1.end());
    // copy(s1.begin(), s1.end(), ostream_iterator<int>(cout, " ")); cout<<endl;//1 2 3 4 5 6 7 8 9
    // deque<int> dq;
    // for (auto& n : s1) {
    //     if (n%2 == 0) dq.push_back(n);
    //     else dq.push_front(n);
    // }
    // copy(dq.begin(), dq.end(), ostream_iterator<int>(cout, " ")); cout<<endl;//9 7 5 3 1 2 4 6 8

    // deque<int> dq;
    // int x;
    // for (int i=0; i<10; ++i) {
    //     cin >> x;
    //     dq.push_front(x);
    // }
    // PrintContainer("deque at first", dq);//10 9 8 7 6 5 4 3 2 1
    // list<int> li(dq.rbegin(), dq.rend());
    // PrintContainer("list at first", li);// 1 2 3 4 5 6 7 8 9 10
    // for (auto it=li.begin(); it != li.end(); ++it) {
    //     int v=*it;
    //     it=li.erase(it); cout<<"*it = "<<*it<<endl;
    //     li.insert(it,v);
    // }
    // PrintContainer("list at last", li);//1 2 3 4 5 6 7 8 9 10
    // dq.assign(li.begin(), li.end());
    // PrintContainer("deque at last", dq);//1 2 3 4 5 6 7 8 9 10
    
    string names1[] = { "Alice", "Helen", "Lucy", "Susan" };
    string names2[] = { "Bob", "David", "Levin", "Mike" };
    list<string> s1(names1, names1 + 4); 
    list<string> s2(names2, names2 + 4); 
    s2.splice(s2.end(), s1, s1.begin()); 
    copy(s1.begin(), s1.end(), ostream_iterator<string>(cout, " ")); cout<<endl;//Helen Lucy Susan
    copy(s2.begin(), s2.end(), ostream_iterator<string>(cout, " ")); cout<<endl;//Bob David Levin Mike Alice
    auto it1 = s1.begin(); advance(it1, 2);//Susan
    auto it2 = s2.begin(); ++it2;//David
    auto it3 = it2; advance(it3, 2);//Mike
    s1.splice(it1, s2, it2, it3);
    copy(s1.begin(), s1.end(), ostream_iterator<string>(cout, " ")); cout<<endl;//Helen Lucy David Levin Susan
    copy(s2.begin(), s2.end(), ostream_iterator<string>(cout, " ")); cout<<endl;//Bob Mike Alice
    
    return 0;
}
*/



//07 关联容器
//7.1 特点
//7.1.1 
//(1)每个关联容器都有一个键Key
//(2)每个元素按键的取值升序排列
//7.1.2 优势: 可根据键值，高效地查找元素
//7.1.3 要求: 
//键的类型必须能够用 < 比较
//int、double等基本数据类型
//其他重载了 < 运算符的类型
//
//7.2 set
//7.2.1 数学中的集合
//(1) 一些同质元素的共同体
//(2) 不含重复的元素
//(3) 不讲究顺序
//(4) 有限/无限集合
//7.2.2 STL中的set
//(1)存储一组数据
//(2)无重复
//(3)有序
//(4)有限集合
//7.2.3 有序的理由
//高效查找
//7.2.4 
//(1)insert()
//(2)erase()
//(3)find()
//(4)lower_bound(); upper_bound(); equal_range();
//(5)count(k)
//
//7.3 map
//7.3.1 map/set相同点 ： 一组无重复有序数据
//7.3.2 map/set不同点
//(1) set的元素类型是键本身
//(2) map的元素类型是由键和附加数据所构成的二元组 map<string, int> scores;
//(3) 在map中按键查找一个元素时，除了能确定它的存在性，还可得到相应的附加数据
//7.3.3 map的元素类型 -- pair
//
//7.4 关联容器分类
//7.4.1 简单关联容器
//容器只有一个类型参数 set<T>
//容器的元素就是键本身
//7.4.2 二元关联容器
//容器有2个类型参数，分别表示键和附加数据的类型
//容器的元素类型是pair<K,V>，即由键类型和元素类型复合而成的二元组
//7.4.3 单重关联容器
//键值唯一，一个键值只能对应一个元素
//7.4.4 多重关联容器
//键值不唯一，一个键值可对应多个元素
//
//7.5 multiset / multimap
//(1)multiset 允许有重复元素
//(2)multimap 允许一个键对应多个附加数据

/*
int main(void) {
    // set<double> sd;
    // pair<set<double>::iterator, bool> r;
    // while (true) {
    //     double v;
    //     cin >> v;
    //     if (v==0) break;
    //     r=sd.insert(v);
    //     if (!r.second) cout<<v<<" duplicated!\n";
    // }
    // auto it1=sd.begin(), it2=sd.end();
    // double mid = (*it1 + *(--it2))/2;
    // cout<<"mid = "<<mid<<endl;
    // cout<<"<= mid "; copy(sd.begin(), sd.upper_bound(mid), ostream_iterator<double>(cout, " ")); cout<<endl;
    // cout<<">= mid "; copy(sd.lower_bound(mid), sd.end(), ostream_iterator<double>(cout, " ")); cout<<endl;
    
    // map<string, int>  courses;
    // map<string, int>::iterator it;
    // string name;
    // courses.insert(make_pair("CSAPP",3));
    // courses.insert(make_pair("CSAPP",3));
    // courses.insert(make_pair("CSARCH", 4));
    // courses.insert(make_pair("COMPILER", 4));
    // courses.insert(make_pair("OS", 5));
    // int n=3, sum_scores=0;
    // while (n > 0) {
    //     cout<<"Input name: "; cin >> name;
    //     it = courses.find(name);
    //     if (it == courses.end()) cout<<name<<"is not available\n";
    //     else {
    //         sum_scores += it->second;
    //         courses.erase(it);
    //         --n;
    //     }
    // }
    // cout<<"sum_scores = "<<sum_scores<<endl;

    // map<char,int> s;
    // char c;
    // cout<<"Input c : "; 
    // do {
    //     cin >> c;
    //     if (isalpha(c)) {
    //         c=tolower(c);
    //         s[c]++;
    //     }
    // }while (c != '.');
    // for (auto& e : s) {
    //     cout<<e.first<<" "<<e.second<<"\n";//统计一句话中每个字母出现的次数
    // }
    // cout<<endl;
    
    return 0;
}
*/



//08 函数对象
//8.1 函数对象
//8.1.1 定义
//(1)一个行为类似函数的对象
//(2)可以无参数，或有几个参数
//(3)功能是获取一个值，或改变操作的状态。
//8.1.2 函数对象的形式
//(1)普通函数就是函数对象
//(2)重载了“()”运算符的类的实例是函数对象
//8.1.3 举例1 定义表示乘法的函数对象——通过定义普通函数
//8.1.4 举例2 定义表示乘法的函数对象——通过重载类的“()”运算符
//
//8.2 STL提供的函数对象
//8.2.1 用于算术运算的函数对象
//一元函数对象: negate
//二元函数对象: plus, minus, multiplies, divides, modulus
//8.2.2 用于逻辑运算的函数对象
//一元谓词: logical_not
//二元谓词: logical_and, logical_or
//8.2.3 用于关系运算的函数对象
//二元谓词: equal_to; not_equal_to; greater; less; greater_equal; less_equal;
//8.3 函数对象概念图
//8.3.1 一元函数对象: 有1个参数的函数对象
//8.3.2 二元函数对象: 有2个参数的函数对象
//8.3.3 产生器: 有0个参数的函数对象
//8.3.4 STL中的函数对象
//一元函数对象: negate
//二元函数对象: plus, minus, multiplies, divides, modulus
//
//8.4 函数对象概念图(谓词)
//8.4.1 用于逻辑运算的函数对象
//8.4.2 用于关系运算的函数对象
//8.4.3 谓词：返回值为bool型的函数对象
//一元谓词
//二元谓词

/*
// template<typename T>
// class Square {
// public:
//     T operator()(T& v) {
//         return v*v;
//     }
// };
//
// double Square(double x) {
//     return x*x;
// }
//
// int mult(int x, int y) {
//     return x*y;
// }
// class MultClass {
// public:
//     int operator()(int x, int y) const {
//         return x*y;
//     }
// };

int main(void) {
    // const int N=5;
    // vector<int> vi(N);
    // cout<<"Input vi: ";
    // for (int i=0; i<N; ++i) {
    //     cin >> vi[i];
    // }
    // transform(vi.begin(), vi.end(), ostream_iterator<int>(cout, " "), negate<int>()); cout<<endl;
    // transform(vi.begin(), vi.end(), ostream_iterator<int>(cout, " "), Square<int>()); cout<<endl;
    //transform(vi.begin(), vi.end(), ostream_iterator<int>(cout, " "), Square); cout<<endl;
    
    // int a[] = {1,2,3,4,5};
    // const int N = sizeof(a) / sizeof(int);
    // // cout<<accumulate(a, a+N, 1, mult)<<endl;//120
    // // cout<<accumulate(a, a+N, 1, MultClass())<<endl;//120
    // cout<<accumulate(a, a+N, 1, multiplies<int>())<<endl;//120
    
    int arr[] ={ 30, 90, 10, 40, 70, 50, 20, 80};
    const int N = sizeof(arr) / sizeof(int);
    vector<int> vi(arr, arr+N);
    cout<<"before sort : ";
    copy(vi.begin(), vi.end(), ostream_iterator<int>(cout, " ")); cout<<endl;
    sort(vi.begin(), vi.end(), greater<int>());//大 -> 小
    cout<<"after sort : ";
    copy(vi.begin(), vi.end(), ostream_iterator<int>(cout, " ")); cout<<endl;
    
    return 0;
}
*/



//11 函数适配器
//11.1 为什么要用函数适配器
//11.1.1 通用需求: 将一种函数对象，转换为另一种符合要求的函数对象
//11.1.2 具体要求
//(1)对函数返回值进行进一步的简单计算
//(2)填上多余参数，再代入算法
//11.1.3 适配器功能: 将一种函数对象，转换为另一种符合要求的函数对象
//
//11.2 使用绑定适配器
//将n元函数对象的指定参数绑定为1个常数，得到n-1元函数对象
//将1个操作数绑定到给定值, 而将二元函数对象转换为一元函数对象
//11.2.2 两个绑定适配器函数
//bind2nd: 将给定值绑定到二元函数对象的第2个实参
//bind1st: 将给定值绑定到二元函数对象的第1个实参
//
//11.3 STL中函数适配器分类
//(1) 绑定适配器: 将n元函数对象的指定参数绑定为1个常数，得到n-1元函数对象 bind1st; bind2nd; --> C++17 中移除
//(2) 组合适配器: 将指定谓词的结果取反 not1; not2 --> C++20 中移除
//(3) 指针函数适配器: 对一般函数使用，使之能够作为其它函数适配器的输入 ptr_fun --> C++17 中移除
//(4) 成员函数适配器: 对成员函数使用，使之能够作为其它函数适配器的输入 mem_fun; mem_fun_ref; --> C++17 中移除
//11.4 函数适配器用法示例
//11.5 成员函数适配器用法

/*
int main(void) {
    int a[] = { 30, 90, 10, 40, 70, 50, 20, 80 };
    const int N = sizeof(a) / sizeof(int);
    vector<int> vi(a, a + N);
    vector<int>::iterator p = find_if(vi.begin(), vi.end(), bind2nd(greater<int>(), 40));
    if (p == vi.end()) cout << "no element greater than 40" << endl;
    else cout << "first element greater than 40 is: " << *p << endl;
    return 0;
}
*/



//12 STL基本算法
//12.1 STL算法基础
//12.1.1  STL算法本身是一种函数模版
// 通过迭代器获得输入数据
// 通过函数对象对数据进行处理
// 通过迭代器将结果输出
//12.1.2 STL算法是通用的，独立于具体的数据类型、容器类型
//12.1.3  STL算法分类
// 不可变序列算法
// 可变序列算法
// 排序和搜索算法
// 数值算法
//
//12.2 不可变序列算法
//12.2.1 类型
//不直接修改所操作的容器内容的算法
//用于查找指定元素、比较两个序列是否相等、对元素进行计数等
//12.2.2 包括
// for_each()：将一个非修改式函数用于指定区间中的每个成员
// find()：在区间中查找某个值首次出现的位置
// find_if()：在区间中查找第一个满足断言测试条件的值
// find_end()：在序列中查找最后一个与另一个序列匹配的值。匹配时可使用等式或二元断言
// find_first_of()：在第二个序列中查找第一个与第一个序列的值匹配的元素
// adjacent_find()：查找第一个与其后面元素匹配的元素。匹配时可使用等式或二元断言
// count()：返回特定值在区间中出现的次数
// count_if()：利用输入的条件，对标志范围内的元素进行操作，返回结果为true的个数
// mismatch()：比较两个序列，找出首个不匹配元素的位置
// equal()：比较两个序列元素是否相同
// search()：在一个系列中查找另一个系列第一次出现的位置
// search_n()：在指定范围内查找某值val出现n次的子序列
//
//12.3 可变序列算法：可以修改它们所操作的容器对象
//对序列进行复制、删除、替换、倒序、旋转、交换、变换、分割、去重、填充、洗牌的算法及生成一个序列的算法
// copy：复制序列
// copy_backward：元素以相反顺序被复制
// iter_swap：交换两个ForwardIterator的值
// remove：删除指定范围内所有等于指定元素的元素
// remove_copy：将所有不匹配元素复制到一个制定容器
// remove_if：删除指定范围内输入操作结果为true的所有元素
// replace：将指定范围内所有等于vold的元素都用vnew代替。
// replace_copy：与replace类似，不过将结果写入另一个容器。
// replace_if：将指定范围内所有操作结果为true的元素用新值代替。
// swap：交换存储在两个对象中的值。
// swap_range：将指定范围内的元素与另一个序列元素值进行交换。
// unique：清除序列中重复元素
// unique_copy：与unique类似，不过把结果输出到另一个容器

/*
bool less6(int x) {
    return x < 6;
}
//
class EvenByTwo {
private:
    int x;
public:
    EvenByTwo():x(0) {}
    int operator()() {
        return x += 2;
    }
};

int main(void) {
    // vector<int> v = {0, 1, 2, 3, 4, 5, 6, 6, 6, 7, 8 };
    // vector<int> v1 = {6,6};
    // vector<int> v2 = {5,6};
    // vector<int> v3 = {0, 1, 2, 3, 4, 5, 7, 7, 7, 9, 7};
    // cout << *adjacent_find(v.begin(), v.end()) <<endl;//6
    // cout << *search(v.begin(), v.end(), v2.begin(), v2.end()) <<endl;//5
    // cout << *search_n(v.begin(), v.end(), 3, 6, equal_to<int>()) <<endl;//6     //连续出现3个6
    // cout << boolalpha << equal(v.begin(), v.end(), v3.begin()) <<endl;//false
    
    // vector<int> v1 = { 0, 1, 2, 3, 4, 4, 5, 5, 6, 6, 6, 6, 6, 7, 8};
    // vector<int> v2 = { 0, 1, 2, 3, 4, 5, 6, 6, 6, 7, 8};
    // ostream_iterator<int> output(cout, " ");
    // vector<int> v4;
    // remove_copy(v2.begin(), v2.end(), back_inserter(v4), 6);    copy(v2.begin(), v2.end(), output); cout<<endl;//0 1 2 3 4 5 6 6 6 7 8
    // v2.erase(remove_if(v2.begin(), v2.end(), less6), v2.end()); copy(v2.begin(), v2.end(), output); cout<<endl;//6 6 6 7 8
    // replace(v2.begin(), v2.end(), 6, 9);                        copy(v2.begin(), v2.end(), output); cout<<endl;//9 9 9 7 8
    // reverse(v2.begin(), v2.end());                              copy(v2.begin(), v2.end(), output); cout<<endl;//8 7 9 9 9
    // rotate_copy(v2.begin(), v2.begin()+3, v2.end(), output);//9 9 8 7 9
    
    vector<int> v(4);
    ostream_iterator<int> output(cout, " ");
    fill(v.begin(), v.end(), -1);
    copy(v.begin(), v.end(), output); cout<<endl;//-1 -1 -1 -1
    generate(v.begin(), v.end(), EvenByTwo());
    copy(v.begin(), v.end(), output); cout<<endl;//2 4 6 8
    
    return 0;
}
*/



//13 STL基本算法(续)
//13.1 排序和搜索算法
// 对序列进行排序
// 对两个有序序列进行合并
// 对有序序列进行搜索
// 有序序列的集合操作
// 堆算法
//13.2 排序算法应用
//13.3 STL数值算法
//13.3.1
//求序列中元素的“和”、部分“和”、相邻元素的“差”或两序列的内积
//求“和”的“+”、求“差”的“-”以及求内积的“+”和“·”都可由函数对象指定

/*
struct Person {
    string name;
    int age;
};
ostream& operator<<(ostream& out, Person p) {
    out << "name: " << p.name;
    out << ", age: " << p.age;
    out<<endl;
    return out;
}
bool SortByName(const Person& lhs, const Person& rhs) {
    return lhs.name < rhs.name;
}
bool SortByAge(const Person& lhs, const Person& rhs) {
    return lhs.age < rhs.age;
}

int main(void) {
    //ostream_iterator<int> output(cout, " ");
    // vector<int> v = {26, 38, 15, 22, 23, 32, 40, 33 };
    // auto p = max_element(v.begin(), v.end());
    // int n = p - v.begin();
    // cout << "max_element" << *p << " found at " << n <<endl;//6
    // vector<int> v1(5);
    // partial_sort_copy(v.begin(), v.begin()+6, v1.begin(), v1.end());
    // copy(v1.begin(), v1.end(), output); cout<<endl;//15 22 23 26 32
    // sort(v.begin(), v.end());
    // copy(v.begin(), v.end(), output); cout<<endl;//15 22 23 26 32 33 38 40
    // cout << *lower_bound(v.begin(), v.end(), 24) << endl;//26
    // cout << *upper_bound(v.begin(), v.end(), 24) << endl;//26
    // cout << boolalpha << binary_search(v.begin(), v.end(), 33) << endl;//true

    // int a1[8] = {26, 38, 15, 22, 23, 32, 40, 33};
    // int a2[8] = {72, 22, 30, 40, 5};
    // vector<int> v1(a1,a1+8);
    // vector<int> v2(a2,a2+5);
    // vector<int> v3(13);
    // merge(v1.begin(), v1.end(),v2.begin(), v2.end(),v3.begin()); copy(v3.begin(), v3.end(), output); cout<<endl; cout<<endl;//26 38 15 22 23 32 40 33 72 22 30 40 5
    // nth_element(v3.begin(), v3.begin()+5, v3.end());             copy(v3.begin(), v3.end(), output); cout<<endl; cout<<endl;//22 5 15 22 23 26 32 33 30 38 72 40 40
    // stable_sort(v2.begin(), v2.end());                           copy(v2.begin(), v2.end(), output); cout<<endl; cout<<endl;//5 22 30 40 72
    // vector<int> v4 = {1, 3, 5, 7, 2, 4, 6, 8};
    // inplace_merge(v4.begin(), v4.begin()+4, v4.end());           copy(v4.begin(), v4.end(), output); cout<<endl; cout<<endl;//1 2 3 4 5 6 7 8

    // const int N=3;
    // vector<Person> people(N);
    // string str[] = {"Alice", "Jack", "Bob"};
    // int a[] = {27,23,22};
    // for (int i=0; i<N; ++i) {
    //     people[i].name = str[i];
    //     people[i].age = a[i];
    // }
    // //sort(people.begin(), people.end(), SortByName);
    // sort(people.begin(), people.end(), SortByAge);
    // copy(people.begin(), people.end(), ostream_iterator<Person>(cout, " ")); cout<<endl;
    
    vector<int> vi = {1,2,3,4,5};
    cout << accumulate(vi.begin(), vi.end(), 0) <<endl;//15
    cout << inner_product(vi.begin(), vi.end(), vi.begin(), 10) << endl;//1^2+2^2+3^2+4^2+5^2+10=65
    partial_sum(vi.begin(), vi.end(), ostream_iterator<int>(cout, " ")); cout<<endl;//1 3 6 10 15
    adjacent_difference(vi.begin(), vi.end(), ostream_iterator<int>(cout, " ")); cout<<endl;//1 1 1 1 1
    
    return 0;
}
*/


