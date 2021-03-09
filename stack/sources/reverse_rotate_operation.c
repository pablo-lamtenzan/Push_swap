/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 18:21:09 by pablo             #+#    #+#             */
/*   Updated: 2021/03/09 21:13:10 by pablo            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include <stack.h>

inline void	rrra(t_stack *const a, t_stack *const b)
{
	(void)b;
	s_reverse_rotate(a);
}

inline void	rb(t_stack *const a, t_stack *const b)
{
	(void)a;
	s_reverse_rotate(b);
}

inline void	rrr(t_stack *const a, t_stack *const b)
{
	s_reverse_rotate(a);
	s_reverse_rotate(b);
}