#include<iostream>
using namespace std;
const int MaxSize=100;//集合中最多元素个数 
class Set{//集合类Set 
	int *data;//存放集合中的元素 
	int n;//集合中元素个数
	public:
		
		Set(){//构造函数 
			data=new int [MaxSize];//动态分配空间 
			n=0; 
		}
		 
		~Set(){//析构函数 
			delete []data;
		} 
		
		bool IsIn(int e){//判断e是否在集合中 
			int i;
			for(int i=0;i<n;i++)
				if(data[i]==e)
					return true;//在data数组中找到元素e返回true 
				return false; //在data数组中没有找到e返回false 
		}
		
		bool Insert(int e){//将元素e插入到集合当中去
			if(IsIn(e)) //如果要插入的e已经在集合当中存在，返回false，插入失败 
				return false;
			else{//如果集合中不存在e，则插入下标为n的位置，数组长度++，返回true 
				data[n]=e;
				n++;
				return true;
			}
		}
		
		bool Remove(int e){//将元素e从集合中删除 
			int i=0,j;
			while(i<n&&data[i]!=e){//查找集合中e所在的数组下标 
				i++;
			} 
			if(i>=n) return false;//查找失败
			for(j=i+1;j<n;j++)
				data[j-1]=data[j];//将待删除元素后面的所有元素向前移动一个位置 
			n--;//成功删除，数组长度--
			return true;//返回true 
		} 
		
		void display(){//输出集合中的元素 
			int i;
			for(i=0;i<n;i++){
				cout<<data[i]<<" ";
			} 
			cout<<endl;
		} 
		
		Set &operator=(Set &s1){//运算符=重载成员函数 
			int i;
			for(i=0;i<s1.n;i++){
				data[i]=s1.data[i];
			}
			n=s1.n;
			return *this;
		}
		
		friend Set&operator+(Set &s1,Set &s2){//求并集 
			int i;
			static Set s3;
			for(i=0;i<s1.n;i++)//将s1集合里面的所有元素复制到s3中 
				s3.Insert(s1.data[i]);
			for(i=0;i<s2.n;i++){//将s2集合中在s1中不存在的元素复制到s3中 
				if(!(s1.IsIn(s2.data[i])))
					s3.Insert(s2.data[i]);
			} 
			return s3;//返回合并后的集合 
		} 
		
		friend Set &operator*(Set &s1,Set &s2){//求交集 
			int i;
			static Set s3;
			for(i=0;i<s1.n;i++)//将集合s1中出现在s2的元素复制到s3
				if(s2.IsIn(s1.data[i]))
					s3.Insert(s1.data[i]);
			return s3;//返回交集 
		}
		
		friend Set&operator-(Set &s1,Set &s2){//求差集 
			int i;
			static Set s3;
			for(int i=0;i<s1.n;i++)//将集合s1不出现在s2中的元素复制到s3
				if(!s2.IsIn(s1.data[i]))
					s3.Insert(s1.data[i]);
			return s3;//返回差集	
		} 
		
};
int main(){
	Set s1,s2,s3,s4,s5;//建立Set的五个对象
	s1.Insert(1);
	s1.Insert(2);
	s1.Insert(4);
	s1.Insert(6);
	s1.Insert(8);
	cout<<"集合s1:";//集合s1中插入 1 2 4 6 8 
	s1.display();//打印集合s1
	s2.Insert(2);
	s2.Insert(3);
	s2.Insert(5);
	s2.Insert(6);
	cout<<"集合s2:";//集合s2中插入2 3 5 6
	s2.display();//打印集合s2
	cout<<"求集合s1，s2的并集s3:"<<" ";
	s3=s1+s2;
	s3.display();
	cout<<"求集合s1，s2的交集s4:"<<" ";
	s4=s1*s2;
	s4.display();
	cout<<"求集合s1，s2的差集s5:"<<" ";
	s5=s1-s2;
	s5.display();
	return 0;
} 
