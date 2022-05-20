#ifndef __VISUAL_TESTS_HPP__
#define __VISUAL_TESTS_HPP__

#include "visualUtil.hpp"

inline void saveTestFigure(std::string title) { saveFigure("../tests_out/", title); }

void generateTests();

// point2D
void testPoint2D();
void testRotateVec2D();

// line2D
void testLine2D();
void testLine2DNormal();
void testLine2DFlip();

// square2D
void testSquare2D();
void testSquareRotate();
void testSquareBlock();
void testSquareShadowConcept();

// triangle2D
void testTriangle2D();
void testTriangleBlock();

// evenShape2D
void testEvenShape2D();
void testEvenShapeBlock();

#endif