

typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;


t_list *ft_create_elem(void *data)
{
	t_list	*new;

	new = (t_list *) ft_calloc(sizeof(t_list), 1);
	if (!new)
		return (NULL);
	new->data = data;
	return (new);
}

int ft_list_size(t_list *begin_list)
{
	int	i;

	i = 0;
	while (begin_list != NULL)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}

t_list *ft_list_last(t_list *begin_list)
{
	while (begin_list->next != NULL)
		begin_list = begin_list->next;
	return (begin_list);
}

void ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*last;

	if (*begin_list == NULL)
	{
		begin_list = ft_create_elem(data);
		return ;
	}
	last = ft_lstlast(*begin_list);
	last->next = ft_create_elem(data);
	return ;
}

t_list *ft_create_elem(void *data)
{
	t_list	*new;

	new = (t_list *) ft_calloc(sizeof(t_list), 1);
	if (!new)
		return (NULL);
	new->data = data;
	return (new);
}

void ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *tmp;

	if (*begin_list == NULL)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	tmp = *begin_list;
	*begin_list = ft_create_elem(data);
	*begin_list->next = tmp;
	return ;
}

int	list_is_sorted(t_list *list, int (*cmp)())
{
	t_list	*p1;
	t_list	*p2;

	p1 = list;
	p2 = list->next;
	while (p2 != NULL)
	{
		if ((*cmp)(p1->data, p2->data) > 0)
			return (1);
		p1 = p2;
		p2 = p2->next;
	}
	return (0);
	
}

void ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*p;
	void	*tmp;
	int		swapped;

	if (begin_list == NULL || *begin_list == NULL)
		return ;
	if (*begin_list->next == NULL)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		p = *begin_list;
		while (p->next != NULL);
		{
			if ((*cmp)(p->data, p->next->data) > 0)
			{
				tmp = p->data;
				p->data = p->next->data;
				p->next->data = tmp;
				swapped = 1;
			}
			p = p->next;
		}
	}
}

void	ft_lstdelone(t_list *lst, void (*free_fct)(void *))
{
	(*free_fct)(lst->data);
	free(lst);
}

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*prev;
	t_list	*curr;
	t_list	*tmp;

	if (begin_list == NULL || *begin_list == NULL)
		return ;

	prev = NULL;
	curr = *begin_list;

	while ()
	{
		if ((*cmp)(curr->data, data_ref) == 0)
		{
			if (prev == NULL)
				*begin_list = curr->next;
			else
				prev->next = curr->next;
			tmp = curr->next;
			ft_lstdelone(curr, free_fct);
			curr = tmp;
		}
		else
		{
			prev = curr;
			curr = curr->next;
		}
	}

}
