// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AudioGameplayVolume.h"
#include "FortAmbientVolume.generated.h"

class UAmbientAudioComponent;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Advanced", "Attachment", "Collision", "Volume", "Advanced", "Attachment", "Collision", "Volume", "Brush", "Physics", "Object", "Blueprint", "Display", "Rendering", "Physics", "Input"), ShowCategories=("Input|MouseInput", "Input|TouchInput"), meta=(DisplayName="Ambient Volume"))
class AFortAmbientAudioVolume : public AAudioGameplayVolume
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Instanced, Category="AudioGameplay", meta=(ShowOnlyInnerProperties))
	TObjectPtr<UAmbientAudioComponent> AmbientComponent;

};

