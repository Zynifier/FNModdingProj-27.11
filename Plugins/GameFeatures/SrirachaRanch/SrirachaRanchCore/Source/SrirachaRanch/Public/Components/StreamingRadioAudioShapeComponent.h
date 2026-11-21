// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Sound/FortAudioShapeComponent.h"
#include "StreamingRadioAudioShapeComponent.generated.h"

class UStreamingRadioPlayerComponent;

UCLASS(BlueprintType, Blueprintable, ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UStreamingRadioAudioShapeComponent : public UFortAudioShapeComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Config")
	float Radius;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UStreamingRadioPlayerComponent> RadioPlayer;

};

