// #include <mlx.h>

// typedef struct s_data
// {
// 	void	*mlx;
// 	void	*win;
// 	void	*img;
// 	char	*addr;
// 	int		bpp;
// 	int		line_lenght;
// 	int		endian;
// } t_data;

// void my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_lenght + x * (data->bpp / 8));
// 	*(unsigned int*)dst = color;
// }

// int main(void)
// {
// 	t_data img;

// 	img.mlx = mlx_init();
// 	img.win = mlx_new_window(img.mlx, 640, 480, "Píxel");
// 	img.img = mlx_new_image(img.mlx, 640, 480);
// 	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_lenght, &img.endian);

// 	my_mlx_pixel_put(&img, 320, 240, 0x00FF0000);

// 	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
// 	mlx_loop(img.mlx);
// 	return(0);
// }
