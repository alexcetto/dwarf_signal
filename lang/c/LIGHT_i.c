/* WARNING if type checker is not performed, translation could contain errors ! */

#include "LIGHT.h"

/* Clause SEES */
#include "ctx.h"

/* Clause CONCRETE_CONSTANTS */
/* Basic constants */

/* Array and record constants */
/* Clause CONCRETE_VARIABLES */

/* Clause INITIALISATION */
void LIGHT__INITIALISATION(void)
{
    
}

/* Clause OPERATIONS */

void LIGHT__set_to_on(bool *rr)
{
    (*rr) = true;
}

void LIGHT__set_to_off(bool *rr)
{
    (*rr) = false;
}

