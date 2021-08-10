/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsail.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 13:06:52 by ciglesia          #+#    #+#             */
/*   Updated: 2021/08/10 21:52:35 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compiled.h"

int		main(int ac, char **av __attribute__((unused)))
{
	if (ac < 2)
		display_files();
	return (EXIT_SUCCESS);
}
