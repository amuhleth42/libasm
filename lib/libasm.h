#ifndef	STDLIB_H
# define STDLIB_H

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dest, const char *src);
int	ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fd, const void *buf, size_t count);
ssize_t	ft_read(int fd, void *buf, size_t count);
char	*ft_strdup(const char *s);

// ft_atoi_base
// ft_list_push_front
// ft_list_size
// ft_list_sort
// ft_list_remove_if
//

typedef struct	s_list
{
	void		*data;
	struct s_list	*next;
}		t_list;


#endif
