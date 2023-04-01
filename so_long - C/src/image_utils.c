/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 18:50:47 by rteles-f          #+#    #+#             */
/*   Updated: 2023/02/27 19:09:08 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	my_mlx_pixel_get(t_data *data, int x, int y)
{
	char	*dst;

	(void)dst;
	dst = data->addr + (y * data->line_length + x * \
		(data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	transparent_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (color < 0x00000f00)
		return ;
	dst = data->addr + (y * data->line_length + x * \
		(data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	(void)dst;
	dst = data->addr + (y * data->line_length + x * \
		(data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
