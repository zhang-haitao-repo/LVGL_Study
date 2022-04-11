
/**
 * @file main
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include <stdlib.h>
#include <unistd.h>

#include "lvgl/lvgl.h"
#include "lv_100ask_teach_demos/lv_100ask_teach_demos.h"
#include "lv_demos/src/lv_demo_widgets/lv_demo_widgets.h"
#include "lv_drivers/win32drv/win32drv.h"

#include <windows.h>


/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void hal_init(void);
static int tick_thread(void *data);

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/
void lv_demo()
{
    static lv_style_t style;
    lv_obj_t *obj = lv_obj_create(lv_scr_act());
    lv_group_t *g = lv_group_create();

    lv_group_add_obj(g, obj);

    lv_obj_t *arc = lv_arc_create(obj);
    lv_obj_set_size(obj, 220, 220);

    lv_style_init(&style);
    lv_style_set_arc_color(&style, lv_palette_main(LV_PALETTE_RED));
    lv_style_set_arc_width(&style, 4);

    lv_obj_set_size(arc, 190, 190);


    lv_obj_add_style(arc, &style, 0);

    lv_obj_center(obj);
    lv_obj_center(arc);

    lv_arc_set_angles(arc, 0, 10);


}

/*************************************************
 *  函数名称 :  lv_Arc_style 圆弧样式设置
 *  参    数 ： 无
 *  函数功能 ： 圆弧样式设置
 *************************************************/
void lv_Arc_style()
{
   static lv_style_t style;                     //创建样式
   lv_style_init(&style);                       //初始化样式
   lv_style_set_arc_color(&style,lv_palette_main(LV_PALETTE_RED)); //设置圆弧颜色
   lv_style_set_arc_width(&style,4);            //设置圆弧的宽度
   lv_obj_t * obj = lv_arc_create(lv_scr_act());//创建圆弧对象
   lv_obj_add_style(obj,&style,0);              //将样式添加到圆弧中
   lv_obj_center(obj);                          //圆弧样式加载在中央
}


/**********************
 *   GLOBAL FUNCTIONS
 **********************/

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR szCmdLine, int nCmdShow)
{
    /*Initialize LittlevGL*/
    lv_init();

    /*Initialize the HAL for LittlevGL*/
    lv_win32_init(hInstance, SW_SHOWNORMAL, 240, 240, NULL);

    /*Output prompt information to the console, you can also use printf() to print directly*/
    LV_LOG_USER("LVGL initialization completed!");
    //printf("www.100ask.net: Lvgl initialization complete!\n");


    /*Run the demo*/
    // lv_100ask_demo_course_2_1_1();
    // lv_demo_widgets();


    lv_example_img_4();

    while(!lv_win32_quit_signal) {
        /* Periodically call the lv_task handler.
         * It could be done in a timer interrupt or an OS task too.*/
        lv_task_handler();
        usleep(10000);       /*Just to let the system breath*/
    }
    return 0;
}
