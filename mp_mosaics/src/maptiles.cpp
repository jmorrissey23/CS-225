/**
 * @file maptiles.cpp
 * Code for the maptiles function.
 */

#include <iostream>
#include <map>

#include "maptiles.h"

using namespace std;


Point<3> convertToXYZ(LUVAPixel pixel) {
    return Point<3>( pixel.l, pixel.u, pixel.v );
}

MosaicCanvas* mapTiles(SourceImage const& theSource,
                       vector<TileImage>& theTiles)
{
    /**
     * @todo Implement this function!
     */

    //make a tree of theTiles 
    vector<LUVAPixel> colors;
    for (size_t i = 0; i < theTiles.size(); i++) {
        colors.push_back(theTiles.at(i).getAverageColor());
    }
    vector<Point<3>> color_points;
    for (size_t i = 0; i < colors.size(); i++) {
        Point<3> point(colors.at(i).l, colors.at(i). u, colors.at(i).v);
        color_points.push_back(point);
    }
    KDTree<3> tree(color_points);
    MosaicCanvas* canvas = new MosaicCanvas(theSource.getRows(), theSource.getColumns());
    for (int i = 0; i < theSource.getRows(); i++) {
        for (int j = 0; j < theSource.getColumns(); j++) {
            Point<3> point(theSource.getRegionColor(i,j).l, theSource.getRegionColor(i,j).u, theSource.getRegionColor(i,j).v);
            Point<3> to_insert = tree.findNearestNeighbor(point);
            int index = 0;
            for (size_t k = 0; k < color_points.size(); k++) {
                if (to_insert == color_points.at(k)) {
                    index = k;
                }
            }
            TileImage* img = new TileImage(theTiles[index]);
            canvas->setTile(i, j, img);
        }
    }
    return canvas;
}

