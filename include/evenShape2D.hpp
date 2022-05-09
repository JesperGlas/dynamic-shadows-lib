#ifndef __EVENSHAPE2D_HPP__
#define __EVENSHAPE2D_HPP__

#include "shape2D.hpp"

namespace ds
{

class evenShape2D : public shape2D
{
public:
    evenShape2D(const point2D center, const float radius, const size_t size);
    ~evenShape2D() {}

    /**
     * @brief Get the Blocking Edge object using a mathematical method
     * 
     * @param ls lightsource [point2D]
     * @return line2D 
     */
    line2D getBlockingEdge(const point2D &ls) const;

    /**
     * @brief Get the Blocking Edge object using naive method
     * 
     * @param ls lightsource [point2D]
     * @return line2D 
     */
    line2D getBlockingEdgeNaive(const point2D &ls) const;

}; // evenShape2D

} // namespace ds

#endif