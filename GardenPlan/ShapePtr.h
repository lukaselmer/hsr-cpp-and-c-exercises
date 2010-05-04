/* 
 * File:   ShapePtr.h
 * Author: Lukas Elmer
 *
 * Created on 4. Mai 2010, 09:10
 */

#ifndef _SHAPEPTR_H
#define	_SHAPEPTR_H

#include "Shape.h"
#include <boost/shared_ptr.hpp>

typedef boost::shared_ptr<Shape> ShapePtr;

#endif	/* _SHAPEPTR_H */

