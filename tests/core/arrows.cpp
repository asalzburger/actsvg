// This file is part of the actsvg package.
//
// Copyright (C) 2022 CERN for the benefit of the ACTS project
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

TEST(core, arrows) {

    // Set a playground
    auto pg = test::playground({-400, -400}, {400, 400});

    // arrow - parallel to x - axis
    auto a0 = draw::measure("a0", {200, 10}, {300, 10}, style::stroke(),
                            style::marker(), style::marker({"<<"}));

    // arrow - backward pointing, different marker head
    auto a1 = draw::measure("a1", {50, 50}, {40, 50}, style::stroke(),
                            style::marker(), style::marker({"<|"}));

    // arrow - anywhere, yet another marker head
    auto a2 = draw::measure("a2", {10, -40}, {-140, -50}, style::stroke(),
                            style::marker(), style::marker({"<"}));

    svg::file mfile;
    mfile.add_object(pg);
    mfile.add_object(a0);
    mfile.add_object(a1);
    mfile.add_object(a2);

    std::ofstream tstream;
    std::string file_name = "test_core_arrows.svg";
    tstream.open(file_name);
    tstream << mfile;
    tstream.close();

    /// Checksum test against reference
    std::string test_name =
        ::testing::UnitTest::GetInstance()->current_test_info()->name();
    std::uint32_t file_checksum = mfile.checksum();
    EXPECT_TRUE(test::checksum(test_name, file_name, file_checksum));
}
