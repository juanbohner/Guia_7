#include <stdio.h>

/* 11001010&10100101, 11001010|10100101, 11001010^10100101. */
/*10100101 = 1+2^2+2^5+2^7 = 165*/
/*11001010 = 2+8+64+128 = 202*/

#define NUM_1		0xCA

#define NUM_2		0xA5

typedef unsigned char uchar;

void print_reg(uchar reg);

int main(void)
{
	uchar a = NUM_1;

	uchar b = NUM_2;
	
	printf("%s\n", "Numero a:");
	print_reg(a);
	printf("%s\n", "Numero b:");
	print_reg(b);
	putchar ('\n');
	
	printf("%s%d\n", "a&b:", a&b);
	print_reg(a);
	print_reg(b);
	print_reg(a&b);
	putchar ('\n');

	printf("%s%d\n", "a|b:", a|b);
	print_reg(a);
	print_reg(b);
	print_reg(a|b);
	putchar ('\n');

	printf("%s%d\n", "a^b:", a^b);
	print_reg(a);
	print_reg(b);
	print_reg(a^b);
	putchar ('\n');

	return 0;
}


void print_reg(uchar reg) {

  size_t i;
  printf(" _______________________________ \n");
  putchar('|');
  for(i = 0; i < sizeof(uchar) * 8; i++) {
    putchar(' ');
    putchar(reg & (1 << ((sizeof(uchar) * 8) - 1 - i)) ? '1' : '0');
    putchar(' ');
    putchar('|');
  }
  printf("\n");
  printf(" ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾ \n");  

}