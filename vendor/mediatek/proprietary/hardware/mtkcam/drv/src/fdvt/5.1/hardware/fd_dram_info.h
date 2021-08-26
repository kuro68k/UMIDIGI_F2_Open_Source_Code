const signed int input_RDMA_RA_buffer_en[66][4][2] = { // [loop][ch][output_index]
{{99,99}, {99,99}, {99,99}, {-1,-1}}, // rs_scale2
{{0,0}, {-1,-1}, {-1,-1}, {-1,-1}},
{{0,0}, {1,0}, {-1,-1}, {-1,-1}},
{{2,0}, {-1,-1}, {-1,-1}, {-1,-1}},
{{0,2}, {1,2}, {3,2}, {3,3}},
{{4,0}, {4,1}, {-1,-1}, {-1,-1}},
{{4,0}, {4,1}, {5,0}, {-1,-1}},
{{6,0}, {6,1}, {-1,-1}, {-1,-1}},
{{4,2}, {4,3}, {5,2}, {7,2}},
{{8,0}, {8,1}, {-1,-1}, {-1,-1}},
{{9,0}, {-1,-1}, {-1,-1}, {-1,-1}},
{{10,0}, {-1,-1}, {-1,-1}, {-1,-1}},
{{8,0}, {8,1}, {11,0}, {-1,-1}},
{{12,0}, {-1,-1}, {-1,-1}, {-1,-1}},
{{13,0}, {-1,-1}, {-1,-1}, {-1,-1}},
{{8,0}, {8,1}, {11,0}, {14,0}},
{{15,0}, {15,1}, {-1,-1}, {-1,-1}},
{{15,0}, {15,1}, {-1,-1}, {-1,-1}},
{{15,0}, {15,1}, {-1,-1}, {-1,-1}},
{{17,0}, {16,0}, {16,1}, {18,0}},
{{99,99}, {99,99}, {99,99}, {-1,-1}}, // rs_scale1
{{20,0}, {-1,-1}, {-1,-1}, {-1,-1}},
{{20,0}, {21,0}, {-1,-1}, {-1,-1}},
{{22,0}, {-1,-1}, {-1,-1}, {-1,-1}},
{{20,2}, {21,2}, {23,2}, {23,3}},
{{24,0}, {24,1}, {-1,-1}, {-1,-1}},
{{24,0}, {24,1}, {25,0}, {-1,-1}},
{{26,0}, {26,1}, {-1,-1}, {-1,-1}},
{{24,2}, {24,3}, {25,2}, {27,2}},
{{28,0}, {28,1}, {-1,-1}, {-1,-1}},
{{29,0}, {-1,-1}, {-1,-1}, {-1,-1}},
{{30,0}, {-1,-1}, {-1,-1}, {-1,-1}},
{{28,0}, {28,1}, {31,0}, {-1,-1}},
{{32,0}, {-1,-1}, {-1,-1}, {-1,-1}},
{{33,0}, {-1,-1}, {-1,-1}, {-1,-1}},
{{28,0}, {28,1}, {31,0}, {34,0}},
{{35,0}, {35,1}, {-1,-1}, {-1,-1}},
{{35,0}, {35,1}, {-1,-1}, {-1,-1}},
{{35,0}, {35,1}, {-1,-1}, {-1,-1}},
{{37,0}, {36,0}, {36,1}, {38,0}},
{{99,99}, {99,99}, {99,99}, {-1,-1}}, // rs_scale0
{{40,0}, {-1,-1}, {-1,-1}, {-1,-1}},
{{40,0}, {41,0}, {-1,-1}, {-1,-1}},
{{42,0}, {-1,-1}, {-1,-1}, {-1,-1}},
{{40,2}, {41,2}, {43,2}, {43,3}},
{{44,0}, {44,1}, {-1,-1}, {-1,-1}},
{{44,0}, {44,1}, {45,0}, {-1,-1}},
{{46,0}, {46,1}, {-1,-1}, {-1,-1}},
{{44,2}, {44,3}, {45,2}, {47,2}},
{{48,0}, {48,1}, {-1,-1}, {-1,-1}},
{{49,0}, {-1,-1}, {-1,-1}, {-1,-1}},
{{50,0}, {-1,-1}, {-1,-1}, {-1,-1}},
{{48,0}, {48,1}, {51,0}, {-1,-1}},
{{52,0}, {-1,-1}, {-1,-1}, {-1,-1}},
{{53,0}, {-1,-1}, {-1,-1}, {-1,-1}},
{{48,0}, {48,1}, {51,0}, {54,0}},
{{55,0}, {55,1}, {-1,-1}, {-1,-1}},
{{55,0}, {55,1}, {-1,-1}, {-1,-1}},
{{55,0}, {55,1}, {-1,-1}, {-1,-1}},
{{55,0}, {55,1}, {-1,-1}, {-1,-1}},
{{55,0}, {55,1}, {-1,-1}, {-1,-1}},
{{55,0}, {55,1}, {-1,-1}, {-1,-1}},
{{55,0}, {55,1}, {-1,-1}, {-1,-1}},
{{55,0}, {55,1}, {-1,-1}, {-1,-1}},
{{55,0}, {55,1}, {-1,-1}, {-1,-1}},
{{59,0}, {56,0}, {56,1}, {62,0}}};

const unsigned int output_WDMA_WRA_buffer_en[66][4] = { // [loop][ch]
{1, 0, 1, 0},
{1, 0, 1, 0},
{1, 0, 0, 0},
{1, 1, 1, 1},
{1, 1, 1, 1},
{1, 0, 1, 0},
{1, 1, 0, 0},
{1, 0, 1, 0},
{1, 1, 0, 0},
{1, 0, 0, 0},
{1, 0, 0, 0},
{1, 0, 0, 0},
{1, 0, 0, 0},
{1, 0, 0, 0},
{1, 0, 0, 0},
{1, 1, 0, 0},
{1, 1, 1, 1},
{1, 1, 0, 0},
{1, 1, 0, 0},
{1, 0, 0, 0},
{1, 0, 1, 0},
{1, 0, 1, 0},
{1, 0, 0, 0},
{1, 1, 1, 1},
{1, 1, 1, 1},
{1, 0, 1, 0},
{1, 1, 0, 0},
{1, 0, 1, 0},
{1, 1, 0, 0},
{1, 0, 0, 0},
{1, 0, 0, 0},
{1, 0, 0, 0},
{1, 0, 0, 0},
{1, 0, 0, 0},
{1, 0, 0, 0},
{1, 1, 0, 0},
{1, 1, 1, 1},
{1, 1, 0, 0},
{1, 1, 0, 0},
{1, 0, 0, 0},
{1, 0, 1, 0},
{1, 0, 1, 0},
{1, 0, 0, 0},
{1, 1, 1, 1},
{1, 1, 1, 1},
{1, 0, 1, 0},
{1, 1, 0, 0},
{1, 0, 1, 0},
{1, 1, 0, 0},
{1, 0, 0, 0},
{1, 0, 0, 0},
{1, 0, 0, 0},
{1, 0, 0, 0},
{1, 0, 0, 0},
{1, 0, 0, 0},
{1, 1, 0, 0},
{1, 1, 1, 1},
{1, 1, 1, 1},
{1, 1, 0, 0},
{1, 1, 0, 0},
{1, 1, 0, 0},
{1, 0, 0, 0},
{1, 1, 0, 0},
{1, 1, 0, 0},
{1, 0, 0, 0},
{1, 0, 0, 0}};


const unsigned int out_stride_size[66][4] = {
{1,	0,	2,	0},
{1,	0,	2,	0},
{1,	0,	0,	0},
{1,	1,	2,	2},
{1,	1,	2,	2},
{1,	0,	2,	0},
{1,	1,	0,	0},
{1,	0,	2,	0},
{1,	1,	0,	0},
{1,	0,	0,	0},
{1,	0,	0,	0},
{1,	0,	0,	0},
{1,	0,	0,	0},
{1,	0,	0,	0},
{1,	0,	0,	0},
{1,	1,	0,	0},
{1,	1,	1,	1},
{1,	1,	0,	0},
{1,	1,	0,	0},
{3,	0,	0,	0},
{1,	0,	2,	0},
{1,	0,	2,	0},
{1,	0,	0,	0},
{1,	1,	2,	2},
{1,	1,	2,	2},
{1,	0,	2,	0},
{1,	1,	0,	0},
{1,	0,	2,	0},
{1,	1,	0,	0},
{1,	0,	0,	0},
{1,	0,	0,	0},
{1,	0,	0,	0},
{1,	0,	0,	0},
{1,	0,	0,	0},
{1,	0,	0,	0},
{1,	1,	0,	0},
{1,	1,	1,	1},
{1,	1,	0,	0},
{1,	1,	0,	0},
{3,	0,	0,	0},
{1,	0,	2,	0},
{1,	0,	2,	0},
{1,	0,	0,	0},
{1,	1,	2,	2},
{1,	1,	2,	2},
{1,	0,	2,	0},
{1,	1,	0,	0},
{1,	0,	2,	0},
{1,	1,	0,	0},
{1,	0,	0,	0},
{1,	0,	0,	0},
{1,	0,	0,	0},
{1,	0,	0,	0},
{1,	0,	0,	0},
{1,	0,	0,	0},
{1,	1,	0,	0},
{1,	1,	1,	1},
{1,	1,	1,	1},
{1,	1,	0,	0},
{1,	1,	0,	0},
{1,	1,	0,	0},
{1,	0,	0,	0},
{1,	1,	0,	0},
{1,	1,	0,	0},
{1,	0,	0,	0},
{3,	0,	0,	0}};




#if 1
unsigned int output_WDMA_WRA_buffer_size[66][4] = {{0}};
#endif
#if 0
const unsigned int output_WDMA_WRA_buffer_size[66][4] = { // [loop][ch] //BC
{10000, 0, 2704, 0},
{10000, 0, 2704, 0},
{10000, 0, 0, 0},
{10000, 10000, 2704, 2704},
{5408, 5408, 1568, 1568},
{5408, 0, 1568, 0},
{5408, 5408, 0, 0},
{5408, 0, 1568, 0},
{1568, 1568, 0, 0},
{1568, 0, 0, 0},
{1568, 0, 0, 0},
{1568, 0, 0, 0},
{1568, 0, 0, 0},
{1568, 0, 0, 0},
{1568, 0, 0, 0},
{1568, 1568, 0, 0},
{6272, 6272, 6272, 6272},
{3136, 3136, 0, 0},
{6272, 6272, 0, 0},
{49152, 0, 0, 0}, //pyramid 2 result
{40000, 0, 10000, 0},
{40000, 0, 10000, 0},
{40000, 0, 0, 0},
{40000, 40000, 10000, 10000},
{20000, 20000, 5408, 5408},
{20000, 0, 5408, 0},
{20000, 20000, 0, 0},
{20000, 0, 5408, 0},
{5408, 5408, 0, 0},
{5408, 0, 0, 0},
{5408, 0, 0, 0},
{5408, 0, 0, 0},
{5408, 0, 0, 0},
{5408, 0, 0, 0},
{5408, 0, 0, 0},
{5408, 5408, 0, 0},
{21632, 21632, 21632, 21632},
{10816, 10816, 0, 0},
{21632, 21632, 0, 0},
{49152, 0, 0, 0}, //pyramid 1 result
{160000,	0, 40000, 0},
{160000,	0, 40000, 0},
{160000,	0, 0,	0},
{160000, 160000, 40000, 40000},
{80000, 80000, 20000, 20000},
{80000, 0, 20000, 0},
{80000, 80000, 0, 0},
{80000, 0, 20000, 0},
{20000, 20000, 0, 0},
{20000, 0, 0, 0},
{20000, 0, 0, 0},
{20000, 0, 0, 0},
{20000, 0, 0, 0},
{20000, 0, 0, 0},
{20000, 0, 0, 0},
{20000, 20000, 0, 0},
{200000, 200000, 200000, 200000},
{200000, 200000, 200000, 200000},
{200000, 200000, 0, 0},
{100000, 100000, 0, 0},
{100000, 100000, 0, 0},
{100000, 0, 0, 0},
{200000, 200000, 0, 0},
{200000, 200000, 0, 0},
{200000, 0, 0, 0},
{49152, 0, 0, 0}}; //pyramid 0 result
#endif
#if 0
const unsigned int output_WDMA_WRA_buffer_size[66][4] = { // [loop][ch]
{7600, 0, 2080, 0},
{7600, 0, 2080, 0},
{7600, 0, 0, 0},
{7600, 7600, 2080, 2080},
{4160, 4160, 1120, 1120},
{4160, 0, 1120, 0},
{4160, 4160, 0, 0},
{4160, 0, 1120, 0},
{1120, 1120, 0, 0},
{1120, 0, 0, 0},
{1120, 0, 0, 0},
{1120, 0, 0, 0},
{1120, 0, 0, 0},
{1120, 0, 0, 0},
{1120, 0, 0, 0},
{1120, 1120, 0, 0},
{4480, 4480, 4480, 4480},
{2240, 2240, 0, 0},
{4480, 4480, 0, 0},
{49152, 0, 0, 0}, //pyramid 2 result
{30400, 0, 7600, 0},
{30400, 0, 7600, 0},
{30400, 0, 0, 0},
{30400, 30400, 7600, 7600},
{15200, 15200, 4160, 4160},
{15200, 0, 4160, 0},
{15200, 15200, 0, 0},
{15200, 0, 4160, 0},
{4160, 4160, 0, 0},
{4160, 0, 0, 0},
{4160, 0, 0, 0},
{4160, 0, 0, 0},
{4160, 0, 0, 0},
{4160, 0, 0, 0},
{4160, 0, 0, 0},
{4160, 4160, 0, 0},
{16640, 16640, 16640, 16640},
{8320, 8320, 0, 0},
{16640, 16640, 0, 0},
{49152, 0, 0, 0}, //pyramid 1 result
{120000,	0, 30400, 0},
{120000,	0, 30400, 0},
{120000,	0, 0,	0},
{120000, 120000, 30400, 30400},
{60800, 60800, 15200, 15200},
{60800, 0, 15200, 0},
{60800, 60800, 0, 0},
{60800, 0, 15200, 0},
{15200, 15200, 0, 0},
{15200, 0, 0, 0},
{15200, 0, 0, 0},
{15200, 0, 0, 0},
{15200, 0, 0, 0},
{15200, 0, 0, 0},
{15200, 0, 0, 0},
{15200, 15200, 0, 0},
{152000, 152000, 152000, 152000},
{152000, 152000, 152000, 152000},
{152000, 152000, 0, 0},
{76000, 76000, 0, 0},
{76000, 76000, 0, 0},
{76000, 0, 0, 0},
{152000, 152000, 0, 0},
{152000, 152000, 0, 0},
{152000, 0, 0, 0},
{49152, 0, 0, 0}}; //pyramid 0 result
#endif


#if 0
const unsigned int output_WDMA_WRA_buffer_size[66][4] = { // [loop][ch]
{18000, 0, 4784, 0},
{18000, 0, 4784, 0},
{18000, 0, 0, 0},
{18000, 18000, 4784, 4784},
{9568, 9568, 2688, 2688},
{9568, 0, 2688, 0},
{9568, 9568, 0, 0},
{9568, 0, 2688, 0},
{2688, 2688, 0, 0},
{2688, 0, 0, 0},
{2688, 0, 0, 0},
{2688, 0, 0, 0},
{2688, 0, 0, 0},
{2688, 0, 0, 0},
{2688, 0, 0, 0},
{2688, 2688, 0, 0},
{10752, 10752, 10752, 10752},
{5376, 5376, 0, 0},
{10752, 10752, 0, 0},
{49152, 0, 0, 0}, //pyramid 2 result
{71200, 0, 18000, 0},
{71200, 0, 18000, 0},
{71200, 0, 0, 0},
{71200, 71200, 18000, 18000},
{36000, 36000, 9568, 9568},
{36000, 0, 9568, 0},
{36000, 36000, 0, 0},
{36000, 0, 9568, 0},
{9568, 9568, 0, 0},
{9568, 0, 0, 0},
{9568, 0, 0, 0},
{9568, 0, 0, 0},
{9568, 0, 0, 0},
{9568, 0, 0, 0},
{9568, 0, 0, 0},
{9568, 9568, 0, 0},
{38272, 38272, 38272, 38272},
{19136, 19136, 0, 0},
{38272, 38272, 0, 0},
{49152, 0, 0, 0}, //pyramid 1 result
{284800,	0, 71200, 0},
{284800,	0, 71200, 0},
{284800,	0, 0,	0},
{284800, 284800, 71200, 71200},
{142400, 142400, 36000, 36000},
{142400, 0, 36000, 0},
{142400, 142400, 0, 0},
{142400, 0, 36000, 0},
{36000, 36000, 0, 0},
{36000, 0, 0, 0},
{36000, 0, 0, 0},
{36000, 0, 0, 0},
{36000, 0, 0, 0},
{36000, 0, 0, 0},
{36000, 0, 0, 0},
{36000, 36000, 0, 0},
{360000, 360000, 360000, 360000},
{360000, 360000, 360000, 360000},
{360000, 360000, 0, 0},
{180000, 180000, 0, 0},
{180000, 180000, 0, 0},
{180000, 0, 0, 0},
{360000, 360000, 0, 0},
{360000, 360000, 0, 0},
{360000, 0, 0, 0},
{49152, 0, 0, 0}}; //pyramid 0 result
#endif

unsigned int out_xsize_plus_1[66] = { // [loop] //AW
400,
400,
400,
400,
416,
416,
416,
416,
224,
224,
224,
224,
224,
224,
224,
224,
448,
224,
448,
0,
800,
800,
800,
800,
800,
800,
800,
800,
416,
416,
416,
416,
416,
416,
416,
416,
832,
416,
832,
0,
1600,
1600,
1600,
1600,
1600,
1600,
1600,
1600,
800,
800,
800,
800,
800,
800,
800,
800,
1600,
1600,
1600,
800,
800,
800,
1600,
1600,
1600,
0};

const unsigned int kernel_RDMA_RA_buffer_en[66][2] = { // [loop][ch]
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{0, 0},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{0, 0},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{1, 1},
{0, 0}};

const unsigned int kernel_RDMA_RA_buffer_size[66][2] = { // [loop][ch]
{240, 240},
{1168, 1168},
{272, 272},
{2320, 2320},
{2080, 2080},
{9232, 9232},
{3104, 3104},
{9232, 9232},
{4128, 4128},
{1040, 1040},
{4624, 4624},
{4624, 4624},
{1552, 1552},
{4624, 4624},
{4624, 4624},
{4128, 4128},
{3648, 3648},
{1040, 1040},
{2080, 2080},
{0, 0},
{240, 240},
{1168, 1168},
{272, 272},
{2320, 2320},
{2080, 2080},
{9232, 9232},
{3104, 3104},
{9232, 9232},
{4128, 4128},
{1040, 1040},
{4624, 4624},
{4624, 4624},
{1552, 1552},
{4624, 4624},
{4624, 4624},
{4128, 4128},
{3648, 3648},
{1040, 1040},
{2080, 2080},
{0, 0},
{240, 240},
{1168, 1168},
{272, 272},
{2320, 2320},
{2080, 2080},
{9232, 9232},
{3104, 3104},
{9232, 9232},
{4128, 4128},
{1040, 1040},
{4624, 4624},
{4624, 4624},
{1552, 1552},
{4624, 4624},
{4624, 4624},
{4128, 4128},
{3648, 3648},
{3648, 3648},
{2080, 2080}, // different with L 1824
{1040, 1040},
{1040, 1040},
{528, 528},
{2080, 2080},
{2080, 2080},
{1040, 1040},
{0, 0}};

const unsigned int Used_Output_Stride2_as_Input[66] = { // [loop] //R
0,
0,
0,
0,
1,
0,
0,
0,
1,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
1,
0,
0,
0,
1,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
1,
0,
0,
0,
1,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0};

const unsigned int fd_stride[66] = { // [loop] //H
2,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
2,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
2,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1,
1};

const unsigned int fd_maxpool[66] = { // [loop] //L
1,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
1,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
1,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0};

const unsigned int out_2size[66] = { // [loop] //O
1,
1,
0,
1,
1,
1,
0,
1,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
1,
1,
0,
1,
1,
1,
0,
1,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
1,
1,
0,
1,
1,
1,
0,
1,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0};

const unsigned int input_channel_pack[66] = { //W
1,
16,
16,
16,
16,
32,
32,
32,
32,
32,
32,
32,
32,
32,
32,
32,
32,
32,
32,
0,
1,
16,
16,
16,
16,
32,
32,
32,
32,
32,
32,
32,
32,
32,
32,
32,
32,
32,
32,
0,
1,
16,
16,
16,
16,
32,
32,
32,
32,
32,
32,
32,
32,
32,
32,
32,
32,
32,
32,
32,
32,
32,
32,
32,
32,
0};

const unsigned int outlayer[66] = { //M
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
1,
1,
1,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
1,
1,
1,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
1,
1,
1,
1,
1,
1,
1,
1,
1,
0};


const unsigned int output_channel_pack[66] = { //X
16,
16,
16,
16,
32,
32,
32,
32,
32,
32,
32,
32,
32,
32,
32,
32,
32,
16,
32,
0,
16,
16,
16,
16,
32,
32,
32,
32,
32,
32,
32,
32,
32,
32,
32,
32,
32,
16,
32,
0,
16,
16,
16,
16,
32,
32,
32,
32,
32,
32,
32,
32,
32,
32,
32,
32,
32,
32,
32,
16,
16,
16,
32,
32,
32,
0};


const unsigned int anchor_enable_number[66] = { //Z
2,
2,
2,
2,
2,
2,
2,
2,
2,
2,
2,
2,
2,
2,
2,
2,
2,
2,
2,
2,
2,
2,
2,
2,
2,
2,
2,
2,
2,
2,
2,
2,
2,
2,
2,
2,
2,
2,
2,
2,
5,
5,
5,
5,
5,
5,
5,
5,
5,
5,
5,
5,
5,
5,
5,
5,
5,
5,
5,
5,
5,
5,
5,
5,
5,
5};

const unsigned int wdma_num[66] = { //AF
2,
2,
1,
4,
4,
2,
2,
2,
2,
1,
1,
1,
1,
1,
1,
2,
4,
2,
2,
1,
2,
2,
1,
4,
4,
2,
2,
2,
2,
1,
1,
1,
1,
1,
1,
2,
4,
2,
2,
1,
2,
2,
1,
4,
4,
2,
2,
2,
2,
1,
1,
1,
1,
1,
1,
2,
4,
4,
2,
2,
2,
1,
2,
2,
1,
1};

unsigned int output_height[66] = {0}; //AY, Q

unsigned int out_ysize_plus_1_stride2[66] = {0}; //AZ

unsigned int out_stride[66] = {0}; //BA

unsigned int out_stride_stride2[66] = {0}; //BB

unsigned int output_width[66] = {0}; //P

unsigned int image_width[66] = {0}; //E

unsigned int image_height[66] = {0}; //F

unsigned int stride2_output_width[66] = {0}; //S

unsigned int stride2_output_height[66] = {0}; //T

unsigned int out_xsize_plus_1_stride2[66] = {0}; //AX

unsigned int input_xsize_plus_1[66] = {0}; //AN


#define Y2R_CONFIG_SIZE 28
#define RS_CONFIG_SIZE 28
#define FD_CONFIG_SIZE 48
#define RD_RLT_SIZE 12

#define Y2R_SRC_DST_FORMAT 0
#define Y2R_IN_W_H 1
#define Y2R_OUT_W_H 2
#define Y2R_RA0_RA1_EN 3
#define Y2R_IN_X_Y_SIZE0 4
#define Y2R_IN_STRIDE0_BUS_SIZE0 5
#define Y2R_IN_X_Y_SIZE1 6
#define Y2R_IN_STRIDE1_BUS_SIZE1 7
#define Y2R_OUT_X_Y_SIZE0 8
#define Y2R_OUT_STRIDE0_BUS_SIZE0 9
#define Y2R_OUT_X_Y_SIZE1 10
#define Y2R_OUT_STRIDE1_BUS_SIZE1 11
#define Y2R_OUT_X_Y_SIZE2 12
#define Y2R_OUT_STRIDE2_BUS_SIZE2 13
#define Y2R_IN_0 14
#define Y2R_IN_1 15
#define Y2R_OUT_0 16
#define Y2R_OUT_1 17
#define Y2R_OUT_2 18
#define Y2R_RS_SEL_SRZ_EN 19
#define Y2R_X_Y_MAG 20
#define Y2R_SRZ_HORI_STEP 22
#define Y2R_SRZ_VERT_STEP 23
#define Y2R_PADDING_EN_UP_DOWN 26
#define Y2R_PADDING_RIGHT_LEFT 27


#define RS_IN_0 22
#define RS_IN_1 23
#define RS_IN_2 24
#define RS_OUT_0 25
#define RS_OUT_1 26
#define RS_OUT_2 27
#define RS_X_Y_MAG 1
#define RS_SRZ_HORI_STEP 3
#define RS_SRZ_VERT_STEP 4
#define RS_INPUT_W_H 7
#define RS_OUTPUT_W_H 8
#define RS_IN_X_Y_SIZE0 10
#define RS_IN_STRIDE0 11
#define RS_IN_X_Y_SIZE1 12
#define RS_IN_STRIDE1 13
#define RS_IN_X_Y_SIZE2 14
#define RS_IN_STRIDE2 15
#define RS_OUT_X_Y_SIZE0 16
#define RS_OUT_STRIDE0 17
#define RS_OUT_X_Y_SIZE1 18
#define RS_OUT_STRIDE1 19
#define RS_OUT_X_Y_SIZE2 20
#define RS_OUT_STRIDE2 21


#define FD_INPUT_ROTATE 1
#define FD_CONV_WIDTH_MOD6 2
#define FD_CONV_IMG_W_H 4

#define FD_IN_IMG_W_H 5
#define FD_OUT_IMG_W_H 6

#define FD_IN_X_Y_SIZE0 9
#define FD_IN_X_Y_SIZE1 11
#define FD_IN_X_Y_SIZE2 13
#define FD_IN_X_Y_SIZE3 15

#define FD_IN_STRIDE0_BUS_SIZE0 10
#define FD_IN_STRIDE1_BUS_SIZE1 12
#define FD_IN_STRIDE2_BUS_SIZE2 14
#define FD_IN_STRIDE3_BUS_SIZE3 16

#define FD_OUT_X_Y_SIZE0 17
#define FD_OUT_X_Y_SIZE1 19
#define FD_OUT_X_Y_SIZE2 21
#define FD_OUT_X_Y_SIZE3 23

#define FD_OUT_STRIDE0_BUS_SIZE0 18
#define FD_OUT_STRIDE1_BUS_SIZE1 20
#define FD_OUT_STRIDE2_BUS_SIZE2 22
#define FD_OUT_STRIDE3_BUS_SIZE3 24

#define FD_IN_0 27
#define FD_IN_1 28
#define FD_IN_2 29
#define FD_IN_3 30

#define FD_OUT_0 31
#define FD_OUT_1 32
#define FD_OUT_2 33
#define FD_OUT_3 34

#define FD_KERNEL_0 35
#define FD_KERNEL_1 36

#define FD_RPN_SET 37
#define FD_IMAGE_COORD 38
