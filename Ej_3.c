/*

a) 0157 trasladado a izquierda una posición de bit		
0157(octal) 	=	111 (decimal)

b) 0701 trasladado a izquierda dos posiciones de bit,
0701 (octal) 	=	448 (decimal)

c) 0673 trasladado a derecha dos posiciones de bit,
0673 			=	443


d) 067 trasladado a derecha tres posiciones de bit. 
067				=	55

*/

#include <stdio.h>

#define NUM_A		111

#define NUM_B		448

#define NUM_C		443

#define NUM_D		55

typedef unsigned short int uint;

uint left_shift_one_bit(uint a);
uint left_shift_two_bits(uint a);
uint rigth_shift_two_bits(uint a);
uint right_shift_tree_bits(uint a);

void print_reg(uint reg);


int main(void)
{
	uint a = NUM_A, b = NUM_B, c = NUM_C, d = NUM_D;

	printf("Numero originales\n");

	/*Imprimo como son originalmente*/
	print_reg(a);
	print_reg(b);
	print_reg(c);
	print_reg(d);

	/*Su represenatcion en valorea octales y decimales antes de haberlos corrido.*/
	printf("%s%o\t%s%d\n", "El numero en octal es:", a, "El numero en decimal es:", a);
	printf("%s%o\t%s%d\n", "El numero en octal es:", b, "El numero en decimal es:", b);
	printf("%s%o\t%s%d\n", "El numero en octal es:", c, "El numero en decimal es:", c);
	printf("%s%o\t%s%d\n", "El numero en octal es:", d, "El numero en decimal es:", d);


	/*Los corro segun lo que me pide el ejercicio*/
	a = left_shift_one_bit(a); 

	b = left_shift_two_bits(b);
	
	c = rigth_shift_two_bits(c);

	d = right_shift_tree_bits(d);

	putchar ('\n');
	printf("Numero modificados\n");

	/*Los imprimo corridos*/
	print_reg(a);
	print_reg(b);
	print_reg(c);
	print_reg(d);

	/*Su represenatcion en valorea octales y decimales despues de haberlos corrido.*/
	printf("%s%o\t%s%d\n", "El numero en octal es:", a, "El numero en decimal es:", a);
	printf("%s%o\t%s%d\n", "El numero en octal es:", b, "El numero en decimal es:", b);
	printf("%s%o\t%s%d\n", "El numero en octal es:", c, "El numero en decimal es:", c);
	printf("%s%o\t%s%d\n", "El numero en octal es:", d, "El numero en decimal es:", d);

	return 0;
}

void print_reg(uint reg) {

  size_t i;
  printf(" _______________________________________________________________ \n");
  putchar('|');
  for(i = 0; i < sizeof(uint) * 8; i++) {
    putchar(' ');
    putchar(reg & (1 << ((sizeof(uint) * 8) - 1 - i)) ? '1' : '0');
    putchar(' ');
    putchar('|');
  }
  printf("\n");
  printf(" ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾ \n");  

}


uint left_shift_one_bit(uint a)
{
	return a >> 1;
}

uint left_shift_two_bits(uint a)
{
	return a >> 2;
}

uint rigth_shift_two_bits(uint a)
{
	return a << 2;
}

uint right_shift_tree_bits(uint a)
{
	return a << 3;
}
