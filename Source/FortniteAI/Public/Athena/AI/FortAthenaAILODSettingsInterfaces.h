// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAthenaAILODSettingsInterfaces.generated.h"

USTRUCT()
struct FFortAthenaAILODSetting
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="AILOD")
	bool bIsValid;

};

UINTERFACE(MinimalAPI, meta=(CannotImplementInterfaceInBlueprint))
class UFortAthenaAILODSettings : public UInterface
{
	GENERATED_BODY()
};

class IFortAthenaAILODSettings
{
	GENERATED_BODY()

};

