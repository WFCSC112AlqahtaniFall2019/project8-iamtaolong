//
// Created by Tao on 11/21/19.
//
#include <iostream>
#include <fstream>
#include "Data.h"
#include <string>
using namespace std;

//
// i use the data from the Kaggle, which is a dataset about Facebook users
// url: https://www.kaggle.com/sheenabatra/facebook-data
// This exploratory data analysis gives insights from Facebook dataset which consists of identifying users that can be
//     focused more to increase the business. These valuable insights should help Facebook to take intelligent decision to
//     identify its useful users and provide correct recommendations to them.
// This dataset contains 99903 entries with 15 columns.

//default constructor
Data :: Data() {

    // gender is a string
    gender = "";
    // age is an int
    age = 0;
    // friendscount is also an int
    friendsCount = 0;
    // likescount is an int
    likesReceivedCount = 0;

}


// alternative constructor
Data :: Data (string Agender, int Aage, int AfriendsCount, int AlikesReceivedCount) {

    // gender is a string
    gender = Agender;
    // age is an int
    age = Aage;
    // friendscount is also an int
    friendsCount = AfriendsCount;
    // likescount is an int
    likesReceivedCount = AlikesReceivedCount;

}

// > overloader
// overloads the comparison operators (< or >).
// You will choose at least one attribute from your data set to be the comparison attribute.
// friend operator
bool operator > (const Data &previousUser, const Data &FBUser) {

    // return bigger
    return previousUser.likesReceivedCount > FBUser.likesReceivedCount;
}


// > overloader
// overloads the comparison operators (< or >).
// You will choose at least one attribute from your data set to be the comparison attribute.
// friend operator
bool operator < (const Data &previousUser, const Data &FBUser) {

    return previousUser.likesReceivedCount < FBUser.likesReceivedCount;

    // return smaller
    /*if (this->likesReceivedCount > FBUser.likesReceivedCount) {
        return false;
    }

        // return smaller
    else if (this->likesReceivedCount < FBUser.likesReceivedCount) {
        return true;
    }

        // same return smaller
    else {
        return false;
    }*/
}


// Overloads the output stream operator
// This will be used by the Linked List class to print the contents of a Linked List class
ostream& operator << (ostream& os, const Data FBuser) {

// print out the contents
// print method for all message
    os << "User's age: " << FBuser.age;
    os << "\t\t,\t\t gender: " << FBuser.gender;
    os << "\t\t,\t\t num of FRIENDS: " << FBuser.friendsCount;
    os << "\t\t,\t\t num of LIKES ❤: " << FBuser.likesReceivedCount;
    return os;
}