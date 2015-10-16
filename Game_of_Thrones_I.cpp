#include <iostream>
#include <string>
#include <map>

#define END return 0
#define ENDLINE cout << endl

using namespace std;


int howManyChars(char ch, string inp){
    int count = 0;
    for ( size_t i = 0; i < inp.size(); i++){
        if (inp[i] == ch) count++;
    }
    return count;
}

std::string removeSameChars(char ch, string inp){
    std::string output;
    for (size_t i = 0; i < inp.size(); i++){
        if (inp[i] != ch){
            output.push_back(inp[i]);
        }
    }
    return output;
}

bool contains(char ch, string input){
    for (size_t i = 0 ; i < input.size(); i++){
        if (input[i] == ch) return true;
    }
    return false;
}

std::string getUniqueChars(string input){
    string output = "";
    for (int i = 0; i < input.size(); i++){
        if (!contains(input[i], output)) output.push_back(input[i]);
    }
    return output;
}

int main()
{
    string s;
    cin >> s;

    string balsal = s;

    std::map <char, int> charMap;

    int flag = 0;

//    cout << getUniqueChars( balsal);

    string unique = getUniqueChars(balsal);
    for (int i = 0; i < unique.size(); i++){
        char map_char = unique[i];
        int occurance = howManyChars(unique[i], balsal);

        charMap.insert(std::pair<char, int>(map_char, occurance));
//        cout << unique[i] << " : " << howManyChars(unique[i], balsal) << endl;
    }

    std::map<char, int>::iterator it = charMap.begin();

    int evencount = 0;
    int oddcount = 0;

    for (; it != charMap.end(); ++it){
        (it->second % 2) ? oddcount++ : evencount++;
    }

    if (oddcount == 0 || oddcount == 1) flag = 1;
    else flag = 0;

    if (flag == 0) cout << "NO";
    else cout << "YES";

    ENDLINE;
    END;
}

