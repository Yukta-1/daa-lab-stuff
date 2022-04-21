#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>

using namespace std;

int in_vector(vector<char> v,char c){
    if(v.size()==0){
        return 0;
    }
    else{
        vector<int>::iterator it;
        it = find (v.begin(), v.end(), c);
        if (it != v.end())
        {
            return 1;
        }
        else
            return 0;
        }
}
int main()
{
    char x[100];
    cin>>x;
    vector<char> letters;
    vector<int> freq;

    for(int i=0;i<strlen(x);i++){
        if(in_vector(letters,x[i])!=0){
            letters.push_back(x[i]);
        }
    }

    for(int i=0;i<letters.size(),i++){
        cout<<letters[i]<<endl;
    }
    return 0;
}


// using namespace std;
// struct MinHeapNode {
// 	char data;
// 	unsigned freq;
// 	MinHeapNode *left, *right;

// 	MinHeapNode(char data, unsigned freq)

// 	{

// 		left = right = NULL;
// 		this->data = data;
// 		this->freq = freq;
// 	}
// };
// struct compare {

// 	bool operator()(MinHeapNode* l, MinHeapNode* r)

// 	{
// 		return (l->freq > r->freq);
// 	}
// };
// void printCodes(struct MinHeapNode* root, string str)
// {

// 	if (!root)
// 		return;

// 	if (root->data != '$')
// 		cout << root->data << ": " << str << "\n";

// 	printCodes(root->left, str + "0");
// 	printCodes(root->right, str + "1");
// }
// void HuffmanCodes(char data[], int freq[], int size)
// {
// 	struct MinHeapNode *left, *right, *top;
// 	priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

// 	for (int i = 0; i < size; ++i)
// 		minHeap.push(new MinHeapNode(data[i], freq[i]));
// 	while (minHeap.size() != 1) {
// 		left = minHeap.top();
// 		minHeap.pop();

// 		right = minHeap.top();
// 		minHeap.pop();
// 		top = new MinHeapNode('$', left->freq + right->freq);

// 		top->left = left;
// 		top->right = right;

// 		minHeap.push(top);
// 	}
// 	printCodes(minHeap.top(), "");
// }
// int main()
// {
// 	char arr[] = { 'a', 'b', 'c', 'd' };
// 	int freq[] = { 3, 2, 5, 6};
// 	int size = sizeof(arr) / sizeof(arr[0]);
// 	HuffmanCodes(arr, freq, size);
// 	return 0;
// }
