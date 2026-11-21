// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Building/BuildingProp.h"
#include "BuildingPropAtlas.generated.h"

class UAudioComponent;
class UMaterialInstanceDynamic;
class UPrimitiveComponent;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingPropActorClassData)
class ABuildingPropAtlas : public ABuildingProp
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Building|ATLAS")
	float GetDefenseAnimSpeed() const;

	UFUNCTION(BlueprintPure, Category="Building|ATLAS")
	float GetDefenseProgress() const;

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Building|ATLAS")
	void InitializeAudio(UAudioComponent* InPortalLoopingComp);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Building|ATLAS")
	void InitializeRings(UPrimitiveComponent* InRing1Comp, UPrimitiveComponent* InRing2Comp, UPrimitiveComponent* InRing3Comp);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="Building|ATLAS")
	void OnRingSpinningLoop();

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Building|ATLAS")
	void PlayRingDamage(float DurationMin, float DurationMax, float MagnitudeMin, float MagnitudeMax);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Building|ATLAS")
	void PlayRingsIdleLoop(float AnimDuration, float Ring1ZOffset);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Building|ATLAS")
	void PlayRingSpinning(const FRotator& Ring1RateMin, const FRotator& Ring1RateMax, const FRotator& Ring2Rate, const FRotator& Ring3Rate);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Building|ATLAS")
	void PlayRingsReset(float AnimDuration);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Building|ATLAS")
	void RestoreRingsHierarchy();

	UFUNCTION(BlueprintCallable, Category="Building|ATLAS")
	void SetupAnimationSpeed(float InActivationTime, float InTotalDefenseTime, float InAnimSpeedStart, float InAnimSpeedEnd);

	UFUNCTION(BlueprintCallable, Category="Building|ATLAS")
	void SetupAnimationTransition(UMaterialInstanceDynamic* MID, FName ParamName, float InTransitionTime);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Building|ATLAS")
	void StopRingSpinning();

protected:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UPrimitiveComponent> Ring1Comp;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UPrimitiveComponent> Ring2Comp;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UPrimitiveComponent> Ring3Comp;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> RingTransitionMID;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> PortalAudioComp;

};

