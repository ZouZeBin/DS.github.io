#include <iostream>
#include <cstring>
#include <cstdio>
#define Max 1005
bool R[Max][Max];//关系数组，R[i][j]==1,表示i,j冲突
int a[Max];
int result[Max];//记录结果，result[i]=j表示i在第j组
int n;//元素个数
using namespace std;
 
struct Que {//构建队列
    int q[Max];
    int sz ;//= 0;//队列大小
    int ft ;//= 0;//队首
    int rr ;//= 0;//队尾
 
    void push(int x) {  //插入队列
        if(sz >= Max) {
            cout << "超过列队最大值" << endl;
            return ;
        }
        sz++;//队列内元素个数加一
        q[rr] = x;
        rr = (rr + 1) % Max;// 队尾后移一位
    }
 
    int pop() { //出队，并返回出队的值
        if(sz <= 0) {
            cout << "队列为空" << endl;
            return 0;
        }
        sz--;//元素个数减一
        ft = (ft+1) % Max;//队首后移一位
        return q[ft-1];
    }
 
    bool emp() { //判断队列是否为空
        if(sz <= 0)
            return true;
        else
            return false;
    }
};

Que q;
void print(Que que) {//输出队列
    while(!que.emp()) {
        cout << que.pop() << endl;
    }
}

void solve() {
    int ans = 1;//组号
    while(!q.emp()) {
        int cnt = q.sz;//表示每次循坏执行开始时队列元素的个数
        //cout << cnt << endl;
        int acnt = 0;//a中元素个数
        for(int i = 0; i < cnt; i++) {//队列初始有多少个元素就进行多少次操作
            int x = q.pop();//取队首
            //printf("%d出队\n",x);
            if(acnt == 0) {//当a中没有元素时之间将x放入a
                a[acnt++] = x;
                //printf("%d进入a\n",x);
                continue;
            }
            int j = 0;
            for(j = 0; j < acnt; j++) {
                //当x与a中元素冲突时，重新将其入队
                if(R[x][a[j]]) {
                        q.push(x);
                        //printf("%d入队",x);
                        break;
                }
            }
            //当x跟a中元素都无冲突时
            if(j == acnt) {
                a[acnt++] = x;
                //printf("%d进入a\n",x);
                continue;
            }
        }
        //此时a数组可得到一个不冲突的子集将其中的元素编号
        for(int i = 0; i < acnt; i++) {
            result[a[i]] = ans;
            //printf("%d\n",a[i]);
        }
        ans++;//组号加一
    }
    for(int i = 1; i < ans; i++) {
        printf("第%d个子集:",i);
        for(int j = 0; j <= n; j++) {
            if(result[j] == i)
                printf("%d ",j);
        }
        printf("\n");
    }
    return;
}
int main() {
    cout << "输入n(即代表元素为1~n)：\n";
    cin >> n;
    for(int i = 1; i <= n; i++) //将1~n入队
        q.push(i);
    //print(q);//测试是否入队
    int m;
    cout << "输入冲突的组数m:\n";
    cin >> m;
    cout << "输入冲突的数对:\n";
    memset(R, 0, sizeof(R));
    while(m--) {
        int x,y;
        cin >> x >> y;
        R[x][y] = R[y][x] = 1;//表示x,y冲突
    }
    solve();
    return 0;
}
/*
测试样例
9
13
2 8
9 4
2 9
2 1
2 5
6 2
5 9
5 6
5 4
7 5
7 6
3 7
6 3
*/
