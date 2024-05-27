#include<stdio.h>
#include<stdlib.h>
/*
write a program using recursive function that calculates the sum of the first n elements 
from harmonic series and print the sum from the main function.Also,the function displays the series
elements.n is entered by the user.The nth harmonic sequence element is calculated as 1/(a+(n-1)d). 
Consider a = 1,d = 1 and n > 0
*/
float harmonic(int x){
	static float total = 0;
	if(x == 0)
	return total;
	else{	
		total += 1.0/x;
		return harmonic(x-1);
	}
	
	
}
int main(){
	int n;
	float sum;
	printf("Enter a number: \n"); scanf("%d",&n);
	sum = harmonic(n);
	printf("Sum of the series is:%f",sum);
	
	return 0;
}
