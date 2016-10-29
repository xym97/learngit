#include<stdio.h>
#include<string.h>
#define assert
int main()
{   
	char dest[12];
	char src[] = "hello_bit";
	int i = 0;
	void my_strcmp(char* dest ,const char* src);
	my_strcmp(dest,src);
	printf("%s",dest);
	return 0;
}

  void my_strcmp(char* dest ,const char* src)
 {
    assert(dest!=NULL);
	assert(src!= NULL);
	/*while(*src!='\0')
	{
       *dest = *src;
	   dest++;
	   src++;
	}*/
	while(*dest++ = *src++)
	{
         ;
	}
	*dest = '\0';
 }