// This file is part of the actsvg package.
//
// Copyright (C) 2022 CERN for the benefit of the ACTS project
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <gtest/gtest.h>

#include <fstream>
#include <iostream>
#include <sstream>

#include "../common/playground.hpp"
#include "../common/test_checksum.hpp"
#include "actsvg/core.hpp"

using namespace actsvg;

TEST(text, unconnected_text) {

    // Set a playground
    auto pg = test::playground({-400, -400}, {400, 400});

    // Write out the file
    std::string file_name = "test_core_text.svg";
    std::ofstream fo;
    fo.open(file_name);


    // Add the playground
    svg::file text_file;
    text_file.add_object(pg);

    style::color red{{255, 0, 0}};
    style::font fs;
    fs._family = "Arial";
    fs._fc = red;

    // Add the text
    auto text = draw::text("t0", {10, 10}, {"Arial test text at (10,10)"}, fs);
    text_file.add_object(text);

    style::color blue{{0, 0, 255}};
    style::font fsb;
    fsb._family = "Times";
    fsb._size = 20;
    fsb._fc = blue;

    text = draw::text("t1", {20, 80}, {"Bigger Times text"}, fsb);
    text_file.add_object(text);

    fo << text_file;
    fo.close();

    // Checksum test against reference
    std::string test_name =
        ::testing::UnitTest::GetInstance()->current_test_info()->name();
    std::size_t file_checksum = text_file.checksum();
    EXPECT_TRUE(test::checksum(test_name, file_name, file_checksum));

}

TEST(text, multiline_text) {

    // Set a playground
    auto pg = test::playground({-400, -400}, {400, 400});

    style::color red{{255, 0, 0}};
    style::font fs;
    fs._family = "Arial";
    fs._fc = red;

    // Write out the file
    std::string file_name = "test_core_text_multiline.svg";
    std::ofstream fo;
    fo.open(file_name);

    svg::file text_file;
    text_file.add_object(pg);

    // Add the text
    auto text = draw::text("t0", {100, 100}, {"line 0", "line 1"}, fs);
    text_file.add_object(text);
    // Close the file
    fo << text_file;
    fo.close();

    // Checksum test against reference
    std::string test_name =
        ::testing::UnitTest::GetInstance()->current_test_info()->name();
    std::size_t file_checksum = text_file.checksum();
    EXPECT_TRUE(test::checksum(test_name, file_name, file_checksum));
}

TEST(text, multiline_text_outside_playground) {

    svg::object pgo = svg::object::create_group("playground");

    // Set a playground
    auto pg = test::playground({-400, -400}, {400, 400});
    pgo.add_object(pg);

    style::color red{{255, 0, 0}};
    style::font fs;
    fs._family = "Arial";
    fs._fc = red;

    // Write out the file, it should adapt the range for the outside text
    std::string file_name = "test_core_text_multiline_range.svg";
    std::ofstream fo;
    fo.open(file_name);

    svg::file text_file;

    // Add the text
    auto t0 = draw::text("t0", {500, 500}, {"line 0", "line 1", "line 2"}, fs);
    auto t1 = draw::text("t1", {-500, -500},
                         {"other line 0", "other line 1", "other line 2"}, fs);
    pgo.add_object(t0);
    pgo.add_object(t1);

    // Add to the file anf write out
    text_file.add_object(pgo);
    fo << text_file;
    fo.close();

    // Checksum test against reference
    std::string test_name =
        ::testing::UnitTest::GetInstance()->current_test_info()->name();
    std::size_t file_checksum = text_file.checksum();
    EXPECT_TRUE(test::checksum(test_name, file_name, file_checksum));
}
