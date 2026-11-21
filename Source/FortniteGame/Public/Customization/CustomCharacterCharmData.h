// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Customization/CustomCharacterAccessoryData.h"
#include "FortCustomPartTypeEnum.h"
#include "CustomCharacterCharmData.generated.h"

UCLASS()
class UCustomCharacterCharmData : public UCustomCharacterAccessoryData
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Charm", meta=(DisplayName="Part Attached To"))
	TEnumAsByte<EFortCustomPartType::Type> PartAttachedToOverride;

};

