/*
Ir de big endian a formato normal.

1) n = 0;
0001 0000	0011 0000	0010 0101	1111 0100
&
1111 1111	0000 0000	0000 0000	0000 0000	
-----------------------------------------------
0001 0000	0000 0000	0000 0000	0000 0000 = resultado_1

n = 0 + resultado_1;

2)
0001 0000	0011 0000	0010 0101	1111 0100
&
0000 0000	1111 1111	0000 0000	0000 0000
-----------------------------------------------
0000 0000	0011 0000	0000 0000	0000 0000 = resultado_2

n = 0 + resultado_1 + resultado_2; 


3)
0001 0000	0011 0000	0010 0101	1111 0100
&
0000 0000	0000 0000	1111 1111	0000 0000
-----------------------------------------------
0000 0000	0000 0000	0010 0101	0000 0000 = resultado_3

n = 0 + resultado_1 + resultado_2 + resultado_3;

y lo mismo para el 4).
*/

#include <stdio.h>

#define MASK_BYTE			0xFF /* 1111  1111 */

#define MSG_ERROR_NULL_POINTER		"Puntero null"

#define MAX_SIZE 65

typedef unsigned int uint; 

typedef enum {
	OK,
	ERROR_NULL_POINTER,
	MAX_ERRORS
} status_t;

void print_num_in_binary(uint num);

status_t big_endian_to_decimal(uint v[], uint num);

int main(void)
{
	status_t st;
	size_t i;
	uint num =  271590900, nn;

	uint v[4];

	print_num_in_binary(num);
	putchar('\n');


	if((st = big_endian_to_decimal(v, num)) != OK)
	{
		fprintf(stderr, "%s%s\n", "Error:", MSG_ERROR_NULL_POINTER);
		return st;
	}

	return OK;

}



void print_num_in_binary(uint num)
{
	size_t i;
	char v[MAX_SIZE];


	for (i = 0; i < sizeof(uint) * 8; i++)
	{
		v[i] = num & (1 << (sizeof(uint) * 8 - 1 -i)) ? '1' : '0';
	}
	v[i] = putchar('\0'); 
	puts(v);

	return ;
}




/*Big endian es dividir un numero de varios bytes en binario en sus fragmetos de bytes, escribiendo primero el byte mas significativo en hexa y ultimo el menos significativo en hexa.*/
status_t big_endian_to_decimal(uint v[], uint num)
{
	size_t i;
	uint result = 0;

	if (v == NULL)	
		return ERROR_NULL_POINTER;
	
	for ( i = 0; i < sizeof(uint); i++)
	{	
		v[i] = num & (MASK_BYTE << ((sizeof(uint) - 1 - i) * 8)); 
	}

	for( i = 0; i < 4; i++)
	{
		printf("%d\n", v[i]);
		result += v[i];
	}

	printf("%d\n", result);
	return OK;
}

