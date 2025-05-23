// This file is part of the actsvg package.
//
// Copyright (C) 2022 Andreas Salzburger <asalzburger@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "actsvg/data/odd_pixel_endcap.hpp"

#include <algorithm>
#include <array>
#include <vector>

#include "actsvg/core/defs.hpp"

namespace actsvg {

/// This file is generated from the Open Data detector and
/// depicts one Pixel endcap layer
namespace {

static const std::vector<std::array<scalar, 3u>> odd_pixel_endcap = []() {
    std::vector<std::array<double, 3u>> raw = {{42, 8.5, -1515.6},
                                               {42, -8.5, -1515.6},
                                               {110, -14.5, -1515.6},
                                               {110, 14.5, -1515.6},
                                               {38.3689, 19.0808, -1516.8},
                                               {42.7688, 2.66003, -1516.8},
                                               {110.005, 14.4642, -1516.8},
                                               {102.499, 42.476, -1516.8},
                                               {-40.6231, 13.6388, -1515.6},
                                               {-32.1231, 28.3612, -1515.6},
                                               {-88.0128, 67.5574, -1515.6},
                                               {-102.513, 42.4426, -1515.6},
                                               {-42.7688, 2.66003, -1516.8},
                                               {-38.3689, 19.0808, -1516.8},
                                               {-102.499, 42.476, -1516.8},
                                               {-110.005, 14.4642, -1516.8},
                                               {-42, -8.5, -1515.6},
                                               {-42, 8.5, -1515.6},
                                               {-110, 14.5, -1515.6},
                                               {-110, -14.5, -1515.6},
                                               {-38.3689, -19.0808, -1516.8},
                                               {-42.7688, -2.66003, -1516.8},
                                               {-110.005, -14.4642, -1516.8},
                                               {-102.499, -42.476, -1516.8},
                                               {-32.1231, -28.3612, -1515.6},
                                               {-40.6231, -13.6388, -1515.6},
                                               {-102.513, -42.4426, -1515.6},
                                               {-88.0128, -67.5574, -1515.6},
                                               {-23.6881, -35.7089, -1516.8},
                                               {-35.7089, -23.6881, -1516.8},
                                               {-88.0348, -67.5287, -1516.8},
                                               {-67.5287, -88.0348, -1516.8},
                                               {-13.6388, -40.6231, -1515.6},
                                               {-28.3612, -32.1231, -1515.6},
                                               {-67.5574, -88.0128, -1515.6},
                                               {-42.4426, -102.513, -1515.6},
                                               {-2.66003, -42.7688, -1516.8},
                                               {-19.0808, -38.3689, -1516.8},
                                               {-42.476, -102.499, -1516.8},
                                               {-14.4642, -110.005, -1516.8},
                                               {8.5, -42, -1515.6},
                                               {-8.5, -42, -1515.6},
                                               {-14.5, -110, -1515.6},
                                               {14.5, -110, -1515.6},
                                               {19.0808, -38.3689, -1516.8},
                                               {2.66003, -42.7688, -1516.8},
                                               {14.4642, -110.005, -1516.8},
                                               {42.476, -102.499, -1516.8},
                                               {32.1231, 28.3612, -1515.6},
                                               {40.6231, 13.6388, -1515.6},
                                               {102.513, 42.4426, -1515.6},
                                               {88.0128, 67.5574, -1515.6},
                                               {28.3612, -32.1231, -1515.6},
                                               {13.6388, -40.6231, -1515.6},
                                               {42.4426, -102.513, -1515.6},
                                               {67.5574, -88.0128, -1515.6},
                                               {35.7089, -23.6881, -1516.8},
                                               {23.6881, -35.7089, -1516.8},
                                               {67.5287, -88.0348, -1516.8},
                                               {88.0348, -67.5287, -1516.8},
                                               {40.6231, -13.6388, -1515.6},
                                               {32.1231, -28.3612, -1515.6},
                                               {88.0128, -67.5574, -1515.6},
                                               {102.513, -42.4426, -1515.6},
                                               {42.7688, -2.66003, -1516.8},
                                               {38.3689, -19.0808, -1516.8},
                                               {102.499, -42.476, -1516.8},
                                               {110.005, -14.4642, -1516.8},
                                               {23.6881, 35.7089, -1516.8},
                                               {35.7089, 23.6881, -1516.8},
                                               {88.0348, 67.5287, -1516.8},
                                               {67.5287, 88.0348, -1516.8},
                                               {13.6388, 40.6231, -1515.6},
                                               {28.3612, 32.1231, -1515.6},
                                               {67.5574, 88.0128, -1515.6},
                                               {42.4426, 102.513, -1515.6},
                                               {2.66003, 42.7688, -1516.8},
                                               {19.0808, 38.3689, -1516.8},
                                               {42.476, 102.499, -1516.8},
                                               {14.4642, 110.005, -1516.8},
                                               {-8.5, 42, -1515.6},
                                               {8.5, 42, -1515.6},
                                               {14.5, 110, -1515.6},
                                               {-14.5, 110, -1515.6},
                                               {-19.0808, 38.3689, -1516.8},
                                               {-2.66003, 42.7688, -1516.8},
                                               {-14.4642, 110.005, -1516.8},
                                               {-42.476, 102.499, -1516.8},
                                               {-28.3612, 32.1231, -1515.6},
                                               {-13.6388, 40.6231, -1515.6},
                                               {-42.4426, 102.513, -1515.6},
                                               {-67.5574, 88.0128, -1515.6},
                                               {-35.7089, 23.6881, -1516.8},
                                               {-23.6881, 35.7089, -1516.8},
                                               {-67.5287, 88.0348, -1516.8},
                                               {-88.0348, 67.5287, -1516.8},
                                               {105, 10.5, -1523.2},
                                               {105, -10.5, -1523.2},
                                               {173, -16.5, -1523.2},
                                               {173, 16.5, -1523.2},
                                               {101.582, 28.5735, -1524.4},
                                               {105.228, 7.89258, -1524.4},
                                               {173.237, 13.7918, -1524.4},
                                               {167.507, 46.2905, -1524.4},
                                               {-28.5735, 101.582, -1523.2},
                                               {-7.89258, 105.228, -1523.2},
                                               {-13.7918, 173.237, -1523.2},
                                               {-46.2905, 167.507, -1523.2},
                                               {-45.7789, 95.0765, -1524.4},
                                               {-26.0453, 102.259, -1524.4},
                                               {-43.6646, 168.21, -1524.4},
                                               {-74.6744, 156.923, -1524.4},
                                               {-61.5933, 85.6827, -1523.2},
                                               {-43.4067, 96.1827, -1523.2},
                                               {-72.2106, 158.072, -1523.2},
                                               {-100.789, 141.572, -1523.2},
                                               {-75.5362, 73.6854, -1524.4},
                                               {-59.4492, 87.1839, -1524.4},
                                               {-98.5625, 143.132, -1524.4},
                                               {-123.842, 121.92, -1524.4},
                                               {-87.1839, 59.4492, -1523.2},
                                               {-73.6854, 75.5362, -1523.2},
                                               {-121.92, 123.842, -1523.2},
                                               {-143.132, 98.5625, -1523.2},
                                               {-96.1827, 43.4067, -1524.4},
                                               {-85.6827, 61.5933, -1524.4},
                                               {-141.572, 100.789, -1524.4},
                                               {-158.072, 72.2106, -1524.4},
                                               {-102.259, 26.0453, -1523.2},
                                               {-95.0765, 45.7789, -1523.2},
                                               {-156.923, 74.6744, -1523.2},
                                               {-168.21, 43.6646, -1523.2},
                                               {-105.228, 7.89258, -1524.4},
                                               {-101.582, 28.5735, -1524.4},
                                               {-167.507, 46.2905, -1524.4},
                                               {-173.237, 13.7918, -1524.4},
                                               {-105, -10.5, -1523.2},
                                               {-105, 10.5, -1523.2},
                                               {-173, 16.5, -1523.2},
                                               {-173, -16.5, -1523.2},
                                               {-101.582, -28.5735, -1524.4},
                                               {-105.228, -7.89258, -1524.4},
                                               {-173.237, -13.7918, -1524.4},
                                               {-167.507, -46.2905, -1524.4},
                                               {95.0765, 45.7789, -1523.2},
                                               {102.259, 26.0453, -1523.2},
                                               {168.21, 43.6646, -1523.2},
                                               {156.923, 74.6744, -1523.2},
                                               {-95.0765, -45.7789, -1523.2},
                                               {-102.259, -26.0453, -1523.2},
                                               {-168.21, -43.6646, -1523.2},
                                               {-156.923, -74.6744, -1523.2},
                                               {-85.6827, -61.5933, -1524.4},
                                               {-96.1827, -43.4067, -1524.4},
                                               {-158.072, -72.2106, -1524.4},
                                               {-141.572, -100.789, -1524.4},
                                               {-73.6854, -75.5362, -1523.2},
                                               {-87.1839, -59.4492, -1523.2},
                                               {-143.132, -98.5625, -1523.2},
                                               {-121.92, -123.842, -1523.2},
                                               {-59.4492, -87.1839, -1524.4},
                                               {-75.5362, -73.6854, -1524.4},
                                               {-123.842, -121.92, -1524.4},
                                               {-98.5625, -143.132, -1524.4},
                                               {-43.4067, -96.1827, -1523.2},
                                               {-61.5933, -85.6827, -1523.2},
                                               {-100.789, -141.572, -1523.2},
                                               {-72.2106, -158.072, -1523.2},
                                               {-26.0453, -102.259, -1524.4},
                                               {-45.7789, -95.0765, -1524.4},
                                               {-74.6744, -156.923, -1524.4},
                                               {-43.6646, -168.21, -1524.4},
                                               {-7.89258, -105.228, -1523.2},
                                               {-28.5735, -101.582, -1523.2},
                                               {-46.2905, -167.507, -1523.2},
                                               {-13.7918, -173.237, -1523.2},
                                               {10.5, -105, -1524.4},
                                               {-10.5, -105, -1524.4},
                                               {-16.5, -173, -1524.4},
                                               {16.5, -173, -1524.4},
                                               {28.5735, -101.582, -1523.2},
                                               {7.89258, -105.228, -1523.2},
                                               {13.7918, -173.237, -1523.2},
                                               {46.2905, -167.507, -1523.2},
                                               {45.7789, -95.0765, -1524.4},
                                               {26.0453, -102.259, -1524.4},
                                               {43.6646, -168.21, -1524.4},
                                               {74.6744, -156.923, -1524.4},
                                               {85.6827, 61.5933, -1524.4},
                                               {96.1827, 43.4067, -1524.4},
                                               {158.072, 72.2106, -1524.4},
                                               {141.572, 100.789, -1524.4},
                                               {61.5933, -85.6827, -1523.2},
                                               {43.4067, -96.1827, -1523.2},
                                               {72.2106, -158.072, -1523.2},
                                               {100.789, -141.572, -1523.2},
                                               {75.5362, -73.6854, -1524.4},
                                               {59.4492, -87.1839, -1524.4},
                                               {98.5625, -143.132, -1524.4},
                                               {123.842, -121.92, -1524.4},
                                               {87.1839, -59.4492, -1523.2},
                                               {73.6854, -75.5362, -1523.2},
                                               {121.92, -123.842, -1523.2},
                                               {143.132, -98.5625, -1523.2},
                                               {96.1827, -43.4067, -1524.4},
                                               {85.6827, -61.5933, -1524.4},
                                               {141.572, -100.789, -1524.4},
                                               {158.072, -72.2106, -1524.4},
                                               {102.259, -26.0453, -1523.2},
                                               {95.0765, -45.7789, -1523.2},
                                               {156.923, -74.6744, -1523.2},
                                               {168.21, -43.6646, -1523.2},
                                               {105.228, -7.89258, -1524.4},
                                               {101.582, -28.5735, -1524.4},
                                               {167.507, -46.2905, -1524.4},
                                               {173.237, -13.7918, -1524.4},
                                               {73.6854, 75.5362, -1523.2},
                                               {87.1839, 59.4492, -1523.2},
                                               {143.132, 98.5625, -1523.2},
                                               {121.92, 123.842, -1523.2},
                                               {59.4492, 87.1839, -1524.4},
                                               {75.5362, 73.6854, -1524.4},
                                               {123.842, 121.92, -1524.4},
                                               {98.5625, 143.132, -1524.4},
                                               {43.4067, 96.1827, -1523.2},
                                               {61.5933, 85.6827, -1523.2},
                                               {100.789, 141.572, -1523.2},
                                               {72.2106, 158.072, -1523.2},
                                               {26.0453, 102.259, -1524.4},
                                               {45.7789, 95.0765, -1524.4},
                                               {74.6744, 156.923, -1524.4},
                                               {43.6646, 168.21, -1524.4},
                                               {7.89258, 105.228, -1523.2},
                                               {28.5735, 101.582, -1523.2},
                                               {46.2905, 167.507, -1523.2},
                                               {13.7918, 173.237, -1523.2},
                                               {-10.5, 105, -1524.4},
                                               {10.5, 105, -1524.4},
                                               {16.5, 173, -1524.4},
                                               {-16.5, 173, -1524.4}};

    std::vector<std::array<scalar, 3>> result;
    auto convert =
        [](const std::array<double, 3>& in) -> std::array<scalar, 3> {
        return {static_cast<scalar>(in[0]), static_cast<scalar>(in[1]),
                static_cast<scalar>(in[2])};
    };

    std::transform(raw.begin(), raw.end(), std::back_inserter(result), convert);
    return result;
}();

std::vector<std::vector<size_t>> odd_pixel_endcap_assoc = {
    {4, 33, 34, 35},  {4, 5, 34, 35, 37},   {5, 35, 37},  {5, 6, 35, 37, 38},
    {6, 37, 38, 39},  {6, 7, 38, 39, 40},   {7, 39, 40},  {7, 8, 39, 40, 41},
    {8, 40, 41, 42},  {8, 9, 41, 42, 43},   {9, 42, 43},  {9, 10, 42, 43, 44},
    {10, 43, 44, 45}, {10, 11, 44, 45, 46}, {11, 45, 46}, {11, 13, 45, 46, 48},
    {13, 46, 48, 49}, {13, 14, 48, 49, 50}, {14, 49, 50}, {14, 15, 49, 50, 51},
    {15, 50, 51, 52}, {15, 16, 51, 52, 53}, {16, 52, 53}, {0, 16, 24, 52, 53},
    {0, 24, 25, 53},  {0, 1, 24, 25, 36},   {1, 25, 36},  {1, 12, 25, 36, 47},
    {12, 36, 47, 54}, {12, 17, 47, 54, 55}, {17, 54, 55}, {17, 18, 54, 55, 56},
    {18, 55, 56, 57}, {18, 19, 56, 57, 58}, {19, 57, 58}, {19, 20, 57, 58, 59},
    {20, 26, 58, 59}, {20, 21, 26, 27, 59}, {21, 26, 27}, {21, 22, 26, 27, 28},
    {22, 27, 28, 29}, {22, 23, 28, 29, 30}, {23, 29, 30}, {2, 23, 29, 30, 31},
    {2, 30, 31, 32},  {2, 3, 31, 32, 33},   {3, 32, 33},  {3, 4, 32, 33, 34},
    {4, 33, 34, 35},  {4, 5, 34, 35, 37},   {5, 35, 37},  {5, 6, 35, 37, 38},
    {6, 37, 38, 39},  {6, 7, 38, 39, 40},   {7, 39, 40},  {7, 8, 39, 40, 41},
    {8, 40, 41, 42},  {8, 9, 41, 42, 43},   {9, 42, 43},  {9, 10, 42, 43, 44},
    {10, 43, 44, 45}, {10, 11, 44, 45, 46}, {11, 45, 46}, {11, 13, 45, 46, 48},
    {13, 46, 48, 49}, {13, 14, 48, 49, 50}, {14, 49, 50}, {14, 15, 49, 50, 51},
    {15, 50, 51, 52}, {15, 16, 51, 52, 53}, {16, 52, 53}, {0, 16, 24, 52, 53},
    {0, 24, 25, 53},  {0, 1, 24, 25, 36},   {1, 25, 36},  {1, 12, 25, 36, 47},
    {12, 36, 47, 54}, {12, 17, 47, 54, 55}, {17, 54, 55}, {17, 18, 54, 55, 56},
    {18, 55, 56, 57}, {18, 19, 56, 57, 58}, {19, 57, 58}, {19, 20, 57, 58, 59},
    {20, 26, 58, 59}, {20, 21, 26, 27, 59}, {21, 26, 27}, {21, 22, 26, 27, 28},
    {22, 27, 28, 29}, {22, 23, 28, 29, 30}, {23, 29, 30}, {2, 23, 29, 30, 31},
    {2, 30, 31, 32},  {2, 3, 31, 32, 33},   {3, 32, 33},  {3, 4, 32, 33, 34}};
}  // namespace

namespace data {

std::vector<trapezoid> generate_endcap_modules() {
    std::vector<trapezoid> modules;
    size_t number_of_modules = odd_pixel_endcap.size() / 4u;
    modules.reserve(number_of_modules);
    for (size_t im = 0; im < number_of_modules; ++im) {
        modules.push_back(
            {odd_pixel_endcap[4 * im], odd_pixel_endcap[4 * im + 1],
             odd_pixel_endcap[4 * im + 2], odd_pixel_endcap[4 * im + 3]});
    }
    return modules;
}

}  // namespace data

}  // namespace actsvg
