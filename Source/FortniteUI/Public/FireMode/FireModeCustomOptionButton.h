// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "FireModeCustomOptionButton.generated.h"

class UCommonTextBlock;

UCLASS(meta=(DisableNativeTick))
class UFireModeCustomOptionButton : public UCommonButtonBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetCustomOptionName(FText NewName);

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FireModeCustomOptionButton", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_CustomOptionName;

};

