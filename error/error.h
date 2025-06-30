/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaname <okaname@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:41:23 by okaname           #+#    #+#             */
/*   Updated: 2025/06/30 11:48:05 by okaname          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

void	error_open(char *file);
void	error_malloc(char **tokenlist, t_world *world);
void	syntax_error(char **tokenlist, t_world *world);
void	error_invalid(char **tokenlist, t_world *world);

#endif