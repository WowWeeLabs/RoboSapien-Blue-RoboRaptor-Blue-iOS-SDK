//
//  ConstantsDefinition.h
//  roboremoteblueSample
//
//  Created by Alex Lam on 1/2/2016.
//  Copyright © 2016 Wowwee. All rights reserved.
//

#ifndef ConstantsDefinition_h
#define ConstantsDefinition_h

enum RoboraptorCommands {
    RoboraptorCommandsGuardMode             = 176,      // 0xB0
    RoboraptorCommandsDemo                  = 208,      // 0xD0
    RoboraptorCommandsHuntingMode           = 180,      // 0xB4
    RoboraptorCommandsCautiousMode          = 178,      // 0xB2
    RoboraptorCommandsRoam                  = 177,      // 0xB1
    RoboraptorCommandsPlayfulMode           = 179,      // 0xB3
    
    RoboraptorCommandsHeadClockwise         = 148,      // 0x94
    RoboraptorCommandsHeadCounterClockwise  = 145,      // 0x91
    RoboraptorCommandsBite                  = 209,      // 0xD1
    
    RoboraptorCommandsTailLeft              = 146,      // 0x92
    RoboraptorCommandsTailRight             = 147,      // 0x93
    
    RoboraptorCommandsUp                    = 134,      // 0x86
    RoboraptorCommandsDown                  = 135,      // 0x87
    RoboraptorCommandsRight                 = 128,      // 0x80
    RoboraptorCommandsLeft                  = 136,      // 0x88
    RoboraptorCommandsStop                  = 142,      // 0x8e
};

enum RSCommands {
    RSCommandsLeftShoulderForward = 137,      // 0x89
    RSCommandsLeftShoulderBackward = 140,     // 0x8c
    RSCommandsRightShoulderForward = 129,     // 0x81
    RSCommandsRightShoulderBackward = 132,    // 0x84
    RSCommandsLeftHandForward = 138,          // 0x8a
    RSCommandsLeftHandBackward = 141,         // 0x8d
    RSCommandsRightHandForward = 130,         // 0x82
    RSCommandsRightHandBackward = 133,        // 0x85
    
    RSCommandsWaistLeft = 139,                // 0x8b
    RSCommandsWaistRight = 131,               // 0x83
    RSCommandsUp = 134,                       // 0x86
    RSCommandsDown = 135,                     // 0x87
    RSCommandsRight = 128,                    // 0x80
    RSCommandsLeft = 136,                     // 0x88
    RSCommandsStop = 142,                     // 0x8e
    RSCommandsLeanForward = 173,              // 0xad
    RSCommandsLeanBackward = 165,             // 0xa5
    RSCommandsDemo1 = 210,                    // 0xd2
    RSCommandsDemo2 = 211,                    // 0xd3
    RSCommandsSFXWhistle = 202,               // 0xca
    RSCommandsSFXBurp = 194,                  // 0xc2
    RSCommandsSFXRoar = 206,                  // 0xce
    RSCommandsSFXOops = 199,                  // 0xc7
    RSCommandsSleep = 163,                    // 0xa3
    RSCommandsListen = 171,                   // 0xab
    
    RSCommandsLeftArmPickUp = 172,            // 0xac
    RSCommandsLeftArmThump = 169,             // 0xa9
    RSCommandsLeftArmSweep = 201,             // 0xc9
    RSCommandsLeftArmThrow = 170,             // 0xaa
    
    RSCommandsRightArmPickUp = 164,           // 0xa4
    RSCommandsRightArmThump = 161,            // 0xa1
    RSCommandsRightArmSweep = 193,            // 0xc1
    RSCommandsRightArmThrow = 162,            // 0xa2
    
    RSCommandsLeftArmStrike1 = 205,           // 0xcd
    RSCommandsLeftArmStrike2 = 203,           // 0xcb
    RSCommandsTalkBack = 204,                 // 0xcc
    RSCommandsLeftArmStrike3 = 200,           // 0xc8
    
    RSCommandsRightArmStrike1 = 197,          // 0xc5
    RSCommandsRightArmStrike2 = 195,          // 0xc3
    RSCommandsRightArmHigh5 = 196,            // 0xc4
    RSCommandsRightArmStrike3 = 192,          // 0xc0
};

enum RoboSapienArmActionMode {
    RoboSapienArmActionModeNormal,
    RoboSapienArmActionModePick,
    RoboSapienArmActionModeStrike
};

#endif /* ConstantsDefinition_h */
