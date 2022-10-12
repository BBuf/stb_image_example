#include <cassert>
#define STB_IMAGE_IMPLEMENTATION
#include "include/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "include/stb_image_write.h"
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "include/stb_image_resize.h"
#include <iostream>
#include <time.h>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main(int argc,char *argv[]) {
	assert(argc == 2);
	clock_t st, en;
	st = clock();
	for(int i = 0; i < 10; i++){
		string inputPath = "/home/zhangxiaoyu/stb_image_example/image/zidane.jpg";
		if(string(argv[1]) == "stb"){
			int iw, ih, n;
		
			// 加载图片获取宽、高、颜色通道信息
			unsigned char *idata = stbi_load(inputPath.c_str(), &iw, &ih, &n, 0);

			std::cout << iw << ", " << ih << ", " << n << std::endl;
			int ow = iw / 2;
			int oh = ih / 2;
			auto *odata = (unsigned char *)malloc(ow * oh * n);

			// 改变图片尺寸
			stbir_resize(idata, iw, ih, 0, odata, ow, oh, 0, STBIR_TYPE_UINT8, n, STBIR_ALPHA_CHANNEL_NONE, 0,
				STBIR_EDGE_CLAMP, STBIR_EDGE_CLAMP,
				STBIR_FILTER_BOX, STBIR_FILTER_BOX,
				STBIR_COLORSPACE_SRGB, nullptr
				);

			string outputPath = "./resize_out.jpg";
			// 写入图片
			stbi_write_png(outputPath.c_str(), ow, oh, n, odata, 0);

			stbi_image_free(idata);
			stbi_image_free(odata);
		}
		else if(string(argv[1]) == "opencv"){
			cv::Mat img = cv::imread(inputPath);
			cv::Mat result;
			cv::resize(img, result, Size(img.cols/2, img.rows/2));
			string outputPath = "./resize_out.jpg";
			cv::imwrite(outputPath, result);
		}
		else{
			std::cout << "not support yet, exit successful!";
		}
	}
	en = clock();
	std::cout << "time = "<< double(en-st) / CLOCKS_PER_SEC << "s" <<endl;
	return 0;
}
