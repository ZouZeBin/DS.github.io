/*17�㷨ʵ���� 6.4 ���ŷ����������
	 ����������
 ���� n ���˿�ͬʱ�ȴ�һ����� 
 �˿� i ��Ҫ�ķ���ʱ��Ϊ t�� 1<i<n�� 
 Ӧ��ΰ��� n ���˿͵ķ������ ����ʹƽ���ȴ�ʱ��ﵽ��С�� 
 ƽ���ȴ�ʱ���� n ���˿͵ȴ�����ʱ����ܺͳ��� n��
	
	ʵ������
 ���ڸ����� n ���˿���Ҫ�ķ���ʱ�䣬 �������ŷ������

	�������룺
 ���ļ� input.txt �����������ݡ� �� 1 ���������� n�� ��ʾ�� n ���˿͡� 
 ������ 1 ���У��� n ���������� ��ʾ n ���˿���Ҫ�ķ���ʱ�䡣
	
	��������
�����������Сƽ���ȴ�ʱ��������ļ� output.txt �С�
�����ö���ҵ����ԭ�� ������һ�������㷨���˿Ͱ�����ʱ���С�������򡣣�
Դ�������£�
1�� ���ŷ����������.cpp*/ 
//ʹ��ѡ������
#include<stdio.h>
typedef int Item;
#define MaxSize 50
#define less(A,B) (A<B)
#define eq(A,B) (!less(A,B) && !less(B,A))
#define swap(A,B) {Item t=A;A=B;B=t;}
#define compswap(A,B) {if(less(B,A)) swap(A,B);}
int T[MaxSize+1];
int mini(Item a[],int i,int r)
{ 
	int j,min=i;
	for(j=i+1;j<=r;j++)
	if(less(a[j],a[min])) min=j;
	return min;
}

void selection(Item a[],int l)//ѡ������
{ 
	int i,j;
	for(i=0;i<l;i++)
	{
		j=mini(a,i,l);
		swap(a[i],a[j]);
	}
}

void main()
{ 
	int i,N;
	double WTime=0,STime=0;
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	printf("\n%d ���˿ͷֱ���Ҫ�ķ���ʱ��Ϊ�� \n",N);
	for (i=1; i<=N; i++) scanf("%d",&T[i]);
	for (i=1; i<=N; i++)
		printf("%d,",T[i]);
	selection(T,N);
	printf("\n\n ���ն���ҵ����ԭ������֮��ʱ������Ϊ�� \n");
	
	for (i=1; i<=N; i++) printf("%d,",T[i]);
	for (i=1; i<=N; i++) STime+=T[i];
	for(i=1; i<N; i++) T[i+1]+=T[i];
	for(i=1; i<N; i++) WTime+=T[i];
	STime+=WTime;
	WTime/=N;
	STime/=N;
	printf("\n\n ����ƽ����Ҫ����ʱ��Ϊ�� %f\n",STime);
	printf("\n ��Сƽ���ȴ�ʱ��Ϊ�� %f\n",WTime);
	freopen("output.txt", "w", stdout);
	printf("%f %f",STime,WTime);
}

