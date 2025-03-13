/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarcos <aarcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 10:09:18 by aarcos            #+#    #+#             */
/*   Updated: 2025/03/12 10:09:19 by aarcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL);
		return (MLX_ERROR);
	data->mlx_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "Fract-ol");
	if (data->mlx_ptr == NULL)
	{
		free(data->mlx_ptr);
		return (MLX_ERROR);
	}
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	if (data->img_ptr == NULL)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data->mlx_ptr);
		return (MLX_ERROR);
	}
	data->img_data = mlx_get_data_addr(data->img_ptr, &data->bpp, &data->size_line, &data->endian);
	return (0);
}

