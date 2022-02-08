/****************************************************
 * 2016-2022 Eric Bachmann and Mike Zmuda
 * All Rights Reserved.
 * NOTICE:
 * Dissemination of this information or reproduction
 * of this material is prohibited unless prior written
 * permission is granted.
 ****************************************************/

#include <ctime>
#include <vector>
#include "defs.h"
#include "utilities.h"
#include "framebuffer.h"
#include "colorandmaterials.h"
#include "rasterization.h"
#include "io.h"

FrameBuffer frameBuffer(WINDOW_WIDTH, WINDOW_HEIGHT);

void render() {
	frameBuffer.clearColorBuffer();
	drawLine(frameBuffer, 0, 0, 100, 100, red);
	drawLine(frameBuffer, 100, 100, 200, 100, blue);
	frameBuffer.showColorBuffer();
}

void resize(int width, int height) {
	frameBuffer.setFrameBufferSize(width, height);
	glutPostRedisplay();
}
int main(int argc, char* argv[]) {
	/*graphicsInit(argc, argv, __FILE__);

	glutDisplayFunc(render);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyboardUtility);
	glutMouseFunc(mouseUtility);

	frameBuffer.setClearColor(paleGreen);

	glutMainLoop();

	return 0;*/

	// Swap Testing
	cout << "Swap Testing" << endl;
	double j = 0;
	double k = 28;
	cout << j << endl; // ----> 0
	cout << k << endl; // ----> 28
	swap(j, k);
	cout << j << endl; // ----> 28
	cout << k << endl; // ----> 0
	cout << "" << endl;

	// Approximately Equal Testing
	cout << "Approximately Equal Testing" << endl;
	cout << approximatelyEqual(3.000000, 3.0000000001) << endl; // ------> 1 I.E. True
	cout << approximatelyEqual(3.000000, 3.1) << endl; // ------> 0 I.E. False
	cout << "" << endl;

	// Approximately Zero Testing
	cout << "Approximately Zero Testing" << endl;
	cout << approximatelyZero(0.0000001) << endl; // ------> 1 I.E. True
	cout << approximatelyZero(0.1) << endl; // -------> 0 I.E. False
	cout << "" << endl;

	// Normalize Degrees Testing
	cout << "Normalize Degrees Testing" << endl;
	cout << normalizeDegrees(0) << endl; // ------> 0
	cout << normalizeDegrees(1.75) << endl; // ------> 1.75
	cout << normalizeDegrees(-1) << endl; // --------> 359
	cout << normalizeDegrees(-721) << endl; // -------> 359
	cout << "" << endl;

	// Normalize Radians Testing
	cout << "Normalize Radians Testing" << endl;
	cout << normalizeRadians(0) << endl; // ------> 0
	cout << normalizeRadians(1) << endl; // ------> 1
	cout << normalizeRadians(3 * PI) << endl; // --------> 3.141
	cout << normalizeRadians(- 31 * PI) << endl; // -------> 3.141
	cout << "" << endl;

	// Radians to Degrees (rad2deg)
	cout << "Radians to Degrees Testing (rad2deg)" << endl;
	cout << rad2deg(0) << endl; // -----> 0
	cout << rad2deg(2 * PI) << endl; // -----> 360
	cout << rad2deg(PI) << endl; // ------> 180
	cout << rad2deg(3 * PI) << endl; // -----> 540
	cout << "" << endl;

	// Degrees to Radians
	cout << "Degrees to Radians Testing (deg2rad)" << endl;
	cout << deg2rad(0) << endl; // -----> 0
	cout << deg2rad(180) << endl; // -----> PI
	cout << deg2rad(360) << endl; // -----> 2 * PI
	cout << "" << endl;

	// Minimum
	cout << "Minimum Testing" << endl;
	cout << min(1, 2, 3) << endl; // -----> 1
	cout << min(-1, 0, 2) << endl; // -----> -1
	cout << min(20, 9, 100) << endl; // ------> 9
	cout << min(10, 8, 6) << endl; // -------> 6
	cout << "" << endl;

	// Maximum
	cout << "Maximum Testing" << endl;
	cout << max(1, 2, 3) << endl; // -----> 3
	cout << max(-1, 0, 2) << endl; // -----> 2
	cout << max(20, 9, 100) << endl; // ------> 100
	cout << max(10, 8, 6) << endl; // -------> 10
	cout << "" << endl;

	// Distance from Origin
	cout << "Distance from Origin Testing" << endl;
	cout << distanceFromOrigin(0, 1) << endl; // --> 1.0
	cout << distanceFromOrigin(1, 0) << endl; // --> 1.0
	cout << distanceFromOrigin(1, 1) << endl; // --> 1.41421356237309514547
	cout << distanceFromOrigin(-10, 30) << endl; // --> 31.62277660168379256334
	cout << "" << endl;

	// Distance between
	cout << "Distance Between Testing" << endl;
	cout << distanceBetween(0, 0, 1, 1) << endl; // -- > 1.41421356237309514547
	cout << distanceBetween(1, 1, 0, 0) << endl; // -- > 1.41421356237309514547
	cout << distanceBetween(10, 10, 11, 11) << endl; // -- > 1.41421356237309514547
	cout << distanceBetween(100, 100, 99, 99) << endl; // -- > 1.41421356237309514547
	cout << distanceBetween(54, 1, -34, -99) << endl; // -- > 133.2066064427737
	cout << "" << endl;

	// Area of Triangle (three inputs)
	cout << "Area of Triangle Testing" << endl;
	cout << areaOfTriangle(3, 4, 5) << endl; // ---> 6
	cout << areaOfTriangle(-3, 4, 5) << endl; // ---> -1
	cout << areaOfTriangle(3, 4, 50) << endl; // ----> -1
	cout << "" << endl;

	// Area of Triangle (six inputs)
	cout << "Area of Triangle Testing" << endl;
	cout << areaOfTriangle(0, 0, 3, 0, 0, 4) << endl; // ----> 6
	cout << "" << endl;
	
	// Point on Unit Circle Testing
	cout << "Point on Unit Circle Testing" << endl;
	double x, y;
	pointOnUnitCircle(2 * PI, x, y);
	cout << x << " " << y << endl;

	cout << "Point on Circle Testing" << endl;
	cout << pointOnCircle(dvec2(1, -1), 2.0, PI_2) << endl;
	cout << "" << endl;

	cout << "Direction in Radians Testing 1" << endl;
	cout << directionInRadians(dvec2(0, 0), dvec2(2, 2)) << endl;  //-- > 0.7853981634
	cout << directionInRadians(dvec2(0, 0), dvec2(-2, 2)) << endl; // -- > 
	cout << directionInRadians(dvec2(0, 0), dvec2(-2, -2)) << endl;
	cout << directionInRadians(dvec2(2, 10), dvec2(3, 11)) << endl; //-- > 0.7853981634
	cout << directionInRadians(dvec2(2, 2), dvec2(2, 0)) << endl; //-- > 4.7123889804
	cout << "" << endl;

	cout << "Direction in Radians Testing 2" << endl;
	cout << directionInRadians(dvec2(2, 2)) << endl;
	cout << directionInRadians(dvec2(0, -2)) << endl;
	cout << "" << endl;

	cout << "Direction in Radians Testing 3" << endl;
	cout << directionInRadians(0, 0, 2, 2) << endl;
	cout << directionInRadians(2, 10, 3, 11) << endl;
	cout << directionInRadians(2, 2, 2, 0) << endl;
	cout << "" << endl;
	
	// directionInRadians((2,2), (2,0))
	double p = 0 - 2;
	double l = 2 - 2;
	// directionInRadians((1,-1), (1.3420, -1.93969))

	// (2,2), (2,0)
	// (0, -2)

	//directionInRadians((0, -2)

}