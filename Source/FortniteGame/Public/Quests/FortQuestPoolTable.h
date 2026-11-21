// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FortQuestPoolTable.generated.h"

USTRUCT()
struct FFortQuestPoolTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortQuestPoolTableRow")
	FString PrerequisiteCompletedQuests;

	UPROPERTY(EditAnywhere, Category="FortQuestPoolTableRow")
	FString PrerequisiteNotCompletedQuests;

	UPROPERTY(EditAnywhere, Category="FortQuestPoolTableRow")
	FString PrerequisiteEventChannel;

	UPROPERTY(EditAnywhere, Category="FortQuestPoolTableRow")
	FString PrerequisiteEventName;

	UPROPERTY(EditAnywhere, Category="FortQuestPoolTableRow")
	int32 RefreshIntervalHours;

	UPROPERTY(EditAnywhere, Category="FortQuestPoolTableRow")
	FString RefreshEvent;

	UPROPERTY(EditAnywhere, Category="FortQuestPoolTableRow")
	FString LootTierGroup;

	UPROPERTY(EditAnywhere, Category="FortQuestPoolTableRow")
	int32 LootTier;

	UPROPERTY(EditAnywhere, Category="FortQuestPoolTableRow")
	int32 RerollLimit;

	UPROPERTY(EditAnywhere, Category="FortQuestPoolTableRow")
	bool bGlobalPull;

	UPROPERTY(EditAnywhere, Category="FortQuestPoolTableRow")
	bool bRollOnActivation;

	UPROPERTY(EditAnywhere, Category="FortQuestPoolTableRow")
	bool bDeleteActiveOnRefresh;

	UPROPERTY(EditAnywhere, Category="FortQuestPoolTableRow")
	int32 MaxActive;

	UPROPERTY(EditAnywhere, Category="FortQuestPoolTableRow")
	int32 DaysToKeepClaimed;

	UPROPERTY(EditAnywhere, Category="FortQuestPoolTableRow")
	int32 DaysToKeepCompleted;

	UPROPERTY(EditAnywhere, Category="FortQuestPoolTableRow")
	int32 MaxUnclaimed;

	UPROPERTY(EditAnywhere, Category="FortQuestPoolTableRow")
	FString LockoutName;

};

