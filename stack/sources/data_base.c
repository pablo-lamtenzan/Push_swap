/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 18:54:42 by pablo             #+#    #+#             */
/*   Updated: 2021/03/10 21:28:12 by pablo            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include <stack.h>

inline t_operation		operation(t_umax index)
{
	static const t_operation operations[] = {
		&sa,
		&sb,
		&ss,
		&pa,
		&pb,
		&ra,
		&rb,
		&rr,
		&rra,
		&rrb,
		&rrr
	};
	
	return (index < sizeof(operations) / sizeof(*operations) ?
		operations[index] : (void*)0x0ul);
}

inline const char*const	char_operation(t_umax index)
{
	static const char *const char_operations[] = {
		"sa",
		"sb",
		"ss",
		"pa",
		"pb",
		"ra",
		"rb",
		"rr",
		"rra",
		"rrb",
		"rrr"	
	};

	return (index < sizeof(char_operations) / sizeof(*char_operations) ?
		char_operations[index] : (void*)0x0ul);
}