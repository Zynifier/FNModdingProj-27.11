// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "CommonButtonLegacy.h"
#include "AthenaMapChallengeCategoryTabButton.generated.h"

class UCommonLazyImage;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaMapChallengeCategoryTabButton : public UCommonButtonLegacy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Show Bang"))
	void BP_ShowBang(const bool bShow);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaMapChallengeCategoryTabButton", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonLazyImage> LazyImage_Icon;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FVector2D ImageSize_Mobile;

};

