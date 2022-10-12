# std_image_encoder_decoder demo

## How to build

```shell
mkdir build
cmake -DENABLE_OPENCV=ON ..
make -j4
```

- 其中 -DENABLE_OPENCV=ON 表示启用OpenCV库，等于OFF表示关闭OpenCV库。

请调整一下main.cpp的图片的路径，然后会输出基于stb做encoder，decoder以及resize的目标图片（尺度为原始图片的1/2）

## How to run

```
cd build
./image stb/opencv
```

会输出运行10个loop的耗时（s）

## Performance

image_read+image_resize+image_write pipline.

|库|循环迭代次数|耗时|
| -- | -- | -- |
| opencv | 10 | 0.338s |
| stb    | 10 | 2.2776s|

- OpenCV 版本：4.6.0

## Result

![origin.jpg](image/zidane.jpg)

->

![resize.jpg](image/resize_out.jpg)
