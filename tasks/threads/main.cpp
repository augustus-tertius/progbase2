#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <thread>
#include <mutex>

#include <progbase.h>
#include <progbase-cpp/console.h>

#include <graphics.h>

using namespace std;
using namespace progbase::console;

mutex m;

void DrawPentagon(Vec2D pentCenter, float K, ConsoleColor C);
void printRotatedPentagon(
	Vec2D consoleCenter, 
	double rotateRadius,
	double radius,
	double radians,
	double dir
	);
void DrawRectangle(int N, int M, Vec2D ConsoleCenter, Vec2D d, ConsoleColor Col);
void printRotatedRectangle(
	Vec2D consoleCenter, 
	double radians
	);

void clearLeft (void);
void clearRight (void);


void threadL(int& T) {
	Vec2D consoleCenter = (Vec2D){20, 12};
	double rotateRadius = 5;
	double radius = 5;
	int degrees = 0;
    double dir = -2;
	while (1) {
		m.lock();
		Console::setCursorAttribute(CursorAttributes::BG_DEFAULT);
		clearLeft();
		m.unlock();
		double radians = degrees * M_PI / 180.0;
		printRotatedPentagon(
			consoleCenter,
			rotateRadius,
			radius,
			radians,
			dir
		);
		degrees++;

        sleepMillis(T);
	}
}

void threadR(int& T) {

    Vec2D consoleCenter = (Vec2D){60, 12};
	double rotateRadius = 5;
	double radius = 5;
	int degrees = 0;
    double dir = -2;

	while (1) {
		m.lock();
		Console::setCursorAttribute(CursorAttributes::BG_DEFAULT);
		clearRight();
		m.unlock();
		double radians = degrees * M_PI / 180.0;
		printRotatedRectangle(
			consoleCenter,
			radians
		);
		degrees++;

        sleepMillis(T);
	}
}


int main(void) {

    pb::conHideCursor();
	int T1 = 10;
    int T2 = 15;

	thread t1(threadL, ref(T1));
    thread t2(threadR, ref(T2));
    
	char x;
	cin >> x;
    pb::conShowCursor();
	
	Console::reset();
    cout << endl << endl << endl << endl << endl << endl;
	
	return 0;
}

void DrawPentagon(Vec2D pentCenter, float K, ConsoleColor Col){
    float angle = sin(M_PI / 10);

    Vec2D rad = (Vec2D){0, 1};
    rad = Vec2D_normalize(rad);
    rad = Vec2D_multByNumber(rad, K);
    rad = Vec2D_rotate(rad, -2*M_PI/5);

    for (int i = 0; i < 5; i++){
        // рисуем сторону 
        Vec2D rotateRad = (Vec2D){1, 1};
        rotateRad = Vec2D_normalize(rotateRad);
        rotateRad = Vec2D_multByNumber(rotateRad, K);
        rotateRad = Vec2D_rotate(rad, M_PI*2 / 5);

        Vec2D p1 = Vec2D_add(pentCenter, rad);
        Vec2D p2 = Vec2D_add(pentCenter, rotateRad);

        Graphics_drawLine(NULL, p1, p2, Col);

        // переприсваиваем

        rad = rotateRad;
    }
}

void printRotatedPentagon(
	Vec2D consoleCenter, 
	double rotateRadius,
	double radius,
	double radians,
	double dir
	) {

	Vec2D rotateVector = (Vec2D){1, 1};
	rotateVector = Vec2D_normalize(rotateVector);
	rotateVector = Vec2D_multByNumber(rotateVector, rotateRadius);
	rotateVector = Vec2D_rotate(rotateVector, dir * radians);
	Vec2D penCent = Vec2D_add(consoleCenter, rotateVector);
	m.lock();
    DrawPentagon(penCent, 5, CursorAttributes::BG_MAGENTA);
	m.unlock();
}

void DrawRectangle(int N, int M, Vec2D ConsoleCenter, Vec2D d, ConsoleColor Col){

    Vec2D rotateRad = Vec2D_rotate(d, 2*atan(M/N));

    Graphics_drawLine(NULL, Vec2D_add(ConsoleCenter, d), Vec2D_add(ConsoleCenter, rotateRad), Col);
    d = rotateRad;

    rotateRad = Vec2D_rotate(d, M_PI - 2*atan(M/N));
    Graphics_drawLine(NULL, Vec2D_add(ConsoleCenter, d), Vec2D_add(ConsoleCenter, rotateRad), Col);
    d = rotateRad;

    rotateRad = Vec2D_rotate(d, 2*atan(M/N));
    Graphics_drawLine(NULL, Vec2D_add(ConsoleCenter, d), Vec2D_add(ConsoleCenter, rotateRad), Col);
    d = rotateRad;

    rotateRad = Vec2D_rotate(d, M_PI - 2*atan(M/N));
    Graphics_drawLine(NULL, Vec2D_add(ConsoleCenter, d), Vec2D_add(ConsoleCenter, rotateRad), Col);
    d = rotateRad;

}

void printRotatedRectangle(Vec2D consoleCenter, double radians) {
    int dir = 2;

    int M = 10;
    int N = 6;

	Vec2D rotateVector = (Vec2D){1, 1};
	rotateVector = Vec2D_normalize(rotateVector);
	rotateVector = Vec2D_multByNumber(rotateVector, sqrt(pow(N/2, 2) + pow(M/2, 2)));
	rotateVector = Vec2D_rotate(rotateVector, dir * radians);

	m.lock();
    DrawRectangle(N,  M, consoleCenter, rotateVector, CursorAttributes::BG_YELLOW);
	m.unlock();
}


void clearLeft (void) {
    // 40 x 24
    for(int i = 0; i <= 24; i ++){
        for(int j = 0; j <= 40; j ++){
            pb::conMove(i, j);
            cout << " ";
        }
    }
}

void clearRight (void) {
    for(int i = 0; i <= 24; i ++){
        for(int j = 40; j <= 80; j ++){
            pb::conMove(i, j);
            cout << " ";
        }
    }
}
