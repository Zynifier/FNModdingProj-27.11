// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAIRuntimeParametersComponent.h"
#include "Athena/AI/FortAthenaAISpawnerDataComponent_AffiliationBase.h"
#include "FortItemAndCount.h"
#include "FortAthenaAISpawnerDataComponent_AIBotAffiliation.generated.h"

class UFortBotNameSettings;
class UFortNPCConversationParticipantComponent;
class UGameplayEffect;

UCLASS(MinimalAPI)
class UFortAthenaAIRuntimeParameters_AIBotDisguise : public UFortAthenaAIRuntimeParameters
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	bool bShouldApplyDisguise;

	UPROPERTY(Transient)
	bool bRevealDisguiseOnDamage;

	UPROPERTY(Transient)
	bool bRevealOnDamageExcludeAIPawnDamage;

	UPROPERTY(Transient)
	bool bRevealDisguiseOnPlayerProximity;

	UPROPERTY(Transient)
	float RevealPlayerProximityDistanceSqr;

	UPROPERTY(Transient)
	float RevealPlayerProximityMinDuration;

	UPROPERTY(Transient)
	float RevealPlayerProximityMaxDuration;

	UPROPERTY(Transient)
	TObjectPtr<UFortBotNameSettings> NameSettingsAfterReveal;

	UPROPERTY(Transient)
	FGameplayTagContainer DisguisedFactionsBeforeReveal;

	UPROPERTY(Transient)
	FGameplayTagContainer DisguisedFactionsAfterReveal;

	UPROPERTY(Transient)
	TArray<TSubclassOf<UGameplayEffect>> DisguiseGameplayEffectBeforeReveal;

	UPROPERTY(Transient)
	TArray<TSubclassOf<UGameplayEffect>> DisguiseGameplayEffectAfterReveal;

	UPROPERTY(Transient)
	TArray<FItemAndCount> DisguiseInventory;

	UPROPERTY(Transient)
	FDataTableRowHandle DisguiseLootInfo;

	UPROPERTY(Transient)
	TSubclassOf<UFortNPCConversationParticipantComponent> DisguiseConversationComponentOverride;

};

UCLASS()
class UFortAthenaAIRuntimeParameters_Collection : public UFortAthenaAIRuntimeParameters
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	bool bForceAddToCollectionOnDamage;

};

UCLASS()
class UFortAthenaAIRuntimeParameters_Marker : public UFortAthenaAIRuntimeParameters
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	uint8 bSupportsMarkerWithFaction : 1;

	UPROPERTY(Transient)
	float MarkerPropagationMaxDistanceSQ;

};

UCLASS(BlueprintType, Blueprintable)
class FORTNITEAI_API UFortAthenaAISpawnerDataComponent_AIBotAffiliation : public UFortAthenaAISpawnerDataComponent_AffiliationBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintPure)
	bool GetSquadID(int32& OutSquadId) const;

private:
	UPROPERTY(EditAnywhere, Category="CollectionBook", meta=(AllowPrivateAccess="true"))
	bool bForceAddToCollectionOnDamage;

	UPROPERTY(EditAnywhere, Category="AIBot", meta=(AllowPrivateAccess="true"))
	uint8 bOverrideIsAnAthenaGameParticipant : 1;

	UPROPERTY(EditAnywhere, Category="AIBot", meta=(AllowPrivateAccess="true", EditCondition="bOverrideIsAnAthenaGameParticipant"))
	uint8 bIsAnAthenaGameParticipant : 1;

	UPROPERTY(EditAnywhere, Category="Marker", meta=(AllowPrivateAccess="true"))
	FScalableFloat SupportsMarkerWithFaction;

	UPROPERTY(EditAnywhere, Category="Marker", meta=(AllowPrivateAccess="true"))
	FScalableFloat MarkerPropagationMaxDistance;

	UPROPERTY(EditAnywhere, Category="Disguise", meta=(AllowPrivateAccess="true"))
	FScalableFloat DisguiseProbability;

	UPROPERTY(EditAnywhere, Category="Disguise", meta=(AllowPrivateAccess="true"))
	FScalableFloat RevealDisguiseOnDamage;

	UPROPERTY(EditAnywhere, Category="Disguise", meta=(AllowPrivateAccess="true"))
	FScalableFloat RevealOnDamageExcludeAIPawnDamage;

	UPROPERTY(EditAnywhere, Category="Disguise", meta=(AllowPrivateAccess="true"))
	FScalableFloat RevealDisguiseOnPlayerProximity;

	UPROPERTY(EditAnywhere, Category="Disguise", meta=(AllowPrivateAccess="true"))
	FScalableFloat RevealPlayerProximityDistance;

	UPROPERTY(EditAnywhere, Category="Disguise", meta=(AllowPrivateAccess="true"))
	FScalableFloat RevealPlayerProximityMinDuration;

	UPROPERTY(EditAnywhere, Category="Disguise", meta=(AllowPrivateAccess="true"))
	FScalableFloat RevealPlayerProximityMaxDuration;

	UPROPERTY(EditAnywhere, Instanced, Category="Disguise", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UFortBotNameSettings> NameSettingsAfterReveal;

	UPROPERTY(EditAnywhere, Category="Disguise", meta=(AllowPrivateAccess="true"))
	FGameplayTagContainer DisguisedFactionsBeforeReveal;

	UPROPERTY(EditAnywhere, Category="Disguise", meta=(AllowPrivateAccess="true"))
	FGameplayTagContainer DisguisedFactionsAfterReveal;

	UPROPERTY(EditAnywhere, Category="Disguise", meta=(AllowPrivateAccess="true"))
	TArray<TSubclassOf<UGameplayEffect>> DisguiseGameplayEffectBeforeReveal;

	UPROPERTY(EditAnywhere, Category="Disguise", meta=(AllowPrivateAccess="true"))
	TArray<TSubclassOf<UGameplayEffect>> DisguiseGameplayEffectAfterReveal;

	UPROPERTY(EditDefaultsOnly, Category="Disguise", meta=(AllowPrivateAccess="true"))
	TArray<FItemAndCount> DisguiseInventory;

	UPROPERTY(EditAnywhere, Category="Disguise", meta=(AllowPrivateAccess="true"))
	FDataTableRowHandle DisguiseLootInfo;

	UPROPERTY(EditDefaultsOnly, Category="Disguise", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortNPCConversationParticipantComponent> DisguiseConversationComponent;

};

