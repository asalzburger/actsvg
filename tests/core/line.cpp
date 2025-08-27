// This file is part of the actsvg package.
//
// Copyright (C) 2022 CERN for the benefit of the ACTS project
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <gtest/gtest.h>

#include <fstream>
#include <sstream>

#include "../common/playground.hpp"
#include "../common/test_checksum.hpp"
#include "actsvg/core/draw.hpp"

using namespace actsvg;

TEST(core, line) {

    auto line = draw::line("l", {40., -20.}, {80., 100.},
                           style::stroke{style::color{{255, 0, 0}}, 2});

    std::array<scalar, 2> ref_x_range = {40., 80.};
    std::array<scalar, 2> ref_y_range = {-100., 20.};
    ASSERT_TRUE(line._x_range == ref_x_range);
    ASSERT_TRUE(line._y_range == ref_y_range);
}

TEST(core, line_plain) {

    // Set a playground
    auto pg = test::playground({-400, -400}, {400, 400});

    // Write out the file
    std::string file_name = "test_core_line.svg";
    std::ofstream fo;
    fo.open(file_name);

    auto line = draw::line("l", {4, -2.}, {8., 10.},
                           style::stroke{style::color{{0, 0, 255}}, 2});

    svg::file line_file;
    line_file.add_object(pg);
    line_file.add_object(line);

    fo << line_file;
    fo.close();

    // Checksum test against reference
    std::string test_name =
        ::testing::UnitTest::GetInstance()->current_test_info()->name();
    std::uint32_t file_checksum = line_file.checksum();
    EXPECT_TRUE(test::checksum(test_name, file_name, file_checksum));
}

TEST(core, line_shifted) {

    // Set a playground
    auto pg = test::playground({-400, -400}, {400, 400});

    // Write out the file
    std::string file_name = "test_core_line_shifted.svg";
    std::ofstream fo;
    fo.open(file_name);

    style::transform t{{100, 100}};
    // Add the line
    auto line = draw::line("l", {4, -2.}, {8., 10.},
                           style::stroke{style::color{{0, 0, 255}}, 2}, t);
    svg::file line_file;

    line_file.add_object(pg);
    line_file.add_object(line);
    // Close the file
    fo << line_file;
    fo.close();

    // Checksum test against reference
    std::string test_name =
        ::testing::UnitTest::GetInstance()->current_test_info()->name();
    std::uint32_t file_checksum = line_file.checksum();
    EXPECT_TRUE(test::checksum(test_name, file_name, file_checksum));
}

TEST(core, line_scaled) {

    // Set a playground
    auto pg = test::playground({-400, -400}, {400, 400});

    // Write out the file
    std::string file_name = "test_core_line_scaled.svg";
    std::ofstream fo;
    fo.open(file_name);

    style::transform t;
    t._scale = {10, 10};
    // Add the line
    auto line = draw::line("l", {4, -2.}, {8., 10.},
                           style::stroke{style::color{{0, 0, 255}}, 2}, t);
    svg::file line_file;
    line_file.add_object(pg);
    line_file.add_object(line);
    fo << line_file;
    fo.close();

    // Checksum test against reference
    std::string test_name =
        ::testing::UnitTest::GetInstance()->current_test_info()->name();
    std::uint32_t file_checksum = line_file.checksum();
    EXPECT_TRUE(test::checksum(test_name, file_name, file_checksum));
}
