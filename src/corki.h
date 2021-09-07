/* date = August 31st 2021 7:10 pm */
#ifndef CORKI_DEF
#define CORKI_DEF
#define CURL_STATICLIB
#include <curl/curl.h>
#include "corki_constants.h"

#define CORKI_internal static;

struct CORKIContext
{
    CURL* request_context;
    char auth_token[128];
    char lcu_base_url[128];
};

// Populate context with LCU Url, Basic password and a initiated Curl context
CORKI_internal int PopulateContext(CORKIContext* Context);
CORKI_internal int GetFeaturedGame(CORKIContext* Context); // Need Implementation
//Init HTTP and WebSockets
int CORKI_Init(CORKIContext* Context);
//Make a request in custom endpoint
int CORKI_CustomRequest(CORKIContext* Context, CORKIReq RequestType, char* Endpoint,
                        char* Data = "");

//GET with no body request
int CORKI_Get(CORKIContext* Context, char* Endpoint);
//POST with no body request
int CORKI_Post(CORKIContext* Context, char* Endpoint);
//DELETE with no body request
int CORKI_Delete(CORKIContext* Context, char* Endpoint);

//PUT with body request
int CORKI_Put(CORKIContext* Context, char* Endpoint, char* Data);

//Easy to use requests
int CORKI_ChangeLane(CORKIContext* Context, CORKILane Lane);
int CORKI_CreateLobby(CORKIContext* Context, CORKILane Lane);
int CORKI_StartMatchSearch(CORKIContext* Context, CORKILane Lane);
int CORKI_StopMatchSearch(CORKIContext* Context, CORKILane Lane);




//Cleanup Curl and Websockets
int CORKI_Cleanup(CORKIContext* Context);

#endif //HLEAGUECLIENTUP_H