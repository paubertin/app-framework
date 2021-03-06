#pragma once

#include <core/App.h>
#include <core/Dimension.h>
#include <core/StreamFactory.h>

class BufferObject;
class ShaderProgram;

class Game : public App
{
public:
    Game(shared_ptr<StreamFactory> streamFactory);
    ~Game();

    void init(const Dimension& windowSize) override;
    void resume() override;
    void pause() override;
    void destroy() override;

    void render(float frameTime) override;

private:
    // OGL ES State
    shared_ptr<BufferObject> vertexBuffer;
    shared_ptr<BufferObject> indexBuffer;
    shared_ptr<ShaderProgram> shader;

    // App state
    float animationX;
    float animationStep;
};
