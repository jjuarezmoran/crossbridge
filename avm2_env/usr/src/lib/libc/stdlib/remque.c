/*
 * Initial implementation:
 * Copyright (c) 2002 Robert Drehmel
 * All rights reserved.
 *
 * As long as the above copyright statement and this notice remain
 * unchanged, you can do what ever you want with this file. 
 */
#include <sys/cdefs.h>
__FBSDID("$FreeBSD: src/lib/libc/stdlib/remque.c,v 1.3.34.1.6.1 2010/12/21 17:09:25 kensmith Exp $");

#define	_SEARCH_PRIVATE
#include <search.h>
#include <stdlib.h>	/* for NULL */

void
remque(void *element)
{
	struct que_elem *prev, *next, *elem;

	elem = (struct que_elem *)element;

	prev = elem->prev;
	next = elem->next;

	if (prev != NULL)
		prev->next = next;
	if (next != NULL)
		next->prev = prev;
}
