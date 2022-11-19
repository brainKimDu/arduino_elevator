int floor_location = 13; 
	// 13 = 1 floor 
int go_down = 3; 
	//1 : up , 2 : down, 3 : equal

int destination; 
	// 목적지를 나타내는 변수
int floor_tmp; 
	// 층수를 나타내는 변수

int i_want=1; 
	// 나 몇층에 가고 싶어요를 나타내는 변수

int push_floor = 4;
	// 1 : 1번 버튼이 눌림 , 2 : 2번 버튼이 눌림 , 3 : 3번 버튼이 눌림


// 버튼 변수
int push_button_1st = 3; 
int push_button_2st = 2;
int push_button_3st = A0;




/*
함수명 : my_delay
목적 : 인터럽트 없이 구현하려면 딜레이를 나누어야 하기 때문
용도 : 딜레이를 분할하고 계속해서 checking 함수를 실행함
*/
void my_delay(int delay_num){
  for(int i=0; i<delay_num; i += 10){
    delay(10);
    checking();
  }
}




/*
함수명 : checking
목적 : 스위치가 눌렸는지 판단
용도 : 스위치가 눌렸는지 지속적으로 확인하는 함수
*/
void checking(){
  if (digitalRead(push_button_1st) == HIGH){
    if (push_floor == 1){
      return;
    }
    else{
      push_floor = 1;
      digitalWrite(6, HIGH);
    }
  }

  if (digitalRead(push_button_2st) == HIGH){
    if (push_floor == 2){
      return;
    }
    else{
      push_floor = 2;
      digitalWrite(5, HIGH);
    }
  }

  if (digitalRead(push_button_3st) == HIGH){
    if (push_floor == 3){
      return;
    }
    else{
      push_floor = 3;
      digitalWrite(4, HIGH);
    }
  }
}




/*
함수명 : set_first_floor
목적 :1층으로 보내는 함수
*/
void set_first_floor(){
  floor_location = 13;
  digitalWrite(floor_location, HIGH);
}



/*
함수명 upstairs
목적 : 1층 위로 올리는 함수
*/
void upstairs(int floor_up){
  if(floor_location == 13 || floor_location == 10 ){
    for(int i=0; i<(3 * floor_up); i++){
      digitalWrite(floor_location, LOW);
      floor_location--;
      if(floor_location == 10){
        digitalWrite(5, LOW);
      }
      digitalWrite(floor_location, HIGH);
      my_delay(100);
    }  
  }
}



/*
함수명 downstairs
목적 : 1층 아래로 내리는 함수
*/
void downstairs(int floor_up){
  if(floor_location == 7 || floor_location == 10 ){
    for(int i=0; i<(3 * floor_up); i++){
      digitalWrite(floor_location, LOW);
      floor_location++;
      if(floor_location == 10){
        digitalWrite(5, LOW);
      }
      digitalWrite(floor_location, HIGH);
      my_delay(100);
    }  
  }
}


/*
함수명 : i_want_go
목적 :   
	1. 핀번호 변환 
	2. 위로 올라가야할지, 내려가야할지 판단
    3. 몇층을 이동해야할지 판단.
*/
void i_want_go(int floor){
  if(floor == 1){
    floor_tmp = 13;
    destination = 6;
  }
  if(floor == 2){
    floor_tmp = 10;
    destination = 5;
  }
  if(floor == 3){
    destination = 4;
    floor_tmp = 7;
  } 

  
  

  if(floor_tmp > floor_location){    
    go_down = 2;
    i_want = (abs(floor_location - floor_tmp))/3;
  }
  
  if(floor_tmp < floor_location){
    go_down = 1;  
    i_want = (abs(floor_location - floor_tmp))/3;
  }

  if(floor_tmp == floor_location){
    go_down = 3;
  }
}


/*
함수명 : setup()
목적 : 초기설정 및 핀번호 부여
*/
void setup(){
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

  pinMode(push_button_1st, INPUT);
  pinMode(push_button_2st, INPUT);
  pinMode(push_button_3st, INPUT);

  set_first_floor();
  Serial.println("--start---");
}



/*
함수명 : loop
목적 : 실질적으로 작동이 진행되는 코드 main문
*/
void loop() {

  my_delay(100);
  
  if(push_floor <= 3)
    i_want_go(push_floor);
  switch(go_down){ 
    case 1:
      upstairs(i_want);
      digitalWrite(destination, LOW);

      break;
    case 2:
      downstairs(i_want);
      digitalWrite(destination, LOW);
      break;

    default:
      break;
  }

  my_delay(100);

}