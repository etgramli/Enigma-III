//direction.h

enum class Direction {
    CLOCKWISE
    ANTICLOCKWISE
};

Direction& operator++(Direction& direction) {
    switch(direction) {
    case Direction::CLOCKWISE:
        return ANTICLOCKWISE;
        break;
    case Direction::ANTICLOCKWISE:
        return CLOCKWISE;
    default:
        return NULL;
    }
}

Direction& operator--(Direction& direction) {
    switch(direction) {
    case Direction::CLOCKWISE:
        return ANTICLOCKWISE;
        break;
    case Direction::ANTICLOCKWISE:
        return CLOCKWISE;
    default:
        return NULL;
    }
}
