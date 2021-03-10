/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:15:48 by pablo             #+#    #+#             */
/*   Updated: 2021/03/10 17:49:31 by pablo            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include <stack.h>
# include <fast_operations.h>

inline void	s_swap(t_stack *const s)
{
	swap(s->esp, s->esp + 1ul);
}

inline void	s_push(t_stack *const dest, t_stack *const src)
{
	if (src->ebp != src->esp)
	{
		if (dest->esp - 1ul == dest->start_alloc)
			move_all_to_the_middle(dest->start_alloc, &dest->esp,
			&dest->ebp, dest->end_alloc);
		*(--dest->esp) = *(src->esp++);
	}
}

inline void	s_rotate(t_stack *const s)
{
	rotate_up(s->start_alloc, &s->esp, &s->ebp, s->end_alloc);
}

inline void	s_reverse_rotate(t_stack *const s)
{
	rotate_down(s->start_alloc, &s->esp, &s->ebp, s->end_alloc);
}