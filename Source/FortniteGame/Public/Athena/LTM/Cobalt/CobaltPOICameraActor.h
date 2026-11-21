// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/SpecialActor/FortPOICameraActor.h"
#include "CobaltPOICameraActor.generated.h"

class USceneComponent;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Input", "Rendering"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class ACobaltPOICameraActor : public AFortPOICameraActor
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="CameraActor", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<USceneComponent> TranslationSceneComponent;

};

