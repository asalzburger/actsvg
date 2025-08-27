// This file is part of the actsvg package.
//
// Copyright (C) 2025 CERN for the benefit of the ACTS project
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#include <fstream>
#include <iostream>
#include <map>
#include <string>

namespace actsvg::test {

// clang-format off
/// @brief  Map of map to allow for multiple files per test
static std::map<std::string, std::map<std::string, std::uint32_t>>
    checksum_references = {
{"arc_plain", {{"test_core_arc.svg", 598987246u}}},
{"arrows", {{"test_core_arrows.svg", 156197267u}}},
{"barrel_x_y_view", {{"test_core_barrel_xy.svg", 475857493u}}},
{"barrel_z_phi_view_grid", {{"test_core_barrel_grid_zphi.svg", 846567370u}}},
{"barrel_z_phi_view", {{"test_core_barrel_zphi.svg", 2866154162u}}},
{"bezier_single_segment", {{"test_core_bezier_single.svg", 1452396398u}}},
{"bezier_spiral", {{"test_core_bezier_spiral.svg", 3456691438u}}},
{"cartesian_grid", {{"test_core_cartesian_grid.svg", 2070215038u}}},
{"circle_plain", {{"test_core_circle.svg", 3148444685u}}},
{"circle_scaled", {{"test_core_circle_scaled.svg", 3227732129u}}},
{"circle_shifted", {{"test_core_circle_shifted.svg", 1574532577u}}},
{"copy_triangle", {{"test_core_copy_triangle.svg", 325380468u}}},
{"disc_sector", {{"test_core_sector.svg", 2519980248u}}},
{"endcap_x_y_view_grid", {{"test_core_endcap_grid_xy.svg", 2340117177u}}},
{"endcap_x_y_view", {{"test_core_endcap_xy.svg", 3832402486u}}},
{"endcap_z_r_view", {{"test_core_endcap_zr.svg", 1171393426u}}},
{"fan_grid", {{"test_core_fan_grid.svg", 4027289050u}}},
{"gradient_box_horizontal_label", {{"test_core_gradient_box_horizontal_label.svg", 474900462u}}},
{"gradient_box_horizontal", {{"test_core_gradient_box_horizontal.svg", 305729971u}}},
{"gradient_box_linear_x", {{"test_core_gradient_box.svg", 3168005651u}}},
{"gradient_box_vertical_label", {{"test_core_gradient_box_vertical_label.svg", 4211281398u}}},
{"gradient_box_vertical", {{"test_core_gradient_box_vertical.svg", 4211281398u}}},
{"info_box", {{"test_core_infobox.svg", 391203306u}}},
{"label_center_center", {{"test_core_label_center_center.svg", 2273812319u}}},
{"label_left_bottom", {{"test_core_label_left_bottom.svg", 2284580567u}}},
{"label_left_center", {{"test_core_label_left_center.svg", 3350259941u}}},
{"label_left_top", {{"test_core_label_left_top.svg", 2653912820u}}},
{"label_right_bottom", {{"test_core_label_right_bottom.svg", 858078508u}}},
{"label_right_center", {{"test_core_label_right_center.svg", 3086957164u}}},
{"label_right_top", {{"test_core_label_right_top.svg", 812048451u}}},
{"line_plain", {{"test_core_line.svg", 2384224490u}}},
{"line_scaled", {{"test_core_line_scaled.svg", 2130133868u}}},
{"line_shifted", {{"test_core_line_shifted.svg", 681977029u}}},
{"markers", {{"test_core_markers.svg", 1722066658u}}},
{"measure", {{"test_core_measures.svg", 2274566291u}}},
{"multiline_text_outside_playground", {{"test_core_text_multiline_range.svg", 660718925u}}},
{"multiline_text", {{"test_core_text_multiline.svg", 986506060u}}},
{"polar_grid", {{"test_core_polar_grid.svg", 4052172164u}}},
{"polyline", {{"test_core_polyline.svg", 2285432013u}}},
{"rectangle", {{"test_core_rectangle.svg", 3386630377u}}},
{"tiled_cartesian_grid", {{"test_core_tiled_cartesian_grid.svg", 3030659065u}}},
{"tiled_fan_grid", {{"test_core_tiled_fan_grid.svg", 232443122u}}},
{"tiled_polar_grid", {{"test_core_tiled_polar_grid.svg", 4084096140u}}},
{"triangle_highligh", {{"test_core_triangle_highlight.svg", 3994778312u}}},
{"triangle_rotated_shifted", {{"test_core_triangle_rotated_shifted.svg", 3296491611u}}},
{"triangle_rotated", {{"test_core_triangle_rotated.svg", 1263086013u}}},
{"triangle_scaled", {{"test_core_triangle_scaled.svg", 3282708057u}}},
{"triangle_shifted", {{"test_core_triangle_shifted.svg", 1124525001u}}},
{"triangle", {{"test_core_triangle.svg", 42086428u}}},
{"unconnected_text", {{"test_core_text.svg", 3211069024u}}},
};
// clang-format on

/** @brief  Checksum test against reference
 *
 * @param test_name  Name of the test
 * @param file_name  Name of the file
 * @param checksum   Checksum value to test from reference
 *
 * @return  True if the checksum matches the reference, false otherwise
 */
static inline bool checksum(const std::string &test_name,
                            const std::string &file_name,
                            std::size_t checksum) {
    auto test_it = checksum_references.find(test_name);
    if (test_it != checksum_references.end()) {
        auto file_it = test_it->second.find(file_name);
        if (file_it != test_it->second.end()) {
            bool result = (file_it->second == checksum);
            if (not result) {
                std::fstream fs;
                fs.open("checksum_mismatch_" + test_name + ".log",
                        std::ios::app);
                fs << "Checksum mismatch! For updating, use this line: "
                   << '\n';
                fs << "{\"" << test_name << "\", {{\"" << file_name << "\", "
                   << checksum << "u}}}," << '\n';
                fs.close();
            }
            return result;
        }
    }
    std::fstream fs;
    fs.open("checksum_not_found_" + test_name + ".log", std::ios::app);
    fs << "Reference not found! If you want to add it, use this line: " << '\n';
    fs << "{\"" << test_name << "\", {{\"" << file_name << "\", " << checksum
       << "u}}}," << '\n';
    fs.close();
    return false;
}

}  // namespace actsvg::test
