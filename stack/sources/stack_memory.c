/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:56:08 by pablo             #+#    #+#             */
/*   Updated: 2021/03/10 21:30:20 by pablo            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include <stack.h>
# include <libc.h>
# include <portable_macros.h>
# include <portable_types.h>
# include <stdlib.h>


/*
** Uses an spetialised version of atoi made
** for return INT32_MIN in case of "subjet error".
** Futhermore, check if each integer is unique.
*/

static bool	unique_atoi(t_val *array, const char* s, t_val *const x,
t_umax lenght)
{
	t_smax			integer;
	static size_t	end_array;
	t_umax 			it;

	if (!end_array++ && (array = malloc(sizeof(t_val) * lenght)))
		return (false);
	if ((integer = ft_atoi(s)) < INT32_MIN)
		return (false);
	it = -1;
	while (++it < end_array)
		if (integer == array[it])
			return (false);
	*x = (t_val)integer;
}

/*
** Init the unsorted data structure used as t_stack 'a' (circular array):
** t_stack::start_alloc points to the heap pointer.
** t_stack::esp point to the top of the stack and it points
**		to the index (%end_alloc - %start_alloc) / 4.
** t_stack::ebp is the stack base pointer and points to the index
**		(%end_alloc - %start_alloc) / 2 + (%end_alloc - %start_alloc) / 4.
** t_stack::end_alloc point to the of the allocated heap + 1.
*/

bool		stack_init_unsorted(t_stack *const target, const char **raw,
t_umax lenght)
{
	const bool		is_odd = lenght % 2ul;
	const t_umax	capacity = !is_odd ? lenght * 2ul : (lenght + 1ul) * 2ul;
	t_umax			it;
	t_val			*tmp;

	if (!(target->start_alloc = (t_val*)malloc(sizeof(t_val) * capacity)))
		return (false);
	target->end_alloc = target->start_alloc + capacity;
	target->esp = &target->start_alloc[capacity / 4ul];
	target->ebp = &target->esp[(capacity / 4ul) - is_odd];
	it = -1;
	while (++it < lenght)
		if (!unique_atoi(tmp, raw[it], &target->esp[it], lenght))
			return (false);
	return (true);
}

/*
** Init the auxiliar data structure used as t_stack 'b' (pseudo circular array):
** t_stack::start_alloc points to the heap pointer.
** t_stack::esp points to midle of %start_alloc.
** t_stack::ebp points to %esp.
** t_stack::end_alloc point to the of the allocated heap + 1.
*/

bool		stack_init_auxliar(t_stack *const target, t_umax lenght)
{
	const t_umax	capacity = !(lenght % 2ul) ? lenght * 2ul : (lenght + 1ul) * 2ul;
	t_umax			it;

	if (!(target->start_alloc = (t_val*)malloc(sizeof(t_val) * capacity)))
		return (false);
	target->end_alloc = target->start_alloc + capacity;
	target->esp = &target->start_alloc[capacity / 2ul];
	target->ebp = target->esp;
	return (true);
}
