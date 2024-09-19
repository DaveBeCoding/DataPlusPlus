#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <iomanip>
#include <ctime>
#include "../include/utilities.h"

// Function to parse date string into tm struct
std::tm parse_date(const std::string& date_str) {
    std::tm tm = {};
    std::istringstream ss(date_str);
    ss >> std::get_time(&tm, "%Y-%m-%dT%H:%M:%S%z");
    if (ss.fail()) {
        std::cerr << "Failed to parse date: " << date_str << std::endl;
    }
    return tm;
}

// Aggregate complaints per month
std::unordered_map<std::string, int> aggregate_complaints_per_month(const std::vector<Complaint>& complaints) {
    std::unordered_map<std::string, int> complaints_per_month;
    for (const auto& complaint : complaints) {
        std::tm tm = parse_date(complaint.date_received);
        std::ostringstream oss;
        oss << std::put_time(&tm, "%Y-%m");
        std::string month_year = oss.str();
        complaints_per_month[month_year]++;
    }
    return complaints_per_month;
}

// Function to display complaint trends
void display_trend_analysis(const std::unordered_map<std::string, int>& complaints_per_month) {
    std::cout << "Complaint Volume Over Time:\n\n";
    std::cout << "Month-Year\tNumber of Complaints\n";
    std::cout << "-------------------------------------\n";
    for (const auto& [month_year, count] : complaints_per_month) {
        std::cout << month_year << "\t\t" << count << "\n";
    }
}
