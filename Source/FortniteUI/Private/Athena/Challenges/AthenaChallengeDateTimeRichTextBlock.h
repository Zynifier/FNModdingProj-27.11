// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonRichTextBlock.h"
#include "Misc/DateTime.h"
#include "Misc/Timespan.h"
#include "AthenaChallengeDateTimeRichTextBlock.generated.h"

UCLASS(BlueprintType)
class UAthenaChallengeDateTimeRichTextBlock : public UCommonRichTextBlock
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="DateTime Text Block")
	FDateTime GetDateTime() const;

	UFUNCTION(BlueprintCallable, Category="DateTime Text Block")
	void SetCountDownCompletionText(const FText InCompletionText);

	UFUNCTION(BlueprintCallable, Category="DateTime Text Block")
	void SetDateTimeValue(const FDateTime InDateTime, bool bShowAsCountdown, float InRefreshDelay = 1.000000f);

	UFUNCTION(BlueprintCallable)
	void SetLabelFormat(const FText& InLabelFormat);

	UFUNCTION(BlueprintCallable, Category="DateTime Text Block")
	void SetTimespanValue(const FTimespan InTimespan);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaChallengeDateTimeRichTextBlock")
	FText LabelFormat;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaChallengeDateTimeRichTextBlock")
	bool bShowUpperCase;

};

