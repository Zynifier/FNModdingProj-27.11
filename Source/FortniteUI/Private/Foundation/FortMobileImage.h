// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/Image.h"
#include "FortMobileImage.generated.h"

UCLASS()
class UFortMobileImage : public UImage
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Mobile", meta=(ClampMax="5.0", ClampMin="0.01"))
	float MobileSizeMultiplier;

};

