#ifndef LIBASM_H
# define LIBASM_H
# include <stddef.h>
# include <aio.h>
# include <unistd.h>
# include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


size_t	ft_strlen(char *s);
char	*ft_strcpy(char *dest, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t	ft_read(int fildes, void *buf, size_t nbyte);
char	*ft_strdup(const char *s);

int		ft_atoi_base(char *str, char *base);


#endif