#include <pybind11/pybind11.h>
#include "free_fall.h"
int add(int i, int j)
{
    return i + j;
}

std::string hello_hina()
{
    return "Hello HinaPE";
}

class Test
{
public:
    Test(int i, int j) : i_(i), j_(j) {}
    int add()
    {
        i_++;
        j_++;
        return i_ + j_;
    }
private:
    int i_;
    int j_;
};

namespace py = pybind11;

PYBIND11_MODULE(HinaPE_py, m)
{
    // 设置这个Module的文档（可以不写）
    m.doc() = R"pbdoc(
        Pybind11 example plugin
        -----------------------

        .. currentmodule:: Hina

        .. autosummary::
           :toctree: _generate

           add
           subtract
    )pbdoc";

    m.def("add", &add, R"pbdoc(
        Add two numbers

        Some other explanation about the add function.
    )pbdoc");

    m.def("subtract", [](int i, int j) { return i - j; }, R"pbdoc(
        Subtract two numbers

        Some other explanation about the subtract function.
    )pbdoc");

    m.def("hello_hina", &hello_hina, R"pbdoc(
        Say Hello to Hina~~~
    )pbdoc");

    py::class_<HinaPE::Vector3F>(m, "Vector3F")
            .def(py::init<>())
            .def_readwrite("x", &HinaPE::Vector3F::x)
            .def_readwrite("y", &HinaPE::Vector3F::y)
            .def_readwrite("z", &HinaPE::Vector3F::z);
    py::class_<HinaPE::FreeFall>(m, "FreeFall")
            .def(py::init<>())
            .def("get_position", &HinaPE::FreeFall::get_position)
            .def("step", &HinaPE::FreeFall::step);

    py::class_<Test>(m, "Test").def(py::init<int, int>()).def("add", &Test::add);
}
