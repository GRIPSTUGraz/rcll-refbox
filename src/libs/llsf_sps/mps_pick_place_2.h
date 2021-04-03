/*!
* \file mps_pick_place_2.h
* \brief Definition of communication between Refbox and Pick&Place 2
* \author David Masternak
* \version 1.0
*/

#ifndef MPSPICKPLACE2_H
#define MPSPICKPLACE2_H

#include "mps.h"

#include <core/threading/thread.h>

using namespace fawkes;

/*!
* \class MPSPickPlace2
* \brief This class handels the communication to a Pick&Place 2
*/
class MPSPickPlace2 : public MPS, public Thread {
 private:
  int countSlide;
 public:
  /*!
   * \fn MPSPickPlace2(char* ip, int port)
   * \brief Initialize communication
   * \param ip address of mps
   * \param port port of modbus communication
   */
  MPSPickPlace2(const char* ip, int port);


  
  MPSPickPlace2(const char* ip, int port, const char* name);
  /*!
   * \fn ~MPSPickPlace2()
   * \brief Destructor
   */
  ~MPSPickPlace2();
  
  /*!
   * \fn produceRing(int workpiece)
   * \brief send command to produce workpiece
   * \param workpiece from which lane
   */
  void produceRing(int workpiece);

  void deliverProduct();
  
  /*!
   * \fn ringReady()
   * \brief receive ringReady command
   * \return true if workpiece is ready and false if not
   */
  bool ringReady();

  /*!
   * \fn isEmpty()
   * \brief receive isEmpty command
   * \return true if lane is empty and false if not
   */
  bool isEmpty();
  
  /*!
   * \fn setLight(int light, int state);
   * \param light what color
   * \param state on or off
   */
  void setLight(int light, int state, int blink);
  
  /*!
   * \fn processQueue()
   * \brief processing the queue
   */
  //void processQueue();

  /*!
   * \fn clearRegister();
   * \brief set all registeres to 0
   */
  void clearRegister();
  
  MachineState getState();

  void loop();

  int getCountSlide();

  void resetCounterSlide();
};

#endif // MPSPICKPLACE2_H
