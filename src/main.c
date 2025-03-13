/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarcos <aarcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 10:09:11 by aarcos            #+#    #+#             */
/*   Updated: 2025/03/12 10:12:22 by aarcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int main(void)
{
	t_data	data;

	if (init(&data) == MLX_ERROR)
	{
		write(2, "Error: Initialization failed.\n", 30);
		return (1);
	}
	render(&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}