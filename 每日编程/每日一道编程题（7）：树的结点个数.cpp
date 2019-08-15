/*��2018����813��2018����887��

��������Ľ�������������ڵ�Ϊ�գ��򷵻� 0�� 

typedef struct Bintreenode{ 

int data�� 

struct Bintreenode *right��

struct Bintreenode *left�� 

} *Bintreenode
*/ 


#include<iostream>
#include <malloc.h>
using namespace std;
static int D = 0;//��¼����������Ů���Ľ�����
struct Bintreenode {//ɾ��typedef ������C���ԵĽṹ�壬C ++���Զ����䡣
 	char data;
 	struct Bintreenode *right;
 	struct Bintreenode *left;
};
 
//���򴴽�������
void CreatBiTree(Bintreenode *&T){
	char ch;
	cin >> ch;
	if (ch == '#') {
		T = NULL;
	}
	else {
			T = (Bintreenode*)malloc(sizeof(Bintreenode));
			T->data = ch;
			CreatBiTree(T->left);//�ݹ鴴��������
			CreatBiTree(T->right);//�ݹ鴴��������
	}
}
//�������������
void Preorder(Bintreenode *&T) {
	if (T) {
		cout << T->data;
		Preorder(T->left);
		Preorder(T->right);
	}
	else
		cout << "";
}
//������������
int CountNode(Bintreenode *&root) {
	int count = 0;
	if (root == NULL)
		return 0;
	int m=CountNode(root->left);
	int n=CountNode(root->right);
	if (root->left != NULL && root->right != NULL)//�жϸý���Ƿ���������Ů���
		D++;
	count=m+n+1;
	return count;
}


int main()
{
	cout << "����һ����������" << endl;
	Bintreenode *T;
	CreatBiTree(T);
	cout << "���������" << endl;
	Preorder(T);
	cout << endl;
	cout << "�������Ľ�����" << endl;
	cout << CountNode(T)<<endl;
	cout << "�������ľ���������Ů���Ľ�����" << endl;
	cout << D << endl;
	return 0;
}







 
