/* WARNING if type checker is not performed, translation could contain errors ! */

#include "M0.h"

/* Clause SEES */
#include "ctx.h"

/* Clause IMPORTS */
#include "LIGHTS.h"

/* Clause CONCRETE_CONSTANTS */
/* Basic constants */

/* Array and record constants */
/* Clause CONCRETE_VARIABLES */

static ctx__signals M0__currentSignal;
static ctx__signals M0__command;
/* Clause INITIALISATION */
void M0__INITIALISATION(void)
{
    
    LIGHTS__INITIALISATION();
    M0__currentSignal = ctx__DARK;
    M0__command = ctx__DARK;
}

/* Clause OPERATIONS */

void M0__set_signal(ctx__signals cmd)
{
    M0__command = cmd;
    if(M0__command == ctx__DARK)
    {
        LIGHTS__set_to_dark(M0__currentSignal);
        M0__currentSignal = ctx__DARK;
    }
    else if(M0__command == ctx__STOP)
    {
        LIGHTS__set_to_stop(M0__currentSignal);
        M0__currentSignal = ctx__STOP;
    }
    else if(M0__command == ctx__WARNING)
    {
        LIGHTS__set_to_warning(M0__currentSignal);
        M0__currentSignal = ctx__WARNING;
    }
    else if(M0__command == ctx__DRIVE)
    {
        LIGHTS__set_to_drive(M0__currentSignal);
        M0__currentSignal = ctx__DRIVE;
    }
    else
    {
        M0__currentSignal = ctx__INDETERMINE;
    }
}

void M0__get_signal(ctx__signals *return_signal)
{
    (*return_signal) = M0__command;
}

