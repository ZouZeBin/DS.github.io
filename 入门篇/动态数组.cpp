#include <stdio.h>
#include <stdlib.h>
int main()
{
int n1,i;
int *array;
printf("��������Ҫ������һά��̬����ĳ��ȣ�");
scanf("%d",&n1);
array=(int*)calloc(n1,sizeof(int));
for(i=0;i<n1;i++)
{
 printf("%d\t",array[i]);
}
printf("\n");
for(i=0;i<n1;i++)
{
 array[i]=i+1;
 printf("%d\t",array[i]);
}
 free(array);//�ͷŵ�һάָ�� 
return 0;
}
