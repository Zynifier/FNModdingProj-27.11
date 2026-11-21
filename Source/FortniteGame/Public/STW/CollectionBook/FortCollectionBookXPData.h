// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FortTypes.h"
#include "FortCollectionBookXPData.generated.h"

USTRUCT()
struct FFortCollectionBookXPData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="XP")
	int32 XpToNextLevel;

	UPROPERTY(VisibleAnywhere, Category="XP")
	int32 TotalXpToGetToThisLevel;

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Category="Rewards", meta=(DataTableImportOptional))
	FString ItemRewardsText;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Category="Rewards")
	bool bIsChoiceReward;
#endif

	UPROPERTY(VisibleAnywhere, Category="Rewards", meta=(DataTableImportOptional))
	FFortRewardInfo Rewards;

	UPROPERTY(VisibleAnywhere, Category="Rewards")
	bool bIsMajorReward;

	UPROPERTY(VisibleAnywhere, Category="Rewards")
	bool bAutoOpenRewardCardPacks;

};

