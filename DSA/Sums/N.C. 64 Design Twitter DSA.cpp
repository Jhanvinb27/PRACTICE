/*
Ques - Implement a simplified version of Twitter which allows users to post tweets, 
       follow/unfollow each other, and view the 10 most recent tweets within their own news feed.
       Users and tweets are uniquely identified by their IDs (integers).
       Implement the following methods:
          - Twitter() Initializes the twitter object.
          - void postTweet(int userId, int tweetId) Publish a new tweet with ID tweetId by the user userId. 
          - You may assume that each tweetId is unique.  
          - List<Integer> getNewsFeed(int userId) Fetches at most the 10 most recent 
            tweet IDs in the user's news feed. Each item must be posted by users who 
            the user is following or by the user themself. 
          - Tweets IDs should be ordered from most recent to least recent.
          - void follow(int followerId, int followeeId) 
            The user with ID followerId follows the user with ID followeeId.
          - void unfollow(int followerId, int followeeId) 
            The user with ID followerId unfollows the user with ID followeeId.
*/
/*
Example - 
Input:
["Twitter", "postTweet", [1, 10], "postTweet", [2, 20], "getNewsFeed", [1], 
"getNewsFeed", [2], "follow", [1, 2], "getNewsFeed", [1], "getNewsFeed", [2], 
"unfollow", [1, 2], "getNewsFeed", [1]]

Output:
[null, null, null, [10], [20], null, [20, 10], [20], null, [10]]

Explanation:
Twitter twitter = new Twitter();
twitter.postTweet(1, 10); // User 1 posts a new tweet with id = 10.
twitter.postTweet(2, 20); // User 2 posts a new tweet with id = 20.
twitter.getNewsFeed(1);   // User 1's news feed should only contain their own tweets -> [10].
twitter.getNewsFeed(2);   // User 2's news feed should only contain their own tweets -> [20].
twitter.follow(1, 2);     // User 1 follows user 2.
twitter.getNewsFeed(1);   // User 1's news feed should contain both tweets from user 1 and user 2 -> [20, 10].
twitter.getNewsFeed(2);   // User 2's news feed should still only contain their own tweets -> [20].
twitter.unfollow(1, 2);   // User 1 unfollows user 2.
twitter.getNewsFeed(1);   // User 1's news feed should only contain their own tweets -> [10].
*/

struct Tweet {
  int id;
  int time;
  Tweet* next = nullptr;
};

struct User {
  int id;
  unordered_set<int> followeeIds;
  Tweet* tweetHead = nullptr;

  User() {}

  User(int id) : id(id) {
    follow(id);
  }

  void follow(int followeeId) {
    followeeIds.insert(followeeId);
  }

  void unfollow(int followeeId) {
    followeeIds.erase(followeeId);
  }

  void post(int tweetId, int time) {
    Tweet* oldTweetHead = tweetHead;
    tweetHead = new Tweet(tweetId, time);
    tweetHead->next = oldTweetHead;
  }
};

class Twitter {
 public:
  void postTweet(int userId, int tweetId) {
    if (!users.contains(userId))
      users[userId] = User(userId);
    users[userId].post(tweetId, time++);
  }

  vector<int> getNewsFeed(int userId) {
    if (!users.contains(userId))
      return {};

    vector<int> newsFeed;

    auto compare = [](const Tweet* a, const Tweet* b) {
      return a->time < b->time;
    };
    priority_queue<Tweet*, vector<Tweet*>, decltype(compare)> maxHeap(compare);

    for (const int followeeId : users[userId].followeeIds) {
      Tweet* tweetHead = users[followeeId].tweetHead;
      if (tweetHead != nullptr)
        maxHeap.push(tweetHead);
    }

    int count = 0;
    while (!maxHeap.empty() && count++ < 10) {
      Tweet* tweet = maxHeap.top();
      maxHeap.pop();
      newsFeed.push_back(tweet->id);
      if (tweet->next)
        maxHeap.push(tweet->next);
    }

    return newsFeed;
  }

  void follow(int followerId, int followeeId) {
    if (followerId == followeeId)
      return;
    if (!users.contains(followerId))
      users[followerId] = User(followerId);
    if (!users.contains(followeeId))
      users[followeeId] = User(followeeId);
    users[followerId].follow(followeeId);
  }

  void unfollow(int followerId, int followeeId) {
    if (followerId == followeeId)
      return;
    if (const auto it = users.find(followerId);
        it != users.cend() && users.contains(followeeId))
      it->second.unfollow(followeeId);
  }

 private:
  int time = 0;
  unordered_map<int, User> users;  
};

/*
Time Complexity : O(n + k log k), where  
                          - n = |tweets| (total number of tweets)  
                          - k = min(10, |tweets|)  

Space Complexity:  
O(n)
*/
