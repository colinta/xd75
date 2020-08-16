#include "WeirdKeyPress.h"
#include <Mechy/Sticky.h>


WeirdKeyPress::WeirdKeyPress() {
    ignoreNextGui = false;
    listenNextGui = false;
}

uint8_t WeirdKeyPress::defaultName() {
    return FN_WEIRD;
}

bool WeirdKeyPress::override(uint8_t name, Event* event, Plugin* plugin) {
    Plugin *sticky = mechy->pluginFor(FN_STICKY);
    if (!sticky) { return KBD_CONTINUE; }

    if (name == FN_WEIRD && event->isPressed() && (mechy->currentModifiers() & MOD_GUI)) {
        // do not turn off gui
        ignoreNextGui = true;
    }
    else if (name == FN_WEIRD && event->isReleased() && (mechy->currentModifiers() & MOD_GUI)) {
        mechy->releaseKey(KEY_LEFT_GUI);
        listenNextGui = true;
    }
    else if (listenNextGui && name == FN_STICKY && event->isPressed() && event->key() == STK_GUI) {
        mechy->pressKey(KEY_LEFT_GUI);
        listenNextGui = false;
        return KBD_HALT;
    }
    else if (ignoreNextGui && name == FN_STICKY && event->isReleased() && event->key() == STK_GUI) {
        ignoreNextGui = false;
        return KBD_HALT;
    }
    return KBD_CONTINUE;
}

bool WeirdKeyPress::is(uint8_t event_type, Event* event) {
    // does this key have modifiers in the data channel?  if so, match EVENT_MODIFIER
    if (event->data() & DATA_MOD_ANY && event_type == EVENT_MODIFIER)  return true;

    // is this a single modifier key?  only match EVENT_MODIFIER
    if (
        event->key() == KEY_LEFT_SHIFT ||
        event->key() == KEY_LEFT_CTRL ||
        event->key() == KEY_LEFT_ALT ||
        event->key() == KEY_LEFT_GUI ||
        event->key() == KEY_RIGHT_SHIFT ||
        event->key() == KEY_RIGHT_CTRL ||
        event->key() == KEY_RIGHT_ALT ||
        event->key() == KEY_RIGHT_GUI)
    {
        return event_type == EVENT_MODIFIER;
    }

    // lastly if there is anything in the key mask, match EVENT_KEYPRESS
    return event->key() && event_type == EVENT_KEYPRESS;
}

void WeirdKeyPress::run(Event* event) {
    if (event->isPressed()) {
        if (event->data() & DATA_MOD_LSFT) { mechy->pressKey(KEY_LEFT_SHIFT); }
        if (event->data() & DATA_MOD_LGUI) { mechy->pressKey(KEY_LEFT_GUI); }
        if (event->data() & DATA_MOD_LCTL) { mechy->pressKey(KEY_LEFT_CTRL); }
        if (event->data() & DATA_MOD_LALT) { mechy->pressKey(KEY_LEFT_ALT); }

        mechy->pressKey(event->key());
    }
    else if (event->isReleased()) {
        mechy->releaseKey(event->key());

        if (event->data() & DATA_MOD_LSFT) { mechy->releaseKey(KEY_LEFT_SHIFT); }
        if (event->data() & DATA_MOD_LGUI) { mechy->releaseKey(KEY_LEFT_GUI); }
        if (event->data() & DATA_MOD_LCTL) { mechy->releaseKey(KEY_LEFT_CTRL); }
        if (event->data() & DATA_MOD_LALT) { mechy->releaseKey(KEY_LEFT_ALT); }
    }
}
