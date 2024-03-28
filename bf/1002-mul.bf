 ++++[>++++[>+++<-]<-]   writing 48 / 0x30 / '0' in cell number (2)
    ,>,>                    reading 2 numbers in cell(0) and cell(1)
    [<-<->>-]               subtracting cell(0) and cell(1) by 48 / 0x30 / '0'
    <<                      go to cell(0)
    [                       mulitplication loop
        >                   go to cell(1)
        [>+>+<<-]           move cell(1) to cell(2) , cell(3)
        >>                  go to cell(3)
        [<<+>>-]            move from cell(3) back to cell(1)
        <<<-                decrement cell(0)
    ]
    >[-]<                   set cell(1) to 0 . it can be used as counter (we are in cell 0 )
    ++++[>++++[>+++<-]<-]   adding 48 / 0x30 / '0' to cell(2) and it has the result
    >>.                     print result (go to cell 2 and print)
