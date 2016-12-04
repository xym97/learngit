#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
void showarr(int* arr,int len)
{
	int i = 0;
	assert(arr);
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
void maopao(void* data,int num,int width,int(*cmp)(void*,void*),void* dataend)
{
	//int i = 0;
	//assert(data);
	//for(;i<num-1;i++){
 //       int flag = 0;
	//	int j = 0;
	//    char* start = (char*)data;
 //  		for(;j<num-1-i;j++){
	//		if( (cmp(start,start+width))>0 ){
	//			int k = 0;
	//			flag = 1;
 //  				for(;k<width;k++){
	//			   start[k]^=start[k+width];
	//			   start[k+width]^=start[k];
	//			   start[k]^=start[k+width];
	//			}
	//			//flag = 1;
 //  			}
	//		start+=width;
	//	}
	//	if(!flag){break;}
	//}
	int pivotkey = 0;
	int* start = (int*)data;
    int* end = (int*)(dataend);
	assert(data);
	pivotkey = *start;
	while(start<end){
	     while(start<end && *end>=pivotkey)
			 --end;
		 *start = *end;
	     while(start<end && *end<=pivotkey)
			 ++start;
		 *end = *start;
	}
    //*start = *((int*)data);
	//return strat
}
int main()
{
	//int arr[] = {15,8,6,56,7,9,12,4,2,};
	int arr[] = {8,5,7,4,2,9,6,3,1}; 
	int len = sizeof(arr)/sizeof(arr[0]);
	showarr(arr,len);
    maopao(arr,len,sizeof(arr[0]),intcmp,arr+len-1);
	showarr(arr,len);
	system("pause");
	return 0;
}