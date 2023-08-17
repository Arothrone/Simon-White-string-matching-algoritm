#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <cctype>
#include <algorithm>

using namespace std;

class WorkFuncs
{
public:
    int startIndex;
    int endIndex;
    string temp;

    void doubleString(string &ggg)
    {
        for (int i = ggg.length(); i > 0; i--)
        {

            if (ggg[0] == ' ')
            {
                if (ggg[1] != ' ')
                {
                    ggg += ggg[0];
                }
            }
            else
            {

                ggg += ggg[0];
                ggg += ggg[0];
            }
            ggg.erase(ggg.begin());
        }
    }

    void customSplit(vector<string> &vectorVar, string &str, const char &separator)
    {

        startIndex = 0;
        endIndex = 0;
        for (int i = 0; i <= str.size(); i++)
        {
            if (str[i] == separator || i == str.size())
            {
                endIndex = i;
                temp = "";
                temp.append(str, startIndex, endIndex - startIndex);
                vectorVar.push_back(temp);
                startIndex = endIndex + 1;
            }
        }
    };

    double CompareStrings(string &str1, string &str2)
    {
        doubleString(str1);
        doubleString(str2);
        transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
        transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
        vector<string> pairs1 = {};
        vector<string> pairs2 = {};
        WordLetterPairs(pairs1, str1);
        WordLetterPairs(pairs2, str2);

        int intersection = 0;
        int unionVar = pairs1.size() + pairs2.size();

        for (int i = 0; i < pairs1.size(); i++)
        {
            for (int j = 0; j < pairs2.size(); j++)
            {
                if (pairs1[i] == pairs2[j])
                {
                    intersection++;
                    pairs2.erase(pairs2.begin() + j); // Must remove the match to prevent "GGGG" from appearing to match "GG" with 100% success

                    break;
                }
            }
        }

        return (2.0 * intersection) / unionVar;
    }

    void WordLetterPairs(vector<string> &AllPairs, string &str)
    {
        // Tokenize the string and put the tokens/words into an array
        vector<string> Words = {};
        customSplit(Words, str, ' ');
        vector<string> PairsInWord = {};

        // For each word
        for (int w = 0; w < Words.size(); w++)
        {

            LetterPairs(PairsInWord, Words[w]);

            for (int p = 0; p < PairsInWord.size(); p++)
            {
                AllPairs.push_back(PairsInWord[p]);
            }
            PairsInWord.clear();
        }
    }

    void LetterPairs(vector<string> &pairs, string &str)
    {
        int numPairs = str.length() - 1;
        for (int i = 0; i < numPairs; i++)
        {
            pairs.push_back(str.substr(i, 2));
        }

        return;
    }

    WorkFuncs()
    {

        string str1 = "FRANCE";
        string str2 = "REPUBLIC OF FRANCE";

        cout << CompareStrings(str1, str2) << endl;
    };
};

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "Russian");

    WorkFuncs funcs;

    return 0;
};
