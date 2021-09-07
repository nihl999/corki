/* date = September 7th 2021 1:14 am */
#ifndef CORKI_ABSTRACTIONS_H
#define CORKI_ABSTRACTIONS_H

int CORKI_CreateQueue(CORKIContext* Context, CORKIQueue QueueType)
{
    char body[64];
    sprintf(body,"{ \"queueId\": %d}", QueueType);
    return CORKI_CustomRequest(Context, CORKIPost, "/lol-lobby/v2/lobby", body);
}
int CORKI_ShowUX(CORKIContext* Context)
{
    return CORKI_Post(Context, "/riotclient/ux-show");
}
int CORKI_MinimizeUX(CORKIContext* Context)
{
    return CORKI_Post(Context, "/riotclient/ux-minimize");
}
int CORKI_ChangeLane(CORKIContext* Context, CORKILane Lane1, CORKILane Lane2)
{
    char body[128];
    sprintf(body,"{ \"firstPreference\": \"%s\", \"secondPreference\": \"%s\" }", Lane1, Lane2); 
    return CORKI_Put(Context, "/lol-lobby/v2/lobby/members/localMember/position-preferences",
                     body);
}
int CORKI_StartMatchSearch(CORKIContext* Context)
{
    return CORKI_Post(Context, "/lol-lobby/v2/lobby/matchmaking/search");;
}
int CORKI_StopMatchSearch(CORKIContext* Context)
{
    return CORKI_Delete(Context, "/lol-lobby/v2/lobby/matchmaking/search");;
}

#endif //CORKI_ABSTRACTIONS_H
