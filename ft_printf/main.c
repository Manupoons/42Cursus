#include "ft_printf.h"

int main()
{

	int	menu(void);

	int		opc;
	char	a = 'h';
	char	b = ' ';
	char	*str = NULL;

	do
	{
		opc = menu();
		switch (opc)
		{
			case 1:
				// %s Imprime una string (como se define por defecto en C)
				printf("Total %d \n",   printf("Printf_OG - Compare Char C =  %c, %c, %c, %c, END.\n", a,b,a,b));
				printf("Total %d \n",ft_printf("FT_Printf - Compare Char C =  %c, %c, %c, %c, END.\n", a,b,a,b));
				break;
			case 2:
				printf("Total %d \n",    printf("Printf_OG - Compare String S = %s\n", str));
				printf("Total %d \n", ft_printf("FT_Printf - Compare String S = %s\n", str));
				break;
			case 3:
				// %p El puntero void * dado como argumento se imprime en formato hexadecimal.
				printf("Total %d \n",   printf("Printf_OG - Imprimir direccion de puntero *str = %p \n", str));
				printf("Total %d \n",ft_printf("FT_Printf - Imprimir direccion de puntero *str = %p \n", str));
				break;
			case 4:
				// Ya he gestionado INT d y INT i
				printf("Total %d \n",    printf("Printf_OG - Imprimir ENTERO d = %d \n", INT_MIN));
				printf("Total %d \n", ft_printf("FT_Printf - Imprimir ENTERO d = %d \n", INT_MIN));
				printf("Total %d \n",    printf("Printf_OG - Imprimir ENTERO i = %d \n", INT_MAX));
				printf("Total %d \n", ft_printf("FT_Printf - Imprimir ENTERO i = %d \n", INT_MAX));
				printf("Total %d \n",    printf("Printf_OG - Imprimir ENTERO u = %u \n", INT_MIN)); //TENGO UN ERROR CON U
				printf("Total %d \n", ft_printf("FT_Prinft - Imprimir ENTERO u = %u \n", INT_MIN)); //SOLO DEBERIA PETAR CON LAS U
				break;
			case 5:
				// Hexadecimal x
				printf("Total %d \n",    printf("Printf_OG - Imprimir HEXA x = %x \n", (int) LONG_MAX));
				printf("Total %d \n", ft_printf("FT_Printf - Imprimir HEXA x = %x \n", LONG_MAX));
				printf("Total %d \n",    printf("Printf_OG - Imprimir HEXA X = %X \n", 255));
				printf("Total %d \n", ft_printf("FT_Printf - Imprimir HEXA X = %X \n", 255));
				//" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42)
				break;
			case 6:
				// Printing %%
				printf("Total %d \n",    printf("hola %%%% como estas\n"));
				printf("Total %d \n", ft_printf("hola %%%% como estas\n"));
				break;
			case 7:
				printf("Total %d \n",    printf("Printf_OG - Imprimir ENTERO u = %u \n", INT_MIN));
				printf("Total %d \n", ft_printf("FT_Prinft - Imprimir ENTERO u = %u \n", INT_MIN));
				printf("Total %d \n",    printf("Printf_OG - Imprimir ENTERO u = %u \n", -1));
				printf("Total %d \n", ft_printf("FT_Prinft - Imprimir ENTERO u = %u \n", -1));
				printf("Total %d \n",    printf("Printf_OG - Imprimir ENTERO u = %u \n", UINT_MAX));
				printf("Total %d \n", ft_printf("FT_Prinft - Imprimir ENTERO u = %u \n", UINT_MAX));
				break;
			case 8:
				printf("Total %d \n",    printf((void *)0));
				printf("Total %d \n", ft_printf((void *)0));
				break;
		}
	}
	while (opc != 0);
	return (0);
}
int menu ()
{
	int opc;

	do
	{
		printf("\nMenú\n");
		printf("\n Ordenados por la secuencia en la que salen en el pdf\n");
		printf("Son un total de 8\n");
		printf("0: Salir\n");
		printf("Opción: ");
		scanf("%d", &opc);
		fflush(stdin);
	}
	while (opc < 0 || opc > 42);
	return opc;
}
