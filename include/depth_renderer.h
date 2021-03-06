
#ifndef _DEPTH_RENDERER_H_
#define _DEPTH_RENDERER_H_

#include <Inventor/nodes/SoDepthBuffer.h>
#include <Inventor/nodes/SoSceneTexture2.h>
#include <sensor_msgs/image_encodings.h>
#include <Inventor/actions/SoGLRenderAction.h>
#include <Inventor/SoOffscreenRenderer.h>
#include <Inventor/Qt/SoQtRenderArea.h>
#include <Inventor/Qt/SoQt.h>
#include <Inventor/nodes/SoShaderObject.h>
#include <Inventor/nodes/SoShaderParameter.h>
#include <Inventor/nodes/SoShaderProgram.h>
#include <Inventor/nodes/SoVertexShader.h>
#include <Inventor/nodes/SoFragmentShader.h>
#include <Inventor/nodes/SoSeparator.h>
#include <Inventor/nodes/SoCamera.h>
#include <Inventor/nodes/SoPerspectiveCamera.h>
#include <Inventor/SbViewportRegion.h>

#include <ros/ros.h>
#include <ros/package.h>
#include <sensor_msgs/Image.h>


class DepthRenderer
{

public:
    DepthRenderer();
    ~DepthRenderer();

    void renderDepthImage(sensor_msgs::Image * img_ptr);


private:
    SoQtRenderArea *renderArea;
    SoGLRenderAction *glRend;
    SoOffscreenRenderer *myRenderer;
    SoVertexShader *vertexShader;
    SoFragmentShader *fragmentShader;
    SoShaderProgram *shaderProgram;
    SoSeparator *shaderSep;
    SoDepthBuffer * depthBuffer;
};

#endif
