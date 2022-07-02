// Copyright 2022 
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "quantum.h"

#define XXX KC_NO

#define LAYOUT( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0E, \
    K10, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K2E, \
    K20, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D, \
    K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3D, K3E, K3F, K3G, \
    K40, K41, K43, K44, K46, K48, K4A, K4B, K4C, K4D, K4E, K4F, K4G  \
) { \
    { K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, XXX, K0E, XXX, XXX }, \
    { K10, XXX, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, XXX, XXX, XXX }, \
    { K20, XXX, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D, K2E, XXX, XXX }, \
    { K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, XXX, K3D, K3E, K3F, K3G }, \
    { K40, K41, XXX, K43, K44, XXX, K46, XXX, K48, XXX, K4A, K4B, K4C, K4D, K4E, K4F, K4G }, \
}

