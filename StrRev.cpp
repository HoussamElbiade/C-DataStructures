#include <iostream>
#include <stack>
#include <string>

std::string Reverse(std::string S);

int main(int argc, char** argv){
    std::string U = "hello world";
    std::string S = Reverse(U);
    std::cout<<S<<std::endl;
    return 0;
}

std::string Reverse(std::string S){
    int size = S.size();
    std::string ret;
    std::stack<char> stack;
    for(int i = 0; i < size; i++){
        stack.push(S[i]);
        // std::cout<<stack.top()<<std::endl;
    }
    for(int i = 0; i < size; i++){
        ret.push_back(stack.top());
        stack.pop();
    }
    return ret;
}
