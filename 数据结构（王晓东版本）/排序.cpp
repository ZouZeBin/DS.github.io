#define less(A,B)(key(A)<key(B))	//A<B 
#define eq(A,B)(!less(A,B)&&!less(B,A))  //A=B
#define swap(A,B){int t=A;A=B;B=t;} //����A,B 
#define compswap(A,B) if(less(B,A)) swap(A,B);//��B<A������A,B 
#include <cstdio>




void BubbleSort(int a[], int n)
{// ð������
   for (int i = n; i > 1; i--)
     for (int j = 0; j < i - 1; j++)
       if (a[j] > a[j+1])
          swap(a[j],a[j+1]);
     }
	 
	 
void InsertionSort(int a[], int n)
{// ֱ�Ӳ��������㷨
   int i,j;
   int temp;
   for (i=1; i<n; i++)
   {
      temp = a[i];
      j=i-1;
      while(temp<a[j]&&j>=0)
      {
	 a[j+1]=a[j];
	 j--;
      }
      a[j+1]=temp;
   }
}

void Binary_InsertonSort(int a[],int n){
	//���ֲ��������㷨 �����⣿ 
	int i,j,s,m,k;
	int x;
	for(i=1;i<n;i++){
		x=a[i];
		s=0;// ��λ�����±� 
		j=i-1;//���λ�����±� 
		while(s<=j){
			m=(s+j)/2;
			if(x<a[m]) j=m-1;
			else s=m+1;
		}
		for(k=i-1;k>=s;k--){
			a[k+1]=a[k];
			a[s]=x;
		}
	}
}

//void ShellSort(a[],int n,int increment[],int incresize){
	//����������increment[]�Գ���Ϊn��Ԫ��a[]��ϣ������
//	int i,j.incr;
//	int tmp;
//	for(int n=0;n<increasize;n++){
//		//���������н��ж���������
//		incr=increment[n];
//		for(i=incr;i<n;i++){
//			//�Զ�������н��в�������
//			//��a[i]�������������ӱ���
//			if(a[i]<a[i-incr]){
//				tmp=a[i];//tmp�����������Ԫ��
//				//�����������ӱ����Ҳ���λ��
//				//�ڸ�λ�ÿ�ʼ���ӱ��е�Ԫ�����κ���
//				for(j=i-incr;j>0&&tmp<a[j];j-=incr){
//					a[j+incr]=a[j];
//				} 
//				a[j+incr]=tmp;//��������Ԫ�� 
//			} 
//		} 
//	} 
//} 

void Print(int a[],int b){//��ӡ 
		for(int i=0;i<b;i++){
		printf("%d ",a[i]);
	}
}

int main(){
	int a[]={0,6,2,43,5,26,7,8,16};
	int b=9;
	//BubbleSort(a,b);
	//InsertionSort(a,b);
	Binary_InsertonSort(a,b);
	Print(a,b); 
//	for(int i=0;i<b;i++){
//		printf("%d ",a[i]);
//	}
	return 0;
}
