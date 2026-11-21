// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AthenaMapScreenContainerTabInterface.h"
#include "Athena/Map/AthenaFullScreenMapBase.h"
#include "AthenaFullScreenMapPanel.generated.h"

class UAthenaMapGameInfo;
class UUserWidget;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaFullScreenMapPanel : public UAthenaFullScreenMapBase, public IAthenaMapScreenContainerTabInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Fullscreen Map")
	FAthenaMapScreenContainerTabInfo MapTabInfo;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnMapGameInfoWidgetCreated(UUserWidget* Widget);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTransistionedFromAnotherMapPanel();

private:
	UPROPERTY(EditAnywhere, Category="AthenaFullScreenMapPanel")
	TSoftClassPtr<UAthenaMapGameInfo> SoftGameInfoClass;

};

