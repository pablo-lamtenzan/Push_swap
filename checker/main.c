/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 18:01:18 by pablo             #+#    #+#             */
/*   Updated: 2021/03/10 21:35:58 by pablo            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include <stack.h>
# include <libc.h>
# include <portable_macros.h>
# include <unistd.h>

static void checker(t_stack *const a, t_stack *const b)
{
	static const char	ok[] = "OK";
	static const char	ko[] = "KO";
	t_smax				cmp;
	t_umax				it;

	if (b->ebp != b->esp)
	{
		write(STDOUT_FILENO, ko, sizeof(ko) - 1ul);
		return ;
	}
	cmp = INT64_MAX;
	it = -1;
	while (++it < a->ebp - a->esp)
	{
		if ((t_smax)a->esp[it] >= cmp)
		{
			write(STDOUT_FILENO, ko, sizeof(ko) - 1ul);
			return ;
		}
		cmp = (t_smax)a->esp[it];
	}
	write(STDOUT_FILENO, ok, sizeof(ok) - 1ul);
}

static void execute_operation(t_stack *const a, t_stack *const b, char* line)
{
	t_umax it;

	it = -1;
	while (ft_strcmp(line, char_operation(++it)))
		;
	operation(it)(a, b);
}

// TO DO: Note ctrl+D
// include gnl and test
int main(int ac, const char **av)
{
	static const char	error[] = "Error\n";
	t_stack				a;
	t_stack				b;
	char				*line;

	if (!stack_init_unsorted(&a, av, ac - 1)
	|| stack_init_auxliar(&b, ac - 1))
		return (write(STDERR_FILENO, error, sizeof(error) - 1ul));
	while (get_next_line(STDIN_FILENO, line) > 0)
	{
		execute_operation(&a, &b, line);
		free(line);
	}
	free(line);
	checker(&a, &b);
	free(a.start_alloc);
	free(b.start_alloc);
	return (0);
}
