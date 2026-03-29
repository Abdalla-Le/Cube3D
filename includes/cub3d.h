#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define W_WIDTH 800
# define W_HEIGHT 600

# define KEY_ESC   65307
# define KEY_W     119
# define KEY_S     115
# define KEY_LEFT  65361
# define KEY_RIGHT 65363

typedef struct s_player
{
    double  pos_x;
    double  pos_y;
    double  dir_x;
    double  dir_y;
    double  plane_x;
    double  plane_y;
}    t_player;

typedef struct s_img
{
    void    *img_ptr;
    char    *addr;
    int     bpp;
    int     line_len;
    int     endian;
}    t_img;

typedef struct s_data
{
    void        *mlx;
    void        *win;
    t_img       img;
    t_img       tex_test;
    t_player    player;
    int         map[24][24];
}    t_data;

int        close_window(t_data *data);
int        key_handler(int keycode, t_data *data);
void    my_mlx_pixel_put(t_data *data, int x, int y, int color);
void    draw_vertical_line(t_data *data, int x, int draw_start,int draw_end, int color);
int        raycasting_loop(t_data *data);
void    load_texture(t_data *data);

#endif