#include <stdio.h>
#include <stdlib.h>

struct node {
   int info;
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

//display the list
void printList() {

   struct node *ptr = head;
   
   printf("\n[head] ->");
   //start from the beginning
   while(ptr != NULL) 
   {        
      printf(" %d ->",ptr->info);
      ptr = ptr->next;
      
   }

   printf(" [null]\n");
}

void create_list()
{
    int data;
    printf("enter the first element: ");
    scanf("%d", &data);
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->info = data;
    new_node->next = NULL;
    head = new_node;
    
}


//insert link at the beggining
void insert_beg()                                         
{
    int m, data, i;
    printf("enter the no of element to be enter: ");
	scanf("%d", &m);
	for(i=0; i<m; i++)
    {
	    printf("enter the element to be enter: ");
		scanf("%d", &data);
        struct node *new_node = (struct node*) malloc(sizeof(struct node));
        new_node->info = data;
        new_node->next = head;		
        head = new_node;
    }
}
void insert_end()
{
    struct node *last = head;
	int m, data, i;
    printf("enter the no of element to be enter: ");
	scanf("%d", &m);
	for(i=0;i<m;i++)
	{
		struct node *new_node = (struct node*) malloc(sizeof(struct node));
		printf("enter the element: ");
		scanf("%d", &data);

		new_node->info = data;
		new_node->next = NULL ;
		if(head == NULL)
		{
			head = new_node;
		}
		else
		{
			last = head;
			while (last->next != NULL) 
			{
        		last = last->next; 
        	}
        	last->next = new_node;
		}
		printList();
	}
}
 void insert_spec()
 {
    struct node *current = head;
    struct node *as_current = head;
    int m, data;
    printf("enter the element after which the new element to be inserted: ");
    scanf("%d", &m);
    printf("\nenter the element to be inserted: ");
    scanf("%d", &data);
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->info = data;
    
    as_current = head;
    current = head;
    while(current->info!= m)
    {
        if(current->next == NULL)
        {
            printf("list is empty!!");
            exit(1);
        }
        else
        {
            current = current->next;
        }
    }
    
    new_node->next = current->next;
    current->next = new_node;
 }
 void delete_beg()
 {
    struct node *current = head;
    int m, i;
    printf("enter the no of element to be delete from beginning: ");
    scanf("%d", &m);
    
        
        head = current->next;
        current->next = NULL;
        printf("element deleted: %d", current->info );
        free(current);
        
    
    
 }
 
 void delete_end()
 {
    struct node *current = head;
    struct node *pre_current = head;
    int m, i;
    printf("enter no of the element to be delete from end: ");
    scanf("%d", &m);
    for (i=0; i<m; i++)
    {
        while(current->next!=NULL)
        {
            pre_current = current;
            current = current->next;
        }
        pre_current->next = NULL;
        printf("element deleted %d: ", current->info);
        free(current);
        
    }
 }
void delete_spec()
{
    struct node*current =head;
    struct node *pre_current = head;
    int m;
    printf("enter the data to be deleted: ");
    scanf("%d", &m);

    current = head;
    while(current->info!= m)
    {
        pre_current = current;
        current = current->next;
        
    }
    pre_current->next = current->next;
    printf("deleted element: %d", current->info);
    free(current);
    
}

void Search()
{
    struct node *current = head;
    int m;
    printf("enter the no to be search: ");
    scanf("%d", &m);
    current = head;
    
    while(current->info!=m)
    {
        current = current->next;
        
    }
    
    if(current->info!=m)
    {
        printf("entered no does not exist in the list!!! ");
        
    }
    else
    {
        printf("   ***** Number  found *****  ");
        printf("%d", current->info);
    }
    
}
void sort_list()
{
    struct node *sort;
    struct node *current = head;
    struct node *pos_current = head;
    current = head;
    pos_current = head;
   
}

int main() 
{
	
	int item, first, choice;
	char ch;
	int i;
	while(1)
	{

		{
			printf("\n1.Create list \n2.Insert in the beggining \n3.Insert at the end ");
		    printf("\n4.insert after an item \n5.Delete from the beggining \n6.Delete from the end ");
		    printf(" \n7.Delete specified node \n8.Search node\n9.Exit!!!");
		    printf("\nenter the choice :");
		    scanf("%d", &choice);
			switch (choice)
			{
				case 1:
    	            create_list();
    	            printList();
    	            break;
    	           
			
				case 2:
		   			insert_beg();
		   			printList();
		   			break;
    	    
    	        case 3:
    	            insert_end();
    	            printList();
    	            break;
		        
		        case 4:
		            insert_spec();
		            printList();
		            break;
		    	
		    	case 5:
		    	    delete_beg();
		    	    printList();
		    	    break;
		    	    
		    	case 6:
		    	    delete_end();
		    	    printList();
		    	    break;
		    	
		    	case 7:
		    	    delete_spec();
		    	    printList();
		    	    break;
		    	 
		    	 case 8:
		    	    Search();
		    	    printList();
		    	    break;
		    	    
		    	 case 9:
		    	    printf("operation successful");
		    	    exit(0);
		    	    
		    	default:
		    		printf("choice don't exist");
		    		break;
			}
		}
		
	}
	return 0;
}







