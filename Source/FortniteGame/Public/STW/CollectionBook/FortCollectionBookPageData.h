// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FortTypes.h"
#include "FortCollectionBookPageData.generated.h"

USTRUCT()
struct FFortCollectionBookPageData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="FortCollectionBookPageData")
	FText Name;

	UPROPERTY(VisibleAnywhere, Category="FortCollectionBookPageData")
	FName CategoryId;

	UPROPERTY(VisibleAnywhere, Category="FortCollectionBookPageData")
	int32 SortPriority;

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Category="FortCollectionBookPageData")
	FString SectionsString;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Category="Rewards", meta=(DataTableImportOptional))
	FString ItemRewardsText;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Category="Rewards", meta=(DataTableImportOptional))
	bool bIsChoiceReward;
#endif

	UPROPERTY(VisibleAnywhere, Category="FortCollectionBookPageData", meta=(DataTableImportOptional))
	TArray<FName> SectionRowNames;

	UPROPERTY(VisibleAnywhere, Category="Rewards", meta=(DataTableImportOptional))
	FFortRewardInfo Rewards;

private:
	UPROPERTY(VisibleAnywhere, Category="FortCollectionBookPageData")
	FName ProfileId;

};

