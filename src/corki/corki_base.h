/* date = September 7th 2021 1:08 am */
#ifndef CORKI_BASE_H
#define CORKI_BASE_H

int CORKI_CustomRequest(CORKIContext* Context, CORKIReq RequestType, char* Endpoint,
                        char* Data)
{
    int res;
    char URL[512];
    if(Context->request_context)
    {
        CopyString(URL, Context->lcu_base_url);
        ConcatenateString(URL, Endpoint);
        switch(RequestType)
        {
            case CORKIGet:
            {
                curl_easy_setopt(Context->request_context, 
                                 CURLOPT_URL, 
                                 URL);
                curl_easy_setopt(Context->request_context, CURLOPT_HTTPGET, 1L);
                //debug option v
                curl_easy_setopt(Context->request_context, CURLOPT_VERBOSE, 1L);
                res = curl_easy_perform(Context->request_context);
                if(res == CURLE_OK)
                {
                    curl_easy_setopt(Context->request_context, CURLOPT_URL, Context->lcu_base_url);
                    return 0;
                }
                return -1;
            }break;
            case CORKIPost:
            {
                curl_easy_setopt(Context->request_context, 
                                 CURLOPT_URL, 
                                 URL);
                curl_easy_setopt(Context->request_context, CURLOPT_POST, 1L);
                curl_easy_setopt(Context->request_context, CURLOPT_POSTFIELDSIZE, (long)strlen(Data));
                curl_easy_setopt(Context->request_context, CURLOPT_POSTFIELDS, Data);
                //debug option v
                curl_easy_setopt(Context->request_context, CURLOPT_VERBOSE, 1L);
                res = curl_easy_perform(Context->request_context);
                if(res == CURLE_OK)
                {
                    curl_easy_setopt(Context->request_context, CURLOPT_URL, Context->lcu_base_url);
                    return 0;
                }
                return -1;
            }break;
            case CORKIPut:
            {
                curl_easy_setopt(Context->request_context, 
                                 CURLOPT_URL, 
                                 URL);
                curl_easy_setopt(Context->request_context, CURLOPT_POSTFIELDSIZE, (long)strlen(Data));
                curl_easy_setopt(Context->request_context, CURLOPT_POSTFIELDS, Data);
                curl_easy_setopt(Context->request_context, CURLOPT_CUSTOMREQUEST, "PUT");
                //debug option v
                curl_easy_setopt(Context->request_context, CURLOPT_VERBOSE, 1L);
                res = curl_easy_perform(Context->request_context);
                if(res == CURLE_OK)
                {
                    curl_easy_setopt(Context->request_context, CURLOPT_URL, Context->lcu_base_url);
                    return 0;
                }
                return -1;
            }break;
            case CORKIDelete:
            {
                curl_easy_setopt(Context->request_context, 
                                 CURLOPT_URL, 
                                 URL);
                curl_easy_setopt(Context->request_context, CURLOPT_CUSTOMREQUEST, "DELETE");
                curl_easy_setopt(Context->request_context, CURLOPT_POSTFIELDSIZE, (long)strlen(Data));
                curl_easy_setopt(Context->request_context, CURLOPT_POSTFIELDS, Data);
                //debug option v
                curl_easy_setopt(Context->request_context, CURLOPT_VERBOSE, 1L);
                res = curl_easy_perform(Context->request_context);
                if(res == CURLE_OK)
                {
                    curl_easy_setopt(Context->request_context, CURLOPT_URL, Context->lcu_base_url);
                    return 0;
                }
                return -1;
                
            }break;
            default:
            {
                puts("CORKI: Invalid HTTP Method.");
                return -1;
            }
        }
    }
    return -1;
}
int CORKI_Get(CORKIContext* Context, char* Endpoint)
{
    return CORKI_CustomRequest(Context, CORKIGet, Endpoint);
}
int CORKI_Post(CORKIContext* Context, char* Endpoint)
{
    return CORKI_CustomRequest(Context, CORKIPost, Endpoint);
}
int CORKI_Put(CORKIContext* Context, char* Endpoint, char* Data)
{
    return CORKI_CustomRequest(Context, CORKIPut, Endpoint, Data);
}
int CORKI_Delete(CORKIContext* Context, char* Endpoint)
{
    return CORKI_CustomRequest(Context, CORKIDelete, Endpoint);
}

#endif //CORKI_BASE_H
