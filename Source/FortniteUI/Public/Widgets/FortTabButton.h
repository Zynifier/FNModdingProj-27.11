// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "Math/MathFwd.h"
#include "FortTabListWidgetBase.h"
#include "FortTabButton.generated.h"

class UCommonLazyImage;
class UCommonTextBlock;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortTabButton : public UCommonButtonBase, public IFortTabButtonInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	FORTNITEUI_API virtual void SetTabLabelInfo_Implementation(const FFortTabButtonLabelInfo& TabLabelInfo);

private:
	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonLazyImage> LazyImage_Icon;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortTabButton", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Title;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FVector2D ImageSize_Mobile;

};

