#########################################################################
# Date: 2018/10/02
# file name: 2nd_assignment_main.py
# Purpose: this code has been generated for the 4 wheel drive body
# moving object to perform the project with line detector
# this code is used for the student only
#########################################################################

#from car import Car
import RPi.GPIO as GPIO
from SEN040134 import SEN040134_Tracking as Tracking_Sensor
from PCA9685 import PCA9685 as PWM_Controller
import rear_wheels
import front_wheels
import time

GPIO.setwarnings(False)


class myCar(object):

    def __init__(self, car_name):
        #self.car = Car(car_name)
        self.line_detector = Tracking_Sensor.SEN040134_Tracking([16, 18, 22, 40, 32])
        self.carEngine = PWM_Controller.PWM()
        self.carEngine.startup()
        self.steering = front_wheels.Front_Wheels(db='config')
        self.steering.ready()
        self.accelerator = rear_wheels.Rear_Wheels(db='config')
        self.accelerator.ready()
        self.steering.turning_max = 35
        self.steering.center_alignment()
   
    def drive_parking(self):
        #self.car.drive_parking()
        self.steering.center_alignment()
        self.accelerator.stop()
        self.accelerator.power_down()
        GPIO.cleanup()


    # =======================================================================
    # 2ND_ASSIGNMENT_CODE
    # Complete the code to perform Second Assignment
    # =======================================================================
    def car_startup(self):
        # self.car.line_detector...
        # self.car.steering...
        # self.car.accelerator...

        move = ( ([1,0,0,0,0],35), ([1,1,0,0,0],30), ([0,1,0,0,0],10), ([0,1,1,0,0],5),
                ([0,0,1,1,0],-5), ([0,0,0,1,0],-10), ([0,0,0,1,1],-30), ([0,0,0,0,1],-35) 
                ([0,0,0,0,0],0) )
        before = [0,0,0,0,0]

        self.car.accelerator.go_forward(15)
        while True:
            #self.car.accelerator.go_forward(15)
            
            line = self.car.line_detector.read_digital()
            for angle in move:
                if line == angle[0]:
                    self.car.steering.turn(90+angle[1])
                    before = line
                    break
                    '''
                    if angle[1] < 0:
                        self.car.steering.turn_left(90+angle[1])
                        before = line
                        break
                        
                    elif angle[1] > 0:
                        self.car.steering.trun_right(90+angle[1])
                        before = line
                        break
                   ''' 
            if line == [0,0,0,0,0]:
                if before == move[0][0]:
                    self.car.steering.turn_right(125)

                elif before == move[7][0]:
                    self.car.steering.turn_left(55)                    
                
                else:
                    self.car.accelerator.stop() 

            if line == [1,1,1,1,1]:
                self.car.accelerator.stop()
                break

            time.sleep(0.1)
            
        pass


if __name__ == "__main__":
    try:
        myCar = myCar("CarName")
        myCar.car_startup()

    except KeyboardInterrupt:
        # when the Ctrl+C key has been pressed,
        # the moving object will be stopped
        myCar.drive_parking()
