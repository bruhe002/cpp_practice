///////////////////////////////////////////////////
// @reverse_deque_string_ex.cpp
//
// Author: Eric Bruhns
//
///////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <deque>
#include <string>

#include "../url_class.cpp"

using namespace std;

class UrlHistory {
public:
    UrlHistory() {
        deque<string> urls{};
    };

    UrlHistory(UrlHistory& uh) {
        this->urls = uh.urls;
    }

    void add_url(const string& pro, const string& res) {
        Url website(pro, res);

        // Loop through the urls
        for(auto u = begin(urls); u < end(urls); u++) {
            // Check if any are equal to website
            if (*u == website) {
                // if the Url is already in front, do nothing
                if(*u != urls.front()) {
                    // else erase it
                    urls.erase(u);
                    break;
                }
            }
        }

        urls.push_front(website);
    }

    friend ostream& operator<<(ostream& os, const UrlHistory& uh) {
        os << "URL History:\n";
        for(size_t i = 0; i < uh.urls.size(); i++) {
            os << i + 1 << ": " << uh.urls[i].returnUrlStr() << endl; 
        }
        os << "\n";
    }

    ~UrlHistory() {
        this->urls.clear();
    }

private:
    deque<Url> urls;
};

const string GLOBAL_PROTOCOL = "http";

int main() {

    // Initialize History object
    UrlHistory history;

    // Loop for input
    string input{""};
    do {
        cout << "Enter a URL:\n";
        getline(cin, input);

        if (input != "-1") {
            auto delimeter_idx = input.find("://");
            if(delimeter_idx != std::string::npos) {
                string protoc{input, 0, delimeter_idx};
                string res{input, delimeter_idx + 3, input.size()};

                history.add_url(protoc, res);
            } else {
                history.add_url(GLOBAL_PROTOCOL, input);
            }

            // Print the history
            cout << history;
        }

    } while(input != "-1");

    return 0;
}