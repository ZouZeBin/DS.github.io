#include<cstdio>
int count=0;
int notDanger(int row,int j,int (*chess)[8]){
	//�ж��з���
	int i,k,flag1=0,flag2=0,flag3=0,flag4=0,flag5=0;
	for(i=0;i<8;i++){
		if (*(*(chess+i)+j)!=0){
			flag1=1;
			break;
		}		
	}
	//�ж����Ϸ�
	for(i=row,k=j;i>=0&&k>=0;i--,k--){
		if ( *(*(chess+i)+k)!=0 ){
			flag2=1;
			break;
		}
	}
	//�ж����·�
	for(i=row,k=j;i<8&&k<8;i++,k++){
		if (*(*(chess+i)+k)!=0){
			flag3=1;
			break;
		}
	} 
	//�ж����Ϸ�
	for(i=row,k=j;i>=0&&k<8;i--,k++){
		if (*(*(chess+i)+k)!=0){
			flag4=1;
			break;
		}
	} 
	//�ж����·�
	for(i=row,k=j;i<8&&k>=0;i++,k--){
		if (*(*(chess+i)+k)!=0){
			flag5=1;
			break;
		}
	}  
	if(flag1||flag2||flag3||flag4||flag5){
		return 0;
	}else{
		return 1;
	}
	 
}

//����row����ʼ��
//����n������
//����(*chess)[8]��ָ������ÿһ�е�ָ��
void EightQueen(int row,int n,int(*chess)[8]){ 
	int chess2[8][8],i,j;//��ʱ�����̴�� 
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			chess2[i][j]=chess[i][j];//���̵ĸ�ֵ 
		}
	}
	if(8==row){
		printf("��%d��",count+1);
		for(i=0;i<8;i++){
			for(j=0;j<8;j++){
				printf("%d ",*(*(chess2+i)+j));
			}
			printf("\n");
		}
		printf("\n");
		count++;
	}
	else{
		for(j=0;j<n;j++){
			if(notDanger(row,j,chess)){//�ж����λ���Ƿ���Σ��
				for(i=0;i<8;i++){//���û��Σ�ռ�������
					*(*(chess2+row)+i)=0;
				}
				*(*(chess2+row)+j)=1;
				EightQueen(row+1,n,chess2);
			} 
		}
	}
}
int main(){
	int chess[8][8],i,j;
	for(i=0;i<8;i++){//���̳�ʼ�� 
		for(j=0;j<8;j++){
			chess[i][j]=0;
		}
	}
	EightQueen(0,8,chess);
	printf("�ܹ���%d�ֽ������\n",count);
	return 0;
}
