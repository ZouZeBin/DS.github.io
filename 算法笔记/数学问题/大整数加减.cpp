#include<cstdio>
#include<string.h>
struct bign{
	int d[1000];
	int len;
	big(){
		memset(d,0,sizeof(d));
		len=0;
	}
}; 
//����ת��Ϊbign 
bign change(char str[]){
	bign a;
	a.len=strlen(str);
	for(int i=0;i<a.len;i++){
		a.d[i]=str[a.len-i-1]-'0';
	}
	return a;
}
//�߾��ȼӷ�
bign add(bign a,bign b){
	bign c;
	int carry=0;//��λ
	for(int i=0;i<a.len||i<b.len;i++){
		int temp=a.d[i]+b.d[i]+carry;
		c.d[c.len++]=temp%10;
		carry=temp/10;
	} 
	if(carry!=0){
		c.d[c.len++]=carry;//�Ȱѽ�λ���� 
	}
	return c;
} 

void print(bign a){
	for(int i=a.len-1;i>=1;i--){//������һ��104 
		printf("%d",a.d[i]);
	}
}

//�߾��ȼ���
bign sub(bign a,bign b){
	bign c;
	for(int i=0;i<a.len||i<b.len;i++){//�ϳ�Ϊ�� 
		if(a.d[i]<b.d[i]){//��������� 
			a.d[i+1]--;//���λ��1
			a.d[i]+=10;//ǰǰλ��10 
		}
		c.d[c.len++]=a.d[i]-b.d[i];//�������Ϊ��ǰλ��� 
	} 
	while(c.len-1>=1&&c.d[c.len-1]==0){
		c.len--;//ȥ����λ��0��ͬʱ���ٱ���һλ���λ 
	} 
	return c;
} 
int main(){
	char m[1000],n[1000]; 
//while(scanf("%s%s",m,n)!=EOF){
		scanf("%s%s",m,n);
		bign a=change(m);
		bign b=change(n);
	//	print(add(a,b));
		printf("\n");
		print(sub(a,b));
	//}
	return 0;
} 
