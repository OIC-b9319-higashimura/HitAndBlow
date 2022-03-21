// Hit_Blow.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <random>
#include <string>

//　50分で完成

int main()
{
	std::random_device seed; // random用の種を決める
	std::mt19937 mt(seed()); // randomを生成

	std::vector<int> list = { 0,1,2,3,4,5,6,7,8,9 };
	std::string QuestionNum;

	for (int i = 0; i < 4; i++)
	{
		int rnd = mt() % (10 - i);					// ① ③でリストのサイズが減るので、i分減らす。
		QuestionNum += std::to_string(list[rnd]);	// ② リストから選ばれた数字を問題に入れる
		list.erase(list.begin() + rnd);				// ③ リストから選ばれて数字を消す
	}
	
    std::cout << "Answer:" << QuestionNum << std::endl; // 答えの出力


	while (true)
	{
		std::string TestNum; //　ユーザーの入力格納用
		std::cout << "TestNumber = "; std::cin >> TestNum; // ユーザー入力

		// スコア変数
		int Hit = 0;
		int Blow = 0;

		for (int i = 0; i < TestNum.size(); i++)
		{
			for (int n = 0; n < QuestionNum.size(); n++)
			{
				// TestNum[i]	  入力の i 文字目
				// QuestionNum[n] 問題の n 文字目
				if (TestNum[i] == QuestionNum[n]) {
					if (i == n) { 
						// 数字の場所が同じ
						Hit++;
					} // if
					else { 
						// 数字の場所は違うが同じ数字がある
						Blow++;
					} // else
				} // if
			} // for
		} // for

		
		std::cout << "Hit, Blow = " << Hit << ", " << Blow << std::endl; // スコアの出力

		// 完全解答でループを抜ける
		if (Hit == 4) {
			std::cout << "complete !!" << std::endl;
			break;
		}
	}
}