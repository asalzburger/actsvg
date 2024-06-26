// This file is part of the actsvg packge.
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

TEST(svg, empty_object) {

    svg::object empty{"empty"};
    std::stringstream ss;
}
