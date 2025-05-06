#include "pch.h"
#include "CppUnitTest.h"
#include "../Calculator/Calculator.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace UnitTestCalculator
{
	TEST_CLASS(UnitTestCalculator)
	{
	public:
		TEST_METHOD(TestSuma)
		{
			a = 5;
			b = 7;
			sumar();
			Assert::AreEqual(12, suma,
				L"Error en la función sumar: el resultado no es el esperado.");
		}
	};
}