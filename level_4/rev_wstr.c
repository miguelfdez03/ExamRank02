#include <unistd.h>

int main(int ac, char **av)
{
	int start;
	int end;
	int first_word = 1;
	int i = 0;

	if (ac == 2)
	{
		// For the string "Hello world, from 42 Málaga" i = 25
		while (av[1][i])
			i++;
		i--;
		while (i >= 0)
		{
			// Saltamos espacios y tabs para encontrar el final de la palabra
			while(i >= 0 && (av[1][i] == ' ' || av[1][i] == '\t'))
				i--;
			end = i; //Final del ultimo caracter de la palabra
			while (i >= 0 && av[1][i] != ' ' && av[1][i] != '\t') // Buscamos inicio de la palbra (estariamos en un espacio o tab)
				i--;
			start = i + 1; //Comienzo del primer caracter de la palabra y le sumamos 1 porque estamos en un espacio o tab
			if (!first_word) // En la 1ª iteracion no imprime espacio, después ya si (espacio entre palabras)
				write(1, " ", 1);
			// Imprimir la palabra actual
			while (start <= end)
				write(1, &av[1][start++], 1);
			first_word = 0;
		}
	}
	write(1, "\n", 1);
	return (0);
}
