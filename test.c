/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 14:31:23 by lpetsoan          #+#    #+#             */
/*   Updated: 2020/01/12 15:08:01 by lpetsoan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <term.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>

#ifdef unix
static char term_buiffer[2048];
#else
#define term_buffer 0
#endif


void init_terminal_data (void)
{
    char *termtype = getenv("TERM");
    int success;

    if (termtype == 0)
    {
        printf("Please spicify the terminal type as an environment variable;");
        exit(1);
    }
    success = tgetent ( term_buffer, termtype );
    if ( success < 0  ){
        printf("Could not access the termvcap data base.\n");
        exit(1);
    }
    if (success == 0){
        printf("Terminal type %s is not defined.\n", termtype);
        exit(1);
    }

}
char *tgetstr ();

char *cl_string, *cm_string;
int height, width, auto_wrap;

char PC;    /* For tputs */
char *BC;   /* For tgoto */
char *UP;

void interrogate_terminal(void)
{
#ifdef unix
    /* Here we assume that an explicit term_buffer
     * was set 
     */
    char *buffer;
#define BUFFADDR &buffer
#else
#define BUFFADDR 0
#endif

    char *temp;

    /* Extract information we will user. */
    cl_string = tgetstr ("cl", BUFFADDR);
    cm_string = tgetstr ("cm", BUFFADDR);
    auto_wrap = tgetflag ("am");
    height = tgetnum ("li");
    width = tgetnum ("co");

    /* Extract information that termcap functions will user. */
    temp = tgetstr ("pc", BUFFADDR);
    PC = temp ? *temp : 0;
    BC = tgetstr ("le", BUFFADDR);
    UP = tgetstr ("up", BUFFADDR);
}

short ospeed;

int main(void)
{
    init_terminal_data();
    interrogate_terminal();

    tputs (":al=2.3*\E[L:", 1, putchar);
    return (0);
}
