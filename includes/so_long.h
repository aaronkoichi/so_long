/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:46:23 by zlee              #+#    #+#             */
/*   Updated: 2025/03/29 00:29:05 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>

/*pixel to sprite ratio*/
# define MUL 32
/* keysyms imported from keysymdef.h */
# define XK_W 119
# define XK_A 97
# define XK_S 115
# define XK_D 100
# define XK_ESC 65307
/*mlx struct*/

typedef struct s_sprite {
	void	*img_ptr;
	int		img_x;
	int		img_y;
	char	*pixels;
	int		bpp;
	int		line_size;
	int		endian;
}	t_sprite;

/*Textures
 * 0 --> Ground
 * 1 --> Wall
 * 2 --> Character
 * 3 --> Collectible
 * 4 --> Exit*/
typedef struct s_data {
	void		*mlx_ptr;
	void		*win_ptr;
	t_list		*map_data;
	t_sprite	textures[5];
	int			win_x;
	int			win_y;
	int			counter;
	t_sprite	d_img;
}	t_data;

int			error_exit(int error_num);
/*maps - walls*/
int			check_all_walls(t_list *map);
/*Check valid input*/
int			check_valid(t_list *map);
int			check_lines(t_list *map);
int			process_map(int fd, t_list **map);
/*Check map items*/
int 		check_map_parameters(t_list *map);
/*Flood Fill*/
int			flood_fill_main(t_list *map);
void		find_player_coordinate(t_list *map, int	*x, int	*y);
/*Display creation*/
void		mlx_start(t_list *map);
void		remove_new_line(t_list **map);
t_sprite	create_sprite(char *path, void *mlx_ptr);
void	print_ground(t_data *mlx, t_list *map, t_sprite *img);
void		set_sprites(t_data *mlx);
void	print_individual_sprites(t_data *mlx, t_list *map,
				char element, int num, t_sprite *img);
int			print_all_elements(t_data *mlx);
/*Manipulate the pixels in the image for transparency*/
void		xpm_image_transparency(t_data *data, t_sprite *sprite, t_sprite *target,
				int offset_x, int offset_y);
void		custom_pixel_put(t_data *data, t_sprite *spr, int x, int y, int color);
/*Game Movement*/
int			game_movement(int keysym, t_data *data);
void		move_up(t_data *data);
void		move_down(t_data *data);
void		move_left(t_data *data);
void		move_right(t_data *data);
int			close_win(t_data *data);
#endif
