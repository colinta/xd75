#pragma once

#include <Keyboard.h>
#include <Mechy/KeyPress.h>
#include <Mechy.h>

class ThrottledKeyPress: public Plugin {
public:
    ThrottledKeyPress();
    uint8_t defaultName();
    bool is(uint8_t event_type, Event* event);
    void run(Event* event);

protected:
    uint16_t prev_key;
    unsigned long prev_time;
    unsigned long delay;
};

#define TK(k) { .name = FN_THROTTLED, .key = k }
#define FN_THROTTLED  FN_USER(0)

#define TK_A TK('a')
#define TK_B TK('b')
#define TK_C TK('c')
#define TK_D TK('d')
#define TK_E TK('e')
#define TK_F TK('f')
#define TK_G TK('g')
#define TK_H TK('h')
#define TK_I TK('i')
#define TK_J TK('j')
#define TK_K TK('k')
#define TK_L TK('l')
#define TK_M TK('m')
#define TK_N TK('n')
#define TK_O TK('o')
#define TK_P TK('p')
#define TK_Q TK('q')
#define TK_R TK('r')
#define TK_S TK('s')
#define TK_T TK('t')
#define TK_U TK('u')
#define TK_V TK('v')
#define TK_W TK('w')
#define TK_X TK('x')
#define TK_Y TK('y')
#define TK_Z TK('z')

#define TK_0 TK('0')
#define TK_1 TK('1')
#define TK_2 TK('2')
#define TK_3 TK('3')
#define TK_4 TK('4')
#define TK_5 TK('5')
#define TK_6 TK('6')
#define TK_7 TK('7')
#define TK_8 TK('8')
#define TK_9 TK('9')

#define TK_GRV TK('`')
#define TK_MINS TK('-')
#define TK_EQL TK('=')
#define TK_SCLN TK(';')
#define TK_LBRC TK('[')
#define TK_RBRC TK(']')
#define TK_QUOT TK('\'')
#define TK_BSLS TK('\\')
#define TK_COMM TK(',')
#define TK_DOT  TK('.')
#define TK_SLSH TK('/')
#define TK_SPC TK(' ')

#define TK_F1 TK(KEY_F1)
#define TK_F2 TK(KEY_F2)
#define TK_F3 TK(KEY_F3)
#define TK_F4 TK(KEY_F4)
#define TK_F5 TK(KEY_F5)
#define TK_F6 TK(KEY_F6)
#define TK_F7 TK(KEY_F7)
#define TK_F8 TK(KEY_F8)
#define TK_F9 TK(KEY_F9)
#define TK_F10 TK(KEY_F10)
#define TK_F11 TK(KEY_F11)
#define TK_F12 TK(KEY_F12)
#define TK_F13 TK(KEY_F13)
#define TK_F14 TK(KEY_F14)
#define TK_F15 TK(KEY_F15)
#define TK_F16 TK(KEY_F16)
#define TK_F17 TK(KEY_F17)
#define TK_F18 TK(KEY_F18)
#define TK_F19 TK(KEY_F19)
#define TK_F20 TK(KEY_F20)
#define TK_F21 TK(KEY_F21)
#define TK_F22 TK(KEY_F22)
#define TK_F23 TK(KEY_F23)
#define TK_F24 TK(KEY_F24)

#define TK_ESC TK(KEY_ESC)
#define TK_INS TK(KEY_INSERT)
#define TK_DEL TK(KEY_DELETE)
#define TK_BSPC TK(KEY_BACKSPACE)
#define TK_ENT TK(KEY_RETURN)
#define TK_TAB TK(KEY_TAB)
#define TK_CAPS TK(KEY_CAPS_LOCK)

#define TK_LEFT TK(KEY_LEFT_ARROW)
#define TK_RGHT TK(KEY_RIGHT_ARROW)
#define TK_UP TK(KEY_UP_ARROW)
#define TK_DOWN TK(KEY_DOWN_ARROW)
#define TK_PGUP TK(KEY_PAGE_UP)
#define TK_PGDN TK(KEY_PAGE_DOWN)
#define TK_HOME TK(KEY_HOME)
#define TK_END TK(KEY_END)

#define TK_LSFT TK(KEY_LEFT_SHIFT)
#define TK_LCTL TK(KEY_LEFT_CTRL)
#define TK_LALT TK(KEY_LEFT_ALT)
#define TK_LGUI TK(KEY_LEFT_GUI)
#define TK_RSFT TK(KEY_RIGHT_SHIFT)
#define TK_RCTL TK(KEY_RIGHT_CTRL)
#define TK_RALT TK(KEY_RIGHT_ALT)
#define TK_RGUI TK(KEY_RIGHT_GUI)

#define TK_HYP TK(DATA_MOD_LSFT | DATA_MOD_LGUI | DATA_MOD_LCTL | DATA_MOD_LALT)
#define TK_MEH TK(DATA_MOD_LSFT | DATA_MOD_LCTL | DATA_MOD_LALT)
#define TK_CAG TK(DATA_MOD_LGUI | DATA_MOD_LCTL | DATA_MOD_LALT)

#define LSFT(k) ((k) | (DATA_MOD_LSFT << EVENT_DATA_SHIFT))
#define LGUI(k) ((k) | (DATA_MOD_LGUI << EVENT_DATA_SHIFT))
#define LCTL(k) ((k) | (DATA_MOD_LCTL << EVENT_DATA_SHIFT))
#define LALT(k) ((k) | (DATA_MOD_LALT << EVENT_DATA_SHIFT))

#define TK_TILD TK(LSFT('`'))
#define TK_EXLM TK(LSFT('1'))
#define TK_AT   TK(LSFT('2'))
#define TK_HASH TK(LSFT('3'))
#define TK_DLR  TK(LSFT('4'))
#define TK_PERC TK(LSFT('5'))
#define TK_CIRC TK(LSFT('6'))
#define TK_AMPR TK(LSFT('7'))
#define TK_ASTR TK(LSFT('8'))
#define TK_LPRN TK(LSFT('9'))
#define TK_RPRN TK(LSFT('0'))
#define TK_UNDS TK(LSFT('_'))
#define TK_PLUS TK(LSFT('+'))
#define TK_LCBR TK(LSFT('['))
#define TK_RCBR TK(LSFT(']'))
#define TK_PIPE TK(LSFT('\\'))
#define TK_COLN TK(LSFT(';'))
#define TK_DQUO TK(LSFT('\''))
#define TK_LABK TK(LSFT(','))
#define TK_RABK TK(LSFT('.'))
#define TK_QUES TK(LSFT('/'))
