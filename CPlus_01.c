

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
// #include <stdbool.h>
// #include <stdarg.h>
#include <string.h>
// #include <limits.h>
// #include <math.h>
// #include <time.h>

//01 初识C语言
//02 C语言概述
//03 数据和C
//04 字符串与格式化输入/输出
//05 运算符，表达式和语句
//06 循环
//07 分支和跳转


//08 字符输入/输出和输入验证

/*
int main(void) {
    int cnt=0;
    char ch = getchar();
    while (ch != EOF) {
        if (cnt++ == 10) {
            printf("\n");
            cnt=1;
        }
        if (ch >= '\040') printf(" \'%c\'--%3d ",ch,ch);
        else if (ch == '\n') {
            printf(" \'\\n\'--\\n\n");
            cnt=0;
        }
        else if (ch == '\t') printf(" \\t--\\t ");
        else printf(" \'%c\'--^%c ",ch,ch+64);
        while ((ch=getchar()) == '\040');
    }
    return 0;
}
*/

/*
int main(void) {
    int word_cnt=0;
    int letter=0;
    char ch;
    printf("Input some words: \n");
    while ((ch=getchar()) != '\n') {
        //if ( (ch>='A' && ch<='Z') || (ch>='a' && ch<='z')) ++letter;
        if (isalpha(ch) != 0) ++letter;
        //if (ch == ' ' || ch == ',' || ch == '.' || ch == '\n') ++word_cnt;
        if (ispunct(ch) != 0 || ch == ' ') ++word_cnt;
    }
    printf("word_cnt=%d, letter=%d, letter/word_cnt=%.3f\n", word_cnt, letter, 1.0*letter/word_cnt);
    return 0;
}
*/


//09 函数

/*
void alter(int* px, int* py) {
    *px=*px+*py;
    *py=*px-*py;
}

int main(void) {
    int x=12,y=34;
    alter(&x,&y);
    printf("x=%d, y=%d\n",x,y);//46,12
    return 0;
}
*/

/*
int position(char ch) {
    if (ch>='A' && ch<='Z') return ch-'A'+1;
    if (ch>='a' && ch<='z') return ch-'a'+1;
    return -1;
}

void get_char_pos(void) {
    char ch;
    printf("Enter the chars (ended by EOF, not enter):");
    while ((ch=getchar()) != '#') {
        if (ch == '\n') continue;
        if (position(ch) != -1) printf("The char %c's position in alphabet is %d.\n", ch, position(ch));
        else printf("%c is not in alphabet.\n", ch);
    }
    printf("end of pos.\n");
}

int main(void) {
    get_char_pos();
    return 0;
}
*/

/*
double power(double n, int p) {
    double pow=1.0;
    int i;
    if (n==0 && p==0) {
        printf("%f ^ %d is not defined!\n", n, p);
        return 1;
    }
    if (n==0) return 0;
    if (p==0) return 1;
    if (p>0) {
        for (i=1;i<=p;++i)
            pow *= n;
        return pow;
    } else {
        for (i=01;i<=-p;++i)
            pow *= n;
        return 1/pow;
    }
}

int main(void) {
    double x,xpow;
    int exp;
    printf("Enter x and exp. Enter q to quit.\n");
    while (scanf("%lf %d",&x,&exp) == 2) {
        xpow=power(x,exp);
        printf("%.1f ^ %d = %.1f\n", x, exp, xpow);
    }
    printf("bye.\n");
    return 0;
}
*/

//10 数组和指针

/*
void r_sort(int num[], int n) {
    for (int i=0; i<n-1;++i) {
        for (int j=0;j<n-1-i;++j) {
            if (num[j] < num[j+1]) {
                num[j] ^= num[j+1];
                num[j+1] ^= num[j];
                num[j] ^= num[j+1];
            }
        }
    }
}

int main(void) {
    int a[9]={1,2,3,4,5,6,7,8,9};
    r_sort(a,9);
    for (int i=0;i<9;++i) printf("%d ",a[i]);
    printf("\n");
    return 0;
}
*/

/*
void copy_arr(int n, int m, int dst[n][m], const int src[n][m]) {
    for (int i=0;i<n;++i) {
        for (int j=0;j<m;++j) {
            dst[i][j]=src[i][j];
        }
    }    
}

void show_arr(int n, int m, const int a[n][m]) {
    printf("n=%d, m=%d\n", n, m);
    for (int i=0;i<n;++i) {
        for (int j=0;j<m;++j) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int n=3;
    int m=5;
    int dst[n][m];
    int src[][5]={
        { 1, 3, 5, 7, 9},
        { 2, 4, 6, 8,10},
        {11,13,15,17,19},
    };
    copy_arr(n,m,dst,src);
    show_arr(n,m,dst);
    
    return 0;
}
*/

/*
#define ROWS 3
#define COLS 5

void input_arr(int rows, int a[][COLS]) {
    printf("Enter the array number: \n");
    for (int i=0;i<rows;++i) {
        printf("Enter five number seprated by enter: \n");
        for (int j=0;j<COLS;++j) 
            scanf("%d",&a[i][j]);
    }
}

double col_avg(int cols, const int a[]) {
    double sum;
    for (int i=0;i<cols;++i) sum += a[i];
    return sum/cols;
}

double arr_avg(int rows, const int a[][COLS]) {
    double sum=0;
    for (int i=0;i<rows;++i) sum += col_avg(COLS,a[i]);
    printf("sum=%f\n", sum);
    return sum/rows;
}

double show_ret(int rows, const int a[][COLS]) {
    printf("original input: \n");
    for (int i=0;i<rows;++i) {
        for (int j=0;j<COLS;++j) 
            printf("%d ",a[i][j]);
        printf("\n");
    }

    for (int i=0;i<rows;++i) {
        printf("col_avg[%d]=%f\n",i,col_avg(COLS,a[i]));
    }
    printf("arr_avg=%f\n",arr_avg(ROWS,a));
}

int main(void) {
    int arr[ROWS][COLS];
    input_arr(ROWS,arr);
    show_ret(ROWS,arr);
    printf("\n");
    return 0;
}
*/

//11 字符串和字符串函数

/*
char* s_gets1(char* st, int n) {
    char* ret_val=fgets(st,n,stdin);
    if (ret_val) {
        while (*st != '\n' && *st != '\0') ++st;
        if (*st == '\n') *st='\0';
        else while (getchar() != '\n') continue;
    }
    return ret_val;
}

char* s_gets2(char* st, int n) {
    char* find;
    char* ret_val=fgets(st,n,stdin);
    if (ret_val) {
        find=strchr(st,'\n');
        if (find) *find='\0';
        else while (getchar() != '\n') continue; 
    }
    return ret_val;
}

void ToUpper(char* st) {
    while (*st) {
        *st=toupper(*st);
        ++st;
    }
}

int str_length(const char* st) {
    int cnt=0;
    while (*st++) {
        ++cnt;
    }
    return cnt;
}

char* str_blank(const char* st) {
    while (*st != '\0' && *st != ' ') ++st;
    if (*st == '\0') return NULL;
    else return (char*)st;
}

#define SIZE 64
#define ANS "GRANT"

int main(void) {
    char a[SIZE];
    puts("Who is buried in grant's tomb?");
    s_gets1(a,SIZE);
    ToUpper(a);
    while (strcmp(a,ANS) != 0) {
        puts("Try again.\n");
        s_gets1(a,SIZE);
        ToUpper(a);
    }
    puts("That's Right.\n");
    return 0;
}
*/

/*
#define SIZE 64
char* get_word(char* out, int n) {
    char input[SIZE];
    char* in=input;
    int i=0;
    puts("Enter a string: ");
    fgets(input,SIZE,stdin);
    while ((*in == '\n' || *in == '\t' || *in == ' ') && *in != '\0') ++in;
    while (*in != '\n' && *in != '\t' && *in != ' ' && *in != '\0' && i<n) {
        *out++ = *in++;
        ++i;
    }
    return out;
}

int main(void) {
    char output[SIZE];
    get_word(output,SIZE);
    printf("First word= %s\n", output);
    return 0;
}
*/

/*
#define SIZE 64
int str_in(char* st, char* sub) {
    char* st0=st;
    int cnt=0; //sub中匹配的字符数
    int src_len=strlen(sub) - 1;//去除结束字符
    printf("src_len=%d\n",src_len);
    while (*st != '\0' && cnt<src_len) {
        if (st[cnt] == sub[cnt]) {
            //printf("st[%d]=%c\n", cnt, st[cnt]);
            ++cnt;
        }
        else {
            cnt=0;
            ++st;
            
        }
    }
    if (cnt==src_len) return (int)(st-st0);
    else return -1;
}

int main(void) {
    char main_str[SIZE],sub_str[SIZE];
    int pos=0;
    printf("Input main_str: "); fgets(main_str,SIZE,stdin);
    printf("Input sub_str: "); fgets(sub_str,SIZE,stdin);
    printf("main_str=%s\n",main_str);
    printf("sub_str=%s\n",sub_str);
    while (*main_str != '\n') {
        pos=str_in(main_str,sub_str);
        printf("pos=%d\n", pos);
        printf("Another? Enetr main_str(blank to quit): ");
        fgets(main_str,SIZE,stdin);
        printf("Input sub_str: ");
        fgets(sub_str,SIZE,stdin);
    }
    return 0;
}
*/


//12 存储类别、链接和内存管理

/*
char color='B';
void f1(void) {
    char color='R';
    printf("f1_color= %c \n",color);
}
void f2(void) {
    color='G';
    printf("f1_color= %c \n",color);
}

int main(void) {
    extern char color;
    printf("main_color= %c \n",color);//B
    f1();//R
    printf("main_color= %c \n",color);//B
    f2();//G
    printf("main_color= %c \n",color);//G
    return 0;
}
*/

/*
#define SIZE 10
#define LENGTH 1000

int main(void) {
    int data_cnt[SIZE+1];
    int data;
    for (int seed=1;seed<11;++seed) {
        printf("seed=%d\n",seed);
        srand(seed);
        for (int i=0;i<=SIZE;++i) data_cnt[i]=0;
        for (int i=0;i<LENGTH;++i) {
            data=rand( )% 10 + 1;
            data_cnt[data]++;
        }
        printf("------\n");
        for (int i=0;i<=SIZE;++i) {
            printf("data_cnt[%d]=%d\n",i,data_cnt[i]);
        }
    }
    return 0;
}
*/

/*
int main(void) {
    int amount;
    printf("Enter amount: ");
    scanf("%d",&amount);
    printf("Enter %d words now: ",amount);
    char** pst=(char**)malloc(amount*sizeof(char*));
    for (int i=0;i<amount;++i) {
        char tmp[100];
        scanf("%s",tmp);
        int len=strlen(tmp);
        char* str=(char*)malloc(len*sizeof(char));
        strcpy(str,tmp);
        pst[i]=str;
    }
    printf("Your words are: \n");
    for (int i=0;i<amount;++i) {
        printf("%s\n",pst[i]);
    }
    free(pst);
    return 0;
}
*/


//13 文件输入输出

/*
#define SIZE 256
int main(int argc, char* argv[]) {
    FILE* fp;
    char line[SIZE];
    char ch;
    if (argc != 3) {
        printf("Usage: %s character filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    else {
        if (strlen(argv[1]) != 1) {
            printf("The second parameter should be a char.\n");
            exit(EXIT_FAILURE);
        }
        if ((fp=fopen(argv[2],"r")) == NULL) {
            printf("Can not open file %s.\n", argv[1]);
            exit(EXIT_FAILURE);
        }
    }
    ch=argv[1][0];
    while (fgets(line,SIZE,fp) != NULL) {
        //char* p=line;
        // while (*p != '\0') {
        //     if (*p++ == ch) {
        //         printf("FOUND %c IN LINE: %s", ch, line);
        //         break;
        //     }
        // }

        char* pch=strchr(line,ch);
        if (pch != NULL) {
            printf("FOUND %c IN LINE: %s", ch, line);
            break;
        }
    }

    fclose(fp);
    return 0;
}
*/

/*
#define BUF_SIZE 512
int main(int argc, char* argv[]) {
    FILE *fsrc,*fdst;
    char buff[BUF_SIZE];
    if (argc != 3) {
        printf("Usage: %s src_file dst_file\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    else {
        if ((fsrc=fopen(argv[1],"rb")) == NULL) {
            printf("Can not open %s.\n", argv[1]);
            exit(EXIT_FAILURE);
        }
        if ((fdst=fopen(argv[2],"wb")) == NULL) {
            printf("Can not open %s.\n", argv[2]);
            exit(EXIT_FAILURE);
        }
    }
    size_t cnt;
    while ((cnt=fread(buff,sizeof(char),BUF_SIZE,fsrc)) > 0) {
        fwrite(buff,sizeof(char),cnt,fdst);
    }
    fclose(fsrc);
    fclose(fdst);

    return 0;
}
*/

/*
#define BUFSIZE 1024
#define SLEN 64

void append(FILE* src, FILE* dst) {
    size_t cnt;
    static char tmp[BUFSIZE];
    while ((cnt=fread(tmp,sizeof(char),BUFSIZE,src)) > 0)
        fwrite(tmp,sizeof(char),cnt,dst);
}

int main(int argc, char* argv[]) {
    FILE *fdst,*fsrc;
    int num=0; //文件数量
    char file_app[SLEN];
    char file_src[SLEN];
    int ch;
    if (argc<3) {
        fprintf(stderr,"Usage: %s dst_file src_file.\n",argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((fdst=fopen(argv[1],"a+")) == NULL) {
        fprintf(stderr,"Can not open %s.\n",argv[1]);
        exit(EXIT_FAILURE);
    }
    if (setvbuf(fdst,NULL,_IOFBF,BUFSIZE) != 0) {
        fputs("Can not create dst buffer.\n", stderr);
        exit(EXIT_FAILURE);
    }

    num=argc-2;
    while (num > 0) {
        if ((fsrc=fopen(argv[argc-num],"r")) == NULL)
            fprintf(stderr,"Can not open %s.\n", argv[argc-num]);
        else {
            if (setvbuf(fdst,NULL,_IOFBF,BUFSIZE) != 0) {
                fputs("Can not create dst buffer.\n", stderr);
                continue;
            }
            append(fsrc,fdst);
            if (ferror(fsrc) != 0) fprintf(stderr,"Error in reading file %s.\n",file_src);
            if (ferror(fdst) != 0) fprintf(stderr,"Error in writing file %s.\n",file_app);
            fclose(fsrc);
            printf("file %s appended.\n",file_src);
            if ( num > 0 ) printf("Next file %s: \n", argv[argc - (--num)]);
            else printf("All appended.\n");
        }
    }
    printf("%d files appended.\n",argc-2);
    rewind(fdst); printf("%s contents: \n",file_app);
    while ((ch = getc(fdst)) != EOF) 
        putchar(ch);
    puts("\nDone displaying.\n");
    fclose(fdst);

    return 0;
}
*/

/*
#define SIZE 256
int str_in(char* st, char* sub) {
    int cnt=0;
    int sub_len=strlen(sub);
    while (*st != '\0' && cnt<sub_len) {
        if (st[cnt]==sub[cnt]) ++cnt;
        else {
            cnt=0;
            ++st;
        }
    }
    if (cnt==sub_len) return 1;
    else return 0;

}

int main(int argc, char* argv[]) {
    FILE* fp;
    char buff[SIZE];
    char* sub_str;
    if (argc < 3) {
        printf("Usage: %s string filename ... \n",argv[0]);
        exit(EXIT_FAILURE);
    }
    sub_str=argv[1];
    if ( (fp=fopen(argv[2],"r")) == NULL) {
        printf("Can not open file %s \n", argv[2]);
        exit(EXIT_FAILURE);
    }
    while (fgets(buff,SIZE,fp) != NULL) {
        //if (str_in(buff,sub_str)) puts(buff);
        if (strstr(buff,sub_str)) puts(buff);
    }

    return 0;
}
*/


//14 结构和其他数据形式

/*
double sum(double a, double b) {
    return a+b;
}
double diff(double a, double b) {
    return a-b;
}
double times(double a, double b) {
    return a*b;
}
double divide(double a, double b) {
    return a/b;
}

int main(void) {
    //double (*pf[4])(double,double) = {sum,diff,times,divide};
    typedef double (*ptype) (double,double);
    ptype pf[4] ={sum,diff,times,divide};
    double ret;
    for (int i=0;i<4;++i) {
        ret=pf[i](10.0,2.5);
        printf("ret=%.3f\n",ret);
    }
}
*/

/*
struct user {
    char fname[15];
    char mname[15];
    char lname[15];
};
struct user_id {
    char sid[30];
    struct user name;
}user_list[5]={
    {"302039823",{"Fname","Mname","Lname"}}
};

void print_user_id(struct user_id list[], int num) {
    for (int i=0;i<num;++i) {
        if (strlen(list[i].sid) < 9) break;
        printf("No %d: %s, ", i+1, list[i].name.lname);
        printf(" %s ", list[i].name.fname);
        if (strlen(list[i].name.mname)>0) printf("%c. ",list[i].name.mname[0]);
        printf("-- %s",list[i].sid);
        printf("\n");
    }
}

int main(void) {
    printf("Test to print struct contents: \n");
    print_user_id(user_list,5);
    return 0;
}
*/

/*
#define LENGTH 10
void transform(double src[], double dst[], int n, double (*pf)(double)) {
    for (int i=0;i<n;++i) {
        dst[i]=pf(src[i]);
    }
}

int main(void) {
    double src[LENGTH],dst[LENGTH];
    for (int i=0;i<LENGTH;++i) {
        src[i]=i;
    }
    transform(src,dst,LENGTH,sin);
    printf("sin transform is: \n");
    for (int i=0;i<LENGTH;++i) {
        printf("dst[%d]=%.1f\n",i,dst[i]);
    }
    printf("\n");

    transform(src,dst,LENGTH,cos);
    printf("cos transform is: \n");
    for (int i=0;i<LENGTH;++i) {
        printf("dst[%d]=%.1f\n",i,dst[i]);
    }
    printf("\n");

    return 0;
}
*/

//15 位操作

/*
int switch_cnt(int n) {
    const static int size=CHAR_BIT*sizeof(int);
    printf("size=%d\n",size);//32
    int sum=0;
    for (int i=0;i<size;++i) {
        if (n & 1) ++sum;
        n >>= 1;
    }
    return sum;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s numerical.\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    int i=atoi(argv[1]);
    printf("The switch bit of %d is %d.\n", i, switch_cnt(i));
    return 0;
}
*/

/*
int rotate_left(int n, int length) {
    const static int size=CHAR_BIT*sizeof(int);
    if (length>size || length<0) {
        printf("Error Length.\n");
        return -1;
    }
    for (int i=0;i<length;++i) {
        if (n & (1<<(size-1))) { //读取将被移出的位，即最高位设置为1.
            n <<= 1;
            n |= 1; //右侧置1
        } else {
            n <<= 1;
        }
    }
    return n;
}

int main(void) {
    int i,length;
    printf("Enter a number and a move bit: \n");
    scanf("%d %d", &i, &length);
    printf("rotate_left(%d,%d)=%d\n",i,length,rotate_left(i,length));

    return 0;
}
*/

//16 C预处理器和C库

/*
#define SHOW2(X,Y) printf(#X "is %d and" #Y "is %d.\n", X, Y)
#define SHOW1(X) printf("name:" #X "; value:%d; address:%p.\n", X, &X)
int main(void) {
    int a=12,b=34;
    int c=56;
    SHOW2(a,b);
    SHOW1(c);
    return 0;
}
*/

/*
#define SIZE 128
void select_rand(int data[], int len, int n) {
    srand((unsigned long)clock());
    printf("Begin to select number: \n");
    int* marks=(int*)malloc(len*sizeof(int));
    int idx;
    while (n>0) {
        idx=rand() % len;
        if (marks[idx] != 0) continue;
        else marks[idx]=1;
        printf("idx=%d, data[idx]=%d\n",idx,data[idx]);
        --n;
    }
}

int main(void) {
    int a[SIZE],number;
    printf("Enter number: \n");
    scanf("%d",&number);
    for (int i=0;i<SIZE;++i) {
        a[i]=i;
    }
    select_rand(a,SIZE,number);
    return 0;
}
*/

/*
void show_array(const double a[], int n) {
    for (int i=0;i<n;++i) {
        printf("%.2lf",a[i]);
    }
    printf("\n");
}

double* new_d_array(int n, ...) {
    va_list ap;
    va_start(ap,n);
    double* a=(double*)malloc(n*sizeof(double));
    for (int i=0;i<n;++i) {
        a[i]=va_arg(ap,double);
    }
    va_end(ap);
    return a;
}

int main(void) {
    double* p1=new_d_array(5, 1.2, 2.3, 3.4, 4.5, 5.6);
    double* p2=new_d_array(4, 100.0, 20.0, 8.08, -1890.0);
    show_array(p1,5);
    show_array(p2,4);
    free(p1);
    free(p2);
    return 0;
}
*/

//17 高级数据表示

/*
#define TSIZE 64

struct film {
    char title[TSIZE];
    int rating;
    struct film* next;
    struct film* pre;
};

char* s_gets(char* st, int n) {
    char* find;
    char* ret_val=fgets(st,n,stdin);
    if (ret_val) {
        find=strchr(st,'\n');
        if (find) *find='\0';
        else while (getchar() != '\n') continue;
    }
    return ret_val;
}

int main(void) {
    struct film* head=NULL;
    struct film *prv,*cur;
    char input[TSIZE];

    //收集并且存储信息
    puts("Enter first film title: ");
    while (s_gets(input,TSIZE) != NULL && input[0] != '\0') {
        cur=(struct film*)malloc(sizeof(struct film));
        if (head == NULL) head=cur;
        else {
            prv->next=cur;
            cur->pre=prv;
        }
        cur->next=NULL;
        strcpy(cur->title,input);
        puts("Enter your rating(0-10): ");
        scanf("%d",&cur->rating);
        while (getchar() != '\n') continue;
        puts("Enter next film title(empty line to stop): ");
        prv=cur;
    }

    //显示电影列表
    if (head==NULL) printf("No data entered.\n");
    else printf("film list: \n");
    cur=head;
    while (cur != NULL) {
        printf("Film: %s Rating: %d\n",cur->title,cur->rating);
        cur=cur->next;
    }

    //逆序显示
    puts("Inverted Film List: ");
    cur=prv;
    while (cur != NULL) {
        printf("Film: %s Rating: %d\n",cur->title,cur->rating);
        cur=cur->pre;
    }

    //释放内存
    cur=head;
    while (cur != NULL) {
        head=cur->next;
        free(cur);
        cur=head;
    }
    printf("Bye!\n");

    return 0;
}
*/

/*
#define MAXSIZE 64
#define TSIZE 64
typedef struct film {
    char title[TSIZE];
    int rating;
    struct film* next;
    struct film* pre;
}Item;
typedef struct {
    Item enteries[MAXSIZE];
    int items;
}List;

void Initialize_List(Item item, List* plist) {
    plist=(List*)malloc(sizeof(List));
    if (!plist) plist->items=0;
    else exit(EXIT_FAILURE);
}

bool IsEmpty_List(const List* plist) {
    return plist->items == 0;
}

bool IsFull_List(const List* plist) {
    return plist->items == MAXSIZE;
}

unsigned int ItemCnt_List(const List* plist) {
    return (unsigned int)plist->items;
}

bool addItem(Item item, List* plist) {
    if (IsFull_List(plist)) return true;
    Copy2Node(item, plist);
    return true;
}

void Traverse(const List* plist, void (*pf)(Item item)) {
    int i=0;
    while (i < plist->items) (*pf)(plist->enteries[i++]);
}

void Empty_List(List* plist) {
    plist->items=0;
}

static void Copy2Node(Item item, List* plist) {
    ++plist->items;
    strcpy(plist->enteries[plist->items-1].title, item.title);
    plist->enteries[plist->items-1].rating = item.rating;
}
*/

/*
int bfind(const int a[], int sz, int dst) {
    int cur,low=0;
    int high=sz-1;
    while (low <= high) {
        cur=(low+high)/2;
        if (dst == a[cur]) return 1;
        if (dst > a[cur]) low=cur+1;
        else high=cur-1;
        if (cur==low) return 0; //单独处理
    }
    return 0;
}
*/







