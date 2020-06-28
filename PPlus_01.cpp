
#include <algorithm>
// #include <array>
// #include <cctype>
// #include <cmath>
// #include <cstring>
// #include <cstdlib>
// #include <ctime>
// #include <fstream>
#include <list>
#include <iostream>
// #include <set>
// #include <stdexcept>
#include <string>
// #include <typeinfo>
// #include <vector>

using namespace std;


//02 开始学习C++

//03 处理数据

//04 复合类型

/*
const int SIZE=20;
int main(void) {
    // char first_name[20],last_name[20];
    // char grade;
    // int age;
    // cout<<"first name: "; cin.getline(first_name,20);
    // cout<<"last name: "; cin.getline(last_name,20);
    // cout<<"grade: ";cin>>grade;
    // cout<<"age: ";cin>>age;
    // cout<<"Name= "<<first_name<<","<<last_name<<endl;
    // cout<<"grade= "<<char(grade+1)<<endl;
    // cout<<"age= "<<age<<endl;

    // string name;
    // string dessert;
    // cout<<"name: "; getline(cin,name);
    // cout<<"dessert: "; getline(cin,dessert);
    // cout<<"I have some delicious "<<dessert;
    // cout<<" for you, "<<name<<endl;

    // char first_name[SIZE],last_name[SIZE];
    // char full_name[2*SIZE+1];
    string first_name,last_name,full_name;
    cout<<"first_name: "; getline(cin,first_name);
    cout<<"last_name: "; getline(cin,last_name);
    full_name=first_name+"."+last_name;
    cout<<"full_name= "<<full_name<<endl;

    return 0;
}
*/

//05 循环和关系表达式

/*
// const int SIZE=20;
// const char FINISHED[]="done";
int main(void) {
    // int cnt=-1;
    // char words[SIZE];
    // cout<<"Enter words until type the word done: \n";
    // while (strcmp(FINISHED,words) != 0) {
        // cin>>words;
        // cin.get(); //删除空白字符
        // ++cnt;
    // }
    // cout<<"cnt= "<<cnt<<endl;

    // int cnt=-1;
    // string words;
    // cout<<"Enter words until type the word done: \n";
    // while (words != FINISHED) {
    //     ++cnt;
    //     cin>>words;
    //     cin.get();
    // }
    // cout<<"cnt= "<<cnt<<endl;

    int line;
    cout<<"Enter line: \n";
    cin>>line;
    for (int i=0;i<line;++i) {
        for (int j=0;j<line-i-1;++j)
            cout<<".";
        for (int j=0;j<=i;++j)
            cout<<"*";
        cout<<"\n";
    }

    return 0;
}
*/

//06 分支语句和逻辑运算符

/*
int main(void) {
    // char words[40];
    // int vowel=0,consonant=0,others=0;
    // cout<<"Enter words (q to quit): \n";
    // cin>>words;
    // while (strcmp(words,"q") != 0) {
    //     if (!isalpha(words[0])) ++others;
    //     else {
    //         switch (words[0])
    //         {
    //         case 'a':
    //         case 'e':
    //         case 'i':
    //         case 'o':
    //         case 'u':
    //             ++vowel;
    //             break;
    //         default:
    //             ++consonant;
    //         }
    //     }
    //     cin>>words;
    // }
    // cout<<"vowel= "<<vowel<<endl;
    // cout<<"consonant= "<<consonant<<endl;
    // cout<<"others= "<<others<<endl;

    ifstream fin;
    string file_name;
    cout<<"Enter file_name: \n";
    getline(cin,file_name);
    fin.open(file_name);
    if (!fin.is_open()) {
        cout<<"open failed.\n";
        exit(EXIT_FAILURE);
    }
    char ch;
    int cnt=0;
    while (!fin.eof()) {
        fin>>ch;
        ++cnt;
    }
    cout<<"cnt= "<<cnt<<endl;
    fin.close();

    return 0;
}
*/

//07 函数--C++的编程模块

/*
const int SIZE=10;
int set_mark(int[], int);
void display_mark(int[], int);
double avg_mark(int[], int);
int main(void) {
    int size, golf_mark[SIZE]={0};
    size=set_mark(golf_mark,SIZE);
    display_mark(golf_mark,size);
    double avg=avg_mark(golf_mark, size);
    cout<<"avg= "<<avg<<endl;

    return 0;
}

int set_mark(int arr[], int size) {
    int i=0, flag=0;
    while (i<size && flag==0) {
        cout<<"Enter NO." << i+1 << " golf marks: \n";
        cin>>arr[i++];
        cout<<"press enter to continue, or 's' to stop.\n";
        if (cin.get() == 's') flag=1;
    }
    cout<<"i= "<<i<<endl;
    return i;
}

void display_mark(int arr[], int size) {
    cout<<"golf_mark: \n";
    for (int i=0;i<size;++i)
        cout<<arr[i]<<" ";
    cout<<endl;
}

double avg_mark(int arr[], int size) {
    int sum=0;
    cout<<"size= "<<size<<endl;
    for (int i=0;i<size;++i)
        sum += arr[i];
    return 1.0 * sum/size;
}
*/

/*
void reverse_arr(int a[], int sz) {
    for (int i=0;i<sz/2;++i) {
        a[i] ^= a[sz-i-1];
        a[sz-i-1] ^= a[i];
        a[i] ^= a[sz-i-1];
    }
}

void show_arr(int a[], int sz) {
    cout<<"arr= ";
    for (int i=0;i<sz;++i)
        cout<<a[i]<<" ";
    cout<<"\n";
}

int main(void) {
    int arr[10]={0,1,2,3,4,5,6,7,8,9};
    reverse_arr(&arr[3], 7); //部分反转
    show_arr(arr,10);

    return 0;
}
*/

/*
double add(double x, double y) {
    return x+y;
}
double subtract(double x, double y) {
    return x-y;
}
double calculate(double x, double y, double (*pf)(double x1, double y1)) {
    return pf(x,y);
}

int main(void) {
    double sum=calculate(2.5,10.4,add);
    cout<<"sum= "<<sum<<endl; //12.9
    return 0;
}
*/

//08 函数探幽

/*
void loop_print(const char* str, int n=0);
int main(void) {
    loop_print("abc!");
    loop_print("abc!");
    loop_print("abc!",4);
    return 0;
}
void loop_print(const char* str, int n) {
    static int cnt=0;
    ++cnt;
    if (n==0) {
        cout<<"n==0\n";
        cout<<"str= "<<str<<endl;
    }
    else {
        cout<<"n != 0\n";
        for (int i=0; i<cnt ;++i)
            cout<<str<<" ";
        cout<<"\n";
    }
}
*/

/*
void uppercase(string& s);
int main(void) {
    string st;
    cout<<"Enter a string (q to quit): ";
    getline(cin,st);
    while (st != "q") {
        uppercase(st);
        cout<<st<<endl;
        cout<<"Next string (q to quit): ";
        getline(cin,st);
    }
    cout<<"Bye.\n";
    return 0;
}
void uppercase(string& s) {
    for (int i=0;i<s.size();++i)
        s[i]=toupper(s[i]);
}
*/

/*
template<typename T>
T maxn(T st[], int n) {
    T max=st[0];
    for (int i=0;i<n;++i) {
        if (max<st[i]) max=st[i];
    }
    return max;
}

template<>
const char* maxn<const char*>(const char* sst[], int n) {
    int pos=0;
    for (int i=0;i<n;++i) {
        if (strlen(sst[pos]) < strlen(sst[pos]))
            pos=i;
    }
    return sst[pos];
}

int main(void) {
    int a[]={1,2,9,4,3};
    double ad[]={19.6,13,19.8,100.8,98.4};
    string ss[]={"hello","abc."};
    cout<<maxn(a,5)<<endl; //9
    cout<<maxn(ad,5)<<endl;//100.8
    cout<<maxn(ss,2)<<endl;//hello
    return 0;
}
*/

/*
struct debts {
    char name[50];
    double amount;
};

template<typename T>
void ShowArray(T a[], int n) {
    cout<<"template A: \n";
    for (int i=0;i<n;++i)
        cout<<a[i]<<" ";
    cout<<"\n";
}

template<typename T>
void ShowArray(T* a[], int n) {
    cout<<"template B: \n";
    for (int i=0;i<n;++i)
        cout<<*a[i]<<" ";
    cout<<"\n";
}

template<typename T>
T SumArray(const T* a, int n) {
    T sum=0;
    for (int i=0;i<n;++i)
        sum += a[i];
    return sum;
}

template<typename T>
T SumArray(T* a[], int n) {
    T sum=0;
    for (int i=0;i<n;++i)
        sum += *a[i];
    return sum;
}

int main(void) {
    int a[]={13,31,103,301,310,130};
    struct debts mr_E[3] ={
        {"zs",2400.0},
        {"ls",1300.0},
        {"ww",1800.0}
    };
    double* pd[3];
    for (int i=0;i<3;++i)
        pd[i]=&mr_E[i].amount;
    ShowArray(a,6);
    ShowArray(pd,3);
    cout<<SumArray(a,6)<<endl;
    cout<<SumArray(pd,3)<<endl;
    
    return 0;
}
*/

//09 内存模型和名称空间

/*
int x=10;
int y;
void f1() {
    int y=1;
    cout<<"f1: "<<"x= "<<x<<","<<"y= "<<y<<endl;
}
extern void f2();

int main(void) {
    cout<<"x= "<<x<<endl;
    {
        int x=4;
        cout<<"x= "<<x<<endl;
        cout<<"y= "<<y<<endl;
    }
    f1();
    f2();

    return 0;
}
*/

/*
// const int ArrSize=100;
// void strcnt(const char* str) {
//     static int total=0;
//     int cnt=0;
//     while (*str++) ++cnt;
//     total += cnt;
//     cout<<"cnt= "<<cnt<<endl;
//     cout<<"total= "<<total<<endl;
// }

void strcnt(const string& str) {
    static int total=0;
    int cnt=str.length();
    total += cnt;
    cout<<"cnt= "<<cnt<<endl;
    cout<<"total= "<<total<<endl;    
}

int main(void) {
    // char a[ArrSize];
    // char ch;
    // cout<<"Enter a line: \n";
    // cin.get(a,ArrSize);
    // while (cin) {
    //     cin.get(ch);
    //     while (ch != '\n') cin.get(ch);
    //     strcnt(a);
    //     cout<<"Enter next line (empty line to quit)\n";
    //     cin.get(a,ArrSize);
    // }
    // cout<<"Bye.\n";

    string s;
    char ch;
    cout<<"Enter a line: \n";
    getline(cin,s);
    while (s != "") {
        strcnt(s);
        cout<<"Enter next line (empty line to quit)\n";
        getline(cin,s);
    }
    cout<<"Bye.\n";

    return 0;
}
*/

/*
struct stu{
    char name[20];
    int num;
};

int set_stu(stu& s, const char* str, int n) {
    if (strlen(str) > 0) {
        strcpy(s.name,str);
        s.num=n;
        return 1;
    }
    else return 0;
}

void show_stu(const stu& cstu) {
    cout<<"name= "<<cstu.name<<endl;
    cout<<"num= "<<cstu.num<<endl;
}

int main(void) {
    char buf[1024];
    char st[20];
    int num,n=0;
    stu* ps=new (buf) stu[2];
    cout<<"Enter string to set stu: "; cin.getline(st,20);
    cout<<"Enter a number: "; cin>>num;
    while (strlen(st) > 0) {
        cin.get();
        set_stu(ps[n++],st,num);
        if (n>=2) break;
        cout<<"Enter string to set stu: "; cin.getline(st,20);
        cout<<"Enter a number: "; cin>>num;
    }
    cout<<"---------\n";
    for (int i=0;i<2;++i) {
        show_stu(ps[i]);
    }
    return 0;
}
*/

//10 对象和类

/*
#include "stack.h"
int main(void) {
    Stack st;
    cumstomer cust;
    double sum_payment=0.0;
    char select;
    cout<<"select a(add) , p(pop) or q(quit): \n";
    while (cin.get(select) && select != 'q') {
        while (cin.get() != '\n') continue;
        if (select == 'a') {
            cout<<"Enter a name: "; cin.getline(cust.name,35);
            cout<<"Enter pament: "; cin>>cust.payment;
            while (cin.get() != '\n') continue;
            st.push(cust);
            cout<<"Item pushed.\n";
        }
        if (select == 'p') {
            st.pop(cust);
            sum_payment += cust.payment;
            cout<<"cust.name= "<<cust.name<<endl;
            cout<<"cust.payment= "<<cust.payment<<endl;
            cout<<"sum_payment= "<<sum_payment<<endl;
        }
    cout<<"select a(add) , p(pop) or q(quit): \n";
    }
    cout<<"Bye.\n";
    return 0;
}
*/

/*
#include "list.h"
void visit_Item(Item& item) {
    cout<<item<<" ";
}

int main(void) {
    List lst;
    Item item=0;
    do {
        cout<<"Enter the unsigned long number: \n";
        cin>>item;
        cin.get();
        lst.add(item);
    }while (item != 0);
    cout<<"start to visit: \n";
    lst.visit(visit_Item);
    cout<<"\n";
    return 0;
}
*/

//11 使用类

/*
#include <cstdlib>
#include <ctime>
#include "vect.h"

int main(void) {
    using VECTOR::Vector;
    srand(time(0));
    double direction;
    Vector step;
    Vector ret(0.0,0.0);
    unsigned long steps=0;
    double target;
    double dstep;
    unsigned long Max=0;
    unsigned long Min=0;
    unsigned long Sum=0;
    unsigned long cnt=0;

    cout<<"Enter target distance (q to quit): ";
    while (cin>>target) {
        cout<<"Enter step length: ";
        if (!(cin>>dstep)) break;
        while (ret.magval() < target) {
            direction=rand()%360;
            step.reset(dstep,direction,Vector::POL);
            ret = ret + step;
            ++steps;
        }
        cout<<"After"<<steps<<" steps, location is now: \n";
        cout<<ret<<endl;
        ret.polar_mode();
        cout<<"or\n"<<ret<<endl;
        cout<<"Average outward distance per step= "<<ret.magval()/steps<<endl;

        if (Max<steps) Max=steps;
        if (Min==0) Min=Max;
        if (Min>steps) Min=steps;
        Sum += steps;
        ++cnt;

        steps=0;
        ret.reset(0.0,0.0);
        cout<<"Enter target distance (q to quit): ";
    }
    cout<<"Your input "<<cnt<<" times, and statistics info: \n";
    cout<<"Max= "<<Max<<endl;
    cout<<"Min= "<<Min<<endl;
    cout<<"avg= "<<Sum/cnt<<endl;
    cout<<"Bye.\n";
    cin.clear();
    while (cin.get() != '\n')
        continue;

    return 0;
}
*/


/*
#include "mytime.h"
int main(void) {
    Time t1(3,25);
    Time t2(2,48);
    Time tmp;

    cout<<"t1 and t2: \n";
    cout<<t1<<" ; "<<t2<<endl;
    tmp=t1+t2;
    cout<<"t1+t2= "<<tmp<<endl;
    tmp=t1*1.17;
    cout<<"tmp= "<<tmp<<endl;
    cout<<"t2*10.0= "<< t2*10.0 <<endl;

    return 0;
}
*/

/*
#include "cpx.h"

int main(void) {
    return 0;
}
*/

//12 类和动态内存分配

/*
#include "string2.h"
int main(void) {
    String s1(" and I am a C++ student.");
    String s2="Please enter your name: ";
    String s3;
    cout<<s2;
    cin>>s3;
    s2="My name is " + s3;
    s2=s2+s1;
    cout<<"s2= "<<s2<<endl;
    s2.string_up();
    cout<<"s2.has('A')= "<<s2.has('A')<<endl;

    s1="red";
    String rgb[3]={String(s1), String("green"), String("blue")};
    cout<<"Enter the name of a primary color: ";
    bool success=false;
    String ans;
    while (cin>>ans) {
        ans.string_low();
        for (int i=0;i<3;++i) {
            if (ans == rgb[i]) {
                cout<<"That is right!\n";
                success=true;
                break;
            }
        }
        if (success) break;
        else cout<<"Try again!\n";
    }
    cout<<"Bye.\n";
    return 0;
}
*/

/*
#include "stack2.h"
const int MAX=5;

int main(void) {
    Stack st(MAX);
    Item item;
    for (int i=0;i<MAX;++i) {
        cout<<"Enter a unsigned long number: ";
        cin>>item;
        while (cin.get() != '\n') continue;
        st.push(item);
        cout<<"Item pushed.\n";
    }

    cout<<"---------\n";
    Stack st_new(st);
    for (int i=0;i<MAX;++i) {
        st_new.pop(item);
        cout<<"Item poped: "<<item<<endl;
    }
    cout<<"Bye.\n";

    return 0;
}
*/

//13 类继承

/*
#include "classic.h"
void f(const Cd& disk) {
    disk.Report();
}

int main(void) {
    Cd c1("zs","Captiol",4,35.5);
    Classic c2=Classic("PS in B, F in C","ABren","Philips",2,57.7); 
    Cd* pcd=&c1;
    cout<<"Using obj dirctly.\n";
    c1.Report();
    c2.Report();
    cout<<"----------\n";

    cout<<"using cd* pointer to objs: \n";
    pcd->Report();
    pcd=&c2;
    pcd->Report();
    cout<<"----------\n";

    cout<<"call a function with Cd& argument: \n";
    f(c1);
    f(c2);
    cout<<"----------\n";

    cout<<"Testing assigment: \n";
    Classic coy;
    coy=c2;
    coy.Report();
    cout<<"----------\n";

    return 0;
};
*/


//14 代码重用
/*
#include "winec.h"
int main(void) {
    cout<<"Enter name of wine: ";
    char lab[50]; cin.getline(lab,50);
    cout<<"Enter number of years: ";
    int yrs; cin>>yrs;
    Wine holding(lab,yrs);
    holding.GetBottles();
    holding.Show();

    const int YRS=3;
    int y[YRS]={1993,1995,1998};
    int b[YRS]={48,60,72};
    Wine more("Gushing Grape Red",YRS,y,b);
    more.Show();
    cout<<"Total bottles for "<<more.Label()<<": "<<more.sum()<<endl;
    cout<<"Bye.\n";
    return 0;
}
*/

/*
#include "queuetp.h"
int main(void) {
    QueueTp<Worker> lolas;
    Worker w1;
    w1.Set();
    lolas.enqueue(w1);
    Worker w2;
    lolas.dequeue(w2);
    w2.Show();
    cout<<"Bye.\n";
    return 0;
}
*/

//15 friend,异常和其他

/*
class bad_hmean: public std::logic_error {
public:
    bad_hmean(const string& what_arg="HMean, Invalid argument "): logic_error(what_arg) {}
};

class bad_gmean: public std::logic_error {
public:
    bad_gmean(const string& what_arg="GMean, Invalid argument "): logic_error(what_arg) {}
};

int main(void) {
    double x,y,z;
    cout<<"Enter two numbers: \n";
    while (cin>>x>>y) {
        try {
           z=hmean(x,y);
           cout<<"z= "<<z<<endl;
           cout<<"gmean(x,y)= "<<gmean(x,y)<<endl;
           cout<<"Enter next set of numbers <q to quit>: ";     
        }
        catch (bad_hmean& bh) {
            bh.what();
            cout<<"Try Again.\n";
            continue;
        }
        catch (bad_gmean& bg) {
            cout<<bg.what();
            cout<<"Sorry, you don't get to play any more.\n";
            break;
        }
    }
    cout<<"Bye.\n";
    return 0;
}
*/

/*
class unexpected_mean: public std::logic_error {
private:
    double v1;
    double v2;
public:
    unexpected_mean(double a=0, double b=0, string s="mean error")
        :v1(),v2(),logic_error(s) {}
    virtual void msg()=0;
};

class bad_hmean: public unexpected_mean {
public:
    bad_hmean(double a=0, double b=0, string s="HMean")
        :unexpected_mean(a,b,s) {}
    void msg();
};

class bad_gmean: public unexpected_mean {
public:
    bad_gmean(double a=0, double b=0, string s="GMean")
        :unexpected_mean(a,b,s) {}
    void msg();
};

inline void unexpected_mean::msg() {
    cout<<v1<<" "<<v2<<endl;
}

inline void bad_hmean::msg() {
    cout<<"bad_HMean now."<<endl;
    cout<<what()<<endl;
    cout<<"HMean, Invalid arguments."<<endl;
    unexpected_mean::msg();
}

inline void bad_gmean::msg() {
    cout<<"bad_GMean now."<<endl;
    cout<<what()<<endl;
    cout<<"GMean, Invalid arguments."<<endl;
    unexpected_mean::msg();
}

double hmean(double a, double b) {
    if (a==-b) throw bad_hmean();
    return 2.0 * a * b/(a+b);
}

double gmean(double a, double b) {
    if (a<0 || b<0) throw bad_gmean();
    return std::sqrt(a*b);
}

int main(void) {
    double x,y,z;
    cout<<"Enter two numbers: \n";
    while (cin>>x>>y) {
        try {
           cout<<"hmean(x,y)= "<<hmean(x,y)<<endl;
           cout<<"gmean(x,y)= "<<gmean(x,y)<<endl;
           cout<<"Enter next set of numbers <q to quit>: ";     
        }
        catch (unexpected_mean& bh) {
            if (typeid(bh) == typeid(bad_hmean)) {
                bad_hmean* pbh=dynamic_cast<bad_hmean*>(&bh);
                pbh->msg();
            }
            else if (typeid(bh) == typeid(bad_gmean)) {
                bad_gmean* pbg=dynamic_cast<bad_gmean*>(&bh);
                pbg->msg();
            }
            cout<<"Try Again.\n";
            continue;
        }
    }
    cout<<"Bye.\n";
    return 0;
}
*/

//16 string类和STL

/*
const int NUM=16;
int main(void) {
    ifstream fin ;
    fin.open("wordlist.txt",ifstream::in);
    if (!fin.is_open()) {
        cerr<<"open wordlist.txt failed.\n";
        exit(EXIT_FAILURE);
    }
    string word;
    vector<string> wordlist;
    if (fin.good()) {
        while (fin>>word)
            wordlist.push_back(word);
    }
    int length=wordlist.size();
    fin.close();

    srand(std::time(0));
    cout<<"Will you play a word game? <y/n> : ";
    char play;
    cin>>play;
    play=tolower(play);
    while (play=='y') {
        string target=wordlist[rand() % NUM];
        int len=target.length();
        string attempt(len,'-'); //
        string badchars; //错误猜测组成的string
        int guesses=6;
        cout<<"This word len= "<<len<<" and you gusse a letter a time. You get "<<guesses<<" wrong guesses.\n";
        cout<<"Your word: "<<attempt<<endl;
        while (guesses>0 && attempt != target) {
            cout<<"Guess a letter: ";
            char letter;
            cin>>letter;
            if (badchars.find(letter) != string::npos || attempt.find(letter) != string::npos) {
                cout<<"You already guesss that. Try again.\n";
                continue;
            }
            int loc=target.find(letter);
            if (loc == string::npos) {
                cout<<"Oh, bad guess! \n";
                --guesses;
                badchars += letter;
            }
            else {
                cout<<"Good guess! \n";
                do {
                    attempt[loc]=letter; //attempt对应位置设置为letter
                    loc=target.find(letter,loc+1); //check if letter appear again
                }while (loc != string::npos);
            }
            cout<<"Your word: "<<attempt<<endl;
            if (attempt != target) {
                if (badchars.length() > 0) cout<<"Bad choices: "<<badchars<<endl;
                cout<<guesses<<" bad guesses left.\n";
            }
        }
        if (guesses > 0) cout<<"That's right! \n";
        else cout<<"Sorry, target= "<<target<<endl;
        cout<<"Will you play another? <y/n>: ";
        cin>>play;
        play=tolower(play);
    }
    cout<<"Bye.\n";

    return 0;
}
*/

/*
template<typename T>
int reduce(T a[], int n) {
    list<T> ls;
    ls.insert(ls.end(),a,a+n);
    ls.sort();
    ls.unique();
    auto pd=ls.begin();
    int i=0;
    while (pd != ls.end()) {
        a[i++]=*pd++;
    }
    return ls.size();
}

int main(void) {
    int i;
    long a1[5]={1,3,2,8,2};
    int sz=reduce(a1,sizeof(a1)/sizeof(long));
    cout<<"a1= ";
    for (i=0;i<sz;++i)
        cout<<a1[i]<<" ";
    cout<<"\n";

    string a2[6]={"it","aborad","it","zone","quit","aa"};
    sz=reduce(a2,sizeof(a2)/sizeof(string));
    cout<<"a2= ";
    for (i=0;i<sz;++i)
        cout<<a2[i]<<" ";
    cout<<"\n";

    return 0;
}
*/

//17 输入，输出和文件

/*
int main(void) {
    char ch;
    int ct1=0;
    cout<<"Input1: ";
    cin>>ch; //忽略空格以及换行符
    while (ch != 'q') {
        ++ct1;
        cin>>ch;
    }

    cout<<"Input2: ";
    int ct2=0;
    cin.get(ch); //所有字符
    while (ch != 'q') {
        ++ct2;
        cin.get(ch);
    }
    cout<<"ct1= "<<ct1<<endl;
    cout<<"ct2= "<<ct2<<endl;

    return 0;
}
*/

/*
int main(void) {
    string line;
    ifstream fin1("file1.txt", ios_base::in);
    ifstream fin2("file2.txt", ios_base::in);
    ofstream fout("CombFile.txt", ios_base::out);

    if (fin1.is_open() && fin2.is_open() && fout.is_open()) {
        while (!fin1.eof() || !fin2.eof()) {
            if (getline(fin1,line) && line.size() > 0) fout<<line;
            if (getline(fin2,line) && line.size() > 0) fout<<" " + line;
            fout<<endl;
        }
    }
    else {
        cout<<"Open file failed.\n";
        exit(EXIT_FAILURE);
    }
    fin1.close();
    fin2.close();
    fout.close();
    return 0;
}
*/

/*
int main(void) {
    ifstream fin_mat("mat.txt",ios_base::in);
    ifstream fin_pat("pat.txt",ios_base::in);
    string guest;
    set<string> mat_guest,pat_guest,guest_set;
    if (!fin_mat.is_open() || !fin_pat.is_open()) {
        cout<<"Open file failed.\n";
        exit(EXIT_FAILURE);
    }
    while (getline(fin_mat,guest) && guest.size() > 0) mat_guest.insert(guest);
    cout<<"mat guests: ";
    for (auto pd=mat_guest.begin(); pd != mat_guest.end(); ++pd) 
        cout<<*pd<<" ";
    while (getline(fin_pat,guest) && guest.size() > 0) pat_guest.insert(guest);
    cout<<"\npat guests: ";
    for (auto pd=pat_guest.begin(); pd != pat_guest.end(); ++pd) 
        cout<<*pd<<" ";
    cout<<"\n";
    fin_mat.close();
    fin_pat.close();

    guest_set.insert(mat_guest.begin(),mat_guest.end());
    guest_set.insert(pat_guest.begin(),pat_guest.end());
    ofstream fout("guest.txt",ios_base::out);
    if (!fout.is_open()) {
        cout<<"Open file failed.\n";
        exit(EXIT_FAILURE);
    }
    for (auto pd=guest_set.begin(); pd != guest_set.end(); ++pd)
        fout<<*pd<<" "; //合并名单
    cout<<"\n";
    fout.close();

    ifstream fin("guest.txt",ios_base::in);
    if (!fin.is_open()) {
        cout<<"Open file failed.\n";
        exit(EXIT_FAILURE);
    }
    cout<<"All Guest list: \n";
    while (getline(fin,guest))
        cout<<guest<<" ";
    cout<<"\n--------------"<<endl;
    fin.close();

    return 0;
}
*/

/*
const int LIMIT=50;
class Store {
private:
    string str;
    ofstream* pfout;
public:
    Store(ofstream& out):pfout(&out) {}
    bool operator()(const string& str) {
        unsigned int len=str.length();
        if (pfout->is_open()) {
            pfout->write((char*)&len, sizeof(len));
            pfout->write(str.data(), len);
            return true;
        }
        else return false;
    }
    ~Store(){}
};

void ShowStr(const string& str) {
    cout<<str<<"\n";
}
void GetStrs(ifstream& fin, vector<string>& v) {
    unsigned int len;
    char* pc;
    while (fin.read((char*)&len, sizeof(len))) {
        pc=new char[len];
        fin.read(pc,len);
        v.push_back(pc);
    }
}

int main(void) {
    vector<string> vostr;
    string tmp;

    cout<<"Enter strings (empty line to quit): \n";
    while (getline(cin,tmp) && tmp[0] != '\0') vostr.push_back(tmp);
    cout<<"Your input: \n";
    for_each(vostr.begin(), vostr.end(), ShowStr);

    ofstream fout("strings.txt", ios_base::out | ios_base::binary);
    for_each(vostr.begin(), vostr.end(), Store(fout));
    fout.close();

    vector<string> vistr;
    ifstream fin("strings.txt", ios_base::in | ios_base::binary);
    if (!fin.is_open()) {
        cerr<<"open file failed.\n";
        exit(EXIT_FAILURE);
    }

    GetStrs(fin,vistr);
    cout<<"\nstrings read from file: \n";
    for_each(vistr.begin(), vistr.end(), ShowStr);

    return 0;
}
*/

//18 探讨C++新标准

/*
const int sz=5;
template<typename T>
void asum(const array<double,sz>& a, T fp) {
    for (auto pt=a.begin(); pt != a.end(); ++pt)
        fp(*pt);
}

int main(void) {
    double total=0.0;
    array<double,sz> arr={1.2, 2.3, 3.4, 4.5, 5.6};
    asum(arr,[&total] (double w) {total += w;});
    cout<<"total= "<<total<<endl; //17

    return 0;
}
*/

/*
template<typename T>
T avg_list(const initializer_list<T>& ilst) {
    int cnt=0;
    T sum=0;
    for (auto p=ilst.begin(); p<=ilst.end(); ++p) {
        ++cnt;
        sum += *p;
    }
    return sum/cnt;
}

int main(void) {
    auto rt1=avg_list({1.2, 3.4, 5.6});
    auto rt2=avg_list({1,3,5,7,9});
    auto rt3=avg_list<double>({'A',70,65,33});
    cout<<"rt1= "<<rt1<<endl;
    cout<<"rt2= "<<rt2<<endl;
    cout<<"rt3= "<<rt3<<endl;
    return 0;
}
*/

/*
class A {
public:
    struct Info {
        string qcode;
        string zcode;
    };
private:
    Info* pi;
public:
    A() {
        pi=nullptr;
        cout<<"A()\n";
        Display();
    }
    A(string q, string z) {
        pi=new Info;
        pi->qcode=q;
        pi->zcode=z;
        cout<<"A(string q, string z)\n";
    }
    A(const A& a) {
        pi=new Info;
        pi->qcode=a.pi->qcode;
        pi->zcode=a.pi->zcode;
        cout<<"A(const A& a)\n";
        Display();
    }
    A(A&& ma) {
        cout<<"A(A&& ma)\n";
        pi=ma.pi;
        ma.pi=nullptr;
    }
    ~A() {
        delete pi;
        cout<<"~A()\n";
    }
    A& operator=(const A& a) {
        if (this == &a) return *this;
        if (!pi) delete pi;
        pi=new Info;
        pi->qcode=a.pi->qcode;
        pi->zcode=a.pi->zcode;
        cout<<"Normal Assigment.\n";
    }
    A& operator=(A&& a) {
        if (this == &a) return *this;
        if (!pi) delete pi;
        pi=a.pi;
        a.pi=nullptr;
        cout<<"Move Assigment.\n";
        Display();
        return *this;
    }
    A operator+(const A& a) const {
        cout<<"operator+()"<<endl;
        return A(pi->qcode + a.pi->qcode, pi->zcode + a.pi->zcode);
    }
    void Display() const {
        cout<<"Display Info: ";
        if (!pi) cout<<"pi==nullptr\n";
        else cout<<"pi= "<<pi<<", qcode= "<<pi->qcode<<", zcode= "<<pi->zcode<<endl;
    }
};

int main(void) {
    A a1("C","++");
    A a2("Computer","Science");
    cout<<"---------------1\n";
    A a3=a2; cout<<"---------------2\n";
    a2=a1; cout<<"---------------3\n";
    a1=a2+a3; cout<<"---------------4\n";
    A a4 (a1+a2); 
    cout<<"---------------5\n";
    return 0;
}
*/

/*
long double sum_val() {return 0;} //必须首先定义

template<typename T, typename...Args>
long double sum_val(T val, Args...args) {
    long double sum=(long double)val + (long double)sum_val(args...);
    return sum;
}

int main(void) {
    cout<<sum_val(52,34,98,101)<<endl;
    cout<<sum_val('x','y',95,74,'Z')<<endl;
    cout<<sum_val(0.2,1e2,54,'M','\t')<<endl;
    return 0;
}
*/

/*
template<typename T>
class TooBig {
private:
    T cutoff;
public:
    TooBig(const T& t): cutoff(t) {}
    bool operator()(const T& v) {return v>cutoff;}
};

auto Loutint=[](int n){cout<<n<<" ";};

int main(void) {
    TooBig<int> tbi(100);
    int a[10]={50,100,90,180,60,210,415,88,188,201};
    list<int> l1(a,a+10);
    list<int> l2(a,a+10);
    cout<<"old list: \n";
    for_each(l1.begin(), l1.end(), Loutint); cout<<"\n";
    for_each(l2.begin(), l2.end(), Loutint); cout<<"\n";
    l1.remove_if([](int n)->bool{return n>100;});
    l2.remove_if([](int n)->bool{return n>200;});
    cout<<"new list: \n";
    for_each(l1.begin(), l1.end(), Loutint); cout<<"\n";
    for_each(l2.begin(), l2.end(), Loutint); cout<<"\n";
    return 0;
}
*/
































