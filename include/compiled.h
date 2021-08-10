/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compiled.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 22:26:10 by ciglesia          #+#    #+#             */
/*   Updated: 2021/08/10 22:46:12 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPILED_H
# define COMPILED_H

# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include <ncurses.h>
# include <locale.h>

# define WL 10
# define WC 26

/*
** interface
*/

void	display_files(void);

#endif
