#include <stdio.h> 
#include <stdlib.h> 
int main() 
{ 
	int n1,n2; 
	int **array,i,j; 
	
	printf("��������Ҫ�����Ķ�̬����ĵ�һά���ȣ�");
	scanf("%d",&n1);
	
	printf("��������Ҫ�����Ķ�̬����ĵڶ�ά���ȣ�");
	scanf("%d",&n2); 
	
	array=(int**)malloc(n1*sizeof(int*)); //��һά �� 
	
	for(i=0;i<n1; i++) 
	{ 
		array[i]=(int*)malloc(n2* sizeof(int));//�ڶ�ά �� 
	}
	
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++) 
		{ 
			array[i][j]=i*n2+j+1; 
			printf("%d\t",array[i][j]); 
		} 
	printf("\n");
	}
	
	for(i=0;i<n1;i++) 
	{ 
		free(array[i]);//�ͷŵڶ�άָ�� 
	} 

	free(array);//�ͷŵ�һάָ�� 
	return 0; 
}


