#include "WeirdKeyPress.h"
#include <Mechy/Sticky.h>


WeirdKeyPress::WeirdKeyPress() {
    guiIsDown = false;
    ignoreNextGui = false;
}

bool WeirdKeyPress::override(Event* event, Plugin* plugin) {
    if (event->isHeld()) { return KBD_CONTINUE; }

    if (guiIsDown && plugin->is(EVENT_KEYPRESS, event) && event->key() == 't') {
        ignoreNextGui = (event->isPressed() || event->isReleased());
    }

    if (plugin->is(EVENT_MODIFIER, event) && event->isPressed()
        && (
            event->key() == KEY_LEFT_GUI
            || event->key() == KEY_RIGHT_GUI
            || event->key() == STK_GUI
        )
    )
    {
        if (ignoreNextGui) {
            ignoreNextGui = false;
            return KBD_HALT;
        }
        guiIsDown = true;
    }

    if (plugin->is(EVENT_MODIFIER, event) && event->isReleased()
        && (
            event->key() == KEY_LEFT_GUI
            || event->key() == KEY_RIGHT_GUI
            || event->key() == STK_GUI
        )
    )
    {
        if (ignoreNextGui) {
            ignoreNextGui = false;
            return KBD_HALT;
        }
        guiIsDown = false;
    }

    return KBD_CONTINUE;
}
