#include <stdio.h>
#include <string.h>
int main (int argc, char *argv[])
{
    // argc   *argv得到输入的(统计方法 和读取路径)  
    FILE *fp;
    int cnt = 0; // 计数
    int i; 
    if ((fp=fopen(argv[2], "r")) == NULL)
    {
        puts("error!\n");//如果读取的文件为空则 报错并退出 
        return 0;
    }
    if (argv[1][1] == 'w') // 统计单词 
    {
        char s[9999];
        while (fscanf(fp, "%s", s) != EOF)//判断是否为空格 
        {
            cnt ++;
            for ( i = 1; i < strlen(s) - 1; i ++)//判断是否为逗号分割 
                if (s[i] == ',' && s[i - 1] != ',' && s[i + 1] != ',') 
                    cnt ++;
        }
        printf("单词数=%d\n", cnt);
    }
    else if (argv[1][1] == 'c') // 统计字符
    {
        char c;
        while ((c = fgetc(fp)) != EOF) //遍历文件获取字符 
		cnt ++;
        printf("字符数=%d", cnt);
    }
    fclose(fp);
    return 0;
}

