// ======== Stack ========
template<class t>
inline t Stack<t>::pop() {
	t element = std::stack<t>::top(); // grabs top element on stack
	std::stack<t>::pop();
	return element;
}

// ======== Queue ========
template<class t>
inline t Queue<t>::dequeue() {
	t element = std::queue<t>::front(); // grabs front element on queue
	std::queue<t>::pop();
	return element;
}

template<class t>
inline void Queue<t>::enqueue(const t& element) {
	push(element);
}

// ======== BSTNode ========
template<class t>
inline BSTNode<t>::BSTNode() {
	left = right = nullptr;
}

template<class t>
inline BSTNode<t>::BSTNode(const t& element, BSTNode* left, BSTNode* right) {
	key = element;
	this->left = left;
	this->right = right;
}

// ======== BST ========

template<class t>
inline BST<t>::BST() {
	root = nullptr;
}

template<class t>
inline BST<t>::~BST() {
	clear();
}

template<class t>
inline void BST<t>::clear() {
	clear(root);
	root = nullptr;
}

template<class t >
inline bool BST<t>::isEmpty() const {
	return root == nullptr;
}

template<class t>
inline void BST<t>::preorder(){
	preorder(root); // call protected function
}

template <class t>
inline void BST<t>::inorder() {
	inorder(root);
}

template<class t>
inline void BST<t>::postorder() {
	postorder(root);
}

template<class t>
inline t* BST<t>::search(const t& element) const {
	search(root, element);
}

template<class t>
inline void BST<t>::breadthFirst() {
	Queue<BSTNode<t>*> queue;
	BSTNode<t>* node = root;

	if (node != nullptr) {
		queue.enqueue(node); // adds node to end of queue

		while (!queue.empty()) {
			node = queue.dequeue();
			visit(node);

			if (node->left != nullptr)
				queue.enqueue(node->left);

			if (node->right != nullptr)
				queue.enqueue(node->right);
		}
	}
}

template<class t>
inline t* BST<t>::search(BSTNode<t>* node, const t& element) const {
	while (node != nullptr) {
		if (element == node->key) // if element and node's data are the same
			return &node->key; // return nodes content's address
		else if (element < node->key)
			node = node->left;
		else
			node = node->right;
	}

	return nullptr;
}

template<class t>
inline void BST<t>::preorder(BSTNode<t>* node) {
	if (node != nullptr) {
		visit(node);
		preorder(node->left);
		preorder(node->right);
	}
}

template<class t>
inline void BST<t>::inorder(BSTNode<t>* node) {
	if (node != nullptr) {
		inorder(node->left);
		visit(node);
		inorder(node->right);
	}
}

template<class t>
inline void BST<t>::postorder(BSTNode<t>* node) {
	if (node != nullptr) {
		postorder(node->left);
		postorder(node->right);
		visit(node);
	}
}
