#include <unistd.h>
#include <stdio.h>
#include <string.h>

#include "libasm.h"


int main(void)
{
	char*	s;

	s = "Salut mec\n";
	printf("Lib: %ld\n", strlen(s));
	printf("Cust: %ld\n", ft_strlen(s));

	return (0);
}
