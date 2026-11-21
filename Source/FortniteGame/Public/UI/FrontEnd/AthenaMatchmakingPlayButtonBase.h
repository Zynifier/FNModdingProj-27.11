// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonLegacy.h"
#include "Online/FortMcpContext.h"
#include "AthenaMatchmakingPlayButtonBase.generated.h"

class UImage;
class UWidgetAnimation;

UCLASS()
class UAthenaMatchmakingPlayButtonBase : public UCommonButtonLegacy
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleCurrentlyViewedAccountInfoChanged(FFortPublicAccountInfo NewInfo);

	UPROPERTY(BlueprintReadOnly, Transient, Category="AthenaMatchmakingPlayButtonBase", meta=(BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> Mobile_FTUE_In;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AthenaMatchmakingPlayButtonBase", meta=(BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> Mobile_FTUE_Idle;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaMatchmakingPlayButtonBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Mobile_FTUE_Anim;

};

