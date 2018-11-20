#########################################################################
# Date: 2018/10/02
# file name: 3rd_assignment_main.py
# Purpose: this code has been generated for the 4 wheel drive body
# moving object to perform the project with line detector
# this code is used for the student only
#########################################################################

from car import Car
import time


class myCar(object):

    def __init__(self, car_name):
        self.car = Car(car_name)

    def drive_parking(self):
        self.car.drive_parking()

    # =======================================================================
    # 3RD_ASSIGNMENT_CODE
    # Complete the code to perform Third Assignment
    # =======================================================================
    def car_startup(self):
        move = [ [1,0,0,0,0], [1,1,0,0,0], [0,1,0,0,0], [0,1,1,0,0], 
                 [0,0,1,0,0], [0,0,1,1,0], [0,0,0,1,0], [0,0,0,1,1], [0,0,0,0,1]]
        turning = [-35, -25, -20, -10, 0, 10, 20, 25, 35]
        before_line = [0,0,0,0,0]
        angle = 90
        block = 0
        reverse = 0
        dodge = 0
        lab = 0

        while True:
            if reverse == 1:
                reverse = 0
                self.car.accelerator.stop()
                self.car.accelerator.go_forward(15)
            line = self.car.line_detecor.read_digital()
            distance = self.car.distance_detector.get_distance()
            if dodge == 0:
                block = 1 if distance < 15 else 0
            
            if block == 0:
                for i in len(move):
                    if line == move[i]:
                        self.car.steering.turn(90+turning[i])
                        before_line = line
                        if dodge == 1:
                            dodge = 2
                        elif dodge == 3:
                            dodge = 0
                        break
            elif block == 1:
                angle = 90 + turning[2]
                dodge = 1
                block = 0
                time.sleep(0.5)
                

                            
            if line == [0,0,0,0,0]:
                if block == 0 and dodge == 0:
                    if before_line == move[0] or before_line == move[1]:
                        angle = 90 + turning[8]
                    elif before_line == move[8] or before_line == move[7]:
                        angle = 90 + turning[0]
                    else:
                        pass

                    self.car.accelerator.stop()
                    self.car.steering.turn(angle)
                    self.car.accelerator.go_backward(15)
                
                elif dodge == 1:
                    pass
                elif dodge == 2:    
                    dodge = 3
                    angle = 90 + turning[6]
                    self.car.steering.turn(angle)
                    time.sleep(1)
                    self.car.steering.turn(90)
                elif dodge == 3:
                    pass
            
            if line == [1,1,1,1,1]:
                lab += 1
                if lab == 2:
                    self.car.accelerator.stop()
                else:
                    while True:
                        line = self.car.line_detector.read_digital()
                        if line != [1,1,1,1,1]:
                            break


if __name__ == "__main__":
    try:
        myCar = myCar("CarName")
        myCar.car_startup()

    except KeyboardInterrupt:
        # when the Ctrl+C key has been pressed,
# the moving object will be stepped
        myCar.drive_parking()
