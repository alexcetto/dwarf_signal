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
    set_to_stop =
    BEGIN
        nextSignal, command :(
            currentSignal: signals &
            nextSignal: signals &
            command: signals &
            nextSignal /= DRIVE & nextSignal /= WARNING
        )
    END;
    set_to_drive =
    BEGIN
       nextSignal, command :(
            currentSignal: signals &
            nextSignal: signals &
            command: signals
       )
    END;
    set_to_warning =
    BEGIN
        nextSignal, command :(
            currentSignal: signals &
            nextSignal: signals &
            command: signals &
            nextSignal /= DRIVE
       )
   END;
   set_to_dark =
   BEGIN
        nextSignal, command :(
            currentSignal: signals &
            nextSignal: signals &
            command: signals &
            nextSignal /= DRIVE & nextSignal /= WARNING
        )
   END
END
