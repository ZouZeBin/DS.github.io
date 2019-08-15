/*（2018北理813，2018华科887）

求二叉树的结点个数，如果根节点为空，则返回 0。 

typedef struct Bintreenode{ 

int data； 

struct Bintreenode *right；

struct Bintreenode *left； 

} *Bintreenode
*/ 


#include<iostream>
#include <malloc.h>
using namespace std;
static int D = 0;//记录具有两个子女结点的结点个数
struct Bintreenode {//删掉typedef ，这是C语言的结构体，C ++会自动分配。
 	char data;
 	struct Bintreenode *right;
 	struct Bintreenode *left;
};
 
//先序创建二叉树
void CreatBiTree(Bintreenode *&T){
	char ch;
	cin >> ch;
	if (ch == '#') {
		T = NULL;
	}
	else {
			T = (Bintreenode*)malloc(sizeof(Bintreenode));
			T->data = ch;
			CreatBiTree(T->left);//递归创建左子树
			CreatBiTree(T->right);//递归创建右子树
	}
}
//先序遍历二叉树
void Preorder(Bintreenode *&T) {
	if (T) {
		cout << T->data;
		Preorder(T->left);
		Preorder(T->right);
	}
	else
		cout << "";
}
//二叉树结点个数
int CountNode(Bintreenode *&root) {
	int count = 0;
	if (root == NULL)
		return 0;
	int m=CountNode(root->left);
	int n=CountNode(root->right);
	if (root->left != NULL && root->right != NULL)//判断该结点是否有两个子女结点
		D++;
	count=m+n+1;
	return count;
}


int main()
{
	cout << "创建一个二叉树：" << endl;
	Bintreenode *T;
	CreatBiTree(T);
	cout << "先序遍历：" << endl;
	Preorder(T);
	cout << endl;
	cout << "二叉树的结点个数" << endl;
	cout << CountNode(T)<<endl;
	cout << "二叉树的具有两个子女结点的结点个数" << endl;
	cout << D << endl;
	return 0;
}







 
