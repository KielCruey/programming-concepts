template<class t>
inline void ThreadedTree<t>::inorder() {
	ThreadedNode<t>* prev, * node = root;

	if (node != nullptr) {
		while (node->left != nullptr)
			node = node->key;

		while (node != nullptr) {
			visit(node);
			prev = node;
			node = node->right;

			if (node != nullptr && prev->successor == 0)
				while (node->left != nullptr)
					node = node->left;
		}
	}
}