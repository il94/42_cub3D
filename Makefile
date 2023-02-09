#==============================================================================#
#                                   TARGETS                                    #
#==============================================================================#

NAME = cub3D

#==============================================================================#
#                                   COMMANDS                                   #
#==============================================================================#

CC = gcc
# CFLAGS = -Wall -Wextra -Werror
MKDIR = mkdir -p
RM = rm -f
MAKE_SILENT = make --no-print-directory

LIBFT = -L libft -lft
LIBX = -L mlx_linux -lmlx_Linux
LIBXFLAGS = -lmlx -lXext -lX11

#==============================================================================#
#                                    COLORS                                    #
#==============================================================================#

PURPLE = \033[35m
GREEN = \033[32m
YELLOW = \033[33m
END = \033[0m

#==============================================================================#
#                                    PATHS                                     #
#==============================================================================#

SRC_DIR = src/
HEADER_DIR = include/
OBJ_DIR = obj/

#==============================================================================#
#                                   SOURCES                                    #
#==============================================================================#

SRC = main.c initialisation.c free_memory.c parsing.c parsing_utils.c \
		parsing_data_map.c parsing_map.c init_mlx.c input_keyboard.c run.c put_render.c \

#==============================================================================#
#                                   HEADERS                                    #
#==============================================================================#

HEAD = $(addprefix $(HEADER_DIR), cub3D.h) \

#==============================================================================#
#                                   OBJECTS                                    #
#==============================================================================#

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

#==============================================================================#
#                                   MAKEFILE                                   #
#==============================================================================#

all : $(OBJ_DIR) $(NAME)

$(NAME) : $(OBJ)
	$(MAKE_SILENT) -C libft
	$(MAKE_SILENT) -C mlx_linux	
	echo "$(YELLOW)Making Cub3D$(END)"
	$(CC) $(OBJ) $(LIBFT) $(LIBX) $(LIBXFLAGS) -o $(NAME)
	echo "$(GREEN)Done$(END)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEAD) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR) :
	$(MKDIR) $(OBJ_DIR)

bonus : all

clean :
	$(MAKE_SILENT) fclean -C libft
	echo "$(PURPLE)Cleaning Mlx's objects..$(END)"
	$(MAKE_SILENT) clean -C mlx_linux
	echo "$(PURPLE)Cleaning Cub3D's objects...$(END)"
	$(RM)r $(OBJ_DIR)
	echo "$(GREEN)Done$(END)"

fclean : clean
	echo "$(PURPLE)Cleaning Cub3D...$(END)"
	$(RM) $(NAME)
	echo "$(GREEN)Done$(END)"

re : fclean
	$(MAKE_SILENT) all

.PHONY : all clean fclean re
.SILENT :