/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartin <gemartin@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:22:04 by gemartin          #+#    #+#             */
/*   Updated: 2022/05/12 16:47:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*bzero;

	bzero = (void *)malloc(count * size);
	if (!bzero)
		return (0);
	ft_bzero (bzero, count * size);
	return (bzero);
}
