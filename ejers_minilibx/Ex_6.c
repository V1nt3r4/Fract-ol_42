// #include "mlx.h"
// #include <stdlib.h>

// #define ESQ_KEY 65307

// typedef struct t_data
// {
// 	void	*mlx;
// 	void	*win;
// } t_data;

// int close_window(int keycode, void *param)
// {
// 	(void)param;
// 	if (keycode == ESQ_KEY)
// 		exit (0);
// 	return 0;
// }

// void my_mlx_pixel_put(void *mlx, void *win, int x, int y, int color)
// {
// 	mlx_pixel_put(mlx, win, x, y, color);
// }

// void draw_gradient(t_data *img, int width, int height)
// {
// 	int x;
// 	int y;
// 	int red, green, blue;
// 	int color;

// 	y = 0;
// 	while (y < height)
// 	{
// 		x = 0;
// 		while (x < width)
// 		{
// 			red	= (x * 255) / width;
// 			green = 0;
// 			blue = 255 - ((x * 255) / width);
// 			// red	= 0;
// 			// green = 0;
// 			// blue = (x * 255) / (width / 2);

// 			color = (red << 16) | (green << 8) | blue;
// 			my_mlx_pixel_put(img->mlx, img->win, x, y, color);

// 			x++;
// 		}
// 		y++;
// 	}
// }

// int main()
// {
// 	t_data	img;
// 	int		width = 800;
// 	int		height = 600;

// 	img.mlx = mlx_init();
// 	if (!img.mlx)
// 		return 1;
// 	img.win = mlx_new_window(img.mlx, width, height, "Degradado");

// 	draw_gradient(&img, width, height);

// 	mlx_key_hook(img.win, close_window, &img);
// 	mlx_loop(img.mlx);
// 	return 0;
// }