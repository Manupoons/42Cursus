/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:08:04 by mamaratr          #+#    #+#             */
/*   Updated: 2025/02/05 12:29:13 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../mlx/mlx.h"

int	ft_exit(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	free_data(data);
	exit(EXIT_SUCCESS);
}

static int	ft_render_frame(t_data *data)
{
	put_background(data);
	create_map(data);
	mlx_hook(data->win, 17, 0, ft_exit, data);
	mlx_key_hook(data->win, key_press, data);
	return (0);
}

void	check_map_ext(t_data *data, char *file_name, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error\nInvalid map_path\n");
		exit(EXIT_FAILURE);
	}
	file_name += (ft_strlen(file_name) - 4);
	if (ft_strncmp(file_name, ".ber", 4))
	{
		ft_printf("Error!\nWrong file extension\n");
		exit(1);
	}
	data->size_x = (ft_line_length(fd) * IMG_W);
	data->size_y = (ft_count_lines(fd, data->size_x, IMG_W) * IMG_H);
	close(fd);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_map	map;

	if (argc != 2)
	{
		ft_printf("Error!\nNumber of arguments incorrect\n");
		return (0);
	}
	data.mlx = mlx_init();
	check_map_ext(&data, argv[1], argv);
	map.map = ft_calloc(data.size_y + 1, sizeof(char *));
	if (!map.map)
		calloc_fail("Error\nCalloc map failed\n");
	ft_init(&data, &map);
	validate_map(&data, argv, argc);
	check_path(&data);
	data.win = mlx_new_window(data.mlx, data.size_x, data.size_y, "so_long");
	ft_render_frame(&data);
	mlx_loop(data.mlx);
	perror("Error\nProgram failed to loop\n");
	exit(EXIT_FAILURE);
}
