/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_20260331120920.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 11:53:29 by eteofilo          #+#    #+#             */
/*   Updated: 2026/03/31 19:57:10 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h" // Ajuste o caminho do include se necessário
#include "../includes/parse.h"
#include <math.h>

// Fecha a janela e termina o programa de forma limpa
int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}

// Ouve as teclas. Se for ESC, fecha.
// Ouve as teclas
// Ouve as teclas
int	key_handler(int keycode, t_data *data)
{
	double move_speed = 1.1;
	double rot_speed = 0.08; // Aumentei um tiquinho pra ficar mais ágil
	double margin = 0.2;     // Nossa "margem de segurança" (o gordinho)

	if (keycode == 53)
		close_window(data);

	// W - ANDAR PARA FRENTE
	if (keycode == 13)
	{
		// Tenta mover no X (Checa se o quadrado destino no mapa é zero)
		if (data->map[(int)(data->player.pos_x + data->player.dir_x * margin)][(int)(data->player.pos_y)] == 0)
			data->player.pos_x += data->player.dir_x * move_speed;

		// Tenta mover no Y (Independente do que aconteceu no X)
		if (data->map[(int)(data->player.pos_x)][(int)(data->player.pos_y + data->player.dir_y * margin)] == 0)
			data->player.pos_y += data->player.dir_y * move_speed;
	}

	// S - ANDAR PARA TRÁS
	if (keycode == 1)
	{
		// Mesma lógica, mas subtraindo a direção
		if (data->map[(int)(data->player.pos_x - data->player.dir_x * margin)][(int)(data->player.pos_y)] == 0)
			data->player.pos_x -= data->player.dir_x * move_speed;

		if (data->map[(int)(data->player.pos_x)][(int)(data->player.pos_y - data->player.dir_y * margin)] == 0)
			data->player.pos_y -= data->player.dir_y * move_speed;
	}

	// SETA DIREITA - GIRAR
	if (keycode == 124)
	{
		double old_dir_x = data->player.dir_x;
		data->player.dir_x = data->player.dir_x * cos(-rot_speed) - data->player.dir_y * sin(-rot_speed);
		data->player.dir_y = old_dir_x * sin(-rot_speed) + data->player.dir_y * cos(-rot_speed);
		double old_plane_x = data->player.plane_x;
		data->player.plane_x = data->player.plane_x * cos(-rot_speed) - data->player.plane_y * sin(-rot_speed);
		data->player.plane_y = old_plane_x * sin(-rot_speed) + data->player.plane_y * cos(-rot_speed);
	}

	// SETA ESQUERDA - GIRAR
	if (keycode == 123)
	{
		double old_dir_x = data->player.dir_x;
		data->player.dir_x = data->player.dir_x * cos(rot_speed) - data->player.dir_y * sin(rot_speed);
		data->player.dir_y = old_dir_x * sin(rot_speed) + data->player.dir_y * cos(rot_speed);
		double old_plane_x = data->player.plane_x;
		data->player.plane_x = data->player.plane_x * cos(rot_speed) - data->player.plane_y * sin(rot_speed);
		data->player.plane_y = old_plane_x * sin(rot_speed) + data->player.plane_y * cos(rot_speed);
	}

	return (0);
}

// Função auxiliar para desenhar pixels no buffer da imagem
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	// Proteção simples pra não desenhar fora da memória
	if (x < 0 || x >= W_WIDTH || y < 0 || y >= W_HEIGHT)
		return;

	// CORREÇÃO: Acessando data->img.addr e data->img.line_len
	dst = data->img.addr + (y * data->img.line_len + x * (data->img.bpp / 8));
	*(unsigned int*)dst = color;
}

// Função para desenhar a linha vertical
void	draw_vertical_line(t_data *data, int x, int draw_start, int draw_end, int color)
{
	int	y;

	y = draw_start;
	while (y < draw_end)
	{
		my_mlx_pixel_put(data, x, y, color);
		y++;
	}
}

// O CORAÇÃO DO JOGO: Loop de Raycasting
int	raycasting_loop(t_data *data)
{
	int		x;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	double	perp_wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	//int		color;

	// 1. Pinta o fundo (Teto e Chão)
	for (int i = 0; i < W_HEIGHT / 2; i++)
		for (int j = 0; j < W_WIDTH; j++)
			my_mlx_pixel_put(data, j, i, 0x87CEEB); // Teto Azul Céu

	for (int i = W_HEIGHT / 2; i < W_HEIGHT; i++)
		for (int j = 0; j < W_WIDTH; j++)
			my_mlx_pixel_put(data, j, i, 0x222222); // Chão Cinza Escuro

	// 2. Loop principal dos raios
	x = 0;
	while (x < W_WIDTH)
	{
		// --- SETUP ---
		camera_x = 2 * x / (double)W_WIDTH - 1; // acha a coluna atual de pixels no espaço entre -1 e 1;
		ray_dir_x = data->player.dir_x + data->player.plane_x * camera_x; // define a direção exata do raio
		ray_dir_y = data->player.dir_y + data->player.plane_y * camera_x;

		map_x = (int)data->player.pos_x;
		map_y = (int)data->player.pos_y;

		delta_dist_x = fabs(1 / ray_dir_x); //variação da distância do raio; TL,DR: Quanto custa para um raio atravessar um bloco;
		delta_dist_y = fabs(1 / ray_dir_y);

		// --- CALCULA STEP E SIDE_DIST ---
		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (data->player.pos_x - map_x) * delta_dist_x; // pos_x - map_x = posição real dentro do bloco; * delta_dist = distância real até o limite do bloco
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - data->player.pos_x) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (data->player.pos_y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - data->player.pos_y) * delta_dist_y;
		}

		// // --- DDA (Achar Parede) ---
		// hit = 0;
		// while (hit == 0)
		// {
		// 	if (side_dist_x < side_dist_y)
		// 	{
		// 		side_dist_x += delta_dist_x;
		// 		map_x += step_x;
		// 		side = 0;
		// 	}
		// 	else
		// 	{
		// 		side_dist_y += delta_dist_y;
		// 		map_y += step_y;
		// 		side = 1;
		// 	}
		// 	if (data->map[map_x][map_y] > 0)
		// 		hit = 1;
		// }

		hit = 0;
		while (hit == 0)
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}

			// // Checa limites de altura
			if (map_x < 0 || map_x >= data->real_map->height)
			 	hit = 1;
			// Checa limites de largura dessa linha específica
			else if (map_y < 0 || map_y >= data->width[map_x])
				hit = 1;
			// Espaço vazio (-1) dentro do mapa
			else if (data->map[map_x][map_y] == -1)
				hit = 1;
			// Parede normal
			else if (data->map[map_x][map_y] > 0)
				hit = 1;
		}

		// --- CÁLCULO FINAL ---
		if (side == 0)
			perp_wall_dist = (side_dist_x - delta_dist_x); //subtrai um passo
		else
			perp_wall_dist = (side_dist_y - delta_dist_y);

		line_height = (int)(W_HEIGHT / perp_wall_dist);

		draw_start = -line_height / 2 + W_HEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + W_HEIGHT / 2;
		if (draw_end >= W_HEIGHT)
			draw_end = W_HEIGHT - 1;

		int tex_index;
		if (side == 0)
			tex_index = (ray_dir_x > 0) ? 2 : 3; // WEST ou EAST
		else
			tex_index = (ray_dir_y > 0) ? 0 : 1; // NORTH ou SOUTH

		t_img *cur_tex = &data->tex_test[tex_index];


		double wall_x;
		if (side == 0)
			wall_x = data->player.pos_y + perp_wall_dist * ray_dir_y;
		else
			wall_x = data->player.pos_x + perp_wall_dist * ray_dir_x;
		wall_x -= floor(wall_x);

		int tex_x = (int)(wall_x * (double)TEX_W);
		if ((side == 0 && ray_dir_x > 0) || (side == 1 && ray_dir_y < 0))
			tex_x = TEX_W - tex_x - 1;

		for (int y = draw_start; y < draw_end; y++)
		{
			int d     = y * 256 - W_HEIGHT * 128 + line_height * 128;
			int tex_y = ((d * TEX_H) / line_height) / 256;
			int color = *(int *)(cur_tex->addr                  // <-- fix do cast também
						+ tex_y * cur_tex->line_len
						+ tex_x * (cur_tex->bpp / 8));

			my_mlx_pixel_put(data, x, y, color);
		}
		x++;
	}

	// CORREÇÃO: Passando data->img.img_ptr
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
	return (0);
}

void load_texture(t_data *data)
{
    int w, h;

    data->tex_test[0].img_ptr = mlx_xpm_file_to_image(data->mlx, data->real_map->no_path, &w, &h);
    data->tex_test[1].img_ptr = mlx_xpm_file_to_image(data->mlx, data->real_map->so_path, &w, &h);
    data->tex_test[2].img_ptr = mlx_xpm_file_to_image(data->mlx, data->real_map->we_path, &w, &h);
    data->tex_test[3].img_ptr = mlx_xpm_file_to_image(data->mlx, data->real_map->ea_path, &w, &h);

    int i = 0;
    while (i < 4)
    {
        data->tex_test[i].addr = mlx_get_data_addr(data->tex_test[i].img_ptr,
                                &data->tex_test[i].bpp,
                                &data->tex_test[i].line_len,
                                &data->tex_test[i].endian);
        i++;
    }
}

// void    init_player(t_data *data)
// {
//     // Posição no centro do tile
//     data->player.pos_x = data->player.pos_x + 0.5;
//     data->player.pos_y = data->player.pos_y + 0.5;

//     // Direção e plano de câmera de acordo com o char
//     if (data->real_map->player_dir == 'N')
//     {
//         data->player.dir_x = -1.0;
//         data->player.dir_y = 0.0;
//         data->player.plane_x = 0.0;
//         data->player.plane_y = 0.66;
//     }
//     else if (data->real_map->player_dir == 'S')
//     {
//         data->player.dir_x = 1.0;
//         data->player.dir_y = 0.0;
//         data->player.plane_x = 0.0;
//         data->player.plane_y = -0.66;
//     }
//     else if (data->real_map->player_dir == 'E')
//     {
//         data->player.dir_x = 0.0;
//         data->player.dir_y = 1.0;
//         data->player.plane_x = 0.66;
//         data->player.plane_y = 0.0;
//     }
//     else if (data->real_map->player_dir == 'W')
//     {
//         data->player.dir_x = 0.0;
//         data->player.dir_y = -1.0;
//         data->player.plane_x = -0.66;
//         data->player.plane_y = 0.0;
//     }
// }

void    find_player(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (data->real_map->grid[i] != NULL)
    {
        j = 0;
        while (data->real_map->grid[i][j] != '\0')
        {
            if (data->real_map->grid[i][j] == 'N' || data->real_map->grid[i][j] == 'S'
                || data->real_map->grid[i][j] == 'E' || data->real_map->grid[i][j] == 'W')
            {
                data->player.pos_x = i + 0.5;
                data->player.pos_y = j + 0.5;
                if (data->real_map->grid[i][j] == 'N')
                { data->player.dir_x = -1.0; data->player.dir_y = 0.0; data->player.plane_x = 0.0; data->player.plane_y = 0.66; }
                else if (data->real_map->grid[i][j] == 'S')
                { data->player.dir_x = 1.0; data->player.dir_y = 0.0; data->player.plane_x = 0.0; data->player.plane_y = -0.66; }
                else if (data->real_map->grid[i][j] == 'E')
                { data->player.dir_x = 0.0; data->player.dir_y = 1.0; data->player.plane_x = 0.66; data->player.plane_y = 0.0; }
                else if (data->real_map->grid[i][j] == 'W')
                { data->player.dir_x = 0.0; data->player.dir_y = -1.0; data->player.plane_x = -0.66; data->player.plane_y = 0.0; }
                data->real_map->grid[i][j] = '0';
            }
            j++;
        }
        i++;
    }
}

int **convert_grid(t_data* data)
{
	int i;
	int j;
	int **int_grid;

	i = 0;
	while (data->real_map->grid[i] != NULL)
		i++;
	int_grid = malloc(sizeof(int *) * (i + 1));
	data->width = malloc(sizeof(int) * (i + 1));
	if (!int_grid || !data->width)
		return (NULL);
	i = 0;
	while (data->real_map->grid[i] != NULL)
	{
		j = 0;
		while (data->real_map->grid[i][j] != '\0')
			j++;
		data->width[i] = j; // <-- salva a largura dessa linha
		int_grid[i] = malloc(sizeof(int) * (j + 1));
		j = 0;
		while (data->real_map->grid[i][j] != '\0')
		{
			if (data->real_map->grid[i][j] == '1')
				int_grid[i][j] = 1;
			else if (data->real_map->grid[i][j] == ' ')
				int_grid[i][j] = -1;
			else
				int_grid[i][j] = 0;
			j++;
		}
		int_grid[i][j] = -1;
		i++;
	}
	int_grid[i] = NULL;
	return (int_grid);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_map	*map;

	if (ac != 2)
	{
		printf("Error\nUso correto: ./cub3D <mapa.cub>\n");
		return (1);
	}
	map = init_parse(av[1]);
	if (!map)
		return (1);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, W_WIDTH, W_HEIGHT, "Cub3D Leticia");
	data.img.img_ptr = mlx_new_image(data.mlx, W_WIDTH, W_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.img_ptr, &data.img.bpp, &data.img.line_len, &data.img.endian);
	data.real_map = *map;
	data.map = convert_grid(&data);
	find_player(&data);
	load_texture(&data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_hook(data.win, 2, 1L << 0, key_handler, &data);
	mlx_loop_hook(data.mlx, &raycasting_loop, &data);
	mlx_loop(data.mlx);
	free_map_struct(map);
	return (0);
}
