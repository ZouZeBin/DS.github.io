#include <iostream>
#include <cstring>
#include <cstdio>
#define Max 1005
bool R[Max][Max];//��ϵ���飬R[i][j]==1,��ʾi,j��ͻ
int a[Max];
int result[Max];//��¼�����result[i]=j��ʾi�ڵ�j��
int n;//Ԫ�ظ���
using namespace std;
 
struct Que {//��������
    int q[Max];
    int sz ;//= 0;//���д�С
    int ft ;//= 0;//����
    int rr ;//= 0;//��β
 
    void push(int x) {  //�������
        if(sz >= Max) {
            cout << "�����ж����ֵ" << endl;
            return ;
        }
        sz++;//������Ԫ�ظ�����һ
        q[rr] = x;
        rr = (rr + 1) % Max;// ��β����һλ
    }
 
    int pop() { //���ӣ������س��ӵ�ֵ
        if(sz <= 0) {
            cout << "����Ϊ��" << endl;
            return 0;
        }
        sz--;//Ԫ�ظ�����һ
        ft = (ft+1) % Max;//���׺���һλ
        return q[ft-1];
    }
 
    bool emp() { //�ж϶����Ƿ�Ϊ��
        if(sz <= 0)
            return true;
        else
            return false;
    }
};

Que q;
void print(Que que) {//�������
    while(!que.emp()) {
        cout << que.pop() << endl;
    }
}

void solve() {
    int ans = 1;//���
    while(!q.emp()) {
        int cnt = q.sz;//��ʾÿ��ѭ��ִ�п�ʼʱ����Ԫ�صĸ���
        //cout << cnt << endl;
        int acnt = 0;//a��Ԫ�ظ���
        for(int i = 0; i < cnt; i++) {//���г�ʼ�ж��ٸ�Ԫ�ؾͽ��ж��ٴβ���
            int x = q.pop();//ȡ����
            //printf("%d����\n",x);
            if(acnt == 0) {//��a��û��Ԫ��ʱ֮�佫x����a
                a[acnt++] = x;
                //printf("%d����a\n",x);
                continue;
            }
            int j = 0;
            for(j = 0; j < acnt; j++) {
                //��x��a��Ԫ�س�ͻʱ�����½������
                if(R[x][a[j]]) {
                        q.push(x);
                        //printf("%d���",x);
                        break;
                }
            }
            //��x��a��Ԫ�ض��޳�ͻʱ
            if(j == acnt) {
                a[acnt++] = x;
                //printf("%d����a\n",x);
                continue;
            }
        }
        //��ʱa����ɵõ�һ������ͻ���Ӽ������е�Ԫ�ر��
        for(int i = 0; i < acnt; i++) {
            result[a[i]] = ans;
            //printf("%d\n",a[i]);
        }
        ans++;//��ż�һ
    }
    for(int i = 1; i < ans; i++) {
        printf("��%d���Ӽ�:",i);
        for(int j = 0; j <= n; j++) {
            if(result[j] == i)
                printf("%d ",j);
        }
        printf("\n");
    }
    return;
}
int main() {
    cout << "����n(������Ԫ��Ϊ1~n)��\n";
    cin >> n;
    for(int i = 1; i <= n; i++) //��1~n���
        q.push(i);
    //print(q);//�����Ƿ����
    int m;
    cout << "�����ͻ������m:\n";
    cin >> m;
    cout << "�����ͻ������:\n";
    memset(R, 0, sizeof(R));
    while(m--) {
        int x,y;
        cin >> x >> y;
        R[x][y] = R[y][x] = 1;//��ʾx,y��ͻ
    }
    solve();
    return 0;
}
/*
��������
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
