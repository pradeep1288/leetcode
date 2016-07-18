struct tweet {
    int idx;
    int tweetId;
};

struct Comp {
    bool operator()(tweet& a, tweet& b) {
        return (a.idx < b.idx);
    }
};

class Twitter {
private:
    map<int, vector<tweet>> tweetNewsFeed; // data structure for maintaining the user id
    map<int, vector<int>> following;
    int globalId;

public:
    /** Initialize your data structure here. */
    Twitter() {
        globalId = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweet tempTweet;
        tempTweet.idx = globalId;
        tempTweet.tweetId = tweetId;
        tweetNewsFeed[userId].push_back(tempTweet);
        globalId++;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> newsFeedToReturn;
        vector<tweet> tempTweetsToReturn; 
        
        if (tweetNewsFeed[userId].size() > 0) {
            for (auto t: tweetNewsFeed[userId])
                tempTweetsToReturn.push_back(t);
        }
        
        if (following[userId].size() >0) {
            for (auto id: following[userId]) {
                if (tweetNewsFeed[id].size() > 0) {
                    for (auto t: tweetNewsFeed[id])
                        tempTweetsToReturn.push_back(t);
                }    
            }   
        }
        
        make_heap(tempTweetsToReturn.begin(), tempTweetsToReturn.end(), Comp());
        
        int size = tempTweetsToReturn.size();
        int k=0;
        while (k<10 && size != 0) {
            newsFeedToReturn.push_back(tempTweetsToReturn.front().tweetId);
            pop_heap(tempTweetsToReturn.begin(), tempTweetsToReturn.end(), Comp());
            tempTweetsToReturn.pop_back();
            k++;
            size--;
        }
        return newsFeedToReturn;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            if (following[followerId].size() > 0) {
                for (auto i: following[followerId]) {
                    if (i == followeeId)
                        return;
                }
                following[followerId].push_back(followeeId);
            }
            else {
                following[followerId].push_back(followeeId);
            }
        }
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (following[followerId].size() > 0) {
            following[followerId].erase(std::remove(following[followerId].begin(), following[followerId].end(),followeeId ), following[followerId].end());
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
