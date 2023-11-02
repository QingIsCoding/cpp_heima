#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "Speaker.h"
#include <algorithm>
#include <deque>
#include <functional>
#include <numeric>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

class SpeechManager
{
	public:
		vector<int> v1;
		vector<int> v2;
		vector<int> v_victory;
		map<int,Speaker> m_speaker;
		int m_index;
		bool FileIsEmpty;
		map<int,vector<string>> m_record;

		SpeechManager();
		void ShowMenu();
		void ExitSystem();
		void InitializeSpeech();
		void CreateSpeaker();
		void StartSpeech();
		void SpeechDraw();
		void SpeechContest();
		void ShowScore();
		void SaveRecord();
		void LoadRecord();
		void ShowRecord();
		void ClearRecord();
		
		~SpeechManager();
};
