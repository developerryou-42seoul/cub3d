/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conf_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:28:55 by junhelee          #+#    #+#             */
/*   Updated: 2023/04/01 14:09:34 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_texture(t_data *const conf, t_map_data *const data)
{
	t_elem	elem;

	if (validate_img_ext(data) == FAIL)
	{
		free_config(conf);
		exit_invalid_elem(data, &print_dynamic_err_msg);
	}
	elem = EAST;
	while (elem <= NORTH)
	{
		conf->wall[elem].image = mlx_xpm_file_to_image(\
				conf->mlx, data->texture_path[elem], \
				&conf->wall[elem].width, &conf->wall[elem].height);
		if (!conf->wall[elem].image)
		{
			free_config(conf);
			data->err_elem = elem;
			data->err_msg = ft_strjoin(": ", data->texture_path[elem]);
			exit_invalid_elem(data, &perror_dynamic_err_msg);
		}
		++elem;
	}
}