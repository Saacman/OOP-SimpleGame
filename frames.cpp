#include "frames.hpp"

Frames::Frames() : frames(0), currentIndex(0), elapsedTime(0.f) { }

// Añadimos un frame a nuestro vector
void Frames::addFrame(int textureID, int x, int y, int width, int height, float duration) {
    FrameData data;
    data.id = textureID;
    data.x = x;
    data.y = y;
    data.width = width;
    data.height = height;
    data.duration = duration;

    frames.push_back(data);
}

// Referencia al frame actual
const FrameData* Frames::getCurrent() const {
    if (frames.size()>0) return &frames[currentIndex];
    return nullptr;
}

// Update se encarga de revisar si es tiempo de pasar al siguiente frame
bool Frames::UpdateFrame(float dTime) {
    if (frames.size() > 0) {
        elapsedTime += dTime;

        if (elapsedTime >= frames[currentIndex].duration) {
            //elapsedTime -= frames[currentIndex].duration;
            elapsedTime = 0.f;
            incrementFrame();
            return true;
        }
    }
    return false;
}

// Reiniciar la animación al estado inicial
void Frames::reset() {
    currentIndex = 0;
    elapsedTime = 0.0;
}

void Frames::incrementFrame() {
    //currentIndex = (currentIndex + 1) % frames.size();
    if (currentIndex == (frames.size() - 1)) currentIndex = 0;
    else currentIndex++;
}
