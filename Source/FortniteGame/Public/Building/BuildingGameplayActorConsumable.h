// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectTypes.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Building/BuildingGameplayActor.h"
#include "FortInteractInterface.h"
#include "BuildingGameplayActorConsumable.generated.h"

class AActor;
class AFortPawn;
class UAnimMontage;
class UFortGameplayAbility;
class UFortWorldItemDefinition;
class UGameplayEffect;
class UParticleSystem;
class USoundBase;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class ABuildingGameplayActorConsumable : public ABuildingGameplayActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, Category="Death")
	FTransform GetDeathFXTransform() const;

	UFUNCTION(BlueprintPure, Category="Consumable")
	TSubclassOf<UGameplayEffect> GetOnConsumeGameplayEffect() const;

	UFUNCTION(BlueprintPure, Category="Consumable")
	UAnimMontage* GetOnConsumeMontage() const;

	UFUNCTION(BlueprintPure, Category="Consumable")
	TSubclassOf<UFortGameplayAbility> GetOnConsumeMontageAbility() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Consumable")
	FGameplayEffectSpecHandle MakeOnConsumeGameplayEffectSpec(AActor* EventCauser, const int32 Level);

	UFUNCTION(BlueprintNativeEvent)
	void OnAllowedToConsumeFailed(const AFortPawn* InteractingPawn);

	UFUNCTION(BlueprintImplementableEvent, Category="Interaction")
	void OnGatherOrInteract(const AFortPawn* InteractingPawn, const EInteractionBeingAttempted InteractionBeingAttempted);

	UFUNCTION(BlueprintNativeEvent, Category="Interaction")
	bool OnInteractAllowedToConsume(const AFortPawn* InteractingPawn, const EInteractionBeingAttempted InteractionBeingAttempted);

	UPROPERTY(BlueprintReadWrite, Replicated, Category="BuildingGameplayActorConsumable")
	TObjectPtr<UFortWorldItemDefinition> ItemDefinition;

protected:
	UFUNCTION(BlueprintNativeEvent, Category="Consumable")
	TSubclassOf<UGameplayEffect> DetermineOnConsumeGameplayEffect() const;

	UFUNCTION(BlueprintNativeEvent, Category="Consumable")
	UAnimMontage* DetermineOnConsumeMontage() const;

	UFUNCTION(BlueprintNativeEvent, Category="Consumable")
	TSubclassOf<UFortGameplayAbility> DetermineOnConsumeMontageAbility() const;

	UFUNCTION(BlueprintNativeEvent, Category="Consumable")
	void PrepareOnConsumeGameplayEffectSpec(UPARAM(ref) FGameplayEffectSpecHandle& SpecHandle);

	UPROPERTY(EditDefaultsOnly, Category="Consumable")
	TSubclassOf<UGameplayEffect> OnConsumeGameplayEffect;

	UPROPERTY(EditDefaultsOnly, Category="Consumable")
	TSubclassOf<UFortGameplayAbility> OnConsumeMontageAbility;

	UPROPERTY(EditDefaultsOnly, Category="Consumable")
	TObjectPtr<UAnimMontage> OnConsumeMontage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Consumable")
	bool bSpawnerCalculateRandomRotation;

	UPROPERTY(EditDefaultsOnly, Category="Death")
	TObjectPtr<UParticleSystem> DeathParticles;

	UPROPERTY(EditDefaultsOnly, Category="Death")
	TObjectPtr<USoundBase> DeathSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Max Draw Distance")
	float MaxDrawDistanceStw;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Max Draw Distance")
	float MaxDrawDistanceAthena;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Stats")
	FName StatNameWhenConsumed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Failed Reason")
	FGameplayTagContainer FailedReason;

	UPROPERTY(EditDefaultsOnly, Category="Anim Montage")
	TObjectPtr<UAnimMontage> SearchAnim;

	UPROPERTY(EditDefaultsOnly, Category="Interaction")
	bool bReplicateLongInteractionDetails;

};

