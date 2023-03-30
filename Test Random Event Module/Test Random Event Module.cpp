#include "pch.h"
#include "CppUnitTest.h"

extern "C" struct Encounter {
	int id;
	char description[100];
	struct Encounter* next;
};
extern "C" struct Encounter* createEncounter(int id, char desc[]);
extern "C" struct Encounter* selectEncounter(struct Encounter* head);
extern "C" int random_number();
extern "C" struct Encounter* initializeEncounters();
extern "C" struct Encounter* initializeJobEncounters();

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestRandomEventModule
{
	TEST_CLASS(TestRandomEventModule)
	{
	public:
		
		TEST_METHOD(TestSelectEncounterAll)
		{
			struct Encounter* parkEncounters = initializeEncounters();
			struct Encounter* jobEncounters = initializeJobEncounters();

			struct Encounter* selectedParkEncounter = selectEncounter(parkEncounters);
			struct Encounter* selectedJobEncounter = selectEncounter(jobEncounters);

			if (selectedParkEncounter->id == 1) {
				Assert::AreEqual("A homeless person pulls a knife on you. What do you do?\n", selectedParkEncounter->description);
			}
			else if (selectedParkEncounter->id == 2) {
				Assert::AreEqual("As you are leaving the park, you spot a wallet lying on the ground. What do you do?\n", selectedParkEncounter->description);
			}
			else if (selectedParkEncounter->id == 3) {
				Assert::AreEqual("Some random event happens?\n", selectedParkEncounter->description);
			}
			else {
				Assert::Fail(L"No encounter selected from park encounters");
			}

			if (selectedJobEncounter->id == 1) {
				Assert::AreEqual("You catch a shoplifter in the act. What do you do?\n", selectedJobEncounter->description);
			}
			else if (selectedJobEncounter->id == 2) {
				Assert::AreEqual("Two customers are fighting over the last TV in the store. What do you do?\n", selectedJobEncounter->description);
			}
			else if (selectedJobEncounter->id == 3) {
				Assert::AreEqual("You are working at Walmart when you notice a group of teenagers attempting to steal some electronics. What do you do?\n", selectedJobEncounter->description);
			}
			else {
				Assert::Fail(L"No encounter selected from job encounters");
			}
		}

		TEST_METHOD(TestRandomNumberReturnsNumberInRange)
		{
			int randomNumber = random_number();

			Assert::IsTrue(randomNumber >= 1 && randomNumber <= 6);
		}

		TEST_METHOD(TestCreateEncounter)
		{
			int expectedId = 1;
			char expectedDesc[] = "A homeless person pulls a knife on you. What do you do?\n";

			struct Encounter* newEncounter = createEncounter(expectedId, expectedDesc);

			Assert::AreEqual(expectedId, newEncounter->id);
			Assert::AreEqual(expectedDesc, newEncounter->description);
		}

		TEST_METHOD(TestInitializeJobEncounters)
		{
			struct Encounter* head = initializeJobEncounters();

			// Verify first job encounter
			int expectedId1 = 1;
			char expectedDesc1[] = "You catch a shoplifter in the act. What do you do?\n";
			Assert::AreEqual(expectedId1, head->id);
			Assert::AreEqual(expectedDesc1, head->description);

			// Verify second job encounter
			int expectedId2 = 2;
			char expectedDesc2[] = "Two customers are fighting over the last TV in the store. What do you do?\n";
			Assert::AreEqual(expectedId2, head->next->id);
			Assert::AreEqual(expectedDesc2, head->next->description);

			// Verify third job encounter
			int expectedId3 = 3;
			char expectedDesc3[] = "You are working at Walmart when you notice a group of teenagers attempting to steal some electronics. What do you do?\n";
			Assert::AreEqual(expectedId3, head->next->next->id);
			Assert::AreEqual(expectedDesc3, head->next->next->description);
		}


	};
}
