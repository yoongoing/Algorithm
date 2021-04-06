#include<iostream>
#include<algorithm>

using namespace std;

int n, arr[100000];

struct Trie {
	Trie *next[2];

	bool finished = false;
	bool existed = false;

	Trie() {
		for (int i = 0; i < 2; i++)
            next[i] = nullptr;
		finished = false;
		existed = false;
	}
	~Trie() {
		for (int i = 0; i < 2; i++)if (next[i]) delete next[i];
	}

	void add(int key, int digit) {
		if (digit<0) {
			finished = true;
			return;
		}
		int nxt = key & (1 << digit);
		if (nxt)
            nxt = 1;
		if (next[nxt]==nullptr)
			next[nxt] = new Trie;
		
        existed = true;
		next[nxt] -> add(key & ~(1 << digit), digit - 1);
	}
	int solve(int key,int digit) {
		if (digit < 0)
            return 0;
		
        int nxt = key & (1 << digit);
		if (nxt)
            nxt = 1;
		nxt = (nxt + 1) % 2;
		
        int ret = 0;
		if(next[nxt] == nullptr)
            nxt = (nxt + 1) % 2;
		else 
            ret = 1 << digit;
		
        return ret + next[nxt] -> solve(key & ~(1 << digit), digit-1);
	}
};

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	cin >> n;
	Trie* T = new Trie;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		T->add(arr[i],31);
	}
	int ret = 0;
	for (int i = 0; i < n; i++) {
		ret = max(ret, T->solve(arr[i], 31));
	}
	cout << ret;
	delete T;
}