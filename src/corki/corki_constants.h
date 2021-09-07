/* date = September 7th 2021 0:15 am */
#ifndef CORKI_CONSTANTS_H
#define CORKI_CONSTANTS_H


//Request Types 
#define CORKIGet 0
#define CORKIPost 1
#define CORKIPut 2
#define CORKIDelete 3
typedef int CORKIReq;

//Lane Types
#define CORKITop "TOP"
#define CORKIMiddle "MIDDLE"
#define CORKIJungle "JUNGLE"
#define CORKIBottom "BOTTOM"
#define CORKISupport "UTILITY"
typedef char* CORKILane;

//Queue Types
#define CORKIAram 450
#define CORKIBlind 430
#define CORKIDraft 400
#define CORKISoloRanked 420
#define CORKIFlexRanked 440
//#define CORKIFeatured "UTILITY" NOT YET
typedef int CORKIQueue;


#endif //CORKI_CONSTANTS_H
