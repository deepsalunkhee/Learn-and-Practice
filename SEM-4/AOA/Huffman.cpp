#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
#include <bitset>

using namespace std;

// Huffman tree node
struct Node
{
    char data;
    int freq;
    Node *left;
    Node *right;
    Node(char data, int freq)
    {
        this->data = data;
        this->freq = freq;
        left = right = nullptr;
    }
};

// Comparator for priority queue
struct compare
{
    bool operator()(Node *left, Node *right)
    {
        return left->freq > right->freq;
    }
};

// Build Huffman tree and return the root node
Node *buildHuffmanTree(string text)
{
    // Calculate frequency of each character
    unordered_map<char, int> freq;
    for (char c : text)
    {
        freq[c]++;
    }

    // Create a priority queue to store nodes
    priority_queue<Node *, vector<Node *>, compare> pq;
    for (auto p : freq)
    {
        pq.push(new Node(p.first, p.second));
    }

    // Build the Huffman tree
    while (pq.size() > 1)
    {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();
        Node *node = new Node('\0', left->freq + right->freq);
        node->left = left;
        node->right = right;
        pq.push(node);
    }

    return pq.top();
}

// Traverse the Huffman tree and build the encoding table
void buildEncodingTable(Node *root, unordered_map<char, string> &encodingTable, string code)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        encodingTable[root->data] = code;
        return;
    }
    buildEncodingTable(root->left, encodingTable, code + "0");
    buildEncodingTable(root->right, encodingTable, code + "1");
}

// Encode the input text using the encoding table
string encode(string text, unordered_map<char, string> &encodingTable)
{
    string encodedText = "";
    for (char c : text)
    {
        encodedText += encodingTable[c];
    }
    return encodedText;
}

// Convert a string of 8 bits to a character
char bitsToChar(string bits)
{
    char c = 0;
    for (int i = 0; i < 8; i++)
    {
        c |= (bits[i] - '0') << (7 - i);
    }
    return c;
}

// Decode the encoded text using the Huffman tree
string decode(string encodedText, Node *root)
{
    string decodedText = "";
    Node *node = root;
    for (char c : encodedText)
    {
        if (c == '0')
        {
            node = node->left;
        }
        else
        {
            node = node->right;
        }
        if (node->left == nullptr && node->right == nullptr)
        {
            decodedText += node->data;
            node = root;
        }
    }
    return decodedText;
}

// Compress the input text using Huffman encoding
string compress(string text)
{
    // Build the Huffman tree
    Node *root = buildHuffmanTree(text);

    // Build the encoding table
    unordered_map<char, string> encodingTable;
    buildEncodingTable(root, encodingTable, "");

    // Encode the input text
    string encodedText = encode(text, encodingTable);

    // Convert the encoded text to a string of bytes
    string compressedText = "";
    for (int i = 0; i < encodedText.size(); i += 8)
    {
        string bits = encodedText.substr(i, 8);
        if (bits.size() < 8)
        {
            bits += string(8 - bits.size(), '0');
        }
        compressedText += bitsToChar(bits);
    }

    // Return the compressed text
    return compressedText;
}

// Convert a character to a string of 8 bits
string charToBits(char c)
{
    string bits = "";
    for (int i = 7; i >= 0; i--)
    {
        bits += ((c >> i) & 1) ? "1" : "0";
    }
    return bits;
}

// Decompress the compressed text using Huffman encoding
string decompress(string compressedText, Node *root)
{
    // Convert the compressed text to a string of bits
    string bits = "";
    for (char c : compressedText)
    {
        bits += charToBits(c);
    }
    // Decode the bits using the Huffman tree
    string decodedText = decode(bits, root);

    // Return the decoded text
    return decodedText;
}

int main()
{
    string text = "The quick brown fox jumps over the lazy dog.";
    // Compress the text
    string compressedText = compress(text);

    // Decompress the text
    string decompressedText = decompress(compressedText, buildHuffmanTree(text));

    // Print the original text, compressed text, and decompressed text
    cout << "Original text: " << text << endl;
    cout << "Compressed text: " << compressedText << endl;
    cout << "Decompressed text: " << decompressedText << endl;

    return 0;
}
