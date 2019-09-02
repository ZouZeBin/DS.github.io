#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100;
//heap为堆 n为元素个数 
int heap[maxn],n=10;

//对heap数组在[low,high]范围下进行向下调整
void downAdjust(int low,int high){
	int i=low,j=i*2;//i为要调整的节点，而j为他的左孩子
	while(j<=high){//存在孩子节点 
		//右孩子存在,且右孩子值大于左孩子 
		if(i+1<=high&&heap[j+1]>heap[j]){
			j+=1;//j存储右孩子下标 
		} 
		
		//如果孩子中最大权值大于预调整节点i
		if(heap[j]>heap[i]){
			swap(heap[j],heap[i]);//交换最大权值的孩子
			i=j;//保持i为预调整节点，j为i的左孩子
			j=i*2; 
		}else{
			break;//孩子权值均比调整节点i小 
		}	
	} 
} 



//建堆  时间复杂度O(n) 
void createHeap(){
	for(int i=n/2;i>=1;i--){
		downAdjust(i,n);
	}
} 

//删除堆顶元素
void deleteTop(){
	heap[1]=heap[n--];//最后一个元素覆盖堆顶，并让元素个数-1
	downAdjust(1,n);//向下调整顶堆元素 
} 

//对heap数组在[low,high]向上进行调整
void upAdjust(int low,int high){
	int i=high,j=i/2;//i为预调整节点，j为父亲
	while(j>=low){//父亲存在 
		//父亲权值小于预调整节点i
		if(heap[j]<heap[i]){
			swap(heap[j],heap[i]);//交换父亲和预调整节点
			i=j;//保持i为预调整节点，j为i的父亲节点 
			j=i/2; 
		}else{
			break;//父亲节点权值大于预调整节点，调整结束 
		} 
	} 
} 


//添加元素
void insert(int x){
	heap[++n]=x;
	upAdjust(1,n);
} 

//堆排序
void heapSort(){
	createHeap();//建堆
	for(int i=n;i>1;i--){//倒着枚举，直到堆中只有一个元素 
		swap(heap[i],heap[1]);
		downAdjust(1,n-1);//调整堆顶 
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








 
