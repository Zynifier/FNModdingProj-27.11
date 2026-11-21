// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FortTypes.h"
#include "FortCollectionBookSectionData.generated.h"

USTRUCT()
struct FFortCollectionBookSectionData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="FortCollectionBookSectionData")
	FText Name;

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Category="FortCollectionBookSectionData")
	FString SlotsString;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Category="Rewards", meta=(DataTableImportOptional))
	FString ItemRewardsText;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Category="Rewards", meta=(DataTableImportOptional))
	bool bIsChoiceReward;
#endif

	UPROPERTY(VisibleAnywhere, Category="FortCollectionBookSectionData", meta=(DataTableImportOptional))
	TArray<FName> SlotRowNames;

	UPROPERTY(VisibleAnywhere, Category="Rewards", meta=(DataTableImportOptional))
	FFortRewardInfo Rewards;

};

