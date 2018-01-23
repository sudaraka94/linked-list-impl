#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//This is the definition of a node
typedef struct node
{
	int val;
	struct node *next;
}node;

void print_list(node *head){
	node *current = head;
	while (current !=NULL){
		printf("%d\n", current->val );
		current=current->next;
	}
}

int member(node *head, int val){
	node *current = head;
	while (current !=NULL){
		if (val==current->val)
		{
			return 1;
		}
		current=current->next;
	}
	return 0;
}

node * insert(node *head,int val){
	if(member(head,val)!=1){
		node *new_head=malloc(sizeof(node));
		new_head->val=val;
		new_head->next=head;
		if (head==NULL)
		{
			new_head->next=head;
		}
		return new_head;
	}
	return head;
}

node * delete(node *head,int val){
	node *current = head;
	node *previous= NULL;
	while (current !=NULL){
		if (val==current->val)
		{
			if (previous==NULL)
			{
				return current->next;
			}
			previous->next=current->next;
			return head;
		}
		previous=current;
		current=current->next;
	}
	return head;

}

node * seed(node *head,int n){
	int i;

	for( i = 0 ; i < n ; i++ ) {
	    while(true){
	    	int num=rand() % 65536;
	    	if (member(head,num)==0)
	    	{
	    		head=insert(head,num);
	    		break;
	    	}
	    }
	}
	return head;
}

node * process(node *head){
	int choice=rand() % 4;
	if(choice==1){
		int val=rand() % 65536;
		return insert(head,val);
	}
	else if (choice==2)
	{
		int val=rand() % 65536;
		return delete(head,val);
	}
	else{
		int val=rand() % 65536;
		member(head,val);
		return head;
	}
}


int main(int argc, char const *argv[])
{
	time_t t;
	printf("%s\n",argv[1]);   
	srand((unsigned) time(&t));

	node *head=NULL;
	head=seed(head,10);
	
	int i,n;
	n=5;

	for( i = 0 ; i < n ; i++ ) {
	    process(head);	
	}
	
	return 0;

}