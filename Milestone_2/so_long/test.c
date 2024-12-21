#include "so_long.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1600, 900, "Hello world!");
	mlx_loop(mlx);
}
