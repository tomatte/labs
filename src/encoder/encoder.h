#ifndef ENCODER_H
# define ENCODER_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../../libft/libftprintf.h"

void	frequency(char *filename);
char	*read_file(int fd);

typedef struct	s_lst
{
	char				c;
	int					times;
	struct s_lst	*next;
}	t_lst;

//lst
t_lst	*lst_new(char c);
t_lst	*lst_find(t_lst *lst, char c);

#endif