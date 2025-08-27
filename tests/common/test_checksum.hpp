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

/// @brief  Map of map to allow for multiple files per test
static std::map<std::string, std::map<std::string, std::uint32_t>>
    checksum_references = {
        {"arc_plain", {{"test_core_arc.svg", 1243177843u}}},
        {"arrows", {{"test_core_arrows.svg", 1086389443u}}},
        {"barrel_x_y_view", {{"test_core_barrel_xy.svg", 1522091882u}}},
        {"barrel_z_phi_view_grid",
         {{"test_core_barrel_grid_zphi.svg", 2950619407u}}},
        {"barrel_z_phi_view", {{"test_core_barrel_zphi.svg", 693995261u}}},
        {"bezier_single_segment",
         {{"test_core_bezier_single.svg", 2738537295u}}},
        {"bezier_spiral", {{"test_core_bezier_spiral.svg", 3252707443u}}},
        {"cartesian_grid", {{"test_core_cartesian_grid.svg", 3320308231u}}},
        {"circle_plain", {{"test_core_circle.svg", 4049313162u}}},
        {"circle_scaled", {{"test_core_circle_scaled.svg", 292374604u}}},
        {"circle_shifted", {{"test_core_circle_shifted.svg", 3123810498u}}},
        {"copy_triangle", {{"test_core_copy_triangle.svg", 3380111819u}}},
        {"disc_sector", {{"test_core_sector.svg", 458193429u}}},
        {"endcap_x_y_view_grid",
         {{"test_core_endcap_grid_xy.svg", 2237589274u}}},
        {"endcap_x_y_view", {{"test_core_endcap_xy.svg", 932791106u}}},
        {"endcap_z_r_view", {{"test_core_endcap_zr.svg", 1512652079u}}},
        {"fan_grid", {{"test_core_fan_grid.svg", 3944820961u}}},
        {"gradient_box_horizontal_label",
         {{"test_core_gradient_box_horizontal_label.svg", 28637731u}}},
        {"gradient_box_horizontal",
         {{"test_core_gradient_box_horizontal.svg", 367593215u}}},
        {"gradient_box_linear_x",
         {{"test_core_gradient_box.svg", 1904663651u}}},
        {"gradient_box_vertical_label",
         {{"test_core_gradient_box_vertical_label.svg", 2253345862u}}},
        {"gradient_box_vertical",
         {{"test_core_gradient_box_vertical.svg", 2253345862u}}},
        {"info_box", {{"test_core_infobox.svg", 801180378u}}},
        {"label_center_center",
         {{"test_core_label_center_center.svg", 4179275377u}}},
        {"label_left_bottom",
         {{"test_core_label_left_bottom.svg", 3784758366u}}},
        {"label_left_center",
         {{"test_core_label_left_center.svg", 3959258088u}}},
        {"label_left_top", {{"test_core_label_left_top.svg", 1830809153u}}},
        {"label_right_bottom",
         {{"test_core_label_right_bottom.svg", 4019039698u}}},
        {"label_right_center",
         {{"test_core_label_right_center.svg", 3384388243u}}},
        {"label_right_top", {{"test_core_label_right_top.svg", 472609614u}}},
        {"line_plain", {{"test_core_line.svg", 1849061987u}}},
        {"line_scaled", {{"test_core_line_scaled.svg", 1046864787u}}},
        {"line_shifted", {{"test_core_line_shifted.svg", 641228521u}}},
        {"markers", {{"test_core_markers.svg", 438928985u}}},
        {"measure", {{"test_core_measures.svg", 1049352393u}}},
        {"multiline_text_outside_playground",
         {{"test_core_text_multiline_range.svg", 903790794u}}},
        {"multiline_text", {{"test_core_text_multiline.svg", 2873250090u}}},
        {"polar_grid", {{"test_core_polar_grid.svg", 884627079u}}},
        {"polyline", {{"test_core_polyline.svg", 2294783306u}}},
        {"rectangle", {{"test_core_rectangle.svg", 3984716410u}}},
        {"tiled_cartesian_grid",
         {{"test_core_tiled_cartesian_grid.svg", 3352147065u}}},
        {"tiled_fan_grid", {{"test_core_tiled_fan_grid.svg", 1298696037u}}},
        {"tiled_polar_grid", {{"test_core_tiled_polar_grid.svg", 3114204036u}}},
        {"triangle_highligh",
         {{"test_core_triangle_highlight.svg", 2884199616u}}},
        {"triangle_rotated_shifted",
         {{"test_core_triangle_rotated_shifted.svg", 3296922076u}}},
        {"triangle_rotated", {{"test_core_triangle_rotated.svg", 2382621365u}}},
        {"triangle_scaled", {{"test_core_triangle_scaled.svg", 4143910371u}}},
        {"triangle_shifted", {{"test_core_triangle_shifted.svg", 363845059u}}},
        {"triangle", {{"test_core_triangle.svg", 936844198u}}},
        {"unconnected_text", {{"test_core_text.svg", 550630037u}}},
};

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
