#include "../includes/cub3d.h"

int    close_window(t_data *data)
{
    mlx_destroy_window(data->mlx, data->win);
    exit(0);
    return (0);
}

int    key_handler(int keycode, t_data *data)
{
    double  move_speed;
    double  rot_speed;
    double  margin;

    move_speed = 0.1;
    rot_speed = 0.08;
    margin = 0.2;
    if (keycode == KEY_ESC)
        close_window(data);
    if (keycode == KEY_W)
    {
        if (data->map[(int)(data->player.pos_x + data->player.dir_x
                * margin)][(int)(data->player.pos_y)] == 0)
            data->player.pos_x += data->player.dir_x * move_speed;
        if (data->map[(int)(data->player.pos_x)]
                [(int)(data->player.pos_y + data->player.dir_y
                * margin)] == 0)
            data->player.pos_y += data->player.dir_y * move_speed;
    }
    if (keycode == KEY_S)
    {
        if (data->map[(int)(data->player.pos_x - data->player.dir_x
                * margin)][(int)(data->player.pos_y)] == 0)
            data->player.pos_x -= data->player.dir_x * move_speed;
        if (data->map[(int)(data->player.pos_x)]
                [(int)(data->player.pos_y - data->player.dir_y
                * margin)] == 0)
            data->player.pos_y -= data->player.dir_y * move_speed;
    }
    if (keycode == KEY_RIGHT)
    {
        double  old_dir_x;
        double  old_plane_x;

        old_dir_x = data->player.dir_x;
        data->player.dir_x = data->player.dir_x * cos(-rot_speed)
            - data->player.dir_y * sin(-rot_speed);
        data->player.dir_y = old_dir_x * sin(-rot_speed)
            + data->player.dir_y * cos(-rot_speed);
        old_plane_x = data->player.plane_x;
        data->player.plane_x = data->player.plane_x * cos(-rot_speed)
            - data->player.plane_y * sin(-rot_speed);
        data->player.plane_y = old_plane_x * sin(-rot_speed)
            + data->player.plane_y * cos(-rot_speed);
    }
    if (keycode == KEY_LEFT)
    {
        double  old_dir_x;
        double  old_plane_x;

        old_dir_x = data->player.dir_x;
        data->player.dir_x = data->player.dir_x * cos(rot_speed)
            - data->player.dir_y * sin(rot_speed);
        data->player.dir_y = old_dir_x * sin(rot_speed)
            + data->player.dir_y * cos(rot_speed);
        old_plane_x = data->player.plane_x;
        data->player.plane_x = data->player.plane_x * cos(rot_speed)
            - data->player.plane_y * sin(rot_speed);
        data->player.plane_y = old_plane_x * sin(rot_speed)
            + data->player.plane_y * cos(rot_speed);
    }
    return (0);
}