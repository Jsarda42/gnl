#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

#include <unistd.h>
#include <fcntl.h>

typedef struct s_list
{
	char	*data;
	struct s_list	*next;

} t_list;



int	ft_strlen(char *str);

#endif
