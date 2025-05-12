// Passed Moulinette 2019.09.01

// This code is heavily influenced by @jochang's solution: github.com/MagicHatJo

typedef struct 	s_point {
	int			x;				// x : Width  | x-axis
	int			y;				// y : Height | y-axis
}				t_point;
 
// Función recursiva de relleno:
	// cur: punto actual en la recursión
	// to_fill: carácter original que queremos reemplazar
void	fill(char **tab, t_point size, t_point cur, char to_fill)
{
	// 1. Comprueba límites y carácter
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x 
        || tab[cur.y][cur.x] != to_fill)
		return ;
	// 2. Rellena posición actual
	tab[cur.y][cur.x] = 'F';
	// 3. Rellena en 4 direcciones
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill); // Izquierda (x-1)
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill); // Derecha (x+1)
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill); // Arriba (y-1)
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill); // Abajo (y+1)
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	// Inicia el relleno desde el punto begin
	fill(tab, size, begin, tab[begin.y][begin.x]);
	/*
	tab[begin.y][begin.x] // Obtiene el carácter en posición inicial
	tab[y][x] porque:
	- Primera dimensión [y]: selecciona la fila
	- Segunda dimensión [x]: selecciona la columna
	*/
}
