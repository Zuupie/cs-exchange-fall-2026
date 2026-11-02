// Description: This program reads in a number of files containing numerical values, calculates the mean, median, and mode of the combined values, and outputs the results.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// Return codes for readFileValues
const int FILE_OK = 0;
const int FILE_NOT_FOUND = -1;
const int FILE_MALFORMED = -2;

int readNumberOfFiles();
bool parseDouble(const string& s, double& out);
int readFileValues(const string& name, vector<double>& out, vector<string>& lines);
void sortValues(vector<double>& v);
double calculateMean(const vector<double>& v);
double calculateMedian(const vector<double>& v); // v must be sorted
double calculateMode(const vector<double>& v);  // v must be sorted

int main(){

    int numFiles = 0;
    string fileName = "";

    vector<double> values; // combined values of all files


    cout << "*** Welcome to Christian's Data Analyzer ***" << endl;
    numFiles = readNumberOfFiles(); //get number of files to read in


    // Loop through the number of files and read each file's values
    for(int i = 0; i < numFiles; i++){
        vector<double> fileValues; // values of this file only
        vector<string> fileLines;  // original text, for printing
        int status = FILE_NOT_FOUND;

        // Keep asking until a valid file was read
        do {
            cout << "Enter the filename for file " << (i + 1) << ": ";
            cin >> fileName;

            //call function to read in file
            status = readFileValues(fileName, fileValues, fileLines);

            if(status == FILE_NOT_FOUND){
                cout << "File not found. Please try again." << endl << endl;
            } else if(status == FILE_MALFORMED){
                cout << "Not an input file. Illegal content/structure detected. Please try again." << endl << endl;
            }
        } while(status != FILE_OK);

        //Print count of values read from the file
        cout << "The list of " << fileValues.size() << " values in file " << fileName << " is: " << endl;
        //Print the values as they appear in the file
        for(size_t j = 0; j < fileLines.size(); j++){
            cout << fileLines[j] << endl;
        }
        cout << endl;

        //Add this file's values to the combined list
        values.insert(values.end(), fileValues.begin(), fileValues.end());
    }

    cout << "*** Summarized Statistics ***" << endl << endl;

    // Sort the combined values
    sortValues(values);

    // Print the sorted list
    cout << "The orderly sorted list of " << values.size() << " values is: " << endl;
    for(size_t i = 0; i < values.size(); i++){
        cout << values[i] << " ";
    }
    cout << endl;

    // Calculate and print the mean, median, and mode
    double mean = calculateMean(values);
    double median = calculateMedian(values);
    double mode = calculateMode(values);

    cout << endl << "Mean: " << mean << fixed << setprecision(4) <<endl;
    cout << "Median: " << median << fixed << setprecision(4) << endl;
    cout << "Mode: " << mode << fixed << setprecision(4) << endl;

    cout << endl << "*** Goodbye. ***" << endl;

    return 0;
}

int readNumberOfFiles(){
    string input;
    while(true){
        cout << "Enter the number of files to read: ";
        cin >> input;

        // Must be a whole number with nothing after it, and > 0
        try {
            size_t pos;
            int numFiles = stoi(input, &pos);
            if(pos == input.size() && numFiles > 0){
                cout << endl;
                return numFiles;
            }
        } catch (const std::exception&) {
            // not a number, fall through to the error message
        }
        cout << "Invalid input. Please enter a whole number greater than 0." << endl << endl;
    }
}

// Parses a string to a double. Returns true if successful, false otherwise.
bool parseDouble(const string& s, double& out)
{
    try
    {
        size_t pos;
        out = stod(s, &pos);
        return pos == s.size();
    }
    catch (const std::invalid_argument&)
    {
        return false;
    }
    catch (const std::out_of_range&)
    {
        return false;
    }
}

// Reads values from a file. Returns FILE_OK if successful, FILE_NOT_FOUND if the file doesn't exist, or FILE_MALFORMED if the file contains invalid data.
int readFileValues(const string& name, vector<double>& out, vector<string>& lines)
{
    out.clear();
    lines.clear();

    ifstream file(name);
    if (!file.is_open())
    {
        return FILE_NOT_FOUND;
    }

    string line;
    while (getline(file, line))
    {
        // Remove Windows line ending
        if (!line.empty() && line[line.size() - 1] == '\r')
        {
            line.erase(line.size() - 1);
        }

        double value;
        if (parseDouble(line, value))
        {
            out.push_back(value);
            lines.push_back(line);
        }
        else
        {
            // One bad line makes the whole file invalid
            file.close();
            out.clear();
            lines.clear();
            return FILE_MALFORMED;
        }
    }

    file.close();

    // A blank file is also invalid
    if (out.empty())
    {
        return FILE_MALFORMED;
    }
    return FILE_OK;
}

void sortValues(vector<double>& v)
{
    // Implement a simple sorting algorithm (e.g., bubble sort)
    for (size_t i = 0; i < v.size(); ++i)
    {
        for (size_t j = 0; j < v.size() - 1; ++j)
        {
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
            }
        }
    }
}


double calculateMean(const vector<double>& v)
{
    if (v.empty())
    {
        return 0.0; // or throw an exception
    }

    double sum = 0.0;
    for (double value : v)
    {
        sum += value;
    }
    return sum / v.size();
}

double calculateMedian(const vector<double>& v){
    if (v.empty())
    {
        return 0.0; // or throw an exception
    }

    size_t n = v.size();
    if (n % 2 == 1)
    {
        return v[n / 2];
    }
    else
    {
        return (v[n / 2 - 1] + v[n / 2]) / 2.0;
    }
}

double calculateMode(const vector<double>& v){
    if (v.empty())
    {
        return 0.0; // or throw an exception
    }

    double mode = v[0];
    int maxCount = 1;
    int currentCount = 1;

    for (size_t i = 1; i < v.size(); ++i)
    {
        if (v[i] == v[i - 1])
        {
            currentCount++;
        }
        else
        {
            if (currentCount > maxCount)
            {
                maxCount = currentCount;
                mode = v[i - 1];
            }
            currentCount = 1;
        }
    }

    // Check the last value
    if (currentCount > maxCount)
    {
        mode = v.back();
    }

    return mode;
}