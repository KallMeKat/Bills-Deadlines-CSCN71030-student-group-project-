#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
extern "C" typedef struct playerstats
{

	//very basics for working overworld:
	int energy;
	int day;
	int cash;
	int time;


	//others stats here - these are unimplemented 
	unsigned int hp;
	unsigned int str;
	unsigned int cha;
	unsigned int intl;


} PlayerStats;

extern "C" int damagePlayer(int scale, PlayerStats stats[]);
extern "C" int  healPlayer(int scale, PlayerStats stats[]);
extern "C" int decreaseEnergy(int scale, PlayerStats stats[]);
extern "C" int increaseEnergy(int scale, PlayerStats stats[]);
extern "C" int resetEnergy(PlayerStats stats[]);

extern "C" int levelCha(int scale, PlayerStats stats[]);

extern "C" int loseCha(int scale, PlayerStats stats[]);

namespace PlayerStatsTest
{
	TEST_CLASS(PlayerStatsTest)
	{
	public:

		TEST_METHOD(HEAL_DAMAGE)
		{
			PlayerStats p[1] = { '\0' };
			p[0].hp = 10;
			int expected = 9;
			Assert::AreEqual(expected, damagePlayer(1, p));

			PlayerStats p1[1] = { '\0' };
			p1[0].hp = 10;
			int expected1 = 8;
			Assert::AreEqual(expected1, damagePlayer(2, p1));

			PlayerStats p2[1] = { '\0' };
			p2[0].hp = 9;
			int expected2 = 10;
			Assert::AreEqual(expected2, healPlayer(1, p2));

			PlayerStats p3[1] = { '\0' };
			p3[0].hp = 8;
			int expected3 = 10;
			Assert::AreEqual(expected3, healPlayer(2, p3));

		}


		TEST_METHOD(INCREASE_DECREASE_RESET)
		{
			PlayerStats p[1] = { '\0' };
			p[0].energy = 10;
			int expected = 9;
			Assert::AreEqual(expected, decreaseEnergy(1, p));


			PlayerStats p1[1] = { '\0' };
			p1[0].energy = 10;
			int expected1 = 8;
			Assert::AreEqual(expected1, decreaseEnergy(2, p1));

			PlayerStats p2[1] = { '\0' };
			p2[0].energy = 9;
			int expected2 = 10;
			Assert::AreEqual(expected2, increaseEnergy(1, p2));

			PlayerStats p3[1] = { '\0' };
			p3[0].energy = 8;
			int expected3 = 10;
			Assert::AreEqual(expected3, increaseEnergy(2, p3));

			PlayerStats p4[1] = { '\0' };
			p4[0].energy = 9;
			int expected4 = 10;
			Assert::AreEqual(expected4, resetEnergy(p4));

			PlayerStats p5[1] = { '\0' };
			p5[0].energy = 8;
			int expected5 = 10;
			Assert::AreEqual(expected5, resetEnergy(p5));
		}

		TEST_METHOD(LEVEL_LOSE)
		{
			PlayerStats p[1] = { '\0' };
			p[0].cha = 10;
			int expected = 9;
			Assert::AreEqual(expected, loseCha(1, p));


			PlayerStats p1[1] = { '\0' };
			p1[0].cha = 10;
			int expected1 = 8;
			Assert::AreEqual(expected1, loseCha(2, p1));

			PlayerStats p2[1] = { '\0' };
			p2[0].cha = 9;
			int expected2 = 10;
			Assert::AreEqual(expected2, levelCha(1, p2));

			PlayerStats p3[1] = { '\0' };
			p3[0].cha = 8;
			int expected3 = 10;
			Assert::AreEqual(expected3, levelCha(2, p3));

		}

	
	};
}
