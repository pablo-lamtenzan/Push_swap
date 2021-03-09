/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 17:49:00 by pablo             #+#    #+#             */
/*   Updated: 2021/03/09 21:17:46 by pablo            ###   ########lyon.fr   */
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
	write(STDOUT_FILENO, char_op, sizeof(char_op) - 1ul);
	write(STDOUT_FILENO, endl, sizeof(endl) - 1ul);
}

void sort_chunk(int *target, int *dest, size_t range)
{
	size_t it;

	it = 0;
	// TO DO: tomorrow, find the better way to solve this.
	// Just have to find the most optimal way to sort those chunks.
}

// just copy and sort by range of 2, 4, 8, 16, ...

void bottom_up_merge_sort_int32(int *data, int *aux, size_t lenght)
{
	size_t range;
	size_t it;

	range = 2ul;
	while (range < lenght)
	{
		it = 0ul;
		while (it < lenght && (it += range))
			sort_chunk(&data[it], &aux[it], range);
		range *= 2ul;
	}
}

// TO DO: Parse error handling
int main(int ac, const char **av)
{
	t_stack a;
	t_stack b;

	a = (t_stack){ .capacity=(size_t)(ac-1), .lenght=ac };
	b = (t_stack){ .capacity=(size_t)(ac-1), .lenght=0ul };
	if (!stack_init(&a, av) || !stack_init(&b, av))
		return (EXIT_FAILURE);
	bottom_up_merge_sort_int32(a.data, b.data, a.lenght);
	stack_clear(&a);
	stack_clear(&b);
	return (EXIT_SUCCESS);
}