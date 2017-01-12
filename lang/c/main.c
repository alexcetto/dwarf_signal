#include "IO.h"
#include "ctx.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
	ctx__signals *mon_signal = malloc((size_t) sizeof(ctx__signals));
	printf("Bien le bonjour, AtelierB c'est super !\n" );

	printf("Set système to command WARNING :\n" );
	IO__set_command(2);
	IO__get_command(mon_signal);

	IO__get_command(mon_signal);
	if (*mon_signal == ctx__WARNING)
		printf("WARNING");
	else if(*mon_signal == ctx__DRIVE)
		printf("DRIVE");
	else if(*mon_signal == ctx__STOP)
		printf("STOP");
	else if(*mon_signal == ctx__DARK)
		printf("DARK");
	else
		printf("INDETERMINE");

	printf(" signal is set !\n");
	return 0;
}
