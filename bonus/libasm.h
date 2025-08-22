#ifndef	STDLIB_H
# define STDLIB_H

typedef struct	s_list
{
	struct s_list	*next;
	void		*data;
}		t_list;

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dest, const char *src);
int	ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fd, const void *buf, size_t count);
ssize_t	ft_read(int fd, void *buf, size_t count);
char	*ft_strdup(const char *s);

// ft_atoi_base
void	ft_list_push_front(t_list **begin_list, void *data);
int		ft_list_size(t_list *begin_list);
void	ft_list_sort(t_list **begin_list, int (*cmp)());
// ft_list_remove_if


#endif
