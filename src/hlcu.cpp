#include "hlcu.h"
#include "utils.h"

// TODO(nihilo): Stop using string.h, make own strtok, atoi, strcat 
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int CORKI_Init(CORKIContext* Context)
{
    int res;
    res = PopulateContext(Context);
    if(res > 0)
    {
        curl_global_init(CURL_GLOBAL_ALL);
        Context->request_context = curl_easy_init();
        if(Context->request_context)
        {
            curl_easy_setopt(Context->request_context, 
                             CURLOPT_USERNAME, 
                             "riot");
            curl_easy_setopt(Context->request_context, 
                             CURLOPT_PASSWORD, 
                             Context->auth_token);
            curl_easy_setopt(Context->request_context, CURLOPT_SSL_VERIFYHOST, 0L);
            curl_easy_setopt(Context->request_context, CURLOPT_SSL_VERIFYPEER, 0L);
            return 1;
        }
    }
    return 0;
}


CORKI_internal int PopulateContext(CORKIContext* Context)
{
    char dir[1024];
    if(Win32GetProcessDir("LeagueClient.exe", dir))
    {
        char lockfile_contents[128];
        
        char* tokens[4];
        char* temp_token;
        strcat(dir, "\\lockfile");
        FILE *lockfile = fopen(dir, "r");
        if(lockfile != NULL)
        {
            if(fgets(lockfile_contents, sizeof(lockfile_contents), lockfile) != NULL)
            {
                temp_token = strtok(lockfile_contents, ":");
                tokens[0] = temp_token;
                for(int token_pos = 1; token_pos < 4; ++token_pos)
                {
                    tokens[token_pos] = strtok(NULL, ":");
                }
                int port =  atoi(tokens[2]);
                sprintf(Context->lcu_base_url, "https://127.0.0.1:%d", port);
                strcpy(Context->auth_token, tokens[3]);
                return 1;
            }
        }
    }
    return 0;
}

int CORKI_CustomRequest(CORKIContext* Context, CORKIReq RequestType, char* Endpoint)
{
    int res;
    char URL[512];
    if(Context->request_context)
    {
        strcpy(URL, Context->lcu_base_url);
        strcat(URL, Endpoint);
        switch(RequestType)
        {
            case CORKIGet:
            {
                
            }break;
            case CORKIPost:
            {
                curl_easy_setopt(Context->request_context, 
                                 CURLOPT_URL, 
                                 URL);
                curl_easy_setopt(Context->request_context, CURLOPT_POST, 1L);
                curl_easy_setopt(Context->request_context, CURLOPT_POSTFIELDSIZE, 0L);
                curl_easy_setopt(Context->request_context, CURLOPT_VERBOSE, 1L);
                res = curl_easy_perform(Context->request_context);
                if(res == CURLE_OK)
                {
                    curl_easy_setopt(Context->request_context, CURLOPT_URL, Context->lcu_base_url);
                    return 1;
                }
                return 0;
            }break;
            case CORKIPut:
            {
                
            }break;
            case CORKIDelete:
            {
                
            }break;
            default:
            {
                // TODO(nihilo): Input error handling.
            }
        }
        
    }
    return 0;
}

int CORKI_Get(char* Endpoint)
{
    // TODO(nihilo): Implement CustomRequest GET method
    return 0;
}
int CORKI_Post(CORKIContext* Context, char* Endpoint)
{
    
    
    return 0;
}

int CORKI_Cleanup(CORKIContext* Context)
{
    curl_easy_cleanup(Context->request_context);
    curl_global_cleanup();
    return 1;
}


