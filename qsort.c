#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
void showarr(int* arr,int len)
{
	int i = 0;
	for(;i<len;i++)
	{
        printf("%d ",arr[i]);
	}
	printf("\n");
}
int intcmp(void* x,void* y)
{
	int* _x = (int*)x;
	int* _y = (int*)y;
	return *_x - *_y;
}

void maopao(void* data,int num,int width,int(*cmp)(void*,void*))
{
	char* start = (char*)data;
	int i = 0;
	assert(data);
	for(;i<num-1;i++){
        int flag = 0;
		int j = 0;
		for(;j<num-i-1;j++){
			//int k = 0;
			if( (cmp(start,start+width))>0 ){
				int k = 0;
				flag = 0;
   				for(;k<width;k++){
				   start[k]^=start[k+width];
				   start[k+width]^=start[k];
				   start[k]^=start[k+width];
				}
				
   			}
			start+=width;
		}
		if(!flag){break;}
	}
}
int main()
{
	int arr[] = {6,8,6,4,7,5,3,2,9};
	int len = sizeof(arr)/sizeof(arr[0]);
	showarr(arr,len);
    maopao(arr,len,sizeof(arr[0]),intcmp);
	showarr(arr,len);
	system("pause");
	return 0;
}