/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_operations.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:22:13 by pablo             #+#    #+#             */
/*   Updated: 2021/03/09 17:10:35 by pablo            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <sys/types.h>

void	swap(int *const a, int *const b);

// See if i can use only one fucntion to rotate
void	rotate_up(int *const raw, size_t lenght);
void	rotate_down(int *const raw, size_t lenght);

