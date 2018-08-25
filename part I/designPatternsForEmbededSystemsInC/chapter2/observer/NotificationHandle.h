#ifndef _NOTIFICATION_HANDLE_H_
#define _NOTIFICATION_HANDLE_H_

#include <stdio.h>
#include "ECGPkg.h"

typedef struct NotificationHandle NotificationHandle;
typedef void * UpdateFuncPtr;

struct NotificationHandle{
    UpdateFuncPtr updateAddr;
    struct NotificationHandle* itsNotificationHandle;
};

/* constructors and destructors: */
void NotificationHandle_Init(NotificationHandle* const me);

void NotificationHandle_Cleanup(NotificationHandle* const me);

struct NotificationHandle* NotificationHandle_getItsNotificationHandle(const NotificationHandle* const me);

void NotificationHandle_setItsNotificationHandle(NotificationHandle* const me, struct NotificationHandle* p_NotificationHandle);

NotificationHandle* NotificationHandle_Create(void);

void NotificationHandle_Destroy(NotificationHandle* const me);

#endif