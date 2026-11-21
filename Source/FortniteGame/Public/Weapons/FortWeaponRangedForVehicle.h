// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Weapons/FortMountedWeaponInterface.h"
#include "Weapons/FortWeaponRanged.h"
#include "FortWeaponRangedForVehicle.generated.h"

class USkeletalMeshComponent;

UCLASS(HideCategories=("Actor", "Input", "Components|Clothing", "Components|Base", "Components|PhysicsVolume", "Components|Activation", "Collision", "Replication", "Rendering", "Tags"))
class AFortWeaponRangedForVehicle : public AFortWeaponRanged, public IFortMountedWeaponInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="Setup")
	void OnHostVehicleSetup();

protected:
	UFUNCTION()
	void OnRep_MountedWeaponInfoRepped();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="MountedWeaponInfo", meta=(EditInline="true"))
	TObjectPtr<USkeletalMeshComponent> CachedWeaponMeshCompOnVehicle;

	UPROPERTY(EditDefaultsOnly, Category="Attach")
	FVector WeaponLoc;

	UPROPERTY(EditDefaultsOnly, Category="Attach")
	FRotator WeaponRot;

	UPROPERTY(EditDefaultsOnly, Category="MountedWeaponInfo")
	FMountedWeaponInfo MountedWeaponInfo;

	UPROPERTY(ReplicatedUsing=OnRep_MountedWeaponInfoRepped)
	FMountedWeaponInfoRepped MountedWeaponInfoRepped;

};

