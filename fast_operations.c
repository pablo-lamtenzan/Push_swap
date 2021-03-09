/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:27:37 by pablo             #+#    #+#             */
/*   Updated: 2021/03/09 17:33:25 by pablo            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "fast_operations.h"

inline void	swap(int *const a, int *const b)
{
	int c;

	if (a != b)
	{
		c = *b;
		*b = *a;
		*a = c;
	}
}

inline void	rotate_up(int *const raw, size_t lenght)
{
	size_t it;
	const int saved = raw[lenght];

	it = 0ul;
	while (++it <= lenght)
		raw[it] = raw[it - 1ul];
	raw[0ul] = saved;
}

inline void	rotate_down(int *const raw, size_t lenght)
{
	size_t it;
	const int saved = raw[0ul];

	it = lenght;
	while (--it >= 0)
		raw[it] = raw[it + 1ul];
	raw[lenght] = saved;
}