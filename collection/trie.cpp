#include "../template.hpp"

struct TrieNode {
    unordered_map<char, unique_ptr<TrieNode>> children;
};

class Trie {
private:
    TrieNode root;

private:
    TrieNode const* find(const string& s) const {
        TrieNode const* node = &root;
        for (const char ch : s) {
            if (not node->children.count(ch)) {
                return nullptr;
            }
            node = node->children.at(ch).get();
        }
        return node;
    }

    template<class Fn>
    void apply_(const TrieNode* const node, string& word, Fn&& fn) const {
        if (node->children.count('\0')) {
            fn(word);
        }
        for (const auto& [ch, child] : node->children) {
            if (ch != '\0') {
                word.push_back(ch);
                apply_(child.get(), word, fn);
                word.pop_back();
            }
        }
    }

public:
    void insert(const string& s) {
        TrieNode* node = &root;
        for (const char ch : s) {
            if (not node->children.count(ch)) {
                node->children[ch] = make_unique<TrieNode>();
            }
            node = node->children[ch].get();
        }
        node->children['\0'];
    }

    bool contains(const string& word) const {
        const auto* node = find(word);
        return node and node->children.count('\0');
    }

    template<class Fn>
    void apply(string prefix, Fn&& fn) const {
        if (const auto* node = find(prefix)) {
            apply_(node, prefix, fn);
        }
    }
};

int main() { TimeMeasure _;
    Trie trie;

    trie.insert("apple");
    trie.insert("app");
    trie.insert("banana");
    trie.insert("appalled");

    trie.insert("appalachians");
    cout << trie.contains("appalachians") << endl; // 1
    cout << trie.contains("appalachian") << endl; // 0
    trie.insert("appalachian");
    cout << trie.contains("appalachian") << endl; // 1

    trie.apply("app", [](std::string const& w) { std::cout << w << '\n'; });
}
