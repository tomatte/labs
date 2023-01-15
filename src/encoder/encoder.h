#ifndef ENCODER_H
# define ENCODER_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/ipc.h>
# include <sys/shm.h>
# include <unistd.h>
# include "../../libft/libftprintf.h"

typedef struct	s_lst
{
	char				c;
	char				*code;
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

typedef struct	s_data
{
	char	*binary;
	t_lst	*dictionary;
}	t_data;

typedef struct	s_segment
{
	void	*mem;
	int		shmid;
}	t_segment;

//lst
t_lst	*lst_new(char c);
t_lst	*lst_find(t_lst *lst, char c);
void	lst_push(t_lst *lst, t_lst *node);
int		lst_size(t_lst *lst);
void	lst_clear(t_lst *lst);

//tree
t_tree	*new_node(char c, int times);
void	clear_tree(t_tree *tree);
t_tree	*get_nodes_copy(t_tree **nodes, int size);

//others
t_lst	*get_frequency(char *text);
char	*read_file(int fd);
t_tree	**get_nodes(t_lst *frequency);
void	order_nodes(t_tree **nodes, int size);
t_tree	*create_tree(t_tree **nodes, int size);
void	huffman_code(t_tree *tree, char *bits, t_lst *lst);
char	*get_text(int argc, char **argv);
char	*encode_to_binary(t_lst *frequency, char *text);
unsigned char	*compress_text(t_lst *frequency, char *text);

//shm
void		share_memory(unsigned char *compressed, t_lst *frequency);
char		**create_code_array(t_lst *frequency);
char		*create_letter_array(t_lst *frequency);
void		join_data(unsigned char *compressed, t_lst *frequency, unsigned char **data, int *size_data);
t_segment	read_shm(void);
void		dettach_segment(t_segment segment);

//text
void	verify_text_integrity(unsigned char *decompressed, unsigned char *original);

//temp
void	print_compressed_bin(unsigned char *compressed);

#endif