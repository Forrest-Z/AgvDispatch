﻿#ifndef MAPFLOOR_H
#define MAPFLOOR_H

#include <list>
#include "mappath.h"
#include "mapbackground.h"
#include "mappoint.h"

class OneMap;

class MapFloor : public MapSpirit
{
public:
    MapFloor(int _id, std::string _name);
    ~MapFloor();

    void addPoint(MapPoint *p){points.push_back(p);}
    void addPath(MapPath *p){paths.push_back(p);}
    void setBkg(MapBackground *b){if(bkg!=nullptr)delete bkg;bkg = b;}

    void removePoint(MapPoint *p){points.remove(p);}
    void removePath(MapPath *p){paths.remove(p);}
    void removeBkg(){if(bkg!=nullptr)delete bkg;bkg = nullptr;}

    //复制地图（深copy）
    MapFloor* clone() const;

    MapPoint *getPointById(int id) const;

    MapPath *getPathById (int id)  const;

    std::list<MapPoint *> getPoints() const {return points;}
    std::list<MapPath *> getPaths() const {return paths;}
    MapBackground *getBkg() const {return bkg;}

private:
    std::list<MapPoint *> points;///若干站点
    std::list<MapPath *> paths;///若干路径
    MapBackground *bkg;///一个背景图片
};

#endif // MAPFLOOR_H