# Nom de l'exécutable à générer
TARGET = FDF

# Compilateur
CC = gcc

# Flags de compilation
CFLAGS = -Wall -I lib/libft -I lib/GNL -I lib/ft_printf

# Dossier source
SRC_DIR = src

# Dossier pour les fichiers objets
OBJ_DIR = obj

# Dossiers des bibliothèques
LIBFT_DIR = lib/libft
FT_PRINTF_DIR = lib/ft_printf
GNL_DIR = lib/GNL
MINILIBX_DIR = mlx

# Noms des bibliothèques
LIBS = -lft -lftprintf -lgnl -lmlx

# Chemins des bibliothèques pour le linker
LFLAGS = -L$(LIBFT_DIR) -L$(FT_PRINTF_DIR) -L$(GNL_DIR) -L$(MINILIBX_DIR)

# Frameworks nécessaires pour MiniLibX
FRAMEWORKS = -framework OpenGL -framework AppKit

# Trouver tous les fichiers .c dans le dossier source
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Convertir les fichiers .c en .o
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Règle principale
all: $(TARGET)

# Lier les fichiers objets pour créer l'exécutable
$(TARGET): $(OBJS) libraries
	$(CC) $(OBJS) $(LFLAGS) $(LIBS) $(FRAMEWORKS) -o $(TARGET)

# Compiler les fichiers source en fichiers objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyer les fichiers compilés
clean:
	rm -rf $(OBJ_DIR)/* $(TARGET)

# Règle pour forcer la recompilation
re: clean all

# Compiler les bibliothèques
libraries:
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(FT_PRINTF_DIR)
	$(MAKE) -C $(GNL_DIR)
	$(MAKE) -C $(MINILIBX_DIR)


https://github.com/Jean-xavierr/42Philosophers/blob/master/srcs/lib/srcs_philosophers/data_manager.c#L37
