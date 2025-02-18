// #define ENCODER_ENABLE

#ifdef ENCODER_ENABLE

#    include "layers.h"

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        switch (get_highest_layer(layer_state)) {
            case _SYMBOL:
            case _MOVE:
                if (clockwise) {
                    tap_code(KC_PGDN);
                } else {
                    tap_code(KC_PGUP);
                }
                break;
            default:
                if (clockwise) {
                    tap_code(MS_WHLD);
                } else {
                    tap_code(MS_WHLU);
                }
                break;
        }
    }
    return true;
}

#endif
