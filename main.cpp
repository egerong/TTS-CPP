#include <stdio.h>
#include <iostream>
#include <vector>

#include "transformer.h"

int main(int argc, const char* argv[]) {
    std::string text = u8"Selle hääle tegi C++";

    TransformerConfig config = {
        .verbose = true,
        .espeakLang = "Estonian",
        .espeakDataPath = "/usr/share/espeak-ng-data-1.50/",
        .modelPath = "/home/egert/EKI/TransformerTTS/out/model",
        .vocoderPath = "/home/egert/EKI/TransformerTTS/out/hifigan",
        .withStress = false,
        .sampleRate = 22050,
        .nFFT = 1024,
        .nMel = 80,
        .hopLength = 256,
        .winLength = 1024,
        .fMin = 0,
        .fMax = 8000
    };
    Transformer transformer(config);
    transformer.Synthesize(text);

    Test();
    return 0;


    std::string model_path = "model";
    if (argc == 1) {
        model_path = argv[0];
    }
}
