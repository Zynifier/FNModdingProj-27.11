// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Customization/CustomCharacterAccessoryData.h"
#include "FortCustomPartTypeEnum.h"
#include "CustomCharacterFaceData.generated.h"

UCLASS()
class UCustomCharacterFaceData : public UCustomCharacterAccessoryData
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Face", meta=(DisplayName="Part Attached To"))
	TEnumAsByte<EFortCustomPartType::Type> PartAttachedToOverride;

	UPROPERTY(EditAnywhere, Category="CustomCharacterFaceData", meta=(ShowOnlyInnerProperties))
	FCustomAccessoryHatReactiveMorphs HatMorphData;

};

