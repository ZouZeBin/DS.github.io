/*题目渊源:
  马踏棋盘问题(又称骑士周游或骑士漫游问题)是算法设计的经典问题之一。

题目要求:
 国际象棋的棋盘为8*8的方格棋盘，现将马放在任意指定的方格中按照马走棋的规则将马进行移动。
 要求每个方格只能进入一次，最终使得马走遍棋盘64个方格。
 
编写代码，
 实现马踏棋盘的操作，要求用1~64来标注马移动的路径
 
 回溯法:
	指导思想很简单，就是一条路走到黑，碰壁了再回来一条
	路走到黑......一般和递归可以很好的搭配使用，还有
	深度优先搜索(DFS)
	
 哈密尔顿路径:
	图G中的哈密尔顿路径指的是经过图G中每个顶点，
	且只经过一次的一条轨迹。如果这条轨迹是一条闭
	合的路径(从起点出发不重复地遍历所有点后仍能
	回到起始点)，那么这条路径称为哈密尔顿回路。
	
--6----7-- 
5--------0 
----马----	
4--------1 
--3----2-- 
*/ 
#include<cstdio>
#include<time.h>
#define X 8
#define Y 8

int chess[X][Y];
//找到基于(x,y)的下一个可走的位置 
int nextxy(int *x,int *y,int count){
	switch(count){
		case 0://3 
			if(*x+2<=X-1&&*y-1>=0&&chess[*x+2][*y-1]==0){
				*x+=2;
				*y-=1;
				return 1;
			}
			break;
		case 1:
			if(*x+2<=X-1&&*y+1<=Y-1&&chess[*x+2][*y+1]==0){
				*x+=2;
				*y+=1;
				return 1;
			}
			break;
		case 2:
			if(*x+2<=X-2&&*y+1<=Y-1&&chess[*x+2][*y-1]==0){
				*x+=2;
				*y+=1;
				return 1;
			}
			break;
		case 3:
			if(*x+1<=X-1&&*y+2<=Y-1&&chess[*x+1][*y+2]==0){
				*x+=1;
				*y+=2;
				return 1;
			}
			break;
		case 4:
			if(*x-2>=0&&*y-1>=0&&chess[*x-2][*y-1]==0){
				*x-=2;
				*y-=1;
				return 1;
			}
			break;	
		case 5:
			if(*x-2>=0&&*y+1<=Y-1&&chess[*x-2][*y+1]==0){
				*x-=2;
				*y+=1;
				return 1;
			}
			break;
		case 6:
			if(*x-1>=0&&*y-2>=0&&chess[*x-1][*y-2]==0){
				*x-=1;
				*y-=2;
				return 1;
			}
			break;
		case 7:
			if(*x-1>=0&&*y+2<=Y-1&&chess[*x-1][*y+2]==0){
				*x-=1;
				*y+=2;
				return 1;
			}
			break;
		default:
			break;
	} 
	return 0;
}
void print() {
	int i,j;
	for(i=0;i<X;i++){
		for(j=0;j<Y;j++){
			printf("%2d\t",chess[i][j]);
		}
		printf("\n");
	}	
	printf("\n");
}
//深度优先遍历棋盘
//(x,y)为位置坐标
//tag为标记变量 每走一步tag+1 
int TravelChessBoard(int x,int y,int tag){
	int x1=x,y1=y,flag=0,count=0;
	chess[x][y]=tag;
	
	if(X*Y==tag){
		//打印棋盘 迭代
		print();
		return 1; 
	}
	flag=nextxy(&x1,&y1,count);//指针的引用	
	while(0==flag&&count<7){//尝试下一个新的情况 
		count++;
		flag=nextxy(&x1,&y1,count);
	} 
	//找到马的下一个可走坐标 (x1,y1)如果找到flag=1，否则为0
	while(flag){
		if(TravelChessBoard(x1,y1,tag+1)){
			return 1;
		}
		//继续找，找到马的下一步可走的坐标(x1,y1),找到flag=1，否则为0 
		x1=x;
		y1=y;
		count++;
		flag=nextxy(&x1,&y1,count);//指针的引用	
		while(0==flag&&count<7){//尝试下一个新的情况 
			count++;
			flag=nextxy(&x1,&y1,count);
		} 
		
	} 
	if(0==flag){//没找到，进行新的情况的考虑 
		chess[x][y]=0;
	} 
	return 0; 
} 



int main(){
	int i,j;
	clock_t start,finish;
	start=clock();
	for(int i=0;i<X;i++){
		for(int j=0;j<Y;j++){
			chess[i][j]=0;
		}
	}
	if(!TravelChessBoard(2,0,1)){
		printf("失败！");
	}
	finish=clock();
	printf("本次耗时：%f秒\n\n",(double)(finish-start)/CLOCKS_PER_SEC);
	return 0;
}















