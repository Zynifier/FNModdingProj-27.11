// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UserSettings/EnhancedInputUserSettings.h"
#include "FortEnhancedInputUserSettings.generated.h"

UCLASS()
class FORTNITEGAME_API UFortEnhancedInputUserSettings : public UEnhancedInputUserSettings
{
	GENERATED_BODY()

private:
	UPROPERTY(SaveGame)
	TSet<FName> UpgradedLegacyMappings;

};

