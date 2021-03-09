/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 18:01:18 by pablo             #+#    #+#             */
/*   Updated: 2021/03/09 19:53:50 by pablo            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include <stack.h>
# include <unistd.h>
# include <limits.h>

static void checker(t_stack *const a, t_stack *const b)
{
	static const char ok[] = "OK";
	static const char ko[] = "KO";
	long cmp;
	size_t it;
	
	if (b->lenght != 0ul)
	{
		write(STDOUT_FILENO, ko, sizeof(ko));
		return ;
	}
	cmp = LONG_MAX;
	it = -1;
	while (++it < a->lenght)
	{
		if (a->data[it] >= cmp)
		{
			write(STDOUT_FILENO, ko, sizeof(ko));
			return ;
		}
		cmp = a->data[it];
	}
	write (STDOUT_FILENO, ok, sizeof(ok));
}

static void execute_operation(t_stack *const a, t_stack *const b, char* line)
{
	size_t it;

	it = 0ul;
	// This is a security exploit, must securize it
	while (strcmp(line, char_operation(it)))
		it++;
	operation(it)(a, b);
}

// TO DO: Note ctrl+D
// include gnl and test
// include / change strcmp
int main(int ac, const char **av)
{
	t_stack a;
	t_stack b;
	char *line;

	a = (t_stack){ .capacity=(size_t)(ac-1), .lenght=(size_t)(ac-1) };
	b = (t_stack){ .capacity=(size_t)(ac-1), .lenght=0ul };
	if (!stack_init(&a, av) || stack_init(&b, av))
		return (EXIT_FAILURE);
	while (get_next_line(STDIN_FILENO, line) > 0)
	{
		execute_operation(&a, &b, line);
		free(line);
	}
	free(line);
	checker(&a, &b);
	stack_clear(&a);
	stack_clear(&b);
	return (EXIT_SUCCESS);
}
