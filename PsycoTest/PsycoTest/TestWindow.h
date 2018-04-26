#pragma once

#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>

using namespace cv;
using namespace std;

enum PICTYPE { SMALL, NORMAL, LARGE };
class TestWindow {
	string testerName;
	int numPics = 4;
	int windowWidth = 800;
	int windowHeight = 600;
	PICTYPE type = NORMAL;

	int currentCase = 0;
	vector<Mat> pics;

	void getPics();
	void calLayout(vector<Rect>&);
	int getInput();
	
public:
	TestWindow() { testerName = "default"; }
	TestWindow(string name) :testerName(name) {}
	int getNumPics() { return numPics; }
	int getWindowWidth() { return windowWidth; }
	int getWindowHeight() { return windowHeight; }
	PICTYPE getPicType() { return type; }
	void setNumPics(int num) { numPics = num; }
	void setWindowWidth(int width) { windowWidth = width; }
	void setWindowHeight(int height) { windowHeight = height; }
	void setPicType(PICTYPE t) { type = t; }

	void startTest();
};