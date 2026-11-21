// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortItemDownloadIndicator.generated.h"

class UFortAccountItemDefinition;
class UImage;

UCLASS()
class UFortItemDownloadIndicator : public UCommonUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemDownloadIndicator", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_DownloadSpinner;

	UPROPERTY(Transient)
	TObjectPtr<UFortAccountItemDefinition> CurrentDisplayedItem;

};

