#include<stdio.h>
#include<string.h>
void fun(char* a,char* b)
{
    int i,j,k=0;
    for(i=strlen(a)-1;i>=0;i--)
    {
        if(a[i]==' ')
        {
            for(j=i+1;a[j]&&a[j]!=' ';j++)
            {
                b[k++] = a[j];
            }
            b[k++] = ' ';
        }
    }
    for(i=0;a[i]!=' ';i++)
        b[k++] = a[i];
    b[k] = '\0';
}
int main()
{
    char a[20]="student a am i",b[20];
    fun(a,b);
    printf("%s",b);
	return 0;
}