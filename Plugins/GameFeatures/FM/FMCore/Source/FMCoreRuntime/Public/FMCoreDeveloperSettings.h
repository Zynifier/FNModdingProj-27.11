// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "UObject/SoftObjectPath.h"
#include "FMCoreDeveloperSettings.generated.h"

UCLASS(Config=Editor, DefaultConfig, meta=(DisplayName="FMCore Settings"))
class FMCORERUNTIME_API UFMCoreDeveloperSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Config, Category="Additional Plugins", meta=(ConfigRestartRequired="TRUE"))
	FDirectoryPath AdditionalContentPath;

};

