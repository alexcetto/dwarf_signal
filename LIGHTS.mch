/* LIGHTS
 * Author: Alex
 * Creation date: 12/12/2016
 */
MACHINE
    LIGHTS
    
SEES
    M0, ctx

VARIABLES
        
    
OPERATIONS
    change_lights(cmd) = PRE
        cmd: signals
    THEN
         currentSignal := cmd
    END
END

