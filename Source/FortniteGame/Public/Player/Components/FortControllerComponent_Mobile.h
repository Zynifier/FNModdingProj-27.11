// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortControllerComponent.h"
#include "FortControllerComponent_Mobile.generated.h"

class AFortPlayerController;
class UObject;

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_Mobile : public UFortControllerComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Touch Platform")
	static bool IsErebus();

	UFUNCTION(BlueprintPure, Category="Touch Platform")
	static bool IsErebusOrErebusPreview();

	UFUNCTION(BlueprintPure, Category="Touch Platform")
	static bool IsErebusPreview();

	UFUNCTION(BlueprintPure, Category="Touch Platform", meta=(WorldContext="WorldContextObject"))
	static bool IsMobileGame(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="Touch Platform")
	static bool IsTouchInputPlatform();

	UFUNCTION(BlueprintPure, Category="Touch Platform", meta=(WorldContext="WorldContextObject"))
	static bool IsUsingTouch(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="Touch Platform")
	static bool IsUsingTouchControls(AFortPlayerController* PlayerController);

};

