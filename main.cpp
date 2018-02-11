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