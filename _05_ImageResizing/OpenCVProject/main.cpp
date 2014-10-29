//
//  main.cpp
//  OpenCVProject
//
//  Created by Charles Morace on 10/5/14.
//  Copyright (c) 2014 Charles Morace. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>


IplImage* doPyrDown(IplImage* in, int filter = CV_GAUSSIAN_5x5)
{
    assert( in->width%2 == 0 && in->height%2 == 0 );
    IplImage* out = cvCreateImage(cvSize( in->width/2, in->height/2 ), in->depth,in->nChannels);
    cvPyrDown( in, out );
    return( out );
};

int main(int argc, char *argv[])
{
    IplImage* img = cvLoadImage("/Users/ccm/Documents/xCodeProjects/OpenCVLearning/common/media/indian.jpg");
    IplImage* out = doPyrDown(img);
    cvReleaseImage( &img );
    cvNamedWindow("Resize", CV_WINDOW_AUTOSIZE );
    cvShowImage("Resize", out );
    cvWaitKey(0);
    cvReleaseImage( &out );
    cvDestroyWindow("Resize");
    
}


