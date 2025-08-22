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
	char	*s;
	s = "Salut mec\n";

	printf("---------FT_STRLEN\n");
	
	printf("TEST 1 : \"Salut mec\"\n");
	printf("Lib: %ld\n", write(1, s, strlen(s)));
	printf("Cust: %ld\n", ft_write(1, s, strlen(s)));

	s = "";
	printf("TEST 2 : \"\"\n");
	printf("Lib: %ld\n", strlen(s));
	printf("Cust: %ld\n", ft_strlen(s));

	printf("\n----------FT_STRCMP\n");
	printf("TEST 1 : salut, bonjour\n");
	s = "salut";
	char*	s2 = "bonjour\n";
	printf("Lib: %d\n", strcmp(s, s2));
	printf("Cust: %d\n", ft_strcmp(s, s2));
	
	s = "bonjour";
	printf("TEST 2 : bonjour, bonjour\n");
	printf("Lib: %d\n", strcmp(s, s2));
	printf("Cust: %d\n", ft_strcmp(s, s2));
	
	
	printf("\n-----------FT_STRCPY\n");
	char	dest1[25];
	char	dest2[25];
	
	printf("TEST 1 : copy of \"bonjour\"\n");
	printf("Lib: %s\n", strcpy(dest1, s));
	printf("Cust: %s\n", ft_strcpy(dest2, s));

	s = "ich bin ein Berliner";
	printf("TEST 2 : copy of \"ich bin ein Berliner\"\n");
	printf("Lib: %s\n", strcpy(dest1, s));
	printf("Cust: %s\n", ft_strcpy(dest2, s));
	
	s = "";
	printf("TEST 3 : copy of \"\"\n");
	printf("Lib: %s\n", strcpy(dest1, s));
	printf("Cust: %s\n", ft_strcpy(dest2, s));


	printf("\n-----------FT_STRDUP\n");
	s = "ich bin ein Berliner";
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
	printf("TEST : duplication of \"ich bin ein Berliner\"\n");
	printf("Lib: %s\n", dup1);
	printf("Cust: %s\n", dup2);

	free(dup1);
	free(dup2);
	

	printf("\n-----------FT_WRITE\n");
	
	printf("TEST 1: Hello -> fd: 1\n");
	int	r1 = write(1, "Hello\n", 6);
	int	r2 = ft_write(1, "Hello\n", 6);
	printf("Lib: %d\n", r1);
	printf("Cust: %d\n", r2);

	printf("TEST 2: \"\" -> fd: 1\n");
	r1 = write(1, "", 0);
	r2 = ft_write(1, "", 0);
	printf("Lib: %d\n", r1);
	printf("Cust: %d\n", r2);
	
	printf("TEST 3: Hello -> fd: -1\n");
	r1 = write(-1, "Hello\n", 6);
	r2 = ft_write(-1, "Hello\n", 6);
	printf("Lib: %d\n", r1);
	printf("Cust: %d\n", r2);

	printf("\n-------BONUS-------\n");
	t_list	*lst;
	lst = NULL;

	printf("TEST 1 : 0 elem list: \n");
	printf("ft_list_size: %d\n", ft_list_size(lst));
	print_list(lst);

	printf("\nTEST 2 : 1 elem: banana \n");
	ft_list_push_front(&lst, "banana");
	printf("ft_list_size: %d\n", ft_list_size(lst));
	print_list(lst);

	printf("\nTEST 3 : 3 elem \n");
	ft_list_push_front(&lst, "apple");
	ft_list_push_front(&lst, "cherry");
	print_list(lst);
	printf("ft_list_size: %d\n", ft_list_size(lst));
	
	printf("\nTEST 4 : sorted \n");
	ft_list_sort(&lst, ft_strcmp);
	print_list(lst);
	return (0);
}
