NAME =	fractol
SRC_DIR =	./src/
OBJ_DIR =	./obj/
HEADERS_DIR =	./includes/
LIBMLX_DIR =	./mlx/
PRINTF_DIR =	./printf/
LIBFT_DIR =		./libft/

SRC_LIST =	main.c \
			window.c \
			draw.c \
			hooks.c

OBJ_LIST =	$(SRC:.c=.o)
HEADERS_LIST =	fractol.h \
				error.h

SRC =	$(addprefix $(SRC_DIR), $(SRC_LIST))
OBJ =	$(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))
HEADERS =	$(addprefix $(HEADERS_DIR), $(HEADERS_LIST))
LIBMLX =	$(addprefix $(LIBMLX_DIR), libmlx.a)
LIBFTPRINTF =	$(addprefix $(PRINTF_DIR), libftprintf.a)
LIBFT =		$(addprefix $(LIBFT_DIR), libft.a)

RM =	rm -rf
CC =	gcc
CFLAGS =	-Wall -Wextra -Werror
LDFLAGS	=	-L$(LIBFT_DIR) -L$(PRINTF_DIR) -L$(LIBMLX_DIR) -lmlx -Lmlx -framework OpenGL -framework Appkit -lz

all:	$(PRINTF) $(LIBFT) $(NAME)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c $(HEADERS) | $(OBJ_DIR)
			$(CC) -I$(HEADERS_DIR) $(CFLAGS) -c $< -o $@

$(LIBFT):
		make -C $(LIBFT_DIR)

$(PRINTF):
		make -C $(PRINTF_DIR)

$(LIBMLX):
		make -C $(LIBMLX_DIR)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LIBFTPRINTF) $(LDFLAGS) -o $@

$(OBJ_DIR):
		mkdir $(OBJ_DIR)

clean:
		$(RM) $(OBJS_DIR)
		make clean -C ./libft/
		#make clean -C ./printf/
		#make clean -C ./mlx/

fclean:	clean
		$(RM) $(NAME)
		make fclean -C ./libft/
		make fclean -C ./printf/

re:	fclean $(OBJ_DIR) all