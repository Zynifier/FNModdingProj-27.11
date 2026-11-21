// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/EditableText.h"
#include "FortMobileEditableText.generated.h"

UCLASS()
class UFortMobileEditableText : public UEditableText
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Editable Text|Mobile")
	float GetMobileFontSizeMultiplier() const;

	UFUNCTION(BlueprintCallable, Category="Editable Text|Mobile")
	void SetMobileFontSizeMultiplier(float InMobileFontSizeMultiplier);

private:
	UPROPERTY(EditAnywhere, Category="Editable Text|Mobile", meta=(ClampMax="5.0", ClampMin="0.01"))
	float MobileFontSizeMultiplier;

};

