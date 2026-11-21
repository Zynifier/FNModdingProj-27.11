// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Movement/FortMovementComp_Character.h"
#include "Weapons/FortWeaponRangedDual.h"
#include "FortWeaponRangedDualSwing.generated.h"

class AActor;
class UStaticMeshComponent;

UCLASS(MinimalAPI, HideCategories=("Actor", "Input", "Components|Clothing", "Components|Base", "Components|PhysicsVolume", "Components|Activation", "Collision", "Replication", "Rendering", "Tags"))
class AFortWeaponRangedDualSwing : public AFortWeaponRangedDual
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Rope")
	void AttachRope(AActor* AttachPointActor);

	UFUNCTION(BlueprintCallable, Category="Rope")
	void DetachRope();

	UFUNCTION(BlueprintPure, Category="Rope")
	FVector GetRopeAttachSocketLocation() const;

	UFUNCTION(BlueprintCallable, Category="Swinging Control Params")
	bool SetActiveOverrideSwingingControlParams(const FGameplayTag ControlParamsTag);

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Hit Check")
	void OnPlayerHitWallWhileSwinging();

	UFUNCTION(BlueprintImplementableEvent, Category="Hit Check")
	void OnPlayerHitWhileSwinging(const FHitResult& Hit);

	UFUNCTION(BlueprintImplementableEvent, Category="Hit Check")
	void OnPlayerStartSkidding();

	UFUNCTION(BlueprintImplementableEvent, Category="Hit Check")
	void OnPlayerTouchedGroundAfterSwingEnded();

	UFUNCTION()
	void OnRep_RopeAttachPointActor();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="Rope")
	void OnRopeAttached();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="Rope")
	void OnRopeFadeOutComplete();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="Rope")
	void OnRopeStartFadeOut();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="Rope")
	void OnRopeUpdated(const FVector RopeDirection, const float RopeLength);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Swinging Control Override")
	TMap<FGameplayTag, FSwingingControlParams> OverrideSwingingControlParams;

	UPROPERTY(EditDefaultsOnly, Category="Swinging Control Override")
	FGameplayTag InitialOverrideSwingingControlParamsTag;

	UPROPERTY(EditDefaultsOnly, Category="Reticle")
	bool bAlwaysUseDefaultReticleColor;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_RopeAttachPointActor, Category="Rope")
	TObjectPtr<AActor> RopeAttachPointActor;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Rope", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> RopeAnchor;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Rope", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> Rope;

	UPROPERTY(EditDefaultsOnly, Category="Rope")
	FName SwingSocketName;

	UPROPERTY(EditDefaultsOnly, Category="Rope")
	float RopeMeshLengthMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="Rope")
	float RopeUpdateFrequency;

	UPROPERTY(EditDefaultsOnly, Category="Rope")
	float RopeFadeTime;

	UPROPERTY(EditDefaultsOnly, Category="Hit Check")
	FScalableFloat HitCheckFrequency;

	UPROPERTY(EditDefaultsOnly, Category="Hit Check")
	float MaximumHeightToStartSkidding;

	UPROPERTY(EditDefaultsOnly, Category="Hit Check")
	FGameplayTag SkiddingTag;

	UPROPERTY(EditDefaultsOnly, Category="Hit Check")
	float MaximumSwingHitWallAngle;

	UPROPERTY(EditDefaultsOnly, Category="Hit Check")
	float MinimumSwingHitGroundAngle;

private:
	UFUNCTION()
	void OnPlayerHit(AActor* HitPlayer, AActor* HitActor, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION()
	void UpdateRope();

};

