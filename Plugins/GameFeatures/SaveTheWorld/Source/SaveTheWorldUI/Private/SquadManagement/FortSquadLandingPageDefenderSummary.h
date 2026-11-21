// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortSquadLandingPageDefenderSummary.generated.h"

USTRUCT(BlueprintType)
struct FFortLandingPageDefenderSummaryInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="SummaryInfo")
	FName SquadId;

	UPROPERTY(BlueprintReadOnly, Category="SummaryInfo")
	FText TheaterDisplayName;

	UPROPERTY(BlueprintReadOnly, Category="SummaryInfo")
	FString TheaterUniqueId;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortSquadLandingPageDefenderSummary : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="DefenderSquadDetails")
	void HandleAddDefenderSquadDetailsBP(FFortLandingPageDefenderSummaryInfo DefenderSummaryInfo);

	UFUNCTION(BlueprintImplementableEvent, Category="DefenderSquadDetails")
	void HandleAddLockedDefenderSquadDetailsBP(FFortLandingPageDefenderSummaryInfo DefenderSummaryInfo);

	UFUNCTION(BlueprintImplementableEvent, Category="DefenderSquadDetails")
	void HandleClearDefenderSquadDetailsBP();

};

