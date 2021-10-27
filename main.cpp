#include <stdio.h>
#include <iostream>
#include <vector>

#include "transformer.h"

int main(int argc, const char* argv[]) {
    std::string text = u8"Karu oli hoolimatu, lampjalgne ja räpane.";

    TransformerConfig config = {
        .verbose = true,
        .espeakLang = "Estonian",
        .espeakDataPath = "/usr/share/espeak-ng-data-1.50/",
        .modelPath = "/home/egert/Prog/TTS-CPP/model",
        .withStress = false,
        .sampleRate = 16000,
        .nMel = 80,
        .nFFT = 1024,
        .fMin = 0,
        .fMax = 8000
    };

    Transformer transformer(config);

    transformer.Synthesize(text);

    return 0;

    std::string model_path = "model";
    if (argc == 1) {
        model_path = argv[0];
    }
}
