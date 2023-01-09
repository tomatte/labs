#------------------- encoder ------------------------

SRC_ENCODER			=	encoder.c \


OBJS_DIR_ENCODER		=	objects_encoder

OBJS_ENCODER			=	$(patsubst %.c,objects_encoder/%.o, $(SRC_ENCODER))

NAME_ENCODER			=	encoder

#---------------------------------------------------

#------------------- decoder ------------------------

SRC_DECODER			=	decoder.c \
						



OBJS_DIR_DECODER		=	objects_decoder

OBJS_DECODER			=	$(patsubst %.c,objects_decoder/%.o, $(SRC_DECODER))

NAME_DECODER			=	decoder

#---------------------------------------------------

CFLAGS		=	-I./

NAME		=	minitalk

VPATH				=	./src/encoder \
						./src/decoder \

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

fclean:	clean
	rm -f ${NAME_ENCODER} ${NAME_DECODER}

re: fclean all

.PHONY:	all clean fclean re