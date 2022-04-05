#ifndef __VISUAL_TESTS_HPP__
#define __VISUAL_TESTS_HPP__

#include "mathplotUtil.hpp" // Contains matplotlib header

std::string OUT_PATH = "../visual_out/";

// point2D
void testPoint2D();
void testRotateVec2D();

// line2D
void testLine2D();
void testLine2DNormal();
void testLine2DFlip();

// square2D
void testSquare2D();
void testSquareBlock();
void testSquareShadowConcept();

// triangle2D
void testTriangle2D();

#endif