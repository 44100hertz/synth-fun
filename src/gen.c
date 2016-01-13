#include <stdio.h>
#include <math.h>
#include "struct.h"

static const uint16_t sineLUT[256] =
{
	0x0065, 0x012e, 0x01f7, 0x02c0, 0x0389, 0x0452, 0x051b, 0x05e3,
        0x06ac, 0x0775, 0x083e, 0x0906, 0x09cf, 0x0a97, 0x0b5f, 0x0c28,
        0x0cf0, 0x0db8, 0x0e80, 0x0f47, 0x100f, 0x10d6, 0x119d, 0x1264,
        0x132b, 0x13f2, 0x14b9, 0x157f, 0x1645, 0x170b, 0x17d0, 0x1896,
        0x195b, 0x1a20, 0x1ae5, 0x1ba9, 0x1c6d, 0x1d31, 0x1df5, 0x1eb8,
        0x1f7b, 0x203e, 0x2100, 0x21c2, 0x2284, 0x2346, 0x2407, 0x24c8,
        0x2588, 0x2648, 0x2708, 0x27c7, 0x2886, 0x2944, 0x2a02, 0x2ac0,
        0x2b7d, 0x2c3a, 0x2cf7, 0x2db3, 0x2e6e, 0x2f2a, 0x2fe4, 0x309e,
        0x3158, 0x3211, 0x32ca, 0x3383, 0x343a, 0x34f2, 0x35a8, 0x365f,
        0x3715, 0x37ca, 0x387e, 0x3933, 0x39e6, 0x3a99, 0x3b4c, 0x3bfe,
        0x3caf, 0x3d60, 0x3e10, 0x3ebf, 0x3f6e, 0x401d, 0x40ca, 0x4177,
        0x4224, 0x42d0, 0x437b, 0x4425, 0x44cf, 0x4578, 0x4621, 0x46c9,
        0x4770, 0x4816, 0x48bc, 0x4961, 0x4a06, 0x4aa9, 0x4b4c, 0x4bee,
        0x4c90, 0x4d31, 0x4dd1, 0x4e70, 0x4f0e, 0x4fac, 0x5049, 0x50e5,
        0x5181, 0x521b, 0x52b5, 0x534e, 0x53e7, 0x547e, 0x5515, 0x55aa,
        0x563f, 0x56d3, 0x5767, 0x57f9, 0x588b, 0x591c, 0x59ac, 0x5a3b,
        0x5ac9, 0x5b56, 0x5be2, 0x5c6e, 0x5cf9, 0x5d82, 0x5e0b, 0x5e93,
        0x5f1a, 0x5fa0, 0x6025, 0x60aa, 0x612d, 0x61af, 0x6231, 0x62b1,
        0x6331, 0x63af, 0x642d, 0x64aa, 0x6525, 0x65a0, 0x661a, 0x6693,
        0x670a, 0x6781, 0x67f7, 0x686c, 0x68e0, 0x6952, 0x69c4, 0x6a35,
        0x6aa4, 0x6b13, 0x6b81, 0x6bed, 0x6c59, 0x6cc3, 0x6d2d, 0x6d95,
        0x6dfd, 0x6e63, 0x6ec8, 0x6f2c, 0x6f90, 0x6ff2, 0x7053, 0x70b2,
        0x7111, 0x716f, 0x71cb, 0x7227, 0x7281, 0x72db, 0x7333, 0x738a,
        0x73e0, 0x7435, 0x7488, 0x74db, 0x752d, 0x757d, 0x75cc, 0x761a,
        0x7667, 0x76b3, 0x76fe, 0x7747, 0x778f, 0x77d7, 0x781d, 0x7862,
        0x78a5, 0x78e8, 0x7929, 0x796a, 0x79a9, 0x79e6, 0x7a23, 0x7a5f,
        0x7a99, 0x7ad2, 0x7b0a, 0x7b41, 0x7b77, 0x7bab, 0x7bde, 0x7c10,
        0x7c41, 0x7c71, 0x7c9f, 0x7ccd, 0x7cf9, 0x7d24, 0x7d4d, 0x7d76,
        0x7d9d, 0x7dc3, 0x7de8, 0x7e0b, 0x7e2e, 0x7e4f, 0x7e6f, 0x7e8d,
        0x7eab, 0x7ec7, 0x7ee2, 0x7efc, 0x7f15, 0x7f2c, 0x7f42, 0x7f57,
        0x7f6b, 0x7f7d, 0x7f8f, 0x7f9f, 0x7fad, 0x7fbb, 0x7fc7, 0x7fd2,
        0x7fdc, 0x7fe5, 0x7fec, 0x7ff3, 0x7ff7, 0x7ffb, 0x7ffe, 0x7fff
};

uint16_t gen_sine(uint16_t phase, uint8_t type)
{
        uint16_t intPosition = phase * 256 * 4;
        uint16_t posLUT = intPosition % 256;

        if(intPosition % 512 > 255)
                posLUT ^= 0x00ff;

        uint16_t topHalf = sineLUT[posLUT];

        if(intPosition > 512) {
                topHalf = 0x8000 - topHalf;
                return topHalf;
        } else {
                return topHalf + 0x7fff;
        }
}

uint16_t gen_preciseSine(uint16_t phase)
{
        return sin(phase * M_PI * 2.0) * 0xffff + 0x7fff;
}

// Square wave w/aliasing.
uint16_t gen_square(uint16_t phase)
{
	if(phase > 0x7fff)
		return 0;
        else
		return 0xffff;
}

uint16_t gen_triangle(uint16_t phase)
{
        if(phase > 0x7fff)
                return phase * 2;
        else
                return (0xffff - phase) * 2;
}

// Used for envelopes
uint16_t gen_1poly(uint16_t phase, double a, double power)
{
	return (uint16_t)pow((0xffff - phase) / (double)0xffff, power) * a * 0xffff;
}
