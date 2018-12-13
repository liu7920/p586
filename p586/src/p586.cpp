#include <iostream>
using namespace std;

class vendingmachine{
	int Coffee;
	int Sugar;
	int CREAM;
	int Water;
	int Cup;
	string str;
public:
	vendingmachine(){
		Coffee=3;
		Sugar=3;
		CREAM=3;
		Water=3;
		Cup=3;
		str = " ";
	}

	int check(){
		if(this->Water<=0){
			cout << "재료가 부족 합니다." << endl;
			return 0;
		}
		return 1;
	}

	void coffee(){
		this->Coffee-=1;
		this->CREAM-=1;
		this->Cup-=1;
		this->Water-=1;
	}

	void sugarcoffee(){
		this->Coffee-=1;
		this->Sugar-=1;
		this->Cup-=1;
		this->Water-=1;
	}

	void blackcoffee(){
		this->Coffee-=1;
		this->Cup-=1;
		this->Water-=1;
	}

	void get(string str1){
		this->str=str1;
	}
	void Fill(){
		this->Coffee=3;
		this->Sugar=3;
		this->CREAM=3;
		this->Water=3;
		this->Cup=3;
	}

	void view(){
		cout << "Coffee ";
		for(int q=0; q<this->Coffee; q++){
			cout << "*";
		}
		cout << endl;

		cout << "Sugar 	";
		for(int q=0; q<this->Sugar; q++){
			cout << "*";
		}
		cout << endl;

		cout << "CREAM 	";
		for(int q=0; q<this->CREAM; q++){
			cout << "*";
		}
		cout << endl;

		cout << "Water 	";
		for(int q=0; q<this->Water; q++){
			cout << "*";
		}
		cout << endl;

		cout << "Cup 	";
		for(int q=0; q<this->Cup; q++){
			cout << "*";
		}
		cout << endl;
	}

	friend ostream& operator << (ostream& stram, vendingmachine a);
};

ostream& operator << (ostream& stream, vendingmachine a){
	stream << "맛있는 " << a.str <<" 나왔습니다~~" ;
	return stream;
}

int main() {

	vendingmachine v;
	int i;

	cout << "-----명품 커피 자판기켭니다.-----" << endl;
	v.view();
	while(1){
		cout << "보통 커피:0, 설탈 커피:1, 블랙 커피:2, 채우기:3, 종료:4>>";
		cin >> i;
		if(i==0){
			if(v.check()==0){
				cout << "재료를 채우세요!!" << endl;
			}
			else{
				v.get("보통 커피");
				cout << v << endl;
				v.coffee();
			}
		}
		else if(i==1){
			if(v.check()==0){
				cout << "재료를 채우세요!!" << endl;
			}
			else{
				v.get("설탕 커피");
				cout << v << endl;
				v.sugarcoffee();
			}
		}
		else if(i==2){
			if(v.check()==0){
				cout << "재료를 채우세요!!" << endl;
			}
			else{
				v.get("블랙 커피");
				cout << v << endl;
				v.blackcoffee();
			}
		}
		else if(i==3){
			cout << "모든 통을 채웁니다.~~" <<endl;
			v.Fill();
		}
		else if(i==4){
			break;
		}

		v.view();
	}

	return 0;
}
