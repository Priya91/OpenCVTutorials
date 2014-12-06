//
//  main.cpp
//  OpenCVProject
//
//  Created by Charles Morace on 10/5/14.
//  Copyright (c) 2014 Charles Morace. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;


int main(int argc, char *argv[])
{
    
    Mat src, src_gray, dst;
    int kernel_size = 3;
    int scale = 1;
    int delta = 0;
    int ddepth = CV_16S;
    char* window_name = "Laplace Demo";
    
    int c;
    
    /// Load an image
    src = imread( "/Users/ccm/Documents/xCodeProjects/OpenCVLearning/common/media/tower.png" );
    
    if( !src.data )
    { return -1; }
    
    /// Remove noise by blurring with a Gaussian filter
    GaussianBlur( src, src, Size(3,3), 0, 0, BORDER_DEFAULT );
    
    /// Convert the image to grayscale
    cvtColor( src, src_gray, CV_RGB2GRAY );
    
    /// Create window
    namedWindow( window_name, CV_WINDOW_AUTOSIZE );
    
    /// Apply Laplace function
    Mat abs_dst;
    
    Laplacian( src_gray, dst, ddepth, kernel_size, scale, delta, BORDER_DEFAULT );
    convertScaleAbs( dst, abs_dst );
    
    /// Show what you got
    imshow( window_name, abs_dst );
    
    waitKey(0);
    
    return 0;
}


