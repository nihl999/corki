# Corki 
Today Corki is only a little LCU helper, but with the objective to become a library to help developers with ***performance and productivity.***
~~And be all handmade~~
## Dependencies
**LibCurl:** I recommend watching this to build and link it: https://www.youtube.com/watch?v=q_mXVZ6VJs4

## Installation
-   Clone the repository:  `git clone https://github.com/nihl999/corki.git`
-   Compile `corki.cpp` linking against `Normaliz.lib Ws2_32.lib wldap32.lib crypt32.lib advapi32.lib libcurl_a.lib Shlwapi.lib` - Unfortunately needed by libCurl

## Use
- Open League of Legends
- Import `corki.h` in a file.
- Create a `CORKIContext`
- Initiate the lib with `CORKI_Init(&Context);` passing the `CORKIContext*` as parameter
- If the return code is 0, the lib was initated succesfuly and can have their functions called.
- Basic test call is `CORKI_ShowUX(&Context)` passing the `CORKIContext*` as parameter.

## TODO
- Error handling.
- Make requests using Berkeley/Winsock2 instead of libCurl.
-  Create a good documentation.
- Create a Event Listener to gather LOL client changes.
- Abstract more useful endpoints.
