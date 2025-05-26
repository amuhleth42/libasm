#include <stdio.h>
#include <string.h>


size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}

char	*ft_strdup(const char *s)
{
	char	*dest;

	dest = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dest)
		return (NULL);
	return (ft_strcpy(dest, s));
}

int main(int argc, char** argv)
{
	char*	s = "hello world ajksdlf ajkdsfl";

	printf("Lib: %ld\n", strlen(s));
	printf("Cus: %ld\n", ft_strlen(s));

	if (argc < 3)
		return (1);
	printf("Lib: %d\n", strcmp(argv[1], argv[2]));
	printf("Cus: %d\n", ft_strcmp(argv[1], argv[2]));

}
