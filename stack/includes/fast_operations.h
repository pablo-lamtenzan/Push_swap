/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_operations.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:22:13 by pablo             #+#    #+#             */
/*   Updated: 2021/03/10 17:39:42 by pablo            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <sys/types.h>

# ifndef VALUE_TYPE
#  define VALUE_TYPE int
# endif

# ifndef VALUE_TYPE
#  ifndef t_val
    typedef VALUE_TYPE	t_val;
#  endif
# endif

void					swap(t_val *const a, t_val *const b);
void 					rotate_up(const t_val *const start_alloc, t_val **esp,
						t_val **ebp, const t_val *const end_alloc);
void 					rotate_down(const t_val *const start_alloc, t_val **esp,
						t_val **ebp, const t_val *const end_alloc);
