#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
}*head =NULL;

void create()
{
	int t;
	int i;
	printf("\nEnter the total number :");
	scanf("%d", &t);
        
	struct node *ptr = (struct node*)malloc(sizeof(struct node));
	scanf("%d",&ptr->data);
	ptr->next = NULL;
        head = ptr;

	for(i = 1; i < t; ++i){
	  struct node *p = (struct node*)malloc(sizeof(struct node));
	  scanf("%d", &p->data);
	  p->next = NULL;
	  ptr->next = p;
	  ptr = p; 
	}
}

void display()
{
      struct node *ptr = head;
      if(head == NULL){
  	       printf("No Data");
       }else{
	       while(ptr != NULL)
	       {
		       printf("%d  ", ptr->data);
		       ptr = ptr->next;
	       }
      }

}

int total()
{
	int count = 0;
 	struct node *ptr = head;
      if(head == NULL){
               return 0;
       }else{
               while(ptr != NULL)
               {
			++count;
                       ptr = ptr->next;
               }
      }

      return count;
}

void insert()
{
	int data;
	int position;
	int i;
	printf("\nEnter the position to insert :");
	scanf("%d", &position);
	int count = total();
	if(position < 0)
	{
		printf("\nInvalid position");
	}else{
		struct node *p = head;
                struct node *q;
		struct node *ptr = (struct node*)malloc(sizeof(struct node));
                printf("\nEnter the number to be inserted : ");
                scanf("%d", &ptr->data);
		if(position == 0){
			head = ptr;
			ptr->next = p;
		}else if(position <= count){
			if(position == count){ 
				while(p->next != NULL)
					p = p->next;
				p->next = ptr;
				ptr->next = NULL;
			}else{
				while(position != 1){
					--position;
					p = p->next;
				}
				q = p -> next;
				p -> next = ptr;
				ptr->next = q;
			}
		}
		else 
			printf("\nInvalid position");

	}
}

void delete()
{
	int position;
	struct node *ptr = head;
	struct node *p, *q;
	printf("\nEnter the poisition :");
	scanf("%d", &position);
	int count = total();
	if(count)
	{
		if(position < 0)
			printf("\nInvalid position");
		else if(position <= count){
			if (position == 0){
				head = head -> next;
				free(ptr);
			}else{
				while((position-1) != 0){
					position--;
					ptr = ptr->next;
				}
				p = ptr;
				ptr = ptr->next;
				q = ptr -> next;
				p->next = q;
				free(ptr);
			}
		
		}
	}else
		printf("\nNothing to delete");
}

int main()
{
	int opt;
	do{
		printf("\n1. create 2.display 3. insert 4.delete 5.exit");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1: create();
				break;
			case 2: display();
				break;
			case 3: insert();
				break;
			case 4: delete();
				break;

			case 5: exit(0);
			        break;
			default: printf("Invalid option");
				 break;
		}

	}while(opt != 5);

}
