// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayCueNotify_Actor.h"
#include "GameplayTagContainer.h"
#include "Abilities/FortGameplayCueTypes.h"
#include "FortGameplayCueNotify_Actor.generated.h"

class AActor;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Tick", "Rendering", "Input", "Actor", "Replication"))
class AFortGameplayCueNotify_Actor : public AGameplayCueNotify_Actor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Defaults")
	FFortGameplayCueSpawnCondition DefaultCondition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Defaults")
	FFortGameplayCueAttachInfo DefaultAttachment;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="HUD")
	FGameplayTagContainer HUDElementTag;

	UPROPERTY(BlueprintReadOnly, Category="FortGameplayCueNotify_Actor")
	TObjectPtr<AActor> ExecutionTarget;

};

