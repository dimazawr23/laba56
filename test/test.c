#include <ctest.h>
#include "discriminant.h"
#include "computering_roots.h"

CTEST(test_suite, negative_discriminant)
{
	const double a = 4;
	const double b = 2;
	const double c = 3;

	double test = discriminant(a, b, c);

	const double expected_discriminant = -44;

	ASSERT_DBL_NEAR(expected_discriminant, test);
}

CTEST(test_suite, zero_discriminant)
{
	const double a = 3;
	const double b = 6;
	const double c = 3;

	double test = discriminant(a, b, c);

	const double expected_discriminant = 0;

	ASSERT_DBL_NEAR(expected_discriminant, test);
}

CTEST(test_suite, positive_discriminant)
{
	const double a = 4;
	const double b = 6;
	const double c = 1;

	double test = discriminant(a, b, c);

	const double expected_discriminant = 20;

	ASSERT_DBL_NEAR(expected_discriminant, test);
}

CTEST(test_suite, NO_ROOTS)
{
	const double a = 8;
	const double b = 3;
	const double c = 5;
	const double x1, x2;

	double test = computering_roots(a, b, c, &x1, &x2);

	const double expected_root_quantity = 0;

	ASSERT_DBL_NEAR(expected_root_quantity, test);
}

CTEST(test_suite, ONE_ROOTS)
{
	const double a = 2;
	const double b = 8;
	const double c = 8;
	const double x1, x2;

	double test = computering_roots(a, b, c, &x1, &x2);
	const double expected_x1 = -8.00;
	const double expected_x2 = -8.00;

	const double expected_root_quantity = 1;

	ASSERT_DBL_NEAR(expected_root_quantity, test);
	ASSERT_DBL_NEAR(expected_x1, x1);
	ASSERT_DBL_NEAR(expected_x2, x2);
}

CTEST(test_suite, TWO_ROOTS)
{
	const double a = 2;
	const double b = 8;
	const double c = 6;
	const double x1, x2;

	double test = computering_roots(a, b, c, &x1, &x2);
	const double expected_x1 = -3.00;
	const double expected_x2 = -1.00;

	const double expected_root_quantity = 2;

	ASSERT_DBL_NEAR(expected_root_quantity, test);
	ASSERT_DBL_NEAR(expected_x1, x1);
	ASSERT_DBL_NEAR(expected_x2, x2);
}
