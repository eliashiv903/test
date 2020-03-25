#include <iostream>
#include <string>

using namespace std;
namespace phonetic {

    string deletSpace(string s);
    bool equalsWord(char t, char s);

    string find(string t, string s) {
        s = deletSpace(s);
        if (s.length() == 0)
            throw "err the world emty";
        std::size_t found = s.find(" ");
        if (found != std::string::npos)
            throw "err more then one word in s or space";
        for (int i = 0; i < t.length(); i++) {
            if (equalsWord(s.at(0), t.at(i))) {
                int count = 0;
                string ans = "";
                for (int j = i, k = 0; k < s.length() && j < t.length(); j++, k++) {
                    if (equalsWord(s.at(k), t.at(j))) {
                        count++;
                        ans += t.at(j);
                        if (count == s.length() && (t.length() == j + 1 || t.at(j + 1) == ' '))
                            return ans;
                    } else
                        break;
                }
            }
        }
        throw "no find word";
    }

    string deletSpace(string s) {
        while (s.length() > 0 && s.at(0) == ' ')
            s = s.substr(1, s.length() - 1);
        while (s.length() > 0 && s.at(s.length() - 1) == ' ')
            s = s.substr(0, s.length() - 1);
        return s;
    }

    bool equalsWord(char t, char s) {
        s = tolower(s);
        t = tolower(t);
        if (s == t)
            return true;
        if ((s == 'v' && t == 'w') || (s == 'w' && t == 'v'))
            return true;
        if ((s == 'b' && t == 'f') || (s == 'b' && t == 'p') || (s == 'f' && t == 'b') || (s == 'f' && t == 'p') ||
            (s == 'p' && t == 'f') || (s == 'p' && t == 'b'))
            return true;
        if ((s == 'g' && t == 'j') || (s == 'j' && t == 'g'))
            return true;
        if ((s == 'c' && t == 'k') || (s == 'c' && t == 'q') || (s == 'k' && t == 'c') || (s == 'k' && t == 'q') ||
            (s == 'q' && t == 'c') || (s == 'q' && t == 'k'))
            return true;
        if ((s == 's' && t == 'z') || (s == 'z' && t == 's'))
            return true;
        if ((s == 'd' && t == 't') || (s == 't' && t == 'd'))
            return true;
        if ((s == 'o' && t == 'u') || (s == 'u' && t == 'o'))
            return true;
        if ((s == 'i' && t == 'y') || (s == 'y' && t == 'i'))
            return true;
        return false;
    }
}