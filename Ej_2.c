#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 65

typedef unsigned char uchar;

/*A partir de un entero, quiero imprimir la representacion binaria de ese nuemro*/

int main (void){

    uchar n_1 = 202;
	uchar n_2 = 165;
    size_t i;
    char s[MAX_SIZE];


    for(i = 0; i < sizeof(uchar) * 8; i++)
	{	
		s[i] = n_1 & (1 << (sizeof(uchar) * 8 - 1 -i)) ? '1' : '0';
    }
    s[i] = '\0';
    puts(s);

	/*Representacion en hexa y en octal*/
    printf("%X\n", n_1);
    printf("%o\n", n_1);

	putchar('\n');

	for(i = 0; i < sizeof(uchar) * 8; i++)
	{	
		s[i] = n_2 & (1 << (sizeof(uchar) * 8 - 1 -i)) ? '1' : '0';
    }
    s[i] = '\0';
    puts(s);

	/*Representacion en hexa y en octal*/
    printf("%X\n", n_2);
    printf("%o\n", n_2);

    return EXIT_SUCCESS;
}
