#include <stdio.h>

#define MAX_SIZE				65

#define PORCENTAJE_CAMBIO_BRILLO	10

#define MASK					0xFF

#define MAX_RGB_VALUE			0xFFFFFF

typedef unsigned char uchar;

typedef unsigned int uint;

uchar rojo(uint rojo);

uchar verde(uint verde);

uchar azul(uint azul);

void print_num_in_binary_32_bits(uint num);

void print_num_in_binary_8_bits(uchar num);

void componentes_rgb(uint color);

uint mezclar_colores(uint color_1, uint color_2);

uint mezclar_colores_OR(uint color_1, uint color_2);

uint mezclar_colores_valor_medio(uint color_1, uint color_2);

uint modificar_brillo_aumnetar(uint color, size_t i);

uint modificar_brillo_disminuir(uint color, size_t i);

uint color_complement (uint color);



int main(void)
{
	uint	value = 0xFFCCAA;
	uint 	color_1 = 0xE4C7B8;
	uint 	color_2 = 0xF89EA9;
	uint 	mezcla;
	uint 	color_aumentado, complemento;
	uchar red, green, blue;

	/*
	printf("El numero inicial del enunciado: 0xFFCCAA\n");
	print_num_in_binary_32_bits(value);


	red = rojo(value);
	print_num_in_binary_8_bits(red);
	printf("En decimal:%d\nEn Hexa:%X\n\n", red, red);

	green = verde(value);
	print_num_in_binary_8_bits(green);
	printf("En decimal:%d\nEn Hexa:%X\n\n", green, green);


	blue = azul(value);
	print_num_in_binary_8_bits(blue);
	printf("En decimal:%d\nEn Hexa:%X\n\n", blue, blue);
	*/
	/*
	componentes_rgb(value);
	*/
	printf("Color 1\n");
	componentes_rgb(color_1);
	printf("Color 2\n");
	componentes_rgb(color_2);

	/*
	printf("La mezcla de color 1 y color 2 sumandolos es:\n");
	mezcla = mezclar_colores(color_1, color_2);
	
	print_num_in_binary_32_bits(mezcla);
	
	componentes_rgb(mezcla);
	
	printf("La mezcla de color 1 y color 2 con OR es:\n");
	mezcla = mezclar_colores_OR(color_1, color_2);
	
	print_num_in_binary_32_bits(mezcla);
	
	componentes_rgb(mezcla);
	*/

	printf("La mezcla de color 1 y color 2 valor medio es:\n");
	print_num_in_binary_32_bits(color_1);
	print_num_in_binary_32_bits(color_2);

	mezcla = mezclar_colores_valor_medio(color_1, color_2);
	print_num_in_binary_32_bits(mezcla);
	componentes_rgb(mezcla);


	printf("Aumentarle el brillo a color 1 en un %d%%:\n", PORCENTAJE_CAMBIO_BRILLO);
	color_aumentado = modificar_brillo_aumnetar( color_1, PORCENTAJE_CAMBIO_BRILLO);
	print_num_in_binary_32_bits(color_aumentado);
	componentes_rgb(color_aumentado);

	printf("Invertir los valores del color es:");
	complemento = color_complement( color_1);
	print_num_in_binary_32_bits(complemento);
	componentes_rgb(complemento);

	return 0;

}

uchar rojo(uint value)
{
	return ((value >> 16) & MASK);
}

uchar verde(uint value)
{
	return ((value >> 8) & MASK);
}

uchar azul(uint value)
{
	return (value & MASK);
}


void print_num_in_binary_32_bits(uint num)
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

void componentes_rgb(uint color)
{
	uchar red, green, blue;

	red = rojo(color);
	green = verde(color);
	blue = azul(color);

	printf("Rojo: ");
	printf("%d\n%X\n\n", red, red);

	printf("Verde: ");
	printf("%d\n%X\n\n", green, green);


	printf("Azul: ");
	printf("%d\n%X\n\n", blue, blue);

	return ;
}

void print_num_in_binary_8_bits(uchar num)
{
	size_t i;
	char v[MAX_SIZE];


	for (i = 0; i < sizeof(uchar) *8 ; i++)
	{

		v[i] = num & (1 << (sizeof(uchar) * 8 - 1 -i)) ? '1' : '0';
	}
	v[i] = putchar('\0'); 
	puts(v);
	putchar('\n');

	return ;
}

uint mezclar_colores(uint color_1, uint color_2)
{
	uint mezcla;

	mezcla = color_1 + color_2;

	if (mezcla > MAX_RGB_VALUE)
	{
		mezcla = MAX_RGB_VALUE;
	}

	return mezcla;
}

uint mezclar_colores_OR(uint color_1, uint color_2)
{
	return color_1 | color_2;
}

uint mezclar_colores_valor_medio(uint color_1, uint color_2)
{
	uint mezcla;
	uchar mezcla_r, mezcla_v, mezcla_a;

	mezcla_r = (rojo(color_1) + rojo(color_2))/2;
	mezcla_v = (verde(color_1) + verde(color_2))/2;
	mezcla_a = (azul(color_1) + azul(color_2))/2;

	mezcla = (mezcla_r << 16) + (mezcla_v << 8) + (mezcla_a);

	return mezcla;
}


uint modificar_brillo_aumnetar(uint color, size_t i)
{
	float j;

	uint color_r, color_v, color_a;


	if( (j = i) > 100)
		j = 100;

	color_r = rojo(color) * (1 + (j/100.0));
	if(color_r > MASK)
		color_r = MASK;	

	color_v = verde(color) + (verde(color) * (j/100.0));
	if(color_v > MASK)
		color_v = MASK;

	color_a = azul(color) + (azul(color) * (j/100.0));
	if(color_a > MASK)
		color_a = MASK;


	return (color_r << 16) + ((color_v << 8) + (color_a));	

}


uint modificar_brillo_disminuir(uint color, size_t i)
{
	float j;

	uint color_r, color_v, color_a;


	if( (j = i) > 100)
		j = 100;

	color_r = rojo(color) - rojo(color) * (j/100);
	if(color_r > 255)
		color_r = 255;	

	color_v = verde(color) - verde(color) * (j/100);
	if(color_v > 255)
		color_v = 255;

	color_a = azul(color) - azul(color) * (j/100);
	if(color_a > 255)
		color_a = 255;


	return (color_r << 16) + (color_v << 8) + (color_a);	

}

uint color_complement (uint color)
{
	return ~color;
}