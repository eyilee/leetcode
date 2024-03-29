#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Tweet
{
public:
    static int count;
    int uid;
    int userId;
    int tweetId;

    Tweet (int userId, int tweetId)
    {
        uid = count++;

        this->userId = userId;
        this->tweetId = tweetId;
    }

    operator int () const
    {
        return tweetId;
    }

    bool operator > (const Tweet& rhs) const
    {
        return this->uid > rhs.uid;
    }
};

int Tweet::count = 0;

class Follower
{
public:
    int followerId;
    vector<int> followees;

    Follower (int followerId, int followeeId)
    {
        this->followerId = followerId;
        followees.push_back (followeeId);
    }

    void add_followee (int followeeId)
    {
        if (find (followees.begin (), followees.end (), followeeId) == followees.end ()) {
            followees.push_back (followeeId);
        }
    }

    void remove_followee (int followeeId)
    {
        vector<int>::iterator it = find (followees.begin (), followees.end (), followeeId);
        if (it != followees.end ()) {
            followees.erase (it);
        }
    }

    bool operator == (const int rhs)
    {
        return this->followerId == rhs;
    }
};

class Twitter
{
public:
    void postTweet (int userId, int tweetId)
    {
        tweets.push_back (Tweet (userId, tweetId));
    }

    vector<int> getNewsFeed (int userId)
    {
        vector<Tweet> news;

        // get tweets posted by user
        for (vector<Tweet>::iterator it = tweets.begin (); it != tweets.end (); it++) {
            if (it->userId == userId) {
                news.push_back (*it);
            }
        }

        // get tweets posted by followees
        vector<Follower>::iterator follower = find (followers.begin (), followers.end (), userId);

        if (follower != followers.end ()) {
            vector<int> followees = follower->followees;

            for (vector<int>::iterator followee = followees.begin (); followee != followees.end (); followee++) {
                for (vector<Tweet>::iterator tweet = tweets.begin (); tweet != tweets.end (); tweet++) {
                    if (tweet->userId == *followee) {
                        news.push_back (*tweet);
                    }
                }
            }
        }

        sort (news.begin (), news.end (), greater<Tweet> ());

        if (news.end () - news.begin () >= 10) {
            return vector<int> (news.begin (), news.begin () + 10);
        }
        else {
            return vector<int> (news.begin (), news.end ());
        }
    }

    void follow (int followerId, int followeeId)
    {
        if (followerId == followeeId) { return; }

        vector<Follower>::iterator follower = find (followers.begin (), followers.end (), followerId);

        if (follower != followers.end ()) {
            follower->add_followee (followeeId);
        }
        else {
            followers.push_back (Follower (followerId, followeeId));
        }
    }

    void unfollow (int followerId, int followeeId)
    {
        if (followerId == followeeId) { return; }

        vector<Follower>::iterator follower = find (followers.begin (), followers.end (), followerId);

        if (follower != followers.end ()) {
            follower->remove_followee (followeeId);
        }
    }

private:
    vector<Tweet> tweets;
    vector<Follower> followers;
};

int main ()
{
    Twitter twitter;
    vector<int> news;

    twitter.postTweet (1, 5);
    news = twitter.getNewsFeed (1);
    twitter.follow (1, 2);
    twitter.postTweet (2, 4);
    news = twitter.getNewsFeed (1);
    twitter.unfollow (1, 2);
    news = twitter.getNewsFeed (1);
}
