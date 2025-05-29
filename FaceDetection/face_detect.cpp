#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <iostream>
#include "tinyfiledialogs.h"

int main() {
    // Load the Caffe model
    const std::string modelFile = "res10_300x300_ssd_iter_140000.caffemodel";
    const std::string configFile = "deploy.prototxt";

    cv::dnn::Net net = cv::dnn::readNetFromCaffe(configFile, modelFile);
    if (net.empty()) {
        std::cerr << "Failed to load Caffe model.\n";
        return -1;
    }

    // Open file dialog
    const char* filter_patterns[2] = { "*.jpg", "*.png" };
    const char* file_path = tinyfd_openFileDialog(
        "Choose an image file",
        "",
        2,
        filter_patterns,
        "Image files",
        0
    );

    if (!file_path) {
        std::cerr << "No file selected.\n";
        return -1;
    }

    // Read image
    cv::Mat frame = cv::imread(file_path);
    if (frame.empty()) {
        std::cerr << "Could not open or find the image.\n";
        return -1;
    }

    // Prepare input blob
    cv::Mat blob = cv::dnn::blobFromImage(frame, 1.0, cv::Size(300, 300),
                                          cv::Scalar(104.0, 177.0, 123.0), false, false);

    net.setInput(blob);
    cv::Mat detections = net.forward();

    // Process detections
    float confidenceThreshold = 0.5;
    for (int i = 0; i < detections.size[2]; i++) {
        float confidence = detections.ptr<float>(0, 0, i)[2];
        if (confidence > confidenceThreshold) {
            int x1 = static_cast<int>(detections.ptr<float>(0, 0, i)[3] * frame.cols);
            int y1 = static_cast<int>(detections.ptr<float>(0, 0, i)[4] * frame.rows);
            int x2 = static_cast<int>(detections.ptr<float>(0, 0, i)[5] * frame.cols);
            int y2 = static_cast<int>(detections.ptr<float>(0, 0, i)[6] * frame.rows);
            cv::rectangle(frame, cv::Point(x1, y1), cv::Point(x2, y2),
                          cv::Scalar(0, 255, 0), 2);
        }
    }
    cv::putText(frame, "Press ESC to exit", cv::Point(10, 30),
                cv::FONT_HERSHEY_SIMPLEX, 0.8, cv::Scalar(0, 0, 255), 2);


    // Show image
      // Show image with fixed window size
    cv::namedWindow("Detected Faces", cv::WINDOW_NORMAL);
    cv::resizeWindow("Detected Faces", 800, 600);
    cv::imshow("Detected Faces", frame);
     // Wait until ESC key is pressed
    while (true) {
        int key = cv::waitKey(1);
        if (key == 27) { // ESC key
            break;
        }
    }
    cv::destroyAllWindows();
    
    }


