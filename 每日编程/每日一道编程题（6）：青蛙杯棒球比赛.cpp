/*
（青蛙题精选）：.青蛙（frog）杯第一届棒球比赛开赛啦。 
你现在是一名记分员，输入一个字符串数组（比赛记录情况），按如下规则计分：
	1. 如果该字符串是数字：代表当轮比赛的得分情况。 
	2. 如果该字符串是“+”： 代表当轮比赛得分情况为上两轮之和。 
	3. 如果该字符串是“C”： 代表上一轮得分无效。 
	4. 如果该字符串是“D”:  代表当轮比赛得分为上一轮得分的两倍。 
你需要得出最后总的得分情况并返回结果。 
函数：int frogPoints(string[ ] ops,int round)  //ops 为字符串数组，round 代表总共的比赛轮数 
例子： 
输入： 
	round		0	1	2	3	4	 
	ops[round]  5	2	C	D	+
输出：30  
解释： 
	第 1 轮得分 5 分，当前总共得分 5 分。
	第 2 轮得分 2 分，当前总共得分 5+2=7 分。 
	第 3 轮取消上轮得分，当前总共得分 5 分。 
	第 4 轮获得上一轮双倍得分，当前总共得分 5+10=15 分。 
	第 5 轮获得上两轮得分之和，当前总共得分 15+5+10=30 分。 
*/
#include<iostream>
#include<cstring>
using namespace std;
int FrogScore(char data[], int n)
{
	/*
		想到使用栈的结构，
		遇到数字要进栈，
		遇到‘C’出栈，
		遇到‘D’要入栈一个栈顶元素二倍的元素
		遇到‘+’要入栈一个栈顶元素+栈顶元素的下一个元素的和
		
		最后全部出栈数字进行相加，即可 
	*/
	int stack[n], top = -1, tmp, score = 0;
	for(int i = 0; i < n; i++)
	{
		if(data[i] >= '0' && data[i] <='9')//如果输入数字，进栈 
		{
			stack[++top] = data[i] - '0';
		}
		else if(data[i] == 'C')//如果输入C,出栈一个 
		{
			if(top >= 0)
				top--;
		}
		else if(data[i] == 'D')//如果输入为D，将栈顶元素*2进栈 
		{
			stack[++top] = stack[top - 1] * 2;
		}
		else if(data[i] == '+') //如果为+，将栈顶往下两个元素的和进栈 
		{
			stack[++top] = stack[top-1] + stack[top -2];
		}
		else{
			cout<<"非法字符！";
			exit(0); 
		} 
	} 
	while(top != -1)//将所有元素出栈 
	{
		score += stack[top--];
	}
	return score;
}
 
 
 
int main()
{
	char data[] = {'5', '2', 'C', 'D', '-'};
	int score = FrogScore(data, 5);
	cout<<"The Total Score is:"<<score<<endl; 
}
