#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100;
//heapΪ�� nΪԪ�ظ��� 
int heap[maxn],n=10;

//��heap������[low,high]��Χ�½������µ���
void downAdjust(int low,int high){
	int i=low,j=i*2;//iΪҪ�����Ľڵ㣬��jΪ��������
	while(j<=high){//���ں��ӽڵ� 
		//�Һ��Ӵ���,���Һ���ֵ�������� 
		if(i+1<=high&&heap[j+1]>heap[j]){
			j+=1;//j�洢�Һ����±� 
		} 
		
		//������������Ȩֵ����Ԥ�����ڵ�i
		if(heap[j]>heap[i]){
			swap(heap[j],heap[i]);//�������Ȩֵ�ĺ���
			i=j;//����iΪԤ�����ڵ㣬jΪi������
			j=i*2; 
		}else{
			break;//����Ȩֵ���ȵ����ڵ�iС 
		}	
	} 
} 



//����  ʱ�临�Ӷ�O(n) 
void createHeap(){
	for(int i=n/2;i>=1;i--){
		downAdjust(i,n);
	}
} 

//ɾ���Ѷ�Ԫ��
void deleteTop(){
	heap[1]=heap[n--];//���һ��Ԫ�ظ��ǶѶ�������Ԫ�ظ���-1
	downAdjust(1,n);//���µ�������Ԫ�� 
} 

//��heap������[low,high]���Ͻ��е���
void upAdjust(int low,int high){
	int i=high,j=i/2;//iΪԤ�����ڵ㣬jΪ����
	while(j>=low){//���״��� 
		//����ȨֵС��Ԥ�����ڵ�i
		if(heap[j]<heap[i]){
			swap(heap[j],heap[i]);//�������׺�Ԥ�����ڵ�
			i=j;//����iΪԤ�����ڵ㣬jΪi�ĸ��׽ڵ� 
			j=i/2; 
		}else{
			break;//���׽ڵ�Ȩֵ����Ԥ�����ڵ㣬�������� 
		} 
	} 
} 


//���Ԫ��
void insert(int x){
	heap[++n]=x;
	upAdjust(1,n);
} 

//������
void heapSort(){
	createHeap();//����
	for(int i=n;i>1;i--){//����ö�٣�ֱ������ֻ��һ��Ԫ�� 
		swap(heap[i],heap[1]);
		downAdjust(1,n-1);//�����Ѷ� 
	} 
} 

void print(){
	for(int i=1;i<=n;i++){
		printf("%d ",heap[i]);
	}
}
int main(){
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	heapSort();
	print();
	return 0;
} 








 
