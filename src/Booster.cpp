#include "Booster.h"

void Booster::DrawBooster()
{
}

void Booster::ExpandPlayerVision()
{
}

// A booster that exposes the enemys position and points in the direction
void Booster::ExposeEnemyPosition(Vector2d inPlayerPosition, Vector2d inEnemyPosition)
{
	if (inEnemyPosition.y <= inPlayerPosition.y && inEnemyPosition.y != inPlayerPosition.y) // On top arrow
	{
		Vector2d playerEnemyVector = inPlayerPosition.CalculateDistanceFromTarget({ inPlayerPosition.x , inPlayerPosition.y - 25 });
		Vector2d normalizedPlayerEnemyVector = playerEnemyVector.NormalizeVector();
		Vector2d normalizedPlayerEnemyVectorFullCalculated = { inPlayerPosition.x + normalizedPlayerEnemyVector.x * 25.f ,inPlayerPosition.y + normalizedPlayerEnemyVector.y * 25.f };
		DrawLine(inPlayerPosition.x, inPlayerPosition.y, normalizedPlayerEnemyVectorFullCalculated.x, normalizedPlayerEnemyVectorFullCalculated.y, RED);
		DrawLine(inPlayerPosition.x - 1, inPlayerPosition.y, normalizedPlayerEnemyVectorFullCalculated.x - 1, normalizedPlayerEnemyVectorFullCalculated.y, RED);
		DrawLine(inPlayerPosition.x + 1, inPlayerPosition.y, normalizedPlayerEnemyVectorFullCalculated.x + 1, normalizedPlayerEnemyVectorFullCalculated.y, RED);

		float forhold = sinf(90) / 10; // Finner forholdet som gjelder for hver side av trekanten

		float sideDC = sinf(45) / forhold;

		float sideBD = sqrt((10 * 10) - (sideDC * sideDC));

		Vector2d vectorBD = { normalizedPlayerEnemyVector.x * (-sideBD), normalizedPlayerEnemyVector.x * (-sideBD) };

		Vector2d vectorDC = { -vectorBD.y, vectorBD.x };

		Vector2d normalizedVectorDC = vectorDC.NormalizeVector();

		Vector2d actualVectorDC = { normalizedVectorDC.x * sideDC, normalizedVectorDC.y * sideDC };

		Vector2d sumVectorBDDC = { vectorBD.x + actualVectorDC.x, vectorBD.y + actualVectorDC.y };

		Vector2d pointA = { normalizedPlayerEnemyVectorFullCalculated.x, normalizedPlayerEnemyVectorFullCalculated.y };
		Vector2d pointC = { normalizedPlayerEnemyVectorFullCalculated.x - sumVectorBDDC.x, normalizedPlayerEnemyVectorFullCalculated.y - sumVectorBDDC.y };
		Vector2d pointB = { pointC.x - sideDC*2, pointC.y};

		DrawTriangle({ pointA.x, pointA.y }, { pointB.x, pointB.y }, { pointC.x,pointC.y }, RED);
	}
	else if (inEnemyPosition.y >= inPlayerPosition.y && inEnemyPosition.y != inPlayerPosition.y) // Under arrow
	{
		Vector2d playerEnemyVector = inPlayerPosition.CalculateDistanceFromTarget({ inPlayerPosition.x , inPlayerPosition.y + 25 });
		Vector2d normalizedPlayerEnemyVector = playerEnemyVector.NormalizeVector();
		Vector2d normalizedPlayerEnemyVectorFullCalculated = { inPlayerPosition.x + normalizedPlayerEnemyVector.x * 25.f ,inPlayerPosition.y + normalizedPlayerEnemyVector.y * 25.f };
		DrawLine(inPlayerPosition.x, inPlayerPosition.y, normalizedPlayerEnemyVectorFullCalculated.x, normalizedPlayerEnemyVectorFullCalculated.y, RED);
		DrawLine(inPlayerPosition.x - 1, inPlayerPosition.y, normalizedPlayerEnemyVectorFullCalculated.x - 1, normalizedPlayerEnemyVectorFullCalculated.y, RED);
		DrawLine(inPlayerPosition.x + 1, inPlayerPosition.y, normalizedPlayerEnemyVectorFullCalculated.x + 1, normalizedPlayerEnemyVectorFullCalculated.y, RED);

		float forhold = sinf(90) / 5; // Finner forholdet som gjelder for hver side av trekanten

		float sideDC = sinf(45) / forhold;

		float sideBD = sqrt((5 * 5) - (sideDC * sideDC));

		Vector2d vectorBD = { normalizedPlayerEnemyVector.x * (-sideBD), normalizedPlayerEnemyVector.x * (-sideBD) };

		Vector2d vectorDC = { -vectorBD.y, vectorBD.x };

		Vector2d normalizedVectorDC = vectorDC.NormalizeVector();

		Vector2d actualVectorDC = { normalizedVectorDC.x * sideDC, normalizedVectorDC.y * sideDC };

		Vector2d sumVectorBDDC = { vectorBD.x + actualVectorDC.x, vectorBD.y + actualVectorDC.y };

		DrawLine(normalizedPlayerEnemyVectorFullCalculated.x, normalizedPlayerEnemyVectorFullCalculated.y, normalizedPlayerEnemyVectorFullCalculated.x - sumVectorBDDC.x,
			normalizedPlayerEnemyVectorFullCalculated.y - sumVectorBDDC.y, RED);
	}
	else if (inEnemyPosition.x <= inPlayerPosition.x) // Left arrow, enemy is to the left
	{
		Vector2d playerEnemyVector = inPlayerPosition.CalculateDistanceFromTarget({ inPlayerPosition.x - 25, inPlayerPosition.y });
		Vector2d normalizedPlayerEnemyVector = playerEnemyVector.NormalizeVector();
		Vector2d normalizedPlayerEnemyVectorFullCalculated = { inPlayerPosition.x + normalizedPlayerEnemyVector.x * 25.f ,inPlayerPosition.y + normalizedPlayerEnemyVector.y * 25.f };
		DrawLine(inPlayerPosition.x, inPlayerPosition.y, normalizedPlayerEnemyVectorFullCalculated.x, normalizedPlayerEnemyVectorFullCalculated.y, RED);
		DrawLine(inPlayerPosition.x, inPlayerPosition.y - 1, normalizedPlayerEnemyVectorFullCalculated.x, normalizedPlayerEnemyVectorFullCalculated.y - 1, RED);
		DrawLine(inPlayerPosition.x, inPlayerPosition.y + 1, normalizedPlayerEnemyVectorFullCalculated.x, normalizedPlayerEnemyVectorFullCalculated.y + 1, RED);

		float forhold = sinf(90) / 10; // Finner forholdet som gjelder for hver side av trekanten

		float sideDC = sinf(45) / forhold;

		float sideBD = sqrt((10 * 10) - (sideDC * sideDC));

		Vector2d vectorBD = { normalizedPlayerEnemyVector.x * (-sideBD), normalizedPlayerEnemyVector.x * (-sideBD) };

		Vector2d vectorDC = { -vectorBD.y, vectorBD.x };

		Vector2d normalizedVectorDC = vectorDC.NormalizeVector();

		Vector2d actualVectorDC = { normalizedVectorDC.x * sideDC, normalizedVectorDC.y * sideDC };

		Vector2d sumVectorBDDC = { vectorBD.x + actualVectorDC.x, vectorBD.y + actualVectorDC.y };

		Vector2d pointA = { normalizedPlayerEnemyVectorFullCalculated.x, normalizedPlayerEnemyVectorFullCalculated.y };
		Vector2d pointC = { normalizedPlayerEnemyVectorFullCalculated.x - sumVectorBDDC.x, normalizedPlayerEnemyVectorFullCalculated.y - sumVectorBDDC.y };
		Vector2d pointB = { normalizedPlayerEnemyVectorFullCalculated.x - (vectorBD.x + (-1 * actualVectorDC.x))+15,
			normalizedPlayerEnemyVectorFullCalculated.y - (vectorBD.y + (-1 * actualVectorDC.y))+5 };

		DrawTriangle({ pointA.x, pointA.y }, { pointB.x, pointB.y }, { pointC.x,pointC.y }, RED);
	}
	else if (inEnemyPosition.x > inPlayerPosition.x) // Right arrow
	{
		Vector2d playerEnemyVector = inPlayerPosition.CalculateDistanceFromTarget({ inPlayerPosition.x + 25 , inPlayerPosition.y });
		Vector2d normalizedPlayerEnemyVector = playerEnemyVector.NormalizeVector();
		Vector2d normalizedPlayerEnemyVectorFullCalculated = { inPlayerPosition.x + normalizedPlayerEnemyVector.x * 25.f ,inPlayerPosition.y + normalizedPlayerEnemyVector.y * 25.f };
		DrawLine(inPlayerPosition.x, inPlayerPosition.y, normalizedPlayerEnemyVectorFullCalculated.x, normalizedPlayerEnemyVectorFullCalculated.y, RED);
		DrawLine(inPlayerPosition.x, inPlayerPosition.y - 1, normalizedPlayerEnemyVectorFullCalculated.x, normalizedPlayerEnemyVectorFullCalculated.y - 1, RED);
		DrawLine(inPlayerPosition.x, inPlayerPosition.y + 1, normalizedPlayerEnemyVectorFullCalculated.x, normalizedPlayerEnemyVectorFullCalculated.y + 1, RED);

		float forhold = sinf(90) / 5; // Finner forholdet som gjelder for hver side av trekanten

		float sideDC = sinf(45) / forhold;

		float sideBD = sqrt((5 * 5) - (sideDC * sideDC));

		Vector2d vectorBD = { normalizedPlayerEnemyVector.x * (-sideBD), normalizedPlayerEnemyVector.x * (-sideBD) };

		Vector2d vectorDC = { -vectorBD.y, vectorBD.x };

		Vector2d normalizedVectorDC = vectorDC.NormalizeVector();

		Vector2d actualVectorDC = { normalizedVectorDC.x * sideDC, normalizedVectorDC.y * sideDC };

		Vector2d sumVectorBDDC = { vectorBD.x + actualVectorDC.x, vectorBD.y + actualVectorDC.y };

		Vector2d pointA = { normalizedPlayerEnemyVectorFullCalculated.x, normalizedPlayerEnemyVectorFullCalculated.y };
		Vector2d pointB = { normalizedPlayerEnemyVectorFullCalculated.x - sumVectorBDDC.x, normalizedPlayerEnemyVectorFullCalculated.y - sumVectorBDDC.y };
		Vector2d pointC = { normalizedPlayerEnemyVectorFullCalculated.x - (vectorBD.x + (-1 * actualVectorDC.x)),
			normalizedPlayerEnemyVectorFullCalculated.y - (vectorBD.y + (-1 * actualVectorDC.y)) };

		DrawTriangle({ pointA.x, pointA.y }, { pointB.x, pointB.y }, { pointC.x,pointC.y }, RED);
	}
}