NAME := fractol
NAME_BONUS := fractol_bonus

MLX_FLAGS := -ldl -lglfw -pthread -lm
CC := cc -Wall -Werror -Wextra -Wunreachable-code -Ofast
LIBFT := ./lib/libft/libft.a
LIBMLX := ./lib/MLX42/build/libmlx42.a
BINDIR := ./bin
MANDATORY := ./src/mandatory
BONUS := ./src/bonus

HEADERS := -I ./include -I $(LIBMLX)/include -I $(LIBFT)
LIBS := $(LIBMLX)/build/libmlx42.a $(LIBFT)/libft.a -ldl -lglfw -pthread -lm

MANDATORY_SRCS := colors.c hook.c main.c math.c utils.c mouse.c message.c
BONUS_SRCS := colors_bonus.c hook_bonus.c main_bonus.c math_bonus.c utils_bonus.c mouse_bonus.c message_bonus.c

MANDATORY_OBJS := $(patsubst %.c, $(BINDIR)/mandatory/%.o, $(MANDATORY_SRCS))
BONUS_OBJS := $(patsubst %.c, $(BINDIR)/bonus/%.o, $(BONUS_SRCS))

all: libs $(BINDIR) $(BINDIR)/mandatory $(NAME)
bonus: libmlx libft $(BINDIR) $(BINDIR)/bonus $(NAME_BONUS)

$(LIBMLX):
	cd lib/MLX42/ && cmake -B build -DDEBUG=1
	cd lib/MLX42/ && cmake --build build -j4

$(LIBFT):
	@make -C lib/libft/

libs: $(LIBFT) $(LIBMLX)

$(BINDIR) $(BINDIR)/mandatory $(BINDIR)/bonus:
	@mkdir -p $@

$(BINDIR)/mandatory/%.o: $(MANDATORY)/%.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(BINDIR)/bonus/%.o: $(BONUS)/%.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(MANDATORY_OBJS)
	@$(CC) $(MANDATORY_OBJS) $(LIBFT) $(LIBMLX) $(MLX_FLAGS) $(HEADERS) -o $(NAME)

$(NAME_BONUS): $(BONUS_OBJS)
	@$(CC) $(BONUS_OBJS) $(LIBFT) $(LIBMLX) $(MLX_FLAGS) $(HEADERS) -o $(NAME_BONUS)

clean:
	@rm -rf $(BINDIR)

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re libmlx libft bonus
