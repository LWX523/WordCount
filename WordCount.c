#include <stdio.h>
#include <string.h>
int main (int argc, char *argv[])
{
    // argc   *argv�õ������(ͳ�Ʒ��� �Ͷ�ȡ·��)  
    FILE *fp;
    int cnt = 0; // ����
    int i; 
    if ((fp=fopen(argv[2], "r")) == NULL)
    {
        puts("error!\n");//�����ȡ���ļ�Ϊ���� �����˳� 
        return 0;
    }
    if (argv[1][1] == 'w') // ͳ�Ƶ��� 
    {
        char s[9999];
        while (fscanf(fp, "%s", s) != EOF)//�ж��Ƿ�Ϊ�ո� 
        {
            cnt ++;
            for ( i = 1; i < strlen(s) - 1; i ++)//�ж��Ƿ�Ϊ���ŷָ� 
                if (s[i] == ',' && s[i - 1] != ',' && s[i + 1] != ',') 
                    cnt ++;
        }
        printf("������=%d\n", cnt);
    }
    else if (argv[1][1] == 'c') // ͳ���ַ�
    {
        char c;
        while ((c = fgetc(fp)) != EOF) //�����ļ���ȡ�ַ� 
		cnt ++;
        printf("�ַ���=%d", cnt);
    }
    fclose(fp);
    return 0;
}

