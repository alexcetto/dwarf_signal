/* LIGHT
 * Author: Alex
 * Creation date: 12/12/2016
 */
MACHINE
    LIGHT
    
SEES ctx
    

OPERATIONS
    rr <-- set_to_on = PRE
        rr : BOOL
    THEN
        rr := TRUE
    END;
    
    rr <-- set_to_off = PRE
        rr : BOOL
    THEN
        rr := FALSE
    END

END
