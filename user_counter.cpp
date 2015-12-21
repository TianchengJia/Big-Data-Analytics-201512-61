//
//  counter.cpp
//  bigdata_final
//
//  Created by Justin on 12/13/15.
//  Copyright © 2015 Tiancheng Jia. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

int main() {
    for (int group=0;group<11;group++) {
        stringstream ss; string grouplabel;
        ss<<group; ss>>grouplabel;
    ifstream group0("/Users/justin/OneDrive/COURSES 2015 Fall/BIG DATA ANALYTICS/final/yahoo_movie/ratinggroup"+grouplabel+".txt");
    ofstream top0("/Users/justin/OneDrive/COURSES 2015 Fall/BIG DATA ANALYTICS/final/yahoo_movie/top10group"+grouplabel+".txt");
    
    map<int, int> counter;
    map<int, int>::iterator it;
    int top[10];
    int userid; int movieid; int rating;
    while (1) {
        group0>>userid>>movieid>>rating;
        if (!group0) break;
        it = counter.find(movieid);
        if (it != counter.end()) {
            int count=it->second+1;
            counter.erase(it);
            counter.insert(pair<int, int>(movieid,count));
        }
        else counter.insert(pair<int, int>(movieid,1));
    }
    
    for (int i=0;i<10;++i) {
        int count=0;
        for (auto itr=counter.begin();itr!=counter.end();++itr) {
            if (count<itr->second) {
                count=itr->second;
                top[i]=itr->first;
            }
        }
        counter.erase(top[i]);
    }
    
    for (int i=0;i<10;++i) {top0<<top[i]<<endl;}
    }
    return 0;
}