/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 18:21:13 by pablo             #+#    #+#             */
/*   Updated: 2021/03/09 21:13:27 by pablo            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include <stack.h>

inline void	ra(t_stack *const a, t_stack *const b)
{
	(void)b;
	s_rotate(a);
}

inline void	rb(t_stack *const a, t_stack *const b)
{
	(void)a;
	s_rotate(b);
}

inline void	rr(t_stack *const a, t_stack *const b)
{
	s_rotate(a);
	s_rotate(b);
}