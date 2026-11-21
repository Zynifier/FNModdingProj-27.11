// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Components/FortWeaponComponent.h"
#include "FortWeaponComponent_TargetModeSelector.generated.h"

class UInputComponent;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTargetModeChangedDelegate, int32, TargetMode);

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UFortWeaponComponent_TargetModeSelector : public UFortWeaponComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(Server, Reliable, BlueprintCallable)
	void ServerSetTargetMode(int32 NewTargetMode);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, ReplicatedUsing=OnRep_TargetMode, Category="FortWeaponComponent_TargetModeSelector")
	int32 TargetMode;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortWeaponComponent_TargetModeSelector")
	int32 TargetModeCount;

	UPROPERTY(EditDefaultsOnly, Category="FortWeaponComponent_TargetModeSelector")
	FScalableFloat ToggleButtonPressCooldown;

	UPROPERTY(EditDefaultsOnly, Category="FortWeaponComponent_TargetModeSelector")
	FScalableFloat TargetModeInputPriority;

	UPROPERTY(BlueprintAssignable)
	FOnTargetModeChangedDelegate OnTargetModeChanged;

private:
	UFUNCTION()
	void OnRep_TargetMode();

	UFUNCTION()
	void OnSetTargeting(bool bNewIsTargeting);

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> TargetModeInputComponent;

};

