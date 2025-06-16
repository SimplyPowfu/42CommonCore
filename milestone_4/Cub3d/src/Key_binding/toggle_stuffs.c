/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toggle_stuffs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glancell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 23:27:01 by glancell          #+#    #+#             */
/*   Updated: 2025/06/09 23:27:55 by glancell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	toggle_hud(t_root *root)
{
	root->hud->show_hud = !root->hud->show_hud;
	render_frame(root);
	return (0);
}

int	toggle_minimap(t_root *root)
{
	root->hud->show_minimap = !root->hud->show_minimap;
	render_frame(root);
	return (0);
}

int	toggle_helmet(t_root *root)
{
	if (HEIGHT == 900 && WIDTH == 1600)
	{
		root->hud->show_helmet = !root->hud->show_helmet;
		render_frame(root);
	}
	return (0);
}

int	toggle_raytracing(t_root *root)
{
	root->is_raytracing = !root->is_raytracing;
	render_frame(root);
	return (0);
}
