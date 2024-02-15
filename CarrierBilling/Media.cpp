//
// Created by shiwe on 11/28/2023.
//

#include "Media.h"

const double Media::DEFAULT_SIZE = 0.0;     // 0 MB
const double Media::CHARGE_PER_MB = 0.05; // 5 cents
const double Media::MIN_CHARGE = 1.00;      // 1 dollar
const double Media::SIZE_THRESHOLD = 100.00;    // 100 MB

Media::Media() : size(Media::DEFAULT_SIZE) {}

Media::Media(double s) : size(s) {}

Media::~Media() {} // no op

double Media::get_size() const {
    return size;
}

void Media::set_size(double s) {
    size = s;
}

double Media::GetCharge() const {
    double charge = CHARGE_PER_MB * size;
    return (charge > MIN_CHARGE) ? charge : MIN_CHARGE;
}
