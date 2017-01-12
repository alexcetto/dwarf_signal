#ifndef _LIGHTS_h
#define _LIGHTS_h

#include <stdint.h>
#include <stdbool.h>
/* Clause SEES */
#include "ctx.h"

/* Clause IMPORTS */
#include "LIGHT.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/* Clause SETS */

/* Clause CONCRETE_VARIABLES */

extern bool LIGHTS__L1;
extern bool LIGHTS__L2;
extern bool LIGHTS__L3;
extern ctx__signals LIGHTS__currentState;
extern ctx__signals LIGHTS__swag;

/* Clause CONCRETE_CONSTANTS */
/* Basic constants */
/* Array and record constants */
extern void LIGHTS__INITIALISATION(void);

/* Clause OPERATIONS */

extern void LIGHTS__set_to_dark(ctx__signals currSig);
extern void LIGHTS__set_to_warning(ctx__signals currSig);
extern void LIGHTS__set_to_stop(ctx__signals currSig);
extern void LIGHTS__set_to_drive(ctx__signals currSig);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* _LIGHTS_h */
