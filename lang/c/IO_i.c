/* WARNING if type checker is not performed, translation could contain errors ! */

#include "IO.h"

/* Clause SEES */
#include "ctx.h"

/* Clause IMPORTS */
#include "M0.h"

/* Clause CONCRETE_CONSTANTS */
/* Basic constants */

/* Array and record constants */
/* Clause CONCRETE_VARIABLES */

/* Clause INITIALISATION */
void IO__INITIALISATION(void)
{
    
    M0__INITIALISATION();
}

/* Clause OPERATIONS */

void IO__set_command(int32_t law_and_order)
{
    if(law_and_order == 0)
    {
        M0__set_signal(ctx__DARK);
    }
    else if(law_and_order == 1)
    {
        M0__set_signal(ctx__STOP);
    }
    else if(law_and_order == 2)
    {
        M0__set_signal(ctx__WARNING);
    }
    else if(law_and_order == 3)
    {
        M0__set_signal(ctx__DRIVE);
    }
}

void IO__get_command(ctx__signals *return_value)
{
    M0__get_signal(return_value);
}

