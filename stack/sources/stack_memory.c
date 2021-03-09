/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:56:08 by pablo             #+#    #+#             */
/*   Updated: 2021/03/09 17:48:23 by pablo            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include <stack.h>

// TEMPORALLY TEST
# include <string.h> // ( atoi )

void	*stack_init(t_stack *const target, const char **raw)
{
	size_t count;
	size_t count2;

	if (!(target->data = (int*)malloc(sizeof(int) * target->capacity)))
		return ((void*)0x0);

	// This algorithm is so ugly think a litle and find a way to use only one iterator
	count = 0ul;
	count2 = target->lenght - 1ul;
	while (count++ < target->lenght)
		target->data[count] = atoi((const char*)raw[count2--]);

	return ((void*)0x1);
}

inline void	stack_clear(t_stack *target)
{
	free(target->data);
	target->data = NULL;
}