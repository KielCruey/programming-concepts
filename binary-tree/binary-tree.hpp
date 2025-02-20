#include<iostream>
#include <queue>
#include <stack>

template<class t>
class Stack : public std::stack<t> 
{
	t pop();
};

template<class t>
class Queue : public std::stack<t>
{
	t dequeue(); // deletes first element
	void enqueue(const t& element); // adds last element
};

// BST means binary search tree
template<class t>
class BSTNode
{
public:
	BSTNode();
	BSTNode(const t& element, BSTNode *left = nullptr, BSTNode *right = nullptr);

	t key;
	BSTNode* left;
	BSTNode* right;
};

template<class t>
class BST
{
public:
	BST();
	~BST();

	void clear();
	bool isEmpty() const;
	void preorder();
	void inorder();
	void postorder();
	t* search(const t& element) const;

	void breadthFirst();
	void iterativePreorder();
	void iterativeIndorder();
	void iterativePostorder();
	void morrisInorder();
	void insert(const t& element);
	void deleteByMerging(BSTNode<t>*& element);
	void findAndDeleteByMerging(const t& element);
	void deleteByCoping(BSTNode<t>*& element);
	void balance(t* data, int first, int last);

protected:
	void clear(BSTNode<t>* node);
	t* search(BSTNode<t>* node, const t& element) const;
	void preorder(BSTNode<t>* node);
	void inorder(BSTNode<t>* node);
	void postorder(BSTNode<t>* node);
	virtual void visit(BSTNode<t>* node) {
		std::cout << node->key << ' ';
	}
};

// ======== Stack ========
template<class t>
inline t Stack<t>::pop() {
	t element =	std::stack<t>::top(); // grabs top element on stack
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