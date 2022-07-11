/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartin <gemartin@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 13:51:22 by gemartin          #+#    #+#             */
/*   Updated: 2022/05/17 01:07:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

long int	static	ft_baseexponente(long int base, size_t exp)
{
	long int	nbr;

	if (exp == 0)
		return (1);
	nbr = base;
	while (--exp)
		nbr *= base;
	return (nbr);
}

char	*ft_itoa(int n)
{
	char	*nbr;
	size_t	digitos;

	digitos = 1;
	while (n / ft_baseexponente(10, digitos))
		digitos++;
	nbr = (char *)ft_calloc(digitos + 1, sizeof(char));
	if (!nbr)
		return (0);
	while (--digitos)
	{
		nbr[digitos] = (char)((n % 10) + '0');
		n /= 10;
	}
	nbr[digitos] = (char)((n % 10) + '0');
	return (nbr);
}
