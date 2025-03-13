/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarcos <aarcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 10:22:52 by aarcos            #+#    #+#             */
/*   Updated: 2025/03/12 10:33:14 by aarcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	put_pixel_to_image(t_data *data, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		pixel = data->img_data + (y * data->size_line + x * (data->bpp / 8));
		*(int *)pixel = color;
	}
}
