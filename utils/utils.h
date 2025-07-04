/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 20:25:09 by okaname           #+#    #+#             */
/*   Updated: 2025/06/30 09:54:02 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int		array_count(char **array);
bool	atof_with_error(char *str, double max, double min, double *num);
bool	atoi_with_error(char *n, int max, int min, int *num);
void	substitute(int *v1, int num1, int *v2, int num2);

#endif
