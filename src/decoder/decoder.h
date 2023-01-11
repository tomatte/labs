#ifndef DECODER_H
# define DECODER_H
# include <stdio.h>
# include "../encoder/encoder.h"

void	read_memory(char **data);
t_lst	*recreate_dictionary(char *data);

#endif