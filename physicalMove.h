#ifndef DINO_MOVER
#define DINO_MOVER

class DinoMover {
    private:
        
    public:
        DinoMover();
        ~DinoMover();
        void moveDistance(int distance);
        void moveTime(int seconds);
        void turnDegrees(int degrees);
        void turnTime(int time, bool watchDirection);
}

#endif
