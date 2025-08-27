// This file is part of the actsvg package.
//
// Copyright (C) 2024 CERN for the benefit of the ACTS project
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <gtest/gtest.h>

#include <fstream>

#include "../common/playground.hpp"
#include "../common/test_checksum.hpp"
#include "actsvg/core.hpp"

using namespace actsvg;

TEST(draw, polyline) {

    // Set a playground
    auto pg = test::playground({-400, -400}, {400, 400});

    svg::file tfile;
    std::vector<std::array<scalar, 2u>> line_points = {
        {0, 0}, {10, 10}, {12, 20}, {18, 100}, {50, 105}};

    auto pl = draw::polyline("lo", line_points);

    tfile._objects.push_back(pg);
    tfile._objects.push_back(pl);

    std::string file_name = "test_core_polyline.svg";
    std::ofstream tstream;
    tstream.open(file_name);
    tstream << tfile;
    tstream.close();

    // Checksum test against reference
    std::string test_name =
        ::testing::UnitTest::GetInstance()->current_test_info()->name();
    std::size_t file_checksum = tfile.checksum();
    EXPECT_TRUE(test::checksum(test_name, file_name, file_checksum));
}
