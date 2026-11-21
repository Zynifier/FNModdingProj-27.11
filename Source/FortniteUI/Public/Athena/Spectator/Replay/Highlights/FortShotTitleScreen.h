// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortShotTitleScreen.generated.h"

class UTextBlock;

UCLASS()
class UFortShotTitleScreen : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortShotTitleScreen")
	float FadeOutTime;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> TextBlock_MainText;

};

