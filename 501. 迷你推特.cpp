class MiniTwitter 
{
public:
    struct Node 
    {
        int order;
        Tweet tweet;
        Node(int o, Tweet t): order(o), tweet(t){}
    };
    vector<Node> getLastTen(const vector<Node>& t) 
    {
        int last = 10;
        if (t.size() < 10) last = t.size();
        return vector<Node>(t.end() - last, t.end());
    }
    vector<Node> getFirstTen(const vector<Node>& t) 
    {
        int last = 10;
        if (t.size() < 10) last = t.size();
        return vector<Node>(t.begin(), t.begin() + last);
    }
    MiniTwitter() 
    {
        order = 0;
    }
    Tweet postTweet(int user_id, string tweet_text) 
    {
        Tweet tweet = Tweet::create(user_id, tweet_text);
        if (!users_tweets.count(user_id)) users_tweets[user_id] = {};
        ++order;
        users_tweets[user_id].push_back(Node(order, tweet));
        return tweet;
    }
    vector<Tweet> getNewsFeed(int user_id) 
    {
        vector<Node> t;
        if (users_tweets.count(user_id)) 
        {
            t = getLastTen(users_tweets[user_id]);
        }
        if (friends.count(user_id)) 
        {
            for (auto it : friends[user_id]) 
            {
                if (users_tweets.count(it)) 
                {
                    vector<Node> v = getLastTen(users_tweets[it]);
                    t.insert(t.end(), v.begin(), v.end());
                }
            }
        }
        sort(t.begin(), t.end(), [](const Node &a, const Node &b){return a.order > b.order;});
        vector<Tweet> res;
        t = getFirstTen(t);
        for (auto a : t) 
        {
            res.push_back(a.tweet);
        }
        return res;
    }
    vector<Tweet>  getTimeline(int user_id) 
    {
        vector<Node> t;
        if (users_tweets.count(user_id)) 
        {
            t = getLastTen(users_tweets[user_id]);
        }
        sort(t.begin(), t.end(), [](const Node &a, const Node &b){return a.order > b.order;});
        vector<Tweet> res;
        t = getFirstTen(t);
        for (auto a : t) 
        {
            res.push_back(a.tweet);
        }
        return res;
    }
    void follow(int from_user_id, int to_user_id) 
    {
        friends[from_user_id].insert(to_user_id);
    }
    void unfollow(int from_user_id, int to_user_id) 
    {
        friends[from_user_id].erase(to_user_id);
    }
private:
    unordered_map<int, set<int>> friends;
    unordered_map<int, vector<Node>> users_tweets;
    int order;
};
