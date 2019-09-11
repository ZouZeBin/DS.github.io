/* 
������Ƕ��нṹ��һ�ֳ����Ķ��нṹ���ںܶ�ط����Ź㷺Ӧ�á����������ָ�����ڵ�Ԫ�ط���ۼ���һ������а����������
1�� ENQUEUE����ʾ�����µ�Ԫ�ؽ�����У����Ȼ�����Ƿ���ͬһ���Ԫ���Ѿ����ڣ�����У�����Ԫ������ͬ���������û����������ĩβ��
2�� DEQUEUE����ʾ����ͷԪ�س���
3�� STOP��ֹͣ����
����ʹ��C++�Դ��Ķ��ж���queue����̸�����
����
��1������һ��t(t<=10)����ʾ1���������ж��ٸ���
��2������һ����1���Ԫ�ظ�������ֵ
��3������һ����2���Ԫ�ظ�������ֵ
�Դ�����������t��֮�󣬿�ʼ��������������(<200)����������ENQUEUE 100����ʾ��Ԫ��100�������
�������STOP����ʾ�����������
���
DEQUEUE���ӵ�Ԫ��
��������
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
�������
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
 
int getsh(int a){//�жϸ���������Ƿ��Ѿ�������ˣ����û�����¼˳��
    for(int i= 0; i< sh; i++)
     if(shu[i]== a)
       return 1;//�����Ѿ������������1 
        
       return 0;//û�����������0 
}

int main(){
     
    int t;
    int n;
    cin>>t;//����һ�������ж����� 
    int o= t;//������������ 
    map<string, int> ma;//�ַ�����int��ӳ�� 
    queue<string> que[maxx];//�ַ������� 
 
    for(int i= 0; i< maxx; i++)//��ʼ����
     shu[i]= -1;
      
    int i= 0;
    while(t--){
        cin>>n;//����ÿ����ַ����� 
        while(n--){
            string s;
            cin>>s;//�����ַ��� 
             
            ma[s]= i;//�ַ��� ��ֵӳ�� 
        }
        i++;
          
    }
     
    int flag= 0;
     
    while(1){
        string str;
        string in;
        cin>>str;//�����ַ��� 
         
        if(str== "STOP")
         break;
          
        if(str== "ENQUEUE"){//��� 
            map<string, int>::iterator it;
            cin>>in;//���뽫Ҫ������� 
            it= ma.find(in);//������������Ƿ��и����ݣ����û����������λ�õĵ�ַ
             
            if(it!= ma.end()){//�ҵ����������
                ma.insert(pair<string, int>(in, it->second));//���������к��� 
                que[it->second].push(in);//�ַ�������ѹ����� 
                 
                if(!getsh(it->second)){//û�ҵ������� 
                    shu[sh++]= it->second;//first:�� second:ֵ 
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
         
        if(str== "DEQUEUE"){//���� 
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







