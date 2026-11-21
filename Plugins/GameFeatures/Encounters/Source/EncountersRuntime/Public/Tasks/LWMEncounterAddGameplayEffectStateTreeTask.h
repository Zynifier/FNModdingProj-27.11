// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "StateTreeTaskBase.h"
#include "LWMEncounterAddGameplayEffectStateTreeTask.generated.h"

class AActor;
class UGameplayEffect;

USTRUCT(meta=(Category="Encounter", DisplayName="LWM Encounter [Add Gameplay Effect]"))
struct FLWMEncounterAddGameplayEffectStateTreeTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

};

USTRUCT()
struct FLWMEncounterAddGameplayEffectStateTreeTaskInstanceData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Parameter")
	FGameplayTagQuery EncounterQuery;

	UPROPERTY(EditAnywhere, Category="Parameter")
	TSubclassOf<UGameplayEffect> GameplayEffect;

	UPROPERTY(EditAnywhere, Category="Parameter")
	bool bRemoveEffectOnExit;

	UPROPERTY(EditAnywhere, Category="Parameter")
	FGameplayTagContainer IdentifierTags;

	UPROPERTY(EditAnywhere, Category="Context")
	TObjectPtr<AActor> UserActor;

};

