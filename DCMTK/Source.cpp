#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/mat.hpp>
#include "dcmtk/dcmimgle/dcmimage.h"
#pragma comment(lib, "ws2_32.lib")
#define _CRT_SECURE_NO_WARNINGS

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    
    DicomImage* image = new DicomImage("test.dcm");
    int nWidth = image->getWidth();
    int nHeight = image->getHeight(); 
    int depth = image->getDepth(); 
    cout << nWidth << ", " << nHeight << endl;
    cout << depth << endl;

    
    image->setWindow(100, 400);
    if (image != NULL)
    {
        if (image->getStatus() == EIS_Normal)
        {
            Uint8* pixelData = (Uint8*)(image->getOutputData(8));
            if (pixelData != NULL)
            {        
                Mat dst(nHeight, nWidth, CV_8UC3, pixelData);
                imshow("image2", dst);
                waitKey(0); 
                system("pause");
            }
        }
        else
            cerr << "Error: cannot load DICOM image (" << DicomImage::getString(image->getStatus()) << ")" << endl;
    }
    delete image;
    return 0;
}













