/* date = September 7th 2021 1:17 am */
#ifndef CORKI_INTERNALS_H
#define CORKI_INTERNALS_H

CORKI_internal int PopulateContext(CORKIContext* Context)
{
    char dir[1024];
    if(Win32GetProcessDir("LeagueClient.exe", dir))
    {
        char lockfile_contents[128];
        
        char* tokens[4];
        char* temp_token;
        ConcatenateString(dir, "\\lockfile");
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
                CopyString(Context->auth_token, tokens[3]);
                return 0;
            }
        }
    }
    return -1;
}
CORKI_internal int GetFeaturedGame(CORKIContext* Context)
{
    // TODO(nihilo): Implement FTG queue option.
    return -1;
}

#endif //CORKI_INTERNALS_H
