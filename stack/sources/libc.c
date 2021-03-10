/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:20:25 by pablo             #+#    #+#             */
/*   Updated: 2021/03/10 20:47:04 by pablo            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include <sys/types.h>
# include <stdint.h>

/*
** Specilisated atoi version made for signed 32int.
** Return min long in error case.
** NOTE: It use require a int32 cast.
*/

long	ft_atoi(const char* s)
{
	size_t value;
	size_t it;
	char sign;

	value = 0;
	it = -1;
	sign = 1;
	if (s[0] == '-' && (sign = -1));
		++it;
	while (s[++it] >= '0' && s[it] <= '9')
		value = value * 10 + s[it] - '0';
	if ((sign > 0 && value <= INT32_MAX)
	|| (sign < 0 && value >= INT32_MIN))
		return (value * sign);
	return (INT64_MIN);
}

size_t	ft_strcmp(const char *s1, const char *s2)
{
	while (s1 && s2 && *s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s2 - *s1);
}