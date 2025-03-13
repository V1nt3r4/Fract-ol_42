#ifndef	FRACT-OL
# define FRACT-OL


# include "minilibx-linux/mlx.h" // Incluye Minilibx
# include <stdlib.h> // Para exit()
# include <stdio.h> // Para pritf()
# include <math.h> // Para funciones matemáticas

#define WIDTH 800
#define HEIGHT 600
#define MLX_ERROR 1

typedef struct s_data
{
	void	*mlx_ptr; // Puntero a la conexión de minilibx
	void	*win_ptr; // Puntero a la ventana
	void	*img_ptr; // Imagen en memoria
	char	*img_data; // Dirección a la imagen en memoria
	int		bpp; // Bytes por píxeles
	int		size_line; // Longitud en cada línnea de memoria
	int		endian; // Endianess de la longitud (0 o 1)	
} t_data;


int		init(t_data *data);
void	put_pixel_to_image(t_data *data, int x, int y, int color);
void	render(t_data *data);
int		handle_key(int keycode, t_data *data);

#endif

