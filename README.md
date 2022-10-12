# std_image_encoder_decoder demo

## How to use

```shell
mkdir build
cmake ..
make -j4
```

请调整一下main.cpp的图片的路径，然后会输出基于stb做encoder，decoder以及resize的目标图片（尺度为原始图片的1/2）

## Performance

后续提供和opencv对比的性能测试结果

## Result

![origin.jpg](image/zidane.jpg)

->

![resize.jpg](image/resize_out.jpg)
