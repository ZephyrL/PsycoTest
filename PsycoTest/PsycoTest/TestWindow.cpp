#include "TestWindow.h"

void TestWindow::startTest() {
	string tWindowName = "Test: " + testerName;
	namedWindow(tWindowName, WINDOW_AUTOSIZE);

	Mat background(windowHeight, windowWidth, CV_8UC3, Scalar(92, 168, 180));
	vector<Rect> layout;
	calLayout(layout);

	getPics();
	assert(layout.size() == numPics || layout.size() == numPics + 1);
	for (int i = 0; i < numPics; i++) {
		Mat temp;
		pics[i].convertTo(temp, CV_8UC3);
		Mat resized;
		resize(temp, resized, Size(layout[i].width, layout[i].height));

		Rect outlineRect = 
			Rect(layout[i].x - 2, layout[i].y - 2, 
				layout[i].width + 4, layout[i].height + 4);
		Mat outline = Mat(outlineRect.height, outlineRect.width, CV_8UC3, Scalar(192, 168, 104));

		outline.copyTo(background(outlineRect));
		resized.copyTo(background(layout[i]));
	}
	imshow(tWindowName, background);
	int key = getInput();
}

void TestWindow::getPics() {

}

void TestWindow::calLayout(vector<Rect>& layout) {

}

int TestWindow::getInput() {
	int key = 0;
	while (key == 0) {
		key = waitKey(0);
		if (key == '1' || key == '2'
			|| key == '3' || key == '4')
			break;
		else
			key = 0;
	}
}