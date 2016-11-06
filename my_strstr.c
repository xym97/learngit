int main()
{
	char* str1 = "hello_bit";
	char* str2 = "o_b";
	char* my_strstr(char* dest,char* src);
	char* ret = my_strstr(str1, str2);
	printf("mystrstr result is:%s",ret);
	system("pause");
	return 0;
}

char* my_strstr(char* dest,char* src)
{   
    
	char* s1 = dest;
	char* s2 = src;
	assert(dest);assert(src);
  while(*s1)
  {
	s1 = dest;
	s2 = src;
	while((*s1!='\0')&&(*s2!='\0'))
	{
        
		if(*s1++ == *s2++)
		{
			;
		}
		else
		{
			dest++;
			break;
		}
	}
	if(*s2=='\0')
	{
		return dest;
		//return s1
	}
  }
}