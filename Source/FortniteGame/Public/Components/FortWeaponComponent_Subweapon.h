// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/EngineTypes.h"
#include "Math/MathFwd.h"
#include "Components/FortWeaponComponent.h"
#include "FortWeaponComponent_Subweapon.generated.h"

class AFortWeapon;
class UFortSubweaponData;
class UFortWeaponComponent_Subweapon;
class UFortWeaponItemDefinition;

USTRUCT()
struct FFortSubweaponReplicationData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<AFortWeapon> Subweapon;

	UPROPERTY()
	TObjectPtr<UFortSubweaponData> SubweaponData;

};

UCLASS()
class UFortSubweaponData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortSubweaponData")
	TObjectPtr<UFortWeaponItemDefinition> WeaponDefinition;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortSubweaponData")
	FName AttachSocketName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortSubweaponData")
	EAttachmentRule LocationRule;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortSubweaponData")
	EAttachmentRule RotationRule;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortSubweaponData")
	EAttachmentRule ScaleRule;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortSubweaponData")
	FTransform RelativeTransform;

	UPROPERTY(VisibleDefaultsOnly, Category="FortSubweaponData")
	TSubclassOf<UFortWeaponComponent_Subweapon> SubweaponComponentClass;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UFortWeaponComponent_Subweapon : public UFortWeaponComponent
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void HandleAimDownSightsChanged(const bool bIsADS);

private:
	UFUNCTION()
	void OnRep_SubweaponData();

	UPROPERTY(ReplicatedUsing=OnRep_SubweaponData)
	FFortSubweaponReplicationData SubweaponData;

};

