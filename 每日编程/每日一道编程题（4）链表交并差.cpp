/*
两个有序的无头结点的链表La，Lb。编写函数：如何以最优的方式找出二者的交集，并且把结果存在一个新链表中返回。

	单链表的类型定义如下： 

	Typeddf struct LNode{ 
		
		Element Type data;  
		
		Struct LNode *next; 
		
	}LNode, *ListNode; 

函数原型： ListNode* intersection(ListNode *A, ListNode *B) */ 
/*
算法思路
	  p1 
链表A 1 -> 2 -> 3 -> 7
      p2
链表B 1 -> 3 -> 5 -> 7
p1指向结点的data等于p2指向结点的data时
将该结点新增到链表C中，p1与p2指向分别指向下一个结点
	       p1 
链表A 1 -> 2 -> 3 -> 7
           p2
链表B 1 -> 3 -> 5 -> 7
链表C 1 
当p1指针指向结点的data不等于p2指针指向结点的data时，
data值较小的针指向下一结点。
	            p1 
链表A 1 -> 2 -> 3 -> 7
           p2
链表B 1 -> 3 -> 5 -> 7

*/
/*
ListNode* Intersection(ListNode* plist1, ListNode* plist2)
{
	//判断不为空
	if(plist1 == NULL || plist2 == NULL)
	return NULL;
}
//头结点(哨兵位节点)
ListNode* newlist = BuyNode(0);
ListNode* tail = newlist;
//相等了一起走，值给tail,不相等小的走
while(plist1 && plist2)
 { 
	if(plist1->data == plist2->data)
	{
		tail->next = plist1;
		tail = plist1;
		plist1 = plist1->next;
		plist2 = plist2->next;
	}
	else if(plist1->data < plist2->data)
	{
		plist1 = plist1->next;
	}	
	else
	{
		plist2 = plist2->next;
	}
}

tail->next = NULL;
//注意tail->next要置空
return newlist->next;
}
int main(){
	int A[10],B[10];
	A[]={1,2,3,7};
	B[]={1,3,5,7};
	Intersection(&A[], &B[]);
}
*/
 
 
//实现并集操作 
#include<cstdio>


typedef struct node
{
	int data;
	struct node *next;
}Node;
//用指定数组创建带头结点的链表
Node *create_list(int *arr, int n)
{
	Node *head = new Node;
	int i;
	Node *p = head;
	for (i = 0; i < n; i++)
	{
		p->next = new Node;
		p = p->next;
		p->data = arr[i];
	}
	p->next = NULL;
	return head;
}
//对链表排序
void sort_list(Node *head)
{
	Node *p1, *p2;
	int data;
	for (p1 = head->next; p1; p1 = p1->next)
		for (p2 = p1->next; p2; p2 = p2->next)
		{
			if (p1->data > p2->data)
			{
				data = p1->data;
				p1->data = p2->data;
				p2->data = data;
			}
		}
}
//打印链表
void print_list(Node *head)
{
	Node *p = head->next;
	while (p)
	{
		printf("%4d", p->data);
		p = p->next;
	}
}
Node *get_union(Node *head1, Node *head2)
{
	Node *head = new Node;
	Node *p1, *p2, *p;
	p1 = head1->next;
	p2 = head2->next;
	p = head;
	while (p1 && p2)
	{
		if (p1->data < p2->data)
		{
			p->next = new Node;
			p = p->next;
			p->data = p1->data;
			p1 = p1->next;
		}
		else if (p1->data > p2->data)
		{
			p->next = new Node;
			p = p->next;
			p->data = p2->data;
			p2 = p2->next;
		}
		else
		{
			p->next = new Node;
			p = p->next;
			p->data = p1->data;
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	while (p1)
	{
		p->next = new Node;
		p = p->next;
		p->data = p1->data;
		p1 = p1->next;
	}
	while (p2)
	{
		p->next = new Node;
		p = p->next;
		p->data = p2->data;
		p2 = p2->next;
	}
	p->next = NULL;
	return head;
}
void free_list(Node *head)
{
	Node *p, *q; 
	p = head;
	while (p)
	{
		q = p->next;
		delete(p);
		p = q;
	}
}
int main(void)
{
	int arr1[] = { 2,4,5,6 };
	int arr2[] = { 4,5,7,9 };
	//创建链表
	Node *head1 = create_list(arr1, 4);
	Node *head2 = create_list(arr2, 4);
	//对链表排序
	sort_list(head1);
	sort_list(head2);
	printf("list1:\n");
	print_list(head1);
	printf("\n");
	printf("list2:\n");
	print_list(head2);
	printf("\n");
	//求并集
	Node *head = get_union(head1, head2);
	printf("list12:\n");
	print_list(head);
	free_list(head1);
	free_list(head2);
	free_list(head);
	return 0;
}


