#include "so_long.h"

static void	texture_load(t_root *root, t_img **img, char *path)
{
	int				width;
	int				height;

	*img = mlx_xpm_file_to_image(root->mlx, path, &width, &height);
	// if (*img == 0)
	// 	root_destroy(0, "texture_init(): can't load texture!", 0);
	(*img)->width = width;
	(*img)->height = height;
}

void	texture_init(t_root *root)
{
	//texture_load(root, &root->player, "./textures/player.xpm");
	texture_load(root, &root->exit, "./textures/key.xpm");
	texture_load(root, &root->coll, "./textures/coin.xpm");
	texture_load(root, &root->wall, "./textures/wall.xpm");
	texture_load(root, &root->ground, "./textures/sand.xpm");
}