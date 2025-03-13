#include "mlx.h"
#include <stdlib.h>
#include <unistd.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define SQUARE_SIZE 50
#define SPEED 2

typedef struct  s_data
{
	void	*mlx;
	void	*win;
	int		square_x;
	int		square_y;
	int		direction; // 1 = right || -1 = left
} t_data;

// Función para dibujar el cuadrado
void draw_square(t_data *img, int size, int color)
{
	int x, y;

	y = img->square_y;
	while (y < img->square_y + size)
	{
		x = img->square_x;
		while (x < img->square_x + size)
		{
			mlx_pixel_put(img->mlx, img->win, x, y, color);
			x++;
		}
		y++;
	}
}

int update_frame(t_data *img)
{
	usleep(10000); // Pequeña pausa para controlar la velocidad

	img->square_x += img->direction * SPEED;

	// Si llega al borde, cambia la dirección
	if (img->square_x + SQUARE_SIZE >= WINDOW_WIDTH || img->square_x <= 0)
	img->direction *= -1;

	//Redibuja la pantalla
	mlx_clear_window(img->mlx, img->win);
	draw_square(img, SQUARE_SIZE, 0x00FF00);

	return (0);

}

int main()
{
	t_data img;

	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "MANOLO ESTO SE MUEVE SOLO!");
	img.square_x = 0;// Empieza en el borde izq.
	img.square_y = (WINDOW_HEIGHT - SQUARE_SIZE) / 2;// Centro verticalmente
	img.direction = 1;// Empieza moviendose a la derecha

	draw_square(&img, SQUARE_SIZE, 0x00FF00);
	mlx_loop_hook(img.mlx, update_frame, &img);

	mlx_loop(img.mlx);
	return (0);
}

