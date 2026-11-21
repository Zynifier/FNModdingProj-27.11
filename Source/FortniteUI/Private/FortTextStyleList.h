// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortTextStyleList.generated.h"

class UCommonTextStyle;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortTextStyleList : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="BorderList")
	TArray<TSoftClassPtr<UCommonTextStyle>> GetTextStyles() const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortTextStyleList")
	FName TextStylesPath;

};

