// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortRuntimeLockerConfig.generated.h"

class UFortLockerCategoryGroupConfig;
class UFortLockerConfig;
class UFortLockerConfigModifier;

UCLASS(MinimalAPI)
class UFortRuntimeLockerConfig : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<UFortLockerCategoryGroupConfig*> CategoryGroups;

private:
	UPROPERTY(Transient)
	UFortLockerConfig* BaseLockerConfig;

	UPROPERTY(Transient)
	TSet<UFortLockerConfigModifier*> Modifiers;

};

