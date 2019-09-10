
//用栈实现...
#include <iostream>
#include <cstdio>
using namespace std;
void initerjing(int A[],int n)//初始化A
{
	int i;
	for(i=0;i<n;i++)
	{
		A[i]=0;
		A[2*n-i-1]=1;
	}
}
void adderjing(int A[],int n)//进位
{
	int i=n;
	if(n>=1)
	{
		A[i]++;
		if(A[i]==2)
		{
			A[i]%=2;
			adderjing(A,n-1);
		}
	}
}
bool real(int A[],int n)//判断是否符合条件
{
	int i,count1=0,count2=0;
	for(i=0;i<2*n;i++)
	{
		if(A[i]==0)
			count1++;
		else
			count2++;
		if(count2>count1)
			return false;
	}
	if(count1==count2)
		return true;
	return false;
}
bool breakdown(int A[],int n)//退出
{
	int i,j = 0;
	for(i=0;i<2*n;i+=2)
	{
		if(A[i]==0&&A[i+1]==1)
			j++;
	}
	if(j == n)
		return true;
	else 
		return false;
}
struct SqStack{//定义栈
	int *base;
	int *top;
	int size;
};
void initstack(SqStack &S,int size)//初始化栈
{
	S.base=(int *)malloc(size *sizeof(int) );
	S.top = S.base ;
	S.size=size;
}
void push(SqStack &S,int &e)//压栈
{
	*S.top++=e;
}
int pop(SqStack &S,int &e)//出栈
{
	e=*--S.top ;
	return e;
}
int main()
{
	int n,i,size=10,e,k;
	int A[20];
	SqStack S;
	cout<<"请输入车厢的长度："<<endl;
	while(cin>>n,n!=0)
	{
	initerjing(A,n);
		initstack(S,size);
		for(i=0;i<2*n;i++)
			{	
				k=i+1;
				if(A[i]==0)
					push(S,k);
				else
				{
					pop(S,e);
					cout<<e<<' ';
				}			
			}cout<<endl;	
		while(n!=1)
		{			
			adderjing(A,2*n-2);
			if(real(A,n))
			{
				k=1;
				for(i=0;i<2*n;i++)
				{					
					if(A[i]==0)
					{
						push(S,k);
						k++;
					}
					else
					{
						pop(S,e);
						cout<<e<<' ';
					}
				}cout<<endl;		
			}
			if(breakdown(A,n))
				break;	
		}
	}
	return 0;

}
