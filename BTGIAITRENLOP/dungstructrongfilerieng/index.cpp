#include <iostream>
#include <fstream>
#include <string>
using namespace std;

typedef struct _Day {
    int DD, MM, YY;
} Day;

typedef struct _Student {
    int ID;
    string Name;
    Day BirDay;
    float Score;
} Student;

void InputFromFile(Student sv[], int& n, const string& inputFile) {
    ifstream inFile(inputFile);
    if (!inFile) {
        cerr << "Unable to open input file!" << endl;
        exit(1);
    }
    inFile >> n;
    inFile.ignore(); // Bỏ ký tự xuống dòng sau khi đọc n
    for (int i = 0; i < n; i++) {
        inFile >> sv[i].ID;
        inFile.ignore(); // Bỏ ký tự xuống dòng trước khi đọc tên
        getline(inFile, sv[i].Name);
        inFile >> sv[i].Score;
        inFile >> sv[i].BirDay.DD >> sv[i].BirDay.MM >> sv[i].BirDay.YY;
    }
    inFile.close();
}

void PrintToFile(Student students[], int n, const string& outputFile) {
    ofstream outFile(outputFile);
    if (!outFile) {
        cerr << "Unable to open output file!" << endl;
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        outFile << students[i].ID << "\t" 
                << students[i].Name << "\t"
                << students[i].BirDay.DD << "/" 
                << students[i].BirDay.MM << "/" 
                << students[i].BirDay.YY << "\t"
                << students[i].Score << endl;
    }
    outFile.close();
}

int main() {
    const string inputFile = "input.txt";
    const string outputFile = "output.txt";
    struct _Student sv[100];
    int n;

    InputFromFile(sv, n, inputFile);
    PrintToFile(sv, n, outputFile);

    cout << "Data has been read from " << inputFile 
         << " and written to " << outputFile << "." << endl;

    return 0;
}
