#include<stdio.h>
#include<conio.h>
#define max 50
int top=-1,nl=0;
int stack[max];

void push(int num)
{

 if(top==max)
 {
	printf("\n sorry stck overflow");
	exit(0);

 }
 else
 {
	if(top==-1)
	{
	 printf("\n you are going to insert first element");

	}
    stack[++top]=num;
    nl++;
    printf("\n %d element are inserted in stack::",nl);
    delay(600);
    printf("\n element inserted successfully");
    delay(500);
    printf("\n wait going back to choice field::");
    delay(2000);

 }

}

int pop()
{
	int n;
	if(top==-1)
	{
		delay(600);
	 printf("\n stack under flow");

	}
	else
	{
	       n=stack[top--];

	}
		printf("\n deleted");
		delay(400);
		if(nl>0)
		printf("\n %d element left in stack::",--nl);
	return n;
}
void disp()
{
 int i,j=1;
 printf("\n elements in stack are::");
 delay(500);
 for(i=0;i<=top;i++)
 {
  printf("\n %d.) %d",j++,stack[i]);

 }
}

void main()
{
	int num1,choice;
	clrscr();
	printf("\n\t\t\t stack repersention throug array:");
	delay(600);
	do
	{
	  printf("\n enter choice what u want:");
	  printf("\n 1. insert(push):");
	  printf("\n 2. delete(pop)");
	  printf("\n 3. display items:");
	  printf("\n 4. exit:");
	  printf("\n\n press any number::");
	  scanf("%d",&choice);
	  switch(choice)
	  {
		case 1:
			printf("\n enter element to insert in stack::");
			scanf("%d",&num1);
			push(num1);

			break;
		case 2:
			num1=0;
			num1=pop();
			if(top==-1)
				printf("\n no element left in stack::");
			else
			printf("\n %d Element Deleted from stack",num1);
			break;
		case 3:
			disp();
			break;
		case 4:
			printf("\n going back::");
			delay(600);
			exit(0);
		default:
			printf("\n Wrong Choice::");
			break;

	  }//switch()

	}while(1);
	getch();
}