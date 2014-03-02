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
    double Theta = rhs[1].toDouble();
    std::vector<double> g = rhs[2].toVector<double>(); 
    std::vector<double> c = rhs[3].toVector<double>();
    
    // Process
    RGB2Rot<CV_8UC4,CV_8UC3> colSpace = RGB2Rot<CV_8UC4,CV_8UC3>(2, 2, Theta, g, c);
    convertColor<CV_8UC4,CV_8UC3>(src, dst, colSpace);
    plhs[0] = MxArray(dst);
}
