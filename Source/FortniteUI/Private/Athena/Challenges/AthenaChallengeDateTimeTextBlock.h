// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonDateTimeTextBlock.h"
#include "AthenaChallengeDateTimeTextBlock.generated.h"

UCLASS(BlueprintType, PrioritizeCategories=("Content"))
class UAthenaChallengeDateTimeTextBlock : public UCommonDateTimeTextBlock
{
	GENERATED_BODY()

public:
	UAthenaChallengeDateTimeTextBlock(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable)
	void SetLabelFormat(const FText& InLabelFormat);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaChallengeDateTimeTextBlock")
	FText LabelFormat;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaChallengeDateTimeTextBlock")
	bool bShowUpperCase;

};

