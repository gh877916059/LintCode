class LRUCache
{
public:
	typedef struct Node
	{
		Node* pre;
		Node* next;
		int key;
		int val;
		Node(int key, int val)
		{
			this->key = key;
			this->val = val;
			this->pre = NULL;
			this->next = NULL;
		}
	};
	int capacity;
	unordered_map<int, Node*> map;
	Node* head = new Node(-1, -1);
	Node* tail = new Node(-1, -1);
	LRUCache(int capacity)
	{
		this->capacity = capacity;
		head->next = tail;
		tail->pre = head;
	}
	int get(int key)
	{
		if (map[key]==NULL)
		{
			map.erase(key);
			return -1;
		}
		Node* current = map[key];
		current->next->pre = current->pre;
		current->pre->next = current->next;
		move_to_tail(current);
		return map[key]->val;
	}
	void set(int key, int value)
	{
		if (get(key) != -1)
		{
			Node* node = map[key];
			node->pre->next = node->next;
			node->next->pre = node->pre;
			move_to_tail(node);
			map[key]->val = value;
			return;
		}
		if (map.size() == capacity)
		{
			map.erase(head->next->key);
			head->next = head->next->next;
			head->next->pre = head;
		}
		Node* insert = new Node(key, value);
		move_to_tail(insert);
		map[key] = insert;
	}
	void move_to_tail(Node* node)
	{
		node->pre = tail->pre;
		tail->pre->next = node;
		node->next = tail;
		tail->pre = node;
	}
};
