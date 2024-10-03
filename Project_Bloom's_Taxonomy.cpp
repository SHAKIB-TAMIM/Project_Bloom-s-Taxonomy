#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>

using namespace std;

// Enum for Bloom's Levels
enum BloomLevel
{
    Remembering,
    Understanding,
    Applying,
    Analyzing,
    Evaluating,
    Creating
};

// Function to convert BloomLevel to string for display
string bloomLevelToString(BloomLevel level)
{
    switch (level)
    {
    case Remembering:
        return "Remembering";
    case Understanding:
        return "Understanding";
    case Applying:
        return "Applying";
    case Analyzing:
        return "Analyzing";
    case Evaluating:
        return "Evaluating";
    case Creating:
        return "Creating";
    default:
        return "Unknown";
    }
}

class BloomClassifier
{
public:
    // Function to classify a word based on Bloom's Taxonomy (currently random)
    BloomLevel classifyWord(string word)
    {
        return static_cast<BloomLevel>(rand() % 6); // Random for demonstration
    }

    // Function to classify a question based on Bloom's Taxonomy
    BloomLevel classifyQuestion(string question)
    {
        // Convert to lowercase for case-insensitive matching
        transform(question.begin(), question.end(), question.begin(), ::tolower);

        cout << "Debug: Analyzing question: " << question << endl; // Debug output

        if (question.find("define") != string::npos || question.find("describe") != string::npos)
        {
            return Remembering;
        }
        else if (question.find("explain") != string::npos || question.find("summarize") != string::npos)
        {
            return Understanding;
        }
        else if (question.find("apply") != string::npos || question.find("use") != string::npos)
        {
            return Applying;
        }
        else if (question.find("analyze") != string::npos || question.find("compare") != string::npos)
        {
            return Analyzing;
        }
        else if (question.find("evaluate") != string::npos || question.find("assess") != string::npos)
        {
            return Evaluating;
        }
        else if (question.find("create") != string::npos || question.find("design") != string::npos)
        {
            return Creating;
        }
        else
        {
            return Remembering; // Default level for unmatched questions
        }
    }

    // Function to print the Bloom's level of a classified question
    void printQuestionLevel(BloomLevel level, string question)
    {
        cout << "The question \"" << question << "\" is at the level of " << bloomLevelToString(level) << "." << endl;
    }
};

int main()
{
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation

    BloomClassifier classifier;
    string input;

    while (true)
    {
        cout << "Enter a word (or type 'exit' to quit): ";
        getline(cin, input);
        if (input == "exit") break;

        BloomLevel wordLevel = classifier.classifyWord(input);
        cout << "The word \"" << input << "\" is classified as: " << bloomLevelToString(wordLevel) << endl;

        cout << "Enter a question (or type 'exit' to quit): ";
        getline(cin, input);
        if (input == "exit") break;

        BloomLevel questionLevel = classifier.classifyQuestion(input);
        classifier.printQuestionLevel(questionLevel, input);
    }

    return 0;
}
