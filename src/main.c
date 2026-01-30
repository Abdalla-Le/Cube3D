#include "../includes/cub3d.h"

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
    if (keycode == 65307)
        close_game(data);
    return (0);
}

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->img.addr + (y * data->img.line_len + x * (data->img.bpp / 8));
    *(unsigned int*)dst = color;
}

// Essa função vai desenhar o quadrado CADA VEZ que for chamada
void    render_background(t_data *data)
{
    int x;
    int y;
    int size = 200; // Tamanho do quadrado

    // PINTAR PRETO (Limpar a tela antes de desenhar)
    // Se não limpar, vira uma bagunça psicodélica quando mover coisas
    y = 0;
    while (y < W_HEIGHT)
    {
        x = 0;
        while (x < W_WIDTH)
        {
            my_mlx_pixel_put(data, x, y, 0x000000); // Preto
            x++;
        }
        y++;
    }

    // DESENHAR O QUADRADO (Centralizado)
    // Ponto inicial Y = Metade da tela - Metade do quadrado
    y = (W_HEIGHT / 2) - (size / 2);
    while (y < (W_HEIGHT / 2) + (size / 2))
    {
        // Ponto inicial X = Metade da tela - Metade do quadrado
        x = (W_WIDTH / 2) - (size / 2);
        while (x < (W_WIDTH / 2) + (size / 2))
        {
            my_mlx_pixel_put(data, x, y, 0x00FF0000); // Vermelho
            x++;
        }
        y++;
    }
}

// Função principal do Loop (Game Loop)
int render_game(t_data *data)
{
    // 1. Desenha tudo na imagem invisível
    render_background(data);
    
    // 2. Joga a imagem na janela
    mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
    
    return (0);
}

int main(void)
{
    t_data data;

    data.mlx = mlx_init();
    if (!data.mlx) return (1);
    
    // Usando as constantes W_WIDTH e W_HEIGHT
    data.win = mlx_new_window(data.mlx, W_WIDTH, W_HEIGHT, "Cub3D Centralizado");

    data.img.img_ptr = mlx_new_image(data.mlx, W_WIDTH, W_HEIGHT);
    data.img.addr = mlx_get_data_addr(data.img.img_ptr, &data.img.bpp,
            &data.img.line_len, &data.img.endian);

    // --- AQUI A MÁGICA ACONTECE ---
    // Diz pro MLX: "Sempre que não tiver nada pra fazer, roda render_game"
    mlx_loop_hook(data.mlx, &render_game, &data);

    mlx_hook(data.win, 17, 0, close_game, &data);
    mlx_key_hook(data.win, handle_keypress, &data);
    mlx_loop(data.mlx);
}