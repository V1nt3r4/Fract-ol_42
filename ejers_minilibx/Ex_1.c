// INICIALIZACIÓN Y CREACIÓN DE VENTANA
#include <mlx.h>

int main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 680, 430, "Mi ventana");

	mlx_loop(mlx);
	return (0);
}

int main() {
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 700, 500, "Ventana PVC");

	mlx_loop(mlx);
	return (0);
}
