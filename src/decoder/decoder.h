#ifndef DECODER_H
# define DECODER_H
# include <stdio.h>
# include "../encoder/encoder.h"

int		read_memory(unsigned char **data);
t_lst	*recreate_dictionary(unsigned char *data);
char	*decode_text(unsigned char *data, t_lst *dictionary);
key_t	get_key(void);
int		get_block(key_t key);
void	finalize_shm(unsigned char *data, char *text, int old_shmid);
void	add_info_to_text(char **text, unsigned char *data);

#endif