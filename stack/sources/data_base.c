/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 18:54:42 by pablo             #+#    #+#             */
/*   Updated: 2021/03/09 19:35:40 by pablo            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include <stack.h>

inline t_operation		operation(size_t index)
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
		operations[index] : NULL);
}

inline const char*const		char_operation(size_t index)
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
		char_operations[index] : NULL);
}