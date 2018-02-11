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
}