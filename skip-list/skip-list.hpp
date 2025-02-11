const int maxLevel = 4;

template<class t>
class SkipListNode
{
public: 
	SkipListNode() = default;
	
	t key;
	SkipListNode** next;
};

template<class t>
class SkipList
{
public:
	SkipList();

	bool isEmpty() const;
	void choosePower();
	int	chooseLevel(); // determines the vertical value of the skip list node
	t* skipListSearch(const t& key);
	void skipListInsert(const t& key);

private:
	typedef SkipListNode<t>* nodePtr; // renames skip list node to a better name called 'nodePtr'

	nodePtr root[maxLevel]; // an array of skip list pointers
	int powers[maxLevel];
};

#include "skip-list.inl"