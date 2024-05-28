
FLAGS = -g3 -Wall -Wextra -Werror
MLX_FLAGS = -ldl -lglfw -pthread -lm
INCLUDES = -I ./lib/
OBJ_DIR = obj/
OBJ_DIR_BONUS = obj_bonus/
SRC = src/mandatory/
SRC_BONUS = src/bonus/
NAME = fractal
NAME_BONUS = fractal_bonus
LIBFT_PATH = lib/libft/libft.a 
MLX_PATH = lib/MLX42/build/libmlx42.a

src += main.c colors.c hook.c math.c message.c mouse.c utils.c

src_bonus += main_bonus.c colors_bonus.c hook_bonus.c math_bonus.c message_bonus.c mouse_bonus.c utils_bonus.c

SRC_OBJ = $(addprefix $(OBJ_DIR), $(src:.c=.o))

SRC_OBJ_BONUS = $(addprefix $(OBJ_DIR_BONUS), $(src_bonus:.c=.o))

all: libft build_mlx $(NAME)

bonus: libft build_mlx $(NAME_BONUS)

$(OBJ_DIR)%.o: $(SRC)%.c
	@mkdir -p $(OBJ_DIR)
	@cc $(FLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR_BONUS)%.o: $(SRC_BONUS)%.c
	@mkdir -p $(OBJ_DIR_BONUS)
	@cc $(FLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(SRC_OBJ)
	@cc $(FLAGS) $(INCLUDES) $(SRC_OBJ) $(LIBFT_PATH) $(MLX_PATH) $(MLX_FLAGS) -o $(NAME)

$(NAME_BONUS): $(SRC_OBJ_BONUS)
	@cc $(FLAGS) $(INCLUDES) $(SRC_OBJ_BONUS) $(LIBFT_PATH) $(MLX_PATH) $(MLX_FLAGS) -o $(NAME_BONUS)

build_mlx:
ifeq (,$(wildcard $(MLX_PATH)))
	@cd lib && \
	git clone https://github.com/codam-coding-college/MLX42.git && \
	cd MLX42 && \
	sed -i 's/cmake_minimum_required (VERSION 3.18.0)/cmake_minimum_required (VERSION 3.16.0)/g' CMakeLists.txt && \
	if ! cmake -B build; then \
		echo "Failed to configure MLX42"; \
	else \
		cmake --build build -j4; \
	fi
endif

libft:
	@make -C lib/libft

clean:
	@rm -rf $(OBJ_DIR) $(OBJ_DIR_BONUS)
	@make -C lib/libft clean

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@make -C lib/libft fclean
	@rm -rf lib/MLX42

re: fclean all

.PHONY: all clean fclean re libft build_mlx