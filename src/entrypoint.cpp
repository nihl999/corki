#include <stdlib.h>
#include "hlcu.h"


// TODO(nihilo): Implement HTTP Socket myself.
// TODO(nihilo): STOP USING LEAGUECLIENTUX AT ALL, KILL THIS PROCESS AND CALL LEAGUECLIENT MYSELF
// TODO(nihilo): STOP NEEDING TO OPEN RIOT CLIENT AT ALL, CREATING THE LOG-IN MYSELF FOR RIOT SERVERS, GETTING THE LEAGUECLIENT
//    PARAMETERS.

int main( int, char *[] )
{
    CORKIContext hlcu;
    CORKI_Init(&hlcu);
    CORKI_Post(&hlcu, "/riotclient/ux-show");
}

