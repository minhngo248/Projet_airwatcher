#if ! defined (ZONE_H)
#define ZONE_H

class Zone {
public:
    double latitude;
    double longitude;
    double rayon;

    Zone();
    Zone(double unLat, double unLong, double unRayon);
    ~Zone();
};

#endif
