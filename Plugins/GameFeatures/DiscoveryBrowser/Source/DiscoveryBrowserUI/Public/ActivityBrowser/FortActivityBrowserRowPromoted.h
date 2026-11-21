// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ActivityBrowser/FortActivityBrowserRow.h"
#include "FortActivityBrowserRowPromoted.generated.h"

class UCommonTextBlock;
class UTexture;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortActivityBrowserRowPromoted : public UFortActivityBrowserRow
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnPreviewImageChanged(const bool bIsLoading, const UTexture* Texture);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityBrowserRowPromoted", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ActivityName;

};

