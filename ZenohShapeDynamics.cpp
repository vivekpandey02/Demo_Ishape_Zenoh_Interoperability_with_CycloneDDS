/**
 * @file
 */
#include "ZenohShapeDynamics.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <thread>

#include "config.hpp"
#include <unistd.h>
#include <stdlib.h>
//include "ishape.hpp"



using namespace std;
using namespace zenoh;



namespace demo { namespace ishapes {


extern char* colorString_[];

//        sub_(nullptr),
ZenohShapeDynamics::ZenohShapeDynamics(int x0, int y0,
                                    std::shared_ptr<zenoh::Session> session,
                                    const std::string& keyExpression,
                                    const std::string& color,
                                    int colorIdx, bool dummy)
    :   ShapeDynamics(x0, y0, QRect(0, 0, 0, 0)),
        x0_(x0),
        y0_(y0),
        session_(std::move(session)),
        keyexpr_(keyExpression),
        attached_(false),
        color_(color),
        colorIdx_(colorIdx),
        updateBounds_(true),
        dummy_(dummy),
        subscriber_(nullptr)
{


    //        subscriber_(nullptr)
    colorList_[BLUE] = QColor(0x33, 0x66, 0x99);
    colorList_[RED] = QColor(0xCC, 0x33, 0x33);
    colorList_[GREEN] = QColor(0x99, 0xCC, 0x66);
    colorList_[ORANGE] = QColor(0xFF, 0x99, 0x33);
    colorList_[YELLOW] = QColor(0xFF, 0xFF, 0x66);
    colorList_[MAGENTA] = QColor(0xCC, 0x99, 0xCC);
    colorList_[CYAN] = QColor(0x99, 0xCC, 0xFF);
    colorList_[GRAY] = QColor(0x99, 0x99, 0x99);
    colorList_[BLACK] = QColor(0x33, 0x33, 0x33);


    zenoh::KeyExprView keyexpr1(keyExpression);

            QPoint tmp;
        plist_.erase(plist_.begin(), plist_.end());

        // Create a dummy when the subscribe button is clicked until the first sample arrives
        
        if(dummy_ == true)
        {
            SharedShape shape;
            if (shape = shape_.lock())
            {
                plist_.push_back(QPoint((IS_WIDTH/2)-10, (IS_HEIGHT/2)-10));
                QBrush brush = QBrush(QColor(0xd3, 0xd3, 0xd3), Qt::SolidPattern);
                shape->setBrush(brush);
                QRect bounds(0, 0, 90, 90);
            }
            
        }

   subscriber_= std::get<zenoh::Subscriber>(session_->declare_subscriber(keyexpr1,[&] (const Sample& sample)// Capturing object by reference
    {  
        
       // if (sample) {
       
    // Implementing Deserialize logic here
    	void* ptr= (void*)sample.get_payload().start;
	    size_t sz = sample.get_payload().len;
        ShapeType sT;
        if(deserialize_sample_from_buffer<ShapeType>(ptr, sz, sT, SDK_DATA))
        {
        	//std::cout<<"Deserialized Successfully: "<<std::endl;
        }

       // std::cout<<"received color: "<< sT.color()<<" shape Color: "<<color_<<std::endl;
            dummy_ = false;

            SharedShape shape;
            if (shape = shape_.lock())
            {
                int _colorIdx_ = convert(sT.color());
            if (strcmp(sT.color().c_str(), color_.c_str()) == 0)
            {     
                plist_.erase(plist_.begin(), plist_.end());      
                tmp.rx() = sT.x();
                tmp.ry() = sT.y();
                plist_.push_back(tmp);

                if (attached_ == false)
                {
                    std::cout<<"x: "<<sT.x()<<" , y: "<<sT.y()<<" , color: "<<sT.color()<<" , size: "<<sT.shapesize()<<std::endl;   
                    attached_ = true;
                    QBrush brush = QBrush(colorList_[_colorIdx_], Qt::SolidPattern);
                    shape->setBrush(brush);
                }
                QRect bounds(0, 0, sT.shapesize(), sT.shapesize());
                shape->setBounds(bounds);
           }
        }

    //}
}
)
);
}

void ZenohShapeDynamics::setKeyExpression(const std::string& keyExpression)
{
    keyexpr_ = keyExpression;
}


int ZenohShapeDynamics::convert(const std::string& str)
    {
    if(str == "BLUE") return 0;
    else if(str == "RED") return 1;
    else if(str == "GREEN") return 2;
    else if(str == "ORANGE") return 3;
    else if(str == "YELLOW") return 4;
    else if(str == "MAGENTA") return 5;
    else if(str == "CYAN") return 6;
    else if(str == "GRAY") return 7;
    else if(str == "BLACK") return 8;
    else
        return -1;
    }


ZenohShapeDynamics::~ZenohShapeDynamics()
{
}


void
ZenohShapeDynamics::simulate()
{
   // sub_.pull();
}
}}
