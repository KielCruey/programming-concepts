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