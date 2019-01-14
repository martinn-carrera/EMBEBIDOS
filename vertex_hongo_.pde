int i=0;
int x=0;
int y=0;

void setup() {
  size(640, 640);
}


void draw() {
  //background(255);
  fill(0);
  textSize(50);
  text(x, 500, 500);
  text(y, 500, 600);
  delay(100);
  figura();
  paredes();
}

void figura() {
  beginShape();
  fill(247, 98, 67);
  vertex(10+x, 20+y);
  vertex(15+x, 20+y);
  vertex(15+x, 15+y);
  vertex(20+x, 15+y);
  vertex(20+x, 10+y);
  vertex(45+x, 10+y);
  vertex(45+x, 15+y);
  vertex(50+x, 15+y);
  vertex(50+x, 20+y);
  vertex(55+x, 20+y);
  vertex(55+x, 30+y);
  vertex(45+x, 30+y);
  vertex(45+x, 25+y);
  vertex(20+x, 25+y);
  vertex(20+x, 30+y);
  vertex(10+x, 30+y);
  vertex(10+x, 20+y);
  endShape();

  beginShape();
  fill(255, 235, 205);
  vertex(15+x, 30+y);
  vertex(15+x, 40+y);
  vertex(20+x, 40+y);
  vertex(20+x, 45+y);
  vertex(45+x, 45+y);
  vertex(45+x, 40+y);
  vertex(50+x, 40+y);
  vertex(50+x, 30+y);
  vertex(45+x, 30+y);
  vertex(45+x, 25+y);
  vertex(20+x, 25+y);
  vertex(20+x, 25+y);
  vertex(20+x, 30+y);
  vertex(15+x, 30+y);
  endShape();
  fill(0);
  rect(25+x, 25+y, 5, 7.5);
  rect(35+x, 25+y, 5, 7.5);
}

void paredes() {
  fill(0);
  rect(100, 0, 10, 100);
  rect(0, 200, 150, 10);
  rect(300, 0, 10, 300);
  rect(0, 400, 400, 10);
  rect(500, 0, 10, 500);
}

void keyPressed() {
  background(255);
  // fill(0);
  //println(keyCode); //key...convierte de hex a letra   keyCode..valor hex
  //textSize(50);
  //fill(0);
  //text(keyCode, 100, 200);
  switch(keyCode) {
  case 38: //arriba
    if (y>-5)
      if (x<46 || x>99 || y>=95 )
        if (y<156 || x>139 || y>201)
          if (x<246 || y>289 || x>299)
            if (y<356 || y>401 || x>389)
              if (x<446 || y>501 || x>499)

                y=y-5;
    break;

  case 40: //abajo
    if (y<590)
      if (y<154 || x>139 || y>199)
        if (x<246 || y>289 || x>299)
          if (y<354 || y>399 || x>389)
            if (x<446 || y>501 || x>499)
              y=y+5;
    break;

  case 39: //derecha
    if (x<590)
      if (x<45 || y>89 || x>99)
        if (x<245 || y>289 || x>299)
          if (y<356 || y>399 || x>389)
            if (x<444 || y>489 || x>499)
              x=x+5;
    break;

  case 37: //izq
    if (x>-5)
      if (x>100 || y>85 || x<=45)
        if (x>144 || y<156 || y>199)
          if (x<246 || y>289 || x>301)
            if (y<356 || y>399 || x>391)
              if (x<446 || y>501 || x>501)
                x=x-5;
    break;
  }
}
