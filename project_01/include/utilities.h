#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <vector>
#include <unordered_map>
#include <../lib/nlohmann/json.hpp>

// Define the Complaint struct
struct Complaint {
    std::string date_received;
    std::string product;
    std::string issue;
    std::string state;
    std::string company;
    std::string complaint_id;
    std::string complaint_what_happened;
    // Add other fields as needed
};

// Function declarations
std::vector<Complaint> load_complaints(const std::string& filename);
void preprocess_data(std::vector<Complaint>& complaints);

#endif // UTILITIES_H
