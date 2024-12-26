#ifndef RESERVATION_H
#define RESERVATION_H

#include <iostream>

class Reservation {
private:
  int reservationNumber;

public:
  Reservation();
  ~Reservation();

  int getReservationNumber();
  void setReservationNumber(int reservationNumber);

  friend std::ostream &operator<<(std::ostream &os, const Reservation &obj);
};

#endif
