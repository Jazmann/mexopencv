/**
 * @file cvtColor.cpp
 * @brief mex interface for cvtColor
 * @author Kota Yamaguchi
 * @date 2012
 */
#include "mexopencv.hpp"
using namespace std;
using namespace cv;

/**
 * Main entry called from Matlab
 * @param nlhs number of left-hand-side arguments
 * @param plhs pointers to mxArrays in the left-hand-side
 * @param nrhs number of right-hand-side arguments
 * @param prhs pointers to mxArrays in the right-hand-side
 */
void mexFunction( int nlhs, mxArray *plhs[],
                  int nrhs, const mxArray *prhs[] )
{
    // Check the number of arguments
    if (nrhs<5 ||  nlhs>1)
        mexErrMsgIdAndTxt("mexopencv:error","Wrong number of arguments");
    
    // Argument vector
    vector<MxArray> rhs(prhs,prhs+nrhs);
    
    // Option processing
    Mat src(rhs[0].toMat()), dst;
    const double Theta = rhs[1].toDouble();
    std::vector<double> vg = rhs[2].toVector<double>(); 
    std::vector<double> vc = rhs[3].toVector<double>();
  //  double g[] = {vg[0],vg[1],vg[2]};
  //  double c[] = {vc[0],vc[1],vc[2]};
    
    
    Vec<double, 3> c(0.5, 125.0/255.0, 107.0/255.0);
    // cv::Vec<typename cv::depthConverter<CV_8UC4, CV_8UC3>::srcType, 3> c(180, 50, 128);
    Vec<double, 3> g(1, 18, 2.8);
    RGB2Rot<CV_8UC4,CV_8UC3> colSpace(2, 2, -0.1537, g, c);

    // Process
   // double t = erf(Theta);
    
 // "void cv::convertColor<50, 34>(cv::_InputArray const&, cv::_OutputArray const&, cv::colorSpaceConverter<50, 34>&)"
 // "cv::RGB2Rot<50, 34>::RGB2Rot(int, int, double, std::__1::vector<double, std::__1::allocator<double> >, std::__1::vector<double, std::__1::allocator<double> >)"

  //  RGB2Rot<CV_8UC3,CV_8UC3> colSpace();
  //  RGB2Rot<CV_8UC3,CV_8UC3> colSpace(2, 2, 0.125, g, c);
  //  convertColor<CV_8UC3,CV_8UC3>(src, dst, colSpace);
    plhs[0] = MxArray(dst);
}
