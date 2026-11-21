// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/IAudioGameplayCondition.h"
#include "AudioWorldizationReflectionProbe.generated.h"

class UAudioGameplayVolumeComponent;
class USubmixSendVolumeComponent;

UCLASS()
class AAudioWorldizationReflectionProbe : public AActor, public IAudioGameplayCondition
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<USubmixSendVolumeComponent> SubmixSends;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAudioGameplayVolumeComponent> AGVComponent;

};

