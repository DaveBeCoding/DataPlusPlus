#include <iostream>
#include <unordered_map>
#include <vector>
#include "../include/utilities.h"

// Aggregate complaints by state
std::unordered_map<std::string, int> aggregate_complaints_by_state(const std::vector<Complaint>& complaints) {
    std::unordered_map<std::string, int> complaints_by_state;
    for (const auto& complaint : complaints) {
        complaints_by_state[complaint.state]++;
    }
    return complaints_by_state;
}

// Function to display geographical analysis
void display_geographical_analysis(const std::unordered_map<std::string, int>& complaints_by_state) {
    std::cout << "Top States by Number of Complaints:\n\n";
    std::cout << "State\tNumber of Complaints\n";
    std::cout << "-------------------------------\n";
    for (const auto& [state, count] : complaints_by_state) {
        std::cout << state << "\t" << count << "\n";
    }
}
