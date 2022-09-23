#include <pybind11/pybind11.h>

#define cimg_use_jpeg
#define cimg_use_png
#define cimg_display 0

#include "cimg.h"

using namespace cimg_library;

int add(int i, int j) {
    return i + j;
}

int getImage(const std::string& file) {
    CImg<unsigned char> data (file.c_str());
    auto m_width = data.width();
    return m_width;
}



namespace py = pybind11;

PYBIND11_MODULE(cmake_example, m) {
    m.def("add", &add, R"pbdoc(
        Add two numbers

        Some other explanation about the add function.
    )pbdoc");
    m.def("img", &getImage);
    m.def("subtract", [] (int i, int j) { return i - j; });
}
