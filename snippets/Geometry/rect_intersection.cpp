//check if intersection is possible without !out_of_bounds. Box is bounding box.

//2D Coordinate Plane up x = left/right
auto intersection = [&](vt<pr<int, int>>& box, vt<pr<int, int>> new_box) {
    cmax(box[0].f, new_box[0].f);
    cmin(box[1].f, new_box[1].f);
    cmin(box[0].s, new_box[0].s);
    cmax(box[1].s, new_box[1].s);
};

//C++ Plane, X = down/up(rows). Top left is (-INF, -INF), bottom right is (INF, INF)
auto intersection = [&](vt<pr<int, int>>& box, vt<pr<int, int>> new_box) {
        cmax(box[0].f, new_box[0].f);
        cmin(box[1].f, new_box[1].f);
        cmax(box[0].s, new_box[0].s);
        cmin(box[1].s, new_box[1].s);
};

