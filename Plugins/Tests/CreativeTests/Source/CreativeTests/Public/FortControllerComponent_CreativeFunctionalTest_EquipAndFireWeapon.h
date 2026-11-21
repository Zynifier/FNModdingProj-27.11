// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortControllerComponent_CreativeFunctionalTest.h"
#include "FortControllerComponent_CreativeFunctionalTest_EquipAndFireWeapon.generated.h"

class AFortPlayerPawn;
class UFortWeaponItemDefinition;
enum class ECreativeFunctionalTest_StopFireReason : uint8;

UENUM(BlueprintType)
enum class ECreativeFunctionalTest_StopFireReason : uint8
{
	TestNoLongerValid = 0,
	PawnNoLongerValid = 1,
	NoInventoryOwner = 2,
	NoWeaponToEquip = 3,
	WrongWeaponEquipped = 4,
	FailedToStartFiring = 5,
	DueToTimeOut = 6,
	DueToAmmoSpent = 7,
};

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_TwoParams(FStoppingFireDelegate, ECreativeFunctionalTest_StopFireReason, StopFireReason, AFortPlayerPawn*, PlayerPawnThatStoppedFiring);

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_CreativeFunctionalTest_EquipAndFireWeapon : public UFortControllerComponent_CreativeFunctionalTest
{
	GENERATED_BODY()

public:
	UFUNCTION(Client, Reliable)
	void ClientStopFiring();

	UFUNCTION(BlueprintCallable, Category="CreativeTest")
	void EquipPawnAndFireWeapon(const UFortWeaponItemDefinition* ItemDefToEquip, FStoppingFireDelegate StoppingFireDelegate, int32 ItemLevel, float TimeUntilStopFire = 5.000000f, int32 MinBulletsToFire = 0);

protected:
	UFUNCTION(Client, Reliable)
	void ClientStartPawnFireWeapon(const UFortWeaponItemDefinition* ItemDefThatShouldBeEquipped, int32 MinAmmoToFire);

	UFUNCTION(Server, Reliable)
	void ServerPawnStartedFiringWeapon();

	UFUNCTION(Server, Reliable)
	void ServerSetStopFireReason(ECreativeFunctionalTest_StopFireReason StopFireReason);

	UPROPERTY()
	TObjectPtr<UFortWeaponItemDefinition> ExpectedWeaponDef;

};

