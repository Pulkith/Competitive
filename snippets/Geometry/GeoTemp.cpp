#include<bits/stdc++.h>

using namespace std;

template<class T> struct GeoBook {
	
	bool intersection(vector<pair<T, T>>& box, vector<pair<T, T>> new_box) {
		if(out_of_bounds(box, new_box)) return 0;
		cmax(box[0].f, new_box[0].f);
    	cmin(box[1].f, new_box[1].f);
    	cmin(box[0].s, new_box[0].s);
    	cmax(box[1].s, new_box[1].s);
    	return 1;
	}

	bool out_of_bound(vector<pair<int, int>> rect1, vector<pair<int, int>> rect2) {
        return (rect1[1].f < rect2[0].f || 
        		rect1[0].f > rect2[1].f || 
        		rect1[1].s > rect2[0].s || 
        		rect1[0].s < rect2[1].s);
	}

};	