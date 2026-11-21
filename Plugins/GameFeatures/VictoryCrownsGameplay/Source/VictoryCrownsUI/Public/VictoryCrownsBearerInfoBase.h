// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "VictoryCrownsBearerInfoBase.generated.h"

class AFortPlayerStateAthena;
class UCommonTextBlock;

UCLASS(Abstract, meta=(DisableNativeTick))
class UVictoryCrownsBearerInfoBase : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetPlayerState(AFortPlayerStateAthena* InPlayerState);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnSetPlayerState(AFortPlayerStateAthena* PSA);

	UPROPERTY(BlueprintReadOnly, Category="VictoryCrownsBearerInfoBase")
	TWeakObjectPtr<AFortPlayerStateAthena> WeakPSA;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="VictoryCrownsBearerInfoBase", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_PlayerName;

};

