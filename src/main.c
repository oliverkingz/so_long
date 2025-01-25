/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozamora- <ozamora-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:37:28 by ozamora-          #+#    #+#             */
/*   Updated: 2025/01/25 21:02:31 by ozamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int32_t	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		if (ft_strlen(argv[1]) == 0)
			ft_mlx_err("Invalid map: path is empty");
		game = init_game(&game, argv[1]);
		print_map_grid(&game);
		if (game.is_running == true)
		{
			mlx_key_hook(game.mlx, &ft_key_hook, &game);
			mlx_loop_hook(game.mlx, ft_loop_hook, &game);
			mlx_close_hook(game.mlx, ft_close_hook, &game);
			mlx_loop(game.mlx);
		}
		mlx_terminate(game.mlx);
	}
	else
		ft_mlx_err("Usage: ./so_long \"assets/maps/example.ber\"");
	return (EXIT_SUCCESS);
}
