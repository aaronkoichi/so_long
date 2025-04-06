/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:46:23 by zlee              #+#    #+#             */
/*   Updated: 2025/04/06 21:22:12 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx.h"
# include "libft.h"
# include <fcntl.h>

/*pixel to sprite ratio*/
# define MUL 64
/* keysyms imported from keysymdef.h */
# define XK_W 119
# define XK_A 97
# define XK_S 115
# define XK_D 100
# define XK_ESC 65307

/*Frame Constants*/
# define TOTAL_FRAME 100
# define FRAME_MUL 20
# define TOTAL_ENEMY_FRAME 200

/*direction*/
enum	e_dir
{
	DOWN,
	UP,
	LEFT,
	RIGHT
};

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_sprite {
	void	*img_ptr;
	int		img_x;
	int		img_y;
	char	*pixels;
	int		bpp;
	int		line_size;
	int		endian;
	t_pos	img_size;
}	t_sprite;

typedef struct s_player
{
	int			frame;
	t_pos		pos;
	t_pos		target_pos;
	t_sprite	left[4];
	t_sprite	right[4];
	t_sprite	up[4];
	t_sprite	down[4];
}	t_player;

typedef struct s_enemy
{
	int			frame_num;
	int			fps;
	t_sprite	frame[4];
}	t_enemy;

/*Textures
 * 0 --> Ground
 * 1 --> Wall
 * 2 --> Character
 * 3 --> Collectible
 * 4 --> Exit
 * 5 (BONUS) --> enemy*/
typedef struct s_data {
	void		*mlx_ptr;
	void		*win_ptr;
	t_list		*map_data;
	t_player	player;
	t_enemy		enemy;
	t_sprite	textures[6];
	t_sprite	numbers[10];
	t_pos		win;
	int			counter;
	t_sprite	display;
	int			exit_check;
	enum e_dir	dir;
	int			frame_counter;
}	t_data;

int			error_exit(int error_num);
/*maps - walls*/
int			check_all_walls(t_list *map);
/*Check valid input*/
int			check_valid(t_list *map);
int			check_lines(t_list *map);
int			process_map(int fd, t_list **map);
/*Check map items*/
int			check_map_parameters(t_list *map);
/*Flood Fill*/
int			flood_fill_main(t_list *map);
void		find_player_coordinate(t_list *map, int	*x, int	*y);
/*Display creation*/
void		mlx_start(t_list *map);
void		remove_new_line(t_list **map);
t_sprite	create_sprite(char *path, void *mlx_ptr, t_pos pos);
void		print_ground(t_data *mlx, t_sprite *img);
void		set_sprites(t_data *mlx);
void		print_individual_sprites(t_data *mlx,
				char element, int num, t_sprite *img);
int			print_all_elements(t_data *mlx);
/*Manipulate the pixels in the image for transparency*/
void		put_img_on_canvas(t_data *data, t_sprite *sprite,
				t_sprite *target, t_pos offset);
void		custom_pixel_put(t_data *data, t_sprite *spr, t_pos pos, int color);
/*Game Movement*/
int			game_movement(int keysym, t_data *data);
void		move_up(t_data *data);
void		move_down(t_data *data);
void		move_left(t_data *data);
void		move_right(t_data *data);
void		movement_check(t_data *data, char *current, char *to_move);
int			close_win(t_data *data);
/*Bonus*/
int			process_map_bonus(int fd, t_list **map);
int			check_valid_bonus(t_list *map);
void		set_spr_data(t_data *data);
int			print_all_elem_bonus(t_data *mlx);
void		set_sprites_bonus(t_data *mlx);
int			game_movement_bonus(int keysym, t_data *data);
void		process_number(t_data *mlx);
void		init_numbers(t_data *mlx);
void		interpolation(t_data *mlx, t_pos target);
#endif
