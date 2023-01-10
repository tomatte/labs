#ifndef ENCODER_H
# define ENCODER_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../../libft/libftprintf.h"

typedef struct	s_lst
{
	char				c;
	int					times;
	struct s_lst	*next;
}	t_lst;

typedef struct	s_tree
{
	char			c;
	struct s_tree	*left;
	struct s_tree	*right;
}	t_tree;

//lst
t_lst	*lst_new(char c);
t_lst	*lst_find(t_lst *lst, char c);
void	lst_push(t_lst *lst, t_lst *node);

//others
t_lst	*get_frequency(char *filename);
char	*read_file(int fd);

#endif