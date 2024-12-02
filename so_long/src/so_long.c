/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:08:04 by mamaratr          #+#    #+#             */
/*   Updated: 2024/12/02 13:53:46 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../mlx/mlx.h"

//map extension
void	check_map_ext(char *file_name)
{
	file_name = file_name + (ft_strlen(file_name) - 4);
	if (ft_strcmp(file_name, ".ber", 4))
	{
		write(2, "Error!\n Wrong file extension", 28);
		exit(1);
	}
}

int	ft_exit(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	free_double_pointer(data);
	exit(EXIT_SUCCESS);
}

void	ft_winner(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	ft_printf("Congratulations!!\n You won in %d moves", data->counter);
	free_double_pointer(data);
	exit(EXIT_SUCCESS);
}

//keyboard input check
static int	ft_render_frame(t_data *data)
{
	put_background(data);
	create_map(data);
	mlx_hook(data->win, 17, 1L << 2, ft_exit, data);
	mlx_key_hook(data->win, key_press, data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_map	map;

	window_size(&data, argv);
	check_map_ext(argv[1]);
	map.map = ft_calloc(data.size_y + 1, sizeof(char *));
	if (!map.map)
		calloc_fail("Error\ncalloc failed\n");
	ft_init(&data, &map);
	validate_map(&data, argv, argc);
	check_path(&data);
	data.mlx = mlx_init();
	if (!data.mlx)
	{
		perror("Error\nprogram initialization failed\n");
		exit(EXIT_FAILURE);
	}
	data.win = mlx_new_window(data.mlx, data.size_x, data.size_y, "so_long");
	ft_render_frame(&data);
	mlx_loop(data.mlx);
	perror("Error\nprogram failed to loop\n");
	exit(EXIT_FAILURE);
}
