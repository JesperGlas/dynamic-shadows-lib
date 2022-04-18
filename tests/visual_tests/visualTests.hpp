#ifndef __VISUAL_TESTS_HPP__
#define __VISUAL_TESTS_HPP__

#include "mathplotUtil.hpp" // Contains matplotlib header

std::string OUT_PATH = "../visual_out/";
std::string DOCS_PATH = "../../docs/";

void setupDefaultFigure();
void saveDefaultFigure(std::string title);
void saveFigure(std::string dir, std::string title);

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

// evenShape2D
void testEvenShape2D();
void testEvenShape2DBlock();


// Docs
void testSquareConceptDocs();


#endif