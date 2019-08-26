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
		cout << "����ʧ��" << endl;
	imshow("��ˮ��Ҷ", photo);//��ʾԭʼͼ��

	vector<Mat>m;
	split(photo, m); //��ȡͨ����Ϣ�����ǵ�δ������ͨ������Ϊ0ʱ��ʾΪ�Ҷ�ͼ������ͨ����Ϣ��ͬ
	vector<Mat>Rchannels, Gchannels, Bchannels;
	//��ȡͨ����Ϣ����orig��ͨ�����ݸ��Ƶ�channals
	split(photo, Rchannels);
	split(photo, Gchannels);
	split(photo, Bchannels);
	//������ͨ����Ϣ����Ϊ0
	Rchannels[1] = 0;
	Rchannels[2] = 0;
	Gchannels[0] = 0;
	Gchannels[2] = 0;
	Bchannels[0] = 0;
	Bchannels[1] = 0;
	//�ϲ�ͨ����ϢRGB
	merge(Rchannels, m[0]);
	merge(Gchannels, m[1]);
	merge(Bchannels, m[2]);
	//��ʾ��ͨ����ϢRGB
	imshow("Blue", m[0]);
	imshow("Green", m[1]);
	imshow("Red", m[2]);

	//RGBתHSV
	Mat HSVphoto;
	cvtColor(photo, HSVphoto, COLOR_BGR2HSV);
	imshow("HSV", HSVphoto);

	//RGBת�Ҷ�ͼ
	Mat Grayphoto;
	cvtColor(photo, Grayphoto, COLOR_BGR2GRAY);
	imshow("Gray", Grayphoto);

	waitKey(0);
	return 0;

}