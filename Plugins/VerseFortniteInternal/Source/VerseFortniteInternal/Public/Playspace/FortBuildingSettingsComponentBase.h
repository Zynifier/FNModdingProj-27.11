// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EntityEnableableComponent.h"
#include "FortBuildingSettingsComponentBase.generated.h"

class AFortAthenaMutator_BuildingSettings;

UENUM()
namespace EPlayerSettingStateInternal
{
	enum Type
	{
		PlayerUseDefault = 0,
		PlayerIsAllowed = 1,
		PlayerIsDisallowed = 2,
	};
}

UCLASS(ClassGroup=("Fortnite"))
class VERSEFORTNITEINTERNAL_API UFortBuildingSettingsComponentBase : public UEntityEnableableComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TObjectPtr<AFortAthenaMutator_BuildingSettings> Mutator;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_Settings)
	TEnumAsByte<EPlayerSettingStateInternal::Type> Building;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_Settings)
	TEnumAsByte<EPlayerSettingStateInternal::Type> BuildingOnWater;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_Settings)
	TEnumAsByte<EPlayerSettingStateInternal::Type> Editing;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_Settings)
	TEnumAsByte<EPlayerSettingStateInternal::Type> EditingHostile;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_Settings)
	TEnumAsByte<EPlayerSettingStateInternal::Type> TrapPlacement;

private:
	UFUNCTION()
	void OnRep_Settings();

};

