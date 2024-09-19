#include <iostream>
#include <fstream>
#include <vector>
#include "../include/utilities.h"
#include "../lib/json.hpp"  // Include the JSON library

using json = nlohmann::json;

// Load complaints from JSON file
std::vector<Complaint> load_complaints(const std::string& filename) {
    std::vector<Complaint> complaints;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open the file: " << filename << std::endl;
        return complaints;
    }

    json j;
    file >> j;

    // Assuming the JSON structure matches the example provided
    for (const auto& item : j["hits"]["hits"]) {
        Complaint complaint;
        auto source = item["_source"];
        complaint.date_received = source["date_received"];
        complaint.product = source["product"];
        complaint.issue = source["issue"];
        complaint.state = source["state"];
        complaint.company = source["company"];
        complaint.complaint_id = source["complaint_id"];
        complaint.complaint_what_happened = source["complaint_what_happened"];
        // Add other fields as necessary
        complaints.push_back(complaint);
    }

    return complaints;
}

// Preprocess data (e.g., remove duplicates, handle missing values)
void preprocess_data(std::vector<Complaint>& complaints) {
    // Example: Remove complaints with empty product field
    complaints.erase(
        std::remove_if(complaints.begin(), complaints.end(),
                       [](const Complaint& c) { return c.product.empty(); }),
        complaints.end());
}

