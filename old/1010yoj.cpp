#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> findPostOrder(const vector<int>& preorder, const vector<int>& inorder) {
    if(preorder.empty() || inorder.empty()) {
        return vector<int>();
    }
    
    vector<int> result;
    int root = preorder[0];
    int rootPos = find(inorder.begin(), inorder.end(), root) - inorder.begin();
    
    vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + rootPos + 1);
    vector<int> leftInorder(inorder.begin(), inorder.begin() + rootPos);
    
    vector<int> rightPreorder(preorder.begin() + rootPos + 1, preorder.end());
    vector<int> rightInorder(inorder.begin() + rootPos + 1, inorder.end());
    
    vector<int> leftPostorder = findPostOrder(leftPreorder, leftInorder);
    result.insert(result.end(), leftPostorder.begin(), leftPostorder.end());
    
    vector<int> rightPostorder = findPostOrder(rightPreorder, rightInorder);
    result.insert(result.end(), rightPostorder.begin(), rightPostorder.end());
    
    result.push_back(root);
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> preorder(n), inorder(n);
    
    for(int i = 0; i < n; i++) {
        cin >> preorder[i];
    }
    
    for(int i = 0; i < n; i++) {
        cin >> inorder[i];
    }
    
    vector<int> postorder = findPostOrder(preorder, inorder);
    
    for(int i = 0; i < postorder.size(); i++) {
        cout << postorder[i];
        if(i != postorder.size() - 1) cout << " ";
    }
    cout << endl;
    
    return 0;
}