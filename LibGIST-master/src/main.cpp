#include <iostream>
#include <iomanip>
#include <opencv2/opencv.hpp>

#include "standalone_image.h"
#include "gist.h"

using namespace std;
using namespace cv;
using namespace cls;

const GISTParams DEFAULT_PARAMS {true, 32, 32, 4, 3, {8, 8, 4}};


int main(int argc, char* argv[])
{
    Mat src = imread(argv[1]);
    if (src.empty()) {
        cerr << "No input image!" << endl;
        exit(1);
    }

    vector<float> result;
    GIST gist_ext(DEFAULT_PARAMS);
    gist_ext.extract(src, result);

    for (const auto & val : result) {
        cout << fixed << setprecision(4) << val << "\n";
        // cout<<endl;
    }
    // cout << endl;

    return 0;
}