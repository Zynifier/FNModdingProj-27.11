// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Sound/FortFeedbackManager.h"
#include "FortFeedbackBank.generated.h"

UCLASS()
class UFortFeedbackBank : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Feedback")
	TArray<FFortFeedbackActionBankDefined> BankDefinedFeedbackEvents;

protected:
	UPROPERTY(EditAnywhere, EditFixedSize, Category="Feedback")
	TArray<FFortFeedbackAction> FeedbackEvents;

};

