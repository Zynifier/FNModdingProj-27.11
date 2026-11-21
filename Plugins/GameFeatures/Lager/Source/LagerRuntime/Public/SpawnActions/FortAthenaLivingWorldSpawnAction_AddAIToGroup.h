// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "FortAthenaLivingWorldSpawnAction.h"
#include "FortAthenaLivingWorldSpawnAction_AddAIToGroup.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaLivingWorldSpawnAction_AddAIToGroup : public UFortAthenaLivingWorldSpawnAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Group AI", meta=(AllowPrivateAccess="true"))
	FGameplayTagContainer GroupTags;

};

