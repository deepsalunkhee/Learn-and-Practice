#include<iostream>
#include <algorithm> // for min function
using namespace std;

int gcd(int x, int y) {
    if (y == 0)
        return x;
    else
        return gcd(y, x % y);
}

bool ispossible(int x, int y, int d) {
    int valgcd = gcd(x, y);
    if (d % valgcd == 0)
        return true;
    return false;
}

void fillx(int &xState, int &xcapacity) {
    xState = xcapacity;
}

void emptyy(int &yState, int ycapacity) {
    yState = 0;
}

void transfer_x_to_y(int &xState, int &yState, int &xcapacity, int &ycapacity) {
    int y_can_take = (ycapacity - yState);
    if (y_can_take >= xState) {
        yState = yState + xState;
        xState = 0;
    }
    else {
        xState = xState - y_can_take;
        yState = ycapacity;
    }
}

int pour(int fromCap, int toCap, int d) {
    int from = fromCap;
    int to = 0;
    int step = 1;

    while (from != d && to != d) {
        int temp = min(from, toCap - to);
        to += temp;
        from -= temp;
        step++;

        if (from == d || to == d)
            break;

        if (from == 0) {
            from = fromCap;
            step++;
        }

        if (to == toCap) {
            to = 0;
            step++;
        }
    }
    return step;
}

int minSteps(int m, int n, int d) {
    if (m > n)
        swap(m, n);

    if (d > n)
        return -1;

    if ((d % gcd(n, m)) != 0)
        return -1;

    return min(pour(n, m, d), pour(m, n, d));
}

int main() {
    int xcapacity, ycapacity, finalx;
    int xState = 0, yState = 0;
    bool possible = true;
    cout << "Enter capacity for first container" << endl;
    cin >> xcapacity;

    cout << "Enter capacity for second container" << endl;
    cin >> ycapacity;

    cout << "Enter Final state of first container" << endl;
    cin >> finalx;

    possible = ispossible(xcapacity, ycapacity, finalx);
    if (!possible) {
        cout << "Not possible" << endl;
        return 0;
    }

    int min_steps = minSteps(xcapacity, ycapacity, finalx);
    if (min_steps == -1) {
        cout << "Not possible" << endl;
        return 0;
    }

    cout << "Minimum number of steps required is " << min_steps << endl;

    cout<<"X"<<" "<<"Y"<<endl;
	
	while(xState!=finalx){
		if(xState==0){
			fillx(xState,xcapacity);
		}else if(yState==ycapacity){
			emptyy(yState,ycapacity);
		}else{
			transfer_x_to_y(xState,yState,xcapacity,ycapacity);
		}
		
		cout<<xState<<" "<<yState<<endl;
		if(xState==finalx ||  yState==finalx ){
			cout<<"congratulation"<<endl;
			return 0;
		}
		
	}

    return 0;
}
