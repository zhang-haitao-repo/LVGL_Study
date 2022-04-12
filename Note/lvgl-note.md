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

#### 样式的创建和应用

```c
static lv_style_t * style_obj;

lv_style_set_bg_color(&style_obj, lv_color_hex(0x000000));	// 设置背景色
lv_style_set_bg_opa(&style_obj, LV_OPA_50);	//设置背景透明度
lv_style_set_...	// 设置其他属性

lv_style_init(&style_obj);


lv_obj_add_style(obj, &style_obj, 0);	// 添加样式到指定对象
lv_obj_add_style(obj,,&style_obj, LV_STATE_PRESSED);	//在对象被按下时应用样式
```

获取样式属性：lv_obj_get_style_<property_name>(obj, <part>)	

```c
lv_color_t color = lv_obj_get_style_bg_color(obj,LV_PART_MAIN);	// 获取样式的背景颜色属性

lv_obj_remove_style_all(obj);	// 删除对象所有样式
```

> 背景部分的属性：
>
> 背景：（Background）, 边界(Border), 轮廓(Outline), 阴影(Shadow), 填充(Padding), 宽度和高度变换， X和Y变换

#### 样式的状态和部分

状态State：(对象可处于以下状态组合)

> LV_STATE_DEFAULT(0x0000) 正常，释放状态
>
> LV_STATE_CHECKED(0x0001) 切换或检查状态
>
> LV_STATE_FOCUSED(0x0002) 通过键盘或编码器聚焦或通过触摸板/鼠标点击
>
> LA_STATE_FOCUS_KEY(0x0004) 通过键盘或编码器聚焦，但不通过触摸板/鼠标点击
>
> LV_STATE_EDITED(0x0008) 由编码器编辑
>
> LV_STATE_PRESSED(0x0020) 被按下

部分Part：(对象可以有多个部分，他们可以有自己的样式)

> 例如：一个滑杆（Slider）包含三部分
>
> 背景、按钮、旋钮。
>
> 这意味着滑杆的三部分均可以有自己的样式。

#### 过度特效

默认情况下，当一个对象改变状态时，新的状态会立即设置。但是，通过转换，可以在状态更改时播放动画。

例如：按下按钮时，其背景颜色可以在300毫秒内动画显示为按下的颜色。

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