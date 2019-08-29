/*
题目大意： 
给定一堆字母，存储在链表的结点中，同时给定两个单词的开始地址，
如果两个单词具有相同的后缀，那么链表将复用该后缀，请找出具有
相同后缀的第一个结点的地址 。

解题思路： 常规的做法是把输入的结点，按照地址进行构建单词链表，
然后从后往前进行比较，得到最后一个不相同的点的地址即可 。
但是这种方法要考虑边界情况，比如-1的处理，比如单词从一开头就是重复的等等。
　　
但这里可以用一种投机取巧的方法——从开始地址开始构建结点，
如果结点在两个单词中均出现，那么必定会被访问两次，那么我
们统计每个结点在构建的时候的访问次数，第一个超过1次的结点
必定为相同后缀的开始结点，这样我们只需要从开始地址遍历链表即可，

*/ 
#include<cstdio>
#include<cstring>
const int maxn=100010;
struct NODE{
	char data;//数据域
	int next;//指针域
	bool flag;//节点是否在第一条链表中出现 
}node[maxn];
int main(){
	for(int i=0;i<maxn;i++){
		node[i].flag=false;
	}
	int s1,s2,n;//s1,s2分别是两条链表的首地址
	printf("两个链表的首地址和节点个数\n"); 
	scanf("%d%d%d",&s1,&s2,&n);
	int address,next;//节点地址与后继地址
	char data;//数据
	for(int i=0;i<n;i++){
		scanf("%d %c %d",&address,&data,&next);//使用%c可以读入空格 
		node[address].data=data;
		node[address].next=next;
	} 
	int p;
	for(p=s1;p!=-1;p=node[p].next){
		node[p].flag=true;//枚举第一条链表中所有节点，出现次数为1 
	}
	for(p=s2;p!=-1;p=node[p].next){
		//找到第一个已经在第一条链表中出现的节点
		if(node[p].flag==true) break; 
	} 
	
	if(p!=-1){//如果第二条链表还没到达结尾，说明找到了共用节点
		printf("%05d\n",p); //不足5位高位补0 
	}else{
		printf("-1\n");
	}
	return 0;
}
