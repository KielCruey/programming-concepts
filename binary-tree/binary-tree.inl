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

	// check for a non-empty binary tree
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
inline void BST<t>::iterativePreorder() {
	Stack<BSTNode<t>*> travStack;
	BSTNode<t>* node = root;

	// check for a non-empty binary tree
	if (node != nullptr) {
		travStack.push(node);

		while (!travStack.empty()) {
			node = travStack.pop(); // deletes top of stack
			visit(node); // prints data's value

			if (node->right != nullptr)
				travStack.push(node->right);

			if (node->left != nullptr)
				travStack.push(node->left);				
		}
	}
}

template<class t>
inline void BST<t>::iterativeInorder() {
	Stack<BSTNode<t>*> travStack;
	BSTNode<t>* node = root;

	// checks for non-empty node
	while (node != nullptr) {
		while (node != nullptr) {
			if (node->right)
				travStack.push(node->right);

			travStack.push(node);
			node = node->left;
		}

		node = travStack.pop();

		while (!travStack.empty() && node->right == nullptr) {
			visit(node);
			node = travStack.pop();
		}

		visit(node);

		if (!travStack.empty())
			node = travStack.pop();
		else
			node = nullptr;
	}
}

template<class t>
inline void BST<t>::iterativePostorder() {
	Stack<BSTNode<t>*> travStack;
	BSTNode<t>* node1 = root, * node2 = root;

	// check for a non-empty binary tree
	while (node1 != nullptr) {
		for (; node1->left != nullptr; node1 = node1->left)
			travStack.push(node1);

		while (node1 != nullptr && (node1->right == nullptr || node1->right == node2)) {
			visit(node1);
			node1 = node2;

			if (travStack.empty())
				return;

			node1 = travStack.pop();
		}

		travStack.push(node1);
		node1 = node1->right;
	}
}

template<class t>
inline t* BST<t>::search(BSTNode<t>* node, const t& element) const {
	// check for a non-empty node
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
	// check for a non-empty node
	if (node != nullptr) {
		visit(node);
		preorder(node->left);
		preorder(node->right);
	}
}

template<class t>
inline void BST<t>::inorder(BSTNode<t>* node) {
	// check for a non-empty node
	if (node != nullptr) {
		inorder(node->left);
		visit(node);
		inorder(node->right);
	}
}

template<class t>
inline void BST<t>::postorder(BSTNode<t>* node) {
	// check for a non-empty node
	if (node != nullptr) {
		postorder(node->left);
		postorder(node->right);
		visit(node);
	}
}

template<class t>
inline void BST<t>::visit(BSTNode<t>* node) {
	std::cout << node->key << ' ';
}
