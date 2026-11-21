// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortBorderStyleList.generated.h"

class UCommonBorderStyle;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortBorderStyleList : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="BorderList")
	TArray<TSoftClassPtr<UCommonBorderStyle>> GetBorderStyles() const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortBorderStyleList")
	FName BordersPath;

};

