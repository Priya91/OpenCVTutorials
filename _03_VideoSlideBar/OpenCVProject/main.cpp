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
int g_slider_position = 0;
CvCapture* g_capture = NULL;

// callback function for slide bar event
void onTrackbarSlide(int pos)
{
    cvSetCaptureProperty(g_capture, CV_CAP_PROP_POS_FRAMES, pos);
    cvShowImage( "Example3", cvQueryFrame( g_capture ) );
}

int main( int argc, char** argv )
{
    cvNamedWindow( "Example3", CV_WINDOW_AUTOSIZE );
    g_capture = cvCreateFileCapture( movieFile );
    int frames = (int) cvGetCaptureProperty(g_capture,CV_CAP_PROP_FRAME_COUNT );
    
    if( frames!= 0 )
    {
        cvCreateTrackbar("Position", "Example3", &g_slider_position, frames, onTrackbarSlide);
    }
    
    IplImage* frame;
    
    while(1) {
        frame = cvQueryFrame( g_capture );
        g_slider_position = (int) cvGetCaptureProperty(g_capture,CV_CAP_PROP_POS_FRAMES);
        cvSetTrackbarPos("Position", "Example3", g_slider_position);
        if( !frame ){
           // break;
        }
        else{
            cvShowImage( "Example3", frame );
            char c = cvWaitKey(33);
            if( c == 'q' ){
                break;
            }
        }
    }
    cvReleaseCapture( &g_capture );
    cvDestroyWindow( "Example3" );
    return(0);
}
