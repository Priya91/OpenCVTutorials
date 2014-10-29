//
//  main.cpp
//  OpenCVProject
//
//  Created by Charles Morace on 10/5/14.
//  Copyright (c) 2014 Charles Morace. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>


int main(int argc, char *argv[])
{
    IplImage* img = cvLoadImage("/Users/ccm/Documents/xCodeProjects/OpenCVLearning/common/media/map.jpg");
    cvNamedWindow("Example1", CV_WINDOW_AUTOSIZE );
    cvShowImage("Example1", img );
    cvWaitKey(0);
    cvReleaseImage( &img );
    cvDestroyWindow("Example1");
    
}
