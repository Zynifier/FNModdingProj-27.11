// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortUpgradeDetailsBase.generated.h"

class UFortUpgradeInfo;
class UMediaPlayer;
class UTexture2D;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortUpgradeDetailsBase : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="FortUpgradeDetails")
	void OnPurchaseComplete();

	UFUNCTION(BlueprintImplementableEvent, Category="FortUpgradeDetails")
	void OnScreenActive();

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="FortUpgradeDetails")
	void OnShowIcon(UTexture2D* Icon);

	UFUNCTION(BlueprintImplementableEvent, Category="FortUpgradeDetails")
	void OnUpgradeToDetailChanged();

	UFUNCTION(BlueprintCallable, Category="FortUpgradeDetails")
	void RequestPurchaseNode();

	UPROPERTY(EditAnywhere, Category="FortUpgradeDetailsBase")
	TObjectPtr<UMediaPlayer> VideoPlayer;

	UPROPERTY(BlueprintReadOnly, Category="FortUpgradeDetails")
	TObjectPtr<UFortUpgradeInfo> UpgradeInfo;

};

