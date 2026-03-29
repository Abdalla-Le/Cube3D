#include "../includes/cub3d.h"

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    if (x < 0 || x >= W_WIDTH || y < 0 || y >= W_HEIGHT)
        return ;
    dst = data->img.addr + (y * data->img.line_len
            + x * (data->img.bpp / 8));
    *(unsigned int *)dst = color;
}

void    draw_vertical_line(t_data *data, int x, int draw_start,int draw_end, int color)
{
    int y;

    y = draw_start;
    while (y < draw_end)
    {
        my_mlx_pixel_put(data, x, y, color);
        y++;
    }
}