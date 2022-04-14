#include "lvgl.h"

void vApplicationIdleHook(void);

void vApplicationIdleHook()
{
	lv_tick_inc(1);
}
