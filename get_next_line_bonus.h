#if !defined GET_NEXT_LINE_BONUS_H
#define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_fdlst
{
	int				fd;
	char			*remainder;
	struct s_fdlst	*next;
}	t_fdlst;


char	*get_next_line_bonus(int fd);

#endif // GET_NEXT_LINE_H