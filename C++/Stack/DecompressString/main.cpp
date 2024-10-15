#include <iostream>
#include <stack>

using namespace std;

int main(){

    stack<int> nums;
    stack<string> chars;
    string ans = "", input, temp = "";
    int num = 0, repeat;

    cout << "Enter input: ";
    cin >> input;

    for(int i = 0; i < input.length(); i++){
        if(input[i] == '[') continue;
        else if(isdigit(input[i])){
            nums.push(input[i] - '0');
            chars.push(ans);
            ans = "";
        }
        else if(input[i] == ']'){
            temp = "";
            repeat = nums.top();
            nums.pop();
            while(repeat != 0){
                temp += ans;
                repeat--;
            }
            ans = chars.top() + temp;
            chars.pop();
        }
        else ans += input[i];
    }

    cout << "Result: " << ans << endl;

    return 0;
}