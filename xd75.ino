#undef DEBUG_ON

// xd75 v1 - Stained Ash
// #define XD75_V1
// xd75 v2 - Sapele
#define XD75_V2

#include <Mechy.h>
#include <Mechy/Hardware/XD75.h>
#include <Mechy/KeyPress.h>
#include <Mechy/MediaKey.h>
#include <Mechy/Sticky.h>
#include <Mechy/Password.h>
#include <Mechy/SendString.h>
#include <Mechy/GotoLayer.h>
#include <Mechy/TapHold.h>
#include <Mechy/Lock.h>
#include "ThrottledKeyPress.h"

#ifdef DEBUG_ON
#include <Mechy/DebugKey.h>
#endif

#define LAYOUT_my( \
    k00 , k01 , k02 , k03 , k04 , k05 , k06 , k07 , k08 , k09 , k0a , k0b , k0c , k0d , k0e , \
          k11 , k12 , k13 , k14 , k15 , k16 , k17 , k18 , k19 , k1a , k1b , k1c , k1d , k1e , \
          k21 , k22 , k23 , k24 , k25 , k26 , k27 , k28 , k29 , k2a , k2b , k2c , k2d , k2e , \
          k31 , k32 , k33 , k34 , k35 , k36 , k37 , k38 , k39 , k3a , k3b , k3c , k3d , k3e , \
          k41    ,    k43    ,    k45    ,          k48       , k4a , k4b , k4c , k4d , k4e   \
) { \
    k00,  k01 , k02 , k03 , k04 , k05 , k06 , k07 , k08 , k09 , k0a , k0b , k0c , k0d , k0e , \
    ____, k11 , k12 , k13 , k14 , k15 , k16 , k17 , k18 , k19 , k1a , k1b , k1c , k1d , k1e , \
    ____, k21 , k22 , k23 , k24 , k25 , k26 , k27 , k28 , k29 , k2a , k2b , k2c , k2d , k2e , \
    ____, k31 , k32 , k33 , k34 , k35 , k36 , k37 , k38 , k39 , k3a , k3b , k3c , k3d , k3e , \
    ____, k41 , ____, k43 , ____, k45 , ____, ____, k48 , ____, k4a , k4b , k4c , k4d , k4e   \
}

#define SLEEP KC(LGUI(LCTL('q')))
#define TH_PGUP TH(10)
#define TH_PGDN TH(11)
#define TH_PLAY TH(12)
#define TH_QUOT TH(13)
#define TH_DOT  TH(14)
#define TH_LBRC TH(15)
#define TH_RBRC TH(16)
#define PW_N    PW(0)
#define PW_S    PW(1)
#define PW_E    PW(2)
#define PW_T    PW(3)
#define PW_J    PW(4)
#define PW_W    PW(5)
#define PW_L    PW(6)
#define PW_D    PW(7)
#define PW_SPC  PW(8)
#define PW_PGUP PW(9)
#define PW_PGDN PW(10)

#define COLE_LAYER 0
#define META_LAYER 1
#define GAME_LAYER 2
#define META     PUSH_1
#define COLEMAK  LSET_0
#define GAME     LSET_2

KEYS(mainKeys) = LAYOUT_my(
    KC_ESC , KC_GRV , TH_1   , TH_2   , TH_3   , TH_4   , TH_5   , KC_DEL , TH_6   , TH_7   , TH_8   , TH_9   , TH_0   , KC_MINS, KC_EQL ,
             KC_TAB , KC_Q   , KC_W   , KC_F   , KC_P   , KC_G   , KC_BSPC, KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, TH_LBRC, TH_RBRC,
             ST_SFT , KC_A   , KC_R   , KC_S   , TK_T   , KC_D   , KC_ENT , KC_H   , KC_N   , KC_E   , KC_I   , KC_O   , TH_QUOT, KC_BSLS,
             ST_CTL , KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,  META  , KC_K   , KC_M   , KC_COMM, TH_DOT , KC_SLSH, KC_UP  , ST_CAG ,
             TH_PLAY,         ST_ALT     ,      ST_GUI           ,          KC_SPC          , TH_PGUP, TH_PGDN, KC_LEFT, KC_DOWN, KC_RGHT
);

KEYS(fnKeys) = LAYOUT_my(
    SLEEP  ,  ____  , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , COLEMAK,  KC_F6 , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
              ____  ,  ____  ,  PW_W  ,  ____  ,  ____  ,  ____  ,  GAME  ,  PW_J  ,  PW_L  ,  ____  ,  ____  ,  ____  , KC_LBRC, KC_RBRC,
              ____  ,  ____  ,  ____  ,  PW_S  ,  PW_T  ,  PW_D  ,  ____  ,  ____  ,  PW_N  ,  PW_E  ,  ____  ,  ____  , KC_QUOT,  ____  ,
              ____  ,  ____  ,  ____  ,  ____  ,  ____  , MD_VOLD,  BACK  , MD_VOLU,  ____  ,  ____  , KC_DOT , KC_INS , KC_PGUP, KC_CAPS,
               LK   ,            LK      ,         LK            ,          PW_SPC          , PW_PGUP, PW_PGDN, KC_HOME, KC_PGDN, KC_END
);

KEYS(gameKeys) = LAYOUT_my(
    KC_ESC , KC_GRV , TH_1   , TH_2   , TH_3   , TH_4   , TH_5   , KC_DEL , TH_6   , TH_7   , TH_8   , TH_9   , TH_0   , KC_MINS, KC_EQL ,
             KC_TAB , KC_Q   , KC_W   , KC_F   , KC_P   , KC_G   , KC_BSPC, KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, KC_LBRC, KC_RBRC,
             KC_LSFT, KC_A   , KC_R   , KC_S   , TK_T   , KC_D   , KC_ENT , KC_H   , KC_N   , KC_E   , KC_I   , KC_O   , KC_QUOT, KC_BSLS,
             KC_LCTL, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,  META  , KC_K   , KC_M   , KC_COMM, TH_DOT , KC_SLSH, KC_UP  , ST_CAG ,
             TH_PLAY,         KC_LALT    ,      KC_LGUI          ,          KC_SPC          , TH_PGUP, TH_PGDN, KC_LEFT, KC_DOWN, KC_RGHT
);

#ifdef DEBUG_ON
KEYS(debugKeys) = LAYOUT_my(
    DB_ESC , DB_GRV , DB_1   , DB_2   , DB_3   , DB_4   , DB_5   , DB_DEL , DB_6   , DB_7   , DB_8   , DB_9   , DB_0   , DB_MINS, DB_EQL ,
             DB_TAB , DB_Q   , DB_W   , DB_F   , DB_P   , DB_G   , DB_BSPC, DB_J   , DB_L   , DB_U   , DB_Y   , DB_SCLN, DB_LBRC, DB_RBRC,
             DB_SFT , DB_A   , DB_R   , DB_S   , DB_T   , DB_D   , DB_ENT , DB_H   , DB_N   , DB_E   , DB_I   , DB_O   , DB_QUOT, DB_BSLS,
             DB_CTL , DB_Z   , DB_X   , DB_C   , DB_V   , DB_B   , DB_FN1 , DB_K   , DB_M   , DB_COMM, DB_DOT , DB_SLSH, DB_UP  , DB_CAG ,
             DB_PLAY,         DB_ALT     ,      DB_GUI           ,          DB_SPC          , DB_PGUP, DB_PGDN, DB_LEFT, DB_DOWN, DB_RGHT
);
Layout layout = Layout(ROWS, COLS, debugKeys);
#else
Layout layout = Layout(ROWS, COLS, mainKeys, fnKeys, gameKeys);
#endif

#if (__has_include("secrets.h"))
#include "secrets.h"
#define PASSWORDS 11
const char* passwords[PASSWORDS] = {PASS_N, PASS_S, PASS_E, PASS_T, PASS_J, PASS_W, PASS_L, PASS_D, PASS_SPC, PASS_PGUP, PASS_PGDN};
#else
#define PASSWORDS 0
const char* passwords[] = {};
#endif

Scanner scanner = Scanner(&layout, pinRows, pinCols, ROWS, COLS);
Mechy mechy = Mechy();
Hardware hardware = Hardware(&mechy);

Password password = Password(PASSWORDS, passwords);
uint16_t* macros[] = {
    send3(ignoreModifiers(downUp('\\')), ignoreModifiers(downUp(LCTL('v'))), downUp('\'')),
    send2(ignoreModifiers(downUp('\\')), downUp('.')),
    send3(ignoreModifiers(downUp('\\')), ignoreModifiers(downUp(LCTL('v'))), downUp('[')),
    send2(ignoreModifiers(downUp('\\')), downUp(']')),
};
SendString sendString = SendString(4, macros);


void setup() {
#ifdef DEBUG_ON
    mechy.add(new DebugKey());
#endif
    TapHold* tapHold = new TapHold();
    tapHold->add(KC_0, KC_F10);     // TH(0)
    tapHold->add(KC_1, KC_F1);      // TH(1)
    tapHold->add(KC_2, KC_F2);      // TH(2)
    tapHold->add(KC_3, KC_F3);      // TH(3)
    tapHold->add(KC_4, KC_F4);      // TH(4)
    tapHold->add(KC_5, KC_F5);      // TH(5)
    tapHold->add(KC_6, KC_F6);      // TH(6)
    tapHold->add(KC_7, KC_F7);      // TH(7)
    tapHold->add(KC_8, KC_F8);      // TH(8)
    tapHold->add(KC_9, KC_F9);      // TH(9)
    tapHold->add(KC_PGUP, KC_HOME); // TH(10)
    tapHold->add(KC_PGDN, KC_END);  // TH(11)
    tapHold->add(MD_PLAY, MD_MUTE); // TH(12)
    tapHold->add(KC_QUOT, SS_0);    // TH(13)
    tapHold->add(KC_DOT, SS_1);     // TH(14)
    tapHold->add(KC_LBRC, SS_2);    // TH(15)
    tapHold->add(KC_RBRC, SS_3);    // TH(16)

    mechy.add(new KeyPress());
    mechy.add(new ThrottledKeyPress());
    mechy.add(new MediaKey());
    mechy.add(new Sticky());
    mechy.add(new GotoLayer());
    mechy.add(new Lock(3));
    mechy.add(tapHold);
    mechy.add(&password);
    mechy.add(&sendString);

    mechy.attach(&scanner);

    mechy.setListenFunc(&update);

    mechy.begin();
    hardware.begin();

    hardware.capsLockLedWrite(false);
    hardware.gp100Write(false);
    hardware.gp103Write(false);

    for (uint8_t i = 0; i < 3 ; ++i) {
        hardware.keycapsLedsWrite(true);
        delay(100);
        hardware.keycapsLedsWrite(false);
        delay(100);
    }

#ifdef XD75_V1
    hardware.keycapsLedsWrite(true);
#elseif XD75_V2
    hardware.keycapsLedsWrite(false);
#endif
}

void loop() {
    mechy.tick();
    hardware.tick();

    bool isMetaLayer = mechy.currentLayer() == META_LAYER;
#if defined(XD75_V1)
    hardware.gp103Write(isMetaLayer);
    hardware.gp100Write(isMetaLayer);
    hardware.capsLockLedWrite(isMetaLayer);
#elif defined(XD75_V2)
    hardware.keycapsLedsWrite(isMetaLayer);
#endif
}

void update(Event* event) {
    if (event->name == FN_KEYPRESS && event->keyAndData == LGUI(LCTL('q')) && mechy.currentLayer() != 0) {
        mechy.removeLayer(META_LAYER);
    }

    if ((event->name == FN_PASSWORD) && event->isActive()) {
        mechy.removeLayer(META_LAYER);
    }
}
