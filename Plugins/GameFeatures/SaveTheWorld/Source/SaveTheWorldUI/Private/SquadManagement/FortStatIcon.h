// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "CommonUserWidget.h"
#include "FortBrushSize.h"
#include "FortStatIcon.generated.h"

class UImage;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortStatIcon : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="FortStat")
	void SetAttribute(const FGameplayAttribute& InAttribute);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortStat")
	FGameplayAttribute Attribute;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortStat")
	TEnumAsByte<EFortBrushSize::Type> ImageSize;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortStat", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Icon;

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="FortStat")
	void HandleDifferentAttributeSetBP();

};

