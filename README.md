# iShapes Demonstrator 
[TOC]

# What is it? 
iShapes is an interactive GUI based Zenoh (Zero Network Overhead) Application to learn, demonstate and test Zenoh key concepts.

It shows and demonstrates the key Zenoh concepts.
It has also been used at the Eclipse Foundation to test the interoperability of the Zettascale products.

Each geometrical shape is represented by a dedicated key expression


The shape dataType is characterized by its color, its position in a 2D space and its Size. 
Shapes with different colors are considered different data objects, i,e different data instances, as the color data attribute is considered the @Key of the dataType. Each data instance has its unique identity, its own lifecycle and its state.


# Building iShapes

ishapes can be rely on Zenoh C++ API, 

For the Zenoh Ishape demo, the Zenoh C core, Zenoh C++ binding for Zenoh need to be installed before proceeding.   
You can get Zenog C Core from https://github.com/eclipse-zenoh/zenoh-c  , t and the related C++ APIs from hhttps://github.com/eclipse-zenoh/zenoh-cpp



To clone the ishape demo application in your locale repository, do  

      $ git clone https://github.com/atolab/dds-ishapes   
      $ cd Adlink_DDS_Demo_Ishapes   


## Building Cyclone DDS iShapes

From now one, we assume Cylone DDS or Vortex Opensplice and QT5 are installed

### Building on Linux/MacOS with cmake
To build the iShapes demo you need to have installed a QT5 development environment. The following QT5 environment variables has to be set in order to build and run ishapes:
      
      $ export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:<qt5_install-location>
      
       Where <qt5_install-location> is the installation directory of your QT5 installation , e.g (/usr/lib/x86_64_linux-gnu/qt5)  

then you need to simply do the following from the iShape demo root directory:

      $ mkdir cyclone_demo_ishapes && cd cyclone_demo_ishapes  
      $ cmake .. -DADLINK_DDS_PRODUCT=Cyclone -DCYCLONE_INSTALLED_DIR="<cxx_install-location>"  
      $ cmake --build . --config Release --target install  
      
      Where <cxx_install-location> is the location of Cyclone DDS C++ package  
      
     Note: please use '--config Debug' if you are using Cyclone DDS debug build to build this iShape application.

### Building on Windows with cmake
To build the demo you need to have installed a QT5 development environment. The following QT5 environment variables has to be set in order to build and run ishapes:

      C:\> set QTDIR=<QT5-INSTALLATION-DIR> 
      C:\> set QT_PLUGIN_PATH=<QT5-INSTALLATION-DIR>\plugins  
      C:\> set PATH=<QT5-INSTALLATION-DIR>\bin;%PATH%   
      
      Where <QT5-INSTALLATION-DIR> is the installation directory of your QT5 installation , e.g (<C:\Qt\5.7.1> )  

then you need to simply do the following from the iShape demo root directory:

      $ mkdir cyclone_demo_ishapes && cd cyclone_demo_ishapes  
      $ cmake .. -DADLINK_DDS_PRODUCT=Cyclone -DCYCLONE_INSTALLED_DIR="<cxx_install-location>"  -G "<generator-name>"
      $ cmake --build . --config Release --target install  
      
Where ``<cxx_install-location>`` is the location of the Cyclone DDS C++ package and ``<generator-name>`` by one of the ways CMake [generators](https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html)
offer for generating build files. For  example, "Visual Studio 15 2017 Win64" would target a 64-bit build using Visual Studio 2017.  
      
Note: please use '--config Debug' if you are using Cyclone DDS debug build to build this iShape application.

## Building Opensplice DDS iShapes

### Building on Linux/MacOS with cmake

To build the iShapes demo you need to have installed a QT5 development environment. The following QT5 environment variables has to be set in order to build and run ishapes:
      
      $ export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:<qt5_install-location>
      
       Where <qt5_install-location> is the installation directory of your QT5 installation , e.g (/usr/lib/x86_64_linux-gnu/qt5)  

then you need to simply do the following from the iShape demo root directory:

      $ source <ospl_install-location>/release.com  
      $ mkdir ospl_demo_ishapes && cd ospl_demo_ishapes  
      $ cmake .. -DADLINK_DDS_PRODUCT=Ospl  
      $ cmake --build . --config Release --target install  
      
      Where <ospl_install-location> is the location of Opensplice DDS Home directory.e. The corresponding Opensplice environment variable is OSPL_HOME. 
      
      Note: please use '--config Debug' if you are using Opensplice DDS debug build to build this iShape application.
  
### Building on Windows with cmake
To build the demo you need to have installed a QT5 development environment.  The following QT5 environment variables has to be set in order to build and run ishapes:

      C:\> set QTDIR=<QT5-INSTALLATION-DIR> 
      C:\> set QT_PLUGIN_PATH=<QT5-INSTALLATION-DIR>\plugins  
      C:\> set PATH=<QT5-INSTALLATION-DIR>\bin;%PATH%  
      C:\> "<ospl_install-location>"\release.bat  
      
      Where is the installation directory of your QT5 installation , e.g (<C:\Qt\5.7.1> )  

then you need to simply do the following from the iShape demo root directory:

      $ "<ospl_install-location>"\release.bat  
      $ mkdir ospl_demo_ishapes && cd ospl_demo_ishapes  
      $ cmake .. -DADLINK_DDS_PRODUCT=Ospl -G "<generator-name>"
      $ cmake --build . --config Release --target install  
      
 Where ``<ospl_install-location>`` is the location of Opensplice DDS Home directory and ``<generator-name>`` by one of the ways CMake [generators](https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html) offer for generating build files. For example, "Visual Studio 15 2017 Win64" would target a 64-bit build  using Visual Studio 2017.
      
Note: please use '--config Debug' if you are using Opensplice DDS debug build to build this iShape application.
      

# Running iShapes

The iShapes demo allows you to publish and subscribe instances of various shapes. The demo is didactic if you run it as at least into two application instances, thus from a shell do one of the below then have one of the applications publish some shapes and press the subscribe button on the other application to receive them.

image-20201022104103958

## Running Cyclone DDS iShapes
### Linux/MacOS:

To build the iShapes demo you need to have set the Cyclone DDS lib to the LD_LIBRARY_PATH. The following Cyclone environment variables has to be set in order to run ishapes:
      

      $ export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:<cxx_install-location>/lib
  
      Where <cxx_install-location> is the location of Cyclone DDS C++ package. 


cyclone_demo_ishapes is intalled in the <cxx_install-location>/bin directory of Cyclone installation. To run it  you  need to simply do the following:

      $ <cxx_install-location>/bin/cyclone_demo_ishapes &  
      $ <cxx_install-location>/bin/cyclone_demo_ishapes &  
  
Where <cxx_install-location> is the location of Cyclone DDS C++ package  
      
Note: You can pass DDS domain id and partition(s) as command line arguments to start cyclone_demo_ishapes in a particular DDS domain and start publication and subscription in particular partition(s). for example to start cyclone_demo_ishapes application in domain 1 and publish and subscribe topic(s) in "Partition-1" and "Partition-2"
      
      $ <cxx_install-location>/bin/cyclone_demo_ishapes 1 Partition-1 Partition-2 &
      $ <cxx_install-location>/bin/cyclone_demo_ishapes 1 Partition-1 Partition-2 &

### Windows:
cyclone_demo_ishapes is intalled in <cxx_install-location>/bin directory of Eclipse Cyclone installation. To run it  you need to simply do the following:  
      
      C:\> start <cxx_install-location>\bin\cyclone_demo_ishapes  
      C:\> start <cxx_install-location>\bin\cyclone_demo_ishapes  
  
Where <cxx_install-location> is the location of Cyclone DDS C++ package  
      
Note: You can pass DDS domain id and partition(s) as command line arguments to start cyclone_demo_ishapes in a particular DDS domain and start publication and subscription in particular partition(s). for example to start cyclone_demo_ishapes application in domain 1 and publish and subscribe topic(s) in "Partition-1" and "Partition-2"
      
      C:\> start <cxx_install-location>\bin\cyclone_demo_ishapes 1 Partition-1 Partition-2
      C:\> start <cxx_install-location>\bin\cyclone_demo_ishapes 1 Partition-1 Partition-2

## Running Opensplice DDS iShapes
### Linux/MacOS:
ospl_demo_ishapes is available in <installation>/bin directory of Opensplice DDS installation directory. To run it you need to simply do the following: 

      $ source <ospl_install-location>/release.com
      $ <ospl_install-location>/bin/ospl_demo_ishapes &
      $ <ospl_install-location>/bin/ospl_demo_ishapes &
  
      Where <ospl_install-location> is the location of Opensplice DDS Home directory.
      
      Note: You can pass DDS domain id and partition(s) as command line arguments to start ospl_demo_ishapes in a particular DDS domain and start publication and       subscription in particular partition(s). for example to start ospl_demo_ishapes application in domain 1 and publish and subscribe topic(s) in "Partition-1"       and "Partition-2"
      
      $ <ospl_install-location>/bin/ospl_demo_ishapes 1 Partition-1 Partition-2 &
      $ <ospl_install-location>/bin/ospl_demo_ishapes 1 Partition-1 Partition-2 &

### Windows:
      $ "<ospl_install-location>"\release.bat 
      C:\> start <ospl_install-location>\bin\ospl_demo_ishapes  
      C:\> start <ospl_install-location>\bin\ospl_demo_ishapes  
      
      Where <ospl_install-location> is the location of Opensplice DDS Home directory.
      
      Note: You can pass DDS domain id and partition(s) as command line arguments to start ospl_demo_ishapes in a particular DDS domain and start publication and       subscription in particular partition(s). for example to start ospl_demo_ishapes application in domain 1 and publish and subscribe topic(s) in "Partition-1"       and "Partition-2"
      
      C:\> start <ospl_install-location>\bin\ospl_demo_ishapes 1 Partition-1 Partition-2
      C:\> start <ospl_install-location>\bin\ospl_demo_ishapes 1 Partition-1 Partition-2
