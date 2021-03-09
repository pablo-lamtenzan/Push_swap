/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:41:45 by pablo             #+#    #+#             */
/*   Updated: 2021/03/09 16:38:58 by pablo            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <stdlib.h>

typedef struct	s_stack
{
	int			*data;
	size_t		lenght;
	size_t		capacity;
}				t_stack;

void			*stack_init(t_stack *const target, const char **raw);
void			stack_clear(t_stack *target);

// Has same signature cause it useful to use function pointers
void			s_swap(t_stack *const lhs, t_stack *const rhs);
void			s_push(t_stack *const lhs, t_stack *const rhs);
void			s_rotate(t_stack *const lhs, t_stack *const rhs);
void			s_reverse_rotate(t_stack *const lhs, t_stack *const rhs);

