/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:56:08 by pablo             #+#    #+#             */
/*   Updated: 2021/03/10 17:12:13 by pablo            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include <stack.h>
# include <stdlib.h>

// TEMPORALLY TEST
# include <string.h> // ( atoi )

/*
** Init the unsorted data structure used as t_stack 'a' (circular array):
** t_stack::start_alloc points to the heap pointer.
** t_stack::esp point to the top of the stack and it points
**		to the index (%end_alloc - %start_alloc) / 4.
** t_stack::ebp is the stack base pointer and points to the index
**		(%end_alloc - %start_alloc) / 2 + (%end_alloc - %start_alloc) / 4.
** t_stack::end_alloc point to the of the allocated heap + 1.
*/

bool	stack_init_unsorted(t_stack *const target, const char **raw, size_t lenght)
{
	const bool is_odd = lenght % 2ul;
	const size_t capacity = !is_odd ? lenght * 2ul : (lenght + 1ul) * 2ul;
	size_t it;

	if (!(target->start_alloc = (t_val*)malloc(sizeof(t_val) * capacity)))
		return (false);
	target->end_alloc = target->start_alloc + capacity;
	target->esp = &target->start_alloc[capacity / 4ul];
	target->ebp = &target->esp[(capacity / 4ul) - is_odd];
	it = -1;
	while (++it < lenght)
		target->esp[it] = (t_val)atoi((const char*)raw[it]);
	return (true);
}

/*
** Init the auxiliar data structure used as t_stack 'b' (pseudo circular array):
** t_stack::start_alloc points to the heap pointer.
** t_stack::esp points to midle of %start_alloc.
** t_stack::ebp points to %esp.
** t_stack::end_alloc point to the of the allocated heap + 1.
*/
bool				stack_init_auxliar(t_stack *const target, size_t lenght)
{
	const size_t capacity = !(lenght % 2ul) ? lenght * 2ul : (lenght + 1ul) * 2ul;
	size_t it;

	if (!(target->start_alloc = (t_val*)malloc(sizeof(t_val) * capacity)))
		return (false);
	target->end_alloc = target->start_alloc + capacity;
	target->esp = &target->start_alloc[capacity / 2ul];
	target->ebp = target->esp;
	return (true);
}

inline void	stack_clear(t_stack *target)
{
	free(target->start_alloc);
	target->start_alloc = NULL;
}
