#pragma once
#include<iostream>
#include<string>
using namespace std;

class board {
private:
	sf::Sprite ghLine, gvLine, rhLine, rvLine, swOn, swOff,
		pduOff, pduOn, upsOff, upsOn,
		bLeiQi, temp_Sprite, AC;
	sf::Texture gh, gv, rh, rv, swOn_texture, swOff_texture, pduOff_texture,
		pduOn_texture, upsOn_texture, upsOff_texture,
		bleiqi, temp_texture, ac;
	map<string, sf::Sprite> layout;
	map<int, bool> switch_Status;
public:
	board() {
		//length 80, width 20
		gh.loadFromFile("pics/horizontal_line.png", sf::IntRect(0, 0, 80/2, 20 / 2));
		ghLine.setTexture(gh);
		gv.loadFromFile("pics/vertical_line.png", sf::IntRect(0, 0, 20 / 2, 80 / 2));
		gvLine.setTexture(gv);
		rh.loadFromFile("pics/horizontal_line.png", sf::IntRect(800 / 2, 0, 80 / 2, 20 / 2));
		rhLine.setTexture(rh);
		rv.loadFromFile("pics/vertical_line.png", sf::IntRect(0, 450 / 2, 20 / 2, 80 / 2));
		rvLine.setTexture(rv);
		swOff_texture.loadFromFile("pics/switchOff.png");
		swOff.setTexture(swOff_texture);
		swOn_texture.loadFromFile("pics/switchOn.png");
		swOn.setTexture(swOn_texture);
		pduOff_texture.loadFromFile("pics/PDUOff.png", sf::IntRect(2 / 2, 2 / 2, 396 / 2, 38 / 2));
		pduOff.setTexture(pduOff_texture);
		pduOn_texture.loadFromFile("pics/PDUOn.png", sf::IntRect(4 / 2, 4 / 2, 396 / 2, 38 / 2));
		pduOn.setTexture(pduOn_texture);
		upsOff_texture.loadFromFile("pics/UPSOff.png", sf::IntRect(4 / 2, 6 / 2, 116 / 2, 180 / 2));
		upsOff.setTexture(upsOff_texture);
		upsOn_texture.loadFromFile("pics/UPSOn.png", sf::IntRect(7 / 2, 4 / 2, 116 / 2, 180 / 2));
		upsOn.setTexture(upsOn_texture);
		bleiqi.loadFromFile("pics/bileiqi.png");
		bLeiQi.setTexture(bleiqi);
		ac.loadFromFile("pics/AC.png");
		AC.setTexture(ac);
	}
	void setBoard() {
		//before first vertical line
		float x = 300/2, y = 580/2;
		int s_index = 1;
		ghLine.setPosition(x - 80 / 2, y);
		rhLine.setPosition(x + 68 / 2, y);
		swOff.setPosition(x, y - 49 / 2);
		rvLine.setPosition(x + 68 / 2 + 80 / 2, y + 10 / 2);
		bLeiQi.setPosition(x + (68 + 80 - 40) / 2, y + (10 + 80 + 80 + 80) / 2);
		layout["a0"] = ghLine;
		layout["s1"] = swOff;
		swOff.setPosition(x + (68 + 80 - 30) / 2, y + (10 + 80) / 2);
		layout["s2"] = swOff;
		layout["a1"] = rhLine;
		layout["a2"] = rvLine;
		rvLine.setPosition(x + (68 + 80) / 2, y + (10 + 80 + 97) / 2);
		layout["a3"] = rvLine;
		layout["blq1"] = bLeiQi;
		rhLine.setPosition(x + (80 + 68) / 2, y);
		layout["a4"] = rhLine;
		rhLine.setPosition(x + (80 + 80 + 68) / 2, y);
		layout["a5"] = rhLine;
		//middle part
		x = x + (80 + 80 + 68 + 80) / 2;//x=304
		y = 100 / 2;
		for (int i = 0; i < 16; i++) {
			string temp = to_string(i);
			rvLine.setPosition(x, y);
			layout["midv" + temp] = rvLine;
			y += 80 / 2;
		}
		x = (608 + 20) / 2;
		y = 100 / 2;
		s_index = 3;
		for (int i = 0; i < 10; i++) {
			int j = 0;
			string temp = to_string(i);
			string index = to_string(j);
			string s_string = to_string(s_index);
			rhLine.setPosition(x, y);
			layout["midh" + temp + index] = rhLine;
			rhLine.setPosition(x + 80 / 2, y);
			j++;
			index = to_string(j);
			layout["midh" + temp + index] = rhLine;
			swOff.setPosition(x + 80 / 2 + 80 / 2, y - (float)48.5 / 2);
			layout["s" + s_string] = swOff;
			s_index++;
			j++;
			rhLine.setPosition(x + 160 / 2 + 68 / 2, y);
			index = to_string(j);
			layout["midh" + temp + index] = rhLine;
			y += 140 / 2;
		}
		//AC & UPS
		x = 936 / 2;
		y = 240 / 2;
		AC.setPosition(x, y - (140 + 80) / 2);
		layout["ac"] = AC;
		for (int i = 0; i < 2; i++) {
			string temp = to_string(i + 3);
			rhLine.setPosition(x, y);
			layout["midh1" + temp] = rhLine;
			x += 80 / 2;
		}
		upsOff.setPosition(x, y - 80 / 2);
		layout["UPS"] = upsOff;
		rhLine.setPosition(x + 116 / 2, y);
		layout["midh15"] = rhLine;
		swOff.setPosition(x + 116 / 2 + 80 / 2, y - (float)48.5 / 2);
		layout["s13"] = swOff;
		for (int i = 0; i < 2; i++) {
			string temp = to_string(i + 6);
			rhLine.setPosition(x + (116 + 80 + 68) / 2, y);
			layout["midh1" + temp] = rhLine;
			x += 80 / 2;
		}
		y += 20 / 2;
		x -= 20 / 2;
		for (int i = 0; i < 2; i++) {
			string temp = to_string(i + 8);
			rvLine.setPosition(x + 116 / 2 + 68 / 2, y);
			layout["midh1" + temp] = rvLine;
			y += 80 / 2 + 97 / 2;
		}
		swOff.setPosition(x + (116 + 68) / 2 - 30 / 2, 260 / 2 + 80 / 2);
		layout["s14"] = swOff;
		bLeiQi.setPosition(x + (116 + 68) / 2 - 40 / 2, y - 97 / 2);
		layout["blq2"] = bLeiQi;
		//PDU
		x = 936 / 2;//608+20+160 + 68 + 80
		y = 380 / 2;
		for (int i = 0; i < 8; i++) {
			string pduNum = to_string(i + 1);
			pduOff.setPosition(x, y - 9 / 2);
			layout["PDU" + pduNum] = pduOff;
			y += 140 / 2;
		}
		//third part
		x = (1200 + 240 + 80) / 2;
		y = 100 / 2;
		for (int i = 0; i < 12; i++) {
			string temp = to_string(i);
			rvLine.setPosition(x, y);
			layout["lastv" + temp] = rvLine;
			y += 80 / 2;
		}
		temp_texture.loadFromFile("pics/vertical_line.png", sf::IntRect(0, 450 / 2, 20 / 2, 40 / 2));
		temp_Sprite.setTexture(temp_texture);
		temp_Sprite.setPosition(x, y);
		layout["lastv12"] = temp_Sprite;
		x += 20 / 2;
		y = 100 / 2;
		s_index = 15;
		for (int i = 0; i < 8; i++) {
			int j = 0;
			string temp = to_string(i);
			string index = to_string(j);
			rhLine.setPosition(x, y);
			layout["lasth" + temp + index] = rhLine;
			j++;
			index = to_string(j);
			rhLine.setPosition(x + 80 / 2, y);
			layout["lasth" + temp + index] = rhLine;
			string s_string = to_string(s_index);
			swOff.setPosition(x + 160 / 2, y - (float)48.5 / 2);
			layout["s" + s_string] = swOff;
			j++;
			index = to_string(j);
			rhLine.setPosition(x + 160 / 2 + 68 / 2, y);
			layout["lasth" + temp + index] = rhLine;
			pduOff.setPosition(x + 160 / 2 + 68 / 2 + 80 / 2, y - 9 / 2);
			layout["UPSPDU" + temp] = pduOff;
			y += 140 / 2;
			s_index++;
		}
		for (int i = 0; i < 22; i++) {
			switch_Status[i + 1] = false;
		}
	}
	string clickOnSwitch(int x, int y) {
		//switch 68*97
		map<string, pair<float, float>> s;
		pair<float, float> temp;
		for (auto it : layout) {
			if (it.first.at(0) == 's') {
				temp.first = it.second.getPosition().x;
				temp.second = it.second.getPosition().y;
				s[it.first] = temp;
			}
		}
		for (auto it : s) {
			if (x > it.second.first&& x<it.second.first + 68 / 2 &&
				y>it.second.second&& y < it.second.second + 97 / 2) {
				return it.first;
			}
		}
		return "false";
	}

	void setS1() {
		if (!switch_Status[1]) {
			float x = getPosition("s1").first;
			float y = getPosition("s1").second;
			swOn.setPosition(x, y);
			layout["s1"] = swOn;
			for (auto it : layout) {
				string temp = it.first;
				if (temp == "a1" || temp == "a4" || temp == "a5" ||
					(temp.substr(0, 4) == "midh" && temp.at(5) == '0') ||
					(temp.substr(0, 4) == "midh" && temp.at(5) == '1')) {
					float x = getPosition(temp).first;
					float y = getPosition(temp).second;
					ghLine.setPosition(x, y);
					layout[temp] = ghLine;
				}
				else if (temp == "a2" ||
					temp.substr(0, 4) == "midv") {
					float x = getPosition(temp).first;
					float y = getPosition(temp).second;
					gvLine.setPosition(x, y);
					layout[temp] = gvLine;
				}
				switch_Status[1] = true;
			}
			for (int i = 2; i < 13; i++) {
				if (switch_Status[i] == true) {
					setGeneral("s" + to_string(i),"s1");
				}
			}
		}
		else {
			float x = getPosition("s1").first;
			float y = getPosition("s1").second;
			swOff.setPosition(x, y);
			layout["s1"] = swOff;
			for (auto it : layout) {
				string temp = it.first;
				if (temp == "a1" || temp == "a4" || temp == "a5" ||
					(temp.substr(0, 4) == "midh" && temp.at(5) == '0') ||
					(temp.substr(0, 4) == "midh" && temp.at(5) == '1')) {
					float x = getPosition(temp).first;
					float y = getPosition(temp).second;
					rhLine.setPosition(x, y);
					layout[temp] = rhLine;
				}
				else if (temp == "a2" ||
					temp.substr(0, 4) == "midv") {
					float x = getPosition(temp).first;
					float y = getPosition(temp).second;
					rvLine.setPosition(x, y);
					layout[temp] = rvLine;
				}
				switch_Status[1] = false;
			}
			for (int i = 2; i < 13; i++) {
				if (switch_Status[i] == true) {
					setGeneral("s" + to_string(i),"s1");
				}
			}
		}
	}
	void setS13(string type) {
		pair<float, float>temp = getPosition("s13");
		sf::Sprite lineTemp;
		sf::Sprite vLineTemp;
		if (type=="s13"&&switch_Status[1] == true && switch_Status[4] == true && 
			switch_Status[13] == true) {
			lineTemp = ghLine;
			vLineTemp = gvLine;
			temp_texture.loadFromFile("pics/vertical_line.png", sf::IntRect(0, 0, 20 / 2, 40 / 2));
			for (int i = 0; i < 2; i++) {
				float x = getPosition("midh1" + to_string(i + 6)).first;
				float y = getPosition("midh1" + to_string(i + 6)).second;
				lineTemp.setPosition(x, y);
				layout["midh1" + to_string(i + 6)] = lineTemp;
			}
			float x = getPosition("midh1" + to_string(8)).first;
			float y = getPosition("midh1" + to_string(8)).second;
			vLineTemp.setPosition(x, y);
			layout["midh18"] = vLineTemp;
			for (int i = 0; i < 12; i++) {
				x = getPosition("lastv" + to_string(i)).first;
				y = getPosition("lastv" + to_string(i)).second;
				vLineTemp.setPosition(x, y);
				layout["lastv" + to_string(i)] = vLineTemp;
			}
			for (int i = 0; i < 8; i++) {
				int j = 0;
				string temp = "lasth" + to_string(i) + to_string(j);
				x = getPosition(temp).first;
				y = getPosition(temp).second;
				lineTemp.setPosition(x, y);
				layout[temp] = lineTemp;
				j++;
				temp = "lasth" + to_string(i) + to_string(j);
				x = getPosition(temp).first;
				y = getPosition(temp).second;
				lineTemp.setPosition(x, y);
				layout[temp] = lineTemp;
			}
			for (int i = 14; i < 23; i++) {
				if (switch_Status[i] == true) {
					setGeneral("s" + to_string(i), "s13");
				}
			}
		}
		else if (type=="s13"&&(switch_Status[1] == false || switch_Status[4] == false || 
			switch_Status[13] == false)) {
			lineTemp = rhLine;
			vLineTemp = rvLine;
			temp_texture.loadFromFile("pics/vertical_line.png", sf::IntRect(0, 450 / 2, 12 / 2, 40 / 2));
			for (int i = 0; i < 2; i++) {
				float x = getPosition("midh1" + to_string(i + 6)).first;
				float y = getPosition("midh1" + to_string(i + 6)).second;
				lineTemp.setPosition(x, y);
				layout["midh1" + to_string(i + 6)] = lineTemp;
			}
			float x = getPosition("midh1" + to_string(8)).first;
			float y = getPosition("midh1" + to_string(8)).second;
			vLineTemp.setPosition(x, y);
			layout["midh18"] = vLineTemp;
			for (int i = 0; i < 12; i++) {
				x = getPosition("lastv" + to_string(i)).first;
				y = getPosition("lastv" + to_string(i)).second;
				vLineTemp.setPosition(x, y);
				layout["lastv" + to_string(i)] = vLineTemp;
			}
			for (int i = 0; i < 8; i++) {
				int j = 0;
				string temp = "lasth" + to_string(i) + to_string(j);
				x = getPosition(temp).first;
				y = getPosition(temp).second;
				lineTemp.setPosition(x, y);
				layout[temp] = lineTemp;
				j++;
				temp = "lasth" + to_string(i) + to_string(j);
				x = getPosition(temp).first;
				y = getPosition(temp).second;
				lineTemp.setPosition(x, y);
				layout[temp] = lineTemp;
			}
			for (int i = 14; i < 23; i++) {
				if (switch_Status[i] == true) {
					setGeneral("s" + to_string(i), "s13");
				}
			}
		}
		else if (switch_Status[1]==true&&switch_Status[4] == true && switch_Status[13] == false) {
			swOn.setPosition(temp.first, temp.second);
			layout["s13"] = swOn;
			lineTemp = ghLine;
			vLineTemp = gvLine;
			temp_texture.loadFromFile("pics/vertical_line.png", sf::IntRect(0, 0, 20 / 2, 40 / 2));
			switch_Status[13] = true;
			for (int i = 0; i < 2; i++) {
				float x = getPosition("midh1" + to_string(i + 6)).first;
				float y = getPosition("midh1" + to_string(i + 6)).second;
				lineTemp.setPosition(x, y);
				layout["midh1" + to_string(i + 6)] = lineTemp;
			}
			float x = getPosition("midh1" + to_string(8)).first;
			float y = getPosition("midh1" + to_string(8)).second;
			vLineTemp.setPosition(x, y);
			layout["midh18"] = vLineTemp;
			for (int i = 0; i < 12; i++) {
				x = getPosition("lastv" + to_string(i)).first;
				y = getPosition("lastv" + to_string(i)).second;
				vLineTemp.setPosition(x, y);
				layout["lastv" + to_string(i)] = vLineTemp;
			}
			for (int i = 0; i < 8; i++) {
				int j = 0;
				string temp = "lasth" + to_string(i) + to_string(j);
				x = getPosition(temp).first;
				y = getPosition(temp).second;
				lineTemp.setPosition(x, y);
				layout[temp] = lineTemp;
				j++;
				temp = "lasth" + to_string(i) + to_string(j);
				x = getPosition(temp).first;
				y = getPosition(temp).second;
				lineTemp.setPosition(x, y);
				layout[temp] = lineTemp;
			}
			for (int i = 14; i < 23; i++) {
				if (switch_Status[i] == true) {
					setGeneral("s" + to_string(i), "s13");
				}
			}
		}
		else {
			lineTemp = rhLine;
			vLineTemp = rvLine;
			temp_texture.loadFromFile("pics/vertical_line.png", sf::IntRect(0, 450 / 2, 12 / 2, 40 / 2));
			if (switch_Status[13] == false) {
				temp_Sprite = swOn;
				switch_Status[13] = true;
			}
			else {
				temp_Sprite = swOff;
				switch_Status[13] = false;
			}
			temp_Sprite.setPosition(temp.first, temp.second);
			layout["s13"] = temp_Sprite;
			for (int i = 0; i < 2; i++) {
				float x = getPosition("midh1" + to_string(i + 6)).first;
				float y = getPosition("midh1" + to_string(i + 6)).second;
				lineTemp.setPosition(x, y);
				layout["midh1" + to_string(i + 6)] = lineTemp;
			}
			float x = getPosition("midh1" + to_string(8)).first;
			float y = getPosition("midh1" + to_string(8)).second;
			vLineTemp.setPosition(x, y);
			layout["midh18"] = vLineTemp;
			for (int i = 0; i < 12; i++) {
				x = getPosition("lastv" + to_string(i)).first;
				y = getPosition("lastv" + to_string(i)).second;
				vLineTemp.setPosition(x, y);
				layout["lastv" + to_string(i)] = vLineTemp;
			}
			for (int i = 0; i < 8; i++) {
				int j = 0;
				string temp = "lasth" + to_string(i) + to_string(j);
				x = getPosition(temp).first;
				y = getPosition(temp).second;
				lineTemp.setPosition(x, y);
				layout[temp] = lineTemp;
				j++;
				temp = "lasth" + to_string(i) + to_string(j);
				x = getPosition(temp).first;
				y = getPosition(temp).second;
				lineTemp.setPosition(x, y);
				layout[temp] = lineTemp;
			}
			for (int i = 14; i < 23; i++) {
				if (switch_Status[i] == true) {
					setGeneral("s" + to_string(i), "s13");
				}
			}
		}
	}
	void setGeneral(string switchName,string type) {
		if (switchName == "s2") {
			if (switch_Status[1]==true) {
				if (type == "s1") {
					float x = getPosition("a3").first;
					float y = getPosition("a3").second;
					gvLine.setPosition(x, y);
					layout["a3"] = gvLine;
				}
				else if (switch_Status[2]==false) {
					float x = getPosition(switchName).first;
					float y = getPosition(switchName).second;
					swOn.setPosition(x, y);
					layout[switchName] = swOn;
					x = getPosition("a3").first;
					y = getPosition("a3").second;
					gvLine.setPosition(x, y);
					layout["a3"] = gvLine;
					switch_Status[2] = true;
				}
				else {
					float x = getPosition(switchName).first;
					float y = getPosition(switchName).second;
					swOff.setPosition(x, y);
					layout[switchName] = swOff;
					x = getPosition("a3").first;
					y = getPosition("a3").second;
					rvLine.setPosition(x, y);
					layout["a3"] = rvLine;
					switch_Status[2] = false;
				}
			}
			else {
				float x = getPosition(switchName).first;
				float y = getPosition(switchName).second;
				if (type == "s1") {
					float x = getPosition("a3").first;
					float y = getPosition("a3").second;
					rvLine.setPosition(x, y);
					layout["a3"] = rvLine;
				}
				else if (!switch_Status[2]) {
					swOn.setPosition(x, y);
					layout["s2"] = swOn;
					switch_Status[2] = true;
				}
				else {
					swOff.setPosition(x, y);
					layout[switchName] = swOff;
					switch_Status[2] = false;
				}
			}
		}
		else if (switchName == "s3") {
			if (type == "s1"&&switch_Status[1]==true&&switch_Status[3]==true) {
				pair<float, float> temp = getPosition(switchName);
				ghLine.setPosition(temp.first + 68 / 2, temp.second + 49 / 2);
				layout["midh02"] = ghLine;
			}
			else if (type == "s1" && switch_Status[1] == false) {
				pair<float, float> temp = getPosition(switchName);
				rhLine.setPosition(temp.first + 68 / 2, temp.second + 49 / 2);
				layout["midh02"] = rhLine;
			}
			else if (switch_Status[1] == true && switch_Status[3] == false) {
				pair<float, float> temp = getPosition(switchName);
				swOn.setPosition(temp.first, temp.second);
				layout[switchName] = swOn;
				ghLine.setPosition(temp.first + 68 / 2, temp.second+49 / 2);
				layout["midh02"] = ghLine;
				switch_Status[3] = true;
			}
			else {
				pair<float, float> temp = getPosition(switchName);
				if (switch_Status[3] == false) {
					swOn.setPosition(temp.first, temp.second);
					layout[switchName] = swOn;
					switch_Status[3] = true;
				}
				else {
					swOff.setPosition(temp.first, temp.second);
					layout[switchName] = swOff;
					rhLine.setPosition(temp.first + 68 / 2, temp.second+49 / 2);
					layout["midh02"] = rhLine;
					switch_Status[3] = false;
				}
			}
		}
		else if (switchName == "s4") {
			pair<float, float> temp = getPosition(switchName);
			if (type == "s1" && switch_Status[1] == true && switch_Status[4] == true) {
				for (int i = 0; i < 4; i++) {
					float x = getPosition("midh1" + to_string(i + 2)).first;
					float y = getPosition("midh1" + to_string(i + 2)).second;
					ghLine.setPosition(x, y);
					layout["midh1" + to_string(i + 2)] = ghLine;
					x = getPosition("UPS").first;
					y = getPosition("UPS").second;
					upsOn.setPosition(x, y);
					layout["UPS"] = upsOn;
				}
				setS13("s13");
			}
			else if (type == "s1" && switch_Status[1] == false) {
				for (int i = 0; i < 4; i++) {
					float x = getPosition("midh1" + to_string(i + 2)).first;
					float y = getPosition("midh1" + to_string(i + 2)).second;
					rhLine.setPosition(x, y);
					layout["midh1" + to_string(i + 2)] = rhLine;
					x = getPosition("UPS").first;
					y = getPosition("UPS").second;
					upsOff.setPosition(x, y);
					layout["UPS"] = upsOff;
				}
				setS13("s13");
			}
			else if (switch_Status[1] == true&&switch_Status[4]==false) {
				swOn.setPosition(temp.first, temp.second);
				layout["s4"] = swOn;
				for (int i = 0; i < 4; i++) {
					float x = getPosition("midh1" + to_string(i + 2)).first;
					float y = getPosition("midh1" + to_string(i + 2)).second;
					ghLine.setPosition(x, y);
					layout["midh1" + to_string(i + 2)] = ghLine;
					x = getPosition("UPS").first;
					y = getPosition("UPS").second;
					upsOn.setPosition(x,y);
					layout["UPS"] = upsOn;
					switch_Status[4] = true;
				}
				setS13("s13");
			}
			else {
				if (switch_Status[4] == false) {
					swOn.setPosition(temp.first, temp.second);
					layout["s4"] = swOn;
					switch_Status[4] = true;
				}
				else {
					swOff.setPosition(temp.first, temp.second);
					layout["s4"] = swOff;
					switch_Status[4] = false;
				}
				for (int i = 0; i < 4; i++) {
					float x = getPosition("midh1" + to_string(i + 2)).first;
					float y = getPosition("midh1" + to_string(i + 2)).second;
					rhLine.setPosition(x, y);
					layout["midh1" + to_string(i + 2)] = rhLine;
					x = getPosition("UPS").first;
					y = getPosition("UPS").second;
					upsOff.setPosition(x, y);
					layout["UPS"] = upsOff;
				}
				setS13("s13");
			}
		}
		//when switchName="s5"-"s12"
		for (int i = 0; i < 8; i++) {
			if (switchName.substr(1, 1) == to_string(i + 5) ||
				switchName.substr(1, 2) == to_string(i + 5)) {
				pair<float, float> temp = getPosition(switchName);
				if (type == "s1" && switch_Status[1] == true && switch_Status[i + 5] == true) {
					ghLine.setPosition(temp.first + 68 / 2, temp.second + 49 / 2);
					layout["midh" + to_string(i + 2) + "2"] = ghLine;
					pduOn.setPosition((float)(temp.first + 68 / 2 + 80 / 2), (float)(temp.second + 49 / 2 - 9.5 / 2));
					layout["PDU" + to_string(i + 1)] = pduOn;
				}
				else if (type == "s1" && switch_Status[1] == false) {
					rhLine.setPosition(temp.first + 68 / 2, temp.second + 49 / 2);
					layout["midh" + to_string(i + 2) + "2"] = rhLine;
					pduOff.setPosition((float)(temp.first + 68 / 2 + 80 / 2), (float)(temp.second + 49 / 2 - 9.5 / 2));
					layout["PDU" + to_string(i + 1)] = pduOff;
				}
				else if (switch_Status[1] == true && switch_Status[i + 5] == false) {
					swOn.setPosition(temp.first, temp.second);
					layout[switchName] = swOn;
					ghLine.setPosition(temp.first + 68 / 2, temp.second + 49 / 2);
					layout["midh" + to_string(i + 2) + "2"] = ghLine;
					pduOn.setPosition((float)(temp.first + 68 / 2 + 80 / 2), (float)(temp.second + 49 / 2 - 9.5 / 2));
					layout["PDU" + to_string(i + 1)] = pduOn;
					switch_Status[i + 5] = true;
				}
				else {
					if (switch_Status[i + 5] == true) {
						swOff.setPosition(temp.first, temp.second);
						layout[switchName] = swOff;
						switch_Status[i + 5] = false;
					}
					else {
						swOn.setPosition(temp.first, temp.second);
						layout[switchName] = swOn;
						switch_Status[i + 5] = true;
					}
					rhLine.setPosition(temp.first + 68 / 2, temp.second + 49 / 2);
					layout["midh" + to_string(i + 2) + "2"] = rhLine;
					pduOff.setPosition((float)(temp.first + 68 / 2 + 80 / 2), (float)(temp.second + 49 / 2 - 9.5 / 2));
					layout["PDU" + to_string(i + 1)] = pduOff;
				}
			}
		}
		if (switchName == "s14") {
			pair<float, float> temp = getPosition(switchName);
			if (type == "s13" && switch_Status[1] == true && switch_Status[4] == true &&
				switch_Status[13] == true&&switch_Status[14]==true) {
				temp = getPosition("midh19");
				gvLine.setPosition(temp.first, temp.second);
				layout["midh19"] = gvLine;
			}
			else if (switch_Status[1]==true&&switch_Status[4]==true&&switch_Status[13] == true) {
				if (switch_Status[14] == false) {
					swOn.setPosition(temp.first, temp.second);
					temp = getPosition("midh19");
					gvLine.setPosition(temp.first,temp.second);
					layout["s14"] = swOn;
					layout["midh19"] = gvLine;
					switch_Status[14] = true;
				}
				else {
					swOff.setPosition(temp.first, temp.second);
					temp = getPosition("midh19");
					rvLine.setPosition(temp.first, temp.second);
					layout["s14"] = swOff;
					layout["midh19"] = rvLine;
					switch_Status[14] = false;
				}
			}
			else {
				if (type == "s13" && (switch_Status[1] == false || switch_Status[4] == false ||
					switch_Status[13] == false)) {
					temp = getPosition("midh19");
					rvLine.setPosition(temp.first, temp.second);
					layout["midh19"] = rvLine;
				}
				else if (switch_Status[14] == false) {
					swOn.setPosition(temp.first, temp.second);
					layout["s14"] = swOn;
					switch_Status[14] = true;
				}
				else {
					swOff.setPosition(temp.first, temp.second);
					layout["s14"] = swOff;
					switch_Status[14] = false;
				}
				temp = getPosition("midh19");
				rvLine.setPosition(temp.first, temp.second);
				layout["midh19"] = rvLine;
			}
		}
		//when switchName="s15"-"s22"
		for (int i = 15; i < 23; i++) {
			if (switchName == "s" + to_string(i)) {
				float x = getPosition(switchName).first;
				float y = getPosition(switchName).second;
				sf::Sprite hLine, pdu,s;
				if (type == "s13" && switch_Status[1] == true && switch_Status[4] == true &&
					switch_Status[13] == true && switch_Status[i] == true) {
					hLine = ghLine;
					pdu = pduOn;
					x = getPosition("lasth" + to_string(i - 15) + '2').first;
					y = getPosition("lasth" + to_string(i - 15) + '2').second;
					hLine.setPosition(x, y);
					layout["lasth" + to_string(i - 15) + '2'] = hLine;
					x = getPosition("UPSPDU" + to_string(i - 15)).first;
					y = getPosition("UPSPDU" + to_string(i - 15)).second;
					pdu.setPosition(x, y);
					layout["UPSPDU" + to_string(i - 15)] = pdu;
				}
				else if (type == "s13" && (switch_Status[1] == false || switch_Status[4] == false ||
					switch_Status[13] == false)) {
					hLine = rhLine;
					pdu = pduOff;
					x = getPosition("lasth" + to_string(i - 15) + '2').first;
					y = getPosition("lasth" + to_string(i - 15) + '2').second;
					hLine.setPosition(x, y);
					layout["lasth" + to_string(i - 15) + '2'] = hLine;
					x = getPosition("UPSPDU" + to_string(i - 15)).first;
					y = getPosition("UPSPDU" + to_string(i - 15)).second;
					pdu.setPosition(x, y);
					layout["UPSPDU" + to_string(i - 15)] = pdu;
				}
				else if (switch_Status[1] == true && switch_Status[4] == true && 
					switch_Status[13] == true && switch_Status[i] == false) {
					hLine = ghLine;
					pdu = pduOn;
					s = swOn;
					s.setPosition(x, y);
					layout[switchName] = s;
					x = getPosition("lasth" + to_string(i - 15) + '2').first;
					y = getPosition("lasth" + to_string(i - 15) + '2').second;
					hLine.setPosition(x, y);
					layout["lasth" + to_string(i - 15) + '2'] = hLine;
					x = getPosition("UPSPDU" + to_string(i - 15)).first;
					y = getPosition("UPSPDU" + to_string(i - 15)).second;
					pdu.setPosition(x, y);
					layout["UPSPDU" + to_string(i - 15)] = pdu;
					switch_Status[i] = true;
				}
				else {
					hLine = rhLine;
					pdu = pduOff;
					if (switch_Status[i] == true) {
						s = swOff;
						switch_Status[i] = false;
					}
					else {
						s = swOn;
						switch_Status[i] = true;
					}
					s.setPosition(x, y);
					layout[switchName] = s;
					x = getPosition("lasth" + to_string(i - 15) + '2').first;
					y = getPosition("lasth" + to_string(i - 15) + '2').second;
					hLine.setPosition(x, y);
					layout["lasth" + to_string(i - 15) + '2'] = hLine;
					x = getPosition("UPSPDU" + to_string(i - 15)).first;
					y = getPosition("UPSPDU" + to_string(i - 15)).second;
					pdu.setPosition(x, y);
					layout["UPSPDU" + to_string(i - 15)] = pdu;
				}
			}
		}
	}


	pair<float,float> getPosition(string input) {
		pair<float, float> temp;
		for (auto it : layout) {
			if (it.first == input) {
				temp.first = it.second.getPosition().x;
				temp.second = it.second.getPosition().y;
				return  temp;
			}
		}
		temp.first = 0;
		temp.second = 0;
		return temp; 
	}

	map<string, sf::Sprite> getMap() {
		return layout;
	}
};