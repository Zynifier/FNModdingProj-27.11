// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BlueprintContext/FortLocalPlayerSubsystem.h"
#include "FortAudioLocalPlayerSubsystem.generated.h"

class UFortClientSettingsRecord;

UCLASS(MinimalAPI)
class UFortAudioLocalPlayerSubsystem : public UFortLocalPlayerSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnLicensedAudioTreatmentChanged(UFortClientSettingsRecord* Settings);

};

