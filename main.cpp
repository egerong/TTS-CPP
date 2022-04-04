#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <time.h>

#include "transformer.h"

int main(int argc, const char* argv[]) {
    char logLevel[] = "TF_CPP_MIN_LOG_LEVEL=3";
    char cudaDevices[] = "CUDA_VISIBLE_DEVICES=0";
    putenv(cudaDevices);
    putenv(logLevel);
    torch::set_num_threads(1);
    //std::string text = u8"Katsetame kõnesünteeesi kiirust.";

    TransformerConfig config = {
        .verbose = true,
        .cudaVisibleDevices = 0,
        .espeakLang = "Estonian",
        .espeakDataPath = "/usr/share/espeak-ng-data-1.50/",
        .modelPath = "/home/egert/EKI/TransformerTTS/out/model",
        .sampleRate = 22050,
        .nMel = 80,
        .tfLogLevel = 3,
        .vocoderPath = "/home/egert/EKI/TransformerTTS/out/hifigan",
    };
    auto startTime = clock();
    Transformer transformer(config);
    auto initTime = clock();
    printf(
        "\nInit time: %f\n",
        (double)(initTime - startTime) / CLOCKS_PER_SEC
    );
    int i;
    std::string text;
    for (i = 0; i < 100; i++) {
        std::ostringstream os;
        os << i << "Katsetame kõnesünteeesi kiirust " << i  <<".";
        text = os.str();
        std::cout << text << std::endl;
        transformer.Synthesize(text);
    }


    Test();
    return 0;


    std::string model_path = "model";
    if (argc == 1) {
        model_path = argv[0];
    }
}
