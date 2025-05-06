#include "pch.h"
#include "CppUnitTest.h"
#include "..\SegundoGrado\SegundoGrado.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PruebaSegundoGrado
{
	TEST_CLASS(PruebaSegundoGrado)
	{
	public:
		TEST_METHOD(DosSolucionesReales)
		{
			a = 1;
			b = -3;
			c = 2;
			discriminar();
			Assert::AreEqual(2, numSols, L"No hay 2 soluciones");
		}

		TEST_METHOD(DiscriminanteNegativo)
		{
			a = 1;
			b = 2;
			c = 5;
			discriminar();
			Assert::AreEqual(0, numSols, L"El discriminante no es negativo");
		}

		TEST_METHOD(TestRaicesDobles)
		{
			a = 1;
			b = 2;
			c = 1;
			discriminar();
			Assert::AreEqual(1, numSols, L"No hay solo 1 resutado");
		}
	};
}