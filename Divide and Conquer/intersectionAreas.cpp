#include <iostream>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

float cx, cy, cr;
float n, qx, qy, ql;

float c_x_min, c_x_max, c_y_min, c_y_max;

float intersecao(float x, float y, float l){

    float q_x_min, q_x_max, q_y_min, q_y_max;

    q_x_min = x;
    q_x_max = x + l;
    q_y_min = y;
    q_y_max = y + l;

    float top_right_x, top_right_y;
    float top_left_x, top_left_y;
    float bot_right_x, bot_right_y;

    top_right_x = x;
    top_right_y = y + l;

    top_left_x = x + l;
    top_left_y = y + l;

    bot_right_x = x + l;
    bot_right_y = y;

    float dis_top_r, dis_top_l, dis_bot_r, dis_bot_l;

    dis_top_r = sqrt(pow(abs(cx - top_right_x), 2) + pow(abs(cy - top_right_y), 2));
    dis_top_l = sqrt(pow(abs(cx - top_left_x), 2) + pow(abs(cy - top_left_y), 2));
    dis_bot_r = sqrt(pow(abs(cx - bot_right_x), 2) + pow(abs(cy - bot_right_y), 2));
    dis_bot_l = sqrt(pow(abs(cx - x), 2) + pow(abs(cy - y), 2));

    if(c_x_min >= q_x_min && c_x_max <= q_x_max && c_y_min >= q_y_min && c_y_max <= q_y_max){
        return(M_PI * pow(cr, 2));
    }
    else if(c_x_min >= q_x_max || c_x_max <= q_x_min || c_y_min >= q_y_max || c_y_max <= q_y_min){
        return 0;
    }
    else if(dis_top_r <= cr && dis_top_l <= cr && dis_bot_r <= cr && dis_bot_l <= cr){
        return(l*l);
    }

    float area = 0;

    if(l > 0.005){
        l /= 2;
        area += intersecao(x, y, l);
        area += intersecao(x+l, y, l);
        area += intersecao(x, y+l, l);
        area += intersecao(x+l, y+l, l);
    }

    return area;
}

int main(){

    cin >> n;

    for(int i=0;i<n;i++){
        cin >> qx >> qy >> ql >> cx >> cy >> cr;

        c_x_min = cx - cr;
        c_x_max = cx + cr;
        c_y_min = cy - cr;
        c_y_max = cy + cr;

        cout << intersecao( qx, qy, ql) << endl;
    }

    return 0;
}
