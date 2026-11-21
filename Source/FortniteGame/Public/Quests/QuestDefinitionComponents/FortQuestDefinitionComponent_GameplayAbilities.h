// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/QuestDefinitionComponents/FortQuestDefinitionComponent.h"
#include "FortQuestDefinitionComponent_GameplayAbilities.generated.h"

class UGameplayAbility;
class UGameplayEffect;

USTRUCT()
struct FGameplayEffectEventData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="GameplayEffectEventData")
	TSoftClassPtr<UGameplayEffect> GameplayEffect;

	UPROPERTY(EditAnywhere, Category="GameplayEffectEventData")
	uint32 EffectLevel;

};

USTRUCT()
struct FObjectiveExtension_AbilitiesAndEffects : public FObjectiveExtensionData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ObjectiveExtension_AbilitiesAndEffects")
	TArray<TSoftClassPtr<UGameplayAbility>> GameplayAbilities;

	UPROPERTY(EditAnywhere, Category="ObjectiveExtension_AbilitiesAndEffects")
	TArray<FGameplayEffectEventData> GameplayEffects;

};

UCLASS(meta=(DisplayName="Gameplay Abilities and Effects Component"))
class UFortQuestDefinitionComponent_GameplayAbilities : public UFortQuestDefinitionComponent
{
	GENERATED_BODY()

};

