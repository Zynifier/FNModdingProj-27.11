// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "CommonButtonLegacy.h"
#include "AthenaMapScreenContainerTabButton.generated.h"

class UCommonLazyImage;
class UCommonTextBlock;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaMapScreenContainerTabButton : public UCommonButtonLegacy
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaMapScreenContainerTabButton", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonLazyImage> LazyImage_Icon;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaMapScreenContainerTabButton", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Title;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FVector2D ImageSize_Mobile;

};

