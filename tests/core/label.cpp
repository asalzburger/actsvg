// This file is part of the actsvg package.
//
// Copyright (C) 2023 CERN for the benefit of the ACTS project
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

namespace {
// Helper function
void test_label(style::label::horizontal h, style::label::vertical v,
                const std::string& name, const std::string& test_name) {
    // Set a playground
    auto pg = test::playground({-400, -400}, {400, 400});

    // Write out the file
    std::ofstream fo;
    std::string file_name = "test_core_label_" + name + ".svg";
    fo.open(file_name);

    auto box = draw::rectangle("box", {200, 100}, 150, 20,
                               style::fill{style::color{{255, 0, 0}}});
    auto [llc, urc] = box.generate_bounding_box();
    auto l = style::label{name, h, v};
    l.place(llc, urc);

    svg::file of;
    of.add_object(pg);
    of.add_object(box);
    of.add_object(draw::label("label", l));
    fo << of;
    fo.close();

    // Checksum test against reference
    std::uint32_t file_checksum = of.checksum();
    EXPECT_TRUE(test::checksum(test_name, file_name, file_checksum));
}
}  // namespace

TEST(core, label_left_bottom) {
    std::string test_name =
        ::testing::UnitTest::GetInstance()->current_test_info()->name();

    test_label(style::label::horizontal::left, style::label::vertical::bottom,
               "left_bottom", test_name);
}

TEST(core, label_right_bottom) {
    std::string test_name =
        ::testing::UnitTest::GetInstance()->current_test_info()->name();
    test_label(style::label::horizontal::right, style::label::vertical::bottom,
               "right_bottom", test_name);
}

TEST(core, label_left_top) {
    std::string test_name =
        ::testing::UnitTest::GetInstance()->current_test_info()->name();
    test_label(style::label::horizontal::left, style::label::vertical::top,
               "left_top", test_name);
}

TEST(core, label_right_top) {
    std::string test_name =
        ::testing::UnitTest::GetInstance()->current_test_info()->name();
    test_label(style::label::horizontal::right, style::label::vertical::top,
               "right_top", test_name);
}

TEST(core, label_center_center) {
    std::string test_name =
        ::testing::UnitTest::GetInstance()->current_test_info()->name();
    test_label(style::label::horizontal::center, style::label::vertical::center,
               "center_center", test_name);
}

TEST(core, label_left_center) {
    std::string test_name =
        ::testing::UnitTest::GetInstance()->current_test_info()->name();
    test_label(style::label::horizontal::left, style::label::vertical::center,
               "left_center", test_name);
}

TEST(core, label_right_center) {
    std::string test_name =
        ::testing::UnitTest::GetInstance()->current_test_info()->name();
    test_label(style::label::horizontal::right, style::label::vertical::center,
               "right_center", test_name);
}
