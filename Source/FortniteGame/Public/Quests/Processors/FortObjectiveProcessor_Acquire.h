// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/PrimaryAssetId.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "FortObjectiveProcessor_Acquire.generated.h"

UENUM()
enum class EAcquireIncrementType : uint8
{
	// update the objective by 1 if the filter passes

	Single = 0,
	// Updates the objective by the size of the biggest item stack that passes the filter

	HighestMatchingItemCount = 1,
	// Updates the objective by the total of all stack sizes that match the filter

	TotalMatchingItemCounts = 2,
	// Updates the objective by the number of unique items that pass the filter

	UniqueMatchingItems = 3,
	// If any item passes the filter, updates the objective by the total of all item stack sizes

	TotalItemCount = 4,
	// If any item passes the filter, updates the objective by the number of unique items acquired in this event.

	UniqueItemCount = 5,
};

USTRUCT(meta=(DisplayName="Acquire"))
struct FFortObjectiveFilter_Acquire : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_Acquire", meta=(DisplayPriority="-1"))
	EAcquireIncrementType IncrementType;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_Acquire", meta=(InlineEditConditionToggle))
	uint8 bUseItemCount : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_Acquire")
	FObjectiveSubjectTags ItemAcquired;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_Acquire", meta=(EditCondition="bUseItemCount", UIMin="0"))
	FInt32Range ItemCount;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_Acquire")
	FObjectiveSubjectTags AcquireSource;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_Acquire")
	bool bGrantProgressForAlreadyAccumulatedItems;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_Acquire", meta=(EditCondition="bGrantProgressForAlreadyAccumulatedItems"))
	TArray<FPrimaryAssetId> ItemTemplates;
#endif

};

UCLASS()
class UFortObjectiveProcessor_Acquire : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

