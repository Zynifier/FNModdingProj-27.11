// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "InstancedStruct.h"
#include "FortEventTypes.generated.h"

class UFortQuestItemDefinition;

USTRUCT(BlueprintType, meta=(Hidden))
struct FFortEventConditionalBase
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType, meta=(DisplayName="Quest"))
struct FFortEventConditional_Quest : public FFortEventConditionalBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortEventConditional_Quest")
	TSoftObjectPtr<UFortQuestItemDefinition> Quest;

};

USTRUCT(BlueprintType, meta=(DisplayName="Verbs"))
struct FFortEventConditional_Verb : public FFortEventConditionalBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortEventConditional_Verb", meta=(BaseStruct="/Script/FortniteGame.ObjectiveFilter", ExcludeBaseStruct))
	TArray<FInstancedStruct> VerbFilters;

};

USTRUCT(BlueprintType, meta=(Hidden))
struct FFortEventReactionBase
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType, meta=(DisplayName="World State Tag"))
struct FFortEventReaction_WorldStateTag : public FFortEventReactionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortEventReaction_WorldStateTag", meta=(Categories="WorldState"))
	FGameplayTag TagToApply;

};

