// Linea recta, algoritmo de BRESENHAN
// #include <mlx.h>
// #include <stdlib.h>
// #include <math.h>

// #define ESQ_KEY 65307


// typedef struct s_data 
// {
// 	void	*mlx;
// 	void	*win;
// } s_data;

// int	close_window(int keycode, void *param)
// {
// 	(void)param;
// 	if (keycode == ESQ_KEY)
// 		exit(1);
// 	return 0;
// }

// void my_mlx_pixel_put(void *mlx, void *win, int x, int y, int color)
// {
// 	mlx_pixel_put(mlx, win, x, y, color);
// }

// int mi_abs(int n)
// {
// 	if (n < 0)
// 		return -n;
// 	return n;
// }

// void draw_line(s_data *img, int x0, int y0, int x1, int y1, int color)
// {
// 	int dx, dy, sx, sy, err, e2;

// 	dx = mi_abs(x1 - x0);
// 	dy = mi_abs(y1 - x1);

// 	if (x0 < x1) // Derecha
// 		sx = 1;
// 	else
// 		sx = -1;

// 	if (y0 < y1) // Izquierda
// 		sy = 1;
// 	else
// 		sy = -1;

// 	err = dx - dy; // Si el error es muy negativo, nos tenemos que mover en Y

// 	while (x0 != x1 || y0 != y1)
// 	{
// 		my_mlx_pixel_put(img->mlx, img->win, x0, y0, color);
// 		e2 = 2 * err;

// 		// Nos movemos en X o en Y?
// 		if (e2 > -dy)//Nos movemos en X
// 		{
// 			err = err - dy;
// 			x0 = x0 + sx;
// 		}
// 		if (e2 < dx)//Nos movemos en Y
// 		{
// 			err = err + dx;
// 			y0 = y0 + sy;
// 		}
// 	}
// }


// int main() {

// 	s_data	img;

// 	img.mlx = mlx_init();
// 	if(!img.mlx)
// 		return(1);
// 	img.win = mlx_new_window(img.mlx, 800, 400, "Window");

// 	draw_line(&img, 100, 100, 700, 500, 0x00FFFFFF);

// 	mlx_key_hook(img.win, close_window, NULL);
// 	mlx_loop(img.mlx);
// 	return 0;
// }
