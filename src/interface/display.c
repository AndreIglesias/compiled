/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 18:44:46 by ciglesia          #+#    #+#             */
/*   Updated: 2021/08/10 23:24:43 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "compiled.h"

static int	ft_strlen(char *str)
{
	int	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	calc_x(int x, int *ix)
{
	if (COLS / 2 + WC / 2 + x >= COLS)
		*ix *= -1;
	else if (COLS / 2 - WC / 2 + x <= 0)
		*ix *= -1;
	return (x + *ix);
}

static int	calc_y(int y, int *iy)
{
	if (LINES / 2 + WL / 2 + y >= LINES)
		*iy *= -1;
	else if (LINES / 2 - WL / 2 + y <= 0)
		*iy *= -1;
	return (y + *iy);
}

void	resize_window(WINDOW *w, int *x, int *y, int *ix, int *iy)
{
	static char	*successul = "Successful";
	static char	*compilation = "Compilation";
	refresh();
	delwin(w);

	*x = calc_x(*x, ix);
	*y = calc_y(*y, iy);

	w = newwin(WL, WC, LINES / 2 - WL / 2 + *y, COLS / 2 - WC / 2 + *x);
	box(w, 0, 0);
	mvwprintw(w, WL / 2 - 1, WC / 2 - ft_strlen(successul) / 2, successul);
	mvwprintw(w, WL / 2, WC / 2 - ft_strlen(compilation) / 2, compilation);
	wrefresh(w);
}

void	display_files(void)
{
	int		key;
	WINDOW	*w = NULL;
	int		x = 0;
	int		y = 0;
	int		ix = 1;
	int		iy = 1;

	initscr();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	intrflush(stdscr, FALSE);
	setlocale(LC_ALL, "");
	curs_set(0);
	nodelay(stdscr, 1);
	resize_window(w, &x, &y, &ix, &iy);
	while ((key = getch()) != 'q') {
		usleep(100000);
		if (key == KEY_RESIZE) {
			clear();
			resize_window(w, &x, &y, &ix, &iy);
			refresh();
		}
		else
		{
			resize_window(w, &x, &y, &ix, &iy);
		}
	}
    endwin();
}
