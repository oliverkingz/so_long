/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:28:43 by ozamora-          #+#    #+#             */
/*   Updated: 2025/01/29 16:38:05 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_display(t_game *game)
{
	int		j;
	int		i;
	char	tile;

	j = -1;
	while (++j < game->map.height)
	{
		i = -1;
		while (++i < game->map.width)
		{
			tile = game->map.grid[j][i];
			if (tile == '0' || tile == 'P' || tile == 'C' || tile == 'X')
				display_img(game, game->graphs.floor, i, j);
			if (tile == '1')
				display_img(game, game->graphs.wall, i, j);
			if (tile == 'C')
				display_img(game, game->graphs.item[1], i, j);
			if (tile == 'C')
				display_img(game, game->graphs.item[0], i, j);
			if (tile == 'X')
				display_img(game, game->graphs.enemy[0], i, j);
			if (tile == 'X')
				display_img(game, game->graphs.enemy[1], i, j);
		}
	}
}

void	display_player_exit(t_game *game)
{
	mlx_image_to_window(game->mlx, game->graphs.play[0],
		game->map.t_size * game->play.x, game->map.t_size * game->play.y);
	mlx_image_to_window(game->mlx, game->graphs.play[1],
		game->map.t_size * game->play.x, game->map.t_size * game->play.y);
	mlx_image_to_window(game->mlx, game->graphs.play[2],
		game->map.t_size * game->play.x, game->map.t_size * game->play.y);
	game->graphs.play[0]->enabled = false;
	game->graphs.play[2]->enabled = false;
	mlx_image_to_window(game->mlx, game->graphs.exit[0],
		game->map.t_size * game->exit.x, game->map.t_size * game->exit.y);
	mlx_image_to_window(game->mlx, game->graphs.exit[1],
		game->map.t_size * game->exit.x, game->map.t_size * game->exit.y);
	game->graphs.exit[0]->enabled = true;
	game->graphs.exit[1]->enabled = false;
}

void	display_img(t_game *game, mlx_image_t *tile, int x, int y)
{
	int32_t	i_instance;

	i_instance = mlx_image_to_window(game->mlx, tile, game->map.t_size * x,
			game->map.t_size * y);
	if (i_instance < 0)
		(free_game(game), ft_mlx_err("Failed displaying image"));
	mlx_set_instance_depth(game->graphs.play[0]->instances,
		tile->instances[i_instance].z + 3);
	mlx_set_instance_depth(game->graphs.play[1]->instances,
		tile->instances[i_instance].z + 2);
	mlx_set_instance_depth(game->graphs.play[2]->instances,
		tile->instances[i_instance].z + 3);
}

void	display_text(t_game *game)
{
	char	*moves;

	moves = ft_itoa(game->moves);
	mlx_delete_image(game->mlx, game->graphs.text);
	game->graphs.text = mlx_put_string(game->mlx, moves, 6, 4);
	free(moves);
}
