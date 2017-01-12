#ifndef _IO_h
#define _IO_h

#include <stdint.h>
#include <stdbool.h>
/* Clause SEES */
#include "ctx.h"

/* Clause IMPORTS */
#include "M0.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/* Clause SETS */

/* Clause CONCRETE_VARIABLES */


/* Clause CONCRETE_CONSTANTS */
/* Basic constants */
/* Array and record constants */
extern void IO__INITIALISATION(void);

/* Clause OPERATIONS */

extern void IO__set_command(int32_t law_and_order);
extern void IO__get_command(ctx__signals *return_value);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* _IO_h */
