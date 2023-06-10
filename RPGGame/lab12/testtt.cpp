#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    std::ifstream file("mons.txt"); // Assuming the input file is named "input.txt"
    std::vector<std::vector<std::string>> data;

    if (file.is_open()) {
        std::string line;

        // Read each line from the file
        while (std::getline(file, line)) {
            std::vector<std::string> row;
            std::stringstream line_ss(line);
            std::string token;

            // Split the line into tokens
            while (line_ss >> token) {
                row.push_back(token);
            }

            // Add the row to the data vector
            data.push_back(row);
        }

        file.close();

        // Display the separated information
        for (int i = 0; i < data.size(); ++i) {
            for (int j = 0; j < data[i].size(); ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    } else {
        std::cout << "Failed to open the file." << std::endl;
    }

    return 0;
}
