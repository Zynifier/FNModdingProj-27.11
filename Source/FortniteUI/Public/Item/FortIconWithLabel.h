// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "FortBrushSize.h"
#include "FortIconWithLabel.generated.h"

class UCommonTextStyle;

UCLASS(Abstract, BlueprintType)
class UFortIconWithLabel : public UWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Icon With Label", meta=(ExposeOnSpawn))
	bool ShouldShowIcon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Icon With Label", meta=(ExposeOnSpawn))
	bool ShouldCollapseIconWhenNotShown;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Icon With Label", meta=(ExposeOnSpawn))
	TEnumAsByte<EFortBrushSize::Type> IconBrushSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Icon With Label", meta=(ExposeOnSpawn))
	bool ShouldShowLabel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Icon With Label", meta=(ExposeOnSpawn))
	TSubclassOf<UCommonTextStyle> LabelTextStyle;

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	bool bStyleNoLongerNeedsConversion;
#endif

};

