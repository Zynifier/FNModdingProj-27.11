// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortUIFeedbackBank.generated.h"

class USoundBase;

USTRUCT()
struct FFortUIFeedback
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortUIFeedback")
	TObjectPtr<USoundBase> Audio;

	UPROPERTY(EditAnywhere, Category="FortUIFeedback")
	bool bLooping;

	UPROPERTY(EditAnywhere, Category="FortUIFeedback", meta=(EditCondition="bLooping"))
	float FadeIn;

	UPROPERTY(EditAnywhere, Category="FortUIFeedback", meta=(EditCondition="bLooping"))
	float FadeOut;

};

USTRUCT()
struct FFortUIFeedbackBlueprintOnly : public FFortUIFeedback
{
	GENERATED_BODY()

};

UCLASS()
class UFortUIFeedbackBank : public UDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Feedback")
	TMap<FName, FFortUIFeedback> FeedbackEvents;

	UPROPERTY(EditAnywhere, Category="Feedback")
	bool bIsAthenaData;

	UPROPERTY(EditAnywhere, Category="Feedback")
	TMap<FName, FFortUIFeedbackBlueprintOnly> BankDefinedFeedbackEvents;

};

