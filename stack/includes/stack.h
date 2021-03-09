/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:41:45 by pablo             #+#    #+#             */
/*   Updated: 2021/03/09 19:11:54 by pablo            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <stdlib.h>

/*
** Stack lib member types
*/

typedef struct		s_stack
{
	int				*data;
	size_t			lenght;
	size_t			capacity;
}					t_stack;

typedef void (*const t_operation)(t_stack*, t_stack*);


/*
** Memory handlers
*/

void				*stack_init(t_stack *const target, const char **raw);
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

t_operation *const	operation(size_t index);
const char*const	char_operation(size_t index);

