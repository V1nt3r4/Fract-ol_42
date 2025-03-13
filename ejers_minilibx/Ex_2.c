// #include <mlx.h>
// #include <stdlib.h>

// #define ESC_KEY 65307

// int close_window(int keycode, void	*param)
// {
// 	(void)param;
// 	if (keycode == ESC_KEY)
// 		exit(0);
// 	return(0);
// }

// int main(void)
// {
// 	void *mlx;
// 	void *win;

// 	mlx = mlx_init();
// 	win = mlx_new_window(mlx, 840, 350, "Tu Vieja");

// 	mlx_key_hook(win, close_window, NULL);	
// 	mlx_loop(mlx);

// 	return (0);
// }
