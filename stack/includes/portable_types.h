/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portable_types.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 21:12:22 by pablo             #+#    #+#             */
/*   Updated: 2021/03/10 21:25:26 by pablo            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <sys/types.h>

# define VALUE_TYPE int
# define S_OP_TYPE long
# define U_OP_TYPE size_t

typedef VALUE_TYPE	t_val;
typedef S_OP_TYPE t_smax;
typedef U_OP_TYPE t_umax;
