// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/FortHarvesterToolTypes.h"
#include "FortHarvesterSwing.generated.h"

class UAnimSequence;

UENUM()
enum EHarvesterSwingTagType
{
	Hit = 0,
	Combo = 1,
};

USTRUCT()
struct FFortHarvesterSwing
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="Harvester Tool Animation")
	ESwingType SwingType;

	UPROPERTY(EditAnywhere, Category="Harvester Tool Animation")
	TObjectPtr<UAnimSequence> UpperBodySwing;

	UPROPERTY(EditAnywhere, Category="Harvester Tool Animation")
	TObjectPtr<UAnimSequence> UpperBodyReturn;

	UPROPERTY(EditAnywhere, Category="Harvester Tool Animation")
	TObjectPtr<UAnimSequence> CrouchUpperBodySwing;

	UPROPERTY(EditAnywhere, Category="Harvester Tool Animation")
	TObjectPtr<UAnimSequence> CrouchUpperBodyReturn;

	UPROPERTY(EditAnywhere, Category="Harvester Tool Animation")
	TObjectPtr<UAnimSequence> CrouchInPlaceAdditiveSwing;

	UPROPERTY(EditAnywhere, Category="Harvester Tool Animation")
	TObjectPtr<UAnimSequence> CrouchInPlaceAdditiveReturn;

};

