#include "../includes/cub3d.h"

int    raycasting_loop(t_data *data)
{
    int     x;
    double  camera_x;
    double  ray_dir_x;
    double  ray_dir_y;
    int     map_x;
    int     map_y;
    double  side_dist_x;
    double  side_dist_y;
    double  delta_dist_x;
    double  delta_dist_y;
    int     step_x;
    int     step_y;
    int     hit;
    int     side;
    double  perp_wall_dist;
    int     line_height;
    int     draw_start;
    int     draw_end;
    int     color;
    int     i;
    int     j;

    i = 0;
    while (i < W_HEIGHT / 2)
    {
        j = 0;
        while (j < W_WIDTH)
        {
            my_mlx_pixel_put(data, j, i, 0x87CEEB);
            j++;
        }
        i++;
    }
    while (i < W_HEIGHT)
    {
        j = 0;
        while (j < W_WIDTH)
        {
            my_mlx_pixel_put(data, j, i, 0x222222);
            j++;
        }
        i++;
    }
    x = 0;
    while (x < W_WIDTH)
    {
        camera_x = 2 * x / (double)W_WIDTH - 1;
        ray_dir_x = data->player.dir_x + data->player.plane_x * camera_x;
        ray_dir_y = data->player.dir_y + data->player.plane_y * camera_x;
        map_x = (int)data->player.pos_x;
        map_y = (int)data->player.pos_y;
        delta_dist_x = fabs(1 / ray_dir_x);
        delta_dist_y = fabs(1 / ray_dir_y);
        if (ray_dir_x < 0)
        {
            step_x = -1;
            side_dist_x = (data->player.pos_x - map_x) * delta_dist_x;
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
            if (data->map[map_x][map_y] > 0)
                hit = 1;
        }
        if (side == 0)
            perp_wall_dist = side_dist_x - delta_dist_x;
        else
            perp_wall_dist = side_dist_y - delta_dist_y;
        line_height = (int)(W_HEIGHT / perp_wall_dist);
        draw_start = -line_height / 2 + W_HEIGHT / 2;
        if (draw_start < 0)
            draw_start = 0;
        draw_end = line_height / 2 + W_HEIGHT / 2;
        if (draw_end >= W_HEIGHT)
            draw_end = W_HEIGHT - 1;
        if (data->map[map_x][map_y] == 1)
            color = 0xFF0000;
        else if (data->map[map_x][map_y] == 2)
            color = 0x00FF00;
        else
            color = 0xFFFF00;
        if (side == 1)
            color = color / 2;
        draw_vertical_line(data, x, draw_start, draw_end, color);
        x++;
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
    return (0);
}