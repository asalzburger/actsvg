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

TEST(core, cartesian_grid) {

    // Set a playground
    auto pg = test::playground({-400, -400}, {400, 400});

    // Write out the file
    std::string file_name = "test_core_cartesian_grid.svg";
    std::ofstream fo;
    fo.open(file_name);

    // A simple cartesian grid, non-tiled
    std::vector<scalar> x_edges = {-100, -50, 0, 50, 100, 150};
    std::vector<scalar> y_edges = {-100, -50, 0, 50, 100, 150};

    style::stroke dashed_red;
    dashed_red._sc = style::color{{255, 0, 0}};
    dashed_red._dasharray = {5, 5};

    auto cartesian_grid =
        draw::cartesian_grid("nt_c_grid", x_edges, y_edges, dashed_red);

    svg::file grid_file;
    grid_file.add_object(pg);
    grid_file.add_object(cartesian_grid);
    fo << grid_file;
    fo.close();

    // Checksum test against reference
    std::string test_name =
        ::testing::UnitTest::GetInstance()->current_test_info()->name();
    std::uint32_t file_checksum = grid_file.checksum();
    EXPECT_TRUE(test::checksum(test_name, file_name, file_checksum));
}

TEST(core, tiled_cartesian_grid) {

    // Set a playground
    auto pg = test::playground({-400, -400}, {400, 400});

    // Write out the file
    std::string file_name = "test_core_tiled_cartesian_grid.svg";
    std::ofstream fo;
    fo.open(file_name);

    // A simple cartesian grid, non-tiled
    std::vector<scalar> x_edges = {-100, -50, 0, 50, 100, 150};
    std::vector<scalar> y_edges = {-100, -50, 0, 50, 100, 150};

    style::stroke dashed_red;
    dashed_red._sc = style::color{{255, 0, 0}};
    dashed_red._dasharray = {5, 5};

    // left lower corer blue tile
    style::fill blue_tile;
    style::color blue_opaque{{0, 0, 255}};
    blue_opaque._opacity = 0.5;
    blue_tile._fc = blue_opaque;
    blue_tile._fc._highlight = {"mouseover", "mouseout"};
    auto cartesian_grid = draw::tiled_cartesian_grid(
        "cartesian_grid", x_edges, y_edges, blue_tile, dashed_red);

    svg::file grid_file;
    grid_file.add_object(pg);
    grid_file.add_object(cartesian_grid);
    fo << grid_file;
    fo.close();

    // Checksum test against reference
    std::string test_name =
        ::testing::UnitTest::GetInstance()->current_test_info()->name();
    std::uint32_t file_checksum = grid_file.checksum();
    EXPECT_TRUE(test::checksum(test_name, file_name, file_checksum));
}

TEST(core, fan_grid) {

    // Set a playground
    auto pg = test::playground({-400, -400}, {400, 400});

    // Write out the file
    std::string file_name = "test_core_fan_grid.svg";
    std::ofstream fo;
    fo.open(file_name);

    // A simple cartesian grid, non-tiled
    std::vector<scalar> x_edges_low = {-100, -50, 0, 50, 100};
    std::vector<scalar> x_edges_high = {-140, -70, 0, 70, 140};
    std::vector<scalar> y_edges = {-100, -50, 0, 50, 100, 150};

    style::stroke dashed_red;
    dashed_red._sc = style::color{{255, 0, 0}};
    dashed_red._dasharray = {5, 5};

    auto fan_grid = draw::fan_grid("fan_grid", x_edges_low, x_edges_high,
                                   y_edges, dashed_red);

    svg::file grid_file;
    grid_file.add_object(pg);
    grid_file.add_object(fan_grid);
    fo << grid_file;
    fo.close();

    // Checksum test against reference
    std::string test_name =
        ::testing::UnitTest::GetInstance()->current_test_info()->name();
    std::uint32_t file_checksum = grid_file.checksum();
    EXPECT_TRUE(test::checksum(test_name, file_name, file_checksum));
}

TEST(core, tiled_fan_grid) {

    // Set a playground
    auto pg = test::playground({-400, -400}, {400, 400});

    // Write out the file
    std::string file_name = "test_core_tiled_fan_grid.svg";
    std::ofstream fo;
    fo.open(file_name);

    // A simple cartesian grid, non-tiled
    std::vector<scalar> x_edges_low = {-100, -50, 0, 50, 100};
    std::vector<scalar> x_edges_high = {-140, -70, 0, 70, 140};
    std::vector<scalar> y_edges = {-100, -50, 0, 50, 100, 150};

    style::fill blue_opaque;
    blue_opaque._fc = style::color{{0, 0, 255}};
    blue_opaque._fc._hl_rgb = {0, 255, 0};
    blue_opaque._fc._opacity = 0.5;
    blue_opaque._fc._highlight = {"mouseover", "mouseout"};

    style::stroke dashed_red;
    dashed_red._sc = style::color{{255, 0, 0}};
    dashed_red._dasharray = {5, 5};

    auto fan_grid = draw::tiled_fan_grid("fan_grid", x_edges_low, x_edges_high,
                                         y_edges, blue_opaque, dashed_red);

    ASSERT_TRUE(fan_grid._sub_objects.size() == 20u);
    // Create the references
    std::vector<std::string> tiles_reference;
    for (unsigned int ix = 0; ix + 1 < x_edges_low.size(); ++ix) {
        for (unsigned int iy = 0; iy + 1 < y_edges.size(); ++iy) {
            tiles_reference.push_back("fan_grid_" + std::to_string(ix) + "_" +
                                      std::to_string(iy));
        }
    }
    std::sort(tiles_reference.begin(), tiles_reference.end());
    // Get the tile names
    std::vector<std::string> tiles_test;
    for (const auto& fg : fan_grid._sub_objects) {
        tiles_test.push_back(fg._id);
    }
    std::sort(tiles_test.begin(), tiles_test.end());
    ASSERT_TRUE(tiles_test == tiles_reference);

    svg::file grid_file;
    grid_file.add_object(pg);
    grid_file.add_object(fan_grid);
    fo << grid_file;
    fo.close();

    // Checksum test against reference
    std::string test_name =
        ::testing::UnitTest::GetInstance()->current_test_info()->name();
    std::uint32_t file_checksum = grid_file.checksum();
    EXPECT_TRUE(test::checksum(test_name, file_name, file_checksum));
}

TEST(core, polar_grid) {

    // Set a playground
    auto pg = test::playground({-400, -400}, {400, 400});

    // Write out the file
    std::string file_name = "test_core_polar_grid.svg";
    std::ofstream fo;
    fo.open(file_name);

    // A simple cartesian grid, non-tiled
    std::vector<scalar> r_edges_low = {50, 75, 100, 125, 150, 175};
    std::vector<scalar> phi_edges = {0.3 * M_PI, 0.4 * M_PI, 0.5 * M_PI,
                                     0.6 * M_PI, 0.7 * M_PI};

    style::stroke dashed_red;
    dashed_red._sc = style::color{{255, 0, 0}};
    dashed_red._dasharray = {5, 5};

    auto polar_grid =
        draw::polar_grid("polar_grid", r_edges_low, phi_edges, dashed_red);

    svg::file grid_file;
    grid_file.add_object(pg);
    grid_file.add_object(polar_grid);
    fo << grid_file;
    fo.close();

    // Checksum test against reference
    std::string test_name =
        ::testing::UnitTest::GetInstance()->current_test_info()->name();
    std::uint32_t file_checksum = grid_file.checksum();
    EXPECT_TRUE(test::checksum(test_name, file_name, file_checksum));
}

TEST(core, tiled_polar_grid) {

    // Set a playground
    auto pg = test::playground({-400, -400}, {400, 400});

    // Write out the file
    std::string file_name = "test_core_tiled_polar_grid.svg";
    std::ofstream fo;
    fo.open(file_name);

    // A simple cartesian grid, non-tiled
    std::vector<scalar> r_edges_low = {50, 75, 100, 125, 150, 175};
    std::vector<scalar> phi_edges = {0.3 * M_PI, 0.4 * M_PI, 0.5 * M_PI,
                                     0.6 * M_PI, 0.7 * M_PI};

    style::fill blue_opaque;
    blue_opaque._fc = style::color{{0, 0, 255}};
    blue_opaque._fc._hl_rgb = {0, 255, 0};
    blue_opaque._fc._opacity = 0.5;
    blue_opaque._fc._highlight = {"mouseover", "mouseout"};

    style::stroke dashed_red;
    dashed_red._sc = style::color{{255, 0, 0}};
    dashed_red._dasharray = {5, 5};

    auto polar_grid = draw::tiled_polar_grid(
        "polar_grid", r_edges_low, phi_edges, blue_opaque, dashed_red);

    svg::file grid_file;
    grid_file.add_object(pg);
    grid_file.add_object(polar_grid);
    // Write and close the file
    fo << grid_file;
    fo.close();

    // Checksum test against reference
    std::string test_name =
        ::testing::UnitTest::GetInstance()->current_test_info()->name();
    std::uint32_t file_checksum = grid_file.checksum();
    EXPECT_TRUE(test::checksum(test_name, file_name, file_checksum));
}
