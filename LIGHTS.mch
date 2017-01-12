/* LIGHTS
 * Author: Alex
 * Creation date: 12/12/2016
 */
MACHINE
    LIGHTS
    
SEES ctx
    
CONCRETE_VARIABLES
    L1,
    L2,
    L3,
    currentState,
    swag
    
INVARIANT
    L1 : BOOL &
    L2 : BOOL &
    L3 : BOOL &
    currentState : signals &
    swag : signals &
    (swag = STOP => (currentState /= DRIVE & currentState /= WARNING)) &
    (swag = WARNING => (currentState /= DRIVE))
    
    
INITIALISATION
    L1 := FALSE ||
    L2 := FALSE ||
    L3 := FALSE ||
    currentState := DARK ||
    swag := DARK

OPERATIONS
    
    set_to_dark(currSig) = PRE
        currSig : signals
    THEN
        swag := DARK ||
        currentState := DARK ||
        L1 := FALSE ||
        L2 := FALSE ||
        L3 := FALSE 
    END;
    
    set_to_warning(currSig) = PRE
        currSig : signals
    THEN
        swag := WARNING ||
        currentState := WARNING ||
        L1 := TRUE ||
        L2 := FALSE ||
        L3 := TRUE
    END;
    
    set_to_stop(currSig) = PRE
        currSig : signals
    THEN
        swag := STOP ||
        currentState := STOP ||
        L1 := TRUE ||
        L2 := TRUE ||
        L3 := FALSE
    END;
    
     set_to_drive(currSig)= PRE
        currSig : signals
    THEN
        swag := DRIVE ||
        currentState := DRIVE ||
        L1 := FALSE ||
        L2 := TRUE ||
        L3 := TRUE
    END
    
END

