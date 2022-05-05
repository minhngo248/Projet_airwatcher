#if ! defined (ZONE_H)
#define ZONE_H

class Zone {
public:

    double GetLatitude();
    double GetLongitude();
    double GetRayon();

    Zone();
    Zone(double unLat, double unLong, double unRayon);
    ~Zone();

private:

    double latitude;
    double longitude;
    double rayon;
};

#endif
