#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <iostream>
#include <Windows.h>

using namespace std;
using namespace cv;

int CALLBACK WinMain(
	_In_  HINSTANCE hInstance,
	_In_  HINSTANCE hPrevInstance,
	_In_  LPSTR lpCmdLine,
	_In_  int nCmdShow){
	Mat face[4];
	face[0] = imread("dog.jpg");
	face[1] = imread("cat.jpg");
	face[2] = imread("alpaca.jpg");
	face[3] = imread("crab.jpg");
	for(int i = 0; i<4; i++)
	if (face[i].empty()) {
		cout << "ERROR::empty" << endl; return -1;
	}
	char* window = "FaceTest";
	//namedWindow(window, CV_WINDOW_AUTOSIZE);
	cvNamedWindow(window, CV_WINDOW_AUTOSIZE);
	Mat background = Mat(600, 900, face[0].type(), Scalar(255, 255, 255));

	Mat outline = Mat(214, 154, face[0].type(), Scalar(104, 168, 192));
	outline.copyTo(background(Rect(198, 58, outline.cols, outline.rows)));
	outline.copyTo(background(Rect(548, 58, outline.cols, outline.rows)));
	outline.copyTo(background(Rect(196, 328, outline.cols, outline.rows)));
	outline.copyTo(background(Rect(548, 328, outline.cols, outline.rows)));

	int i = 0;
	while(true){
		Mat resizedFace;
		resize(face[i], resizedFace, Size(150, 210));
		resizedFace.copyTo(background(Rect(200, 60, resizedFace.cols, resizedFace.rows)));
		resizedFace.copyTo(background(Rect(550, 60, resizedFace.cols, resizedFace.rows)));
		resizedFace.copyTo(background(Rect(200, 330, resizedFace.cols, resizedFace.rows)));
		resizedFace.copyTo(background(Rect(550, 330, resizedFace.cols, resizedFace.rows)));

		//imshow(window, background);
		CvArr* temp = (CvArr*)(&IplImage(background));
		cvShowImage(window, temp);
		int key = 0;
		while (key == 0) {
			key = waitKey(0);
			if (key == '1' || key == '2' || key == '3' || key == '4') break;
			cout << "ERROR::input not in [1,2,3,4]" << endl;
			key = 0;
		}
		cout << (char)key << endl;
		i = (i + 1) % 4;
	}
}