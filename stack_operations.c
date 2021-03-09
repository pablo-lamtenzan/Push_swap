/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:15:48 by pablo             #+#    #+#             */
/*   Updated: 2021/03/09 17:28:51 by pablo            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "stack.h"
# include "fast_operations.h"

inline void	s_swap(t_stack *const lhs, t_stack *const rhs)
{
	(void)rhs;
	if (lhs->lenght > 1ul)
		swap(&lhs->data[lhs->lenght], &lhs->data[lhs->lenght - 1ul]);
}

inline void	s_push(t_stack *const lhs, t_stack *const rhs)
{
	if (rhs->lenght != 0ul)
	{
		lhs->data[++lhs->lenght] = rhs->data[rhs->lenght];
		rhs->data[rhs->lenght--] = 0;
	}
}

inline void	s_rotate(t_stack *const lhs, t_stack *const rhs)
{
	(void)rhs;
	rotate_up(lhs->data, lhs->lenght - 1ul);
}

inline void	s_reverse_rotate(t_stack *const lhs, t_stack *const rhs)
{
	(void)rhs;
	rotate_down(lhs->lenght, lhs->lenght - 1ul);
}