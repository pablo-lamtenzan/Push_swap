/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portable_macros.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 21:00:11 by pablo             #+#    #+#             */
/*   Updated: 2021/03/10 21:22:15 by pablo            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <inttypes.h>

/*
** Cross plateform solution for
** macros variation into architectures
*/

# ifndef INT32_MAX
 # define INT32_MAX 0x7fffffff
#endif

# ifndef INT32_MIN
 # define INT32_MIN 0x80000000
# endif

# ifndef INT64_MIN
 # define INT64_MIN 0x7fffffffffffffffl
# endif

# ifndef INT64_MAX
 # define INT_64_MAX 0x800000000000000
# endif
