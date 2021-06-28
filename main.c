/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouelw <cabouelw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:50:58 by cabouelw          #+#    #+#             */
/*   Updated: 2021/06/28 15:02:11 by cabouelw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

long int	ft_atoi(const char *s)
{
	int			sign;
	long int	n;

	n = 0;
	sign = 1;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	else if (*s == '+')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		n = n * 10 + sign * (*s - '0');
		s++;
	}
	return (n);
}

int main()
{
    long int l;

    l = 2147483648;
    if (l > 2147483647)
        printf("long\n");
    l = ft_atoi("9223372036854775807");
    printf("%ld\n", l);
    if (l > 2147483647)
        printf("long long\n");
    l = -2147483659;
    if (l < -2147483648)
        printf("long\n");
}