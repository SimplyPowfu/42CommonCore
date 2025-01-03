#include "so_long.h"

static void	texture_load(t_root *root, t_img **img, char *path)
{
	int	width;
	int	height;

	*img = mlx_xpm_file_to_image(root->mlx, path, &width, &height);
	(*img)->width = width;
	(*img)->height = height;
}

void	image_load(t_root *root)
{
	int	x;
    int	y;
	int	pos;
	int color1;
	int color2;
	int combined;

	x = 0;
	y = 0;
	while (y < root->ground->height)
	{
		while (x < root->ground->width)
		{
			pos = y * root->ground->size_line + x * (root->ground->bpp / 8);
			color1 = *(int *)root->ground->data + pos;
			color2 = *(int *)root->player->data + pos;
			combined = ((color1 & 0xFF) + (color2 & 0xFF)) / 2 |
                    	(((color1 >> 8 & 0xFF) + (color2 >> 8 & 0xFF)) / 2) << 8 |
                        (((color1 >> 16 & 0xFF) + (color2 >> 16 & 0xFF)) / 2) << 16;
			*(int *)(root->mlx_img->data + pos) = combined;//probema segFault
			x++;
		}
		x = 0;
		y++;
	}
}

void	texture_init(t_root *root)
{
	texture_load(root, &root->player, "./textures/player.xpm");
	texture_load(root, &root->playerM, "./textures/playerMove.xpm");
	texture_load(root, &root->exit, "./textures/key.xpm");
	texture_load(root, &root->coll, "./textures/coin.xpm");
	texture_load(root, &root->wall, "./textures/wall.xpm");
	texture_load(root, &root->ground, "./textures/sand.xpm");
}