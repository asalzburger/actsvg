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
static std::map<std::string, std::map<std::string, std::size_t>>
    checksum_references = {
        {"arc_plain", {{"test_core_arc.svg", 18363127543040328364u}}},
        {"arrows", {{"test_core_arrows.svg", 1440603090354431698u}}},
        {"barrel_x_y_view",
         {{"test_core_barrel_xy.svg", 7112374335976454304u}}},
        {"barrel_z_phi_view_grid",
         {{"test_core_barrel_grid_zphi.svg", 14219364576139207301u}}},
        {"barrel_z_phi_view",
         {{"test_core_barrel_zphi.svg", 11822802627672614157u}}},
        {"bezier_single_segment",
         {{"test_core_bezier_single.svg", 4796635130615460946u}}},
        {"bezier_spiral",
         {{"test_core_bezier_spiral.svg", 13812603586203006412u}}},
        {"circle_plain", {{"test_core_circle.svg", 11152991457678069022u}}},
        {"circle_scaled",
         {{"test_core_circle_scaled.svg", 14136610263704253315u}}},
        {"circle_shifted",
         {{"test_core_circle_shifted.svg", 5769621367364451915u}}},
        {"copy_triangle",
         {{"test_core_copy_triangle.svg", 9748590202782190011u}}},
        {"endcap_x_y_view_grid",
         {{"test_core_endcap_grid_xy.svg", 3208848548015170136u}}},
        {"endcap_x_y_view",
         {{"test_core_endcap_xy.svg", 9123446266404323210u}}},
        {"endcap_z_r_view",
         {{"test_core_endcap_zr.svg", 1895439008834708001u}}},
        {"cartesian_grid",
         {{"test_core_cartesian_grid.svg", 12324221387649471978u}}},
        {"copy_triangle",
         {{"test_core_copy_triangle.svg", 9748590202782190011u}}},
        {"endcap_x_y_view_grid",
         {{"test_core_endcap_grid_xy.svg", 3208848548015170136u}}},
        {"endcap_x_y_view",
         {{"test_core_endcap_xy.svg", 9123446266404323210u}}},
        {"endcap_z_r_view",
         {{"test_core_endcap_zr.svg", 1895439008834708001u}}},
        {"fan_grid", {{"test_core_fan_grid.svg", 5073300397829703284u}}},
        {"gradient_box_horizontal_label",
         {{"test_core_gradient_box_horizontal_label.svg",
           14397697380348472196u}}},
        {"gradient_box_horizontal",
         {{"test_core_gradient_box_horizontal.svg", 249249637231932785u}}},
        {"gradient_box_linear_x",
         {{"test_core_gradient_box.svg", 14361307405134246492u}}},
        {"gradient_box_vertical_label",
         {{"test_core_gradient_box_vertical_label.svg", 8595011159310365754u}}},
        {"gradient_box_vertical",
         {{"test_core_gradient_box_vertical.svg", 8595011159310365754u}}},
        {"info_box", {{"test_core_infobox.svg", 17615410449384041646u}}},
        {"label_center_center",
         {{"test_core_label_center_center.svg", 4999180398815436104u}}},
        {"label_left_bottom",
         {{"test_core_label_left_bottom.svg", 10393147420831657506u}}},
        {"label_left_center",
         {{"test_core_label_left_center.svg", 14243632695585795193u}}},
        {"label_left_top",
         {{"test_core_label_left_top.svg", 10839318581355876372u}}},
        {"label_right_bottom",
         {{"test_core_label_right_bottom.svg", 13975953792602082035u}}},
        {"label_right_center",
         {{"test_core_label_right_center.svg", 7260991627532736474u}}},
        {"label_right_top",
         {{"test_core_label_right_top.svg", 6121022308674565994u}}},
        {"polar_grid", {{"test_core_polar_grid.svg", 10927291049712492932u}}},
        {"tiled_cartesian_grid",
         {{"test_core_tiled_cartesian_grid.svg", 15065814730637020972u}}},
        {"tiled_fan_grid",
         {{"test_core_tiled_fan_grid.svg", 6975321005958877305u}}},
        {"tiled_polar_grid",
         {{"test_core_tiled_polar_grid.svg", 5119111784448489025u}}},
        {"disc_sector", {{"test_core_sector.svg", 13704500161126974520u}}},
        {"line_plain", {{"test_core_line.svg", 8604728454198242411u}}},
        {"line_scaled", {{"test_core_line_scaled.svg", 8504726860006614313u}}},
        {"line_shifted",
         {{"test_core_line_shifted.svg", 13066924139834964738u}}},
        {"markers", {{"test_core_markers.svg", 7449625682434313483u}}},
        {"measure", {{"test_core_measures.svg", 10476912088548367813u}}},
        {"multiline_text_outside_playground",
         {{"test_core_text_multiline_range.svg", 2053376690733877833u}}},
        {"multiline_text",
         {{"test_core_text_multiline.svg", 17769756650823278370u}}},
        {"polyline", {{"test_core_polyline.svg", 8802252797845306999u}}},
        {"rectangle", {{"test_core_rectangle.svg", 5832522774609444434u}}},
        {"triangle_highligh",
         {{"test_core_triangle_highlight.svg", 1527975388628644916u}}},
        {"triangle_rotated_shifted",
         {{"test_core_triangle_rotated_shifted.svg", 8503461977783193596u}}},
        {"triangle_rotated",
         {{"test_core_triangle_rotated.svg", 16041057479135013470u}}},
        {"triangle_scaled",
         {{"test_core_triangle_scaled.svg", 7225430537971897920u}}},
        {"triangle_shifted",
         {{"test_core_triangle_shifted.svg", 6569322384903829277u}}},
        {"triangle", {{"test_core_triangle.svg", 18351118287512204327u}}},
        {"unconnected_text", {{"test_core_text.svg", 13814141537365926044u}}},
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
