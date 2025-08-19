#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libasm.h"


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
	
	
	printf("FT_STRCMP\n");
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

	return (0);
}
