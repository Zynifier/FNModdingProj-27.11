// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "Internationalization/PolyglotTextData.h"
#include "FortTextHotfixConfig.generated.h"

UCLASS(Config=Game, DefaultConfig)
class UFortTextHotfixConfig : public UDeveloperSettings
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Config, Category="FortTextHotfixConfig")
	TArray<FPolyglotTextData> TextReplacements;

};

