#include "./ChannelPrimitive.h"

std::vector<float> ChannelPrimitive::fft;
std::vector<Beat> ChannelPrimitive::beats;

void ChannelPrimitive::setFFT(std::vector<float> & toset){
    fft = toset;
}
