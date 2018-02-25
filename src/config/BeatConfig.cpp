#include "config/BeatConfig.h"

BeatConfig beatConfig;

#include "model/Input.h"
using psiInput::bufferSize;

beatConfig.kickDefaultPos = (int) bufferSize * 0.05;
beatConfig.kickDefaultRadius = (int) bufferSize * 0.01;

beatConfig.snareDefaultPos = (int) bufferSize * 0.10;
beatConfig.snareDefaultRadius = (int) bufferSize * 0.03;

beatConfig.hatDefaultPos = (int) bufferSize * 0.02;
beatConfig.hatDefaultRadius = (int) bufferSize * 0.1;