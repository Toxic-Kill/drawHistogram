#include <iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	cv::Mat src_Mat = cv::imread("D:\\Files\\2.jpg");//读取文件
	float histgram[256] = { 0 };//建立容量为256的数组，并初始化为0
	int height = src_Mat.rows;
	int width = src_Mat.cols;
	for (int i = 0; i < height; i++)//遍历像素
	{
		for (int j = 0; j < width; j++)
		{
			int greyValue = (src_Mat.at<Vec3b>(i, j)[0] * 0.1140 + src_Mat.at<Vec3b>(i, j)[1] * 0.5870 + src_Mat.at<Vec3b>(i, j)[2] * 0.2989);//计算灰度值
			histgram[greyValue]++;//写入数组中计数
		}
	}
	for (int m = 0; m < 256; m++)
	{
		histgram[m] = histgram[m] / 256;//计算各灰度出现概率
	}
}