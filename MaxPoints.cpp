//
//  MaxPoints.cpp
//  leetcode
//
//  Created by witwolf on 4/29/15.
//  Copyright (c) 2015 witwolf. All rights reserved.
//



#include <vector>
#include <map>
#include <utility>
#include <cstdlib>
#include <iostream>
#include <set>


using namespace std;

/**
 * Definition for a point.
 */

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

ostream& operator<<(ostream &os,const Point& p){
    os << '(' << p.x << ',' << p.y << ')';
    return os;
}

bool operator<(const Point& p1,const Point &p2){
    if(p1.x < p2.x){
        return true;
    }else if(p1.x == p2.x){
        if(p1.y < p2.y){
            return true;
        }
    }
    return false;
}

int gcd(int a,int b){
    int _min = min(a,b);
    int _max = max(a,b);
    if(_min == 0){
        return _max;
    }
    int temp;
    while (_max % _min) {
        temp = _min;
        _min  = _max % _min;
        _max = temp;
    }
    return _min;
}

int gcd(int a,int b,int c){
    return gcd(gcd(a,b),c);
}

// ax + by + c = 0;
class Line{
public:
    Line(const Point& p1,Point &p2){
        // x = x0;
        if(p1.x == p2.x){
            a = 1;
            b = 0;
            c = - p1.x;
        }
        // y = y0
        if(p1.y == p2.y){
            a = 0 ;
            b = 1;
            c = -p1.y;
        }else{
            
            // (y1-y0)x + (x0-x1)y + (x1y0-x0y1) = 0
            a = p2.y - p1.y;
            b = p1.x - p2.x;
            c = p2.x*p1.y - p1.x*p2.y;
            // 化简
            // 1. a取正
            // 2. 约去最大公约数
            if(a < 0 ){
                a = -a ;
                b = -b ;
                c = -c ;
            }
            int _gcd = gcd(a,abs(b),abs(c));
            a /= _gcd;
            b /= _gcd;
            c /= _gcd;
        }
        
        
    }
    
    friend ostream& operator<<(ostream &os,const Line &l){
        os << "Line: a=" << l.a << ",b=" << l.b << ",c=" << l.c ;
        return os;
    }
    
    friend bool operator<(const Line &l1,const Line &l2){
        if(l1.a < l2.a){
            return true;
        }else if(l1.a == l2.a){
            if(l1.b < l2.b){
                return true;
            }else if(l1.b == l2.b){
                if(l1.c < l2.c){
                    return true;
                }
            }
        }
        return false;
    }
    
private:
    int a;
    int b;
    int c;
};


class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if(points.empty()){
            return 0;
        }
        vector<pair<Point,int> > ps = uniq(points);
        int max = ps[0].second;
        map<Line,pair<set<Point>,int>  > lines;
        map<Line,pair<set<Point>,int>  >::iterator it;
        for(int i = 0;i< ps.size();++i){
            pair<Point,int> &p1 = ps[i];
            for(int j = i+1;j<ps.size() ; ++j){
                pair<Point,int> &p2 = ps[j];
                Line l(p1.first,p2.first);
                it = lines.find(l);
                if(it != lines.end()){
                    set<Point> &s = it->second.first;
                    if(s.find(p2.first) == s.end()){
                        s.insert(p2.first);
                        it->second.second += p2.second;
                        if(it->second.second > max){
                            max = it->second.second;
                        }
                    }
                }else{
                    set<Point> s;
                    s.insert(p1.first);s.insert(p2.first);
                    lines[l] = make_pair(s, p1.second + p2.second);
                    if(p1.second + p2.second > max){
                        max = p1.second + p2.second;
                    }
                }
            }
        }
//        for(it=lines.begin();it!=lines.end();++it){
//            cout << it->first ;
//            pair<set<Point>,int>  p = it->second;
//            set<Point> s = p.first;
//            cout << " Points :";
//            copy(s.begin(),s.end(),ostream_iterator<Point>(cout," "));
//            cout << " Counts :" << p.second << endl;
//        }
        return max;
    }
    
    
private:
    vector<pair<Point,int> > uniq(vector<Point>& points){
        map<Point,int> m;
        for(vector<Point>::iterator it = points.begin(); it != points.end();++it){
            map<Point,int>::iterator iter = m.find(*it);
            if(iter!=m.end()){
                ++(iter->second);
            }else{
                m[*it] = 1;
            }
        }
        vector<pair<Point,int> >p;
        for(map<Point,int >::iterator it = m.begin();it!=m.end();++it){
            p.push_back(make_pair(it->first, it->second));
        }
        return p;
    }
};

int main(int argc,char **argv){
    Solution s;
    vector<Point> points;
    points.push_back(Point(0,0));
    points.push_back(Point(-1,-1));
    points.push_back(Point(2,2));
    points.push_back(Point(2,2));
    cout << s.maxPoints(points) << endl;
    
}