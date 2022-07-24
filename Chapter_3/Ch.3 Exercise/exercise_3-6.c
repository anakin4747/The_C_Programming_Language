#include <stdio.h>
#include <string.h>
#include <math.h>

#define SIZE 40
#define WORDSIZE 32 // Switch to 64 for 64 bit systems

char * itoa(int x, char s[], int w);

int main(int argc, char *argv[]){
	char s[SIZE];
	int largest = -1 * pow(2, WORDSIZE - 1);
	printf("%s\n", itoa(largest, s, 16));
	return 0;
}

char * itoa(int x, char s[], int w){
	int i, sign;
	unsigned n = x;	// This line is the line that solves 3-4
	/*
		x is a signed int so for it to hold every bit of x 
		an unsigned int should be used to store every bit
	*/

	if((sign = n) < 0) // If n is negative 
		n = -n;	// make it positive
	// But before making it positive save the signed value in sign
	// so that we can check the sign again later

	i = 0;
	do{
		s[i++] = n % 10 + '0';	
		/* Get the ones digit with % 10 
		   Convert to char with + '0'
		   Add this ones digit to the string at i then increment i
		   Note that this places it in the reverse order
		*/ 
	} while((n /= 10) > 0); // While n divide by 10 holds value
		// Divide by 10 so the next digit gets shifted to the ones place to moduloed in the loop
	
	if(sign < 0)
		s[i++] = '-';	// If the number was negative add the negative sign to the end of the string
	while(i != w){
		s[i++] = ' ';
	}
	s[i] = '\0';	// Add string terminating char
	strrev(s);	// Reverse string to put it in the correct order 
	return s;
}
