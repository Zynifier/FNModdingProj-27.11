// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortProfileStatsRow.generated.h"

class UCommonTextBlock;

UCLASS(meta=(DisableNativeTick))
class UFortProfileStatsRow : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortProfileStatsRow", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Name;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortProfileStatsRow", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Value;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortProfileStatsRow")
	FText StatName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortProfileStatsRow")
	FString BaseGameplayTag;

};

