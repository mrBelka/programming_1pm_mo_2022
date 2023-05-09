#include <opencv2\opencv.hpp>
using namespace cv;
using namespace std;

int main() {
	cv::Mat image;
	
	namedWindow("Display window");

	VideoCapture cap(0);

	if (!cap.isOpened()) {

		cout << "cannot open camera";
		return 0;
	}

	while (true) {
		cap >> image;
		std::cout << image.rows << " " << image.cols << std::endl;
		std::cout << image.step << std::endl;
		Vec3b& bgrPixel = image.at<Vec3b>(240, 320);
		std::cout << (int)bgrPixel[0] << " " << (int)bgrPixel[1] << " " << (int)bgrPixel[2] << std::endl;
		
		for(int i=0;i<image.rows;i++)
			for (int j = 0; j < image.cols; j++)
			{
				Vec3b& bgrPixel = image.at<Vec3b>(i, j);
				if (bgrPixel[0] > 130 && bgrPixel[1] < 90 && bgrPixel[2] < 90)
				{
					bgrPixel[0] = 255;
					bgrPixel[1] = 255;
					bgrPixel[2] = 255;
				}
			}
		
		imshow("Display window", image);
		if (cv::waitKey(10) >= 0)
			break;
	}

	return 0;

}