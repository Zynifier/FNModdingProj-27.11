// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/InputSettings.h"
#include "PlayerMappableKeySettings.h"
#include "FortPlayerMappableKeySettings.generated.h"

UCLASS()
class FORTNITEGAME_API UFortPlayerMappableKeySettings : public UPlayerMappableKeySettings
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Settings|Legacy")
	TMap<EHardwareDevicePrimaryType, FName> LegacyMappingNames;

	UPROPERTY(EditAnywhere, Category="Settings|Widget")
	bool bDisplayInTooltip;

	UPROPERTY(EditAnywhere, Category="Settings|Widget", meta=(EditCondition="bDisplayInTooltip"))
	TArray<FText> WidgetDisplayTexts;

};

