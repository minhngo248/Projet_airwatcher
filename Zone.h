#if ! defined (ZONE_H)
#define ZONE_H

class Zone {
private:
    double latitude;
    double longitude;
    double rayon;
public:
    Zone();
    Zone(double unLat, double unLong, double unRayon);
    ~Zone();
}

#endif