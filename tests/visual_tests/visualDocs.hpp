#ifndef __VISUAL_DOCS_HPP__
#define __VISUAL_DOCS_HPP__

#include "visualUtil.hpp"

inline void saveDocsFigure(std::string title) { saveFigure("../docs_out/", title); }

void generateDocs();

void docsSquare();
void docsSquarePerp();
void docsSquareDiag();
void docsSquareQuadrant();
void docsSquareStart();
void docsSquareBlock();

void docsCircleBlock();
void docsCircleZoom();
void docsCircleTangent();

void docsTriangle();
void docsTrianglePerp();
void docsTriangleDiag();
void docsTriangleQuadrant();

void docsEvenShape();
void docsEvenShapeLen();
void docsEvenShapeTangent();
void docsEvenShapeCheck();

#endif