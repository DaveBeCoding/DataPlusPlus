#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "../include/utilities.h"
#include "../lib/json.hpp"  // Include the JSON library

using json = nlohmann::json;

// Prepare data for visualization and export to JSON
void export_to_json(const std::unordered_map<std::string, int>& data, const std::string& filename) {
    json j;
    for (const auto& [key, value] : data) {
        j.push_back({{"name", key}, {"value", value}});
    }

    std::ofstream file(filename);
    if (file.is_open()) {
        file << j.dump(4);  // Pretty-print with 4-space indentation
        file.close();
        std::cout << "Data exported to " << filename << "\n";
    } else {
        std::cerr << "Failed to open file for writing: " << filename << "\n";
    }
}
