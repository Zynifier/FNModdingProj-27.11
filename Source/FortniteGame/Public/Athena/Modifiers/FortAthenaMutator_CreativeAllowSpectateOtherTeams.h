// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator_AllowSpectateOtherTeams.h"
#include "FortAthenaMutator_CreativeAllowSpectateOtherTeams.generated.h"

UENUM(BlueprintType)
enum class ECreativeAllowSpectateOtherTeams : uint8
{
	Disallow = 0 UMETA(DisplayName="Disallowed"),
	Allow = 1 UMETA(DisplayName="Allowed"),
	BattleRoyale = 2,
};

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_CreativeAllowSpectateOtherTeams : public AFortAthenaMutator_AllowSpectateOtherTeams
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="AllowSpectateOtherTeams")
	ECreativeAllowSpectateOtherTeams AllowSpectateOtherTeams;

};

