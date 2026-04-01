/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 21:23:02 by eteofilo          #+#    #+#             */
/*   Updated: 2026/03/31 21:45:09 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "../lib/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	char			**grid;
	int				width;
	int				height;
	int				p_x;
	int				p_y;
	char			p_dir;
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
	int				floor_color;
	int				ceil_color;
}					t_map;

typedef struct s_gnl
{
	char			*line;
	int				index;
	struct s_gnl	*next;
}					t_gnl;

int					stdin_parse(char *file_name);
int					parse_file(int fd, t_map *map, t_gnl **lst);
void				ft_lstadd_back(t_gnl **lst, t_gnl *new);
t_gnl				*ft_lstnew(char *content, int i);
int					path_way(int fd, t_map *file, char *line);
int					parse_map(t_map *map);
char				**fill_matrix(t_gnl **lst, t_map *map);
void				fill_list(t_gnl **lst, char *line);
int					check_params(t_map *map);
int					handle_position(char c, t_map *map, int y, int x);
void				get_width(t_map *map);
void				normalize_grid(t_map *map);
int					validate_wall(t_map *map);
char				*get_clean_path(char *line);
int					take_color(char **rgb);
void				free_map_struct(t_map *map);
t_map				*init_parse(char *file_name);
void				free_lst(t_gnl *lst);
void				free_map_fields(t_map *map);

#endif
