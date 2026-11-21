// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator_CustomCharacterParts.h"
#include "Athena/Modifiers/FortAthenaMutator_FactionCustomCharacterParts.h"
#include "FortAthenaMutator_OperationsCustomCharacterParts.generated.h"

UENUM(BlueprintType)
enum class EOperationsTeamFaction : uint8
{
	Alter = 0,
	Ego = 1,
	NumFactions = 2,
};

UCLASS(Abstract, HideDropdown, HideCategories=("Base", "Override", "Customizations", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_OperationsCustomCharacterParts : public AFortAthenaMutator_FactionCustomCharacterParts
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Skins")
	TArray<FPartOverrideData> FactionCustomizations_Alter;

	UPROPERTY(EditDefaultsOnly, Category="Skins")
	TArray<FPartOverrideData> FactionCustomizations_Ego;

};

UINTERFACE()
class UFortOperationsCharacterPartsFactionAuthority : public UInterface
{
	GENERATED_BODY()
};

class IFortOperationsCharacterPartsFactionAuthority
{
	GENERATED_BODY()

};

