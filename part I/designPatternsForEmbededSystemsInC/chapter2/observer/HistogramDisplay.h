#ifndef _HISTOGRAMDISPLAY_H_
#define _HISTOGRAMDISPLAY_H_

#include <stdio.h>
#include "ECGPkg.h"

struct TMDQueue;

/* class HistogramDisplay */
typedef struct HistogramDisplay HistogramDisplay;
struct HistogramDisplay {
    int index;
    struct TMDQueue* itsTMDQueue;
};

void HistogramDisplay_update(HistogramDisplay* const me, const struct TimeMarkedData tmd);
void HistogramDisplay_Init(HistogramDisplay* const me);
void HistogramDisplay_Cleanup(HistogramDisplay* const me);
void HistogramDisplay_updateHistogram(HistogramDisplay* const me);
struct TMDQueue *HistogramDisplay_getItsTMDQueue(const HistogramDisplay* const me);
void HistogramDisplay_getItsTMDQueue(HistogramDisplay* const me, struct TMDQueue *p_TMDQueue);
HistogramDisplay* HistogramDisplay_Create(void);
void HistogramDisplay_Destroy(HistogramDisplay* const me);



#endif