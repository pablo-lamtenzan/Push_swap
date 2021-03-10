/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:15:48 by pablo             #+#    #+#             */
/*   Updated: 2021/03/10 19:10:52 by pablo            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include <stack.h>
# include <fast_operations.h>

/*
** Move %esp to index 25% of the circular array if %esp == %start_alloc.
** Move &ebp to index 75% of the circular array if %ebp == %end_alloc.
** Obiously, values in range %esp-%ebp are moved too.
*/

void move_all_to_the_middle(t_val *const start_alloc, t_val **esp,
t_val **ebp, const t_val *const end_alloc)
{
	const size_t capacity = end_alloc - start_alloc;
	const size_t amount = *ebp - *esp;
	const bool is_ebp = *ebp == end_alloc;
	const size_t base_index = capacity / 4ul + (is_ebp ? capacity / 2ul : 0ul);
	size_t it;

	it = -1;
	while (++it < amount)
		start_alloc[(size_t)((long)base_index + (long)((amount - it)
		* (is_ebp ? 1l : -1l)))] = (*esp)[is_ebp ? it : amount - it];
	if (!is_ebp)
	{
		*esp = start_alloc + base_index;
		*ebp = *esp + amount;
	}
	else
	{
		*ebp = start_alloc + base_index;
		*esp = *ebp - amount;
	}
}

inline void	s_swap(t_stack *const s)
{
	if (s->ebp - s->esp > 1)
		swap(s->esp, s->esp + 1ul);
}

inline void	s_push(t_stack *const dest, t_stack *const src)
{
	if (src->ebp != src->esp)
	{
		if (dest->esp == dest->start_alloc)
			move_all_to_the_middle(dest->start_alloc, &dest->esp,
			&dest->ebp, dest->end_alloc);
		*(--dest->esp) = *(src->esp++);
	}
}

inline void	s_rotate(t_stack *const s)
{
	if (s->ebp - s->esp > 1)
		rotate_up(s->start_alloc, &s->esp, &s->ebp, s->end_alloc);
}

inline void	s_reverse_rotate(t_stack *const s)
{
	if (s->ebp - s->esp > 1)
		rotate_down(s->start_alloc, &s->esp, &s->ebp, s->end_alloc);
}