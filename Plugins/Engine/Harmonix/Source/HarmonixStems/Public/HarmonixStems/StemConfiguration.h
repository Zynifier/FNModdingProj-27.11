// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StemConfiguration.generated.h"

class UAudioBus;

USTRUCT(BlueprintType)
struct HARMONIXSTEMS_API FStemConfigurationAudioBus
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="HarmonixStems")
	FName StemName;

	UPROPERTY(EditAnywhere, Category="HarmonixStems")
	TObjectPtr<UAudioBus> AudioBus;

};

UCLASS(ClassGroup=("Harmonix"))
class HARMONIXSTEMS_API UStemConfiguration : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="HarmonixStems")
	TArray<FStemConfigurationAudioBus> Stems;

};

