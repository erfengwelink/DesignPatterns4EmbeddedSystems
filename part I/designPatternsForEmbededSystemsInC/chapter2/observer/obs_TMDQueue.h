#ifndef _OBS_TMDQUEUE_H_
#define _OBS_TMDQUEUE_H_

#include <stdio.h>
#include "ECGPkg.h"
#include "TimeMarkedData.h"


struct NotificationHandle;

typedef struct TMDQueue TMDQueue;//TMD -- time marked data

/**
 * this queue is meant to operate as a "leaky" queue.
 * in this queue,data are never removed per se,
 * but are instead overwritten when the buffer pointer wraps around.
 * this allows for many clients to read the same data from the queue.
 */
 
struct TMDQueue
{
    int head;
    int nSubscribers;
    int size;
    struct TimeMarkedData buffer[100];
    struct NotificationHandle* itsNotificationHandle;
};
/* Constructors and destructors:*/
void TMDQueue_Init(TMDQueue *const me);
void TMDQueue_Cleanup(TMDQueue *const me);

/* Operations */
int TMDQueue_getNextIndex(TMDQueue *const me, int index);
void TMDQueue_insert(TMDQueue *const me, const struct TimeMarkedData tmd);
int TMDQueue_isEmpty(TMDQueue *const me);

void TMDQueue_notify(TMDQueue *const me, const struct TimeMarkedData tmd);
struct TimeMarkedData TMDQueue_remove(TMDQueue *const me, int index);
/* the NotificationHandle is managed as a linked list,with insertions coming at the end. */
void TMDQueue_subscribe(TMDQueue *const me, const UpdateFuncPtr updateFuncAddr);

int TMDQueue_unsubscribe(TMDQueue *const me, const UpdateFuncPtr updateFuncAddr);

int TMDQueue_getBuffer(const TMDQueue *const me);

struct NotificationHandle* TMDQueue_getItsNotificationHandle(const TMDQueue *const me);
void TMDQueue_setItsNotificationHandle(const TMDQueue *const me, struct NotificationHandle* p_NotificationHandle);


TMDQueue *TMDQueue_Create(void);
void TMDQueue_Destroy(TMDQueue *const me);


// a pattern language
// design patterns:elements of reusable object-oriented software:erich gamma
#endif
