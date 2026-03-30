#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h> // Precisa dessa para as contas matematicas

# define W_WIDTH 800
# define W_HEIGHT 600

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
    t_img       tex_test;
    t_player    player; // Adicionamos o jogador aqui
    int         map[24][24]; // Um mapa fixo temporário só pra testar
} t_data;

#endif