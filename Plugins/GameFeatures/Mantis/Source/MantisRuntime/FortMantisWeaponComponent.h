// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortWeaponComponent.h"
#include "FortMantisTypes.h"
#include "FortMantisWeaponComponent.generated.h"

class AFortWeapon;
class UFortMantisData;
class UFortMantisPawnComponent;
enum class EFortWeaponAbilityRemovalReason : uint8;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class MANTISRUNTIME_API UFortMantisWeaponComponent : public UFortWeaponComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Mantis")
	const FFortMantisReplicatedAnimInstanceInfo& GetAnimInstanceInfo() const;

protected:
	UFUNCTION()
	void OnEquip(AFortWeapon* Weapon);

	UFUNCTION()
	void OnPressSecondaryFire(AFortWeapon* Weapon);

	UFUNCTION()
	void OnPressTrigger(AFortWeapon* Weapon);

	UFUNCTION()
	void OnReleaseSecondaryFire(AFortWeapon* Weapon);

	UFUNCTION()
	void OnReleaseTrigger(AFortWeapon* Weapon);

	UFUNCTION()
	void OnRep_ReplayAnimInstanceInfo();

	UFUNCTION()
	void OnUnEquip(AFortWeapon* Weapon);

	UFUNCTION()
	void OnWeaponAbilitiesRemoved(AFortWeapon* Weapon, EFortWeaponAbilityRemovalReason RemovalReason);

	UPROPERTY(EditDefaultsOnly, Category="Mantis")
	TObjectPtr<UFortMantisData> MantisData;

	UPROPERTY(EditDefaultsOnly, Category="Mantis|Input")
	bool bAllowPrimaryFireInputsWhileHolstered;

	UPROPERTY(EditDefaultsOnly, Category="Mantis|Input")
	bool bAllowSecondaryFireInputsWhileHolstered;

	UPROPERTY(Export)
	TWeakObjectPtr<UFortMantisPawnComponent> MantisPawnComponent;

	UPROPERTY(Replicated)
	FFortMantisReplicatedAnimInstanceInfo AnimInstanceInfo;

	UPROPERTY(ReplicatedUsing=OnRep_ReplayAnimInstanceInfo)
	FFortMantisReplicatedAnimInstanceInfo ReplayAnimInstanceInfo;

};

