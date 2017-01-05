/* LIGHTS
 * Author: Alex
 * Creation date: 12/12/2016
 */
MACHINE
    LIGHTS
    
    
SEES ctx 

SETS
    LAMPES = {L1, L2, L3}
VARIABLES
    on, off
INVARIANT
    on <: LAMPES &
    off <: LAMPES &
    on \/ off = LAMPES &
    on /\ off = {}
    
INITIALISATION
    off:=LAMPES ||
    on := {}
OPERATIONS
    
    
    rr <-- change_to_dark = PRE
        rr : signals
    THEN
        ANY ll WHERE
            ll:on
        THEN
            on:= on-{ll} ||
            off:= off \/{ll}
        END
        ||
        rr := DARK
    END;
    
    rr <-- change_to_warning = PRE
        rr : signals
    THEN
        on := {} \/ {L1, L3} || 
        off := {} \/ {L2}
        ||
        rr := WARNING
    END;
    
    rr <-- change_to_stop = PRE
        rr : signals
    THEN
        on := {} \/ {L1, L2} || 
        off := {} \/ {L3}
        ||
        rr := STOP
    END;
    
     rr <-- change_to_drive = PRE
        rr : signals
    THEN
        on := {} \/ {L2, L3} || 
        off := {} \/ {L1}
        ||
        rr := DRIVE
    END;
    
    
    
    ss <-- read_state = PRE
        ss : signals
    THEN
        SELECT L1:off & L2:off & L3:off THEN ss:=DARK
        WHEN L1:off & L2:on & L3:on THEN ss := DRIVE
        WHEN L1:on & L2:off & L3:on THEN ss := WARNING
        WHEN L1:on & L2:on & L3:off THEN ss:= STOP
        ELSE ss:= INDETERMINE
    END
    
END
END

