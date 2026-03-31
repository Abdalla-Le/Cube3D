#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
#include "parse.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h> // Precisa dessa para as contas matematicas

# define W_WIDTH 800
# define W_HEIGHT 600

#define TEX_W 64
#define TEX_H 64

#ifdef __APPLE__

#define KEY_W      13
#define KEY_A      0
#define KEY_S      1
#define KEY_D      2
#define KEY_LEFT   123
#define KEY_RIGHT  124
#define KEY_ESC    53

#else

#define KEY_W      119
#define KEY_A      97
#define KEY_S      115
#define KEY_D      100
#define KEY_LEFT   65361
#define KEY_RIGHT  65363
#define KEY_ESC    65307

#endif

// Struct do Jogador (Matemática Pura)
typedef struct s_player {
    double  pos_x;      // Posição X no mapa
    double  pos_y;      // Posição Y no mapa
    double  dir_x;      // Vetor de Direção X
    double  dir_y;      // Vetor de Direção Y
    double  plane_x;    // Vetor do Plano de Câmera X (O "Leque")
    double  plane_y;    // Vetor do Plano de Câmera Y
} t_player;

typedef struct s_img {
    void    *img_ptr;
    char    *addr;
    int     bpp;
    int     line_len;
    int     endian;
} t_img;

typedef struct s_data {
    void        *mlx;
    void        *win;
    t_img       img;
    t_img       tex_test[4];
    t_player    player;
    int**       map;
    t_map       real_map;
    int        map_size[2];

} t_data;

typedef struct s_raycast {
    int     side;
	int		map[2];
	int		step[2];
    int     line_height;
    int     draw_start;
    int     draw_end;
    double  perp_wall_dist;
    double	ray_dir[2];
	double	side_dist[2];
	double	delta_dist[2];
} t_raycast;

void	find_player(t_data *data);
int     **convert_grid(t_data *data);
void	load_texture(t_data *data);
int	    key_handler(int keycode, t_data *data);
void	set_raycast(int x, t_raycast *raycast, t_data *data);
void	set_side(t_raycast *raycast, t_data *data);
void	set_step(t_raycast *raycast);
void	set_dda(t_raycast *raycast, t_data *data);
void	set_walls(t_raycast *raycast);
void	set_textures(int x, t_raycast *raycast, t_data *data);
int	    raycasting_loop(t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int	    close_window(t_data *data);
int	is_wall(t_data *data, int x, int y);

#endif
