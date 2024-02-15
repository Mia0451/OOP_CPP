//
// Created by shiwe on 11/28/2023.
//

#ifndef CS2B_ASSIGNMENT4_MEDIA_H
#define CS2B_ASSIGNMENT4_MEDIA_H


class Media {
private:
    double size; // Size in Mega bytes (MB)

public:
    static const double DEFAULT_SIZE;
    static const double CHARGE_PER_MB;
    static const double MIN_CHARGE;
    static const double SIZE_THRESHOLD;

    Media();

    Media(double s);

    ~Media();

    double get_size() const;

    void set_size(double s);

    double GetCharge() const;
};


#endif //CS2B_ASSIGNMENT4_MEDIA_H
