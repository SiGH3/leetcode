#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, string> parseParams(const string &url) {
    unordered_map<string, string> paramMap;
    size_t pos = url.find('?');
    if (pos == string::npos) return paramMap;

    size_t start = pos + 1, end;
    while (start < url.size()) {
        end = url.find('&', start);
        string param = url.substr(start, end - start);
        size_t eqPos = param.find('=');
        if (eqPos != string::npos) {
            paramMap[param.substr(0, eqPos)] = param.substr(eqPos + 1);
        }
        if (end == string::npos) break;
        start = end + 1;
    }
    return paramMap;
}

int main() {
    string url, key;
    cin >> url >> key;
    
    auto paramMap = parseParams(url);
    cout << (paramMap.count(key) ? paramMap[key] : "Key not found") << endl;
    
    return 0;
}
