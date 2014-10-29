//
//  main.cpp
//  OpenCVProject
//
//  Created by Charles Morace on 10/5/14.
//  Copyright (c) 2014 Charles Morace. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>

IplImage* convertToGray(IplImage* in)
{
    IplImage* out = cvCreateImage(cvSize(in->width, in->height), IPL_DEPTH_8U, 1);
    cvCvtColor(in, out, CV_BGR2GRAY);
    return( out );
};

IplImage* doCanny( IplImage* in,double lowThresh, double highThresh, double aperture)
{
    IplImage* out;
    if(in->nChannels != 1)
    {
      out = convertToGray(in); //Canny only handles gray scale images
    }
    else{
      out = cvCreateImage(cvSize(in->width, in->height), IPL_DEPTH_8U,1);
    }
    
    cvCanny( in, out, lowThresh, highThresh, aperture );
    return( out );
};

int main(int argc, char *argv[])
{
    IplImage* img = cvLoadImage("/Users/ccm/Documents/xCodeProjects/OpenCVLearning/common/media/map.jpg");
    IplImage* out = doCanny(img, 10, 100, 3);
    cvReleaseImage( &img );
    cvNamedWindow("Canny Edge", CV_WINDOW_AUTOSIZE );
    cvShowImage("Canny Edge", out );
    cvWaitKey(0);
    cvReleaseImage( &out );
    cvDestroyWindow("Canny Edge");
    
}


