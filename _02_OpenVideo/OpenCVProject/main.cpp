//
//  main.cpp
//  OpenCVProject
//
//  Created by Charles Morace on 10/5/14.
//  Copyright (c) 2014 Charles Morace. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>

const char* movieFile = "/Users/ccm/Documents/xCodeProjects/OpenCVLearning/common/media/airhorse.avi";

int main(int argc, char *argv[])
{
    cvNamedWindow( "Example2", CV_WINDOW_AUTOSIZE );
    CvCapture* capture = cvCreateFileCapture( movieFile );
    IplImage* frame;
    while(1) {
        frame = cvQueryFrame( capture );
        
        if( !frame ){
            break;
        }
        cvShowImage( "Example2", frame );
        char c = cvWaitKey(33);
        
        if( c == 27 ){
            break;
        }
    }
    cvReleaseCapture( &capture );
    cvDestroyWindow( "Example2" );
}
