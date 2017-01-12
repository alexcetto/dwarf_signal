/* IO
 * Author: oliviermarin
 * Creation date: 06/01/2017
 */
MACHINE
    IO
    
SEES ctx
   
VARIABLES
    order
    
INITIALISATION
    order := DARK
    
INVARIANT
    order : signals
    
OPERATIONS
    set_command(law_and_order) = PRE
        law_and_order : NAT &
        law_and_order : 0..3
    THEN
        SELECT law_and_order = 0 THEN order := DARK
        WHEN law_and_order = 1 THEN order := STOP
        WHEN law_and_order = 2 THEN order := WARNING
        WHEN law_and_order = 3 THEN order := DRIVE
        END    
    END        
END
