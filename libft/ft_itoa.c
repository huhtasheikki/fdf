/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 11:56:12 by hhuhtane          #+#    #+#             */
/*   Updated: 2019/10/29 14:54:35 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		ft_len_count(int n)
{
	size_t		n_len;

	n_len = 1;
	if (n < 0)
	{
		n_len++;
	}
	while ((n > 9 || n < -9))
	{
		n /= 10;
		n_len++;
	}
	return (n_len);
}

char			*ft_itoa(int n)
{
	size_t		n_len;
	char		*str;

	n_len = ft_len_count(n);
	if (!(str = (char*)malloc(sizeof(char) * (n_len + 1))))
		return (NULL);
	str[n_len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		if (n == -2147483648)
		{
			str[--n_len] = '8';
			n /= 10;
		}
		n *= -1;
	}
	while (n > 9)
	{
		str[--n_len] = (n % 10) + '0';
		n /= 10;
	}
	str[--n_len] = n + '0';
	return (str);
}
