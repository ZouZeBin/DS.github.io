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
//整数转化为bign 
bign change(char str[]){
	bign a;
	a.len=strlen(str);
	for(int i=0;i<a.len;i++){
		a.d[i]=str[a.len-i-1]-'0';
	}
	return a;
}
//高精度加法
bign add(bign a,bign b){
	bign c;
	int carry=0;//进位
	for(int i=0;i<a.len||i<b.len;i++){
		int temp=a.d[i]+b.d[i]+carry;
		c.d[c.len++]=temp%10;
		carry=temp/10;
	} 
	if(carry!=0){
		c.d[c.len++]=carry;//先把进位加入 
	}
	return c;
} 

void print(bign a){
	for(int i=a.len-1;i>=1;i--){//后面多出一个104 
		printf("%d",a.d[i]);
	}
}

//高精度减法
bign sub(bign a,bign b){
	bign c;
	for(int i=0;i<a.len||i<b.len;i++){//较长为界 
		if(a.d[i]<b.d[i]){//如果不够减 
			a.d[i+1]--;//向高位借1
			a.d[i]+=10;//前前位加10 
		}
		c.d[c.len++]=a.d[i]-b.d[i];//减法结果为当前位结果 
	} 
	while(c.len-1>=1&&c.d[c.len-1]==0){
		c.len--;//去除高位的0，同时至少保留一位最低位 
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
