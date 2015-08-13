#include <stdio.h>
#include <stdlib.h>

struct node
{
	char data;
	struct node * next;
};
typedef struct node NODE;
void insert_old(struct node * in,struct node * NODE)
{
	int i =0 ;
	struct node * temp = NODE;
	while(temp->next  != NULL)
	{ 
		temp = temp->next;
		// printf("temp data :%d\n",temp->data);

	}
	temp->next =  in;
	//printf("data :%d\n",in->data);

	in->next =NULL; 
}
NODE *insert(char data,struct node * head)
{
	NODE * add_node = (NODE*)malloc(sizeof(NODE));
	add_node->data = data;
	add_node->next = NULL; 
	NODE * temp = head;
	if (temp == NULL)
		//*temp = *add_node;
		head = add_node;
	else
	{
		while(temp->next != NULL)	
			temp = temp->next;
		temp->next = add_node;
	}
	return head;
}
void init(struct node * NODE)
{
	NODE->next = NULL;
}

void print_node (struct node * head)
{
	struct node * temp =head ;
	while(temp -> next != NULL)
	{
		printf("node :%d\n",temp->data);
		temp = temp->next;
	}
	printf("node :%d\n",temp->data);
}

struct node * reverse(struct node * head);
//struct node * reverse_recursion(struct node * head);
struct node * reverse_recursion(NODE * p, struct node * head);
NODE *reverse_example(NODE *p, NODE * head) ; 
NODE* RecReverseList(NODE* head) ;
int main(void )
{
	struct node node1 = {1,NULL};
	struct node node2 = {2,NULL};
	struct node node3 = {3,NULL};
	struct node node4= {4,NULL};
	struct node node5 = {5,NULL};
	//struct node * head = &node1;
	struct node node0 = {0,NULL};
	//struct node * head = &node0;
	struct node * head = NULL;
	//printf("node1 data:%d",node1.data);
	//init(head);
	//insert(&node1,head);
	head = insert(1,head);
	head = insert(2,head);
	head = insert(3,head);
	head = insert(4,head);
	head = insert(5,head);
	head = insert(6,head);
	print_node(head);
	//head = reverse(head);
	//head = reverse_recursion(head);
	//head = reverse_recursion(head,head);
	head = RecReverseList(head);
	//head = reverse_example(head,head);
	print_node(head);



}
struct node * reverse(struct node * head)
{
	struct node * current,*next,*pre;
	//current = head->next;
	current = head;
	next = current->next;
	current->next  = NULL;
	pre = current;
	current = next;

	while(current->next != NULL)
	{
		printf("current data:%d\n",current->data);
		next = current->next;
		current->next = pre;
		printf("pre data:%d\n",pre->data);

		pre =  current;
		current =  next;

	}
	current->next = pre;
	head = current;
	//head = pre;
	//head->next = current;
	return head;

}
struct node * reverse_recursion(NODE * p, struct node * head)
{
	if(p == NULL || p->next == NULL)	
	{
		head = p;
		return p;
	}
	else
	{
		NODE * temp = reverse_recursion(p->next,head);
		temp->next = p;
		return p;

	} }


NODE *reverse_example(NODE *p, NODE *head)  
{  
    if(p == NULL || p->next == NULL)  
    {  
        head = p;  
        return p;  
    }  
    else  
    {  
        NODE *temp = reverse_example(p->next, head);  
        temp->next = p;  
        return p;  
    }  
}
NODE* RecReverseList(NODE* head) //递归方法  
{     
    if (!head || !head->next)  
    {  
        return head;  
    }  
    NODE *newhead = RecReverseList(head->next);  
    head->next->next = head;  
    head->next = NULL;  
    return newhead;  
}   
