/* 
组队列是队列结构中一种常见的队列结构，在很多地方有着广泛应用。组队列是是指队列内的元素分组聚集在一起。组队列包含两种命令：
1、 ENQUEUE，表示当有新的元素进入队列，首先会检索是否有同一组的元素已经存在，如果有，则新元素排在同组的最后，如果没有则插入队列末尾。
2、 DEQUEUE，表示队列头元素出队
3、 STOP，停止操作
建议使用C++自带的队列对象queue，编程更方便
输入
第1行输入一个t(t<=10)，表示1个队列中有多少个组
第2行输入一个第1组的元素个数和数值
第3行输入一个第2组的元素个数和数值
以此类推输入完t组之后，开始输入多个操作命令(<200)，例如输入ENQUEUE 100，表示把元素100插入队列
最后输入STOP，表示输入命令结束
输出
DEQUEUE出队的元素
样例输入
2
3 101 102 103
3 201 202 203
ENQUEUE 101
ENQUEUE 201
ENQUEUE 102
ENQUEUE 202
ENQUEUE 103
ENQUEUE 203
DEQUEUE
DEQUEUE
DEQUEUE
STOP
样例输出
101 102 103
*/ 
#include<iostream>
#include<queue>
#include<vector>
#include<stack>
#include<iomanip>
#include<map>
using namespace std;
const int maxx= 100+20;
int shu[maxx]; 
int sh= 0;
 
int getsh(int a){//判断该组的数据是否已经输入过了，如果没有则记录顺序
    for(int i= 0; i< sh; i++)
     if(shu[i]== a)
       return 1;//数据已经输入过，返回1 
        
       return 0;//没有输入过返回0 
}

int main(){
     
    int t;
    int n;
    cin>>t;//输入一个队列有多少组 
    int o= t;//将组数存起来 
    map<string, int> ma;//字符串与int的映射 
    queue<string> que[maxx];//字符串队列 
 
    for(int i= 0; i< maxx; i++)//初始数组
     shu[i]= -1;
      
    int i= 0;
    while(t--){
        cin>>n;//输入每组的字符数量 
        while(n--){
            string s;
            cin>>s;//输入字符串 
             
            ma[s]= i;//字符串 数值映射 
        }
        i++;
          
    }
     
    int flag= 0;
     
    while(1){
        string str;
        string in;
        cin>>str;//输入字符串 
         
        if(str== "STOP")
         break;
          
        if(str== "ENQUEUE"){//入队 
            map<string, int>::iterator it;
            cin>>in;//输入将要入队数据 
            it= ma.find(in);//查找组队列中是否有该数据，如果没有则输出最后位置的地址
             
            if(it!= ma.end()){//找到数据则进入
                ma.insert(pair<string, int>(in, it->second));//将其插入队列后面 
                que[it->second].push(in);//字符串的字压入队列 
                 
                if(!getsh(it->second)){//没找到该数据 
                    shu[sh++]= it->second;//first:键 second:值 
                }
                  
            }
            else{
                ma.insert(pair<string, int>(in, o-1));
                que[o- 1].push(in);
                 
                if(!getsh(o- 1)){
                    shu[sh++]= o- 1;
                }
            }
        }
         
        if(str== "DEQUEUE"){//出队 
            int i =0;
            int j= 0;
            while(true){
                if(que[shu[j]].empty())
                 j++;
                else{
                    if(!flag){
                        cout<<que[shu[j]].front();
                        flag++;
                    }
                    else
                     cout<<' '<<que[shu[j]].front();
                    que[shu[j]].pop();
                    break;
                }
            }
        }
    }
    cout<<endl;
    return 0;
}







