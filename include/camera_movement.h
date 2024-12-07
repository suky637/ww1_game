#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <nlohmann/json.hpp>
#include <map>
#include <memory>

#include "engine.h"

class CameraMovement: public Script
{
    private:
    void ResetZoom(float* acc);
    public:
    float x;
    float y;
    CameraMovement();
    sf::View* view;
    float zoom;
    void Start() override;
    void Update(bool gui_hovered) override;
    void FixedUpdate() override;
    void Draw() override;
};