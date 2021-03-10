/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:41:45 by pablo             #+#    #+#             */
/*   Updated: 2021/03/10 17:17:50 by pablo            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// TOTAL OPERATIONS per data structure
// linear dlinked list: push 4, rot 4, swap 2
// circular dlinked list: push 7, rot 1, swap 2
// circular array: push 2, rot 3, swap 2 (but sometimes move all values at some point)

# pragma once

# include <sys/types.h>
# include <stdbool.h>

/*
** Stack lib member types
*/

#define VALUE_TYPE int

typedef VALUE_TYPE	t_val;

typedef struct		s_stack
{
	// simple array
	//int				*data;
	//size_t			lenght;
	//size_t			capacity;

	// circular array
	t_val				*start_alloc;
	t_val				*esp;
	t_val				*ebp;
	t_val				*end_alloc;
}					t_stack;

typedef void (*const t_operation)(t_stack*, t_stack*);


/*
** Memory handlers
*/

bool				stack_init_unsorted(t_stack *const target, const char **raw, size_t lenght);
bool				stack_init_auxliar(t_stack *const target, size_t lenght);
void				stack_clear(t_stack *target);

/*
** Core functions
*/

void				s_swap(t_stack *const s);
void				s_push(t_stack *const lhs, t_stack *const rhs);
void				s_rotate(t_stack *const s);
void				s_reverse_rotate(t_stack *const s);

/*
** Specilised functions
*/

void				sa(t_stack *const a, t_stack *const b);
void				sb(t_stack *const a, t_stack *const b);
void				ss(t_stack *const a, t_stack *const b);

void				pa(t_stack *const a, t_stack *const b);
void				pb(t_stack *const a, t_stack *const b);

void				ra(t_stack *const a, t_stack *const b);
void				rb(t_stack *const a, t_stack *const b);
void				rr(t_stack *const a, t_stack *const b);

void				rra(t_stack *const a, t_stack *const b);
void				rrb(t_stack *const a, t_stack *const b);
void				rrr(t_stack *const a, t_stack *const b);

/*
** Getters for 42 Norme
*/

t_operation			operation(size_t index);
const char*const	char_operation(size_t index);

