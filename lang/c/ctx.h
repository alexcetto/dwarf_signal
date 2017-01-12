#ifndef _ctx_h
#define _ctx_h

#include <stdint.h>
#include <stdbool.h>
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/* Clause SETS */
typedef enum
{
    ctx__DRIVE,
    ctx__WARNING,
    ctx__STOP,
    ctx__DARK,
    ctx__INDETERMINE
    
} ctx__signals;
#define ctx__signals__max 5

/* Clause CONCRETE_VARIABLES */


/* Clause CONCRETE_CONSTANTS */
/* Basic constants */
/* Array and record constants */
extern void ctx__INITIALISATION(void);


#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* _ctx_h */
