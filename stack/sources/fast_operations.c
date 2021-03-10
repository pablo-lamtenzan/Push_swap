/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:27:37 by pablo             #+#    #+#             */
/*   Updated: 2021/03/10 20:54:18 by pablo            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include <stack.h>
# include <fast_operations.h>

inline void	swap(t_val *const a, t_val *const b)
{
	t_val c;

	if (a != b)
	{
		c = *b;
		*b = *a;
		*a = c;
	}
}

inline void rotate_up(const t_val *const start_alloc, t_val **esp,
t_val **ebp, const t_val *const end_alloc)
{
	if (*ebp == end_alloc)
		move_all_to_the_middle(start_alloc, esp, ebp, end_alloc);
	*(++(*ebp)) = *((*esp)++);
}

inline void rotate_down(const t_val *const start_alloc, t_val **esp,
t_val **ebp, const t_val *const end_alloc)
{
	if (*esp == start_alloc)
		move_all_to_the_middle(start_alloc, esp, ebp, end_alloc);
	*(--(*esp)) = *((*ebp)--);
}
