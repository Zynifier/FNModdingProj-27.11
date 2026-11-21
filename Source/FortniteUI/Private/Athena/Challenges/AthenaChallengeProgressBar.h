// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AthenaChallengeProgressBar.generated.h"

class UCommonRichTextBlock;
class UProgressBar;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaChallengeProgressBar : public UUserWidget
{
	GENERATED_BODY()

public:
	UAthenaChallengeProgressBar(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintImplementableEvent)
	void SetPercentValueForMaterialNumber(int32 PercentValue);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaChallengeProgressBar")
	bool bHideProgressBar;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaChallengeProgressBar", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UProgressBar> ProgressBar_StepsCompleted;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_Progress;

};

