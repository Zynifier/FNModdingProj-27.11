// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortDynamicMotdFullscreenTile.generated.h"

class UMotdActionBase;
class UMotdViewModel;
enum class EMotdButtonStyle : uint8;

UCLASS(BlueprintType, Blueprintable)
class UFortDynamicMotdFullscreenTile : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetMotd(UMotdViewModel* InMotd);

protected:
	UFUNCTION(BlueprintCallable)
	void OnButtonPressed(const UMotdActionBase* Action, const EMotdButtonStyle Style);

	UPROPERTY(BlueprintReadOnly, Category="FortDynamicMotdFullscreenTile")
	TObjectPtr<UMotdViewModel> Motd;

};

