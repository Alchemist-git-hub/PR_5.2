#include "pch.h"
#include "CppUnitTest.h"
#include "../PR5.2/pr5.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testPR52
{
	TEST_CLASS(testPR52)
	{
	public:
		
        // Перевірка функції A()
        TEST_METHOD(TestA)
        {
            double a = 2.0 / 2.0;
            double result = A(2.0, 1, a);

            Assert::AreEqual(1.0 / 12.0, result, 0.000001);
        }

        // Перевірка функції S()
        TEST_METHOD(TestS)
        {
            int n = 0;
            double result = S(2.0, 0.000001, n);

            Assert::AreEqual(log(3.0), result, 0.00001);
        }
	};
}
