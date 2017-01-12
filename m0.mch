/* M0
 * Author: Alex
 * Creation date: 12/12/2016
 */
MACHINE
    M0
    
SEES ctx
    
VARIABLES
    currentSignal,
    command
    
INVARIANT
    currentSignal : signals &
    command : signals 
    
INITIALISATION
    currentSignal := DARK ||
    command := DARK

OPERATIONS
    set_signal(cmd) = PRE
        cmd : signals
    THEN
        IF cmd = DARK THEN 
            currentSignal := cmd ||
            command := cmd
        ELSIF cmd = STOP THEN 
            currentSignal := cmd ||
            command := cmd
        ELSIF cmd = WARNING THEN 
            currentSignal := cmd ||
            command := cmd
        ELSIF cmd = DRIVE THEN 
            currentSignal := cmd ||
            command := cmd
        ELSE 
            currentSignal := INDETERMINE ||
            command := INDETERMINE
        END
    END
    
END
