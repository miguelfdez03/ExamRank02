void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i = 0;
	int temp;

	while (i < (size - 1)) // to [5,3,1,4,2] => size = 5
	//                     index  0 1 2 3 4
	// i < (size - 1) compara hasta i = 3 y último acceso es tab[3] y tab[4]
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0; //Empezamos de nuevo desde el principio
		}
		else
			i++;
	}
}
