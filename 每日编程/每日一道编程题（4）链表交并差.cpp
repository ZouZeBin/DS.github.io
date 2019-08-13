/*
�����������ͷ��������La��Lb����д��������������ŵķ�ʽ�ҳ����ߵĽ��������Ұѽ������һ���������з��ء�

	����������Ͷ������£� 

	Typeddf struct LNode{ 
		
		Element Type data;  
		
		Struct LNode *next; 
		
	}LNode, *ListNode; 

����ԭ�ͣ� ListNode* intersection(ListNode *A, ListNode *B) */ 
/*
�㷨˼·
	  p1 
����A 1 -> 2 -> 3 -> 7
      p2
����B 1 -> 3 -> 5 -> 7
p1ָ�����data����p2ָ�����dataʱ
���ý������������C�У�p1��p2ָ��ֱ�ָ����һ�����
	       p1 
����A 1 -> 2 -> 3 -> 7
           p2
����B 1 -> 3 -> 5 -> 7
����C 1 
��p1ָ��ָ�����data������p2ָ��ָ�����dataʱ��
dataֵ��С����ָ����һ��㡣
	            p1 
����A 1 -> 2 -> 3 -> 7
           p2
����B 1 -> 3 -> 5 -> 7

*/
/*
ListNode* Intersection(ListNode* plist1, ListNode* plist2)
{
	//�жϲ�Ϊ��
	if(plist1 == NULL || plist2 == NULL)
	return NULL;
}
//ͷ���(�ڱ�λ�ڵ�)
ListNode* newlist = BuyNode(0);
ListNode* tail = newlist;
//�����һ���ߣ�ֵ��tail,�����С����
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
//ע��tail->nextҪ�ÿ�
return newlist->next;
}
int main(){
	int A[10],B[10];
	A[]={1,2,3,7};
	B[]={1,3,5,7};
	Intersection(&A[], &B[]);
}
*/
 
 
//ʵ�ֲ������� 
#include<cstdio>


typedef struct node
{
	int data;
	struct node *next;
}Node;
//��ָ�����鴴����ͷ��������
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
//����������
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
//��ӡ����
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
	//��������
	Node *head1 = create_list(arr1, 4);
	Node *head2 = create_list(arr2, 4);
	//����������
	sort_list(head1);
	sort_list(head2);
	printf("list1:\n");
	print_list(head1);
	printf("\n");
	printf("list2:\n");
	print_list(head2);
	printf("\n");
	//�󲢼�
	Node *head = get_union(head1, head2);
	printf("list12:\n");
	print_list(head);
	free_list(head1);
	free_list(head2);
	free_list(head);
	return 0;
}


