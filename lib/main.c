#include <unistd.h>
#include <stdio.h>
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
	return (0);
}
