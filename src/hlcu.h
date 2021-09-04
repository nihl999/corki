/* date = August 31st 2021 7:10 pm */
#ifndef CORKI_DEF
#define CORKI_DEF
#define CURL_STATICLIB
#include <curl/curl.h>

//Request Types 
#define CORKIGet 0
#define CORKIPost 1
#define CORKIPut 2
#define CORKIDelete 3
typedef int CORKIReq;

#define CORKI_internal static;

struct CORKIContext
{
    CURL* request_context;
    char auth_token[128];
    char lcu_base_url[128];
};
// Populate context with LCU Url, Basic password and a initiated Curl context
CORKI_internal int PopulateContext(CORKIContext* Context);
//Init HTTP and WebSockets
int CORKI_Init(CORKIContext* Context);
//Make a request in custom endpoint
int CORKI_CustomRequest(CORKIContext* Context, CORKIReq RequestType, char* Endpoint); // Request body needed CORKI_CustomRequest(CORKIReq RequestType, char* Endpoint, ** body);
//GET with no body request
int CORKI_Get(CORKIContext* Context, char* Endpoint);
//POST with no body request
int CORKI_Post(CORKIContext* Context, char* Endpoint);
//Cleanup Curl and Websockets
int CORKI_Cleanup(CORKIContext* Context);

#endif //HLEAGUECLIENTUP_H
