#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib> 

using namespace std;

// Define a struct to store the data read from each line
struct DataPoint {
    int x;
    string symbol; 
    int y;
};

int main() {
    
    
    system("chcp 65001 > nul"); 

    // 1. Download the input data 
    ifstream inputFile("inData.txt");

    if (!inputFile.is_open()) {
        cout << "Error: Cannot open inData.txt. Please ensure the file is in the same directory as the program!" << endl;
        return 1;
    }

    vector<DataPoint> points;
    int max_x = 0;
    int max_y = 0;

    int x, y;
    string symbol;

    // 3. Process the Given Input Data
    while (inputFile >> x >> symbol >> y) {
        points.push_back({x, symbol, y});

        // 4. Determine the Maximum x and y
        if (x > max_x) {
            max_x = x;
        }
        if (y > max_y) {
            max_y = y;
        }
    }

    inputFile.close();

    // 5. Create a 2D Array initialized with spaces
    vector<vector<string>> grid(max_y + 1, vector<string>(max_x + 1, " "));

    // 6. Fill the array with characters from the Input Data
    for (const auto& pt : points) {
        grid[pt.y][pt.x] = pt.symbol;
    }

    // 7. Print the array to reveal the answer of block annotated letters
    cout << "===== Decoded Result =====" << endl;
    for (int row = 0; row <= max_y; ++row) {
        for (int col = 0; col <= max_x; ++col) {
            cout << grid[row][col];
        }
        cout << endl; 
    }

    return 0;
}