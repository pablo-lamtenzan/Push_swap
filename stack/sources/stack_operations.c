/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:15:48 by pablo             #+#    #+#             */
/*   Updated: 2021/03/09 18:34:34 by pablo            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include <stack.h>
# include <fast_operations.h>

inline void	s_swap(t_stack *const s)
{
	if (s->lenght > 1ul)
		swap(&s->data[s->lenght], &s->data[s->lenght - 1ul]);
}

inline void	s_push(t_stack *const lhs, t_stack *const rhs)
{
	if (rhs->lenght != 0ul)
	{
		lhs->data[++lhs->lenght] = rhs->data[rhs->lenght];
		rhs->data[rhs->lenght--] = 0;
	}
}

inline void	s_rotate(t_stack *const s)
{
	rotate_up(s->data, s->lenght - 1ul);
}

inline void	s_reverse_rotate(t_stack *const s)
{
	rotate_down(s->lenght, s->lenght - 1ul);
}