// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/FortWeaponRanged.h"
#include "FortWeaponRangedDual.generated.h"

class UAnimMontage;
class USkeletalMeshComponentBudgeted;
enum class EDualWeaponHand : uint8;

UENUM(BlueprintType)
enum class EDualWeaponHand : uint8
{
	LEFT = 0,
	RIGHT = 1,
	MAX = 2,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHandFired, EDualWeaponHand, Hand, bool, bPersistantFire);

UCLASS(MinimalAPI, HideCategories=("Actor", "Input", "Components|Clothing", "Components|Base", "Components|PhysicsVolume", "Components|Activation", "Collision", "Replication", "Rendering", "Tags"))
class AFortWeaponRangedDual : public AFortWeaponRanged
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, BlueprintCosmetic, Category="Ranged Weapon Dual")
	EDualWeaponHand GetLastFireHand() const;

	UFUNCTION(BlueprintPure)
	USkeletalMeshComponentBudgeted* GetLeftHandWeaponMesh() const;

	UFUNCTION(BlueprintPure, BlueprintCosmetic, Category="Ranged Weapon Dual")
	EDualWeaponHand GetNextFireHand() const;

	UPROPERTY(VisibleAnywhere, Export, Category="RangedDualWield", meta=(EditInline="true"))
	TObjectPtr<USkeletalMeshComponentBudgeted> LeftHandWeaponMesh;

	UPROPERTY(EditAnywhere, Category="CharacterAnimation")
	TObjectPtr<UAnimMontage> LeftHandFireAnimation;

	UPROPERTY(EditAnywhere, Category="CharacterAnimation")
	TObjectPtr<UAnimMontage> LeftCockingAnimation;

	UPROPERTY(EditAnywhere, Category="CharacterAnimation")
	TObjectPtr<UAnimMontage> LeftHandFireDownsightsAnimation;

	UPROPERTY(EditAnywhere, Category="WeaponAnimation")
	TObjectPtr<UAnimMontage> LeftWeaponFireMontage;

	UPROPERTY(EditAnywhere, Category="WeaponAnimation")
	TObjectPtr<UAnimMontage> LeftWeaponFireDownsightsMontage;

	UPROPERTY(EditAnywhere, Category="WeaponAnimation")
	TObjectPtr<UAnimMontage> LeftWeaponCockingMontage;

	UPROPERTY(EditAnywhere, Category="WeaponAnimation")
	TObjectPtr<UAnimMontage> LeftWeaponReloadMontage;

	UPROPERTY(BlueprintAssignable, Category="Ranged Weapon Dual")
	FOnHandFired OnHandFired;

};

