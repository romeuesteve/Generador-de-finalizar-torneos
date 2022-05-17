#include <random>
#include <iostream>
#include <time.h>
#include "BinTree.hh"
using namespace std;

int rand_r(int n) {
	return rand()%(n+1);
}
BinTree<int> arbol(int i, int m, const int& n) {
        BinTree<int> t = BinTree<int>(i);
        BinTree<int> t_left = BinTree<int>(i);
        BinTree<int> t_right = BinTree<int>(m + 1 - i);
        m *= 2;
        if (m + 1 - i <= n) t_left = arbol(i, m, n);
        if (m + 1 - t_right.value() <= n) t_right = arbol(t_right.value(), m, n);
        return BinTree<int>(i, t_left, t_right);
}

BinTree<int> generate_tree(int n) {
	return arbol(1, 2, n);
}

string generate_match() {
	if (7 >= rand_r(100)) {
		return "1-0";
	}
	if (7 >= rand_r(100)) {
		return "0-1";
	}
	string match;
	match.push_back(rand_r(7)+ '0');
	match.push_back('-');
	match.push_back(rand_r(7)+ '0');
	if (match[0] == '0' and match[2] == '1') return match;
	else if (match[2] == '0' and match[0] == '1') return match;
	match.push_back(',');
	match.push_back(rand_r(7)+ '0');
	match.push_back('-');
	match.push_back(rand_r(7)+ '0');
	if (match[0] < match[2] and match[4] < match[6]) return match;
	else if (match[0] > match[2] and match[4] > match[6]) return match;
	match.push_back(',');
	match.push_back(rand_r(7)+ '0');
	match.push_back('-');
	match.push_back(rand_r(7)+ '0');
	while (match[8] == match[10]) match[10] = rand_r(7) + '0';
	return match;
}
bool hoja(BinTree<int> t) {
	return (t.right().empty() && t.left().empty());
}
void generate_text(BinTree<int> t) {
	cout << generate_match() << endl;
	if (hoja(t.left())) cout << 0;
	else generate_text(t.left());
	if (hoja(t.right())) {
		if (hoja(t.left())) cout << " 0" << endl;
		else cout << 0 << endl;
	}
	else {
		if (hoja(t.left())) cout << endl;
		generate_text(t.right());
	}
}

int main() {
	srand(time(NULL)*18493);
	int n;
	cin >> n;

	BinTree<int> t = generate_tree(n);
	generate_text(t);
		
}
