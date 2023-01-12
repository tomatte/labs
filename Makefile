#------------------- common ---------------------------

SRC_COMMON			=	lst_new.c \
						lst_find.c \
						lst_push.c \
						lst_size.c \
						lst_clear.c \

#------------------- encoder ------------------------

SRC_ENCODER			=	encoder.c \
						read_file.c \
						get_frequency.c \
						new_node.c \
						get_nodes.c \
						order_nodes.c \
						create_tree.c \
						huffman_code.c \
						clear_tree.c \
						get_text.c \
						share_memory.c \
						create_code_array.c \
						create_letter_array.c \
						join_data.c \
						encode_to_binary.c \
						compress_text.c \
						read_shm.c \



OBJS_DIR_ENCODER		=	objects_encoder

OBJS_ENCODER			=	$(patsubst %.c,objects_encoder/%.o, $(SRC_ENCODER) $(SRC_COMMON))

NAME_ENCODER			=	encoder

#---------------------------------------------------

#------------------- decoder ------------------------

SRC_DECODER			=	decoder.c \
						read_memory.c \
						recreate_dictionary.c \
						decode_text.c \
						finalize_shm.c \
						


#------------------------------------------------------


OBJS_DIR_DECODER		=	objects_decoder

OBJS_DECODER			=	$(patsubst %.c,objects_decoder/%.o, $(SRC_DECODER) $(SRC_COMMON))

NAME_DECODER			=	decoder

#---------------------------------------------------

LIBFT		=	./libft/libftprintf.a

CFLAGS		=	-I./ -g

NAME		=	minitalk

VPATH				=	./src/encoder \
						./src/decoder \
						./src/encoder/lst \
						./src/encoder/others \
						./src/encoder/tree \
						./src/encoder/shm \
						./src/decoder/others \

$(OBJS_DIR_ENCODER)/%.o:	%.c
							$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR_DECODER)/%.o:	%.c
							$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(OBJS_DIR_ENCODER):
						mkdir -p $@

$(OBJS_DIR_DECODER):
						mkdir -p $@

$(NAME_ENCODER): $(OBJS_DIR_ENCODER) $(OBJS_ENCODER) $(LIBFT)
	cc ${OBJS_ENCODER} ${CFLAGS} ${LIBFT} -o $@

$(NAME_DECODER): $(OBJS_DIR_DECODER) $(OBJS_DECODER) $(LIBFT)
	cc ${OBJS_DECODER} ${CFLAGS} ${LIBFT} -o $@
	
$(NAME): $(NAME_ENCODER) $(NAME_DECODER)

$(LIBFT):
	make -C ./libft bonus

clean:
	rm -rf ${OBJS_DIR_ENCODER} ${OBJS_DIR_DECODER}
	make -C ./libft clean

fclean:	clean
	rm -f ${NAME_ENCODER} ${NAME_DECODER}
	make -C ./libft fclean

re: fclean all

push:
	git push
	git push 42 main

.PHONY:	all clean fclean re