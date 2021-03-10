/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 17:49:00 by pablo             #+#    #+#             */
/*   Updated: 2021/03/10 21:26:51 by pablo            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include <stack.h>
# include <unistd.h>

void print_operation(t_operation op)
{
	t_umax						i;
	static const char *const	char_operations[] = {
		"sa\n", "sb\n", "ss\n", "pa\n", "pb\n", "ra\n",
		"rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n"
	};

	i = -1;
	while (operation(++i) != op)
		;
	write(STDOUT_FILENO, char_operations[i], sizeof(char_operations[i]) - 1ul);
}

void sort_chunk(t_val *target, t_val *dest, t_umax range)
{
	t_umax it;

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
	const t_umax	lenght = a->ebp - a->esp;
	t_umax			range;
	t_umax			it;

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

int main(int ac, const char **av)
{
	static const char	error[] = "Error\n";
	t_stack				a;
	t_stack				b;

	if (!stack_init_unsorted(&a, av, ac - 1)
	|| !stack_init_auxliar(&b, ac - 1))
		return (write(STDERR_FILENO, error, sizeof(error) - 1ul));
	bottom_up_merge_sort_int32(&a, &b);
	free(a.start_alloc);
	free(b.start_alloc);
	return (0);
}