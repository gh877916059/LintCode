class Solution 
{
public:
string serialize(TreeNode *root)
{
	string str;
	if (root == NULL)
	{
		str += "# ";
	}
	else
	{
		stringstream ss;
		ss << root->val;
		str += ss.str();
		str += " ";
		str += serialize(root->left);
		str += serialize(root->right);
	}
	return str;
}
TreeNode *deserialize(string& data)
{
	if (data.length() == 0)
	{
		return NULL;
	}
	else if (data[0] == '#')
	{
		data = data.substr(2);
		return NULL;
	}
	else
	{
		int temp;
		int counter = 1;
		while (data[counter] != ' ')
		{
			counter++;
		}
		string temp_str = data.substr(0, counter);
		stringstream ss(temp_str);
		ss >> temp;
		TreeNode* wow = new TreeNode(temp);
		data = data.substr(counter + 1);
		wow->left = deserialize(data);
		wow->right = deserialize(data);
		return wow;
	}
}
};
