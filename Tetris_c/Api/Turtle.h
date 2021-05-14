#pragma once

#include "Common.h"
#include "Graphics.h"

#undef DrawText
#undef DrawTextEx

namespace Turtle
{
	typedef int TurtleId;
	typedef int OceanId;

	#define TurtleErrorIdBase 1000

	enum TurtleErrorId
	{
		InvalidOceanId = TurtleErrorIdBase,
		InvalidTurtleId,
		InvalidParameter,
		InvalidFloodLevel,
		NoActiveFill,
		CantAddOceanToItself,
		CantAddOceanToItsChildren,
		ChildNotInParent,
		InvalidChildIndex,
	};

	extern "C"
	{
		EXPORT_API OceanId EXPORT_CALL CreateOceanEx(Common::ErrorId *lpErrorId);
		EXPORT_API Common::ErrorId EXPORT_CALL DestroyOceanEx(OceanId ocean);

		EXPORT_API TurtleId EXPORT_CALL CreateTurtleEx(OceanId ocean, Common::ErrorId *lpErrorId);
		EXPORT_API Common::ErrorId EXPORT_CALL DestroyTurtleEx(TurtleId turtle);

		EXPORT_API Common::ErrorId EXPORT_CALL AddOceanToOcean(OceanId parent, OceanId child);
		EXPORT_API Common::ErrorId EXPORT_CALL RemoveOceanFromOcean(OceanId parent, OceanId child);
		EXPORT_API Common::ErrorId EXPORT_CALL InsertOceanInOcean(OceanId parent, int index, OceanId child);
		EXPORT_API int EXPORT_CALL GetChildOceanCount(OceanId parent, Common::ErrorId *lpErrorId);
		EXPORT_API OceanId EXPORT_CALL GetChildOcean(OceanId parent, int index, Common::ErrorId *lpErrorId);
		EXPORT_API OceanId EXPORT_CALL GetParentOcean(OceanId ocean, Common::ErrorId *lpErrorId);

		EXPORT_API Common::ErrorId EXPORT_CALL AssignOceanToControlEx(OceanId ocean, Graphics::ControlId control);
		EXPORT_API Common::ErrorId EXPORT_CALL UnassignOceanFromControlEx(OceanId ocean);

		EXPORT_API Common::ErrorId EXPORT_CALL MoveEx(TurtleId turtle, double distance);
		EXPORT_API Common::ErrorId EXPORT_CALL MoveForwardEx(TurtleId turtle, double distance);
		EXPORT_API Common::ErrorId EXPORT_CALL MoveBackwardEx(TurtleId turtle, double distance);
		EXPORT_API Common::ErrorId EXPORT_CALL TurnEx(TurtleId turtle, double angleDegrees);
		EXPORT_API Common::ErrorId EXPORT_CALL TurnLeftEx(TurtleId turtle, double angleDegrees);
		EXPORT_API Common::ErrorId EXPORT_CALL TurnRightEx(TurtleId turtle, double angleDegrees);
		EXPORT_API Common::ErrorId EXPORT_CALL ArcEx(TurtleId turtle, double radius, double sweepAngleDegrees);
		/*	Common::ErrorId ArcElliptical(TurtleId turtle, double radiusA, double radiusB, double startAngleDegrees, double sweepAngleDegrees);*/
		EXPORT_API Common::ErrorId EXPORT_CALL MoveWithWideTextEx(TurtleId turtle, double size, wchar_t *text);
		EXPORT_API Common::ErrorId EXPORT_CALL MoveWithTextEx(TurtleId turtle, double size, char *text);

		EXPORT_API Common::ErrorId EXPORT_CALL PenUpEx(TurtleId turtle);
		EXPORT_API Common::ErrorId EXPORT_CALL PenDownEx(TurtleId turtle);
		EXPORT_API Common::ErrorId EXPORT_CALL SetPenColorEx(TurtleId turtle, int rgbColor);
		EXPORT_API Common::ErrorId EXPORT_CALL SetPenWidthEx(TurtleId turtle, double width);
		EXPORT_API Common::ErrorId EXPORT_CALL SetBackgroundColorEx(OceanId ocean, int rgbColor);

		EXPORT_API Common::ErrorId EXPORT_CALL SuspendPresentationEx(OceanId ocean);
		EXPORT_API Common::ErrorId EXPORT_CALL ResumePresentationEx(OceanId ocean);
		EXPORT_API Common::ErrorId EXPORT_CALL PresentEx(OceanId ocean);
		EXPORT_API Common::ErrorId EXPORT_CALL ClearEx(OceanId ocean);
		EXPORT_API Common::ErrorId EXPORT_CALL ResetEx(TurtleId turtle);

		EXPORT_API Common::ErrorId EXPORT_CALL JumpToEx(TurtleId turtle, double x, double y);
		EXPORT_API Common::ErrorId EXPORT_CALL SetDirectionEx(TurtleId turtle, double angleDegrees);
		EXPORT_API Common::ErrorId EXPORT_CALL LineToEx(TurtleId turtle, double x, double y);
		EXPORT_API Common::ErrorId EXPORT_CALL DotAtEx(TurtleId turtle, double x, double y);
		EXPORT_API Common::ErrorId EXPORT_CALL LineEx(TurtleId turtle, double x1, double y1, double x2, double y2);
		EXPORT_API Common::ErrorId EXPORT_CALL DrawRectangleEx(TurtleId turtle, double x, double y, double width, double height);
		EXPORT_API Common::ErrorId EXPORT_CALL FillRectangleEx(TurtleId turtle, double x, double y, double width, double height);
		EXPORT_API Common::ErrorId EXPORT_CALL DrawEllipseEx(TurtleId turtle, double x, double y, double width, double height);
		EXPORT_API Common::ErrorId EXPORT_CALL FillEllipseEx(TurtleId turtle, double x, double y, double width, double height);
		EXPORT_API Common::ErrorId EXPORT_CALL DrawEllipseArcEx(TurtleId turtle, double x, double y, double width, double height, double startAngle, double sweepAngle);
		EXPORT_API Common::ErrorId EXPORT_CALL FillEllipseSegmentEx(TurtleId turtle, double x, double y, double width, double height, double startAngle, double sweepAngle);

		EXPORT_API Common::ErrorId EXPORT_CALL StartFillEx(TurtleId turtle);
		EXPORT_API Common::ErrorId EXPORT_CALL CompleteFillEx(TurtleId turtle);

		EXPORT_API Common::ErrorId EXPORT_CALL DrawWideTextEx(TurtleId turtle, double x, double y, double size, wchar_t *text);
		EXPORT_API double EXPORT_CALL CalculateWideTextWidthEx(TurtleId turtle, double size, wchar_t *text, Common::ErrorId * lpError);
		EXPORT_API double EXPORT_CALL CalculateWideTextHeightEx(TurtleId turtle, double size, wchar_t *text, Common::ErrorId * lpError);
		EXPORT_API double EXPORT_CALL CalculateWideTextAscentEx(TurtleId turtle, double size, wchar_t *text, Common::ErrorId * lpError);
		EXPORT_API double EXPORT_CALL CalculateWideTextDescentEx(TurtleId turtle, double size, wchar_t *text, Common::ErrorId * lpError);

		EXPORT_API Common::ErrorId EXPORT_CALL DrawTextEx(TurtleId turtle, double x, double y, double size, char *text);
		EXPORT_API double EXPORT_CALL CalculateTextWidthEx(TurtleId turtle, double size, char *text, Common::ErrorId * lpError);
		EXPORT_API double EXPORT_CALL CalculateTextHeightEx(TurtleId turtle, double size, char *text, Common::ErrorId * lpError);
		EXPORT_API double EXPORT_CALL CalculateTextAscentEx(TurtleId turtle, double size, char *text, Common::ErrorId * lpError);
		EXPORT_API double EXPORT_CALL CalculateTextDescentEx(TurtleId turtle, double size, char *text, Common::ErrorId * lpError);

		EXPORT_API Common::ErrorId EXPORT_CALL ShowTurtleEx(TurtleId turtle);
		EXPORT_API Common::ErrorId EXPORT_CALL HideTurtleEx(TurtleId turtle);

		EXPORT_API Common::ErrorId EXPORT_CALL DrawGridEx(OceanId ocean, double x, double y, double delta, int count, double extraLength);

		EXPORT_API Common::ErrorId EXPORT_CALL SetOceanDisplayCenterEx(OceanId ocean, double x, double y);



		EXPORT_API void EXPORT_CALL InitTurtle();

		EXPORT_API OceanId EXPORT_CALL GetMainOcean();
		EXPORT_API TurtleId EXPORT_CALL GetMainTutle();

		EXPORT_API void EXPORT_CALL Move(double distance);
		EXPORT_API void EXPORT_CALL MoveForward(double distance);
		EXPORT_API void EXPORT_CALL MoveBackward(double distance);
		EXPORT_API void EXPORT_CALL Turn(double angleDegrees);
		EXPORT_API void EXPORT_CALL TurnLeft(double angleDegrees);
		EXPORT_API void EXPORT_CALL TurnRight(double angleDegrees);
		EXPORT_API void EXPORT_CALL Arc(double radius, double sweepAngleDegrees);
		/*	void ArcElliptical(double radiusA, double radiusB, double startAngleDegrees, double sweepAngleDegrees);*/
		EXPORT_API void EXPORT_CALL MoveWithWideText(double size, wchar_t *text);
		EXPORT_API void EXPORT_CALL MoveWithText(double size, char *text);

		EXPORT_API void EXPORT_CALL PenUp();
		EXPORT_API void EXPORT_CALL PenDown();
		EXPORT_API void EXPORT_CALL SetPenColor(int rgbColor);
		EXPORT_API void EXPORT_CALL SetPenWidth(double width);
		EXPORT_API void EXPORT_CALL SetBackgroundColor(int rgbColor);

		EXPORT_API void EXPORT_CALL SuspendPresentation();
		EXPORT_API void EXPORT_CALL ResumePresentation();
		EXPORT_API void EXPORT_CALL Present();
		EXPORT_API void EXPORT_CALL Clear();
		EXPORT_API void EXPORT_CALL Reset();

		EXPORT_API void EXPORT_CALL JumpTo(double x, double y);
		EXPORT_API void EXPORT_CALL SetDirection(double angleDegrees);
		EXPORT_API void EXPORT_CALL LineTo(double x, double y);
		EXPORT_API void EXPORT_CALL DotAt(double x, double y);
		EXPORT_API void EXPORT_CALL Line(double x1, double y1, double x2, double y2);
		EXPORT_API void EXPORT_CALL DrawRectangle(double x, double y, double width, double height);
		EXPORT_API void EXPORT_CALL FillRectangle(double x, double y, double width, double height);
		EXPORT_API void EXPORT_CALL DrawEllipse(double x, double y, double width, double height);
		EXPORT_API void EXPORT_CALL FillEllipse(double x, double y, double width, double height);
		EXPORT_API void EXPORT_CALL DrawEllipseArc(double x, double y, double width, double height, double startAngle, double sweepAngle);
		EXPORT_API void EXPORT_CALL FillEllipseSegment(double x, double y, double width, double height, double startAngle, double sweepAngle);

		EXPORT_API void EXPORT_CALL StartFill();
		EXPORT_API void EXPORT_CALL CompleteFill();

		EXPORT_API void EXPORT_CALL DrawText(double x, double y, double size, char *text);
		EXPORT_API double EXPORT_CALL CalculateTextWidth(double size, char *text);
		EXPORT_API double EXPORT_CALL CalculateTextHeight(double size, char *text);
		EXPORT_API double EXPORT_CALL CalculateTextAscent(double size, char *text);
		EXPORT_API double EXPORT_CALL CalculateTextDescent(double size, char *text);

		EXPORT_API void EXPORT_CALL DrawWideText(double x, double y, double size, wchar_t *text);
		EXPORT_API double EXPORT_CALL CalculateWideTextWidth(double size, wchar_t *text);
		EXPORT_API double EXPORT_CALL CalculateWideTextHeight(double size, wchar_t *text);
		EXPORT_API double EXPORT_CALL CalculateWideTextAscent(double size, wchar_t *text);
		EXPORT_API double EXPORT_CALL CalculateWideTextDescent(double size, wchar_t *text);

		EXPORT_API void EXPORT_CALL ShowTurtle();
		EXPORT_API void EXPORT_CALL HideTurtle();

		EXPORT_API void EXPORT_CALL DrawGrid(double x, double y, double delta, int count, double extraLength);

		EXPORT_API void EXPORT_CALL SetOceanDisplayCenter(double x, double y);
	}
}
