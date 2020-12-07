#include <stdio.h>

#define MASK_BIT	1

#define VAL_A_MOVER		3

typedef unsigned char uchar;

#define MOVIL_MASK 		sizeof(uchar) * 8 - 1

uchar move_mask(size_t i);

uchar move_mask(size_t i);

uchar OR_operation(uchar n);
uchar AND_operation(uchar n);

void print_binary_representation(uchar num);

int main (void)
{
	uchar num = 156;
	uchar num_OR, num_AND;

	print_binary_representation(num);

	num_OR = OR_operation(num);

	print_binary_representation(num_OR);

	num_AND = AND_operation(num);

	print_binary_representation(num_AND);

	return 0;

}

uchar OR_operation(uchar n)
{
	return n | move_mask(VAL_A_MOVER);
}

uchar AND_operation(uchar n)
{
	return n & (~move_mask(VAL_A_MOVER));
}

uchar move_mask(size_t i)
{
	return MASK_BIT << i;
}

void print_binary_representation(uchar num)
{
	size_t i;

	printf(" _______________________________\n");

  	putchar('|');
	
	for (i = 0; i < sizeof(uchar) * 8; i++)
	{
		putchar(' ');
		putchar(num & (MASK_BIT << ( MOVIL_MASK -i)) ? '1' : '0');
		putchar(' ');
		putchar('|');
	}

	printf("\n");
  	printf(" ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n");
	return ;
}
