# arduino_elevator

## 회로 구성
![image](https://user-images.githubusercontent.com/110883172/202864472-176fe54b-2402-4d93-ac8f-636acdd70823.png)


</br>

## 작동

![Circuit_design_Cool_Turing-Bigery___Tinkercad_외_페이지_1개_-_개인_3_-_Microsoft__Edge_2022-11-20_02-33-07_AdobeExpress](https://user-images.githubusercontent.com/110883172/202865041-65465d80-15b1-41d7-aed9-59c42bc0c6e8.gif)


</br>

![Circuit_design_Cool_Turing-Bigery___Tinkercad_외_페이지_1개_-_개인_3_-_Microsoft__Edge_2022-11-20_02-33-07_AdobeExpress (1)](https://user-images.githubusercontent.com/110883172/202865042-45d2c15b-2622-4834-87cd-f962e2df0554.gif)



- 왼쪽의 빨간 LED가 1층이다, 중간이 2층 오른쪽이 3층이다

- 각 층으로 이동하라는 스위치가 눌리면 그 층으로 이동한다.

- 단, 인터럽트를 사용하면 안된다.

- 버튼이 눌리고 움직이던중 다른 스위치가 동작하면 

- 일단 목적지에 도착한 후에 다른 스위치로 이동한다

- 1에서 3을 가던중 2층이 켜지면 2층을 도착할때 2층이 꺼진다.



#### 1. LED와 My_delay 함수를 이용하여 구현


#### 2.(도전중) My_delay함수를 사용하지 말고 아두이노의 주기성을 해치지 않게 구현


#### 3. 서보모터를 이용한 구현

#### 4. 층수를 
