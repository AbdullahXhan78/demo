#include<stdio.h>
#include<conio.h> 
int main() 
{ 
	int n,cn,i; 
	int count_pos=0; 
	int count_neg=0; 
	int count_zero=0; 
	printf("Enter the numbers limit : "); 
	scanf("%d",&n); 
	printf("Enter %d numbers: \n",n); 
	for(i=1;i<=n;i++) 
	{ 
		scanf("%d",&cn); 
		if(cn>=1)
		{ 
			count_pos++;
		}
		else if(cn<0)
		{
		 	count_neg++;
		}
		else  
		count_zero++; 
	} 
	printf("Total no. of Positive numbers %d \n",count_pos); 
	printf("Total no. of Negative numbers %d \n",count_neg); 
	printf("Total no. of Zero %d\n",count_zero);
	return 1;
	getch();
}

