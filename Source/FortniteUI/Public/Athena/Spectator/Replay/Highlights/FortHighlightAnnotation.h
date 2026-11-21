// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortHighlightAnnotation.generated.h"

class UTextBlock;

UCLASS()
class UFortHighlightAnnotation : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortHighlightAnnotation")
	float FadeOutTime;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> TextBlock_MainText;

};

