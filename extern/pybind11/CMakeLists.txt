cmake_minimum_required(VERSION 3.11)
include(FetchContent)

# Tell the user what's happening.
message(STATUS "Building pybind11 as part of actsvg")

# Declare where to get VecMem from.
set(ACTSVG_PYBIND11_GIT_REPOSITORY
    "https://github.com/pybind/pybind11.git"
    CACHE STRING
    "Git repository to take pybind11 from"
)
set(ACTSVG_PYBIND11_GIT_TAG
    "v2.13.6"
    CACHE STRING
    "Version of pybind11 to build"
)
mark_as_advanced(ACTSVG_PYBIND11_GIT_REPOSITORY ACTSVG_PYBIND11_GIT_TAG)
FetchContent_Declare(
    pybind11
    GIT_REPOSITORY "${ACTSVG_PYBIND11_GIT_REPOSITORY}"
    GIT_TAG "${ACTSVG_PYBIND11_GIT_TAG}"
)

# Now set up its build.
set(PYBIND11_TEST OFF)
set(PYBIND11_INSTALL OFF)
FetchContent_MakeAvailable(pybind11)
