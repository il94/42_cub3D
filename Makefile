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
# LIBXFLAGS = -lmlx -lXext -lX11 -lXfixes
LIBXFLAGS = -lmlx -lXext -lX11
LIBMATHS = -lm

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

SRC = main.c temp.c \
		init/init.c init/init_utils.c init/init_mlx.c \
		\
		parsing/parsing.c parsing/parsing_utils.c parsing/parsing_map.c \
		parsing/parsing_map_utils.c parsing/parsing_data_map.c \
		parsing/parsing_data_map_utils.c \
		\
		interaction/door.c interaction/move.c \
		\
		put_render/put_render.c put_render/put_utils.c \
		put_render/draw_minimap.c put_render/put_column.c \
		put_render/put_environnement.c put_render/put_environnement_utils.c \
		put_render/put_minimap.c put_render/put_sky.c \
		put_render/put_multiple_stars.c \
		\
		run/run.c run/utils.c run/process_inputs.c run/free_memory.c \
		\


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

all : $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEAD) Makefile
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(MAKE_SILENT) -C libft
	$(MAKE_SILENT) -C mlx_linux	
	echo "$(YELLOW)Making Cub3D$(END)"
	$(CC) $(OBJ) $(LIBFT) $(LIBX) $(LIBXFLAGS) $(LIBMATHS) -o $(NAME)
	echo "$(GREEN)Done$(END)"

# $(OBJ_DIR) :
# 	$(MKDIR) $(OBJ_DIR)

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