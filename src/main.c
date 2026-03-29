#include "../includes/cub3d.h"

void    load_texture(t_data *data)
{
    int width;
    int height;

    data->tex_test.img_ptr = mlx_xpm_file_to_image(data->mlx,
            "textures/teste.xpm", &width, &height);
    if (data->tex_test.img_ptr == NULL)
    {
        write(2, "Erro\nNao achou a textura!\n", 26);
        exit(1);
    }
    data->tex_test.addr = mlx_get_data_addr(data->tex_test.img_ptr,
            &data->tex_test.bpp, &data->tex_test.line_len,
            &data->tex_test.endian);
}

static void    init_player(t_data *data)
{
    data->player.pos_x = 12.0;
    data->player.pos_y = 12.0;
    data->player.dir_x = -1.0;
    data->player.dir_y = 0.0;
    data->player.plane_x = 0.0;
    data->player.plane_y = 0.66;
}

static void    init_map(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (i < 24)
    {
        j = 0;
        while (j < 24)
        {
            if (i == 0 || i == 23 || j == 0 || j == 23)
                data->map[i][j] = 1;
            else
                data->map[i][j] = 0;
            j++;
        }
        i++;
    }
    data->map[10][10] = 2;
}

int    main(void)
{
    t_data  data;

    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, W_WIDTH, W_HEIGHT,
            "Cub3D Leticia");
    data.img.img_ptr = mlx_new_image(data.mlx, W_WIDTH, W_HEIGHT);
    data.img.addr = mlx_get_data_addr(data.img.img_ptr, &data.img.bpp,
            &data.img.line_len, &data.img.endian);
    load_texture(&data);
    init_player(&data);
    init_map(&data);
    mlx_hook(data.win, 17, 0, close_window, &data);
    mlx_hook(data.win, 2, 1L << 0, key_handler, &data);
    mlx_loop_hook(data.mlx, &raycasting_loop, &data);
    mlx_loop(data.mlx);
    return (0);
}