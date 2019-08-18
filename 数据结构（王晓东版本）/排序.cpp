#define less(A,B)(key(A)<key(B))	//A<B 
#define eq(A,B)(!less(A,B)&&!less(B,A))  //A=B
#define swap(A,B){int t=A;A=B;B=t;} //交换A,B 
#define compswap(A,B) if(less(B,A)) swap(A,B);//当B<A，交换A,B 
#include <cstdio>




void BubbleSort(int a[], int n)
{// 冒泡排序
   for (int i = n; i > 1; i--)
     for (int j = 0; j < i - 1; j++)
       if (a[j] > a[j+1])
          swap(a[j],a[j+1]);
     }
	 
	 
void InsertionSort(int a[], int n)
{// 直接插入排序算法
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
	//二分插入排序算法 有问题？ 
	int i,j,s,m,k;
	int x;
	for(i=1;i<n;i++){
		x=a[i];
		s=0;// 首位数组下标 
		j=i-1;//最高位数组下标 
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
	//按增量序列increment[]对长度为n的元素a[]做希尔排序
//	int i,j.incr;
//	int tmp;
//	for(int n=0;n<increasize;n++){
//		//按递增序列进行多遍插入排序
//		incr=increment[n];
//		for(i=incr;i<n;i++){
//			//对多个子序列进行插入排序
//			//将a[i]插入有序增量子表中
//			if(a[i]<a[i-incr]){
//				tmp=a[i];//tmp用来保存插入元素
//				//在有序增量子表中找插入位置
//				//在该位置开始将子表中的元素依次后移
//				for(j=i-incr;j>0&&tmp<a[j];j-=incr){
//					a[j+incr]=a[j];
//				} 
//				a[j+incr]=tmp;//插入排序元素 
//			} 
//		} 
//	} 
//} 

void Print(int a[],int b){//打印 
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
