PrintWriter output;

import processing.serial.*;

Serial ARD;

float angle;
float distance;



void setup() {
  size(800,400);
  
  output = createWriter("history.txt");
  
  ARD = new Serial(this,"COM12",9600);
  ARD.bufferUntil('\n'); 
}

void draw() {
  
  background(0);
  
  fill(0,255,0);
  
  stroke(0,255,0);
  noFill();
  
  translate(400,400);
  
  arc(0,0,100,100,PI,TWO_PI);
  arc(0,0,300,300,PI,TWO_PI);
  arc(0,0,600,600,PI,TWO_PI);
  
  for (int i = -90; i <= 90; i = i + 30) {
    float x = 300 * sin(radians(i));
    float y = -300 * cos(radians(i));
    stroke(0,255,0);
    line(0,0,x,y);
  }
  LineSweeper();
}

void serialEvent(Serial ARD) {
  String data = ARD.readStringUntil('\n');
  
  if (data != null) {
    data = trim(data);
    String values [] = split(data,',');
    
    if (values.length == 2) {
      angle = float(values[0]);
      distance = float(values[1]);
    }
  }
}

void LineSweeper() {
  float correctedAngle = angle - 90;
  float screenDist = map(distance,0,30,0,300);
  screenDist = constrain(screenDist,0,300);
  float radarX = screenDist * sin(radians(correctedAngle));
  float radarY = -screenDist * cos(radians(correctedAngle));
  
  
  if (screenDist < 300) {
    stroke(0,255,0);
    fill(0,255,0);
    text("object detected in the vicinity",-350,-330);
    text("distance: " + distance + "cm", -350,-350);
    text("angle: " + angle + "'",-350,-310);
    ellipse(radarX,radarY,20,20);
    if (distance != 0 && angle!=0) {
      output.println("distance: " + distance + "cm");
      output.println("angle: " + angle + "'");
      output.flush();
    }
  }
  else {
    fill(0,255,0);
    text("no object in the vicinity",-350,-330);
    text("distance: 30 cm (no object)",-350,-350);
    text("angle: " + angle + "'",-350,-310);
  }
}
  
  
  
  
