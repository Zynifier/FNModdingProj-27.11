// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortTypes.h"
#include "FortFrontendItemViewSettingsManager.generated.h"

class UFortItemDefinition;
enum class EFrontEndCamera : uint8;
enum class ESubGame : uint8;

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortFrontendItemViewSettingsManager : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	FFortItemViewSettings GetItemViewSettings(const EFrontEndCamera Camera, const ESubGame GameMode, const UFortItemDefinition* ItemDefinition, const int32 SubSlotIndex) const;

};

