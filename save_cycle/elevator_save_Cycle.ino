
int floor_location = 13; // 13 = 1 floor
int up_down = 3; //1 : up , 2 : down, 3 : equal

int destination;
int floor_tmp;

int i_want=0;


int push_button_1st = 3; 
int push_button_2st = 2;
int push_button_3st = A0;

int count = 0;



int push_floor = 4;

int push_floor_list[3] = {4, 4, 4};
int order_sunseo = 0;

int instruct_sunseo = 0;





void my_delay(int delay_num){
  for(int i=0; i<delay_num; i += 10){
    delay(10);
    checking();
  }
}


void checking(){
  if (digitalRead(push_button_1st) == HIGH){
    if (push_floor == 1){
      return;
    }
    
    else if (order_sunseo < 3){
      push_floor = 1;
      push_floor_list[order_sunseo] = push_floor;
      order_sunseo += 1;
      if (order_sunseo == 3)
      	order_sunseo = 0;
      digitalWrite(6, HIGH);
    }
  }

  if (digitalRead(push_button_2st) == HIGH){
    if (push_floor == 2){
      return;
    }
    else if (order_sunseo < 3){
      push_floor = 2;
      push_floor_list[order_sunseo] = push_floor;
      order_sunseo += 1;
      if (order_sunseo == 3)
      	order_sunseo = 0;
      digitalWrite(5, HIGH);
    }
  }

  if (digitalRead(push_button_3st) == HIGH){
    if (push_floor == 3){
      return;
    }
    else if (order_sunseo < 3){
      push_floor = 3;
      push_floor_list[order_sunseo] = push_floor;
      order_sunseo += 1;
      if (order_sunseo == 3)
      	order_sunseo = 0;
      digitalWrite(4, HIGH);
    }
  }
}


void set_first_floor(){
  floor_location = 13;
  digitalWrite(floor_location, HIGH);
}


void upstairs(int floor_up){
  digitalWrite(floor_location, LOW);
  floor_location--;
     
  if(floor_location == 10){
    digitalWrite(5, LOW);
    if(push_floor_list[order_sunseo-1] == 2){
        push_floor_list[order_sunseo-1] = 4;
        order_sunseo -= 1;
    }
  }
  digitalWrite(floor_location, HIGH);   
}

void downstairs(int floor_up){
      digitalWrite(floor_location, LOW);
      floor_location++;
  
      if(floor_location == 10){
        digitalWrite(5, LOW);
        if(push_floor_list[order_sunseo-1] == 2){
          push_floor_list[order_sunseo-1] = 4;
          order_sunseo -= 1;
        }
      }
  
      digitalWrite(floor_location, HIGH);
}

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
    up_down = 2;
    i_want = abs(floor_location - floor_tmp);
  }
  
  if(floor_tmp < floor_location){
    up_down = 1;  
    i_want = abs(floor_location - floor_tmp);
  }

  if(floor_tmp == floor_location){
    up_down = 3;
  }
}



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




void loop() {

  
  delay(10);
  checking();
  count += 1;
  
  
  if (count == 50){ 
    count = 0;
    
    if(push_floor_list[instruct_sunseo] <= 3 || i_want != 0 ){
    	i_want_go(push_floor_list[instruct_sunseo]);
    
 		switch(up_down){ 
    		case 1:
      			if(i_want != 0){
            		upstairs(i_want);
              		delay(10);
                  	if(floor_location == 13 || floor_location == 7)
      					digitalWrite(destination, LOW);
              		i_want -= 1 ;
            	}			
            	break;
          
    		case 2:
				if(i_want != 0){
            		downstairs(i_want);
              		delay(10);
                  	if(floor_location == 13 || floor_location == 7)
      					digitalWrite(destination, LOW);
              		i_want -= 1 ;
            	}
      			break;
          
    		default:
      			break;
  		}
      
      if (i_want == 0){
         push_floor_list[instruct_sunseo] = 4;
         instruct_sunseo++;
      }
    }
  }
  
  if (instruct_sunseo == 3)
    instruct_sunseo = 0;
}