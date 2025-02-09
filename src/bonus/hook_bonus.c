/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:40:28 by ozamora-          #+#    #+#             */
/*   Updated: 2025/01/29 16:17:55 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_loop_hook(void *param)
{
	static int	counter = 0;
	t_game		*game;
	int			i;
	bool		state;

	game = (t_game *)param;
	counter++;
	if (counter % 20 == 0)
	{
		i = game->graphs.item[0]->count;
		while (i-- > 0)
		{
			state = (counter % 40 != 0);
			game->graphs.item[0]->enabled = state;
			game->graphs.item[1]->enabled = !state;
			game->graphs.enemy[0]->enabled = state;
			game->graphs.enemy[1]->enabled = !state;
		}
	}
	if (game->map.item == 0)
		game->graphs.exit[1]->enabled = true;
	if (counter >= 1000000)
		counter = 0;
}

void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			(mlx_close_window(game->mlx), free_game(game));
		if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
			move(game, 0, -1);
		if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
			move(game, 0, 1);
		if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
			game->graphs.play[0]->enabled = true;
		if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
			move(game, -1, 0);
		if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
			game->graphs.play[2]->enabled = true;
		if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
			move(game, 1, 0);
	}
	if (keydata.action == MLX_RELEASE && keydata.key != MLX_KEY_ESCAPE)
	{
		game->graphs.play[0]->enabled = false;
		game->graphs.play[2]->enabled = false;
	}
}

void	ft_close_hook(void *param)
{
	t_game	*game;

	game = param;
	mlx_close_window(game->mlx);
	free_game(game);
}
