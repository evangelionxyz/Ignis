#pragma once

#include <cstdint>

#define KEY_EXTENDED_MASK          (1u << 29)
#define KEY_SCANCODE_MASK          (1u << 30)
#define KEY_SCANCODE_TO_KEYCODE(X) (X | KEY_SCANCODE_MASK)
#define KEY_UNKNOWN                0x00000000u /**< 0 */
#define KEY_RETURN                 0x0000000du /**< '\r' */
#define KEY_ESCAPE                 0x0000001bu /**< '\x1B' */
#define KEY_BACKSPACE              0x00000008u /**< '\b' */
#define KEY_TAB                    0x00000009u /**< '\t' */
#define KEY_SPACE                  0x00000020u /**< ' ' */
#define KEY_EXCLAIM                0x00000021u /**< '!' */
#define KEY_DBLAPOSTROPHE          0x00000022u /**< '"' */
#define KEY_HASH                   0x00000023u /**< '#' */
#define KEY_DOLLAR                 0x00000024u /**< '$' */
#define KEY_PERCENT                0x00000025u /**< '%' */
#define KEY_AMPERSAND              0x00000026u /**< '&' */
#define KEY_APOSTROPHE             0x00000027u /**< '\'' */
#define KEY_LEFTPAREN              0x00000028u /**< '(' */
#define KEY_RIGHTPAREN             0x00000029u /**< ')' */
#define KEY_ASTERISK               0x0000002au /**< '*' */
#define KEY_PLUS                   0x0000002bu /**< '+' */
#define KEY_COMMA                  0x0000002cu /**< ',' */
#define KEY_MINUS                  0x0000002du /**< '-' */
#define KEY_PERIOD                 0x0000002eu /**< '.' */
#define KEY_SLASH                  0x0000002fu /**< '/' */
#define KEY_0                      0x00000030u /**< '0' */
#define KEY_1                      0x00000031u /**< '1' */
#define KEY_2                      0x00000032u /**< '2' */
#define KEY_3                      0x00000033u /**< '3' */
#define KEY_4                      0x00000034u /**< '4' */
#define KEY_5                      0x00000035u /**< '5' */
#define KEY_6                      0x00000036u /**< '6' */
#define KEY_7                      0x00000037u /**< '7' */
#define KEY_8                      0x00000038u /**< '8' */
#define KEY_9                      0x00000039u /**< '9' */
#define KEY_COLON                  0x0000003au /**< ':' */
#define KEY_SEMICOLON              0x0000003bu /**< ';' */
#define KEY_LESS                   0x0000003cu /**< '<' */
#define KEY_EQUALS                 0x0000003du /**< '=' */
#define KEY_GREATER                0x0000003eu /**< '>' */
#define KEY_QUESTION               0x0000003fu /**< '?' */
#define KEY_AT                     0x00000040u /**< '@' */
#define KEY_LEFTBRACKET            0x0000005bu /**< '[' */
#define KEY_BACKSLASH              0x0000005cu /**< '\\' */
#define KEY_RIGHTBRACKET           0x0000005du /**< ']' */
#define KEY_CARET                  0x0000005eu /**< '^' */
#define KEY_UNDERSCORE             0x0000005fu /**< '_' */
#define KEY_GRAVE                  0x00000060u /**< '`' */
#define KEY_A                      0x00000061u /**< 'a' */
#define KEY_B                      0x00000062u /**< 'b' */
#define KEY_C                      0x00000063u /**< 'c' */
#define KEY_D                      0x00000064u /**< 'd' */
#define KEY_E                      0x00000065u /**< 'e' */
#define KEY_F                      0x00000066u /**< 'f' */
#define KEY_G                      0x00000067u /**< 'g' */
#define KEY_H                      0x00000068u /**< 'h' */
#define KEY_I                      0x00000069u /**< 'i' */
#define KEY_J                      0x0000006au /**< 'j' */
#define KEY_K                      0x0000006bu /**< 'k' */
#define KEY_L                      0x0000006cu /**< 'l' */
#define KEY_M                      0x0000006du /**< 'm' */
#define KEY_N                      0x0000006eu /**< 'n' */
#define KEY_O                      0x0000006fu /**< 'o' */
#define KEY_P                      0x00000070u /**< 'p' */
#define KEY_Q                      0x00000071u /**< 'q' */
#define KEY_R                      0x00000072u /**< 'r' */
#define KEY_S                      0x00000073u /**< 's' */
#define KEY_T                      0x00000074u /**< 't' */
#define KEY_U                      0x00000075u /**< 'u' */
#define KEY_V                      0x00000076u /**< 'v' */
#define KEY_W                      0x00000077u /**< 'w' */
#define KEY_X                      0x00000078u /**< 'x' */
#define KEY_Y                      0x00000079u /**< 'y' */
#define KEY_Z                      0x0000007au /**< 'z' */
#define KEY_LEFTBRACE              0x0000007bu /**< '{' */
#define KEY_PIPE                   0x0000007cu /**< '|' */
#define KEY_RIGHTBRACE             0x0000007du /**< '}' */
#define KEY_TILDE                  0x0000007eu /**< '~' */
#define KEY_DELETE                 0x0000007fu /**< '\x7F' */
#define KEY_PLUSMINUS              0x000000b1u /**< '\xB1' */
#define KEY_CAPSLOCK               0x40000039u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CAPSLOCK) */
#define KEY_F1                     0x4000003au /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F1) */
#define KEY_F2                     0x4000003bu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F2) */
#define KEY_F3                     0x4000003cu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F3) */
#define KEY_F4                     0x4000003du /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F4) */
#define KEY_F5                     0x4000003eu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F5) */
#define KEY_F6                     0x4000003fu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F6) */
#define KEY_F7                     0x40000040u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F7) */
#define KEY_F8                     0x40000041u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F8) */
#define KEY_F9                     0x40000042u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F9) */
#define KEY_F10                    0x40000043u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F10) */
#define KEY_F11                    0x40000044u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F11) */
#define KEY_F12                    0x40000045u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F12) */
#define KEY_PRINTSCREEN            0x40000046u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PRINTSCREEN) */
#define KEY_SCROLLLOCK             0x40000047u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SCROLLLOCK) */
#define KEY_PAUSE                  0x40000048u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PAUSE) */
#define KEY_INSERT                 0x40000049u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_INSERT) */
#define KEY_HOME                   0x4000004au /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_HOME) */
#define KEY_PAGEUP                 0x4000004bu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PAGEUP) */
#define KEY_END                    0x4000004du /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_END) */
#define KEY_PAGEDOWN               0x4000004eu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PAGEDOWN) */
#define KEY_RIGHT                  0x4000004fu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RIGHT) */
#define KEY_LEFT                   0x40000050u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LEFT) */
#define KEY_DOWN                   0x40000051u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_DOWN) */
#define KEY_UP                     0x40000052u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_UP) */
#define KEY_NUMLOCKCLEAR           0x40000053u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_NUMLOCKCLEAR) */
#define KEY_KP_DIVIDE              0x40000054u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_DIVIDE) */
#define KEY_KP_MULTIPLY            0x40000055u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MULTIPLY) */
#define KEY_KP_MINUS               0x40000056u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MINUS) */
#define KEY_KP_PLUS                0x40000057u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_PLUS) */
#define KEY_KP_ENTER               0x40000058u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_ENTER) */
#define KEY_KP_1                   0x40000059u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_1) */
#define KEY_KP_2                   0x4000005au /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_2) */
#define KEY_KP_3                   0x4000005bu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_3) */
#define KEY_KP_4                   0x4000005cu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_4) */
#define KEY_KP_5                   0x4000005du /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_5) */
#define KEY_KP_6                   0x4000005eu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_6) */
#define KEY_KP_7                   0x4000005fu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_7) */
#define KEY_KP_8                   0x40000060u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_8) */
#define KEY_KP_9                   0x40000061u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_9) */
#define KEY_KP_0                   0x40000062u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_0) */
#define KEY_KP_PERIOD              0x40000063u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_PERIOD) */
#define KEY_APPLICATION            0x40000065u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_APPLICATION) */
#define KEY_POWER                  0x40000066u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_POWER) */
#define KEY_KP_EQUALS              0x40000067u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_EQUALS) */
#define KEY_F13                    0x40000068u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F13) */
#define KEY_F14                    0x40000069u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F14) */
#define KEY_F15                    0x4000006au /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F15) */
#define KEY_F16                    0x4000006bu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F16) */
#define KEY_F17                    0x4000006cu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F17) */
#define KEY_F18                    0x4000006du /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F18) */
#define KEY_F19                    0x4000006eu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F19) */
#define KEY_F20                    0x4000006fu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F20) */
#define KEY_F21                    0x40000070u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F21) */
#define KEY_F22                    0x40000071u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F22) */
#define KEY_F23                    0x40000072u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F23) */
#define KEY_F24                    0x40000073u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F24) */
#define KEY_EXECUTE                0x40000074u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_EXECUTE) */
#define KEY_HELP                   0x40000075u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_HELP) */
#define KEY_MENU                   0x40000076u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MENU) */
#define KEY_SELECT                 0x40000077u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SELECT) */
#define KEY_STOP                   0x40000078u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_STOP) */
#define KEY_AGAIN                  0x40000079u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AGAIN) */
#define KEY_UNDO                   0x4000007au /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_UNDO) */
#define KEY_CUT                    0x4000007bu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CUT) */
#define KEY_COPY                   0x4000007cu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_COPY) */
#define KEY_PASTE                  0x4000007du /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PASTE) */
#define KEY_FIND                   0x4000007eu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_FIND) */
#define KEY_MUTE                   0x4000007fu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MUTE) */
#define KEY_VOLUMEUP               0x40000080u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_VOLUMEUP) */
#define KEY_VOLUMEDOWN             0x40000081u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_VOLUMEDOWN) */
#define KEY_KP_COMMA               0x40000085u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_COMMA) */
#define KEY_KP_EQUALSAS400         0x40000086u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_EQUALSAS400) */
#define KEY_ALTERASE               0x40000099u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_ALTERASE) */
#define KEY_SYSREQ                 0x4000009au /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SYSREQ) */
#define KEY_CANCEL                 0x4000009bu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CANCEL) */
#define KEY_CLEAR                  0x4000009cu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CLEAR) */
#define KEY_PRIOR                  0x4000009du /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PRIOR) */
#define KEY_RETURN2                0x4000009eu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RETURN2) */
#define KEY_SEPARATOR              0x4000009fu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SEPARATOR) */
#define KEY_OUT                    0x400000a0u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_OUT) */
#define KEY_OPER                   0x400000a1u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_OPER) */
#define KEY_CLEARAGAIN             0x400000a2u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CLEARAGAIN) */
#define KEY_CRSEL                  0x400000a3u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CRSEL) */
#define KEY_EXSEL                  0x400000a4u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_EXSEL) */
#define KEY_KP_00                  0x400000b0u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_00) */
#define KEY_KP_000                 0x400000b1u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_000) */
#define KEY_THOUSANDSSEPARATOR     0x400000b2u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_THOUSANDSSEPARATOR) */
#define KEY_DECIMALSEPARATOR       0x400000b3u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_DECIMALSEPARATOR) */
#define KEY_CURRENCYUNIT           0x400000b4u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CURRENCYUNIT) */
#define KEY_CURRENCYSUBUNIT        0x400000b5u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CURRENCYSUBUNIT) */
#define KEY_KP_LEFTPAREN           0x400000b6u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_LEFTPAREN) */
#define KEY_KP_RIGHTPAREN          0x400000b7u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_RIGHTPAREN) */
#define KEY_KP_LEFTBRACE           0x400000b8u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_LEFTBRACE) */
#define KEY_KP_RIGHTBRACE          0x400000b9u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_RIGHTBRACE) */
#define KEY_KP_TAB                 0x400000bau /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_TAB) */
#define KEY_KP_BACKSPACE           0x400000bbu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_BACKSPACE) */
#define KEY_KP_A                   0x400000bcu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_A) */
#define KEY_KP_B                   0x400000bdu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_B) */
#define KEY_KP_C                   0x400000beu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_C) */
#define KEY_KP_D                   0x400000bfu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_D) */
#define KEY_KP_E                   0x400000c0u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_E) */
#define KEY_KP_F                   0x400000c1u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_F) */
#define KEY_KP_XOR                 0x400000c2u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_XOR) */
#define KEY_KP_POWER               0x400000c3u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_POWER) */
#define KEY_KP_PERCENT             0x400000c4u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_PERCENT) */
#define KEY_KP_LESS                0x400000c5u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_LESS) */
#define KEY_KP_GREATER             0x400000c6u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_GREATER) */
#define KEY_KP_AMPERSAND           0x400000c7u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_AMPERSAND) */
#define KEY_KP_DBLAMPERSAND        0x400000c8u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_DBLAMPERSAND) */
#define KEY_KP_VERTICALBAR         0x400000c9u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_VERTICALBAR) */
#define KEY_KP_DBLVERTICALBAR      0x400000cau /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_DBLVERTICALBAR) */
#define KEY_KP_COLON               0x400000cbu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_COLON) */
#define KEY_KP_HASH                0x400000ccu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_HASH) */
#define KEY_KP_SPACE               0x400000cdu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_SPACE) */
#define KEY_KP_AT                  0x400000ceu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_AT) */
#define KEY_KP_EXCLAM              0x400000cfu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_EXCLAM) */
#define KEY_KP_MEMSTORE            0x400000d0u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMSTORE) */
#define KEY_KP_MEMRECALL           0x400000d1u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMRECALL) */
#define KEY_KP_MEMCLEAR            0x400000d2u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMCLEAR) */
#define KEY_KP_MEMADD              0x400000d3u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMADD) */
#define KEY_KP_MEMSUBTRACT         0x400000d4u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMSUBTRACT) */
#define KEY_KP_MEMMULTIPLY         0x400000d5u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMMULTIPLY) */
#define KEY_KP_MEMDIVIDE           0x400000d6u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMDIVIDE) */
#define KEY_KP_PLUSMINUS           0x400000d7u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_PLUSMINUS) */
#define KEY_KP_CLEAR               0x400000d8u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_CLEAR) */
#define KEY_KP_CLEARENTRY          0x400000d9u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_CLEARENTRY) */
#define KEY_KP_BINARY              0x400000dau /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_BINARY) */
#define KEY_KP_OCTAL               0x400000dbu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_OCTAL) */
#define KEY_KP_DECIMAL             0x400000dcu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_DECIMAL) */
#define KEY_KP_HEXADECIMAL         0x400000ddu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_HEXADECIMAL) */
#define KEY_LCTRL                  0x400000e0u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LCTRL) */
#define KEY_LSHIFT                 0x400000e1u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LSHIFT) */
#define KEY_LALT                   0x400000e2u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LALT) */
#define KEY_LGUI                   0x400000e3u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LGUI) */
#define KEY_RCTRL                  0x400000e4u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RCTRL) */
#define KEY_RSHIFT                 0x400000e5u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RSHIFT) */
#define KEY_RALT                   0x400000e6u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RALT) */
#define KEY_RGUI                   0x400000e7u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RGUI) */
#define KEY_MODE                   0x40000101u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MODE) */
#define KEY_SLEEP                  0x40000102u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SLEEP) */
#define KEY_WAKE                   0x40000103u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_WAKE) */
#define KEY_CHANNEL_INCREMENT      0x40000104u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CHANNEL_INCREMENT) */
#define KEY_CHANNEL_DECREMENT      0x40000105u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CHANNEL_DECREMENT) */
#define KEY_MEDIA_PLAY             0x40000106u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_PLAY) */
#define KEY_MEDIA_PAUSE            0x40000107u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_PAUSE) */
#define KEY_MEDIA_RECORD           0x40000108u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_RECORD) */
#define KEY_MEDIA_FAST_FORWARD     0x40000109u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_FAST_FORWARD) */
#define KEY_MEDIA_REWIND           0x4000010au /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_REWIND) */
#define KEY_MEDIA_NEXT_TRACK       0x4000010bu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_NEXT_TRACK) */
#define KEY_MEDIA_PREVIOUS_TRACK   0x4000010cu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_PREVIOUS_TRACK) */
#define KEY_MEDIA_STOP             0x4000010du /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_STOP) */
#define KEY_MEDIA_EJECT            0x4000010eu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_EJECT) */
#define KEY_MEDIA_PLAY_PAUSE       0x4000010fu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_PLAY_PAUSE) */
#define KEY_MEDIA_SELECT           0x40000110u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_SELECT) */
#define KEY_AC_NEW                 0x40000111u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_NEW) */
#define KEY_AC_OPEN                0x40000112u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_OPEN) */
#define KEY_AC_CLOSE               0x40000113u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_CLOSE) */
#define KEY_AC_EXIT                0x40000114u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_EXIT) */
#define KEY_AC_SAVE                0x40000115u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_SAVE) */
#define KEY_AC_PRINT               0x40000116u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_PRINT) */
#define KEY_AC_PROPERTIES          0x40000117u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_PROPERTIES) */
#define KEY_AC_SEARCH              0x40000118u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_SEARCH) */
#define KEY_AC_HOME                0x40000119u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_HOME) */
#define KEY_AC_BACK                0x4000011au /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_BACK) */
#define KEY_AC_FORWARD             0x4000011bu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_FORWARD) */
#define KEY_AC_STOP                0x4000011cu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_STOP) */
#define KEY_AC_REFRESH             0x4000011du /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_REFRESH) */
#define KEY_AC_BOOKMARKS           0x4000011eu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_BOOKMARKS) */
#define KEY_SOFTLEFT               0x4000011fu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SOFTLEFT) */
#define KEY_SOFTRIGHT              0x40000120u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SOFTRIGHT) */
#define KEY_CALL                   0x40000121u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CALL) */
#define KEY_ENDCALL                0x40000122u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_ENDCALL) */
#define KEY_LEFT_TAB               0x20000001u /**< Extended key Left Tab */
#define KEY_LEVEL5_SHIFT           0x20000002u /**< Extended key Level 5 Shift */
#define KEY_MULTI_KEY_COMPOSE      0x20000003u /**< Extended key Multi-key Compose */
#define KEY_LMETA                  0x20000004u /**< Extended key Left Meta */
#define KEY_RMETA                  0x20000005u /**< Extended key Right Meta */
#define KEY_LHYPER                 0x20000006u /**< Extended key Left Hyper */
#define KEY_RHYPER                 0x20000007u /**< Extended key Right Hyper */

#define KMOD_NONE   0x0000u /**< no modifier is applicable. */
#define KMOD_LSHIFT 0x0001u /**< the left Shift key is down. */
#define KMOD_RSHIFT 0x0002u /**< the right Shift key is down. */
#define KMOD_LEVEL5 0x0004u /**< the Level 5 Shift key is down. */
#define KMOD_LCTRL  0x0040u /**< the left Ctrl (Control) key is down. */
#define KMOD_RCTRL  0x0080u /**< the right Ctrl (Control) key is down. */
#define KMOD_LALT   0x0100u /**< the left Alt key is down. */
#define KMOD_RALT   0x0200u /**< the right Alt key is down. */
#define KMOD_LGUI   0x0400u /**< the left GUI key (often the Windows key) is down. */
#define KMOD_RGUI   0x0800u /**< the right GUI key (often the Windows key) is down. */
#define KMOD_NUM    0x1000u /**< the Num Lock key (may be located on an extended keypad) is down. */
#define KMOD_CAPS   0x2000u /**< the Caps Lock key is down. */
#define KMOD_MODE   0x4000u /**< the !AltGr key is down. */
#define KMOD_SCROLL 0x8000u /**< the Scroll Lock key is down. */
#define KMOD_CTRL   (KMOD_LCTRL | KMOD_RCTRL)   /**< Any Ctrl key is down. */
#define KMOD_SHIFT  (KMOD_LSHIFT | KMOD_RSHIFT) /**< Any Shift key is down. */
#define KMOD_ALT    (KMOD_LALT | KMOD_RALT)     /**< Any Alt key is down. */
#define KMOD_GUI    (KMOD_LGUI | KMOD_RGUI)     /**< Any GUI key is down. */

using KeyCode = u32;
using KeyModCode = u16;

namespace Key {
    enum : KeyCode
    {
        Space = KEY_SPACE,
        Apostrophe = KEY_APOSTROPHE, /* ' */
        Comma = KEY_COMMA, /* , */
        Minus = KEY_MINUS, /* - */
        Period = KEY_PERIOD, /* . */
        Slash = KEY_SLASH, /* / */

        D0 = KEY_0, /* 0 */
        D1 = KEY_1, /* 1 */
        D2 = KEY_2, /* 2 */
        D3 = KEY_3, /* 3 */
        D4 = KEY_4, /* 4 */
        D5 = KEY_5, /* 5 */
        D6 = KEY_6, /* 6 */
        D7 = KEY_7, /* 7 */
        D8 = KEY_8, /* 8 */
        D9 = KEY_9, /* 9 */

        Semicolon = KEY_SEMICOLON, /* ; */
        Equal = KEY_EQUALS, /* = */

        A = KEY_A,
        B = KEY_B,
        C = KEY_C,
        D = KEY_D,
        E = KEY_E,
        F = KEY_F,
        G = KEY_G,
        H = KEY_H,
        I = KEY_I,
        J = KEY_J,
        K = KEY_K,
        L = KEY_L,
        M = KEY_M,
        N = KEY_N,
        O = KEY_O,
        P = KEY_P,
        Q = KEY_Q,
        R = KEY_R,
        S = KEY_S,
        T = KEY_T,
        U = KEY_U,
        V = KEY_V,
        W = KEY_W,
        X = KEY_X,
        Y = KEY_Y,
        Z = KEY_Z,

        LeftBracket = KEY_LEFTBRACKET,  /* [ */
        Backslash = KEY_BACKSLASH,  /* \ */
        RightBracket = KEY_RIGHTBRACKET,  /* ] */
        GraveAccent = KEY_GRAVE,  /* ` */

        /* Function keys */
        Escape = KEY_ESCAPE,
        Enter = KEY_RETURN,
        Tab = KEY_TAB,
        Backspace = KEY_BACKSPACE,
        Insert = KEY_INSERT,
        Delete = KEY_DELETE,
        Right = KEY_RIGHT,
        Left = KEY_LEFT,
        Down = KEY_DOWN,
        Up = KEY_UP,
        PageUp = KEY_PAGEUP,
        PageDown = KEY_PAGEDOWN,
        Home = KEY_HOME,
        End = KEY_END,
        CapsLock = KEY_CAPSLOCK,
        ScrollLock = KEY_SCROLLLOCK,
        NumLock = KEY_NUMLOCKCLEAR,
        PrintScreen = KEY_PRINTSCREEN,
        Pause = KEY_PAUSE,
        F1 = KEY_F1,
        F2 = KEY_F2,
        F3 = KEY_F3,
        F4 = KEY_F4,
        F5 = KEY_F5,
        F6 = KEY_F6,
        F7 = KEY_F7,
        F8 = KEY_F8,
        F9 = KEY_F9,
        F10 = KEY_F10,
        F11 = KEY_F11,
        F12 = KEY_F12,
        F13 = KEY_F13,
        F14 = KEY_F14,
        F15 = KEY_F15,
        F16 = KEY_F16,
        F17 = KEY_F17,
        F18 = KEY_F18,
        F19 = KEY_F19,
        F20 = KEY_F20,
        F21 = KEY_F21,
        F22 = KEY_F22,
        F23 = KEY_F23,
        F24 = KEY_F24,

        /* Keypad */
        KP0 = KEY_KP_0,
        KP1 = KEY_KP_1,
        KP2 = KEY_KP_2,
        KP3 = KEY_KP_3,
        KP4 = KEY_KP_4,
        KP5 = KEY_KP_5,
        KP6 = KEY_KP_6,
        KP7 = KEY_KP_7,
        KP8 = KEY_KP_8,
        KP9 = KEY_KP_9,
        KPDecimal = KEY_KP_DECIMAL,
        KPDivide = KEY_KP_DIVIDE,
        KPMultiply = KEY_KP_MULTIPLY,
        KPSubtract = KEY_KP_MEMSUBTRACT,
        KPAdd = KEY_KP_MEMADD,
        KPEnter = KEY_KP_ENTER,
        KPEqual = KEY_KP_EQUALS,
        Menu = KEY_MENU,
    };
}
namespace KeyMod {
    enum : KeyModCode {
        None = KMOD_NONE,
        Shift = KMOD_SHIFT,
        Control = KMOD_CTRL,
        LeftShift = KMOD_LSHIFT,
        LeftControl = KMOD_LCTRL,
        LeftAlt = KMOD_LALT,
        LeftSuper = KMOD_LGUI,
        RightShift = KMOD_RSHIFT,
        RightControl = KMOD_RCTRL,
        RightAlt = KMOD_RALT,
        RightSuper = KMOD_RGUI,
        Super = KMOD_GUI,
    };
}
