#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/core.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

int main()
{
	Mat photo;
	photo = imread("background.jpg");
	if (photo.empty())
		cout << "读入失败" << endl;
	imshow("宫水三叶", photo);//显示原始图像

	vector<Mat>m;
	split(photo, m); //提取通道信息，但是当未把其他通道设置为0时显示为灰度图，但各通道信息不同
	vector<Mat>Rchannels, Gchannels, Bchannels;
	//提取通道信息，把orig的通道数据复制到channals
	split(photo, Rchannels);
	split(photo, Gchannels);
	split(photo, Bchannels);
	//将其他通道信息设置为0
	Rchannels[1] = 0;
	Rchannels[2] = 0;
	Gchannels[0] = 0;
	Gchannels[2] = 0;
	Bchannels[0] = 0;
	Bchannels[1] = 0;
	//合并通道信息RGB
	merge(Rchannels, m[0]);
	merge(Gchannels, m[1]);
	merge(Bchannels, m[2]);
	//显示各通道信息RGB
	imshow("Blue", m[0]);
	imshow("Green", m[1]);
	imshow("Red", m[2]);

	//RGB转HSV
	Mat HSVphoto;
	cvtColor(photo, HSVphoto, COLOR_BGR2HSV);
	imshow("HSV", HSVphoto);

	//RGB转灰度图
	Mat Grayphoto;
	cvtColor(photo, Grayphoto, COLOR_BGR2GRAY);
	imshow("Gray", Grayphoto);

	waitKey(0);
	return 0;

}