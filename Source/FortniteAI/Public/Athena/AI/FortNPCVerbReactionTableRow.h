// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "InstancedStruct.h"
#include "FortNPCVerbReactionTableRow.generated.h"

class UAthenaDanceItemDefinition;
class UGameplayEffect;

USTRUCT(BlueprintType)
struct FORTNITEAI_API FFortNPCVerbReactionTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Reaction Entry", meta=(BaseStruct="/Script/FortniteGame.ObjectiveFilter", ExcludeBaseStruct))
	TArray<FInstancedStruct> VerbFilters;

	UPROPERTY(EditAnywhere, Category="Reaction Entry")
	TObjectPtr<UAthenaDanceItemDefinition> EmoteReaction;

	UPROPERTY(EditAnywhere, Category="Reaction Entry")
	TSubclassOf<UGameplayEffect> GameplayEffectReaction;

	UPROPERTY(EditAnywhere, Category="Reaction Entry")
	FGameplayTagQuery ConditionalQuery;

	UPROPERTY(EditAnywhere, Category="Reaction Entry")
	bool bOncePerWorld;

};

