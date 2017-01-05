/* LIGHTS
 * Author: Alex
 * Creation date: 12/12/2016
 */
MACHINE
    LIGHTS
    
SEES
    M0, ctx

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
    rr <-- change_lights(cmd) = PRE
        rr : signals &
        cmd : signals
    THEN
        SELECT cmd = DARK THEN
            ANY ll WHERE
                ll:on
            THEN
                on:= on-{ll} ||
                off:= off \/{ll}
            END
        WHEN cmd = STOP THEN
            on := on-{L1, L2, L3}
        WHEN cmd = WARNING THEN
           off := off-{L1, L3} ||
           on := on \/{L1, L3} ||
           on := on-{L2} ||
           off := off \/{L2}
       WHEN cmd = DRIVE THEN
           off := off-{L2, L3} ||
           on := on \/{L2, L3} ||
           on := on -{L1} ||
           off := off \/{L1}
       END
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

