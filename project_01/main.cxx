#include <iostream>
#include <vector>
#include "../include/utilities.h"

// Function declarations from other modules
std::unordered_map<std::string, int> aggregate_complaints_per_month(const std::vector<Complaint>&);
void display_trend_analysis(const std::unordered_map<std::string, int>&);

std::unordered_map<std::string, int> aggregate_complaints_by_state(const std::vector<Complaint>&);
void display_geographical_analysis(const std::unordered_map<std::string, int>&);

std::unordered_map<std::string, int> aggregate_complaints_by_product(const std::vector<Complaint>&);
std::unordered_map<std::string, int> aggregate_complaints_by_issue(const std::vector<Complaint>&);
void display_product_and_issue_analysis(
    const std::unordered_map<std::string, int>&,
    const std::unordered_map<std::string, int>&);

void export_to_json(const std::unordered_map<std::string, int>&, const std::string&);

int main() {
    std::string data_file = "/Users/deejay/Developer/src/R_D/Big_Data/Data++/project_01/data/consumer_report.json";
    std::vector<Complaint> complaints = load_complaints(data_file);

    if (complaints.empty()) {
        std::cerr << "No complaints loaded. Exiting." << std::endl;
        return 1;
    }

    preprocess_data(complaints);

    // Trend Analysis
    auto complaints_per_month = aggregate_complaints_per_month(complaints);
    display_trend_analysis(complaints_per_month);
    export_to_json(complaints_per_month, "../data/complaints_per_month.json");

    // Geographical Analysis
    auto complaints_by_state = aggregate_complaints_by_state(complaints);
    display_geographical_analysis(complaints_by_state);
    export_to_json(complaints_by_state, "../data/complaints_by_state.json");

    // Product and Issue Categorization
    auto product_complaints = aggregate_complaints_by_product(complaints);
    auto issue_complaints = aggregate_complaints_by_issue(complaints);
    display_product_and_issue_analysis(product_complaints, issue_complaints);
    export_to_json(product_complaints, "../data/product_complaints.json");
    export_to_json(issue_complaints, "../data/issue_complaints.json");

    // Additional analyses can be added here

    return 0;
}
