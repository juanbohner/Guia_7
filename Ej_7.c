/*Programa para invertir los bits*/

#include <stdio.h>

typedef unsigned char uchar;

#define MASK				1

#define MAX_LEN				9

void display_bits(uchar num);

int main(void)
{	
	uchar numero = 124;

	printf("%s\n", "Numero original:");
	display_bits(numero);


	printf("%s\n", "Complemento de numero original:");
	display_bits(~numero);



	return 0;
}

void display_bits(uchar num){
	size_t i;

	char str[MAX_LEN];

	for(i = 0; i < sizeof(uchar) * 8; i++)
	{
		str[i] = (num & (MASK << (sizeof(uchar) * 8 - 1 -i))) ? '1' : '0';
	}
	str[i] = '\0';
	puts(str);
	return ;
}