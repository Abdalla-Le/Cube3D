#include "../includes/cub3d.h"
#include <math.h>

// 1. Função de fechar (Close)
int close_game(t_data *data)
{
    mlx_destroy_window(data->mlx, data->win);
    mlx_destroy_display(data->mlx);
    free(data->mlx);
    exit(0);
    return (0);
}

int handle_keypress(int keycode, t_data *data)
{
    if (keycode == 65307) // ESC
        close_game(data);
    return (0);
}

// 2. Função de Pixel (Tem que vir antes de quem usa ela)
void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;
    dst = data->img.addr + (y * data->img.line_len + x * (data->img.bpp / 8));
    *(unsigned int*)dst = color;
}

// 3. Inicializa Jogador
void    init_player(t_data *data)
{
    data->player.pos_x = 22.0;
    data->player.pos_y = 12.0;
    data->player.dir_x = -1.0;
    data->player.dir_y = 0.0;
    data->player.plane_x = 0.0;
    data->player.plane_y = 0.66;
}

// 4. Carrega Mapa
void    load_map(t_data *data)
{
    // Mapa Hardcoded
    int worldMap[24][24] = {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
        {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
        {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };
    for (int i = 0; i < 24; i++)
        for (int j = 0; j < 24; j++)
            data->map[i][j] = worldMap[i][j];
}

int render_game(t_data *data)
{
    // Limpa fundo (Preto)
    for (int y=0; y<W_HEIGHT; y++) for (int x=0; x<W_WIDTH; x++) 
        my_mlx_pixel_put(data, x, y, 0x000000);

    int x = 0;
    while (x < W_WIDTH)
    {
        // 1. Calcula a posição na régua (-1 a 1)
        double camera_x = 2 * x / (double)W_WIDTH - 1;

        // 2. CALCULA A DIREÇÃO DO RAIO
        double ray_dir_x = data->player.dir_x + data->player.plane_x * camera_x;
        double ray_dir_y = data->player.dir_y + data->player.plane_y * camera_x;

        // --- TRUQUE NOVO ---
        // Essa linha não faz nada, mas avisa o compilador: "Eu sei que essa variável existe, relaxa".
        (void)ray_dir_x; 

        // 3. Visualização
        int color;
        
        if (ray_dir_y < 0)
            color = 0xFF0000; // Vermelho (Esquerda)
        else if (ray_dir_y > 0)
            color = 0x0000FF; // Azul (Direita)
        else
            color = 0xFFFFFF; // Branco (Meio)

        // Desenha a linha
        int y = 100;
        while (y < 500) {
            my_mlx_pixel_put(data, x, y, color);
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
    return (0);
}

int main(void)
{
    t_data data;

    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, W_WIDTH, W_HEIGHT, "Cub3D Raycasting");
    data.img.img_ptr = mlx_new_image(data.mlx, W_WIDTH, W_HEIGHT);
    data.img.addr = mlx_get_data_addr(data.img.img_ptr, &data.img.bpp,
            &data.img.line_len, &data.img.endian);

    load_map(&data);
    init_player(&data);

    mlx_loop_hook(data.mlx, &render_game, &data);
    mlx_hook(data.win, 17, 0, close_game, &data);
    mlx_key_hook(data.win, handle_keypress, &data);
    mlx_loop(data.mlx);
}