#include<stdio.h>
#include<windows.h>
void PaiXu_print(int *arr,int le)
{
    int i = 0;
	int j = 0;
	for(;i<le;i++){
		for(j=0;j<le-i-1;j++){
			if(arr[j]>arr[j+1]){
                 arr[j]^=arr[j+1];
                 arr[j+1]^=arr[j];			
  				 arr[j]^=arr[j+1];			
   			}
	    }
	}
	
}

int main()
{
	int arr[] = {2,8,5,9,4,7,1,6,3};
	int len = sizeof(arr)/sizeof(arr[0]);
	int i = 0;
	//void PaiXu_print(int *arr,int len);
	PaiXu_print(arr,len);
	printf("small to big:");
	for(;i<len;i++)
	printf("%d",arr[i]);
	system("pause");
	return 0;
	
}
