#include<cstdio>
#include<vector>
using namespace std;
int main(){
	//通过迭代器访问 
	vector<int> vi;
	for(int i=1;i<=5;i++){
		vi.push_back(i);//依次插入vi末尾 
	}
	
	//vi.begin()为取vi的首地址，而it指向这个地址
	vector<int>::iterator it=vi.begin();
	for(int i=0;i<5;i++){
		printf("%d",*(it+i));//输出vi[i] 
	} 
	//vector的迭代器不支持it<vi.end()的写法，【左闭右开】vi.end()
	//指向尾地址的下一个位置 
	for(vector<int>::iterator it=vi.begin();it!=vi.end();it++){
		printf("%d",*it);
	} 
	//size()给出vi元素的个数
	for(int i=0;i<vi.size();i++){
		printf("%d",vi[i]);
	} 	
	//pop_back()用于删除vector的尾元素
	vi.pop_back();
	for(int i=0;i<vi.size();i++){
		printf("%d\n",vi[i]);
	} 
	//vi.clear();
	vi.erase(vi.begin());
	 
	vi.insert(vi.begin()+2,666);//任意插入操作 
	for(int i=0;i<vi.size();i++){
		printf("%d\n",vi[i]);
	} 
	////////
	vi.clear();
	for(int i=1;i<=5;i++){
		vi.push_back(i);//依次插入vi末尾 
	}
	vi.erase(vi.begin(),vi.begin()+1);
	for(int i=0;i<vi.size();i++){
		printf("%d\n",vi[i]);
	} 
	return 0;
}
