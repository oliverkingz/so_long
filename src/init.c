/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:49:16 by ozamora-          #+#    #+#             */
/*   Updated: 2025/01/24 15:05:09 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	init_game(t_game *game, char *map_dir)
{
	init_texture(game);
	init_map(game, map_dir);
	init_mlx(game);
	init_images(game);
	init_display(game);
	game->graphs.text = mlx_put_string(game->mlx, "0", 6, 4);
	game->moves = 0;
	game->is_running = true;
	return (*game);
}

void	init_texture(t_game *game)
{
	game->graphs.player_t[0] = mlx_load_png("./assets/textures/Player_TL.png");
	if (!game->graphs.player_t[0])
		ft_mlx_err("Failed loading player texture\n");
	game->graphs.player_t[1] = mlx_load_png("./assets/textures/Player_TF.png");
	if (!game->graphs.player_t[1])
		ft_mlx_err("Failed loading player texture\n");
	game->graphs.player_t[2] = mlx_load_png("./assets/textures/Player_TR.png");
	if (!game->graphs.player_t[2])
		ft_mlx_err("Failed loading player texture\n");
	game->graphs.floor_t = mlx_load_png("./assets/textures/Tile.png");
	if (!game->graphs.floor_t)
		ft_mlx_err("Failed loading floor texture\n");
	game->graphs.wall_t = mlx_load_png("./assets/textures/Tree.png");
	if (!game->graphs.wall_t)
		ft_mlx_err("Failed loading wall texture\n");
	game->graphs.exit_t = mlx_load_png("./assets/textures/House.png");
	if (!game->graphs.exit_t)
		ft_mlx_err("Failed loading exit texture\n");
	game->graphs.item_t[0] = mlx_load_png("./assets/textures/Food.png");
	if (!game->graphs.item_t[0])
		ft_mlx_err("Failed loading item texture\n");
	game->graphs.item_t[1] = mlx_load_png("./assets/textures/Food_B.png");
	if (!game->graphs.item_t[1])
		ft_mlx_err("Failed loading item texture");
}

void	init_images(t_game *game)
{
	game->graphs.player[0] = mlx_texture_to_image(game->mlx,
			game->graphs.player_t[0]);
	game->graphs.player[1] = mlx_texture_to_image(game->mlx,
			game->graphs.player_t[1]);
	game->graphs.player[2] = mlx_texture_to_image(game->mlx,
			game->graphs.player_t[2]);
	game->graphs.item[0] = mlx_texture_to_image(game->mlx,
			game->graphs.item_t[0]);
	game->graphs.item[1] = mlx_texture_to_image(game->mlx,
			game->graphs.item_t[1]);
	game->player.img = game->graphs.player[1];
	game->graphs.floor = mlx_texture_to_image(game->mlx, game->graphs.floor_t);
	game->graphs.wall = mlx_texture_to_image(game->mlx, game->graphs.wall_t);
	game->graphs.exit = mlx_texture_to_image(game->mlx, game->graphs.exit_t);
}

void	init_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.grid[i][j] == 'P')
			{
				game->player.x = j;
				game->player.y = i;
				game->player.img = game->graphs.player[1];
			}
			j++;
		}
		i++;
	}
}

void	init_mlx(t_game *game)
{
	int	height;
	int	width;

	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	height = game->map.height * game->map.t_size;
	width = game->map.width * game->map.t_size;
	game->mlx = mlx_init(width, height, "so_long", true);
	if (!game->mlx)
		ft_mlx_err("Failed init MLX42");
	mlx_set_window_size(game->mlx, width * 2, height * 2);
	mlx_set_icon(game->mlx, game->graphs.player_t[1]);
	mlx_set_window_limit(game->mlx, width, height, width * 3, height * 3);
}
