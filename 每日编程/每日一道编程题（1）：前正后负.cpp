/*(2018吉林大学941)一个长度为 n 的数组由负数、0、正数组成。
编写函数，将其重新排序为前段都是负数，后段均为非负数的结构。
要求时间复杂度为 O(n)。  
解答：时间复杂度O(n)，空间复杂度O(n)。*/ 

/*第一步：写明算法思路 
	使用两个指针，分别指向顺序表的头和尾
	从前至后遍历顺序表
	如果：该节点为负数 将其与头指针交换，头指针指向下一个节点，从交换的后一个节点开始遍历
		  该节点为0，什么都不做
		  该节点为正数，将其与尾指针交换，尾指针指向前一节点，从交换前的节点指针处开始遍历
		  终止条件：当元素个数等于数组长度时，结束循环*/

#include<iostream>
using namespace std;

void sort(int A[],int length){//输入：数组A[],数组长度length 
	int head,rear,count;//头尾指针 count为计算比较的元素个数
	head=0;count=0; 
	rear=length-1;//初始化
	for(int i=head;count<length;){//中止条件 
		if(A[i]>0){//如果该节点为正数，将其与尾指针交换
			int temp;
			temp=A[i];
			A[i]=A[rear];
			A[rear]=temp; 
			rear--;
			count++;//计数加一 
		}
		if(A[i]==0){//如果该节点为0，什么都不做，继续遍历 
			i++;
			count++;
		}
		if(A[i]<0){//如果节点为负数，将其与头指针交换 
			int temp;
			temp=A[i];
			A[i]=A[head];
			A[head]=temp; 
			head++;
			i++;
			count++;//计数加一 
		} 
		 
	} 
}
int print(int A[],int length){
	int n=length;
	for(int i=0;i<n;i++){
		cout<<i<<':'<<A[i]<<endl;
	}
}
int main(){
	int A[]={1,-2,-3,4,0,-1,2,3,5,-2};
	int length=10;
	sort(A,length);
	print(A,length);
	return 0;
} 
