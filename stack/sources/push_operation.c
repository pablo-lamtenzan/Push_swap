/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 18:21:03 by pablo             #+#    #+#             */
/*   Updated: 2021/03/09 18:29:22 by pablo            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include <stack.h>

inline void	pa(t_stack *const a, t_stack *const b)
{
	s_push(a, b);
}

inline void	pb(t_stack *const a, t_stack *const b)
{
	s_push(b, a);
}
