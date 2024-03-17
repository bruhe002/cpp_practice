///////////////////////////////////////////////////
// @reverse_deque_string_ex.cpp
//
// Author: Eric Bruhns
//
///////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <deque>

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

    ~UrlHistory() {
        this->urls.clear();
    }

private:
    deque<Url> urls;
};

int main() {



    return 0;
}