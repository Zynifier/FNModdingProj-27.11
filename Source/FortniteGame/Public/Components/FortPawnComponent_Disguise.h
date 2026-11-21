// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Components/FortPawnComponent.h"
#include "FortPawnComponent_Disguise.generated.h"

class AActor;
class AController;
class UFortAthenaAIRuntimeParameters_AIBotDisguise;
class UFortAthenaAIRuntimeParameters_NPCBehavior;
class UFortGameStateComponent_AffiliationManager;
class UPrimitiveComponent;
enum class EFortPawnComponent_DisguiseRevealReason : uint8;

UENUM(BlueprintType)
enum class EFortPawnComponent_DisguiseRevealReason : uint8
{
	ByDamage = 0,
	ByConversation = 1,
	ByProximity = 2,
	Unknown = 3,
};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UFortPawnComponent_Disguise : public UFortPawnComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool CanBeRevealed() const;

	UFUNCTION(BlueprintCallable)
	void RevealDisguise(const AActor* RevealInstigator = nullptr, EFortPawnComponent_DisguiseRevealReason RevealReason = EFortPawnComponent_DisguiseRevealReason::Unknown);

private:
	UFUNCTION()
	void OnOwnerPawnDamaged(AActor* DamageOnOwnerPawnDamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIRuntimeParameters_AIBotDisguise> CachedAIDisguiseParameters;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIRuntimeParameters_NPCBehavior> CachedNPCBehaviorParameters;

	UPROPERTY(Transient)
	float PlayerDetectedTimestamp;

	UPROPERTY(Transient)
	float RevealPlayerProximityDuration;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortGameStateComponent_AffiliationManager> AffiliationManager;

};

