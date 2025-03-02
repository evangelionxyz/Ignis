#pragma once

#define IGN_KEY_EXTENDED_MASK          (1u << 29)
#define IGN_KEY_SCANCODE_MASK          (1u << 30)
#define IGN_KEY_SCANCODE_TO_KEYCODE(X) (X | KEY_SCANCODE_MASK)
#define IGN_KEY_UNKNOWN                0x00000000u /**< 0 */
#define IGN_KEY_RETURN                 0x0000000du /**< '\r' */
#define IGN_KEY_ESCAPE                 0x0000001bu /**< '\x1B' */
#define IGN_KEY_BACKSPACE              0x00000008u /**< '\b' */
#define IGN_KEY_TAB                    0x00000009u /**< '\t' */
#define IGN_KEY_SPACE                  0x00000020u /**< ' ' */
#define IGN_KEY_EXCLAIM                0x00000021u /**< '!' */
#define IGN_KEY_DBLAPOSTROPHE          0x00000022u /**< '"' */
#define IGN_KEY_HASH                   0x00000023u /**< '#' */
#define IGN_KEY_DOLLAR                 0x00000024u /**< '$' */
#define IGN_KEY_PERCENT                0x00000025u /**< '%' */
#define IGN_KEY_AMPERSAND              0x00000026u /**< '&' */
#define IGN_KEY_APOSTROPHE             0x00000027u /**< '\'' */
#define IGN_KEY_LEFTPAREN              0x00000028u /**< '(' */
#define IGN_KEY_RIGHTPAREN             0x00000029u /**< ')' */
#define IGN_KEY_ASTERISK               0x0000002au /**< '*' */
#define IGN_KEY_PLUS                   0x0000002bu /**< '+' */
#define IGN_KEY_COMMA                  0x0000002cu /**< ',' */
#define IGN_KEY_MINUS                  0x0000002du /**< '-' */
#define IGN_KEY_PERIOD                 0x0000002eu /**< '.' */
#define IGN_KEY_SLASH                  0x0000002fu /**< '/' */
#define IGN_KEY_0                      0x00000030u /**< '0' */
#define IGN_KEY_1                      0x00000031u /**< '1' */
#define IGN_KEY_2                      0x00000032u /**< '2' */
#define IGN_KEY_3                      0x00000033u /**< '3' */
#define IGN_KEY_4                      0x00000034u /**< '4' */
#define IGN_KEY_5                      0x00000035u /**< '5' */
#define IGN_KEY_6                      0x00000036u /**< '6' */
#define IGN_KEY_7                      0x00000037u /**< '7' */
#define IGN_KEY_8                      0x00000038u /**< '8' */
#define IGN_KEY_9                      0x00000039u /**< '9' */
#define IGN_KEY_COLON                  0x0000003au /**< ':' */
#define IGN_KEY_SEMICOLON              0x0000003bu /**< ';' */
#define IGN_KEY_LESS                   0x0000003cu /**< '<' */
#define IGN_KEY_EQUALS                 0x0000003du /**< '=' */
#define IGN_KEY_GREATER                0x0000003eu /**< '>' */
#define IGN_KEY_QUESTION               0x0000003fu /**< '?' */
#define IGN_KEY_AT                     0x00000040u /**< '@' */
#define IGN_KEY_LEFTBRACKET            0x0000005bu /**< '[' */
#define IGN_KEY_BACKSLASH              0x0000005cu /**< '\\' */
#define IGN_KEY_RIGHTBRACKET           0x0000005du /**< ']' */
#define IGN_KEY_CARET                  0x0000005eu /**< '^' */
#define IGN_KEY_UNDERSCORE             0x0000005fu /**< '_' */
#define IGN_KEY_GRAVE                  0x00000060u /**< '`' */
#define IGN_KEY_A                      0x00000061u /**< 'a' */
#define IGN_KEY_B                      0x00000062u /**< 'b' */
#define IGN_KEY_C                      0x00000063u /**< 'c' */
#define IGN_KEY_D                      0x00000064u /**< 'd' */
#define IGN_KEY_E                      0x00000065u /**< 'e' */
#define IGN_KEY_F                      0x00000066u /**< 'f' */
#define IGN_KEY_G                      0x00000067u /**< 'g' */
#define IGN_KEY_H                      0x00000068u /**< 'h' */
#define IGN_KEY_I                      0x00000069u /**< 'i' */
#define IGN_KEY_J                      0x0000006au /**< 'j' */
#define IGN_KEY_K                      0x0000006bu /**< 'k' */
#define IGN_KEY_L                      0x0000006cu /**< 'l' */
#define IGN_KEY_M                      0x0000006du /**< 'm' */
#define IGN_KEY_N                      0x0000006eu /**< 'n' */
#define IGN_KEY_O                      0x0000006fu /**< 'o' */
#define IGN_KEY_P                      0x00000070u /**< 'p' */
#define IGN_KEY_Q                      0x00000071u /**< 'q' */
#define IGN_KEY_R                      0x00000072u /**< 'r' */
#define IGN_KEY_S                      0x00000073u /**< 's' */
#define IGN_KEY_T                      0x00000074u /**< 't' */
#define IGN_KEY_U                      0x00000075u /**< 'u' */
#define IGN_KEY_V                      0x00000076u /**< 'v' */
#define IGN_KEY_W                      0x00000077u /**< 'w' */
#define IGN_KEY_X                      0x00000078u /**< 'x' */
#define IGN_KEY_Y                      0x00000079u /**< 'y' */
#define IGN_KEY_Z                      0x0000007au /**< 'z' */
#define IGN_KEY_LEFTBRACE              0x0000007bu /**< '{' */
#define IGN_KEY_PIPE                   0x0000007cu /**< '|' */
#define IGN_KEY_RIGHTBRACE             0x0000007du /**< '}' */
#define IGN_KEY_TILDE                  0x0000007eu /**< '~' */
#define IGN_KEY_DELETE                 0x0000007fu /**< '\x7F' */
#define IGN_KEY_PLUSMINUS              0x000000b1u /**< '\xB1' */
#define IGN_KEY_CAPSLOCK               0x40000039u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CAPSLOCK) */
#define IGN_KEY_F1                     0x4000003au /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F1) */
#define IGN_KEY_F2                     0x4000003bu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F2) */
#define IGN_KEY_F3                     0x4000003cu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F3) */
#define IGN_KEY_F4                     0x4000003du /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F4) */
#define IGN_KEY_F5                     0x4000003eu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F5) */
#define IGN_KEY_F6                     0x4000003fu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F6) */
#define IGN_KEY_F7                     0x40000040u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F7) */
#define IGN_KEY_F8                     0x40000041u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F8) */
#define IGN_KEY_F9                     0x40000042u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F9) */
#define IGN_KEY_F10                    0x40000043u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F10) */
#define IGN_KEY_F11                    0x40000044u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F11) */
#define IGN_KEY_F12                    0x40000045u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F12) */
#define IGN_KEY_PRINTSCREEN            0x40000046u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PRINTSCREEN) */
#define IGN_KEY_SCROLLLOCK             0x40000047u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SCROLLLOCK) */
#define IGN_KEY_PAUSE                  0x40000048u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PAUSE) */
#define IGN_KEY_INSERT                 0x40000049u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_INSERT) */
#define IGN_KEY_HOME                   0x4000004au /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_HOME) */
#define IGN_KEY_PAGEUP                 0x4000004bu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PAGEUP) */
#define IGN_KEY_END                    0x4000004du /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_END) */
#define IGN_KEY_PAGEDOWN               0x4000004eu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PAGEDOWN) */
#define IGN_KEY_RIGHT                  0x4000004fu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RIGHT) */
#define IGN_KEY_LEFT                   0x40000050u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LEFT) */
#define IGN_KEY_DOWN                   0x40000051u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_DOWN) */
#define IGN_KEY_UP                     0x40000052u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_UP) */
#define IGN_KEY_NUMLOCKCLEAR           0x40000053u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_NUMLOCKCLEAR) */
#define IGN_KEY_KP_DIVIDE              0x40000054u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_DIVIDE) */
#define IGN_KEY_KP_MULTIPLY            0x40000055u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MULTIPLY) */
#define IGN_KEY_KP_MINUS               0x40000056u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MINUS) */
#define IGN_KEY_KP_PLUS                0x40000057u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_PLUS) */
#define IGN_KEY_KP_ENTER               0x40000058u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_ENTER) */
#define IGN_KEY_KP_1                   0x40000059u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_1) */
#define IGN_KEY_KP_2                   0x4000005au /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_2) */
#define IGN_KEY_KP_3                   0x4000005bu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_3) */
#define IGN_KEY_KP_4                   0x4000005cu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_4) */
#define IGN_KEY_KP_5                   0x4000005du /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_5) */
#define IGN_KEY_KP_6                   0x4000005eu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_6) */
#define IGN_KEY_KP_7                   0x4000005fu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_7) */
#define IGN_KEY_KP_8                   0x40000060u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_8) */
#define IGN_KEY_KP_9                   0x40000061u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_9) */
#define IGN_KEY_KP_0                   0x40000062u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_0) */
#define IGN_KEY_KP_PERIOD              0x40000063u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_PERIOD) */
#define IGN_KEY_APPLICATION            0x40000065u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_APPLICATION) */
#define IGN_KEY_POWER                  0x40000066u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_POWER) */
#define IGN_KEY_KP_EQUALS              0x40000067u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_EQUALS) */
#define IGN_KEY_F13                    0x40000068u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F13) */
#define IGN_KEY_F14                    0x40000069u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F14) */
#define IGN_KEY_F15                    0x4000006au /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F15) */
#define IGN_KEY_F16                    0x4000006bu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F16) */
#define IGN_KEY_F17                    0x4000006cu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F17) */
#define IGN_KEY_F18                    0x4000006du /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F18) */
#define IGN_KEY_F19                    0x4000006eu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F19) */
#define IGN_KEY_F20                    0x4000006fu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F20) */
#define IGN_KEY_F21                    0x40000070u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F21) */
#define IGN_KEY_F22                    0x40000071u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F22) */
#define IGN_KEY_F23                    0x40000072u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F23) */
#define IGN_KEY_F24                    0x40000073u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F24) */
#define IGN_KEY_EXECUTE                0x40000074u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_EXECUTE) */
#define IGN_KEY_HELP                   0x40000075u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_HELP) */
#define IGN_KEY_MENU                   0x40000076u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MENU) */
#define IGN_KEY_SELECT                 0x40000077u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SELECT) */
#define IGN_KEY_STOP                   0x40000078u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_STOP) */
#define IGN_KEY_AGAIN                  0x40000079u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AGAIN) */
#define IGN_KEY_UNDO                   0x4000007au /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_UNDO) */
#define IGN_KEY_CUT                    0x4000007bu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CUT) */
#define IGN_KEY_COPY                   0x4000007cu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_COPY) */
#define IGN_KEY_PASTE                  0x4000007du /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PASTE) */
#define IGN_KEY_FIND                   0x4000007eu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_FIND) */
#define IGN_KEY_MUTE                   0x4000007fu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MUTE) */
#define IGN_KEY_VOLUMEUP               0x40000080u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_VOLUMEUP) */
#define IGN_KEY_VOLUMEDOWN             0x40000081u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_VOLUMEDOWN) */
#define IGN_KEY_KP_COMMA               0x40000085u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_COMMA) */
#define IGN_KEY_KP_EQUALSAS400         0x40000086u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_EQUALSAS400) */
#define IGN_KEY_ALTERASE               0x40000099u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_ALTERASE) */
#define IGN_KEY_SYSREQ                 0x4000009au /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SYSREQ) */
#define IGN_KEY_CANCEL                 0x4000009bu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CANCEL) */
#define IGN_KEY_CLEAR                  0x4000009cu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CLEAR) */
#define IGN_KEY_PRIOR                  0x4000009du /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PRIOR) */
#define IGN_KEY_RETURN2                0x4000009eu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RETURN2) */
#define IGN_KEY_SEPARATOR              0x4000009fu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SEPARATOR) */
#define IGN_KEY_OUT                    0x400000a0u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_OUT) */
#define IGN_KEY_OPER                   0x400000a1u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_OPER) */
#define IGN_KEY_CLEARAGAIN             0x400000a2u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CLEARAGAIN) */
#define IGN_KEY_CRSEL                  0x400000a3u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CRSEL) */
#define IGN_KEY_EXSEL                  0x400000a4u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_EXSEL) */
#define IGN_KEY_KP_00                  0x400000b0u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_00) */
#define IGN_KEY_KP_000                 0x400000b1u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_000) */
#define IGN_KEY_THOUSANDSSEPARATOR     0x400000b2u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_THOUSANDSSEPARATOR) */
#define IGN_KEY_DECIMALSEPARATOR       0x400000b3u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_DECIMALSEPARATOR) */
#define IGN_KEY_CURRENCYUNIT           0x400000b4u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CURRENCYUNIT) */
#define IGN_KEY_CURRENCYSUBUNIT        0x400000b5u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CURRENCYSUBUNIT) */
#define IGN_KEY_KP_LEFTPAREN           0x400000b6u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_LEFTPAREN) */
#define IGN_KEY_KP_RIGHTPAREN          0x400000b7u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_RIGHTPAREN) */
#define IGN_KEY_KP_LEFTBRACE           0x400000b8u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_LEFTBRACE) */
#define IGN_KEY_KP_RIGHTBRACE          0x400000b9u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_RIGHTBRACE) */
#define IGN_KEY_KP_TAB                 0x400000bau /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_TAB) */
#define IGN_KEY_KP_BACKSPACE           0x400000bbu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_BACKSPACE) */
#define IGN_KEY_KP_A                   0x400000bcu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_A) */
#define IGN_KEY_KP_B                   0x400000bdu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_B) */
#define IGN_KEY_KP_C                   0x400000beu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_C) */
#define IGN_KEY_KP_D                   0x400000bfu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_D) */
#define IGN_KEY_KP_E                   0x400000c0u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_E) */
#define IGN_KEY_KP_F                   0x400000c1u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_F) */
#define IGN_KEY_KP_XOR                 0x400000c2u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_XOR) */
#define IGN_KEY_KP_POWER               0x400000c3u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_POWER) */
#define IGN_KEY_KP_PERCENT             0x400000c4u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_PERCENT) */
#define IGN_KEY_KP_LESS                0x400000c5u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_LESS) */
#define IGN_KEY_KP_GREATER             0x400000c6u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_GREATER) */
#define IGN_KEY_KP_AMPERSAND           0x400000c7u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_AMPERSAND) */
#define IGN_KEY_KP_DBLAMPERSAND        0x400000c8u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_DBLAMPERSAND) */
#define IGN_KEY_KP_VERTICALBAR         0x400000c9u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_VERTICALBAR) */
#define IGN_KEY_KP_DBLVERTICALBAR      0x400000cau /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_DBLVERTICALBAR) */
#define IGN_KEY_KP_COLON               0x400000cbu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_COLON) */
#define IGN_KEY_KP_HASH                0x400000ccu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_HASH) */
#define IGN_KEY_KP_SPACE               0x400000cdu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_SPACE) */
#define IGN_KEY_KP_AT                  0x400000ceu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_AT) */
#define IGN_KEY_KP_EXCLAM              0x400000cfu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_EXCLAM) */
#define IGN_KEY_KP_MEMSTORE            0x400000d0u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMSTORE) */
#define IGN_KEY_KP_MEMRECALL           0x400000d1u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMRECALL) */
#define IGN_KEY_KP_MEMCLEAR            0x400000d2u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMCLEAR) */
#define IGN_KEY_KP_MEMADD              0x400000d3u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMADD) */
#define IGN_KEY_KP_MEMSUBTRACT         0x400000d4u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMSUBTRACT) */
#define IGN_KEY_KP_MEMMULTIPLY         0x400000d5u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMMULTIPLY) */
#define IGN_KEY_KP_MEMDIVIDE           0x400000d6u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMDIVIDE) */
#define IGN_KEY_KP_PLUSMINUS           0x400000d7u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_PLUSMINUS) */
#define IGN_KEY_KP_CLEAR               0x400000d8u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_CLEAR) */
#define IGN_KEY_KP_CLEARENTRY          0x400000d9u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_CLEARENTRY) */
#define IGN_KEY_KP_BINARY              0x400000dau /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_BINARY) */
#define IGN_KEY_KP_OCTAL               0x400000dbu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_OCTAL) */
#define IGN_KEY_KP_DECIMAL             0x400000dcu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_DECIMAL) */
#define IGN_KEY_KP_HEXADECIMAL         0x400000ddu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_HEXADECIMAL) */
#define IGN_KEY_LCTRL                  0x400000e0u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LCTRL) */
#define IGN_KEY_LSHIFT                 0x400000e1u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LSHIFT) */
#define IGN_KEY_LALT                   0x400000e2u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LALT) */
#define IGN_KEY_LGUI                   0x400000e3u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LGUI) */
#define IGN_KEY_RCTRL                  0x400000e4u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RCTRL) */
#define IGN_KEY_RSHIFT                 0x400000e5u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RSHIFT) */
#define IGN_KEY_RALT                   0x400000e6u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RALT) */
#define IGN_KEY_RGUI                   0x400000e7u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RGUI) */
#define IGN_KEY_MODE                   0x40000101u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MODE) */
#define IGN_KEY_SLEEP                  0x40000102u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SLEEP) */
#define IGN_KEY_WAKE                   0x40000103u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_WAKE) */
#define IGN_KEY_CHANNEL_INCREMENT      0x40000104u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CHANNEL_INCREMENT) */
#define IGN_KEY_CHANNEL_DECREMENT      0x40000105u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CHANNEL_DECREMENT) */
#define IGN_KEY_MEDIA_PLAY             0x40000106u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_PLAY) */
#define IGN_KEY_MEDIA_PAUSE            0x40000107u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_PAUSE) */
#define IGN_KEY_MEDIA_RECORD           0x40000108u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_RECORD) */
#define IGN_KEY_MEDIA_FAST_FORWARD     0x40000109u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_FAST_FORWARD) */
#define IGN_KEY_MEDIA_REWIND           0x4000010au /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_REWIND) */
#define IGN_KEY_MEDIA_NEXT_TRACK       0x4000010bu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_NEXT_TRACK) */
#define IGN_KEY_MEDIA_PREVIOUS_TRACK   0x4000010cu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_PREVIOUS_TRACK) */
#define IGN_KEY_MEDIA_STOP             0x4000010du /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_STOP) */
#define IGN_KEY_MEDIA_EJECT            0x4000010eu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_EJECT) */
#define IGN_KEY_MEDIA_PLAY_PAUSE       0x4000010fu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_PLAY_PAUSE) */
#define IGN_KEY_MEDIA_SELECT           0x40000110u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_SELECT) */
#define IGN_KEY_AC_NEW                 0x40000111u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_NEW) */
#define IGN_KEY_AC_OPEN                0x40000112u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_OPEN) */
#define IGN_KEY_AC_CLOSE               0x40000113u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_CLOSE) */
#define IGN_KEY_AC_EXIT                0x40000114u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_EXIT) */
#define IGN_KEY_AC_SAVE                0x40000115u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_SAVE) */
#define IGN_KEY_AC_PRINT               0x40000116u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_PRINT) */
#define IGN_KEY_AC_PROPERTIES          0x40000117u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_PROPERTIES) */
#define IGN_KEY_AC_SEARCH              0x40000118u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_SEARCH) */
#define IGN_KEY_AC_HOME                0x40000119u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_HOME) */
#define IGN_KEY_AC_BACK                0x4000011au /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_BACK) */
#define IGN_KEY_AC_FORWARD             0x4000011bu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_FORWARD) */
#define IGN_KEY_AC_STOP                0x4000011cu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_STOP) */
#define IGN_KEY_AC_REFRESH             0x4000011du /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_REFRESH) */
#define IGN_KEY_AC_BOOKMARKS           0x4000011eu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_BOOKMARKS) */
#define IGN_KEY_SOFTLEFT               0x4000011fu /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SOFTLEFT) */
#define IGN_KEY_SOFTRIGHT              0x40000120u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SOFTRIGHT) */
#define IGN_KEY_CALL                   0x40000121u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CALL) */
#define IGN_KEY_ENDCALL                0x40000122u /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_ENDCALL) */
#define IGN_KEY_LEFT_TAB               0x20000001u /**< Extended key Left Tab */
#define IGN_KEY_LEVEL5_SHIFT           0x20000002u /**< Extended key Level 5 Shift */
#define IGN_KEY_MULTI_KEY_COMPOSE      0x20000003u /**< Extended key Multi-key Compose */
#define IGN_KEY_LMETA                  0x20000004u /**< Extended key Left Meta */
#define IGN_KEY_RMETA                  0x20000005u /**< Extended key Right Meta */
#define IGN_KEY_LHYPER                 0x20000006u /**< Extended key Left Hyper */
#define IGN_KEY_RHYPER                 0x20000007u /**< Extended key Right Hyper */

#define IGN_KEY_MOD_NONE   0x0000u /**< no modifier is applicable. */
#define IGN_KEY_MOD_LSHIFT 0x0001u /**< the left Shift key is down. */
#define IGN_KEY_MOD_RSHIFT 0x0002u /**< the right Shift key is down. */
#define IGN_KEY_MOD_LEVEL5 0x0004u /**< the Level 5 Shift key is down. */
#define IGN_KEY_MOD_LCTRL  0x0040u /**< the left Ctrl (Control) key is down. */
#define IGN_KEY_MOD_RCTRL  0x0080u /**< the right Ctrl (Control) key is down. */
#define IGN_KEY_MOD_LALT   0x0100u /**< the left Alt key is down. */
#define IGN_KEY_MOD_RALT   0x0200u /**< the right Alt key is down. */
#define IGN_KEY_MOD_LGUI   0x0400u /**< the left GUI key (often the Windows key) is down. */
#define IGN_KEY_MOD_RGUI   0x0800u /**< the right GUI key (often the Windows key) is down. */
#define IGN_KEY_MOD_NUM    0x1000u /**< the Num Lock key (may be located on an extended keypad) is down. */
#define IGN_KEY_MOD_CAPS   0x2000u /**< the Caps Lock key is down. */
#define IGN_KEY_MOD_MODE   0x4000u /**< the !AltGr key is down. */
#define IGN_KEY_MOD_SCROLL 0x8000u /**< the Scroll Lock key is down. */
#define IGN_KEY_MOD_CTRL   (IGN_KEY_MOD_LCTRL | IGN_KEY_MOD_RCTRL)   /**< Any Ctrl key is down. */
#define IGN_KEY_MOD_SHIFT  (IGN_KEY_MOD_LSHIFT | IGN_KEY_MOD_RSHIFT) /**< Any Shift key is down. */
#define IGN_KEY_MOD_ALT    (IGN_KEY_MOD_LALT | IGN_KEY_MOD_RALT)     /**< Any Alt key is down. */
#define IGN_KEY_MOD_GUI    (IGN_KEY_MOD_LGUI | IGN_KEY_MOD_RGUI)     /**< Any GUI key is down. */

using KeyCode = u32;
using KeyModCode = u16;

namespace Key {
    enum : KeyCode
    {
        Space = IGN_KEY_SPACE,
        Apostrophe = IGN_KEY_APOSTROPHE, /* ' */
        Comma = IGN_KEY_COMMA, /* , */
        Minus = IGN_KEY_MINUS, /* - */
        Period = IGN_KEY_PERIOD, /* . */
        Slash = IGN_KEY_SLASH, /* / */

        D0 = IGN_KEY_0, /* 0 */
        D1 = IGN_KEY_1, /* 1 */
        D2 = IGN_KEY_2, /* 2 */
        D3 = IGN_KEY_3, /* 3 */
        D4 = IGN_KEY_4, /* 4 */
        D5 = IGN_KEY_5, /* 5 */
        D6 = IGN_KEY_6, /* 6 */
        D7 = IGN_KEY_7, /* 7 */
        D8 = IGN_KEY_8, /* 8 */
        D9 = IGN_KEY_9, /* 9 */

        Semicolon = IGN_KEY_SEMICOLON, /* ; */
        Equal = IGN_KEY_EQUALS, /* = */

        A = IGN_KEY_A,
        B = IGN_KEY_B,
        C = IGN_KEY_C,
        D = IGN_KEY_D,
        E = IGN_KEY_E,
        F = IGN_KEY_F,
        G = IGN_KEY_G,
        H = IGN_KEY_H,
        I = IGN_KEY_I,
        J = IGN_KEY_J,
        K = IGN_KEY_K,
        L = IGN_KEY_L,
        M = IGN_KEY_M,
        N = IGN_KEY_N,
        O = IGN_KEY_O,
        P = IGN_KEY_P,
        Q = IGN_KEY_Q,
        R = IGN_KEY_R,
        S = IGN_KEY_S,
        T = IGN_KEY_T,
        U = IGN_KEY_U,
        V = IGN_KEY_V,
        W = IGN_KEY_W,
        X = IGN_KEY_X,
        Y = IGN_KEY_Y,
        Z = IGN_KEY_Z,

        LeftBracket = IGN_KEY_LEFTBRACKET,  /* [ */
        Backslash = IGN_KEY_BACKSLASH,  /* \ */
        RightBracket = IGN_KEY_RIGHTBRACKET,  /* ] */
        GraveAccent = IGN_KEY_GRAVE,  /* ` */

        /* Function keys */
        Escape = IGN_KEY_ESCAPE,
        Enter = IGN_KEY_RETURN,
        Tab = IGN_KEY_TAB,
        Backspace = IGN_KEY_BACKSPACE,
        Insert = IGN_KEY_INSERT,
        Delete = IGN_KEY_DELETE,
        Right = IGN_KEY_RIGHT,
        Left = IGN_KEY_LEFT,
        Down = IGN_KEY_DOWN,
        Up = IGN_KEY_UP,
        PageUp = IGN_KEY_PAGEUP,
        PageDown = IGN_KEY_PAGEDOWN,
        Home = IGN_KEY_HOME,
        End = IGN_KEY_END,
        CapsLock = IGN_KEY_CAPSLOCK,
        ScrollLock = IGN_KEY_SCROLLLOCK,
        NumLock = IGN_KEY_NUMLOCKCLEAR,
        PrintScreen = IGN_KEY_PRINTSCREEN,
        Pause = IGN_KEY_PAUSE,
        F1 = IGN_KEY_F1,
        F2 = IGN_KEY_F2,
        F3 = IGN_KEY_F3,
        F4 = IGN_KEY_F4,
        F5 = IGN_KEY_F5,
        F6 = IGN_KEY_F6,
        F7 = IGN_KEY_F7,
        F8 = IGN_KEY_F8,
        F9 = IGN_KEY_F9,
        F10 = IGN_KEY_F10,
        F11 = IGN_KEY_F11,
        F12 = IGN_KEY_F12,
        F13 = IGN_KEY_F13,
        F14 = IGN_KEY_F14,
        F15 = IGN_KEY_F15,
        F16 = IGN_KEY_F16,
        F17 = IGN_KEY_F17,
        F18 = IGN_KEY_F18,
        F19 = IGN_KEY_F19,
        F20 = IGN_KEY_F20,
        F21 = IGN_KEY_F21,
        F22 = IGN_KEY_F22,
        F23 = IGN_KEY_F23,
        F24 = IGN_KEY_F24,

        /* Keypad */
        KP0 = IGN_KEY_KP_0,
        KP1 = IGN_KEY_KP_1,
        KP2 = IGN_KEY_KP_2,
        KP3 = IGN_KEY_KP_3,
        KP4 = IGN_KEY_KP_4,
        KP5 = IGN_KEY_KP_5,
        KP6 = IGN_KEY_KP_6,
        KP7 = IGN_KEY_KP_7,
        KP8 = IGN_KEY_KP_8,
        KP9 = IGN_KEY_KP_9,
        KPDecimal = IGN_KEY_KP_DECIMAL,
        KPDivide = IGN_KEY_KP_DIVIDE,
        KPMultiply = IGN_KEY_KP_MULTIPLY,
        KPSubtract = IGN_KEY_KP_MEMSUBTRACT,
        KPAdd = IGN_KEY_KP_MEMADD,
        KPEnter = IGN_KEY_KP_ENTER,
        KPEqual = IGN_KEY_KP_EQUALS,
        Menu = IGN_KEY_MENU,
    };
}
namespace KeyMod {
    enum : KeyModCode {
        None         = IGN_KEY_MOD_NONE,
        Shift        = IGN_KEY_MOD_SHIFT,
        Control      = IGN_KEY_MOD_CTRL,
        LeftShift    = IGN_KEY_MOD_LSHIFT,
        LeftControl  = IGN_KEY_MOD_LCTRL,
        LeftAlt      = IGN_KEY_MOD_LALT,
        LeftSuper    = IGN_KEY_MOD_LGUI,
        RightShift   = IGN_KEY_MOD_RSHIFT,
        RightControl = IGN_KEY_MOD_RCTRL,
        RightAlt     = IGN_KEY_MOD_RALT,
        RightSuper   = IGN_KEY_MOD_RGUI,
        Super        = IGN_KEY_MOD_GUI,
        Alt          = IGN_KEY_MOD_ALT,
    };
}
