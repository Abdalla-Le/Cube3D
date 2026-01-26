/*
    #Bibliotecas
*/

#include "lib/libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
/*
    structs and lists
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

/* MAP LIST*/

typedef struct s_gnl
{
	char			*line;
    int             index;
	struct s_gnl	*next;
}				t_gnl;

/*
    Functions
*/
int		stdin_parse(char *file_name);
int		parse_file(int fd, t_map *map, t_gnl **lst);
void	ft_lstadd_back(t_gnl **lst, t_gnl*new);
t_gnl	*ft_lstnew(char *content, int i);
int		path_way(int fd, t_map *file, char *line);
int		parse_map(t_map *map);
char	**fill_matrix(t_gnl **lst, t_map *map);
void    fill_list(t_gnl **lst, char *line);
int     check_params(t_map *map);
int     handle_position(char c, t_map *map, int y, int x);
void	get_width(t_map *map);
void	normalize_grid(t_map *map);
int     validate_wall(t_map *map);

