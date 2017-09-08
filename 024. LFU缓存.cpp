class LFUCache
{
public:
	vector<tuple<int, int, int> > huan_cun;
	int capacity;
	unordered_map<int, int> to_index;
	LFUCache(int capacity)
	{
		this->capacity = capacity;
	}
	void set(int key, int value)
	{
		if (to_index.find(key) != to_index.end())
		{
			int index = to_index[key];
			std::get<1>(huan_cun[index]) = value;
			std::get<2>(huan_cun[index])++;
			return;
		}
		else
		{
			if (huan_cun.size()<capacity)
			{
			}
			else
			{
				auto i = huan_cun[huan_cun.size() - 1];
				huan_cun.pop_back();
				to_index.erase(std::get<0>(i));
			}
			huan_cun.push_back(make_tuple(key, value, 0));
			to_index[key] = huan_cun.size() - 1;
		}
		for (int i = to_index[key]; i > 0; --i)
		{
			if (std::get<2>(huan_cun[i - 1]) <= std::get<2>(huan_cun[i]))
			{
				swap(huan_cun[i], huan_cun[i - 1]);
				to_index[std::get<0>(huan_cun[i])] = i;
				to_index[std::get<0>(huan_cun[i - 1])] = i - 1;
			}
		}
	}
	int get(int key)
	{
		if (to_index.find(key) == to_index.end())
		{
			return -1;
		}
		int index = to_index[key];
		++std::get<2>(huan_cun[index]);
		int result = std::get<1>(huan_cun[index]);
		if (index>0 && std::get<2>(huan_cun[index - 1]) <= std::get<2>(huan_cun[index]))
		{
			swap(huan_cun[index], huan_cun[index - 1]);
			to_index[std::get<0>(huan_cun[index])] = index;
			to_index[std::get<0>(huan_cun[index - 1])] = index - 1;
		}
		return result;
	}
};
