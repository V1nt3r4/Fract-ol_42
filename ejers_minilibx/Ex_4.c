// #include <mlx.h>
// #include <stdlib.h>

// #define ESQ_KEY 65307

// typedef struct s_data
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


// int main()
// {
// 	t_data	img;

// 	img.mlx = mlx_init();
// 	if (!img.mlx)
// 		return 1;
// 	img.win = mlx_new_window(img.mlx, 800, 400, "Un Pixel");

// 	mlx_pixel_put(img.mlx, img.win, 700, 500, 0x00FF0000);

// 	mlx_key_hook(img.win, close_window, NULL);
// 	mlx_loop(img.mlx);
// 	return 0;
// }
