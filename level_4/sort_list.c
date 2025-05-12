// Passed Moulinette 2019.09.01

#include "list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int temp;
	t_list *begin = lst;

	while (lst && lst->next)
	{
		if ((*cmp)(lst->data, lst->next->data) == 0)
		{
			temp = lst->data;
            		lst->data = lst->next->data;
            		lst->next->data = temp;
            		lst = begin;
		}
		else
			lst = lst->next;
	}
	return (begin);
}
