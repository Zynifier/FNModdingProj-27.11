// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameFrameworkComponent.h"
#include "GameplayAbilitySpecHandle.h"
#include "Misc/Guid.h"
#include "Abilities/FortAbilitySetHandle.h"
#include "FortOffhandComponent.generated.h"

class AFortWeapon;

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UFortOffhandComponent : public UGameFrameworkComponent
{
	GENERATED_BODY()

public:
	UFortOffhandComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable)
	AFortWeapon* GetCurrentEquippedOffhandWeapon();

private:
	UFUNCTION(Client, Reliable)
	void ClientEquipOffhandWeapon(AFortWeapon* Weapon);

	UFUNCTION(Client, Reliable)
	void ClientHandleOffhandItemDestroyedDueToDurability(FGuid ItemGuid);

	UFUNCTION(Client, Reliable)
	void ClientUnequipOffhandWeapon();

	UFUNCTION()
	void OnRep_CurrentEquippedOffhandWeapon(AFortWeapon* OldWeapon);

	UPROPERTY(Transient, Replicated)
	FGameplayAbilitySpecHandle OffhandPrimaryAbilitySpecHandle;

	UPROPERTY(Transient, Replicated)
	FFortAbilitySetHandle OffhandEquippedAbilitySet;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_CurrentEquippedOffhandWeapon)
	TObjectPtr<AFortWeapon> CurrentEquippedOffhandWeapon;

};

