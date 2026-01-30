#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>

// Definindo o tamanho da janela aqui pra usar em todo lugar
# define W_WIDTH 800
# define W_HEIGHT 600

typedef struct s_img {
    void    *img_ptr;
    char    *addr;
    int     bpp;
    int     line_len;
    int     endian;
} t_img;

typedef struct s_data {
    void    *mlx;
    void    *win;
    t_img   img;
} t_data;

#endif