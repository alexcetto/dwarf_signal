/* WARNING if type checker is not performed, translation could contain errors ! */

#include "LIGHTS.h"

/* Clause SEES */
#include "ctx.h"

/* Clause IMPORTS */
#include "LIGHT.h"

/* Clause CONCRETE_CONSTANTS */
/* Basic constants */

/* Array and record constants */
/* Clause CONCRETE_VARIABLES */

bool LIGHTS__L1;
bool LIGHTS__L2;
bool LIGHTS__L3;
ctx__signals LIGHTS__currentState;
ctx__signals LIGHTS__swag;
/* Clause INITIALISATION */
void LIGHTS__INITIALISATION(void)
{
    
    LIGHT__INITIALISATION();
    LIGHTS__L1 = false;
    LIGHTS__L2 = false;
    LIGHTS__L3 = false;
    LIGHTS__currentState = ctx__DARK;
    LIGHTS__swag = ctx__DARK;
}

/* Clause OPERATIONS */

void LIGHTS__set_to_dark(ctx__signals currSig)
{
    LIGHTS__swag = ctx__DARK;
    LIGHTS__currentState = currSig;
    LIGHT__set_to_off(&LIGHTS__L1);
    LIGHTS__currentState = ctx__INDETERMINE;
    LIGHT__set_to_off(&LIGHTS__L2);
    LIGHT__set_to_off(&LIGHTS__L3);
    LIGHTS__currentState = ctx__DARK;
}

void LIGHTS__set_to_warning(ctx__signals currSig)
{
    LIGHTS__swag = ctx__WARNING;
    LIGHTS__currentState = currSig;
    if(currSig == ctx__STOP)
    {
        LIGHT__set_to_off(&LIGHTS__L2);
        LIGHTS__currentState = ctx__INDETERMINE;
        LIGHT__set_to_on(&LIGHTS__L3);
        LIGHT__set_to_on(&LIGHTS__L1);
    }
    else if(currSig == ctx__DARK)
    {
        LIGHT__set_to_on(&LIGHTS__L1);
        LIGHTS__currentState = ctx__INDETERMINE;
        LIGHT__set_to_on(&LIGHTS__L3);
        LIGHT__set_to_off(&LIGHTS__L2);
    }
    else if(currSig == ctx__DRIVE)
    {
        LIGHT__set_to_off(&LIGHTS__L2);
        LIGHTS__currentState = ctx__INDETERMINE;
        LIGHT__set_to_on(&LIGHTS__L1);
        LIGHT__set_to_on(&LIGHTS__L3);
    }
    else
    {
        LIGHT__set_to_on(&LIGHTS__L1);
        LIGHTS__currentState = ctx__INDETERMINE;
        LIGHT__set_to_off(&LIGHTS__L2);
        LIGHT__set_to_on(&LIGHTS__L3);
    }
    LIGHTS__currentState = ctx__WARNING;
}

void LIGHTS__set_to_stop(ctx__signals currSig)
{
    LIGHTS__swag = ctx__STOP;
    LIGHTS__currentState = currSig;
    if(currSig == ctx__WARNING)
    {
        LIGHT__set_to_off(&LIGHTS__L3);
        LIGHTS__currentState = ctx__INDETERMINE;
        LIGHT__set_to_on(&LIGHTS__L2);
        LIGHT__set_to_on(&LIGHTS__L1);
    }
    else if(currSig == ctx__DARK)
    {
        LIGHT__set_to_on(&LIGHTS__L1);
        LIGHTS__currentState = ctx__INDETERMINE;
        LIGHT__set_to_on(&LIGHTS__L2);
        LIGHT__set_to_off(&LIGHTS__L3);
    }
    else if(currSig == ctx__DRIVE)
    {
        LIGHT__set_to_on(&LIGHTS__L1);
        LIGHTS__currentState = ctx__INDETERMINE;
        LIGHT__set_to_off(&LIGHTS__L3);
        LIGHT__set_to_on(&LIGHTS__L2);
    }
    else
    {
        LIGHT__set_to_on(&LIGHTS__L1);
        LIGHTS__currentState = ctx__INDETERMINE;
        LIGHT__set_to_on(&LIGHTS__L2);
        LIGHT__set_to_off(&LIGHTS__L3);
    }
    LIGHTS__currentState = ctx__STOP;
}

void LIGHTS__set_to_drive(ctx__signals currSig)
{
    LIGHTS__swag = ctx__DRIVE;
    LIGHTS__currentState = currSig;
    if(currSig == ctx__WARNING)
    {
        LIGHT__set_to_off(&LIGHTS__L1);
        LIGHTS__currentState = ctx__INDETERMINE;
        LIGHT__set_to_on(&LIGHTS__L2);
        LIGHT__set_to_on(&LIGHTS__L3);
    }
    else if(currSig == ctx__DARK)
    {
        LIGHT__set_to_on(&LIGHTS__L2);
        LIGHTS__currentState = ctx__INDETERMINE;
        LIGHT__set_to_on(&LIGHTS__L3);
        LIGHT__set_to_off(&LIGHTS__L1);
    }
    else if(currSig == ctx__STOP)
    {
        LIGHT__set_to_off(&LIGHTS__L1);
        LIGHTS__currentState = ctx__INDETERMINE;
        LIGHT__set_to_on(&LIGHTS__L3);
        LIGHT__set_to_on(&LIGHTS__L2);
    }
    else
    {
        LIGHT__set_to_off(&LIGHTS__L1);
        LIGHTS__currentState = ctx__INDETERMINE;
        LIGHT__set_to_on(&LIGHTS__L2);
        LIGHT__set_to_on(&LIGHTS__L3);
    }
    LIGHTS__currentState = ctx__DRIVE;
}

