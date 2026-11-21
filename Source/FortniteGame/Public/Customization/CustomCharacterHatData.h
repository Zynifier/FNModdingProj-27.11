// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Customization/CustomCharacterAccessoryData.h"
#include "CustomCharacterHatData.generated.h"

UENUM()
enum ECustomHatType
{
	ECustomHatType_None = 0 UMETA(DisplayName="None"),
	ECustomHatType_Cap = 1 UMETA(DisplayName="Cap"),
	ECustomHatType_Helmet = 2 UMETA(DisplayName="Helmet"),
	ECustomHatType_Mask = 3 UMETA(DisplayName="Mask"),
	ECustomHatType_Hat = 4 UMETA(DisplayName="Hat"),
	ECustomHatType_HeadReplacement = 5 UMETA(DisplayName="Head Replacement"),
};

UCLASS()
class UCustomCharacterHatData : public UCustomCharacterAccessoryData
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Accessory")
	TEnumAsByte<ECustomHatType> HatType;

};

