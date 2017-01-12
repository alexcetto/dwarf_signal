#ifndef _M0_h
#define _M0_h

#include <stdint.h>
#include <stdbool.h>
/* Clause SEES */
#include "ctx.h"

/* Clause IMPORTS */
#include "LIGHTS.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/* Clause SETS */

/* Clause CONCRETE_VARIABLES */


/* Clause CONCRETE_CONSTANTS */
/* Basic constants */
/* Array and record constants */
extern void M0__INITIALISATION(void);

/* Clause OPERATIONS */

extern void M0__set_signal(ctx__signals cmd);
extern void M0__get_signal(ctx__signals *return_signal);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* _M0_h */
