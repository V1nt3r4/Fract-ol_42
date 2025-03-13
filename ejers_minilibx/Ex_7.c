// #include "mlx.h"
// #include <stdlib.h>

// #define ESQ_KEY 65307
// #define LEFT_KEY 65361
// #define RIGHT_KEY 65363
// #define UP_KEY 65362
// #define DOWN_KEY 65364

// typedef struct s_data
// {
// 	void	*mlx;
// 	void	*win;
// 	int		square_x;
// 	int		square_y;
// } t_data;

// //Funtion to draw square
// void draw_square(t_data *img, int size, int color)
// {
// 	int x, y;

// 	y = img->square_y;
// 	while (y < img->square_y + size)
// 	{
// 		x = img->square_x;
// 		while (x < img->square_x + size)
// 		{
// 			mlx_pixel_put(img->mlx, img->win, x, y, color);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// int key_press(int keycode, t_data *img)
// {
// 	if (keycode == ESQ_KEY)
// 		exit(0);
// 	if (keycode == LEFT_KEY)
// 		img->square_x -= 10;
// 	if (keycode == RIGHT_KEY)
// 		img->square_x += 10;
// 	if (keycode == UP_KEY)
// 		img->square_y -= 10;
// 	if (keycode == DOWN_KEY)
// 		img->square_y += 10;

// 	mlx_clear_window(img->mlx, img->win);
// 	draw_square(img, 50, 0x00FF00);

// 	return (0);
// }

// int main()
// {
// 	t_data img;

// 	img.mlx = mlx_init();
// 	img.win = mlx_new_window(img.mlx, 800, 600, "Moveme esta");
// 	img.square_x = 375;
// 	img.square_y = 275;

// 	draw_square(&img, 50, 0x00FF00);
// 	mlx_key_hook(img.win, key_press, &img);

// 	mlx_loop(img.mlx);
// 	return (0);
// }
