// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortCoreGamerScoreTrackerRow.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCoreGamerScoreTrackerRow : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortCoreGamerScoreTrackerRow(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnRowDataSet(const int32 TeamPlacement, const FText& TeamName, const int32 TeamScore, const bool bIsLocalTeam);

};

