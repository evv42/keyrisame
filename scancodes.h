//input is AT scancode, comment is QWERTY layout (PC-98 mapping in parenthesis)
const PROGMEM uint8_t pc98_scancode[] = {
  0xBF, //?0
  0x6A, //F9
  0xBF, //?2
  0x66, //F5
  0x64, //F3
  0x62, //F1
  0x63, //F2
  0x53, //F12
  0xBF, //?8
  0x6B, //F10
  0x69, //F8
  0x67, //F6
  0x65, //F4
  0x0F, //Tab
  0x0D, //` (YEN)
  0xBF, //?F
  0xBF, //?10
  0x73, //Left Alt (GRAPH)
  0x70, //Left Shift
  0xBF, //?13
  0x74, //Left Control
  0x10, //Q
  0x01, //1
  0xBF, //?17
  0xBF, //?18
  0xBF, //?19
  0x29, //Z
  0x1E, //S
  0x1D, //A
  0x11, //W
  0x02, //2
  0xBF, //?1F
  0xBF, //?20
  0x2B, //C
  0x2A, //X
  0x1F, //D
  0x12, //E
  0x04, //4
  0x03, //3
  0xBF, //?27
  0xBF, //?28
  0x34, //Space
  0x2C, //V
  0x20, //F
  0x14, //T
  0x13, //R
  0x05, //5
  0xBF, //?2F
  0xBF, //?30
  0x2E, //N
  0x2D, //B
  0x22, //H
  0x21, //G
  0x15, //Y
  0x06, //6
  0xBF, //?37
  0xBF, //?38
  0xBF, //?39
  0x2F, //M
  0x23, //J
  0x16, //U
  0x07, //7
  0x08, //8
  0xBF, //?3F
  0xBF, //?40
  0x30, //,
  0x24, //K
  0x17, //I
  0x18, //O
  0x0A, //0 (zero)
  0x09, //9
  0xBF, //?47
  0xBF, //?48
  0x31, //.
  0x32, //Slash
  0x25, //L
  0x26, //;
  0x19, //P
  0x0B, //-
  0xBF, //?4F
  0xBF, //?50
  0xBF, //?51
  0x27, //'
  0xBF, //?53
  0x1A, //[
  0x0C, //=
  0xBF, //?56
  0xBF, //?57
  0x71, //Caps Lock
  0x7D, //Right Shift
  0x1C, //Enter
  0x1B, //]
  0xBF, //?5C
  0x28, //Backslash
  0xBF, //?5E
  0xBF, //?5F
  0xBF, //?60
  0xBF, //<
  0xBF, //?62
  0xBF, //?63
  0xBF, //?64
  0xBF, //?65
  0x0E, //Backspace
  0xBF, //?67
  0xBF, //?68
  0x4A, //KP 1
  0xBF, //?6A
  0x46, //KP 4
  0x42, //KP 7
  0xBF, //?6D
  0xBF, //?6E
  0xBF, //?6F
  0x4E, //KP 0
  0x50, //KP .
  0x4B, //KP 2
  0x47, //KP 5
  0x48, //KP 6
  0x43, //KP 8
  0x00, //Escape
  0x60, //Num Lock (STOP)
  0x52, //F11
  0x49, //KP +
  0x4C, //KP 3
  0x40, //KP -
  0x45, //KP *
  0x44, //KP 9
  0x61, //Scroll Lock (Copy)
  0xBF, //?7F
  0xBF, //?80
  0xBF, //?81
  0xBF, //?82
  0x68, //F7
  };

//input is AT scancode (0xE0-prefixed), comment is QWERTY layout (PC-98 mapping in parenthesis)
const PROGMEM uint8_t pc98_scancode_spe[] = {
  0xBF, //?0
  0xBF, //?1
  0xBF, //?2
  0xBF, //?3
  0xBF, //?4
  0xBF, //?5
  0xBF, //?6
  0xBF, //?7
  0xBF, //?8
  0xBF, //?9
  0xBF, //?A
  0xBF, //?B
  0xBF, //?C
  0xBF, //?D
  0xBF, //?E
  0xBF, //?F
  0xBF, //?10
  0x35, //Alt Gr (XFER)
  0xBF, //?12
  0xBF, //?13
  0x72, //Right Control (KANA)
  0xBF, //?15
  0xBF, //?16
  0xBF, //?17
  0xBF, //?18
  0xBF, //?19
  0xBF, //?1A
  0xBF, //?1B
  0xBF, //?1C
  0xBF, //?1D
  0xBF, //?1E
  0x77, //Left GUI
  0xBF, //?20
  0xBF, //?21
  0xBF, //?22
  0xBF, //?23
  0xBF, //?24
  0xBF, //?25
  0xBF, //?26
  0x78, //Right GUI
  0xBF, //?28
  0xBF, //?29
  0xBF, //?2A
  0xBF, //?2B
  0xBF, //?2C
  0xBF, //?2D
  0xBF, //?2E
  0x79, //Menu
  0xBF, //?30
  0xBF, //?31
  0xBF, //?32
  0xBF, //?33
  0xBF, //?34
  0xBF, //?35
  0xBF, //?36
  0xBF, //Power
  0xBF, //?38
  0xBF, //?39
  0xBF, //?3A
  0xBF, //?3B
  0xBF, //?3C
  0xBF, //?3D
  0xBF, //?3E
  0xBF, //Sleep
  0xBF, //?40
  0xBF, //?41
  0xBF, //?42
  0xBF, //?43
  0xBF, //?44
  0xBF, //?45
  0xBF, //?46
  0xBF, //?47
  0xBF, //?48
  0xBF, //?49
  0x41, //KP /
  0xBF, //?4B
  0xBF, //?4C
  0xBF, //?4D
  0xBF, //?4E
  0xBF, //?4F
  0xBF, //?50
  0xBF, //?51
  0xBF, //?52
  0xBF, //?53
  0xBF, //?54
  0xBF, //?55
  0xBF, //?56
  0xBF, //?57
  0xBF, //?58
  0xBF, //?59
  0x1C, //KP Enter
  0xBF, //?5B
  0xBF, //?5C
  0xBF, //?5D
  0xBF, //Wake
  0xBF, //?5F
  0xBF, //?60
  0xBF, //?61
  0xBF, //?62
  0xBF, //?63
  0xBF, //?64
  0xBF, //?65
  0xBF, //?66
  0xBF, //?67
  0xBF, //?68
  0x3F, //End
  0xBF, //?6A
  0x3B, //Left
  0x3E, //Home
  0xBF, //?6D
  0xBF, //?6E
  0xBF, //?6F
  0x38, //Insert
  0x39, //Delete
  0x3D, //Down
  0xBF, //?73
  0x3C, //Right
  0x3A, //Up
  0xBF, //?76
  0xBF, //?77
  0xBF, //?78
  0xBF, //?79
  0x36, //Page Down
  0xBF, //?7B
  0xBF, //?7C
  0x37, //Page Up
  };
