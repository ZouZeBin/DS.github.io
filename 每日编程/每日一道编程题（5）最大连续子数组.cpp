/*（青蛙题精选）在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。
	但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？

	例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
	各位小皮皮有什么好的解法呢？(子向量的长度至少是1)
*/ 

#include<iostream>
using namespace std;


int FindGreatestSumOfSubArray (int array[],int size) {
	int max = 0, sum = 0;
	for(int i = 0; i < size; ++i) {
		sum += array[i];
		//累加
		if(sum > max)
			max = sum;
		//
		if(sum < 0) sum = 0;
		//当sum小于0时，就不要在继续往后累加了，因为这样只会越来越小。
	}
	return max;
}

int main(){
	int array[]={6,-3,-2,7,-15,1,2,2};
	int size=8;
	cout<<FindGreatestSumOfSubArray (array,size); 
	return 0;
}
 
