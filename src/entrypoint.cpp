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
    CORKI_Get(&hlcu, "/riotclient/app-port");
    CORKI_Post(&hlcu, "/riotclient/ux-show");
    CORKI_Post(&hlcu, "/riotclient/ux-minimize");
    //Riot disaproves?
    CORKI_CustomRequest(&hlcu, CORKIPost, "/lol-lobby/v2/lobby/", 
                        "{"
                        "\"queueId\": 430"
                        "}"
                        );
}

