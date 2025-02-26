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
// algorithm an traverse the tree without using stack and recursion.
// Goes to the left most node in the right subtree.
template<class t>
inline void BST<t>::morrisInorder() {
	BSTNode<t>* node = root;
	BSTNode<t>* tmp;

	while (node != nullptr) {
		if (node->left == nullptr) {
			visit(node);
			node = node->right;
		}
		else {
			tmp = node->left;

			while (tmp->right != nullptr && tmp->right != node)
				tmp = tmp->right;

			if (tmp->right == nullptr) {
				tmp->right = node;
				node = node->left;
			}
			else {
				visit(node);
				tmp->right = nullptr;
				node = node->right;
			}
		}
	}
}

template<class t>
inline void BST<t>::insert(const t& element) {
	BSTNode<t>* node = root;
	BSTNode<t>* previous;

	// checks for a non-empty node
	while (node != nullptr) {
		previous = node;

		if (node->key < element)
			node = node->right;
		else
			node = node->left;

		// tree is empty
		if (root == nullptr)
			root = new BSTNode<t>(element);
		else if (previous->key < element)
			previous->right = new BSTNode<t>(element);
		else
			previous->left = new BSTNode<t>(element);
	}
}

template<class t>
inline void BST<t>::deleteByMerging(BSTNode<t>*& node) {
	BSTNode<t>* tmp = node;

	if (node != nullptr) {
		if (!node->right) // doesn't have a right child
			node = node->left;	// move to the left child
		else if (node->left == nullptr) // doesn't have a left child
			node = node->right; // move to the right child
		// no left or right child then start merging
		else {
			tmp = node->left; // move left subtree

			// keep on going down to the left most subtree's right node
			while (tmp->right != nullptr)
				tmp = tmp->right;

			tmp->right = node->right;
			tmp = node;
			node = node->left;
		}
		
		delete tmp;
	}
}

template<class t>
inline void BST<t>::findAndDeleteByMerging(const t& element) {
	BSTNode<t>* node = root;
	BSTNode<t>* previous = nullptr;

	// non-empty node
	while (node != nullptr) {
		// if node is found, break from while loop
		if (node->key == element) 
			break;

		previous = node;

		// looks left or right childe depending on the current nodes value
		if (node->key < element)
			node = node->right;
		else
			node = node->left;
	}

	if (node != nullptr && node->key == element) {
		if (node == root)
			deleteByMerging(root);
		else if (previous->left == node)
			deleteByMerging(previous->left);
		else
			deleteByMerging(previous->right);
	}
	else if (root != nullptr)
		std::cout << "key: " << element << " -- not in the tree\n"; \
	else
		std::cout << "the tree is empty\n";
}

template<class t>
inline void BST<t>::deleteByCoping(BSTNode<t>*& node) {
	BSTNode<t>* previous;
	BSTNode<t>* tmp = node;

	if (node->right == nullptr) // no right child node
		node = node->left;
	else if (node->left == nullptr) // no right child node
		node = node->right;
	// node has both children
	else {
		tmp = node->left;
		previous = node;

		// keep on moving to right node
		while (tmp->right != nullptr) {
			previous = tmp;
			tmp = tmp->right;
		}

		node->key = tmp->key;

		if (previous == node)
			previous->left = tmp->left;
		else
			previous->right = tmp->left;
	}

	delete tmp;
}

template<class t>
inline t* BST<t>::search(BSTNode<t>* node, const t& element) const {
	// checks for a non-empty node
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
