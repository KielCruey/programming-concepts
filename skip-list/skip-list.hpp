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
	int	chooseLevel();
	t* skipListSearch(const t& key);
	void skipListInsert(const t& key);

private:
	typedef SkipListNode<t>* nodePtr;
	nodePtr root[maxLevel];
	int powers[maxLevel];
};

#include "skip-list.inl"