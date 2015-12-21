//
//  main.cpp
//  bigdata_final
//
//  Created by Justin on 12/12/15.
//  Copyright © 2015 Tiancheng Jia. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    ifstream userinfo("/Users/justin/OneDrive/COURSES 2015 Fall/BIG DATA ANALYTICS/final/yahoo_movie/ydata-ymovies-user-demographics-v1_0.txt");
    
    ofstream out0("/Users/justin/OneDrive/COURSES 2015 Fall/BIG DATA ANALYTICS/final/yahoo_movie/usergroup0.txt");
    ofstream out1("/Users/justin/OneDrive/COURSES 2015 Fall/BIG DATA ANALYTICS/final/yahoo_movie/usergroup1.txt");
    ofstream out2("/Users/justin/OneDrive/COURSES 2015 Fall/BIG DATA ANALYTICS/final/yahoo_movie/usergroup2.txt");
    ofstream out3("/Users/justin/OneDrive/COURSES 2015 Fall/BIG DATA ANALYTICS/final/yahoo_movie/usergroup3.txt");
    ofstream out4("/Users/justin/OneDrive/COURSES 2015 Fall/BIG DATA ANALYTICS/final/yahoo_movie/usergroup4.txt");
    ofstream out5("/Users/justin/OneDrive/COURSES 2015 Fall/BIG DATA ANALYTICS/final/yahoo_movie/usergroup5.txt");
    ofstream out6("/Users/justin/OneDrive/COURSES 2015 Fall/BIG DATA ANALYTICS/final/yahoo_movie/usergroup6.txt");
    ofstream out7("/Users/justin/OneDrive/COURSES 2015 Fall/BIG DATA ANALYTICS/final/yahoo_movie/usergroup7.txt");
    ofstream out8("/Users/justin/OneDrive/COURSES 2015 Fall/BIG DATA ANALYTICS/final/yahoo_movie/usergroup8.txt");
    ofstream out9("/Users/justin/OneDrive/COURSES 2015 Fall/BIG DATA ANALYTICS/final/yahoo_movie/usergroup9.txt");
    ofstream outundef("/Users/justin/OneDrive/COURSES 2015 Fall/BIG DATA ANALYTICS/final/yahoo_movie/usergroupundef.txt");
    ofstream usergroup("/Users/justin/OneDrive/COURSES 2015 Fall/BIG DATA ANALYTICS/final/yahoo_movie/usergroup.txt");
    
    int id; string birth; string gender; int userlabel[8000];
    for (int i=0;i<8000;i++) userlabel[i]=-2;   //the user's group label
    while (1) {
        if (!userinfo) break;
        int flag;
        userinfo>>id>>birth>>gender;
        if (birth=="undef" || birth=="0") {flag=-1;}
        else {
            stringstream ss;
            ss<<birth; ss>>flag;
            if (flag<1900) flag=0;
            else {flag=(flag-1900)/10; ss.clear();}
        }
        userlabel[id]=flag;
        usergroup<<id<<","<<userlabel[id]<<endl;
        switch (flag) {
            case -1: outundef<<id<<","<<birth<<endl; break;
            case 1: out1<<id<<","<<birth<<endl; break;
            case 2: out2<<id<<","<<birth<<endl; break;
            case 3: out3<<id<<","<<birth<<endl; break;
            case 4: out4<<id<<","<<birth<<endl; break;
            case 5: out5<<id<<","<<birth<<endl; break;
            case 6: out6<<id<<","<<birth<<endl; break;
            case 7: out7<<id<<","<<birth<<endl; break;
            case 8: out8<<id<<","<<birth<<endl; break;
            case 9: out9<<id<<","<<birth<<endl; break;
            case 0: out0<<id<<","<<birth<<endl; break;
        }
    }
    
    //ifstream ratings("/Users/justin/OneDrive/COURSES 2015 Fall/BIG DATA ANALYTICS/final/yahoo_movie/ydata-ymovies-user-movie-ratings-train-v1_0.txt");
    ifstream ratings("/Users/justin/OneDrive/COURSES 2015 Fall/BIG DATA ANALYTICS/final/yahoo_movie/alldata.txt");
    ofstream rating0("/Users/justin/OneDrive/COURSES 2015 Fall/BIG DATA ANALYTICS/final/yahoo_movie/ratinggroup0.txt");
    ofstream rating1("/Users/justin/OneDrive/COURSES 2015 Fall/BIG DATA ANALYTICS/final/yahoo_movie/ratinggroup1.txt");
    ofstream rating2("/Users/justin/OneDrive/COURSES 2015 Fall/BIG DATA ANALYTICS/final/yahoo_movie/ratinggroup2.txt");
    ofstream rating3("/Users/justin/OneDrive/COURSES 2015 Fall/BIG DATA ANALYTICS/final/yahoo_movie/ratinggroup3.txt");
    ofstream rating4("/Users/justin/OneDrive/COURSES 2015 Fall/BIG DATA ANALYTICS/final/yahoo_movie/ratinggroup4.txt");
    ofstream rating5("/Users/justin/OneDrive/COURSES 2015 Fall/BIG DATA ANALYTICS/final/yahoo_movie/ratinggroup5.txt");
    ofstream rating6("/Users/justin/OneDrive/COURSES 2015 Fall/BIG DATA ANALYTICS/final/yahoo_movie/ratinggroup6.txt");
    ofstream rating7("/Users/justin/OneDrive/COURSES 2015 Fall/BIG DATA ANALYTICS/final/yahoo_movie/ratinggroup7.txt");
    ofstream rating8("/Users/justin/OneDrive/COURSES 2015 Fall/BIG DATA ANALYTICS/final/yahoo_movie/ratinggroup8.txt");
    ofstream rating9("/Users/justin/OneDrive/COURSES 2015 Fall/BIG DATA ANALYTICS/final/yahoo_movie/ratinggroup9.txt");
    ofstream ratingall("/Users/justin/OneDrive/COURSES 2015 Fall/BIG DATA ANALYTICS/final/yahoo_movie/ratingall.txt");
    ofstream ratingundef("/Users/justin/OneDrive/COURSES 2015 Fall/BIG DATA ANALYTICS/final/yahoo_movie/ratinggroup10.txt");
    ofstream rating678("/Users/justin/OneDrive/COURSES 2015 Fall/BIG DATA ANALYTICS/final/yahoo_movie/ratinggroup678.txt");
    int userid; int movieid; int r13; int r5;
    while (1) {
        if (!ratings) break;
        int label;
        ratings>>userid>>movieid>>r13>>r5;
        ratingall<<userid<<","<<movieid<<","<<r13<<endl;
        label=userlabel[userid];
        switch (label) {
            case -1: ratingundef<<userid<<","<<movieid<<","<<r5<<endl; break;
            case 1: rating1<<userid<<","<<movieid<<","<<r5<<endl; break;
            case 2: rating2<<userid<<","<<movieid<<","<<r5<<endl; break;
            case 3: rating3<<userid<<","<<movieid<<","<<r5<<endl; break;
            case 4: rating4<<userid<<","<<movieid<<","<<r5<<endl; break;
            case 5: rating5<<userid<<","<<movieid<<","<<r5<<endl; break;
            case 6: rating6<<userid<<","<<movieid<<","<<r5<<endl; break;
            case 7: rating7<<userid<<","<<movieid<<","<<r5<<endl; break;
            case 8: rating8<<userid<<","<<movieid<<","<<r13<<endl; break;
            case 9: rating9<<userid<<","<<movieid<<","<<r5<<endl; break;
            case 0: rating0<<userid<<","<<movieid<<","<<r5<<endl; break;
        }
    }
    
    return 0;
}
