// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortSettingRegistry.generated.h"

class UFortLocalPlayer;
class UFortSetting;

UCLASS(Abstract, BlueprintType)
class UFortSettingRegistry : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortSetting>> TopLevelSettings;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortSetting>> RegisteredSettings;

	UPROPERTY(Transient)
	TObjectPtr<UFortLocalPlayer> OwningLocalPlayer;

};

