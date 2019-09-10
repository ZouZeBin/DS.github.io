/*算法实验题 2.2 条形图轮廓问题
 	问题描述：
	在 x 轴上水平放置着 n 个条形图。条形图轮廓是消去这 n 个条形图的隐藏线后得到的图
	形。 每个条形图由 3 元组（Li， Hi， Ri） 表示。
	Li、 Ri 分别表示条形图左右竖线的x坐标值，
	Hi 为条形图的高度。 
	条形图轮廓可用轮廓向量（v1， v2， ……vm） 表示。 
	
	当 i 为奇数时，vi 表示条形图轮廓中一条竖线的 x 坐标值， 
	当 i 为偶数时，vi 表示条形图轮廓中一条横线的高度。
	
 	实验任务：
	对于给定的 n 个条形图， 计算其条形图轮廓。
 
 	数据输入：
	由文件 input.txt 给出输入数据。 
	每行有 3 个正整数（Li， Hi， Ri）， 
	Li、 Ri 分别表示条形图左右竖线的 x 坐标值， Hi 为条形图的高度。
 
 	结果输出：
	将计算出的条形图轮廓向量输出到文件 output.txt。
	源程序如下：
	1、 条形图轮廓.cpp*/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LBound (-3000)//左边界 
#define UBound 3000	//右边界 
#define Cod2Idx(x) ((x)-LBound)
#define Size Cod2Idx(UBound+1)//SIZE=UBound-LBound+1 宽度
 
int main()
{
	int hs[Size], n;
	int i, l, r, h, i0, i1;
	memset(hs, 0, sizeof(*hs) * Size);
	//内存填充命令， 使用"0" 填充 hs 大小的 SIZE 个内存单元
	printf("输入条形图的个数： \n");
	scanf("%d", &n);
	for (i0=UBound, i1=LBound; n>0; n--)
	{ 
		printf("输入条形图的左边界的坐标、 条形图的高度、 右边界的坐标， 以空格隔开： \n");
		scanf("%d %d %d", &l, &h, &r);
		if (l < i0) i0 = l;//如果输入值低于左边界值，将其赋值为左边界 
		if (r > i1) i1 = r;//如果大于右边界，将其赋为右边界 
		for (i=l; i<r; i++)
			if (hs[Cod2Idx(i)] < h)//？不懂 
			hs[Cod2Idx(i)] = h;
	}
	printf("\n 消边后的条形图边界如下： \n");
	for (i=i0, h=0; i<i1; i++)
	if (hs[Cod2Idx(i)] != h)
		printf("%d %d ", i, h=hs[Cod2Idx(i)]);
	printf("%d %d\n", i, 0);
	return 0;
}

