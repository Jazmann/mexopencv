/**
 * @file cvtColorRot.cpp
 * @brief mex interface for cvtColor
 * @author Jasper
 * @date 2014
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
    // cvtColorRot(dst,src,theta,g,c)
    // Check the number of arguments
    if (nrhs<4 ||  nlhs>1)
        mexErrMsgIdAndTxt("mexopencv:error","Wrong number of arguments");
    
    // Argument vector
    vector<MxArray> rhs(prhs,prhs+nrhs);
    
    // Option processing
    Mat src(rhs[0].toMat()), dst;
    const double Theta = rhs[1].toDouble();
    std::vector<double> g_std = rhs[2].toVector<double>(); 
    std::vector<double> c_std = rhs[3].toVector<double>();
    double g[] = {g_std[0],g_std[1],g_std[2]};
    double c[] = {c_std[0],c_std[1],c_std[2]};
    Vec<double, 3> g_cv(c_std[0],c_std[1],c_std[2]);
    Vec<double, 3> c_cv(g_std[0],g_std[1],g_std[2]);
    
    RGB2Rot<CV_8UC3,CV_8UC3> colSpace(2, 2, Theta, g_cv, c_cv);
    
 //   RGB2Rot<CV_8UC3,CV_8UC3> colSpace_std(2, 2, Theta, g_std, c_std);
    
 //   RGB2Rot<CV_8UC3,CV_8UC3> colSpace_null;
//      colSpace_null.setTransformFromAngle(Theta);
//      colSpace_null.setRGBIndices(2, 2);
//      colSpace_null.setuC(c_cv); // asumes that C is in rotated color space and with a dstBlueIdx
//      colSpace_null.setG(g_cv);
//      colSpace_null.setRedDistributionErf();
//      colSpace_null.setGreenDistributionErf();
//      colSpace_null.setBlueDistributionErf();
    // Process
    double t = cv::erf(Theta);
    double it = cv::erfinv(Theta);
    
    convertColor<CV_8UC3,CV_8UC3>(src, dst, colSpace);
    plhs[0] = MxArray(dst);
}
