// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AudioPropertiesSheetAssetBase.h"
#include "PropertyBag.h"
#include "AudioPropertiesSheet.generated.h"

class UAudioPropertiesSheetAsset;

USTRUCT()
struct AUDIOPROPERTIES_API FAudioPropertiesSheet
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Default")
	TObjectPtr<UAudioPropertiesSheetAsset> Parent;

	UPROPERTY(EditAnywhere, Category="Default")
	FInstancedPropertyBag Properties;

};

UCLASS(BlueprintType)
class AUDIOPROPERTIES_API UAudioPropertiesSheetAsset : public UAudioPropertiesSheetAssetBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Default")
	FAudioPropertiesSheet PropertiesSheet;

};

