#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char input[10];
	system("shutdown -s -t 10");
flag:
	printf("���룺���ػ�����Ȼ�͹ػ�\n");
	scanf("%s",input);
	if(strcmp(input,"���ػ�")==0)
	{
		system("shutdown -a");
	}
	else
	{
		goto flag;
	}
	return 0;

}
