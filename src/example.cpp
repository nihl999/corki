//#include <stdlib.h>
#include "windows.h"
#include "corki/corki.h"


// TODO(nihilo): Implement HTTP Socket myself.

int main( int, char *[] )
{
    CORKIContext hlcu;
    CORKI_Init(&hlcu);
    CORKI_ShowUX(&hlcu);
    //Riot disaproves?
    CORKI_CreateQueue(&hlcu, CORKIDraft);
    /*CORKI_Put(&hlcu, "/lol-lobby/v2/lobby/members/localMember/position-preferences",
              "{\"firstPreference\": \"BOTTOM\", \"secondPreference\": \"JUNGLE\"}");*/
    CORKI_ChangeLane(&hlcu, CORKIMiddle, CORKIBottom);
    
}

