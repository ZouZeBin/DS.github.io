/**
* ��ͼ��Ⱦɫ����
*
*/
#include<stdio.h>
void mapcolor(int dist[6][6], int areanum,int s[6]){
    s[0] = 1;//һ�ŵ���Ϳһ��ɫ
    int curarea = 1;//��ǰӦ��Ϳ������
    int color = 1;//��ɫ
    int i = 0;
    while (curarea < areanum){//��ûͿ��
        while (color <= 4 && curarea < areanum){//ÿ����ɫ������̽
            i = 0;
            while ((i < curarea) && (s[i] * dist[curarea][i] != color)){//�뵱ǰ�������ڵ���Ⱦɫ�����Ƿ����������ɫ��ͬ��
                i++;
            }
            if (i<curarea){//k<curarea,��ǰ�˳�ѭ����˵��������ɫ�����ã��ȶ���һ����ɫ
                color++;
            }
            else{//������ɫ����
                s[curarea] = color;//��ǰ����Ⱦɫ
                curarea++;//��ʼ��һ����
                color = 1;//color��һ��ʼ
            }
        }
        if (color>4){//color>4˵���Ҳ������ʵ���ɫ�Ե�ǰ�������Ⱦɫ�����ݣ�������һ���������ɫ��
            curarea--;
            color = s[curarea] + 1;//��Ϊ��һ�������Ѿ�Ⱦɫ�����Դ���Ⱦɫ����һ����ɫ��ʼ����
        }
    }
    
}
int main() {
    int areaNum = 6;//��������
    int dist[6][6] = {//�ڽӾ���0��ʾ���ڽ�
        { 0, 1, 1, 0, 0, 1 },
        { 1, 0, 1, 1, 1, 1 },
        { 1, 1, 0, 1, 0, 0 },
        { 0, 1, 1, 0, 1, 0 },
        { 0, 1, 0, 1, 0, 1 },
        { 1, 1, 0, 0, 1, 0 }
    };
    int s[6];//��¼��ɫ
    mapcolor(dist, areaNum,s);
    for (int o = 0; o < areaNum; o++){
        printf("%d������:��%d����ɫ\n", o + 1, s[o]);
    }
  //  system("pause");
  return 0;
}
