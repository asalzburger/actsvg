include(FetchContent)

# Tell the user what's happening.
message(STATUS "Building GoogleTest as part of the ACTSVG project")

# Declare where to get GoogleTest from.
set(ACTSVG_GOOGLETEST_SOURCE
    "URL;https://gitlab.cern.ch/google/googletest/-/archive/v1.17.0/googletest-v1.17.0.tar.gz;URL_MD5;1fc26f132bc4b595113d0290c99fec4a"
    CACHE STRING
    "Source for GoogleTest, when built as part of this project"
)
mark_as_advanced(ACTSVG_GOOGLETEST_SOURCE)
FetchContent_Declare(GoogleTest "${ACTSVG_GOOGLETEST_SOURCE};EXCLUDE_FROM_ALL")

# Options used in the build of GoogleTest.
set(BUILD_GMOCK TRUE CACHE BOOL "Turn off the build of GMock")
set(INSTALL_GTEST FALSE CACHE BOOL "Turn off the installation of GoogleTest")
if(WIN32)
    set(gtest_force_shared_crt
        TRUE
        CACHE BOOL
        "Use shared (DLL) run-time library, even with static libraries"
    )
endif()

# Silence some warnings with modern versions of CMake on macOS.
set(CMAKE_MACOSX_RPATH TRUE)

# Get it into the current directory.
FetchContent_MakeAvailable(GoogleTest)

# Set up aliases for the GTest targets with the same name that they have
# when we find GTest pre-installed.
add_library(GTest::gtest ALIAS gtest)
add_library(GTest::gtest_main ALIAS gtest_main)
