#pragma once

#include <Keyboard.h>
#include <Mechy/KeyPress.h>
#include <Mechy.h>

class WeirdKeyPress: public Plugin {
public:
    WeirdKeyPress();
    uint8_t defaultName();
    bool is(uint8_t event_type, Event* event);
    void run(Event* event);
    bool override(uint8_t name, Event* event, Plugin* plugin);

protected:
    bool ignoreNextGui;
    bool listenNextGui;
};

#define WTF(k) { .name = FN_WEIRD, .key = k }
#define FN_WEIRD  FN_USER(0)

#define WTF_A WTF('a')
#define WTF_B WTF('b')
#define WTF_C WTF('c')
#define WTF_D WTF('d')
#define WTF_E WTF('e')
#define WTF_F WTF('f')
#define WTF_G WTF('g')
#define WTF_H WTF('h')
#define WTF_I WTF('i')
#define WTF_J WTF('j')
#define WTF_K WTF('k')
#define WTF_L WTF('l')
#define WTF_M WTF('m')
#define WTF_N WTF('n')
#define WTF_O WTF('o')
#define WTF_P WTF('p')
#define WTF_Q WTF('q')
#define WTF_R WTF('r')
#define WTF_S WTF('s')
#define WTF_T WTF('t')
#define WTF_U WTF('u')
#define WTF_V WTF('v')
#define WTF_W WTF('w')
#define WTF_X WTF('x')
#define WTF_Y WTF('y')
#define WTF_Z WTF('z')

#define WTF_0 WTF('0')
#define WTF_1 WTF('1')
#define WTF_2 WTF('2')
#define WTF_3 WTF('3')
#define WTF_4 WTF('4')
#define WTF_5 WTF('5')
#define WTF_6 WTF('6')
#define WTF_7 WTF('7')
#define WTF_8 WTF('8')
#define WTF_9 WTF('9')

#define WTF_GRV WTF('`')
#define WTF_MINS WTF('-')
#define WTF_EQL WTF('=')
#define WTF_SCLN WTF(';')
#define WTF_LBRC WTF('[')
#define WTF_RBRC WTF(']')
#define WTF_QUOT WTF('\'')
#define WTF_BSLS WTF('\\')
#define WTF_COMM WTF(',')
#define WTF_DOT  WTF('.')
#define WTF_SLSH WTF('/')
#define WTF_SPC WTF(' ')

#define WTF_F1 WTF(KEY_F1)
#define WTF_F2 WTF(KEY_F2)
#define WTF_F3 WTF(KEY_F3)
#define WTF_F4 WTF(KEY_F4)
#define WTF_F5 WTF(KEY_F5)
#define WTF_F6 WTF(KEY_F6)
#define WTF_F7 WTF(KEY_F7)
#define WTF_F8 WTF(KEY_F8)
#define WTF_F9 WTF(KEY_F9)
#define WTF_F10 WTF(KEY_F10)
#define WTF_F11 WTF(KEY_F11)
#define WTF_F12 WTF(KEY_F12)
#define WTF_F13 WTF(KEY_F13)
#define WTF_F14 WTF(KEY_F14)
#define WTF_F15 WTF(KEY_F15)
#define WTF_F16 WTF(KEY_F16)
#define WTF_F17 WTF(KEY_F17)
#define WTF_F18 WTF(KEY_F18)
#define WTF_F19 WTF(KEY_F19)
#define WTF_F20 WTF(KEY_F20)
#define WTF_F21 WTF(KEY_F21)
#define WTF_F22 WTF(KEY_F22)
#define WTF_F23 WTF(KEY_F23)
#define WTF_F24 WTF(KEY_F24)

#define WTF_ESC WTF(KEY_ESC)
#define WTF_INS WTF(KEY_INSERT)
#define WTF_DEL WTF(KEY_DELETE)
#define WTF_BSPC WTF(KEY_BACKSPACE)
#define WTF_ENT WTF(KEY_RETURN)
#define WTF_TAB WTF(KEY_TAB)
#define WTF_CAPS WTF(KEY_CAPS_LOCK)

#define WTF_LEFT WTF(KEY_LEFT_ARROW)
#define WTF_RGHT WTF(KEY_RIGHT_ARROW)
#define WTF_UP WTF(KEY_UP_ARROW)
#define WTF_DOWN WTF(KEY_DOWN_ARROW)
#define WTF_PGUP WTF(KEY_PAGE_UP)
#define WTF_PGDN WTF(KEY_PAGE_DOWN)
#define WTF_HOME WTF(KEY_HOME)
#define WTF_END WTF(KEY_END)

#define WTF_LSFT WTF(KEY_LEFT_SHIFT)
#define WTF_LCTL WTF(KEY_LEFT_CTRL)
#define WTF_LALT WTF(KEY_LEFT_ALT)
#define WTF_LGUI WTF(KEY_LEFT_GUI)
#define WTF_RSFT WTF(KEY_RIGHT_SHIFT)
#define WTF_RCTL WTF(KEY_RIGHT_CTRL)
#define WTF_RALT WTF(KEY_RIGHT_ALT)
#define WTF_RGUI WTF(KEY_RIGHT_GUI)

#define WTF_HYP WTF(DATA_MOD_LSFT | DATA_MOD_LGUI | DATA_MOD_LCTL | DATA_MOD_LALT)
#define WTF_MEH WTF(DATA_MOD_LSFT | DATA_MOD_LCTL | DATA_MOD_LALT)
#define WTF_CAG WTF(DATA_MOD_LGUI | DATA_MOD_LCTL | DATA_MOD_LALT)

#define LSFT(k) ((k) | (DATA_MOD_LSFT << EVENT_DATA_SHIFT))
#define LGUI(k) ((k) | (DATA_MOD_LGUI << EVENT_DATA_SHIFT))
#define LCTL(k) ((k) | (DATA_MOD_LCTL << EVENT_DATA_SHIFT))
#define LALT(k) ((k) | (DATA_MOD_LALT << EVENT_DATA_SHIFT))

#define WTF_TILD WTF(LSFT('`'))
#define WTF_EXLM WTF(LSFT('1'))
#define WTF_AT   WTF(LSFT('2'))
#define WTF_HASH WTF(LSFT('3'))
#define WTF_DLR  WTF(LSFT('4'))
#define WTF_PERC WTF(LSFT('5'))
#define WTF_CIRC WTF(LSFT('6'))
#define WTF_AMPR WTF(LSFT('7'))
#define WTF_ASTR WTF(LSFT('8'))
#define WTF_LPRN WTF(LSFT('9'))
#define WTF_RPRN WTF(LSFT('0'))
#define WTF_UNDS WTF(LSFT('_'))
#define WTF_PLUS WTF(LSFT('+'))
#define WTF_LCBR WTF(LSFT('['))
#define WTF_RCBR WTF(LSFT(']'))
#define WTF_PIPE WTF(LSFT('\\'))
#define WTF_COLN WTF(LSFT(';'))
#define WTF_DQUO WTF(LSFT('\''))
#define WTF_LABK WTF(LSFT(','))
#define WTF_RABK WTF(LSFT('.'))
#define WTF_QUES WTF(LSFT('/'))
