#include<stdio.h>
#include<malloc.h>

struct node
{
	int usn;
	char name[10];
	char prog[10];
	int sem;
	long int mno;
	
	struct node *link;
}; typedef struct node * NODE;


NODE insfront(NODE first)
{
	NODE newnode;
	newnode = (NODE)malloc(sizeof(struct node));
	printf("Enter the USN, Name, Program, Semester, Mobile No. of student \n");
	scanf("%d %s %s %d %ld", &newnode->usn, newnode->name, newnode->prog, &newnode->sem, &newnode->mno);
	newnode->link = first;
	first = newnode;
	return first;
}


NODE delfront(NODE first)
{
	NODE temp;

	if( first == NULL)
	{
		printf("The List is Empty, deletion cannot be possible\n");
	}
	else
	{
		temp =  first;
	    first = first ->link;
	    free(temp);
	}
	return first;
}

void display(NODE first)
{
	NODE temp;

	if( first == NULL)
	{
	    printf(" The List is Empty\n");
	}
	else
	{
	    temp =  first;
	    printf("The USN, Name, Program, Semester, Mobile No. of student \n");
	    while(temp != NULL )
	    {
			printf("%d\t%s\t%s\t%d\t%ld\n", temp->usn, temp->name, temp->prog, temp->sem, temp->mno);
			temp  = temp->link;
	    }
	}
}
int main()
{
	NODE first = NULL;
	int ch;

    for(;;)
    {
        printf("1:Ins Front 2:Del Front 3: Display\n");
        scanf("%d",&ch);
        
	    switch(ch)
	    {
			case 1: first = insfront(first);
		            break;
	        case 2: first = delfront(first);
		            break;
	        case 3: display(first);
		            break;
	        default: exit(0);
	    }
	}
}
