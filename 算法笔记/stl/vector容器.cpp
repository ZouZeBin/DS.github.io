#include<cstdio>
#include<vector>
using namespace std;
int main(){
	//ͨ������������ 
	vector<int> vi;
	for(int i=1;i<=5;i++){
		vi.push_back(i);//���β���viĩβ 
	}
	
	//vi.begin()Ϊȡvi���׵�ַ����itָ�������ַ
	vector<int>::iterator it=vi.begin();
	for(int i=0;i<5;i++){
		printf("%d",*(it+i));//���vi[i] 
	} 
	//vector�ĵ�������֧��it<vi.end()��д����������ҿ���vi.end()
	//ָ��β��ַ����һ��λ�� 
	for(vector<int>::iterator it=vi.begin();it!=vi.end();it++){
		printf("%d",*it);
	} 
	//size()����viԪ�صĸ���
	for(int i=0;i<vi.size();i++){
		printf("%d",vi[i]);
	} 	
	//pop_back()����ɾ��vector��βԪ��
	vi.pop_back();
	for(int i=0;i<vi.size();i++){
		printf("%d\n",vi[i]);
	} 
	//vi.clear();
	vi.erase(vi.begin());
	 
	vi.insert(vi.begin()+2,666);//���������� 
	for(int i=0;i<vi.size();i++){
		printf("%d\n",vi[i]);
	} 
	////////
	vi.clear();
	for(int i=1;i<=5;i++){
		vi.push_back(i);//���β���viĩβ 
	}
	vi.erase(vi.begin(),vi.begin()+1);
	for(int i=0;i<vi.size();i++){
		printf("%d\n",vi[i]);
	} 
	return 0;
}
