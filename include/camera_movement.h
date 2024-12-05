#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <nlohmann/json.hpp>
#include <map>
#include <memory>

#include "utils.h"
#include "scroll_wheel.h"

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
    void Update() override;
    void FixedUpdate() override;
    void Draw() override;
};