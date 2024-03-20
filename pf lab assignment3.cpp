#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()
{
	int a[4],n,result;
	
	for(int i=0 ; i<=3 ; i++)
	{
		scanf("%d",&a[i]);
	}
	result = a[0] + a[1] + a[2] + a[3];
	
	printf("\n Result is %d",result);
	return 0;
}

