// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Customization/CustomCharacterPartData.h"
#include "CustomCharacterBodyPartData.generated.h"

class UAnimInstance;
class UCustomAccessoryColorSwatch;

UCLASS()
class UCustomCharacterBodyPartData : public UCustomCharacterPartData
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Body")
	TSoftClassPtr<UAnimInstance> AnimClass;

	UPROPERTY(EditAnywhere, Category="Body")
	TSoftClassPtr<UAnimInstance> FrontEndAnimClass;

	UPROPERTY(EditAnywhere, Category="Body")
	TSoftClassPtr<UAnimInstance> MannequinAnimClass;

	UPROPERTY(EditAnywhere, Category="Body")
	TSoftObjectPtr<UCustomAccessoryColorSwatch> AccessoryColors;

};

