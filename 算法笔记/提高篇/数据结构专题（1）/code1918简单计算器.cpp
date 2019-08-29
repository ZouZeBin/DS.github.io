/*题目描述
	读入一个只包含 +, -, *, / 的非负整数计算表达式，计算该表达式的值。

输入
	测试输入包含若干测试用例，每个测试用例占一行，每行不超过200个字符，
	整数和运算符之间用一个空格分隔。没有非法表达式。
	当一行中只有0时输入结束，相应的结果不要输出。

输出
	对每个测试用例输出1行，即该表达式的值，精确到小数点后2位。

样例输入
	30 / 90 - 26 + 97 - 5 - 6 - 13 / 88 * 6 + 51 / 29 + 79 * 87 + 57 * 92
	0
样例输出
12178.21
*/

#include<iostream>
#include<cstdio>
#include<string>
#include<stack>
#include<queue>
#include<map>
using namespace std;
struct node{
	double num;//操作数
	char op;//操作符
	bool flag;//true表示操作数，false表示操作符 
};

string str;
stack<node> s;//操作符栈
queue<node> q;//后缀表达式序列
map<char,int> op;

//中缀转后缀
void change(){
	double num;
	node temp;
	for(int i=0;i<str.length();){
		if(str[i]>='0'&&str[i]<='9'){//如果是数字 
			temp.flag=true;//标记为数字位 
			temp.num=str[i++]-'0';//记录操作数的第一个数位
			while(i<str.length()&&str[i]>='0'&&str[i]<='9'){
				temp.num=temp.num*10+(str[i]-'0');//如果连续入数，便更新该操作数
				i++; 
			} 
			q.push(temp);//将更新后整个操作数整体进入后缀表达队列 
		}else{//如果是操作符 
			temp.flag=false;//标记为操作符
			//只要操作符栈顶优先级比该操作符优先级高
			//把操作符从栈顶弹到后缀表达式的队列中
			while(!s.empty()&&op[str[i]]<=op[s.top().op]){
				q.push(s.top());//将栈顶操作符进入队列 
				s.pop();//将栈顶元素弹出 
			}
			temp.op=str[i];
			s.push(temp);//把该操作符压入操作符栈中
			i++; 
		} 
	}
	//如果操作符栈还有操作符，就把它弹出到后缀表达式队列当中
	while(!s.empty()){
		q.push(s.top());
		s.pop();
	} 	
} 

//计算后缀表达式
double Cal(){
    double temp1,temp2;
	node cur,temp;
	while(!q.empty()){//只要后缀表达列表非空 
		cur=q.front();//cur记录队首元素
		q.pop();
		if(cur.flag==true) s.push(cur);//如果是操作数直接压入栈
		else{//如果是操作符
			temp2=s.top().num;//弹出第二个操作数 
			s.pop();
			temp1=s.top().num;//弹出第一个操作数
			s.pop();
			temp.flag=true;//记录临时操作数
			if(cur.op=='+') temp.num=temp1+temp2;//加 
			else if(cur.op=='-') temp.num=temp1-temp2;//减 
			else if(cur.op=='*') temp.num=temp1*temp2;//乘 
			else temp.num=temp1/temp2;//除 
			s.push(temp);//将操作数入栈 
		} 
	}
	return s.top().num;//栈顶就是后缀表达式的值 
} 

//主函数 
int main(){
	op['+']=op['-']=1;//设立操作符优先级
	op['*']=op['/']=2;
	while(getline(cin,str),str!="0"){//0 结束 
		for(string::iterator it=str.end();it!=str.begin();it--){
			if(*it==' ') str.erase(it);//将空格去除 
		}
		while(!s.empty()) s.pop();//初始化栈 
		change();//中缀转后缀
		printf("%.2f\n",Cal());//计算后缀表达式 
	} 
	return 0; 
} 





