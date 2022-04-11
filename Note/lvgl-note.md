## LVGL理论基础与基本函数

### 一、 lvgl 三种屏幕(Create)

```c
lvgl_scr_arc(void);   // 活动屏幕
    
lvgl_layer_top(void); // 顶层
    
lvgl_layer_sys(void); // 系统层
```

一般都是创建活动屏幕作为基类。

### 二、 基础对象的大小(Size)

调整基础对象的大小：

```c
lv_obj_set_width(obj, new_width);	//

lv_obj_set_hight(obj, new_hight);		// 

lv_obj_set_size(obj, new_width, new_hight); 	//
```

获取基础对象的大小：

```c
lv_obj_get_width(obj, new_width);	//

lv_obj_get_hight(obj, new_hight);		//

lv_obj_get_size(obj, new_width, new_hight);	//
```

例子：

```c
lv_obj_t *obj = lv_obj_create(lv_scr_act());	//

lv_obj_set_width(obj, new_width); 
lv_obj_set_hight(obj, new_width);
```

### 三、 设置当前部件的位置(Position)

设置轴坐标位置：

```c
lv_obj_set_X(obj, 200);		// 设置x轴坐标位置
lv_obj_set_y(obj, 200);		// 设置y轴坐标位置
lv_obj_set_pos(obj, 200, 200);	// 同时设置坐标位置
```

设置位置对齐方式：

```c
lv_obj_align(obj, LV_ALIGN...);

lv_obj_align_to(x_obj, obj, LV_ALIGN..., 0, 0);
```

获取部件位置：

```c
lv_obj_get_X(obj);		// 获取x轴坐标位置
lv_obj_get_y(obj);		// 获取y轴坐标位置
```

### 四、 盒子模型(Box)





### 五、 盒子的样式(Style)



## LVGL复杂应用
### 圆弧的应用(arc)
相关api函数：
```c
void lv_style_set_arc_width(lv_style_t * style, lv_coord_t value);      //设置圆弧样式的宽度
void lv_style_set_arc_rounded(lv_style_t * style, lv_coord_t value);    //设置圆弧样式的末端圆形
void lv_style_set_arc_color(lv_style_t * style, lv_color_t value);      //设置圆弧样式的颜色
void lv_style_set_arc_color_filtered(lv_style_t * style, lv_color_t value);	//设置弧样式的颜色滤色
void lv_style_set_arc_opa(lv_style_t * style, lv_opa_t value);      	//设置圆弧样式的透明度
void lv_style_set_arc_img_src(lv_style_t * style, const void * value);	//设置圆弧图片资源
void lv_arc_set_angles(lv_obj_t * arc, uint16_t start, uint16_t end);	//设置圆弧的角度范围

```