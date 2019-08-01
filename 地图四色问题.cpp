/**
* 地图四染色问题
*
*/
#include<stdio.h>
void mapcolor(int dist[6][6], int areanum,int s[6]){
    s[0] = 1;//一号地区涂一号色
    int curarea = 1;//当前应该涂的区域
    int color = 1;//颜色
    int i = 0;
    while (curarea < areanum){//还没涂完
        while (color <= 4 && curarea < areanum){//每种颜色进行试探
            i = 0;
            while ((i < curarea) && (s[i] * dist[curarea][i] != color)){//与当前区域相邻的已染色区域是否有与此种颜色相同的
                i++;
            }
            if (i<curarea){//k<curarea,提前退出循环，说明此种颜色不可用，比对下一种颜色
                color++;
            }
            else{//此种颜色可用
                s[curarea] = color;//当前区域染色
                curarea++;//开始下一区域
                color = 1;//color从一开始
            }
        }
        if (color>4){//color>4说明找不到合适的颜色对当前区域进行染色，回溯，更改上一个区域的颜色，
            curarea--;
            color = s[curarea] + 1;//因为上一个区域已经染色，所以从已染色的下一个颜色开始即可
        }
    }
    
}
int main() {
    int areaNum = 6;//地区数量
    int dist[6][6] = {//邻接矩阵，0表示不邻接
        { 0, 1, 1, 0, 0, 1 },
        { 1, 0, 1, 1, 1, 1 },
        { 1, 1, 0, 1, 0, 0 },
        { 0, 1, 1, 0, 1, 0 },
        { 0, 1, 0, 1, 0, 1 },
        { 1, 1, 0, 0, 1, 0 }
    };
    int s[6];//记录颜色
    mapcolor(dist, areaNum,s);
    for (int o = 0; o < areaNum; o++){
        printf("%d号区域:第%d号颜色\n", o + 1, s[o]);
    }
  //  system("pause");
  return 0;
}
