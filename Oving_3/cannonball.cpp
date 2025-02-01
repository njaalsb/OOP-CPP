#include "cannonball.h"
#include "cannonball_viz.h"
#include "utilities.h"

// BEGIN: 2a
double acclY(){
    return -gravity;
}
// END: 2a

// BEGIN: 2b
double velY(double initVelocityY, double time){
    return initVelocityY + acclY()*time;
}
// END: 2b

// BEGIN: 2c
double posX(double initPositionX, double initVelocityX, double time){
    return initPositionX + initVelocityX*time;
} 
double posY(double initPositionY, double initVelocityY, double time){
    double tempy = (acclY()*pow(time,2))/2;
    return initPositionY + initVelocityY*time + tempy;
}
// END: 2c

// BEGIN: 2d
void printTime(double time){
    int hours = time/3600;
    int minutes = (time-(hours*3600))/60;
    double seconds = (time-(hours*3600 + minutes*60));
    cout << "Tid brukt: " << hours << "t, " << minutes << "m og " << fixed << setprecision(2) << seconds << "s." << endl;
}
// END: 2d

// BEGIN: 2e
double flightTime(double initVelocityY){
    double temp = (-2*initVelocityY);
    return temp/acclY();
}
// END: 2e

// BEGIN: 3b
bool testDeviation(double compareOperand, double toOperand, double maxError, string name){
    if(abs(compareOperand - toOperand) <= maxError){
        cout << name << " is valid.\n"; 
        return true;
    }
    else{
        cout << name << " is not valid, expected " << toOperand << " got " << compareOperand << ".\n";
        return false;
    }
}
// END: 3b

// BEGIN: 4a
double getUserInputTheta(){
    cout << "Skriv en vinkel i grader: ";
    double theta;
    cin >> theta;
    return theta;
}

double getUserInputInitVelocity(){
    cout << "Skriv en startfart: ";
    double initV;
    cin >> initV;
    return initV;
}

double degToRad(double deg){
    return (pi/180)*deg;
}

double getVelocityX(double theta, double initVelocity){
    return (cos(degToRad(theta))*initVelocity);
}

double getVelocityY(double theta, double initVelocity){
    double mid = sin(degToRad(theta));
    return initVelocity*mid;
}

vector<double> getVelocityVector(double theta, double initVelocity){
    vector<double> data{getVelocityX(theta, initVelocity), getVelocityY(theta, initVelocity)};
    cout << "{" <<  data.at(0) << ", " << data.at(1) << "}\n";

    return data;
}
// END: 4a

// BEGIN: 4b
double getDistanceTraveled(double velocityX, double velocityY){
    return posX(0, velocityX, flightTime(velocityY));
    }
// END: 4b

// BEGIN: 4c
double targetPractice(double distanceToTarget, double velocityX, double velocityY){
    return (distanceToTarget - getDistanceTraveled(velocityX, velocityY));
}
// END: 4c


// BEGIN: 5b
void playTargetPractice(){
    double theta;
    double initVelocity;
    int distanceToTarget = randomWithLimits(100,1000);

    cout << "Malet er plassert" << distanceToTarget << "meter unna deg.\r\n";

    for(int i = 0; i < 9; i++){
        theta = getUserInputTheta();
        initVelocity = getUserInputInitVelocity();
        double landingToTarget = targetPractice(distanceToTarget, getVelocityX(theta, initVelocity), getVelocityY(theta, initVelocity));
        printTime(flightTime(getVelocityY(theta, initVelocity)));
        if(abs(landingToTarget) < 5){
            cout << "Winner Winner chicken dinner!" << endl;
            i = 10;
        }
        else{
            if(i == 8){
                cout << "Lmao, u suck!\n";
            }
            else if (i != 8){
                cout << "Yoooo you missed by so much " << landingToTarget << "just give up!\n";
            }
        }
        cannonBallViz(distanceToTarget, 1000, getVelocityX(theta, initVelocity), getVelocityY(theta, initVelocity), 100);
    }



}   
// END: 5b
