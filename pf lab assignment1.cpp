#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()
{
	
	int distance;
	printf("Enter distance in Kilometers : ");
	scanf("%d",&distance);
	
	printf("%dKm = %dm \n",distance,distance*1000);
	
	return 0;
}

