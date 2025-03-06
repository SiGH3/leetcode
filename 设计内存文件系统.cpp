//ls：输入一个路径字符串。如果路径指向一个文件，返回仅包含该文件名的列表；
//如果路径指向一个文件夹，返回该文件夹内所有文件和子文件夹的名字，按字典序排列。

//mkdir：输入一个当前不存在的文件夹路径，根据路径名创建一个新的文件夹。如果上层文件夹路径不存在，也需要将它们全部创建。

//addContentToFile：输入文件路径和文件内容。
//如果文件不存在，创建包含给定文件内容的文件；如果文件已存在，将给定的文件内容追加在原本内容的后面。

//readContentFromFile：输入文件路径，返回该文件的内容。

#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class FileSystem{
private:
    struct Node{
        bool isFile = false;
        string content = "";
        unordered_map<string, Node*> children;
    };
    Node* root;

    // 辅助函数：遍历路径，若 create = true 则创建路径
    Node* traverse(const string& path, bool create = false){
        Node* node = root;
        if(path == "/") return node;
        stringstream ss(path);
        string part;
        while(getline(ss,part,'/')){
            if(part.empty()) continue;
            if(node->children.find(part)==node->children.end()){
                if(!create) return nullptr;
                node->children[part]=new Node();
            }
            node = node->children[part];
        }
        return node;
    }
    
    public:
    FileSystem(){
        root = new Node();
    }

    vector<string> ls(string path){
        Node* node = traverse(path);
        if(!node) return {};
        if(node->isFile) return {path.substr(path.find_last_of('/')+1)};

        vector<string> result;
        for(const auto&[name,_]:node->children){
            result.push_back(name);
        }
        sort(result.begin(),result.end());
        return result;
    }

    void mkdir(string path){
        traverse(path,true);
    }

    void addContentToFile(string filePath,string content){
        Node* node = traverse(filePath,true);
        node->isFile = true;
        node->content += content;
    }

    string readContentFromFile(string filePath){
        Node* node = traverse(filePath);
        return node && node->isFile?node->content:" ";
    }
};

int main(){
    FileSystem fs;
    fs.mkdir("a/b/c");
    fs.addContentToFile("a/b/c/d","hello");
    cout << "Read fron a/b/c/d:" << fs.readContentFromFile("a/b/c/d")<<endl;

    vector<string> res = fs.ls("/");
    cout<<"contents of root:";
    for(const string& name: res)cout<<name<<" ";
    cout<<endl;

    return 0;
}