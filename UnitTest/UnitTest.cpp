#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB_11.3/Main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:

        TEST_METHOD(TestCalculateAverageGrade)
        {
            // Arrange
            Student student;
            student.physics_grade = 80;
            student.math_grade = 90;
            student.additional_grade.programming = 85;
            student.specialization = COMPUTER_SCIENCE;

            // Act
            double averageGrade = CalculateAverageGrade(student);

            // Assert
            Assert::AreEqual(85.0, averageGrade);
        }

        TEST_METHOD(TestPSort)
        {
            // Arrange
            const int N = 3;
            Student students[N] = {
                { "John", 3, COMPUTER_SCIENCE, 80, 90, { 85 } },
                { "Alice", 2, INFORMATICS, 75, 85, { 80 } },
                { "Bob", 4, MATH_ECONOMICS, 85, 95, { 90 } }
            };

            // Act
            p_sort(students, N);

            // Assert
            Assert::AreEqual(std::string("Alice"), students[0].surname);
            Assert::AreEqual(std::string("John"), students[1].surname);
            Assert::AreEqual(std::string("Bob"), students[2].surname);
        }

        TEST_METHOD(TestISort)
        {
            // Arrange
            const int N = 3;
            Student students[N] = {
                { "John", 3, COMPUTER_SCIENCE, 80, 90, { 85 } },
                { "Alice", 2, INFORMATICS, 75, 85, { 80 } },
                { "Bob", 4, MATH_ECONOMICS, 85, 95, { 90 } }
            };

            // Act
            int* indices = i_sort(students, N);

            // Assert
            Assert::AreEqual(std::string("Alice"), students[indices[0]].surname);
            Assert::AreEqual(std::string("John"), students[indices[1]].surname);
            Assert::AreEqual(std::string("Bob"), students[indices[2]].surname);

            delete[] indices;
        }
        TEST_METHOD(TestBSearch)
        {
            // Arrange
            const int N = 3;
            Student students[N] = {
                { "Alice", 2, INFORMATICS, 75, 85, { 80 } },
                { "Bob", 4, MATH_ECONOMICS, 85, 95, { 90 } },
                { "John", 3, COMPUTER_SCIENCE, 80, 90, { 85 } }
            };

            // Act
            bool found = b_search(students, N, "David", 75.0, 80);

            // Assert
            Assert::IsFalse(found);
        }
    };
}
