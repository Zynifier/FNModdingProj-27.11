// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Styling/SlateBrush.h"
#include "FortServerBrowserActionData.generated.h"

UENUM(BlueprintType)
enum class EFortServerBrowserAction : uint8
{
	BattleLabServerCreate = 0,
	PlaygroundServerCreate = 1,
	CreativeServerCreate = 2,
	Play = 3,
	CreativeIslandCode = 4,
	CreativeDiscovery = 5,
};

UCLASS(BlueprintType)
class UFortServerBrowserActionData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortServerBrowserActionData")
	EFortServerBrowserAction ActionType;

	UPROPERTY(EditAnywhere, Category="FortServerBrowserActionData")
	FText Title;

	UPROPERTY(EditAnywhere, Category="FortServerBrowserActionData")
	FText Description;

	UPROPERTY(EditAnywhere, Category="FortServerBrowserActionData")
	FSlateBrush TileImage;

};

