// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAIRuntimeParametersComponent.h"
#include "Athena/AI/FortAthenaAISpawnerDataComponent.h"
#include "FortAthenaAISpawnerDataComponent_AffiliationBase.generated.h"

class UBlackboardData;

USTRUCT()
struct FSpawnerDataComponentAffiliationSharedBBConfiguration
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="SpawnerDataComponentAffiliationSharedBBConfiguration")
	FGameplayTag FactionTag;

	UPROPERTY(EditAnywhere, Category="SpawnerDataComponentAffiliationSharedBBConfiguration")
	FScalableFloat MaximumDistance;

	UPROPERTY(EditAnywhere, Category="SpawnerDataComponentAffiliationSharedBBConfiguration")
	FGameplayTag SharedBlackboardTag;

	UPROPERTY(EditAnywhere, Category="SpawnerDataComponentAffiliationSharedBBConfiguration")
	TObjectPtr<UBlackboardData> SharedBlackboard;

};

UCLASS(MinimalAPI)
class UFortAthenaAIRuntimeParameters_AffiliationBase : public UFortAthenaAIRuntimeParameters
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	uint8 bFullTeamAwarenessPropagation : 1;

	UPROPERTY(Transient)
	uint8 bAwarenessPropagationIsBasedOnAlertLevel : 1;

	UPROPERTY(Transient)
	uint8 bTurnHostileOnDamageIfNeutral : 1;

	UPROPERTY(Transient)
	float TurnHostileWhenBlockedTime;

	UPROPERTY(Transient)
	uint8 bPropagateHostilityOnDamaged : 1;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortAthenaAISpawnerDataComponent_AffiliationBase : public UFortAthenaAISpawnerDataComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool GetAwarenessPropagationIsBasedOnAlertLevel() const;

	UFUNCTION(BlueprintCallable)
	FGameplayTagContainer GetFactionTag();

	UFUNCTION(BlueprintPure)
	float GetFullTeamAwarenessMaxDistance() const;

	UFUNCTION(BlueprintPure)
	bool GetFullTeamAwarenessPropagation() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintPure)
	bool GetTeamID(int32& OutTeamId) const;

	UFUNCTION(BlueprintCallable)
	void SetAwarenessPropagationIsBasedOnAlertLevel(const bool bInAwarenessPropagationIsBasedOnAlertLevel);

	UFUNCTION(BlueprintCallable)
	void SetFactionTags(const FGameplayTagContainer& NewTags);

	UFUNCTION(BlueprintCallable)
	void SetFullTeamAwarenessPropagation(const bool bInFullTeamAwarenessPropagation);

	UFUNCTION(BlueprintCallable)
	void SetFullTeamAwarenessPropagationDistance(const float InFullTeamAwarenessMaxDistance);

	UFUNCTION(BlueprintCallable)
	void SetOverrideTeamIndex(const int32 InOverrideTeamIdx);

private:
	UPROPERTY(EditAnywhere, Category="Faction", meta=(AllowPrivateAccess="true", Categories="Athena.Faction"))
	FGameplayTagContainer FactionTags;

	UPROPERTY(EditAnywhere, Category="Faction", meta=(AllowPrivateAccess="true"))
	FScalableFloat TurnHostileOnDamageIfNeutral;

	UPROPERTY(EditAnywhere, Category="Faction", meta=(AllowPrivateAccess="true"))
	FScalableFloat TurnHostileWhenBlockedTime;

	UPROPERTY(EditAnywhere, Category="Faction", meta=(AllowPrivateAccess="true"))
	FScalableFloat PropagateHostilityOnDamaged;

	UPROPERTY(EditAnywhere, Category="Faction", meta=(AllowPrivateAccess="true"))
	TArray<FSpawnerDataComponentAffiliationSharedBBConfiguration> FactionSharedBBConfigurations;

	UPROPERTY(EditAnywhere, Category="Awareness Propagation", meta=(AllowPrivateAccess="true"))
	uint8 bFullTeamAwarenessPropagation : 1;

	UPROPERTY(EditAnywhere, Category="Awareness Propagation", meta=(AllowPrivateAccess="true"))
	uint8 bAwarenessPropagationIsBasedOnAlertLevel : 1;

	UPROPERTY(EditAnywhere, Category="Awareness Propagation", meta=(AllowPrivateAccess="true", EditCondition="bFullTeamAwarenessPropagation"))
	float FullTeamAwarenessMaxDistance;

	UPROPERTY(EditAnywhere, Category="Awareness Propagation", meta=(AllowPrivateAccess="true"))
	bool bAddGameParticipantFactionAutomatically;

	UPROPERTY(EditAnywhere, Category="Team", meta=(AllowPrivateAccess="true"))
	int32 OverrideTeamIndex;

};

