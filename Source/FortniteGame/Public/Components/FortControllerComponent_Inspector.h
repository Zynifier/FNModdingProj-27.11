// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortControllerComponent.h"
#include "FortControllerComponent_Inspector.generated.h"

USTRUCT()
struct FInspectorScreenshotContext
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float DelaySeconds;

	UPROPERTY()
	float FOVAngle;

	UPROPERTY()
	uint32 ResX;

	UPROPERTY()
	uint32 ResY;

	UPROPERTY()
	uint32 SampleMultiplier;

	UPROPERTY()
	FString ResponseUri;

};

UCLASS(Config=Game, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_Inspector : public UFortControllerComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(Client, Reliable)
	void ClientBeginRequestScreenshot(FInspectorScreenshotContext InScreenshotContext);

	UFUNCTION(Client, Reliable)
	void ClientEndRequestScreenshot();

};

