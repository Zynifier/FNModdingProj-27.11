// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "Math/MathFwd.h"
#include "FortBattlePassCustomSkinTab.generated.h"

class UCommonLazyImage;
class UObject;

UCLASS(Abstract, meta=(DisableNativeTick))
class BATTLEPASSBASE_API UFortBattlePassCustomSkinTab : public UCommonButtonBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Show Bang"))
	void BP_ShowBang(bool bShow);

	UFUNCTION(BlueprintCallable, meta=(DisplayName="Set Icon"))
	void SetIcon(TSoftObjectPtr<UObject> LazyObject);

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortBattlePassCustomSkinTab", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonLazyImage> LazyImage_Icon;

private:
	UPROPERTY(EditAnywhere, Category="Appearance")
	FVector2D ImageSize_Mobile;

};

