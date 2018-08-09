// 백준 14503: 로봇 청소기
#include <iostream>

using namespace std;

enum { NORTH, EAST, SOUTH, WEST };

int main(){
    int map[51][51];
    int answer = 0;
    int height, width;
    int y, x;
    int dir;

    cin >> height >> width;
    cin >> y >> x >> dir;

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            cin >> map[i][j];
        }
    }
/* test case
    int map[12][11] = { {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                        {1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
                        {1, 0, 0, 1, 1, 0, 0, 0, 0, 1},
                        {1, 0, 1, 1, 0, 0, 0, 0, 0, 1},
                        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                        {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
                        {1, 0, 0, 0, 0, 0, 1, 1, 0, 1},
                        {1, 0, 0, 0, 0, 0, 1, 1, 0, 1},
                        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
                    };
    cout << endl;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
*/
    if(map[y][x] == 0){
        map[y][x] = 2;
        answer++;
    }

    while(true){
        dir--;
        if(dir == -1){
            dir = WEST;
        }

        if(dir == WEST) { x--; }
        else if(dir == SOUTH) { y++; }
        else if(dir == NORTH) { y--; }
        else if(dir == EAST) { x++; }

        if(map[y][x] == 0){
            map[y][x] = 2;
            answer++;
        }
        else{
            if(dir == WEST) { x++; }
            else if(dir == SOUTH) { y--; }
            else if(dir == NORTH) { y++; }
            else if(dir == EAST) { x--; }
        }

        if(map[y-1][x] > 0 && map[y+1][x] > 0 && map[y][x-1] > 0 && map[y][x+1] > 0){
            if(dir == WEST && map[y][x+1] == 1) { break;  }
            else if(dir == SOUTH && map[y-1][x] == 1) { break; }
            else if(dir == NORTH && map[y+1][x] == 1) { break; }
            else if(dir == EAST && map[y][x-1] == 1) { break; }
            else {
                if(dir == WEST) { x++; dir++; }
                else if(dir == SOUTH) { y--; dir++; }
                else if(dir == NORTH) { y++; dir++; }
                else if(dir == EAST) { x--; dir++; }
            }
        }
    }
/*
    cout << endl;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
*/
    cout << answer << endl;
/*
    cout << "y: " << y << endl;
    cout << "x: " << x << endl;
    cout << "dir: " << dir << endl;
    */
}
