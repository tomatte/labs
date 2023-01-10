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
	int				times;
	struct s_tree	*left;
	struct s_tree	*right;
}	t_tree;

//lst
t_lst	*lst_new(char c);
t_lst	*lst_find(t_lst *lst, char c);
void	lst_push(t_lst *lst, t_lst *node);
int		lst_size(t_lst *lst);

//tree
t_tree	*new_node(char c, int times);

//others
t_lst	*get_frequency(char *filename);
char	*read_file(int fd);
t_tree	**get_nodes(t_lst *frequency);
void	order_nodes(t_tree **nodes, int size);
t_tree	*create_tree(t_tree **nodes, int size);

#endif