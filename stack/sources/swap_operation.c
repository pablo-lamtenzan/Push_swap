/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 18:21:19 by pablo             #+#    #+#             */
/*   Updated: 2021/03/09 21:13:43 by pablo            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include <stack.h>

inline void	sa(t_stack *const a, t_stack *const b)
{
	(void)b;
	s_swap(a);
}

inline void	sb(t_stack *const a, t_stack *const b)
{
	(void)a;
	s_swap(b);
}

inline void	ss(t_stack *const a, t_stack *const b)
{
	s_swap(a);
	s_swap(b);
}