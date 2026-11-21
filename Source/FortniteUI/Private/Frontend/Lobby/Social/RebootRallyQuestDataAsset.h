// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "RebootRallyQuestDataAsset.generated.h"

UCLASS()
class URebootRallyQuestDataAsset : public UDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Quest Category Tag")
	FGameplayTag QuestCategoryTag;

};

