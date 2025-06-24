/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 20:25:09 by okaname           #+#    #+#             */
/*   Updated: 2025/06/24 21:36:01 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int		array_count(char **array);
double	atof_with_error(char *str, double max, double min);
int		atoi_with_error(char *n, int max, int min);

#endif
