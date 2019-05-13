#include "fillit.h"

void freetlist(t_tetr *tetr)
{		
	t_tetr *buf;

	buf = tetr;
	while (tetr)
	{
		buf = tetr->next;
		free(tetr->fig);
		free(tetr);
		tetr = buf;
	}
}
