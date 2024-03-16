///////////////////////////////////////////////////
// @reverse_deque_string_ex.cpp
//
// Author: Eric Bruhns
//
///////////////////////////////////////////////////

#include <iostream>
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

    void add_url(const string& pro, const string& res) const {
        Url website(pro, res);

        urls.push_front(Url(pro, res));
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