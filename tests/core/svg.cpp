// This file is part of the actsvg package.
//
// Copyright (C) 2022 CERN for the benefit of the ACTS project
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "actsvg/core/svg.hpp"

#include <gtest/gtest.h>

#include <fstream>
#include <iostream>
#include <sstream>

using namespace actsvg;

TEST(core, empty_object) {

    svg::object empty{"empty"};
    std::stringstream ss;
}

TEST(core, file_set_view_box_and_checksum) {
    svg::file file;
    file.set_view_box({0, 0, 100, 100});
    std::stringstream ss;
    ss << file;
    std::string svg = ss.str();
    ASSERT_TRUE(svg.find("viewBox=\"0 0 100 100\"") != std::string::npos);

    std::size_t checksum = file.checksum();
    ASSERT_EQ(checksum, 3187404258u);
}
