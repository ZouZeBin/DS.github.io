#include<cstdio>
const int maxn=11;
//PΪ��ǰ���У�hashTable��¼����x�Ƿ��Ѿ���P��
int n,P[maxn],hashTable[maxn]={false};
//����ǰ���е�indexλ
void generateP(int index){
	if(index==n+1){//�ݹ�߽磬�Ѿ�����������1-nλ
		for(int i=1;i<=n;i++){
			printf("%d",P[i]);//�����ǰ���� 
		} 
		printf("\n");
		return; 
	}


for(int x=1;x<=n;x++){//ö��1-n����x����P[index]
	if(hashTable[x]==false){//x����P[0]-P[index] ����
		P[index]=x;//��x���������
		hashTable[x]=true;//���x�Ѿ���P��
		generateP(index+1);//�������еĵ�index+1λ
		hashTable[x]=false;//��ԭ״̬ 
	} 
  }	
}
int main(){
	n=4;//���1-3��ȫ����
	generateP(1);//P(1)��ʼ�� 
	return 0;
}
