// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortPropertyOverrideData.h"
#include "FortAthenaMutator_CreativePartyRiftIslandSettings.generated.h"

UCLASS(HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_CreativePartyRiftIslandSettings : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void MutatorSettingsChanged(const FPropertyOverrideData& OverrideData);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Replicated, Category="PartyRifts")
	bool bAllowGuestPartyRiftsUserSetting;

};

