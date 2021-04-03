#include "mps_deliver_message.h"

MPSDeliverSideMessage::MPSDeliverSideMessage() {
  this->side = 0;
}

MPSDeliverSideMessage::MPSDeliverSideMessage(int side) {
  this->side = side;
}

int MPSDeliverSideMessage::getSide() {
  return this->side;
}

void MPSDeliverSideMessage::setSide(int side) {
  this->side = side;
}
