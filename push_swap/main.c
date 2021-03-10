/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 17:49:00 by pablo             #+#    #+#             */
/*   Updated: 2021/03/10 18:05:05 by pablo            ###   ########lyon.fr   */
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

void sort_chunk(t_val *target, t_val *dest, size_t range)
{
	size_t it;

	it = 0;
	// TO DO: tomorrow, find the better way to solve this.
	// Just have to find the most optimal way to sort those chunks.

	// 1) Find smallest index
	// 2) See if index =< (range / 2) left is the shorter way to the top
	// 3) Else right is the shorter way top
	// 4) To find the top rotate and swap if necesary 1st and 2nd
	// 5) Push to dest
	// 6) Repeat until range element had been pushed
}

// just copy and sort by range of 2, 4, 8, 16, ...

void bottom_up_merge_sort_int32(t_stack *const a, t_stack *const b)
{
	const size_t lenght = a->ebp - a->esp;
	size_t range;
	size_t it;

	range = 2ul;
	while (range < lenght)
	{
		it = 0ul;
		// TO DO: Think about this algorithm, not enought good
		while (it < lenght && (it += range))
			;//sort_chunk(&data[it], &aux[it], range);
		range *= 2ul;
	}
}

// TO DO: Parse error handling
int main(int ac, const char **av)
{
	t_stack a;
	t_stack b;

	if (!stack_init_unsorted(&a, av, ac - 1) || !stack_init_auxliar(&b, ac - 1))
		return (1);
	bottom_up_merge_sort_int32(&a, &b);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}