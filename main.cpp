#include <cstdio>
#include <cmath>
/*
int main() {
    char str1[20],str2[5][10];
    gets(str1);
    for(int i = 0;i < 3; i++)
    {
        gets(str2[i]);
    }
    puts(str1);
    for(int i = 0;i < 3;i++)
    {
        puts(str2[i]);
    }
    return 0;
}*/
//http://codeup.cn/problem.php?cid=100000569
//01
/*
 *题目描述
有一个已排好序的数组，要求输入一个数后，按原来排序的规律将它插入到数组中。

假设数组长度为10，数组中前9个数（这9个数要求从键盘上输入，输入时要满足自小到大的输入顺序）已经按从小到大进行排序。

然后再从键盘上输入一个整数，将此整数插入到前有序的9个数中，使得最终的10个数依然是从小到大有序的。

输入
第一行输入以空格分隔的9个整数数，要求按从小到大的顺序输入。

第二行输入一个整数

输出
从小到大输出这10个数，每个数一行。
样例输入
1 11 21 31 41 51 61 71 81
45
样例输出
1
11
21
31
41
45
51
61
71
81

 */
/*
int main()
{
    int str[10];
    for(int i = 0; i < 9; i++)
    {
        scanf("%d",&str[i]);
    }
    str[9] = pow(10,6);
    int in;
    scanf("%d",&in);
    bool flag = false;
    for(int i = 0; i < 9; i++)
    {
        if(flag)
        {
            printf("%d\n",str[i]);
        }
        else if(in >= str[i] && in <= str[i+1])
        {
            printf("%d\n",str[i]);
            printf("%d\n",in);
            flag = true;
        }
        else
        {
            printf("%d\n",str[i]);
        }

    }
    return 0;
}*/

//02
/*
 * 题目描述
将一个长度为10的整型数组中的值按逆序重新存放。

如：原来的顺序为1,2,3,4,5,6,7,8,9,0，要求改为0,9,8,7,6,5,4,3,2,1

输入
从键盘上输入以空格分隔的10个整数。

输出
按相反的顺序输出这10个数，每个数占一行。
样例输入
1 2 3 4 5 6 7 8 9 0
样例输出
0
9
8
7
6
5
4
3
2
1
 */
/*
int main() {
    int a[10];
    //依次输入十个数字存入数组
    for (int i = 0; i < 10; i++)
    {
        scanf("%d",&a[i]);
    }

    //逆序输出十个数字存入数组
    for(int i = 9; i >= 0; i--)
    {
        printf("%d\n",a[i]);
    }
    return 0;
}
 */

//03
/*
 * 题目描述
按要求输入如下格式的杨辉三角

1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1

最多输出10层

输入
输入只包含一个正整数n，表示将要输出的杨辉三角的层数。
输出
对应于该输入，请输出相应层数的杨辉三角，每一层的整数之间用一个空格隔开
样例输入
5
样例输出
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
 */
/*
int main()
{
    int level;
    scanf("%d",&level);
    int matrix[level][level];

    //将每行的两端都赋值为1
    for(int row = 0; row < level; row++)
    {
        matrix[row][0] = 1;
        matrix[row][row] = 1;
    }
    //打印二维数组
    for(int row = 0; row < level; row++)
    {
        for(int col = 0; col <= row; col++)
        {
            printf("%d ",matrix[row][col]);
        }
        printf("\n");
    }

    //除了端点值，其余数字matrix[i][j] = matrix[i-1][j] + matrix[i-1][j-1]
    for(int row = 2; row < level; row++)
    {
        for(int col = 1; col < row; col++)
        {
            matrix[row][col] = matrix[row-1][col] + matrix[row-1][col-1];
//            printf("row:%d,col:%d--%d--\n",row,col,matrix[row][col]);
        }
    }

    //打印二维数组
    for(int row = 0; row < level; row++)
    {
        for(int col = 0; col <= row; col++)
        {
            printf("%d ",matrix[row][col]);
        }
        printf("\n");
    }


    return 0;
}
 */
//04
/*
 * 题目描述
有一行电文，已按如下规律译成密码：

A-->Z        a-->z

B-->Y        b-->y

C-->X        c-->x

......          ......

即第一个字母变成第26个字母，第i个字母变成第（26-i+1)个字母，非字母字符不变。要求根据密码译回原文，并输出。

输入
输入一行密文
输出
解密后的原文，单独占一行。
样例输入
ZYX123zyx
样例输出
ABC123abc
 */
/*
int main()
{
    int len;
    scanf("%d",&len);
    char s1[len],s2[len];
    scanf("%s",s1);
    printf("%s\n",s1);
    for(int i = 0; i < len; i++)
    {
        if(s1[i] >= 65 && s1[i] <= 77)
        {
            s2[i] = s1[i] + 25 - 2*(s1[i] - 'A');
        }
        else if(s1[i] >= 78 && s1[i] <= 90)
        {
            s2[i] = s1[i] - 25 + 2*('Z' - s1[i]);
        }
        else if(s1[i] >= 97 && s1[i] <= 109)
        {
            s2[i] = s1[i] + 25 - 2*(s1[i] - 'a');
        }
        else if(s1[i] >= 110 && s1[i] <= 122)
        {
            s2[i] = s1[i] - 25 + 2*( 'z' - s1[i]);
        } else
            s2[i] = s1[i];
    }

    //打印明文
    printf("%s\n",s2);


    return 0;
}
 */
//05
/*
 *题目描述
比较两个字符串s1和s2的大小，如果s1>s2，则输出一个正数；若s1=s2，则输出0；若s1<s2，则输出一个负数。

要求：不用strcpy函数；两个字符串用gets函数读入。

例如："A"与"C"相比，由于"A"<"C"，应输出负数，同时由于"A"与"C"的ASCII码差值为2，因此应输出"-2"。

同理："And"和"Aid"比较，根据第2个字符比较的结果，"n"比"i"大5，因此应该输出"5"

输入
输入2行字符串

输出
一个整数，表示这两个字符串 比较的差值，单独占一行。
样例输入
And
Aid
样例输出
5
 */
/*
int main()
{
    int len;
    scanf("%d",&len);
    getchar();
    char str1[len],str2[len];
    gets(str1);
    gets(str2);
    int i;
    for(i = 0; i < len; i++)
    {
        if(str1[i] != str2[i])
        {
            printf("%d\n",str2[i] - str1[i]);
            break;
        }

    }
    if(i == len)
        printf("0\n");
    return 0;
}*/
//06
/*
 * 题目描述
Fibonacci数列的特点：第1,2个数为1,1。从第3个数开始，概述是前面两个数之和。即：

要求输出Fibonacci数列的前20个数。

输入
无
输出
Fibonacci数列的前20个数，每个数占一行。
样例输入
无
样例输出
1
1
2
3
5
8
13
21
34
55
89
144
233
377
610
987
1597
2584
4181
6765
 */
/*
int main()
{
    int m = 1,n = 1;
    int len;
    scanf("%d",&len);
    for(int i = 0; i < len;i++)
    {
        printf("%d\n",m);
        int prem = m;
        m = n;
        n += prem;
    }
    return 0;
}
 */
//07
/*
 * 例题6-3 冒泡排序
时间限制: 1 Sec  内存限制: 12 MB
献花: 265  解决: 239
[献花][花圈][TK题库]
题目描述
从键盘上输入10个整数，用冒泡法对这10个数进行排序（由小到大）。
输入
以空格分隔的10个整数
输出
依次输出排好序的10个整数，每个数占一行。
样例输入
1 3 5 7 9 2 4 6 8 0
样例输出
0
1
2
3
4
5
6
7
8
9

 */
/*
int main()
{
    int a[10];
    for(int i = 0;i < 10;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i = 0;i < 10;i++)
    {
        for(int j = 0; j < 9-i;j++)
        {
            if(a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    for(int i = 0;i < 10;i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
}*/
//08
/*
 * 例题6-4 矩阵转置
时间限制: 1 Sec  内存限制: 12 MB
献花: 225  解决: 209
[献花][花圈][TK题库]
题目描述
将一个2行3列的矩阵（二维数组）行列互换，存储到另一个3行2列的矩阵中。

要求以整型数据为例来解答。

输入
输入2行数据，每行3个整数，以空格分隔。
输出
行列互换后的矩阵，3行，每行2个数据，以空格分隔。
样例输入
1 2 3
4 5 6
样例输出
1 4
2 5
3 6
 */
/*
int main()
{
    int a[2][3];
    int b[3][2];
    for(int i = 0;i < 2;i++)
    {
        for(int j = 0;j < 3;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(int i = 0;i < 2;i++)
    {
        for(int j = 0;j < 3;j++)
        {
            b[j][i] = a[i][j];
        }
    }
    for(int i = 0;i < 3;i++)
    {
        for(int j = 0;j < 2; j++)
        {
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
    return 0;
}*/
//09
/*
 * 例题6-9 字符串求最大值
时间限制: 1 Sec  内存限制: 12 MB
献花: 276  解决: 228
[献花][花圈][TK题库]
题目描述
从键盘上输入3个字符串，求出其中最大者。
输入
输入3行，每行均为一个字符串。

输出
一行，输入三个字符串中最大者。
样例输入
England
China
America
样例输出
England
 */
/*
#include <string.h>
int main()
{
    //存储三个字符串的长度
    int len[3];
    scanf("%d%d%d",&len[0],&len[1],&len[2]);
    int max = 0;
    //max存储长度最大的数
    for(int i = 0;i < 3;i++)
    {
        if(max < len[i])
        {
            max = len[i];
        }
    }
    char maxstr[max];
    //二维数组存储三个字符串
    char str[3][max];
    for(int i = 0;i < 3;i++)
    {
        scanf("%s",str[i]);
    }
    strcpy(maxstr,str[0]);
    printf("%s\n",maxstr);
    for(int i = 1;i < 3;i++)
    {
        if(strcmp(maxstr,str[i]) < 0) strcpy(maxstr,str[i]);
    }
    printf("%s\n",maxstr);
    return 0;
}*/
//
/*
 * 习题7-7 复制字符串中的元音字母
时间限制: 1 Sec  内存限制: 12 MB
献花: 301  解决: 224
[献花][花圈][TK题库]
题目描述
写一个函数，将一个字符串中的元音字母复制到另一个字符串中。在主函数中输入一个字符串，通过调用该函数，得到一个有该字符串中的元音字母组成的一个字符串，并输出。
输入
一个字符串（一行字符）。

输出
该字符串所有元音字母构成的字符串。行尾换行。
样例输入
CLanguage
样例输出
auae
 */
/*
#include <string.h>
void vowels(char s1[],char s2[])
{
    int len = strlen(s1);
    int j =0 ;
    for(int i = 0;i < len;i++)

    {
        if(s1[i] == 'a' || s1[i] == 'A' || s1[i] == 'e' || s1[i] == 'E' || s1[i] == 'i' ||s1[i] == 'I' || s1[i] == 'o' || s1[i] == 'O' || s1[i] == 'u' || s1[i] == 'U')
        {
            s2[j++] = s1[i];
        }
    }
    printf("%s\n",s2);
}

int main()
{
    char s1[20],s2[20];
    scanf("%s",s1);
    vowels(s1,s2);
    return 0;
}*/

/*
 * C语言10.1
时间限制: 1 Sec  内存限制: 32 MB
献花: 252  解决: 233
[献花][花圈][TK题库]
题目描述
输入a和b两个整数，按先大后小的顺序输出a和b。注意请使用指针变量的方式进行比较和输出。

输入
两个用空格隔开的整数a和b。

输出
按先大后小的顺序输出a和b，用空格隔开。
请注意行尾输出换行。

样例输入
5 9
样例输出
9 5
 */
/*
void swap(int* a,int* b)
{
    if(*a < *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}

int main()
{
    int x,y;
    scanf("%d%d",&x,&y);
    swap(&x,&y);
    printf("%d %d\n",x,y);
    return 0;
}*/
/*
 * C语言10.2
时间限制: 1 Sec  内存限制: 32 MB
献花: 244  解决: 195
[献花][花圈][TK题库]
题目描述
输入a、b、c三个整数，按先大后小的顺序输出a、b和c。注意请使用指针变量的方式进行比较和输出。

输入
三个用空格隔开的整数a、b和c。

输出
按先大后小的顺序输出a、b和c，用空格隔开。
请注意行尾输出换行。

样例输入
9 0 10
样例输出
10 9 0
 */
/*
void swap(int* a,int* b)
{
    if(*a < *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}

void sort(int* a)
{
    int maxIndex = 0;
    int max = *a;
    for(int i = 1;i < 3;i++)
    {
        if(max < *a + i)
        {
            max = *a + i;
            maxIndex = i;
        }
    }
    swap(a,a+maxIndex);
    if(*a+1 < *a+2) swap(a+1,a+2);

}

int main()
{
    int a[3];
    scanf("%d%d%d",&a[0],&a[1],&a[2]);
    sort(a);
    printf("%d %d %d\n",a[0],a[1],a[2]);
    return 0;
}*/
/*
 * C语言10.15
时间限制: 1 Sec  内存限制: 32 MB
献花: 227  解决: 161
[献花][花圈][TK题库]
题目描述
输入3个字符串，按从小到大的顺序输出。要求使用指针的方法进行处理。

输入
3行，每行一个用字符串。保证每个字符串的长度不超过20。

输出
按从小到大的顺序输出这3个字符串，每个字符串一行。
请注意行尾输出换行。

样例输入
China
CLOCK
deal
样例输出
CLOCK
China
deal
 */
/*
#include <string.h>

//字符串交换
void swap(char *str1, char *str2)
{
    char temp[21];
    strcpy(temp,str1);
    strcpy(str1,str2);
    strcpy(str2,temp);
}

int main()
{
    char s1[21],s2[21],s3[21];
    scanf("%s",s1);
    scanf("%s",s2);
    scanf("%s",s3);

    if(strcmp(s1,s2) > 0)
        swap(s1,s2);
    if(strcmp(s1,s3) > 0)
        swap(s1,s3);
    if(strcmp(s2,s3) > 0)
        swap(s2,s3);

    printf("%s\n%s\n%s\n",s1,s2,s3);

}*/
/*
#include <string.h>
struct person{
    char name[20];
    int count;
}leader[3] = {"Li",0,"Zhang",0,"Fun",0};
int main()
{
    int times;
    scanf("%d",&times);
    while(times--)
    {
        char in[20];
        scanf("%s",&in);
        for(int i = 0; i < 3;i++)
        {
            if(strcmp(leader[i].name,in) == 0)
                leader[i].count++;
        }
    }
    for(int i = 0;i < 3;i++)
    {
        printf("%s:%d\n",leader[i].name,leader[i].count);
    }
    return 0;
}*/
/*
 * C语言11.2
时间限制: 1 Sec  内存限制: 32 MB
献花: 227  解决: 170
[献花][花圈][TK题库]
题目描述
定义一个结构体student，存储学生的学号、名字、性别和年龄，读入每个学生的所有信息，保存在结构体中，并输出。结构体student的定义如下：
struct student {
    int num;
    char name[20];
    char sex;
    int age;
};
本题要求使用指向结构体数组的指针进行输入和输出。

输入
第一行有一个整数n，表示以下有n个学生的信息将会输入。保证n不大于20。
以后的n行中，每一行包含对应学生的学号、名字、性别和年龄，用空格隔开。保证每一个人名都不包含空格且长度不超过15，性别用M和F两个字符来表示。

输出
有n行，每行输出一个学生的学号、名字、性别和年龄，用空格隔开。
请注意行尾输出换行。

样例输入
3
10101 LiLin M 18
10102 ZhangFun M 19
10104 WangMin F 20
样例输出
10101 LiLin M 18
10102 ZhangFun M 19
10104 WangMin F 20

 */

/*
struct student{
    int num;
    char name[20];
    char sex;
    int age;
}p[21];

int main()
{
    int num,i = 0;
    scanf("%d",&num);
    int storeNum = num;
    while(num--)
    {
        scanf("%d%s %c%d",&(p+i)->num,(p+i)->name,&(p+i)->sex,&(p+i)->age);
        i++;
    }
    for(int i = 0;i < storeNum;i++)
    {
        printf("%d %s %c %d\n",(p+i)->num,(p+i)->name,(p+i)->sex,(p+i)->age);
    }
    return 0;
}
 */
/*
struct {
    int num;
    char name[10];
    char sex;
    char job;
    union{
        int batch;
        char position[10];
    };
}info[21];

int main()
{
    int number;
    scanf("%d",&number);
    for(int i = 0;i < number;i++)
    {
        scanf("%d%s %c %c",&(info+i)->num,(info+i)->name,&(info+i)->sex,&(info+i)->job);
        if((info+i)->job == 's') scanf("%d",&(info+i)->batch);
        else if((info+i)->job == 't') scanf("%s",(info+i)->position);
    }
    //打印输入的结构信息
    for(int i = 0;i < number;i++)
    {
        printf("%d %s %c %c ",(info+i)->num,(info+i)->name,(info+i)->sex,(info+i)->job);
        if((info+i)->job == 's') printf("%d\n",(info+i)->batch);
        else if ((info+i)->job == 't') printf("%s\n",(info+i)->position);
    }
    return 0;
}*/
/*
 * C语言11.8
时间限制: 1 Sec  内存限制: 32 MB
献花: 200  解决: 152
[献花][花圈][TK题库]
题目描述
有10个学生，每个学生的数据包括学号、姓名、3门课程的成绩。读入这10个学生的数据，要求输出3门课程的总平均成绩，以及个人平均分最高的学生的数据（包括学号、姓名、3门课程成绩、平均分数）。

输入
共有10行，每行包含了一个学生的学号（整数）、名字（长度不超过19的无空格字符串）和3门课程的成绩（0至100之间的整数），用空格隔开。

输出
第一行包含了3个实数，分别表示3门课程的总平均成绩，保留2位小数，每个数之后输出一个空格。
第二行输出个人平均分最高的学生的数据，与输入数据格式相同。如果有多位个人平均分最高的学生，输出按照输入顺序第一个最高分的学生数据。
请注意行尾输出换行。

样例输入
101 AAA 80 81 82
102 BBB 83 84 85
103 CCC 86 87 88
104 DDD 89 90 91
105 EEE 92 93 94
106 FFF 80 90 100
107 GGG 85 90 95
108 HHH 80 85 90
109 III 90 91 92
110 JJJ 91 88 87
样例输出
85.60 87.90 90.40
105 EEE 92 93 94

 */
struct stuInfo
{
    int num;
    char name[20];
    int grade1;
    int grade2;
    int grade3;
}stuInfo[15];
int main()
{
    double sum_grade1 = 0, sum_grade2 = 0, sum_grade3 = 0;
    double avg_grade;
    double max = 0;
    int maxIndex = 0;
    for(int i = 0;i < 10;i++)
    {
        scanf("%d%s%d%d%d",&(stuInfo+i)->num,(stuInfo+i)->name,&(stuInfo+i)->grade1,&(stuInfo+i)->grade2,&(stuInfo+i)->grade3);
        sum_grade1 += (stuInfo+i)->grade1;
        sum_grade2 += (stuInfo+i)->grade2;
        sum_grade3 += (stuInfo+i)->grade3;
        avg_grade = ((stuInfo+i)->grade1 + (stuInfo+i)->grade2 + (stuInfo+i)->grade3)/3;
        if(max < avg_grade)
        {
            max = avg_grade;
            maxIndex = i;
        }
    }
    printf("%.2f %.2f %.2f\n",sum_grade1/10,sum_grade2/10,sum_grade3/10);
    printf("%d %s %d %d %d\n",(stuInfo+maxIndex)->num,(stuInfo+maxIndex)->name,(stuInfo+maxIndex)->grade1,(stuInfo+maxIndex)->grade2,(stuInfo+maxIndex)->grade3);
    return 0;
}
