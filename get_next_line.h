#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h> 
# include <stdio.h>
# include <fcntl.h>


size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char *buffer, char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_endl(char *str);
char	*ft_get_line(char *buffer);
char	*ft_new_str(char *buffer);
char	*ft_read_str(int fd, char *buffer);
char	*get_next_line(int fd);

#endif
