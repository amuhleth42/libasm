#include <unistd.h>
#include <stdio.h>
#include <string.h>


int main(void)
{
	char*	s;

	s = "Salut mec\n";
	printf("Lib: %d\n", strlen(s));
	printf("Cust: %d\n", ft_strlen(s));

	return (0);
}
