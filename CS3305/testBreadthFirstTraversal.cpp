#include "bintree.h"
#include <iostream>
#include <cassert>
#include <cstdlib>
using namespace std;
using namespace main_savitch_10;

binary_tree_node<char>* create_tree ();

binary_tree_node<char>* create_tree() {
binary_tree_node<char>* t8 = new binary_tree_node<char>('Q'); 
binary_tree_node<char>* t7 = new binary_tree_node<char>('A'); 
binary_tree_node<char>* t5 = new binary_tree_node<char>('P',NULL,t8);
binary_tree_node<char>* t6 = new binary_tree_node<char>('W');
binary_tree_node<char>* t4 = new binary_tree_node<char>('E',t7);
binary_tree_node<char>* t2 = new binary_tree_node<char>('H',t4);
binary_tree_node<char>* t3 = new binary_tree_node<char>('T',t5,t6);
binary_tree_node<char>* t1 = new binary_tree_node<char>('M',t2,t3); 
return t1;
}

	int main() {

		binary_tree_node<char>* t = create_tree();

		display_complete_tree(t);

		return EXIT_SUCCESS;
	}


