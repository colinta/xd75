#pragma once

#include <Keyboard.h>
#include <Mechy/KeyPress.h>
#include <Mechy.h>

class WeirdKeyPress: public Plugin {
public:
    WeirdKeyPress();
    bool override(Event* event, Plugin* plugin);

protected:
    bool guiIsDown;
    bool ignoreNextGui;
};
