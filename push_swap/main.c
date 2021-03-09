/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 17:49:00 by pablo             #+#    #+#             */
/*   Updated: 2021/03/09 19:09:17 by pablo            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include <stack.h>
# include <unistd.h>

void print_operation(t_operation op)
{
	size_t i = 0ul;
	static char *char_op;
	static const char endl[] = "\n";

	while (operation(i) != op)
		i++;
	char_op = char_operation(i);
	write(STDOUT_FILENO, char_op, sizeof(char_op));
	write(STDOUT_FILENO, endl, sizeof(endl));
}

int main(int ac, const char **av)
{
	t_stack a;

	a = (t_stack){.capacity=(size_t)(ac-1), .lenght=(size_t)ac};
	if (!stack_init(&a, av))
		return (EXIT_FAILURE);
	stack_sort(a);
	stack_clear(&a);
	return (EXIT_SUCCESS);
}