#ifndef _ZENOHSHAPEDYNAMICS_HPP
#define _ZENOHSHAPEDYNAMICS_HPP

/** @file */


#include <ShapeDynamics.hpp>
#include <QtCore/QRect>
#include <QtWidgets/QtWidgets>
#include <Shape.hpp>
// -- Shaped Include
#include "dds/dds.h"
#include "ishape.hpp"
#include "zenoh.hxx"
#include <vector>
#include<queue>
#include "org/eclipse/cyclonedds/topic/datatopic.hpp"


namespace demo { namespace ishapes {
#define CN 9


 typedef ::std::shared_ptr<Shape> SharedShape; 
 typedef ::std::weak_ptr<Shape> WeakSharedShape; 

/**
 * @addtogroup demos_iShapes
 */
/** @{*/

class ZenohShapeDynamics : public ShapeDynamics
{
public:
    enum
    {
        BLUE    = 0,
        RED     = 1,
        GREEN   = 2,
        ORANGE  = 3,
        YELLOW  = 4,
        MAGENTA = 5,
        CYAN    = 6,
        GRAY    = 7,
        BLACK   = 8
    };


public:
    ZenohShapeDynamics(
        int x0, int y0,
        std::shared_ptr<zenoh::Session> session,
        const std::string& keyExpression,
        const std::string& color,
        int colorIdx,
        bool dummy
    );

    int convert(const std::string& str);



    virtual ~ZenohShapeDynamics();

public:
     typedef ::std::shared_ptr<ZenohShapeDynamics> ref_type; 

public:

    void setShape(SharedShape shape)
    {
        shape_ = shape;
    }

    void setSession(std::shared_ptr<zenoh::Session> session)
    {
        session_ = std::move(session);
    }

    void setKeyExpression(const std::string& keyExpression);


    virtual void simulate();

private:
    WeakSharedShape shape_;
    int x0_;
    int y0_;
    std::string  keyexpr_;
    bool attached_;
    std::string color_;
    int colorIdx_;
    QColor  colorList_[CN];
    bool updateBounds_;
    bool dummy_;
    std::shared_ptr<zenoh::Session> session_;
    zenoh::Subscriber subscriber_;
};
}
}

/** @}*/

#endif	/* _ZENOHSHAPEDYNAMICS_HPP */
