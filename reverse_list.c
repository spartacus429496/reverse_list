#include <stdio.h>

struct node
{
        char data;
        struct node * next;
};

void insert(struct node * in,struct node * list)
{
        int i =0 ;
        struct node * temp = list;
        while(temp->next  != NULL)
        { 
                temp = temp->next;
                // printf("temp data :%d\n",temp->data);

        }
        temp->next =  in;
        //printf("data :%d\n",in->data);

        in->next =NULL; 
}
void init(struct node * list)
{
        list->next = NULL;
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
int main(void )
{
        struct node node1 = {1,NULL};
        struct node node2 = {2,NULL};
        struct node node3 = {3,NULL};
        struct node node4= {4,NULL};
        struct node node5 = {5,NULL};
        //struct node * head = &node1;
        struct node node0 = {0,NULL};
        struct node * head = &node0;
        //printf("node1 data:%d",node1.data);
        init(head);
        insert(&node1,head);
        insert(&node2,head);
        insert(&node3,head);
        insert(&node4,head);
        insert(&node5,head);
        print_node(head);
        head = reverse(head);
        print_node(head);



}
struct node * reverse(struct node * head)
{
        struct node * current,*next,*pre;
        current = head->next;
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
