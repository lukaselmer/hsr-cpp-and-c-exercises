/* 
 * File:   Cat.h
 * Author: Lukas Elmer
 *
 * Created on 9. August 2010, 01:02
 */

#ifndef CAT_H
#define	CAT_H

#include <boost/shared_ptr.hpp>
#include <string>

class Cat {
public:
    Cat(const std::string & s);
    std::string getName();
    void setName(const std::string & s);
private:
    boost::shared_ptr<class CatImplementation> pImpl;
};

#endif	/* CAT_H */

