// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "CommonUserWidget.h"
#include "FortBrushSize.h"
#include "FortSquadStatValueWithIcon.generated.h"

class UCommonNumericTextBlock;
class UImage;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortSquadStatValueWithIcon : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortStats")
	FGameplayAttribute Attribute;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortStats")
	FGameplayAttribute TeamAttribute;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortStats")
	TEnumAsByte<EFortBrushSize::Type> ImageSize;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortStats", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonNumericTextBlock> Value;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortStats", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Icon;

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="FortStats")
	void HandleDifferentAttributeSetBP();

};

