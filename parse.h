/*
    #Bibliotecas
*/

#include "lib/libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
/*
    structs
*/

/* MAP STRUCT*/

typedef struct s_map {
    char    **grid;      // O mapa em si (matriz de caracteres)
    int     width;       // Largura da maior linha
    int     height;      // Quantidade de linhas
    int     p_x;         // Posição X inicial do player
    int     p_y;         // Posição Y inicial do player
    char    p_dir;       // Direção inicial ('N', 'S', 'E', 'W')
    char    *no_path;    // Caminho da textura NO
    char    *so_path;    // Caminho da textura SO
    char    *we_path;    // Caminho da textura WE
    char    *ea_path;    // Caminho da textura EA
    int     floor_color; // Cor do chão (convertido pra int/hex)
    int     ceil_color;  // Cor do teto (convertido pra int/hex)
} t_map;

/*
    Functions
*/
int stdin_parse(char *file_name);
int parse_map(int fd);