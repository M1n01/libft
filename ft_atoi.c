/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 10:57:14 by minabe            #+#    #+#             */
/*   Updated: 2022/06/06 17:24:21 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_sign(const char *str, size_t *i);

int	ft_atoi(const char *str)
{
	size_t		i;
	long long	nbr;
	int			sign;

	i = 0;
	while (('\t' <= str[i] && str[i] <= '\r') || str[i] == ' ')
		i++;
	sign = check_sign(str, &i);
	nbr = 0;
	while (ft_isdigit(str[i]))
	{
		if ((nbr * 10 + (str[i] - '0')) / 10 != nbr)
		{
			if (sign == 1)
				return (-1);
			if (sign == -1)
				return (0);
		}
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	nbr *= sign;
	return ((int)nbr);
}

static int	check_sign(const char *str, size_t *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}
