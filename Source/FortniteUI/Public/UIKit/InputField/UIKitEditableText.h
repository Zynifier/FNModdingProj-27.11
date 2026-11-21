// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/EditableText.h"
#include "UIKitEditableText.generated.h"

class UMaterialInstanceDynamic;

UCLASS(MinimalAPI)
class UUIKitEditableText : public UEditableText
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="UIKit Editable Text|Appearance")
	UMaterialInstanceDynamic* GetDynamicFontMaterial();

	UFUNCTION(BlueprintPure, Category="UIKit Editable Text|Mobile")
	float GetMobileFontSizeMultiplier() const;

	UFUNCTION(BlueprintCallable, Category="UIKit Editable Text|Mobile")
	void SetMobileFontSizeMultiplier(float InMobileFontSizeMultiplier);

protected:
	UPROPERTY(EditAnywhere, Category="Mobile", meta=(ClampMax="5.0", ClampMin="0.01"))
	float MobileFontSizeMultiplier;

};

