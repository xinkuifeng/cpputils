#ifndef FXK_SEGMENT_H_
#define FXK_SEGMENT_H_

#include <functional>
#include <iostream>

namespace fxk {

struct Segment {
    int low;
    int high;

    Segment() : low(0), high(0) {}
    Segment(int lo, int hi) : low(lo), high(hi) {}

    bool valid() const { return low <= high; }

    void display(std::ostream & os) const {
        os << "(" << low << "," << high << ")";
    }

    bool operator==(const Segment & other) const {
        return low == other.low && high == other.high;
    }

    bool operator!=(const Segment & other) const {
        return low != other.low || high != other.high;
    }
};

std::ostream & operator<<(std::ostream & os, const Segment & s) {
    s.display(os);
    return os;
}

}

namespace std {
    template <> struct hash<fxk::Segment> {
        inline size_t operator()(const fxk::Segment & seg) const {
            std::hash<int> int_hasher;
            return int_hasher(seg.low) ^ int_hasher(seg.high);
        }
    };
}

#endif