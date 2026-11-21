// Copyright Epic Games, Inc. All Rights Reserved.

#include "Player/Components/FortControllerComponent_Mobile.h"

bool UFortControllerComponent_Mobile::IsErebus()
{
	return false;
}

bool UFortControllerComponent_Mobile::IsErebusOrErebusPreview()
{
	return false;
}

bool UFortControllerComponent_Mobile::IsErebusPreview()
{
	return false;
}

bool UFortControllerComponent_Mobile::IsMobileGame(const UObject* WorldContextObject)
{
	return false;
}

bool UFortControllerComponent_Mobile::IsTouchInputPlatform()
{
	return false;
}

bool UFortControllerComponent_Mobile::IsUsingTouch(const UObject* WorldContextObject)
{
	return false;
}

bool UFortControllerComponent_Mobile::IsUsingTouchControls(AFortPlayerController* PlayerController)
{
	return false;
}
