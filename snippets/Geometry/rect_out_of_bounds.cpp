
//2D Coordinate Plane up x = left/right
auto out_of_bounds = [&](vt<pr<int, int>> rect1, vt<pr<int, int>> rect2) -> bool {
        return (rect1[1].f < rect2[0].f || rect1[0].f > rect2[1].f || rect1[1].s > rect2[0].s || rect1[0].s < rect2[1].s);
};

//C++ Plane, X = down/up(rows). Top left is (-INF, -INF), bottom right is (INF, INF)
auto out_of_bounds = [&](vt<pr<int, int>> rect1, vt<pr<int, int>> rect2) -> bool {
       
        bool b1 = rect1[1].f < rect2[0].f;
        bool b2 = rect1[0].f > rect2[1].f;
        bool b3 = rect1[1].s < rect2[0].s;
        bool b4 = rect1[0].s > rect2[1].s;

        return (b1 || b2 || b3 || b4 );
};