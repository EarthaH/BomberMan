#pragma once

/**
 * @typedef	struct KeyInput
 *
 * @brief	Structure holding the state of keys on the keyboard that are related to the game.
 */

typedef struct KeyInput
{
  bool up, down, left, right, enter, camUp, camDown, camLeft, camRight, space, esc,
  camRotXUp, camRotXDown, camRotYUp, camRotYDown, camRotZUp, camRotZDown,
  camPosXUp, camPosXDown, camPosYUp, camPosYDown, camPosZUp, camPosZDown;
  KeyInput()
  {
    up = false;
    down = false;
    left = false;
    right = false;
    camUp = false;
    camDown = false;
    camLeft = false;
    camRight = false;
    camRotXUp = false;
    camRotXDown = false;
    camRotYUp = false;
    camRotYDown = false;
    camRotZUp = false;
    camRotZDown = false;
    camPosXUp = false;
    camPosXDown = false;
    camPosYUp = false;
    camPosYDown = false;
    camPosZUp = false;
    camPosZDown = false;
    enter = false;
    space = false;
    esc = false;
  }
} KeyInput;