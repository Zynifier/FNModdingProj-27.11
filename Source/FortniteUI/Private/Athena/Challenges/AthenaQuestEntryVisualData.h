// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Athena/Challenges/AthenaChallengeListEntry.h"
#include "AthenaQuestEntryVisualData.generated.h"

class UAthenaChallengeListEntryBase;

USTRUCT(BlueprintType)
struct FQuestEntryVisualData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="QuestEntryVisualData")
	TSubclassOf<UAthenaChallengeListEntryBase> EntryClass;

	UPROPERTY(EditDefaultsOnly, Category="QuestEntryVisualData", meta=(ClampMax="100", ClampMin="0"))
	int32 PreallocationCount;

};

UCLASS(BlueprintType)
class UAthenaQuestEntryVisualData : public UDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="AthenaQuestEntryVisualData")
	TMap<EChallengeListEntryType, FQuestEntryVisualData> EntryWidgetData;

};

