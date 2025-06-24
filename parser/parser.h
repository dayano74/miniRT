/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:22:02 by okaname           #+#    #+#             */
/*   Updated: 2025/06/24 21:52:46 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# define BRIGHT_MAX 1.0
# define BRIGHT_MIN 0.0

# include "../color/color.h"
# include "../libft/libft.h"
# include "../vector/vec.h"
# include "make_object/object.h"

int	parser(t_world *world, char *file);

#endif