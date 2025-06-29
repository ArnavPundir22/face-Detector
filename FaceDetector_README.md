# FaceDetector (C++) 😎📷

FaceDetector is a C++ application that detects human faces in uploaded images using OpenCV's Haar Cascade Classifiers. It provides fast and accurate face detection for static image files, drawing bounding boxes around detected faces.

## Features

- 👤 Detects faces in uploaded image files  
- 🧠 Utilizes Haar Cascade Classifier (pre-trained XML model)  
- 📂 Simple and efficient image-based detection  
- 🚀 Fast and lightweight with OpenCV in C++

## How It Works

1. The user uploads an image through the interface (or provides a path in CLI).
2. The app uses OpenCV to load the image.
3. Faces are detected using a Haar Cascade classifier.
4. Detected faces are highlighted with rectangles and displayed/saved.

## Installation & Setup

1. **Clone the repository:**
   ```bash
   git clone https://github.com/ArnavPundir22/FaceDetector.git
   cd FaceDetector
   ```

2. **Ensure OpenCV is installed:**
   If using Linux:
   ```bash
   sudo apt install libopencv-dev
   ```

   Or build from source or use vcpkg on Windows.

3. **Build the project:**
   ```bash
   g++ facedetector.cpp -o facedetector `pkg-config --cflags --libs opencv4`
   ```

4. **Run the application:**
   ```bash
   ./facedetector path_to_image.jpg
   ```

## Requirements

- C++ Compiler (e.g., g++)
- OpenCV (version 4.x recommended)

## Notes

- The application processes static images, not real-time webcam feed.
- For best results, use clear images with frontal faces.

## Creator

This project is created by - **Arnav Pundir**.

---

Simple and effective face detection in C++!
