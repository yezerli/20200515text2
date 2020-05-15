#include<iostream>
#include<opencv.hpp>

using namespace cv;
using namespace std;


int main()
{
	cv::Mat srcMat = imread("E:\\Git\\etest.jpg", 0);
	cv::Mat dstMat;

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
	float srcHist[256];
	float dstHist[256];
	cv::Mat srcHistMat;
	cv::Mat dstHistMat;

	imshow("srcMat", srcMat);
	imshow("dstMat", dstMat);
	waitKey(0);

	destroyAllWindows();

	return 0;

}
