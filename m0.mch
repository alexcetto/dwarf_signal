/* M0
 * Author: Alex
 * Creation date: 12/12/2016
 */
MACHINE
    M0
    
SEES ctx
    
VARIABLES
    currentSignal,
    nextSignal,
    command
    
INVARIANT
    currentSignal : signals &
    nextSignal : signals &
    command : signals &
    (command = STOP => (nextSignal /= DRIVE & nextSignal /= WARNING)) &
    (command = WARNING => (nextSignal /= DRIVE))
    
    
INITIALISATION
    currentSignal := STOP ||
    nextSignal := STOP ||
    command := STOP

OPERATIONS
    setSignal=
    BEGIN
        currentSignal, nextSignal, command :(
            currentSignal: signals
           & nextSignal: signals &
           command: signals &
    (command = STOP => (nextSignal /= DRIVE & nextSignal /= WARNING)) &
    (command = WARNING => (nextSignal /= DRIVE))
           
        )
        
    END
    
            
END
