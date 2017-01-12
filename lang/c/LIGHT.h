#ifndef _LIGHT_h
#define _LIGHT_h

#include <stdint.h>
#include <stdbool.h>
/* Clause SEES */
#include "ctx.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/* Clause SETS */

/* Clause CONCRETE_VARIABLES */


/* Clause CONCRETE_CONSTANTS */
/* Basic constants */
/* Array and record constants */
extern void LIGHT__INITIALISATION(void);

/* Clause OPERATIONS */

extern void LIGHT__set_to_on(bool *rr);
extern void LIGHT__set_to_off(bool *rr);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* _LIGHT_h */
