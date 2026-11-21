// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Weapons/FortMountedWeaponInterface.h"
#include "Weapons/FortWeaponRangedDual.h"
#include "FortWeaponRangedDualForVehicle.generated.h"

UCLASS(HideCategories=("Actor", "Input", "Components|Clothing", "Components|Base", "Components|PhysicsVolume", "Components|Activation", "Collision", "Replication", "Rendering", "Tags"))
class AFortWeaponRangedDualForVehicle : public AFortWeaponRangedDual, public IFortMountedWeaponInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="Setup")
	void OnHostVehicleSetup();

protected:
	UFUNCTION()
	void OnRep_MountedWeaponInfoRepped();

	UPROPERTY(EditDefaultsOnly, Category="MountedWeaponInfo")
	FMountedWeaponInfo MountedWeaponInfo;

	UPROPERTY(ReplicatedUsing=OnRep_MountedWeaponInfoRepped)
	FMountedWeaponInfoRepped MountedWeaponInfoRepped;

	UPROPERTY(EditDefaultsOnly, Category="Attach")
	FVector LeftWeaponLoc;

	UPROPERTY(EditDefaultsOnly, Category="Attach")
	FRotator LeftWeaponRot;

	UPROPERTY(EditDefaultsOnly, Category="Attach")
	FVector RightWeaponLoc;

	UPROPERTY(EditDefaultsOnly, Category="Attach")
	FRotator RightWeaponRot;

};

