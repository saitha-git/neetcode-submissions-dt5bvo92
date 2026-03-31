#include <iostream>
#include <string>
using namespace std;

class PrefixTree {
    struct TrieNode {
        bool wordEnd;
        TrieNode* child[26];

        TrieNode() {
            wordEnd = false;
            for (int i = 0; i < 26; i++) {
                child[i] = nullptr;
            }
        }
    };

    TrieNode* root;

public:
    PrefixTree() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->child[index]) {
                node->child[index] = new TrieNode();
            }
            node = node->child[index];
        }
        node->wordEnd = true;
    }

    bool search(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->child[index]) {
                return false;
            }
            node = node->child[index];
        }
        return node->wordEnd;
    }

    bool startsWith(const string& prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (!node->child[index]) {
                return false;
            }
            node = node->child[index];
        }
        return true;
    }
};
