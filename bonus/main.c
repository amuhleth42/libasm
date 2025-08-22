#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libasm.h"

void	print_list(t_list *lst)
{
	int i;

	i = 0;
	while (lst)
	{
		i++;
		printf("%d:elem p: %p, data: %s, next: %p\n", i, lst, (char*) lst->data, lst->next);
		lst = lst->next;
	}
}

int main(void)
{
	char*	s;
	s = "Salut mec\n";

	printf("FT_WRITE\n");
	printf("Lib: %ld\n", write(1, s, strlen(s)));
	printf("Cust: %ld\n", ft_write(1, s, strlen(s)));

	
	printf("FT_STRLEN\n");
	printf("Lib: %ld\n", strlen(s));
	printf("Cust: %ld\n", ft_strlen(s));

	printf("FT_STRCMP\n");
	char*	s2 = "bonjour\n";
	printf("Lib: %d\n", strcmp(s, s2));
	printf("Cust: %d\n", ft_strcmp(s, s2));
	
	
	printf("FT_STRCPY\n");
	char	dest1[25];
	char	dest2[25];
	printf("Lib: %s\n", strcpy(dest1, s));
	printf("Cust: %s\n", ft_strcpy(dest2, s));

	printf("FT_STRDUP\n");
	char	*dup1 = strdup(s);
	char	*dup2 = ft_strdup(s);
	if (!dup1)
	{
		printf("error dup1\n");
		return(1);
	}
	else if (!dup2)
	{
		printf("error dup2\n");
		return(1);
	}
	printf("Lib: %s\n", dup1);
	printf("Cust: %s\n", dup2);

	free(dup1);
	free(dup2);


	printf("-------BONUS-------\n");
	t_list	*lst;
	lst = NULL;

	printf("TEST 1 : 0 elem list: \n");
	printf("ft_list_size: %d\n", ft_list_size(lst));
	print_list(lst);

	printf("TEST 2 : 1 elem: banana \n");
	ft_list_push_front(&lst, "banana");
	printf("ft_list_size: %d\n", ft_list_size(lst));
	print_list(lst);

	printf("TEST 3 : 3 elem \n");
	printf("alive\n");
	ft_list_push_front(&lst, "apple");
	printf("alive\n");
	ft_list_push_front(&lst, "cherry");
	printf("alive\n");
	print_list(lst);
	printf("ft_list_size: %d\n", ft_list_size(lst));
	printf("alive\n");
	print_list(lst);
	
	printf("TEST 4 : sorted \n");
	ft_list_sort(&lst, ft_strcmp);
	print_list(lst);
	return (0);
}
