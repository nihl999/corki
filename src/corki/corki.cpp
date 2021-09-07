//NOTE(nihilo): Base Corki headers.
#include "corki.h"
#include "corki_utils.h"
#include "corki_internals.h"

int CORKI_Init(CORKIContext* Context)
{
    int res;
    res = PopulateContext(Context);
    if(res >= 0)
    {
        curl_global_init(CURL_GLOBAL_ALL);
        Context->request_context = curl_easy_init();
        if(Context->request_context)
        {
            struct curl_slist *headers = NULL;
            headers = curl_slist_append(headers, "Accept: */*");
            headers = curl_slist_append(headers, "Content-Type: application/json");
            curl_easy_setopt(Context->request_context, CURLOPT_HTTPHEADER, headers);
            curl_easy_setopt(Context->request_context, 
                             CURLOPT_USERNAME, 
                             "riot");
            curl_easy_setopt(Context->request_context, 
                             CURLOPT_PASSWORD, 
                             Context->auth_token);
            curl_easy_setopt(Context->request_context, CURLOPT_SSL_VERIFYHOST, 0L);
            curl_easy_setopt(Context->request_context, CURLOPT_SSL_VERIFYPEER, 0L);
            return 0;
        }
    }
    return -1;
}

int CORKI_Cleanup(CORKIContext* Context)
{
    curl_easy_cleanup(Context->request_context);
    curl_global_cleanup();
    return 0;
}

#include "corki_base.h"
#include "corki_abstractions.h"



