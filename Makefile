NAME := fractol
NAME_BONUS := fractol_bonus

MLX_FLAGS := -ldl -lglfw -pthread -lm
CC := cc -Wall -Werror -Wextra -Wunreachable-code -Ofast
LIBFT := ./lib/libft/libft.a
LIBMLX := ./lib/MLX42/build/libmlx42.a
BINDIR := ./bin
MANDATORY := ./src/mandatory
BONUS := ./src/bonus

HEADERS := -I ./include -I ./lib/MLX42/include -I ./lib/libft
LIBS := $(LIBMLX) $(LIBFT) $(MLX_FLAGS)

MANDATORY_SRCS := colors.c hook.c main.c math.c utils.c mouse.c message.c
BONUS_SRCS := colors_bonus.c hook_bonus.c main_bonus.c math_bonus.c utils_bonus.c mouse_bonus.c message_bonus.c

MANDATORY_OBJS := $(patsubst %.c, $(BINDIR)/mandatory/%.o, $(MANDATORY_SRCS))
BONUS_OBJS := $(patsubst %.c, $(BINDIR)/bonus/%.o, $(BONUS_SRCS))

all: libs $(BINDIR) $(BINDIR)/mandatory $(NAME)
bonus: libs $(BINDIR) $(BINDIR)/bonus $(NAME_BONUS)

$(LIBMLX):
	cd lib/MLX42/ && cmake -B build -DDEBUG=1
	cd lib/MLX42/ && cmake --build build -j4

$(LIBFT):
	@make -C lib/libft/

libs: $(LIBFT) $(LIBMLX)

$(BINDIR) $(BINDIR)/mandatory $(BINDIR)/bonus:
	@mkdir -p $@

$(BINDIR)/mandatory/%.o: $(MANDATORY)/%.c
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<

$(BINDIR)/bonus/%.o: $(BONUS)/%.c
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<

$(NAME): $(MANDATORY_OBJS)
	@$(CC) $(MANDATORY_OBJS) $(LIBS) -o $(NAME)

$(NAME_BONUS): $(BONUS_OBJS)
	@$(CC) $(BONUS_OBJS) $(LIBS) -o $(NAME_BONUS)

clean:
	@rm -rf $(BINDIR)

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re libs bonus
