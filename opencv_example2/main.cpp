#include "opencv2/opencv.hpp"

int main() {

    cv::VideoCapture inputVideo(0);

    cv::aruco::DetectorParameters detectorParams = cv::aruco::DetectorParameters();
    cv::aruco::Dictionary dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);
    cv::aruco::ArucoDetector detector(dictionary, detectorParams);

    while (1) {
        cv::Mat image, imageCopy;

        inputVideo >> image;

        std::vector<int> ids;
        std::vector<std::vector<cv::Point2f>> corners;
        detector.detectMarkers(image, corners, ids);
        // if at least one marker detected
        if (ids.size() > 0)
            cv::aruco::drawDetectedMarkers(image, corners, ids);
        cv::imshow("out111", image);

        char key = (char) cv::waitKey(10);
        if (key == 27)
            break;
    }
}