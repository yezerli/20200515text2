#include<iostream>
#include<opencv.hpp>

using namespace cv;
using namespace std;


int equalizeMain()
{
	cv::Mat srcMat = imread("../testImages\\face.jpg", 0);
	cv::Mat dstMat;

	if (srcMat.empty()) {
		cout << "fail to read pic!" << endl;
		return -1;
	}

	//0.����ͼ�������� 8λ��ͨ��
	//1.���ͼ��������ͬ���ߴ�ͬ������
	if (srcMat.type() == CV_8UC1) {
		equalizeHist(srcMat, dstMat);
	}
	else if (srcMat.type() == CV_8UC3) {
		Mat channel[3];
		Mat out[3];
		split(srcMat, channel);

		for (int i = 0; i < 3; i++) {
			equalizeHist(channel[i], out[i]);
		}

		merge(out, 3, dstMat);

	}


	//����ֱ��ͼ
	float srcHist[256];
	float dstHist[256];

	cv::Mat srcHistMat;
	cv::Mat dstHistMat;

	imshow("srcMat", srcMat);
	imshow("dstMat", dstMat);
	/*imshow("srcHistMat", srcHistMat);
	imshow("dstHistMat", dstHistMat);*/
	waitKey(0);

	destroyAllWindows();

	return 0;

}
