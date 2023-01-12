#ifndef DECODER_H
# define DECODER_H
# include <stdio.h>
# include "../encoder/encoder.h"

void	read_memory(char **data);
t_lst	*recreate_dictionary(char *data);
char	*decode_text(char *data, t_lst *dictionary);
key_t	get_key(void);
key_t	get_block(key_t key);
void	finalize_shm(char *mem);

#endif