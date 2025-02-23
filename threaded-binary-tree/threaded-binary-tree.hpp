template<class t>
class ThreadedNode
{
public:
	ThreadedNode();
	ThreadedNode(const t& element, ThreadedNode* left = nullptr, ThreadedNode* right = nullptr);

	t key;
	ThreadedNode* left;
	ThreadedNode* right;
	unsigned int successor : 1;
};

// insert and inorder is different for threaded trees
// everything else is the same
template<class t>
class ThreadedTree
{
public:
	ThreadedTree();

	void insert(const t& element);
	void inorder();

protected:
	ThreadedNode<t>* root;
};

#include "threaded-binary-tree.inl"