#include "CppUnitTest.h"
#include "GameObjectLib.h"
#include "Vector_math.h"
#define _USE_MATH_DEFINES

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
    TEST_CLASS(UnitTests)
    {
    public:
        TEST_METHOD(TestMethod1)
        {
            HelloFromLib();
            Assert::IsTrue(1 + 1 == 2);
        }
        TEST_METHOD(TestMagnitude)
        {
            Vector<double, double> vector(3.0, 4.0);
            double result = vector.magnitude();
            Assert::IsTrue(result == 5.0);
        }
        TEST_METHOD(TestNormalize)
        {
            Vector<double, double> vector(3.0, 4.0);
            Vector<double, double> result = vector.normalize();
            Assert::AreEqual(result.getX(), 0.6);
        }
        TEST_METHOD(TestMinVector)
        {
            Vector<int, int> left(3, 4);
            Vector<int, int> right(1, 2);

            Vector<int, int> result = Vector<int, int>::minVector(left, right);

            Assert::AreEqual(result.getX(), 1);
            Assert::AreEqual(result.getY(), 2);
        }
        TEST_METHOD(TestMaxVector)
        {
            Vector<int, int> left(3, 4);
            Vector<int, int> right(1, 2);

            Vector<int, int> result = Vector<int, int>::maxVector(left, right);

            Assert::AreEqual(result.getX(), 3);
            Assert::AreEqual(result.getY(), 4);
        }
        TEST_METHOD(TestPerpendicularVector)
        {
            Vector<int, int> vector(3, 4);

            Vector<int, int> result_x = Vector<int, int>::perpendiculaireVector(vector, 'x');
            Vector<int, int> result_y = Vector<int, int>::perpendiculaireVector(vector, 'y');

            Assert::AreEqual(result_x.getX(), -3);
            Assert::AreEqual(result_x.getY(), 4);

            Assert::AreEqual(result_y.getX(), 3);
            Assert::AreEqual(result_y.getY(), -4);
        }
        TEST_METHOD(TestReflectVector)
        {
            Vector<int, int> vector(3, 4);

            Vector<int, int> normal(1, 1);

            Vector<int, int> result = Vector<int, int>::reflectVector(vector, normal);

            Assert::AreEqual(result.getX(), 3);
            Assert::AreEqual(result.getY(), 4);
        }
        TEST_METHOD(TestDotVector)
        {
            Vector<int, int> vector1(3, 4);
            Vector<int, int> vector2(1, 2);

            double result = Vector<int, int>::dotVector(vector1, vector2);

            Assert::AreEqual(result, 11.0);
        }
        TEST_METHOD(TestLerpVector)
        {
           Vector<double, double> vector1(3.0, 4.0);
           Vector<double, double> vector2(6.0, 8.0);

            Vector<double, double> result_t0 = Vector<double, double>::lerpVector(vector1, vector2, 0.0);
            Vector<double, double> result_t05 = Vector<double, double>::lerpVector(vector1, vector2, 0.5);
            Vector<double, double> result_t1 = Vector<double, double>::lerpVector(vector1, vector2, 1.0);

            
            Assert::AreEqual(result_t0.getX(), 3.0);
           Assert::AreEqual(result_t0.getY(), 4.0);

           Assert::AreEqual(result_t05.getX(), 4.5);
           Assert::AreEqual(result_t05.getY(), 6.0);

            Assert::AreEqual(result_t1.getX(), 6.0);
            Assert::AreEqual(result_t1.getY(), 8.0);
        }
        TEST_METHOD(TestLerpClampedVector)
        {
            Vector<double, double> vector1(3.0, 4.0);
            Vector<double, double> vector2(6.0, 8.0);

            Vector<double, double> result_tNeg1 = Vector<double, double>::lerpClampedVector(vector1, vector2, -1.0);
            Vector<double, double> result_t0 = Vector<double, double>::lerpClampedVector(vector1, vector2, 0.0);
            Vector<double, double> result_t05 = Vector<double, double>::lerpClampedVector(vector1, vector2, 0.5);
            Vector<double, double> result_t1 = Vector<double, double>::lerpClampedVector(vector1, vector2, 1.0);
            Vector<double, double> result_t2 = Vector<double, double>::lerpClampedVector(vector1, vector2, 2.0);

            Assert::AreEqual(result_tNeg1.getX(), 3.0);
            Assert::AreEqual(result_tNeg1.getY(), 4.0);

            Assert::AreEqual(result_t0.getX(), 3.0);
            Assert::AreEqual(result_t0.getY(), 4.0);

            Assert::AreEqual(result_t05.getX(), 4.5);
            Assert::AreEqual(result_t05.getY(), 6.0);

            Assert::AreEqual(result_t1.getX(), 6.0);
            Assert::AreEqual(result_t1.getY(), 8.0);

            Assert::AreEqual(result_t2.getX(), 6.0);
            Assert::AreEqual(result_t2.getY(), 8.0);
        }
        TEST_METHOD(TestAngleVector)
        {
            Vector<double, double> vector1(1.0, 0.0);  
            Vector<double, double> vector2(0.0, 1.0);  

            double result = Vector<double, double>::angleVector(vector1, vector2);

            Assert::AreEqual(result, 90.0);
        }

        TEST_METHOD(TestSignedAngleVector)
        {
            Vector<double, double> vector1(1.0, 0.0);  
            Vector<double, double> vector2(0.0, 1.0); 

            double result = Vector<double, double>::signedAngleVector(vector1, vector2);

            Assert::AreEqual(result, 1.5708, 0.0001);
        }
        TEST_METHOD(TestClampMagnitude)
        {
            Vector<double, double> vector(3.0, 4.0);

            double maxMagnitude = 5.0;
            Vector<double, double> result = vector.clampMagnitude(vector, maxMagnitude);

            
            double resultMagnitude = result.magnitude();

            if (resultMagnitude <= maxMagnitude)
            {
                Assert::AreEqual(result.getX(), 3.0);
                Assert::AreEqual(result.getY(), 4.0);
            }
            else
            {
                double scaleFactor = maxMagnitude / resultMagnitude;
                Assert::AreEqual(result.getX(), 3.0 );
                Assert::AreEqual(result.getY(), 4.0 );
            }
        }
        TEST_METHOD(TestScaleVector)
        {
            Vector<double, double> vector(3.0, 4.0);

            double scale = 2.0;
            Vector<double, double> result = Vector<double, double>::scaleVector(vector, scale);

            Assert::AreEqual(result.getX(), 6.0);
            Assert::AreEqual(result.getY(), 8.0);
        }
        TEST_METHOD(TestDistanceVector)
        {
            Vector<double, double> vector1(1.0, 2.0);
            Vector<double, double> vector2(4.0, 6.0);

            double result = Vector<double, double>::distanceVector(vector1, vector2);

            
            Assert::AreEqual(result, 5.0);
        }




    };



}