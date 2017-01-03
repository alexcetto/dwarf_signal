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
    currentSignal := DARK ||
    nextSignal := DARK ||
    command := DARK

OPERATIONS
    set_to_stop =
    BEGIN
        nextSignal :(
            currentSignal: signals &
            nextSignal: signals &
            command: signals &
            command = STOP &
            nextSignal /= DRIVE & nextSignal /= WARNING
        )
    END;
    set_to_drive =
    BEGIN
       nextSignal :(
            currentSignal: signals &
            nextSignal: signals &
            command: signals &
            command = DRIVE
       )
    END;
    set_to_warning =
    BEGIN
        nextSignal :(
            currentSignal: signals &
            nextSignal: signals &
            command: signals &
            command = WARNING &
            nextSignal /= DRIVE
       )
   END;
   set_to_dark =
   BEGIN
        nextSignal :(
            currentSignal: signals &
            nextSignal: signals &
            command: signals &
            command = DARK &
            nextSignal /= DRIVE & nextSignal /= WARNING
        )
   END
END
