#ifndef __MAP_PAINTER_CANVAS_H__
#define __MAP_PAINTER_CANVAS_H__

/*
  This source is part of the libosmscout library
  Copyright (C) 2010  Tim Teulings

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
*/

#include <osmscout/MapPainter.h>

namespace osmscout {

  class MapPainterCanvas : public osmscout::MapPainter
  {

  private:

    JNIEnv   *mJniEnv;
    jclass   mJavaClass;
    jobject  mObject;
    
    int GetColor(double r, double g, double b, double a);
  
  protected:

    bool HasIcon(const StyleConfig& styleConfig,
                 const MapParameter& parameter,
                 IconStyle& style);

    bool HasPattern(const MapParameter& parameter,
                    const FillStyle& style);

    void GetTextDimension(const MapParameter& parameter,
                          double fontSize,
                          const std::string& text,
                          double& xOff,
                          double& yOff,
                          double& width,
                          double& height);

    void DrawLabel(const Projection& projection,
                   const MapParameter& parameter,
                   const Label& label);

    void DrawPlateLabel(const Projection& projection,
                        const MapParameter& parameter,
                        const Label& label);

    void DrawContourLabel(const Projection& projection,
                          const MapParameter& parameter,
                          const LabelStyle& style,
                          const std::string& text,
                          size_t transStart, size_t transEnd);

    void DrawSymbol(const SymbolStyle* style,
                    double x, double y);

    void DrawIcon(const IconStyle* style,
                  double x, double y);

    void DrawPath(const Projection& projection,
                  const MapParameter& parameter,
                  double r, double g, double b, double a,
                  double width,
                  const std::vector<double>& dash,
                  CapStyle startCap,
                  CapStyle endCap,
                  size_t transStart, size_t transEnd);

    void DrawArea(const Projection& projection,
                  const MapParameter& parameter,
                  const AreaData& area);

    void DrawArea(const FillStyle& style,
                  const MapParameter& parameter,
                  double x,
                  double y,
                  double width,
                  double height);

  public:
    MapPainterCanvas();
    virtual ~MapPainterCanvas();

    bool DrawMap(const StyleConfig& styleConfig,
                 const Projection& projection,
                 const MapParameter& parameter,
                 const MapData& data,
                 JNIEnv *env,
                 jobject object);
  };
}

#endif	// __MAP_PAINTER_CANVAS_H__

