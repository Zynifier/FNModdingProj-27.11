// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/FortAbilitySetHandle.h"
#include "Quests/PlayerStateComponent_Quests.h"
#include "FortPlayerStateComponent_Quests.generated.h"

class APawn;
class IQuestInstanceInterface;
class UFortChallengeBundleItem;

USTRUCT()
struct FFortGrantedQuestAbilitySetData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FFortAbilitySetHandle GrantedAbilitySetHandle;

};

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortPlayerStateComponent_Quests : public UPlayerStateComponent_Quests
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<FName> ProgressedObjectives;

protected:
	UFUNCTION()
	void HandlePlayerPossesedPawn(APawn* PlayerPawn);

	UPROPERTY(Transient)
	TArray<TScriptInterface<IQuestInstanceInterface>> GrantedQuests;

	UPROPERTY(Transient)
	TArray<TScriptInterface<IQuestInstanceInterface>> AbandonedQuests;

	UPROPERTY(Transient)
	TArray<TScriptInterface<IQuestInstanceInterface>> CompletedQuests;

	UPROPERTY(Transient)
	TArray<UFortChallengeBundleItem*> CompletedBundles;

	UPROPERTY(Transient)
	TArray<FFortGrantedQuestAbilitySetData> GrantedQuestAbilitySets;

};

