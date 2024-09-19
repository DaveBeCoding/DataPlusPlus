#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include "../include/utilities.h"

// Standardize text (convert to lowercase)
std::string standardize_text(const std::string& text) {
    std::string result = text;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

// Aggregate complaints by product
std::unordered_map<std::string, int> aggregate_complaints_by_product(const std::vector<Complaint>& complaints) {
    std::unordered_map<std::string, int> product_complaints;
    for (const auto& complaint : complaints) {
        std::string product = standardize_text(complaint.product);
        product_complaints[product]++;
    }
    return product_complaints;
}

// Aggregate complaints by issue
std::unordered_map<std::string, int> aggregate_complaints_by_issue(const std::vector<Complaint>& complaints) {
    std::unordered_map<std::string, int> issue_complaints;
    for (const auto& complaint : complaints) {
        std::string issue = standardize_text(complaint.issue);
        issue_complaints[issue]++;
    }
    return issue_complaints;
}

// Function to display top products and issues
void display_product_and_issue_analysis(
    const std::unordered_map<std::string, int>& product_complaints,
    const std::unordered_map<std::string, int>& issue_complaints) {
    std::cout << "Top Complained Products:\n\n";
    std::cout << "Product\t\tNumber of Complaints\n";
    std::cout << "-----------------------------------\n";
    for (const auto& [product, count] : product_complaints) {
        std::cout << product << "\t\t" << count << "\n";
    }

    std::cout << "\nTop Complaint Issues:\n\n";
    std::cout << "Issue\t\tNumber of Complaints\n";
    std::cout << "-----------------------------------\n";
    for (const auto& [issue, count] : issue_complaints) {
        std::cout << issue << "\t\t" << count << "\n";
    }
}
